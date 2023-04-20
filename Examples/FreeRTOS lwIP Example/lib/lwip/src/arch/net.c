/**
  @file net.c
  @brief Abstraction file for handling access to lwIP library.
 */
/*
 * ============================================================================
 * History
 * =======
 * 2017-12-06 : Created
 *
 * (C) Copyright Bridgetek Pte Ltd
 * ============================================================================
 *
 * This source code ("the Software") is provided by Bridgetek Pte Ltd
 *  ("Bridgetek ") subject to the licence terms set out
 * http://brtchip.com/BRTSourceCodeLicenseAgreement/ ("the Licence Terms").
 * You must read the Licence Terms before downloading or using the Software.
 * By installing or using the Software you agree to the Licence Terms. If you
 * do not agree to the Licence Terms then do not download or use the Software.
 *
 * Without prejudice to the Licence Terms, here is a summary of some of the key
 * terms of the Licence Terms (and in the event of any conflict between this
 * summary and the Licence Terms then the text of the Licence Terms will
 * prevail).
 *
 * The Software is provided "as is".
 * There are no warranties (or similar) in relation to the quality of the
 * Software. You use it at your own risk.
 * The Software should not be used in, or for, any medical device, system or
 * appliance. There are exclusions of Bridgetek liability for certain types of loss
 * such as: special loss or damage; incidental loss or damage; indirect or
 * consequential loss or damage; loss of income; loss of business; loss of
 * profits; loss of revenue; loss of contracts; business interruption; loss of
 * the use of money or anticipated savings; loss of information; loss of
 * opportunity; loss of goodwill or reputation; and/or loss of, damage to or
 * corruption of data.
 * There is a monetary cap on Bridgetek's liability.
 * The Software may have subsequently been amended by another user and then
 * distributed by that other user ("Adapted Software").  If so that user may
 * have additional licence terms that apply to those amendments. However, Bridgetek
 * has no liability in relation to those amendments.
 * ============================================================================
 */

#include <stdint.h>
#include <string.h>

#include <ft900.h>
#include "net.h"
#if NET_USE_EEPROM
#include <ft900_i2cm.h>
#endif // NET_USE_EEPROM
#include <ft900_eth.h>

#ifdef __TFP_PRINTF__
#define NET_DEBUG
#endif

#undef NET_EEPROM_DEBUG
#ifdef NET_DEBUG
#include "tinyprintf.h"
#define NET_DEBUG_PRINTF(...) do {tfp_printf(__VA_ARGS__);} while (0)
#else
#define NET_DEBUG_PRINTF(...)
#endif

/* CONSTANTS ***********************************************************************/

#if NET_USE_EEPROM
/**
 @brief Key value to signify valid data in EEPROM.
 @details This must be unique to the layout of the eeprom_net_config structure.
 It is safest, when using this code as an example to build on, to assign a new
 unique number whenever the base structure changes.
 */
#define EEPROM_VALID_KEY 0x5A45

/**
 @brief Address of EEPROM on I2C bus.
 @details This can be set in the lwipopts.h file and override this value.
 */
#ifndef NET_EEPROM_ADDR
#define NET_EEPROM_ADDR 0xA0
#endif // NET_EEPROM_ADDR

/**
 @brief Offset in EEPROM for MAC address.
 @details This can be set in the lwipopts.h file and override this value.
 */
#ifndef NET_EEPROM_OFFSET_MACADDRESS
#define NET_EEPROM_OFFSET_MACADDRESS 0xfa
#endif // NET_EEPROM_OFFSET_MACADDRESS

#endif // NET_USE_EEPROM

#if defined(NO_SYS) && (NO_SYS==0)
/**
 @brief Name and thread parameters of network Ethernet input thread.
 @details The thread name is to give some context to any failures (such as
 stack overflows) that may occur or trace reports.
 The Stacksize has been determined experimentally using the
 uxTaskGetStackHighWaterMark function with configUSE_TRACE_FACILITY on.
 If Stacksize and Priority are set in the lwIPopts.h file then the
 values here will be overridden.
 */
