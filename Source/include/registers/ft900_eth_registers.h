/**
    @file ft900_eth_registers.h

    @brief Ethernet registers
**/
/*
 * ============================================================================
 * History
 * =======
 *
 * Copyright (C) Bridgetek Pte Ltd
 * ============================================================================
 *
 * This source code ("the Software") is provided by Bridgetek Pte Ltd
 *  ("Bridgetek") subject to the licence terms set out
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


#ifndef FT900_ETH_REGISTERS_H_
#define FT900_ETH_REGISTERS_H_

/* INCLUDES ************************************************************************/

#include <stdint.h>
#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

/*
 * Definitions for ETH_MNG_CNTL
 */

/* Management control address register (MII) for write. */
#define BIT_ETH_MCR_RGAD            (3)
#define MASK_ETH_MCR_RGAD           (0x1F<<BIT_ETH_MCR_RGAD)

/* Write bit of management control register (MII) */
#define BIT_ETH_MCR_WRITE           (1)
#define MASK_ETH_MCR_WRITE          (1<<BIT_ETH_MCR_WRITE)

/* Start bit of management control register (MII) */
#define BIT_ETH_MCR_START           (0)
#define MASK_ETH_MCR_START          (1<<BIT_ETH_MCR_START)

/*
 * Definitions for ETH_INT_STATUS
 */

/* MII transaction has completed */
#define BIT_ETH_IACK_MD_INT         (5)
#define MASK_ETH_IACK_MD_INT        (1<<BIT_ETH_IACK_MD_INT)

/* Receive error */
#define BIT_ETH_IACK_RX_ERR         (4)
#define MASK_ETH_IACK_RX_ERR        (1<<BIT_ETH_IACK_RX_ERR)

/* FIFO overflow */
#define BIT_ETH_IACK_FIFO_OV        (3)
#define MASK_ETH_IACK_FIFO_OV       (1<<BIT_ETH_IACK_FIFO_OV)

/* Transmit empty */
#define BIT_ETH_IACK_TX_EMPTY       (2)
#define MASK_ETH_IACK_TX_EMPTY      (1<<BIT_ETH_IACK_TX_EMPTY)

/* Transmit error */
#define BIT_ETH_IACK_TX_ERR         (1)
#define MASK_ETH_IACK_TX_ERR        (1<<BIT_ETH_IACK_TX_ERR)

/* Packet received */
#define BIT_ETH_IACK_RX_INT         (0)
#define MASK_ETH_IACK_RX_INT        (1<<BIT_ETH_IACK_RX_INT)

/*
 * Definitions for ETH_INT_ENABLE
 */

/* MII transaction has completed mask */
#define BIT_ETH_IMR_MD_INT_MASK     (5)
#define MASK_ETH_IMR_MD_INT_MASK    (1<<BIT_ETH_IMR_MD_INT_MASK)

/* Receive error mask */
#define BIT_ETH_IMR_RX_ERR_MASK     (4)
#define MASK_ETH_IMR_RX_ERR_MASK    (1<<BIT_ETH_IMR_RX_ERR_MASK)

/* FIFO overflow mask */
#define BIT_ETH_IMR_FIFO_OV_MASK    (3)
#define MASK_ETH_IMR_FIFO_OV_MASK   (1<<BIT_ETH_IMR_FIFO_OV_MASK)

/* Transmit empty mask */
#define BIT_ETH_IMR_TX_EMPTY_MASK   (2)
#define MASK_ETH_IMR_TX_EMPTY_MASK  (1<<BIT_ETH_IMR_TX_EMPTY_MASK)

/* Transmit error mask */
#define BIT_ETH_IMR_TX_ERR_MASK     (1)
#define MASK_ETH_IMR_TX_ERR_MASK    (1<<BIT_ETH_IMR_TX_ERR_MASK)

/* Packet received mask */
#define BIT_ETH_IMR_RX_INT_MASK     (0)
#define MASK_ETH_IMR_RX_INT_MASK    (1<<BIT_ETH_IMR_RX_INT_MASK)

/*
 * Definitions for ETH_RX_CNTL
 */

/* Memory size - 2048 bytes */
#define BIT_ETH_RCR_RX_MEM_SIZE     (6)
#define MASK_ETH_RCR_RX_MEM_SIZE    (3<<BIT_ETH_RCR_RX_MEM_SIZE)

