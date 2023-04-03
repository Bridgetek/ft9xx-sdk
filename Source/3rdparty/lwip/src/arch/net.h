/**
  @file net.h
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

#ifndef NET_H_
#define NET_H_

#include <stdint.h>
#include <stdlib.h>

#include <lwip/inet.h>
#include <lwip/udp.h>
#include <lwip/tcp.h>
#include <lwip/tcpip.h>
#include <lwip/timeouts.h>
#include <lwip/netif.h>
#include <lwip/init.h>
#include <lwip/sys.h>
#include <lwip/igmp.h>
#include <netif/etharp.h>
#include <lwip/dhcp.h>
#include <lwip/ip_addr.h>
#include <lwip/igmp.h>
#include <lwip/dns.h>

#include "netif_arch.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 @brief Write the IP address configuration information to the EEPROM.
 @details Define macro to make an address change event update the EEPROM.
 */
#ifndef NET_USE_EEPROM
#define NET_USE_EEPROM 1
#endif

/**
 @brief Callback function for network available/unavailable signal and packet available.
*/
#define NET_CALLBACK_LINK_UP 1
#define NET_CALLBACK_LINK_DOWN 2
#define NET_CALLBACK_READY 4
#define NET_CALLBACK_PACKET_AVAILABLE 8
typedef void (*fn_status_cb)(int callback);

void net_setup();
err_t net_init(ip_addr_t ip,
		ip_addr_t gw, ip_addr_t mask,
		int dhcp, ip_addr_t dns,char *hostname,
		fn_status_cb pfn_status);
struct netif* net_get_netif();
uint8_t net_is_ready(void);
int8_t net_update_eeprom(ip_addr_t ip, ip_addr_t gw, ip_addr_t mask, uint8_t dhcp);
int8_t net_get_eeprom(ip_addr_t *ip, ip_addr_t *gw, ip_addr_t *mask, uint8_t *dhcp);
#if !defined(NO_SYS) || (NO_SYS!=0)
err_t net_tick(void);
uint8_t net_is_link_up(void);
void net_set_link_up();
void net_set_link_down();
uint8_t net_is_up();
#endif
#if defined(NET_USE_EEPROM) && (!NET_USE_EEPROM)
extern void net_supply_mac(uint8_t *);
#endif // NET_USE_EEPROM

uint8_t *net_get_mac();
ip_addr_t net_get_ip();
ip_addr_t net_get_gateway();
ip_addr_t net_get_netmask();
uint8_t net_get_dhcp();
void net_packet_available();

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* NET_H_ */