//@{
#define NET_ETHERNET_INPUT_TASK 			"Ethernet"

#ifndef NET_ETHERNET_INPUT_TASK_STACKSIZE
#define NET_ETHERNET_INPUT_TASK_STACKSIZE 	512 // Fix crash issue
#endif // NET_ETHERNET_INPUT_TASK_STACKSIZE

#ifndef NET_ETHERNET_INPUT_TASK_PRIO
#define NET_ETHERNET_INPUT_TASK_PRIO 		1
#endif // NET_ETHERNET_INPUT_TASK_PRIO
//@}
#endif

/* GLOBAL VARIABLES ****************************************************************/

/* LOCAL VARIABLES *****************************************************************/

#if defined(NO_SYS) && (NO_SYS==0)
/**
 @brief Thread handle for network Ethernet input.
 @details Thread which will add packets received by Ethernet handler to lwIP.
 This is signalled from IRQ level to create pbufs from the raw data received and
 add the pbufs to lwIP.
 */
static sys_thread_t g_task_ethernet_input;
#endif

/**
 @brief Callback function for network available/unavailable signal and packet
 available.
 @details When this is set a callback to the application will be made for
 status changes.
 */
static fn_status_cb gfn_status = NULL;

#if NET_USE_EEPROM
/**
 @brief Structure to hold IP address configuration in EEPROM.
 @details This is used to both keep settings stored persistently in EEPROM.
 */
struct eeprom_net_config {
	uint16_t key; // Must contain EEPROM_VALID_KEY
	uint8_t dhcp;
	ip_addr_t ip;
	ip_addr_t gw;
	ip_addr_t mask;
} __attribute__((packed));
#endif // NET_USE_EEPROM

/**
 @brief Default network hostname.
 */
#if LWIP_NETIF_HOSTNAME
static char default_hostname[8] =
{'F','T','9','0','x', 0, 0, 0};
#endif

/** @brief Pointer to network interface structure.
 * @details This is used by lwIP to address an interface. We have only one interface
 *         to which this is the handle that is passed to lwIP for all relevant
 *         operations.
 */
static struct netif g_netif;
#if LWIP_DHCP
/** @brief Flag to remember if DHCP is active.
 * @details This is used to indicate that lwIP has been asked to manage the network
 *         configuration by DHCP. 
 */
static uint8_t g_dhcp = 0;
#endif

/* MACROS **************************************************************************/

/** @brief Simple minimum macro.
 */
#define MIN(a,b) (a<b)?a:b

/** @brief Sets the name of the network interface.
 */
#define NETIF_SET_NAME(netif,c1,c2) do { (netif)->name[0] = c1; (netif)->name[1] = c2; } while (0)

/* LOCAL FUNCTIONS / INLINES *******************************************************/

#if NET_USE_EEPROM
/** EEPROM Read routine
 *  @param location The location to start reading
 *  @param data A pointer to the data to read into
 *  @param len The size of data to read */
static int8_t ee_read(uint8_t location, uint8_t *data, const uint16_t len)
{
	return i2cm_read(NET_EEPROM_ADDR, location, data, len);

}

/** EEPROM Write routine
 *  @param location The location to start writing
 *  @param data A pointer to the data to write
 *  @param len The size of data to write */
static int8_t ee_write(uint8_t location, uint8_t *data, const uint16_t len)
{
	uint16_t i;
	int8_t retval = 0;

	/* Transfer a block of data by carrying out a series of byte writes
       and waiting for the write to complete */
	for (i = 0; (i < len) && (retval == 0); ++i)
	{
		retval |= i2cm_write(NET_EEPROM_ADDR, location++, data++, 1);
		delayms(5); // Wait a write cycle time
	}

	return retval;
}
#endif // NET_USE_EEPROM

/* FUNCTIONS ***********************************************************************/