/* Reset receive FIFO */
#define BIT_ETH_RCR_RESET_FIFO      (4)
#define MASK_ETH_RCR_RESET_FIFO     (1<<BIT_ETH_RCR_RESET_FIFO)

/* Discard frames with bad CRC */
#define BIT_ETH_RCR_BAD_CRC         (3)
#define MASK_ETH_RCR_BAD_CRC        (1<<BIT_ETH_RCR_BAD_CRC)

/* Set promiscuous mode */
#define BIT_ETH_RCR_PRMS_MODE       (2)
#define MASK_ETH_RCR_PRMS_MODE      (1<<BIT_ETH_RCR_PRMS_MODE)

/* Accept multicast */
#define BIT_ETH_RCR_ACC_MULTI       (1)
#define MASK_ETH_RCR_ACC_MULTI      (1<<BIT_ETH_RCR_ACC_MULTI)

/* Enable receiver */
#define BIT_ETH_RCR_RX_ENABLE       (0)
#define MASK_ETH_RCR_RX_ENABLE      (1<<BIT_ETH_RCR_RX_ENABLE)

/*
 * Definitions for ETH_TX_CNTL
 */

/* Memory size - 2048 bytes */
#define BIT_ETH_TCR_TX_MEM_SIZE     (6)
#define MASK_ETH_TCR_TX_MEM_SIZE    (3<<BIT_ETH_TCR_TX_MEM_SIZE)

/* Enable ethernet full duplex mode */
#define BIT_ETH_TCR_DUPLEX_MODE     (4)
#define MASK_ETH_TCR_DUPLEX_MODE    (1 << BIT_ETH_TCR_DUPLEX_MODE)

/* Append CRC to frames */
#define BIT_ETH_TCR_CRC_ENABLE      (2)
#define MASK_ETH_TCR_CRC_ENABLE     (1 << BIT_ETH_TCR_CRC_ENABLE)

/* Pad to minimum frame size */
#define BIT_ETH_TCR_PAD_ENABLE      (1)
#define MASK_ETH_TCR_PAD_ENABLE     (1 << BIT_ETH_TCR_PAD_ENABLE)

/* Enable transmitter */
#define BIT_ETH_TCR_TX_ENABLE       (0)
#define MASK_ETH_TCR_TX_ENABLE      (1 << BIT_ETH_TCR_TX_ENABLE)

/*
 * Definitions for ETH_TR_REQ
 */

/* Start packet write. */
#define BIT_ETH_TRR_NEXTX           (0)
#define MASK_ETH_TRR_NEXTX          (1<<BIT_ETH_TRR_NEXTX)

/*
 * Definitions for the physical interface
 */

#define BIT_ETHPHY_MISC_PHYAD       (0)
#define MASK_ETHPHY_MISC_PHYAD      (0x1F << BIT_ETHPHY_MISC_PHYAD)

#define BIT_ETHPHY_MISC_PWRDN       (8)
#define MASK_ETHPHY_MISC_PWRDN      (1 << BIT_ETHPHY_MISC_PWRDN)

#define BIT_ETHPHY_MISC_PWRSV       (9)
#define MASK_ETHPHY_MISC_PWRSV      (1 << BIT_ETHPHY_MISC_PWRSV)

#define BIT_ETHPHY_MISC_LED1_SEL    (16)
#define MASK_ETHPHY_MISC_LED1_SEL   (0x7 << BIT_ETHPHY_MISC_LED1_SEL)

#define BIT_ETHPHY_MISC_LED0_SEL    (20)
#define MASK_ETHPHY_MISC_LED0_SEL   (0x7 << BIT_ETHPHY_MISC_LED0_SEL)

/* Note: Below READ ONLY bits are available from FT900 Rev C */

/* Active LOW indicates the link speed is 100Mbps */
#define BIT_ETHPHY_MISC_LINK_SPEED_LED    (24)
#define MASK_ETHPHY_MISC_LINK_SPEED_LED   (0x1 << BIT_ETHPHY_MISC_LINK_SPEED_LED)

/* Active LOW indicates the status of the full-duplex mode. */
#define BIT_ETHPHY_MISC_FULL_DUPLEX_LED   (25)
#define MASK_ETHPHY_MISC_FULL_DUPLEX_LED  (0x1 << BIT_ETHPHY_MISC_FULL_DUPLEX_LED)

/* Active LOW indicates the presence of a collision. */
#define BIT_ETHPHY_MISC_COLLISION_LED     (26)
#define MASK_ETHPHY_MISC_COLLISION_LED    (0x1 << BIT_ETHPHY_MISC_COLLISION_LED)

/* Active LOW indicates the presence of an active receive. */
#define BIT_ETHPHY_MISC_RX_ACTIVITY       (27)
#define MASK_ETHPHY_MISC_RX_ACTIVITY      (0x1 << BIT_ETHPHY_MISC_RX_ACTIVITY)

/* Active LOW indicates the presence of an active transmit. */
#define BIT_ETHPHY_MISC_TX_ACTIVITY       (28)
#define MASK_ETHPHY_MISC_TX_ACTIVITY      (0x1 << BIT_ETHPHY_MISC_TX_ACTIVITY)

/* Link State: Active Low indicates a good link status for 10/100M.
   Traffic State: The traffic status is always ON (LOW) when the link is OK and toggles between the
   TX and RX state.*/
#define BIT_ETHPHY_MISC_LINK_TRAFFIC_LED  (29)
#define MASK_ETHPHY_MISC_LINK_TRAFFIC_LED (0x1 << BIT_ETHPHY_MISC_LINK_TRAFFIC_LED)

/* Link Status: 0: Link is down,1: Link is up. */
#define BIT_ETHPHY_MISC_LINK_STATUS       (31)
#define MASK_ETHPHY_MISC_LINK_STATUS      (0x1 << BIT_ETHPHY_MISC_LINK_STATUS)

/* TYPES ***************************************************************************/

/** \brief Interrupt Status Register
 *  \note: The individual status will still be reflected even if the individual interrupt has been
 *         disabled. This allows polling by software.
 */
typedef struct
{
  uint8_t RX_INT   : 1;   ///< Set when at least one packet is in the receiver’s FIFO.
                          ///< This status flag will be cleared by hardware when there is no packet
                          ///< in the receiver FIFO

  uint8_t TX_ERR   : 1;   ///< Set when an error on TX has been encountered. This occurs when the
                          ///< Data Length field value stored in the TX RAM exceeds 2032 in which
                          ///< case the frame will not be sent when this condition is encountered,
                          ///< or the retransmission attempt limit (16) has failed during a
                          ///< truncated binary exponential back off process. Write a 1 to clear the
                          ///< status flag. The write data pointer is also reset in this case.

  uint8_t TX_EMPTY : 1;   ///< Set when a packet has been sent. Write a 1 to clear the status flag.

  uint8_t FIFO_OV  : 1;   ///< Set when RX FIFO overrun is encountered. Write a 1 to clear the
                          ///< status flag.

  uint8_t RX_ERR   : 1;   ///< Set when an error on RX has been encountered. This occurs when the
                          ///< RXER input pin is sampled high during frame reception (100 Mbps only)
                          ///< or the frame is not an integer number of octets and the FCS check
                          ///< failed (dribble bits in frame) – alignment error, or the frame has a
                          ///< wrong CRC, or the length/type field is inconsistent with the client
                          ///< data size. Write a 1 to clear the status flag.

  uint8_t MD_INT   : 1;   ///< Set when a transaction on the MII management interface has completed
                          ///< successfully (either read or write). Write a 1 to clear the status
                          ///< flag.

  uint8_t Reserved : 2;   ///< Reserved
} eth_int_sts_reg_t;

typedef union
{
  eth_int_sts_reg_t B;
  REG_ACCESS_U8     U;
} eth_int_sts_reg_u;

/** \brief Interrupt Enable Register
 *  \details Setting a bit in this register enables the interrupt. Clearing a bit in this register
 *           disables the interrupt.
 */
typedef struct
{
  uint8_t RX_MASK       : 1;    ///< Mask for RX_INT interrupt
  uint8_t TX_ERR_MASK   : 1;    ///< Mask for TX_ERR_MASK interrupt
  uint8_t TX_EMPTY_MASK : 1;    ///< Mask for TX_EMPTY_MASK interrupt
  uint8_t FIFO_OV_MASK  : 1;    ///< Mask for FIFO_OV_MASK interrupt
  uint8_t RX_ERR_MASK   : 1;    ///< Mask for RX_ERR_MASK interrupt
  uint8_t MD_INT_MASK   : 1;    ///< Mask for MD_INT_MASK interrupt
  uint8_t Reserved      : 1;    ///< Reserved
} eth_int_ena_reg_t;