void net_setup()
{
    /* Set up Ethernet */
    sys_enable(sys_device_ethernet);

#ifdef NET_USE_EEPROM
    /* Set up I2C */
    sys_enable(sys_device_i2c_master);

    /* Setup I2C channel 0 pins */
    /* Use sys_i2c_swop(0) to activate. */
    gpio_function(44, pad_i2c0_scl); /* I2C0_SCL */
    gpio_function(45, pad_i2c0_sda); /* I2C0_SDA */

    /* Setup I2C channel 1 pins for EEPROM */
    /* Use sys_i2c_swop(1) to activate. */
    gpio_function(46, pad_i2c1_scl); /* I2C1_SCL */
    gpio_function(47, pad_i2c1_sda); /* I2C1_SDA */
#endif
}

/** @brief Return the netif structure for the network.
 *  @details Returns a pointer to the structure containing the netif
 *  information used in lwIP. This allows an application to access the
 *  lwIP information directly for more advanced operations than are
 *  supported in this abstraction.
 *  @returns Pointer to netif structure.
 */
struct netif *net_get_netif(void)
{
	return &g_netif;
}

/** @brief Query the status for the network.
 *  @details The status is ready when there is a valid connection to another
 *  Ethernet device such as a switch or router AND a valid IP address is
 *  configured.
 *  @returns Non-zero if the network is ready.
 */
uint8_t net_is_ready(void)
{
	if (netif_is_link_up(&g_netif))
	{
#if LWIP_DHCP
		if (g_dhcp)
		{
			/* DHCP enabled and address supplied. */
			return dhcp_supplied_address(&g_netif);
		}
#endif
		if (g_netif.ip_addr.addr != IPADDR_ANY)
		{
			/* Valid IP address set and link is UP. */
			return 1;
		}
	}
	return 0;
}

/** @brief Update the EEPROM contents with new network parameters.
 *  @details If new network configuration parameters are supplied then
 *  this function will write to the EEPROM and update the valid key.
 *  @returns Zero if the EEPROM contents match the passed parameters.
 *  -1 if the EEPROM is disabled.
 */
int8_t net_update_eeprom(ip_addr_t ip, ip_addr_t gw, ip_addr_t mask, uint8_t dhcp)
{
	int8_t i2c_status = -1;

#if NET_USE_EEPROM
	struct eeprom_net_config curval;
	struct eeprom_net_config setval;

	/* Set the I2C Master pins to channel 1 */
	sys_i2c_swop(1);
	i2cm_init(I2CM_NORMAL_SPEED, 10000);

	/* Read structure from EEPROM. */
	i2c_status = ee_read(0, (uint8_t *)&curval, sizeof(struct eeprom_net_config));
	if (i2c_status == 0)
	{
		/* Set values in structure. */
		setval.key = EEPROM_VALID_KEY;
		setval.dhcp = dhcp;
		setval.ip.addr = ip.addr;
		setval.gw.addr = gw.addr;
		setval.mask.addr = mask.addr;

#ifdef NET_EEPROM_DEBUG
		for (int i = 0; i < sizeof(struct eeprom_net_config); i++)
		{
			tfp_printf("%02x ", ((uint8_t *)&setval)[i]);
		}
		tfp_printf("\r\n");
#endif // NET_EEPROM_DEBUG

		/* Compare structure in EEPROM to new structure. */
		if (memcmp(&curval, &setval, sizeof(struct eeprom_net_config)) != 0)
		{
			/* Write updated structure to EEPROM. */
			i2c_status = ee_write(0, (uint8_t *)&setval, sizeof(struct eeprom_net_config));

#ifdef NET_EEPROM_DEBUG
			ip_addr_t ip4;
			NET_DEBUG_PRINTF("Set EEPROM key = %x\r\n", setval.key);
			NET_DEBUG_PRINTF("  DHCP = %c\n", setval.dhcp?'Y':'N');
			ip4.addr = setval.ip.addr;
			NET_DEBUG_PRINTF("  ipaddr = %s\n", ipaddr_ntoa(&ip4));
			ip4.addr = setval.gw.addr;
			NET_DEBUG_PRINTF("  gw = %s\n", ipaddr_ntoa(&ip4));
			ip4.addr = setval.mask.addr;
			NET_DEBUG_PRINTF("  mask = %s\n", ipaddr_ntoa(&ip4));
#endif // NET_EEPROM_DEBUG
		}
	}
	/* Set the I2C Master pins back to channel 0 */
	i2cm_init(I2CM_NORMAL_SPEED, 100000);
	sys_i2c_swop(0);
#endif // NET_USE_EEPROM

	return i2c_status;
}