typedef union
{
  eth_int_ena_reg_t B;
  REG_ACCESS_U8     U;
} eth_int_ena_reg_u;

/** \brief Receive Control Register
 *  \details This register configures the receiver.
 */
typedef struct
{
  uint8_t RX_ENABLE   : 1;    ///< 1: Enable frame receiver
                              ///< 0: Disable frame receiver

  uint8_t ACC_MULTI   : 1;    ///< 1: Accept multicast; accepts all frames which have first bit of
                              ///<    Destination Address set.

  uint8_t PRMS_MODE   : 1;    ///< 1: Promiscuous mode enabled; all valid frames regardless of
                              ///<    destination address will be captured, including multicast and
                              ///<    broadcast frames.
                              ///< 0: Promiscuous mode disabled

  uint8_t BAD_CRC     : 1;    ///< 1: all frames with wrong CRC will be discarded; all valid frames
                              ///<    with broadcast address FF-FF-FF-FF-FFFF in the Destination
                              ///<    Address field are captured
                              ///< 0: do not drop frames with the wrong CRC. RX_ERR will still be
                              ///<    flagged to indicate an erroneous packet has been received. The
                              ///<    erroneous packet should be read out to make place for
                              ///<    subsequent packets.

  uint8_t RESET_FIFO  : 1;    ///< 1: clears the receiver FIFO; should be done when software
                              ///<    initialisation of MAC is needed. It is recommended to set
                              ///<    RX_ENABLE 0 first.

  uint8_t Reserved    : 1;    ///< Reserved

  uint8_t RX_MEM_SIZE : 2;    ///< Memory size – 2048 Bytes
} eth_rx_cntl_reg_t;

typedef union
{
  eth_rx_cntl_reg_t B;
  REG_ACCESS_U8     U;
} eth_rx_cntl_reg_u;

/** \brief Transmit Control Register
 *  \details This register configures the transmitter.
 */
typedef struct
{
  uint8_t TX_ENABLE   : 1;    ///< 1: Enable transmitter
                              ///< 0: Disable transmitter

  uint8_t PAD_ENABLE  : 1;    ///< 1: Padding will be appended to frames shorter than the minimum
                              ///<    frame size
                              ///< 0: Padding will not be appended to frames shorter than the
                              ///<    minimum frame size

  uint8_t CRC_ENABLE  : 1;    ///< 1: Frames will be sent with CRC appended
                              ///< 0: Frames will be sent without CRC appended

  uint8_t Reserved_3  : 1;    ///< Reserved

  uint8_t DUPLEX_MODE : 1;    ///< 1: Enable duplex mode for Ethernet transmitter
                              ///< 0: Disable duplex mode for Ethernet transmitter

  uint8_t Reserved_5  : 1;    ///< Reserved

  uint8_t TX_MEM_SIZE : 2;    ///< Memory size – 2048 Bytes
} eth_tx_cntl_reg_t;

typedef union
{
  eth_tx_cntl_reg_t B;
  REG_ACCESS_U8     U;
} eth_tx_cntl_reg_u;

/** \brief Data register */
typedef struct
{
  uint8_t ETH_DATA_N0;  ///< Data Register (octet n+0) For read/write from/to data buffer (RX/TX RAM)
  uint8_t ETH_DATA_N1;  ///< Data Register (octet n+1) For read/write from/to data buffer (RX/TX RAM)
  uint8_t ETH_DATA_N2;  ///< Data Register (octet n+2) For read/write from/to data buffer (RX/TX RAM)
  uint8_t ETH_DATA_N3;  ///< Data Register (octet n+3) For read/write from/to data buffer (RX/TX RAM)
} eth_data_reg_t;

typedef union
{
  eth_data_reg_t B;
  REG_ACCESS_U32 U;
} eth_data_reg_u;

/** \brief Address Register */
typedef struct
{
  uint8_t ETH_ADDR_1;   ///< Address Register (octet 1) MAC hardware address octet
  uint8_t ETH_ADDR_2;   ///< Address Register (octet 2) MAC hardware address octet
  uint8_t ETH_ADDR_3;   ///< Address Register (octet 3) MAC hardware address octet
  uint8_t ETH_ADDR_4;   ///< Address Register (octet 4) MAC hardware address octet
  uint8_t ETH_ADDR_5;   ///< Address Register (octet 5) MAC hardware address octet
  uint8_t ETH_ADDR_6;   ///< Address Register (octet 6) MAC hardware address octet
} eth_addr_reg_t;

/** \brief Threshold Register w*/
typedef struct
{
  uint8_t THRESHOLD : 6;  ///< This threshold specifies the threshold level for the TX RAM to begin
                          ///< transmission. When the byte count of the data in the TX RAM reaches
                          ///< this level, the transmission will start.
                          ///< Transmission starts when:
                          ///< Number of bytes written >= 4 * (THRESHOLD * 8 + 1)

  uint8_t Reserved  : 2;  ///< Reserved
} eth_threshold_reg_t;

typedef struct
{
  eth_threshold_reg_t B;
  REG_ACCESS_U8       U;
} eth_threshold_reg_u;

/** \brief Management Control Register
 *  \details This register is used to send management frames from the STA entity across the MII
 *           management interface.
 */
typedef struct
{
  uint8_t START       : 1;  ///< Setting this bit to 1 will initiate the transaction. Hardware
                            ///< clears this bit after the transaction is complete.

  uint8_t WRITE       : 1;  ///< This bit should be updated together with the START bit.
                            ///<   1: Perform write transaction
                            ///<   0: Perform read transaction

  uint8_t Reserved    : 1;  ///< Reserved

  uint8_t REG_ADDRESS : 5;  ///< These set the MII register address for the next transaction
} eth_mng_cntl_reg_t;

typedef union
{
  eth_mng_cntl_reg_t B;
  REG_ACCESS_U8      U;
} eth_mng_cntl_reg_u;

/** \brief Management Divider Register */
typedef struct
{
  uint8_t DIV;              ///< This is used to set the clock divider for the MDC clock used by the
                            ///< STA to clock transactions between PHY and MAC across the serial MII
                            ///< interface. The MDC clock is derived as follows:
                            ///< Fmdc = Fclk / (2 * (MDVR + 1))
} eth_mng_div_reg_t;

typedef union
{
  eth_mng_div_reg_t B;
  REG_ACCESS_U8     U;
} eth_mng_div_reg_u;

/** \brief Management Address Register */
typedef struct
{
  uint8_t PHY_ADDRESS : 5;  ///< This register should be updated with the PHY address.
  uint8_t Reserved    : 3;  ///< Reserved
} eth_mng_addr_reg_t;

typedef union
{
  eth_mng_addr_reg_t B;
  REG_ACCESS_U8      U;
} eth_mng_addr_reg_u;

/** \brief  Management Transmit Data Register */
typedef struct
{
  uint8_t ETH_MNG_TX0;      ///< This is the lower byte of a word of data to be sent across the MII
                            ///< management interface to the PHY during the next data transmission.

  uint8_t ETH_MNG_TX1;      ///< This is the upper byte of a word of data to be sent across the MII
                            ///< management interface to the PHY during the next data transmission.
} eth_mng_tx_reg_t;

typedef union
{
  eth_mng_tx_reg_t B;
  REG_ACCESS_U16   U;
} eth_mng_tx_reg_u;

/** \brief Management Receive Data Registers */
typedef struct
{
  uint8_t ETH_MNG_RX0;      ///< This is the lower byte of a word of data read by the STA management
                            ///< entity from the PHY during the last transaction.

  uint8_t ETH_MNG_RX1;      ///< This is the upper byte of a word of data read by the STA management
                            ///< entity from the PHY during the last transaction.
} eth_mng_rx_reg_t;

typedef union
{
  eth_mng_rx_reg_t B;
  REG_ACCESS_U8    U;
} eth_mng_rx_reg_u;

/** \brief Number of Packets Register */
typedef struct
{
  uint8_t NUM_PKT  : 6;     ///< This is the number of packets in the receive FIFO. When NPR is
                            ///< greater than 0, RXINT `interrupt will be active

  uint8_t Reserved : 2;     ///< Reserved
} eth_num_pkt_reg_t;

typedef union
{
  eth_num_pkt_reg_t B;
  REG_ACCESS_U8     U;
} eth_num_pkt_reg_t;

typedef struct
{
  uint8_t NEW_TX   : 1;     ///< 1: Send the new frame in transmit memory. Hardware clears this bit
                            ///<    when the transmission is complete, or an error on TX is
                            ///<    encountered.

  uint8_t Reserved : 7;     ///< Reserved
} eth_tr_req_reg_t;

typedef union
{
  eth_tr_req_reg_t B;
  REG_ACCESS_U8    U;
} eth_tr_req_reg_u;