/** @brief Read network parameters from the EEPROM.
 *  @details Get network configuration parameters from the EEPROM.
 *  Will check the key matches the expected value.
 *  @returns Zero if the EEPROM contents are read and valid.
 *  -1 if the EEPROM is disabled.
 */
int8_t net_get_eeprom(ip_addr_t *ip, ip_addr_t *gw, ip_addr_t *mask, uint8_t *dhcp)
{
	int8_t i2c_status = -1;

#if NET_USE_EEPROM
	struct eeprom_net_config getval;

	/* Set the I2C Master pins to channel 1 */
	sys_i2c_swop(1);
	i2cm_init(I2CM_NORMAL_SPEED, 10000);

	/* Read structure from EEPROM. */
	i2c_status = ee_read(0, (uint8_t *)&getval, sizeof(struct eeprom_net_config));
	if (i2c_status == 0)
	{
#ifdef NET_EEPROM_DEBUG
		for (int i = 0; i < sizeof(struct eeprom_net_config); i++)
		{
			tfp_printf("%02x ", ((uint8_t *)&getval)[i]);
		}
		tfp_printf("\r\n");
#endif // NET_EEPROM_DEBUG

#ifdef NET_EEPROM_DEBUG
		NET_DEBUG_PRINTF("Get EEPROM key = %x\r\n", getval.key);
#endif // NET_EEPROM_DEBUG

		/* Check key is correct. If not return error value. */
		i2c_status = !(getval.key == EEPROM_VALID_KEY);
		if (i2c_status == 0)
		{
#ifdef NET_EEPROM_DEBUG
			NET_DEBUG_PRINTF("  DHCP = %c\r\n", getval.dhcp?'Y':'N');
			ip->addr = getval.ip.addr;
			NET_DEBUG_PRINTF("  ipaddr = %s\r\n", ipaddr_ntoa(ip));
			gw->addr = getval.gw.addr;
			NET_DEBUG_PRINTF("  gw = %s\r\n", ipaddr_ntoa(gw));
			mask->addr = getval.mask.addr;
			NET_DEBUG_PRINTF("  mask = %s\r\n", ipaddr_ntoa(mask));
#endif // NET_EEPROM_DEBUG
		}
	}
	/* Set the I2C Master pins back to channel 0 */
	i2cm_init(I2CM_NORMAL_SPEED, 100000);
	sys_i2c_swop(0);
#endif // NET_USE_EEPROM

	return i2c_status;
}

/** @brief Display network status for the interface.
 *  @details Prints the network configuration for the
 *      network interface. This is limited to the IP address
 *      gateway and network mask. It is called when the network
 *      status for the interface changes (from down to up or
 *      up to down).
 */
void net_status_cb(struct netif *netif)
{
	/* Network changes received. */
	NET_DEBUG_PRINTF("IP config\r\n");
	NET_DEBUG_PRINTF("  ipaddr = %s\r\n", ipaddr_ntoa(&netif->ip_addr));
	NET_DEBUG_PRINTF("  gw = %s\r\n", ipaddr_ntoa(&netif->gw));
	NET_DEBUG_PRINTF("  mask = %s\r\n", ipaddr_ntoa(&netif->netmask));
#if INCLUDE_uxTaskGetStackHighWaterMark
	NET_DEBUG_PRINTF("  "NET_ETHERNET_INPUT_TASK" = %ld\r\n", uxTaskGetStackHighWaterMark(g_task_ethernet_input) * sizeof(StackType_t));
#endif // INCLUDE_uxTaskGetStackHighWaterMark
#if NET_USE_EEPROM
	if (net_is_ready())
	{
		NET_DEBUG_PRINTF("Ready status\r\n");

		if (gfn_status) {
			gfn_status(NET_CALLBACK_READY);
		}
	}
#endif // NET_USE_EEPROM

	/*mdns_resp_netif_settings_changed();*/
}

/** @brief Signal from Ethernet ISR to say packet received.
 *  @details When a packet has been received in netif_ft900.c during
 *  the arch_ft900_ethernet_ISR function it will signal this to the
 *  application via this function.
 *  Note that this function is called at interrupt level and MUST
 *  adhere to the convention of returning as soon as possible to the
 *  ISR calling it.
 */
void net_packet_available()
{
#if defined(NO_SYS) && (NO_SYS==0)
	/* Signal vTaskNetwork to perform networking tasks. */
	/* Note: This callback is at ISR level. */
	if (g_task_ethernet_input)
	{
		xTaskNotify(g_task_ethernet_input, (uint32_t)1, eSetValueWithOverwrite);
	}
#endif
}

/** @brief Gets the MAC address of the interface.
 *  @returns Returns a pointer to the 6 octets which form the
 *      MAC address of the interface.
 */
uint8_t *net_get_mac()
{
	return g_netif.hwaddr;
}

/** @brief Gets the currently configured IP address of the interface.
 *  @returns Returns structure which contains the IP address. This is
 *      actually a 32 bit integer which can be expressed as 4 octets
 *      to display a traditional IP address.
 */
ip_addr_t net_get_ip()
{
	return g_netif.ip_addr;
}

/** @brief Gets the currently configured gateway address of the interface.
 *  @returns Returns structure which contains the gateway address. This is
 *      actually a 32 bit integer which can be expressed as 4 octets
 *      to display a traditional IP address.
 */
ip_addr_t net_get_gateway()
{
	return g_netif.gw;
}

/** @brief Gets the currently configured network mask of the interface.
 *  @returns Returns structure which contains the network mask. This is
 *      actually a 32 bit integer which can be expressed as 4 octets
 *      to display a traditional network mask.
 */
ip_addr_t net_get_netmask()
{
	return g_netif.netmask;
}

/** @brief Gets the currently configured status of DHCP for the interface.
 *  @returns Returns zero if currently disabled and non-zero if enabled.
 */
uint8_t net_get_dhcp()
{
	return g_dhcp;
}

/*void net_mdns_start(const char *hostname)
{
    mdns_resp_init();
    mdns_resp_add_netif(g_netif, hostname, 59);
}*/

static void net_timeout(void *arg)
{
	struct netif *netif = (struct netif *)arg;

	if (netif_is_link_up(netif))
	{
		if (!ethernet_is_link_up())
		{
			netif_set_link_down(netif);
#if LWIP_DHCP
			dhcp_network_changed(netif);
#endif
			NET_DEBUG_PRINTF("Ethernet disconnected.\r\n\r\n");
			if (gfn_status) {
				gfn_status(NET_CALLBACK_LINK_DOWN);
			}
		}
	}
	else
	{
		if (ethernet_is_link_up())
		{
			netif_set_link_up(netif);
#if LWIP_DHCP
			dhcp_network_changed(netif);
#endif
			NET_DEBUG_PRINTF("Ethernet connected.\r\n\r\n");
			if (gfn_status) {
				gfn_status(NET_CALLBACK_LINK_UP);
			}
		}
	}
	sys_timeout(250, net_timeout, arg);
}

#if defined(NO_SYS) && (NO_SYS==0)
/** @brief Adds packets received from the Ethernet at IRQ level to lwIP.
 *  @details Called when a packet is received from the Ethernet IRQ
 *  handler at IRQ level and needs adding to lwIP core at normal
 *  running level.
 *  Only applicable for FreeRTOS systems.
 */