/** @brief Register mappings for Ethernet MAC registers */
typedef struct
{
  __IO eth_int_sts_reg_u   ETH_INT_STATUS;
  __IO eth_int_ena_reg_u   ETH_INT_ENABLE;
  __IO eth_rx_cntl_reg_u   ETH_RX_CNTL;
  __IO eth_tx_cntl_reg_u   ETH_TX_CNTL;
  __IO eth_data_reg_u      ETH_DATA;
  __IO eth_addr_reg_t      ETH_ADDR;
  __IO eth_threshold_reg_u ETH_THRESHOLD;
  __IO eth_mng_cntl_reg_u  ETH_MNG_CNTL;
  __IO eth_mng_div_reg_u   ETH_MNG_DIV;
  __IO eth_mng_addr_reg_u  ETH_MNG_ADDR;
  __IO eth_mng_tx_reg_u    ETH_MNG_TX;
  __IO eth_mng_rx_reg_u    ETH_MNG_RX;
  __IO eth_num_pkt_reg_t   ETH_NUM_PKT;
  __IO eth_tr_req_reg_u    ETH_TR_REQ;
} eth_regs_t;

/** \brief Ethernet PHY Miscellaneous Configuration Register */
typedef struct
{
  uint32_t ETHERNET_PHYAD    : 5;   ///< Ethernet PHY Address

  uint32_t Reserved_5_7      : 3;   ///< Reserved

  uint32_t ETHERNET_PWRDN    : 1;   ///< 1: Ethernet PHY Power Down (Preferably Set this to 0 prior
                                    ///<    to enabling the MAC clock)

  uint32_t ETHERNET_PWRSV    : 1;   ///< 1: Ethernet PHY Power Save (Preferably Set this to 0 prior
                                    ///<    to enabling the MAC clock)

  uint32_t ETHERNET_LOOPBACK : 1;   ///< 0: Normal operation
                                    ///< 1: Ethernet loopback

  uint32_t Reserved_11_15    : 5;   ///< Reserved

  uint32_t ETHERNET_LED2_SEL : 3;   ///< Ethernet LED 2 source selection:
                                    ///< 0: LINKLED
                                    ///< 1: TXLED
                                    ///< 2: RXLED
                                    ///< 3: COLLED
                                    ///< 4: FDXLED
                                    ///< Others: SPDLED

  uint32_t Reserved_17       : 1;   ///< Reserved

  uint32_t ETHERNET_LED1_SEL : 3;   ///< Ethernet LED 1 source selection:
                                    ///< 0: LINKLED
                                    ///< 1: TXLED
                                    ///< 2: RXLED
                                    ///< 3: COLLED
                                    ///< 4: FDXLED
                                    ///< Others: SPDLED

  uint32_t Reserved_23_31    : 9;   ///< Reserved
} eth_phy_cfg_reg_t;

typedef union
{
  eth_phy_cfg_reg_t B;
  REG_ACCESS_U32    U;
} eth_phy_cfg_reg_u;

/** \brief Register mappings for Ethernet PHY registers */
typedef struct
{
  __IO eth_phy_cfg_reg_u ETH_PHY_CFG;
  __IO uint32_t          ETH_PHY_ID;
} eth_phy_conf_reg_t;

/** @brief Register mappings for Ethernet PHY registers */
typedef struct
{
  __IO uint32_t MISC;
  __IO uint32_t ID;
} ft900_eth_phy_conf_reg_t;

/** @brief Register mappings for Ethernet MAC registers */
typedef struct
{
  __IO uint8_t  ETH_INT_STATUS;
  __IO uint8_t  ETH_INT_ENABLE;
  __IO uint8_t  ETH_RX_CNTL;
  __IO uint8_t  ETH_TX_CNTL;
  __IO uint32_t ETH_DATA;
  __IO uint8_t  ETH_ADDR[6];
  __IO uint8_t  ETH_THRESHOLD;
  __IO uint8_t  ETH_MNG_CNTL;
  __IO uint8_t  ETH_MNG_DIV;
  __IO uint8_t  ETH_MNG_ADDR;
  __IO uint16_t ETH_MNG_TX0;
  __IO uint16_t ETH_MNG_RX0;
  __IO uint8_t  ETH_NUM_PKT;
  __IO uint8_t  ETH_TR_REQ;
} ft900_eth_regs_t;


/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#endif /* FT900_ETH_REGISTERS_H_ */