void net_tick(void *pvParameters)
{
	uint32_t ulNotifiedValue;

	while (1)
	{
		/* Up-to 10 ms delay if no packets received. */
		if (xTaskNotifyWait(0, (uint32_t)1, &ulNotifiedValue, pdMS_TO_TICKS(10)))
		{
			/* Perform Ethernet packet input task. */
			arch_ft900_tick(&g_netif);
		}
	}
}
#else
/** @brief Processes all lwIP actions for this interface.
 *  @details Calls lwIP architecture specific code to process any
 *      actions that are required for the network interface.
 *      This function is not used on FreeRTOS. When used in a 'bare
 *      metal' application this needs to be called as often as
 *      possible. This does not require to be timer-driven as the
 *      sys_now function is used for timer related operations.
 *  @returns Returns value returned by the architecture-specific
 *      action handling function.
 */
err_t net_tick(void)
{
	return arch_ft900_tick(&g_netif);
}
#endif

/** @brief Query the link status for the interface.
 *  @details The link status is up when there is a valid connection to another
 *      Ethernet device such as a switch or router. It does not mean that the
 *      network is available.
 *  @returns Non-zero if the link is up.
 */
uint8_t net_is_link_up(void)
{
    return netif_is_link_up(&g_netif);
}

/** @brief Sets the link status for the interface to be up.
 */
void net_set_link_up()
{
    netif_set_link_up(&g_netif);
}

/** @brief Sets the link status for the interface to be down.
 */
void net_set_link_down()
{
    netif_set_link_down(&g_netif);
}

/** @brief Query the network status for the interface.
 *  @returns Non-zero if the network is up and configured.
 */
uint8_t net_is_up()
{
    return netif_is_up(&g_netif);
}

/** @brief Initialises the network interface.
 *  @details Configures lwIP to use the network configuration passed in
 *      the parameters. Turns on the hardware for the Ethernet interface
 *      and starts lwIP working.
 *  @param ip IP address to use. If non-zero and dhcp is not set this will
 *      use the IP address in the parameter. If zero then the value in the
 *      EEPROM will be used (DHCP will be enabled or disabled depending on
 *      the parameter).
 *  @param gw IP gateway to use.
 *  @param mask IP network mask to use.
 *  @param dhcp Enable DHCP if non-zero. If an address is passed in the ip
 *      parameter then this will be loaded regardless but may be updated by
 *      a DHCP server.
 *  @returns ERR_OK if the network was initialised successfully.
 */
err_t net_init(ip_addr_t ip,
		ip_addr_t gw, ip_addr_t mask,
        int dhcp, ip_addr_t dns, char *hostname,
		fn_status_cb pfn_status)
{
#if NET_USE_EEPROM
	int8_t i2c_status;
#endif

#if LWIP_DHCP
	g_dhcp = dhcp;
#endif

#if NET_USE_EEPROM
	/* Set the I2C Master pins to channel 1 */
	/* Read Network parameters from EEPROM */
	if ((ip.addr == IPADDR_ANY) && (!g_dhcp))
	{
		/* If the EEPROM contents are valid, the application has not supplied
		 * an IP address then we can use the stored values UNLESS DHCP is
		 * set. DHCP can be enabled from the EEPROM as well.
		 */
		net_get_eeprom(&ip, &gw, &mask, &g_dhcp);
	}
	if (ip.addr == IPADDR_ANY)
	{
		NET_DEBUG_PRINTF("Enabling DHCP\r\n");
		// Rescue an incorrect IP address.
		g_dhcp = 1;
	}
#endif // NET_USE_EEPROM

	/* Read MAC address from pre-programmed area of EEPROM. */
	g_netif.hwaddr_len = 6;

#if NET_USE_EEPROM
	/* Set the I2C Master pins to channel 1 */
	sys_i2c_swop(1);
	i2cm_init(I2CM_NORMAL_SPEED, 10000);

	i2c_status = ee_read(NET_EEPROM_OFFSET_MACADDRESS, &g_netif.hwaddr[0], 6);
	if (i2c_status != 0)
	{
		NET_DEBUG_PRINTF("MAC address read failed\r\n");
		return ERR_IF;
	}

	/* Set the I2C Master pins back to channel 0 */
	i2cm_init(I2CM_NORMAL_SPEED, 100000);
	sys_i2c_swop(0);
#else // NET_USE_EEPROM
	/* If no EEPROM then application must implement this function to
	 * supply a MAC address. */
	net_supply_mac(&g_netif.hwaddr[0]);
    //g_netif.hwaddr[0] = 0x44;
    //g_netif.hwaddr[1] = 0x6D;
    //g_netif.hwaddr[2] = 0x57;
    //g_netif.hwaddr[3] = 0xAA;
    //g_netif.hwaddr[4] = 0xBB;
    //g_netif.hwaddr[5] = 0xCC;
#endif // NET_USE_EEPROM

	NET_DEBUG_PRINTF("MAC = %02x:%02x:%02x:%02x:%02x:%02x\r\n",
			g_netif.hwaddr[0], g_netif.hwaddr[1], g_netif.hwaddr[2],
			g_netif.hwaddr[3], g_netif.hwaddr[4], g_netif.hwaddr[5]);

	NETIF_SET_NAME(&(g_netif),' ','1');
	g_netif.next = NULL;

	/* Initialize lwIP. */
#if defined(NO_SYS) && (NO_SYS==0)
	tcpip_init(NULL, NULL);
#else
	lwip_init();
#endif

	/* Add our netif to LWIP (netif_add calls our driver initialization function) */
	if (netif_add(&g_netif,
			&ip,
			&mask,
			&gw,
			NULL,
			arch_ft900_init,
			ethernet_input) == NULL)
	{
		NET_DEBUG_PRINTF("netif_add failed\r\n");
		return ERR_IF;
	}

	/* Initial state of Ethernet link is set to down.
	 * net_timeout will change it later. */
	netif_set_link_down(&g_netif);

#if LWIP_NETIF_HOSTNAME
	/* Use default hostname if required. */
	netif_set_hostname(&g_netif, default_hostname);
	if (hostname != NULL)
	{
		if (*hostname != '\0')
		{
			/* Otherwise use application-supplied hostname. */
			netif_set_hostname(&g_netif, hostname);
		}
	}
	NET_DEBUG_PRINTF("Hostname = \"%s\"\r\n", g_netif.hostname);
#endif

	/* Set global callback for status change. */
	gfn_status = pfn_status;

	/* Set this (and only) network interface to be the default interface. */
	netif_set_default(&g_netif);

#if LWIP_DNS
    ip_addr_t dnsserver = { dns.addr };
    if (dnsserver.addr == 0) {
        ipaddr_aton("8.8.8.8", &dnsserver);
    }
    dns_setserver(0, &dnsserver);
#endif // LWIP_DNS

	/* Initialise callback functions. */
#if LWIP_NETIF_STATUS_CALLBACK
	netif_set_status_callback(&g_netif, net_status_cb);
#endif

#if LWIP_NETIF_LINK_CALLBACK
	netif_set_link_callback(&g_netif, net_status_cb);
#endif

	/* Netif software configuration completed. */
	netif_set_up(&g_netif);

	/* Poll for physical link. */
	net_timeout(&g_netif);

#if defined(NO_SYS) && (NO_SYS==0)
	/* Start a thread to add received packets to lwIP. */
	g_task_ethernet_input = sys_thread_new(NET_ETHERNET_INPUT_TASK, net_tick, (void *)&g_netif,
			NET_ETHERNET_INPUT_TASK_STACKSIZE, NET_ETHERNET_INPUT_TASK_PRIO);
	if (g_task_ethernet_input == NULL)
	{
		NET_DEBUG_PRINTF(NET_ETHERNET_INPUT_TASK" Thread failed\r\n");
	}
#endif

	/* Turn on Ethernet receiver. */
	arch_ft900_recv_on();

#if LWIP_DHCP
	/* Start DHCP if requested. */
	if (g_dhcp)
	{
		NET_DEBUG_PRINTF("DHCP starting...\r\n");
		dhcp_start(&g_netif);
		g_dhcp = 1;
	}
	else
#endif
	{
#if LWIP_DNS
		dns_setserver(0, &dns);
#endif // LWIP_DNS
	}

	/* All done. Application must wait for net_is_ready to return
	 * non-zero before starting applications. */
	NET_DEBUG_PRINTF("Network ready.\r\n");

	return ERR_OK;
}
