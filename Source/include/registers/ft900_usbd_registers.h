/**
    @file ft900_usbd_registers.h

    @brief USBD (USB Device) registers
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

#ifndef FT900_USBD_REGISTERS_H_
#define FT900_USBD_REGISTERS_H_

/* INCLUDES ************************************************************************/

#include <stdint.h>

#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

#if defined(__FT930__)
#define USBD_MAX_ENDPOINT_COUNT           (16)
#else
#define USBD_MAX_ENDPOINT_COUNT           (8)
#endif

/** Bit masks for the USBD Common Interrupt register */
//@{
#define MASK_USBD_CMIF_ALL                (0xFF)
#define BIT_USBD_CMIF_PHYIRQ              (7)
#define MASK_USBD_CMIF_PHYIRQ             (1 << BIT_USBD_CMIF_PHYIRQ)
#define BIT_USBD_CMIF_PIDIRQ              (6)
#define MASK_USBD_CMIF_PIDIRQ             (1 << BIT_USBD_CMIF_PIDIRQ)
#define BIT_USBD_CMIF_CRC16IRQ            (5)
#define MASK_USBD_CMIF_CRC16IRQ           (1 << BIT_USBD_CMIF_CRC16IRQ)
#define BIT_USBD_CMIF_CRC5IRQ             (4)
#define MASK_USBD_CMIF_CRC5IRQ            (1 << BIT_USBD_CMIF_CRC5IRQ)
#define BIT_USBD_CMIF_RESIRQ              (3)
#define MASK_USBD_CMIF_RESIRQ             (1 << BIT_USBD_CMIF_RESIRQ)
#define BIT_USBD_CMIF_SUSIRQ              (2)
#define MASK_USBD_CMIF_SUSIRQ             (1 << BIT_USBD_CMIF_SUSIRQ)
#define BIT_USBD_CMIF_RSTIRQ              (1)
#define MASK_USBD_CMIF_RSTIRQ             (1 << BIT_USBD_CMIF_RSTIRQ)
#define BIT_USBD_CMIF_SOFIRQ              (0)
#define MASK_USBD_CMIF_SOFIRQ             (1 << BIT_USBD_CMIF_SOFIRQ)
//@}

/** Bit masks for the USBD Common Interrupt Enable register */
//@{
#define MASK_USBD_CMIE_ALL                (0xFF)
#define BIT_USBD_CMIE_PHYIE               (7)
#define MASK_USBD_CMIE_PHYIE              (1 << BIT_USBD_CMIE_PHYIE)
#define BIT_USBD_CMIE_PIDIE               (6)
#define MASK_USBD_CMIE_PIDIE              (1 << BIT_USBD_CMIE_PIDIE)
#define BIT_USBD_CMIE_CRC16IE             (5)
#define MASK_USBD_CMIE_CRC16IE            (1 << BIT_USBD_CMIE_CRC16IE)
#define BIT_USBD_CMIE_CRC5IE              (4)
#define MASK_USBD_CMIE_CRC5IE             (1 << BIT_USBD_CMIE_CRC5IE)
#define BIT_USBD_CMIE_RESIE               (3)
#define MASK_USBD_CMIE_RESIE              (1 << BIT_USBD_CMIE_RESIE)
#define BIT_USBD_CMIE_SUSIE               (2)
#define MASK_USBD_CMIE_SUSIE              (1 << BIT_USBD_CMIE_SUSIE)
#define BIT_USBD_CMIE_RSTIE               (1)
#define MASK_USBD_CMIE_RSTIE              (1 << BIT_USBD_CMIE_RSTIE)
#define BIT_USBD_CMIE_SOFIE               (0)
#define MASK_USBD_CMIE_SOFIE              (1 << BIT_USBD_CMIE_SOFIE)
//@}

/** Bit masks for the USBD EPIF Endpoint Interrupt Status register */
//@{
#define MASK_USBD_EPIF_IRQ(x)    (1 << (x))
#if defined(__FT930__)
#define BIT_USBD_EPIF_EP15IRQ             (15)
#define MASK_USBD_EPIF_EP15IRQ            (1 << BIT_USBD_EPIF_EP15IRQ)
#define BIT_USBD_EPIF_EP14IRQ             (14)
#define MASK_USBD_EPIF_EP14IRQ            (1 << BIT_USBD_EPIF_EP14IRQ)
#define BIT_USBD_EPIF_EP13IRQ             (13)
#define MASK_USBD_EPIF_EP13IRQ            (1 << BIT_USBD_EPIF_EP13IRQ)
#define BIT_USBD_EPIF_EP12IRQ             (12)
#define MASK_USBD_EPIF_EP12IRQ            (1 << BIT_USBD_EPIF_EP12IRQ)
#define BIT_USBD_EPIF_EP11IRQ             (11)
#define MASK_USBD_EPIF_EP11IRQ            (1 << BIT_USBD_EPIF_EP11IRQ)
#define BIT_USBD_EPIF_EP10IRQ             (10)
#define MASK_USBD_EPIF_EP10IRQ            (1 << BIT_USBD_EPIF_EP10IRQ)
#define BIT_USBD_EPIF_EP9IRQ              (9)
#define MASK_USBD_EPIF_EP9IRQ             (1 << BIT_USBD_EPIF_EP9IRQ)
#define BIT_USBD_EPIF_EP8IRQ              (8)
#define MASK_USBD_EPIF_EP8IRQ             (1 << BIT_USBD_EPIF_EP8IRQ)
#endif
#define BIT_USBD_EPIF_EP7IRQ              (7)
#define MASK_USBD_EPIF_EP7IRQ             (1 << BIT_USBD_EPIF_EP7IRQ)
#define BIT_USBD_EPIF_EP6IRQ              (6)
#define MASK_USBD_EPIF_EP6IRQ             (1 << BIT_USBD_EPIF_EP6IRQ)
#define BIT_USBD_EPIF_EP5IRQ              (5)
#define MASK_USBD_EPIF_EP5IRQ             (1 << BIT_USBD_EPIF_EP5IRQ)
#define BIT_USBD_EPIF_EP4IRQ              (4)
#define MASK_USBD_EPIF_EP4IRQ             (1 << BIT_USBD_EPIF_EP4IRQ)
#define BIT_USBD_EPIF_EP3IRQ              (3)
#define MASK_USBD_EPIF_EP3IRQ             (1 << BIT_USBD_EPIF_EP3IRQ)
#define BIT_USBD_EPIF_EP2IRQ              (2)
#define MASK_USBD_EPIF_EP2IRQ             (1 << BIT_USBD_EPIF_EP2IRQ)
#define BIT_USBD_EPIF_EP1IRQ              (1)
#define MASK_USBD_EPIF_EP1IRQ             (1 << BIT_USBD_EPIF_EP1IRQ)
#define BIT_USBD_EPIF_EP0IRQ              (0)
#define MASK_USBD_EPIF_EP0IRQ             (1 << BIT_USBD_EPIF_EP0IRQ)
//@}

/** Bit masks for the USBD EPIE Endpoint Interrupt Enable register */
//@{
#define BIT_USBD_EPIE_EP0IE               (0)
#define MASK_USBD_EPIE_EP0IE              (1 << BIT_USBD_EPIE_EP0IE)
#define BIT_USBD_EPIE_EP1IE               (1)
#define MASK_USBD_EPIE_EP1IE              (1 << BIT_USBD_EPIE_EP1IE)
#define BIT_USBD_EPIE_EP2IE               (2)
#define MASK_USBD_EPIE_EP2IE              (1 << BIT_USBD_EPIE_EP2IE)
#define BIT_USBD_EPIE_EP3IE               (3)
#define MASK_USBD_EPIE_EP3IE              (1 << BIT_USBD_EPIE_EP3IE)
#define BIT_USBD_EPIE_EP4IE               (4)
#define MASK_USBD_EPIE_EP4IE              (1 << BIT_USBD_EPIE_EP4IE)
#define BIT_USBD_EPIE_EP5IE               (5)
#define MASK_USBD_EPIE_EP5IE              (1 << BIT_USBD_EPIE_EP5IE)
#define BIT_USBD_EPIE_EP6IE               (6)
#define MASK_USBD_EPIE_EP6IE              (1 << BIT_USBD_EPIE_EP6IE)
#define BIT_USBD_EPIE_EP7IE               (7)
#define MASK_USBD_EPIE_EP7IE              (1 << BIT_USBD_EPIE_EP7IE)
//@}

/** Bit masks for the USBD FCTRL Device Mode register */
//@{
#define BIT_USBD_FCTRL_TST_MODE_ENABLE    (7)
#define MASK_USBD_FCTRL_TST_MODE_ENABLE   (1 << BIT_USBD_FCTRL_TST_MODE_ENABLE)
#define BIT_USBD_FCTRL_TST_MODE_SELECT1   (6)
#define MASK_USBD_FCTRL_TST_MODE_SELECT1  (1 << BIT_USBD_FCTRL_TST_MODE_SELECT1)
#define BIT_USBD_FCTRL_TST_MODE_SELECT0   (5)
#define MASK_USBD_FCTRL_TST_MODE_SELECT0  (1 << BIT_USBD_FCTRL_TST_MODE_SELECT0)
#define BIT_USBD_FCTRL_MODE_FS_ONLY       (1)
#define MASK_USBD_FCTRL_MODE_FS_ONLY      (1 << BIT_USBD_FCTRL_MODE_FS_ONLY)
#define BIT_USBD_FCTRL_USB_DEV_EN         (0)
#define MASK_USBD_FCTRL_USB_DEV_EN        (1 << BIT_USBD_FCTRL_USB_DEV_EN)
/* Bit 2 and Bit 3 in FCTRL register for improvement in the USB hardware in case
 * of FT900 C only
 * */
#define BIT_USBD_FCTRL_NYET               (2)
#define BIT_USBD_FCTRL_CONT_RW            (3)
#define MASK_USBD_FCTRL_IMP_PERF          ((1 << BIT_USBD_FCTRL_CONT_RW)|(1 << BIT_USBD_FCTRL_NYET))
//@}

/** Bit masks for the USBD EP0_STATUS Endpoint 0 Status register */
//@{
#define BIT_USBD_EP0SR_DATAEND            (4)
#define MASK_USBD_EP0SR_DATAEND           (1 << BIT_USBD_EP0SR_DATAEND)
#define BIT_USBD_EP0SR_STALL              (3)
#define MASK_USBD_EP0SR_STALL             (1 << BIT_USBD_EP0SR_STALL)
#define BIT_USBD_EP0SR_SETUP              (2)
#define MASK_USBD_EP0SR_SETUP             (1 << BIT_USBD_EP0SR_SETUP)
#define BIT_USBD_EP0SR_INPRDY             (1)
#define MASK_USBD_EP0SR_INPRDY            (1 << BIT_USBD_EP0SR_INPRDY)
#define BIT_USBD_EP0SR_OPRDY              (0)
#define MASK_USBD_EP0SR_OPRDY             (1 << BIT_USBD_EP0SR_OPRDY)
//@}

/** Bit masks for the USBD EP0_CONTROL Endpoint 0 Control register */
//@{
#define BIT_USBD_EP0CR_SDSTL              (0)
#define MASK_USBD_EP0CR_SDSTL             (1 << BIT_USBD_EP0CR_SDSTL)
#define BIT_USBD_EP0CR_SIZE0              (1)
#define MASK_USBD_EP0CR_SIZE0             (1 << BIT_USBD_EP0CR_SIZE0)
#define BIT_USBD_EP0CR_SIZE1              (2)
#define MASK_USBD_EP0CR_SIZE1             (1 << BIT_USBD_EP0CR_SIZE1)
/** EP0 Max Packet Sizes */
//@{
#define BIT_USBD_EP0_MAX_SIZE             BIT_USBD_EP0CR_SIZE0
#define MASK_USBD_EP0_MAX_SIZE            (3 << BIT_USBD_EP0_MAX_SIZE)
#define USBD_EP0_MAX_SIZE_8               (0)
#define USBD_EP0_MAX_SIZE_16              (1)
#define USBD_EP0_MAX_SIZE_32              (2)
#define USBD_EP0_MAX_SIZE_64              (3)
//@}
//@}

/** Bit masks for the USBD EPx_STATUS Endpoints 1-7 Status registers */
//@{
#define BIT_USBD_EPxSR_CLR_TOGGLE         (7)
#define MASK_USBD_EPxSR_CLR_TOGGLE        (1 << BIT_USBD_EPxSR_CLR_TOGGLE)
#define BIT_USBD_EPxSR_FIFO_FLUSH         (6)
#define MASK_USBD_EPxSR_FIFO_FLUSH        (1 << BIT_USBD_EPxSR_FIFO_FLUSH)
#define BIT_USBD_EPxSR_DATA_ERR           (5)
#define MASK_USBD_EPxSR_DATA_ERR          (1 << BIT_USBD_EPxSR_DATA_ERR)
#define BIT_USBD_EPxSR_SEND_STALL         (4)
#define MASK_USBD_EPxSR_SEND_STALL        (1 << BIT_USBD_EPxSR_SEND_STALL)
#define BIT_USBD_EPxSR_UNDER_RUN          (3)
#define MASK_USBD_EPxSR_UNDER_RUN         (1 << BIT_USBD_EPxSR_UNDER_RUN)
#define BIT_USBD_EPxSR_OVER_RUN           (2)
#define MASK_USBD_EPxSR_OVER_RUN          (1 << BIT_USBD_EPxSR_OVER_RUN)
#define BIT_USBD_EPxSR_INPRDY             (1)
#define MASK_USBD_EPxSR_INPRDY            (1 << BIT_USBD_EPxSR_INPRDY)
#define BIT_USBD_EPxSR_OPRDY              (0)
#define MASK_USBD_EPxSR_OPRDY             (1 << BIT_USBD_EPxSR_OPRDY)
//@}

/** Bit masks for the USBD EPx_CONTROL Endpoints 1-7 Control registers */
//@{
#define BIT_USBD_EPxCR_DB                 (7)
#define MASK_USBD_EPxCR_DB                (1 << BIT_USBD_EPxCR_DB)
#define BIT_USBD_EPxCR_SIZE2              (6)
#define MASK_USBD_EPxCR_SIZE2             (1 << BIT_USBD_EPxCR_SIZE2)
#define BIT_USBD_EPxCR_SIZE1              (5)
#define MASK_USBD_EPxCR_SIZE1             (1 << BIT_USBD_EPxCR_SIZE1)
#define BIT_USBD_EPxCR_SIZE0              (4)
#define MASK_USBD_EPxCR_SIZE0             (1 << BIT_USBD_EPxCR_SIZE0)
#define BIT_USBD_EPxCR_SDSTL              (3)
#define MASK_USBD_EPxCR_SDSTL             (1 << BIT_USBD_EPxCR_SDSTL)
#define BIT_USBD_EPxCR_MODE1              (2)
#define MASK_USBD_EPxCR_MODE1             (1 << BIT_USBD_EPxCR_MODE1)
#define BIT_USBD_EPxCR_MODE0              (1)
#define MASK_USBD_EPxCR_MODE0             (1 << BIT_USBD_EPxCR_MODE0)
#define BIT_USBD_EPxCR_DIR                (0)
#define MASK_USBD_EPxCR_DIR               (1 << BIT_USBD_EPxCR_DIR)
/** EPx Max Packet Sizes */
//@{
#define BIT_USBD_EP_MAX_SIZE              BIT_USBD_EPxCR_SIZE0
#define MASK_USBD_EP_MAX_SIZE             (7 << BIT_USBD_EP_MAX_SIZE)

#define USBD_EP_MAX_SIZE_8                (0)
#define USBD_EP_MAX_SIZE_16               (1)
#define USBD_EP_MAX_SIZE_32               (2)
#define USBD_EP_MAX_SIZE_64               (3)
#define USBD_EP_MAX_SIZE_128              (4)
#define USBD_EP_MAX_SIZE_256              (5)
#define USBD_EP_MAX_SIZE_512              (6)
#define USBD_EP_MAX_SIZE_1024             (7)
//@}
/** EPx Endpoint Types */
//@{
#define BIT_USBD_EP_CONTROL_DIS           BIT_USBD_EPxCR_MODE0
#define MASK_USBD_DIS                     (3 << BIT_USBD_EP_CONTROL_DIS)
#define USBD_EP_DIS_BULK                  (1)
#define USBD_EP_DIS_INT                   (2)
#define USBD_EP_DIS_ISO                   (3)
//@}
//@}

/* TYPES ***************************************************************************/

/** \brief Interrupt Enable Register */
typedef struct
{
  uint8_t SOF_IE   : 1;   ///< Start of Frame interrupt enable
  uint8_t RST_IE   : 1;   ///< Reset interrupt enable
  uint8_t SUS_IE   : 1;   ///< Suspend interrupt enable
  uint8_t RESM_IE  : 1;   ///< Resume interrupt enable
  uint8_t CRC5_IE  : 1;   ///< CRC5 error interrupt enable
  uint8_t CRC16_IE : 1;   ///< CRC16 error interrupt enable
  uint8_t PID_IE   : 1;   ///< Package ID error interrupt enable
  uint8_t PHY_IE   : 1;   ///< PHY receive error interrupt enable
} usbd_dc_int_ena_reg_t;

/** \brief Interrupt Enable Register */
typedef union
{
  usbd_dc_int_ena_reg_t B;
  REG_ACCESS_U8         U;
} usbd_dc_int_ena_reg_u;

/** \brief Mode Register */
typedef struct
{
  uint8_t USB_DEV_EN      : 1;  ///< USB function enables. Setting this to 1 enables the USB device

  uint8_t FS_ONLY         : 1;  ///< Setting this to 1 disables HS detection handshake

  uint8_t Reserved_2_4    : 3;  ///< Reserved

  uint8_t TST_MODE_SELECT : 2;  ///< Test Mode select (writeable only if MODE_ENABLE is 0)
                                ///<     2’h0: SE0_NAK
                                ///<     2’h1: J
                                ///<     2’h2: K
                                ///<     2’h3: Packet

  uint8_t TST_MODE_ENABLE : 1;  ///< Test Mode Enable. Setting this to 1 to enter the test mode. It
                                ///< can only be cleared by hardware reset.
} usbd_dc_mode_reg_t;

/** \brief Mode Register */
typedef union
{
  usbd_dc_mode_reg_t B;
  REG_ACCESS_U8      U;
} usbd_dc_mode_reg_u;

/** \brief Endpoints Interrupt Enable Register
 *  \details This register enables the different interrupt sources based on the specific endpoints
 *           by writing 1 to the corresponding bit.
 */
typedef struct
{
  uint8_t EP0_IE : 1;   ///< Endpoint 0 interrupt enable
  uint8_t EP1_IE : 1;   ///< Endpoint 1 interrupt enable
  uint8_t EP2_IE : 1;   ///< Endpoint 2 interrupt enable
  uint8_t EP3_IE : 1;   ///< Endpoint 3 interrupt enable
  uint8_t EP4_IE : 1;   ///< Endpoint 4 interrupt enable
  uint8_t EP5_IE : 1;   ///< Endpoint 5 interrupt enable
  uint8_t EP6_IE : 1;   ///< Endpoint 6 interrupt enable
  uint8_t EP7_IE : 1;   ///< Endpoint 7 interrupt enable
} usbd_dc_ep_int_ena_reg_t;

/** \brief Endpoints Interrupt Enable Register */
typedef union
{
  usbd_dc_ep_int_ena_reg_t B;
  REG_ACCESS_U8            U;
} usbd_dc_ep_int_ena_reg_u;

/** \brief Address Register
 *  \details This register sets the USB assigned address sent from the USB host and enables the USB
 *           peripheral. In response to the standard USB request SET_ADDRESS, the firmware must
 *           write the peripheral address to this register.
 */
typedef struct
{
  uint8_t ADDR   : 7;   ///< Function Address

  uint8_t ENABLE : 1;   ///< Hardware sets this to 1 when software writes a new address to this
                        ///< register. It is cleared by hardware at the end of the current transfer
                        ///< when the new address will take effect.
} usbd_dc_addr_ena_reg_t;

/** \brief Address Register */
typedef union
{
  usbd_dc_addr_ena_reg_t B;
  REG_ACCESS_U8          U;
} usbd_dc_addr_ena_reg_u;

/** \brief Endpoint 0 Control Register
 *  \details This register configures the maximum packet size of the control endpoint 0. It is also
 *           used to stall the control endpoint.
 */
typedef struct
{
  uint8_t STALL    : 1;   ///< Send STALL
                          ///< Software writes 1 to send a STALL handshake in response to an IN
                          ///< token. Software writes 0 to terminate the STALL signalling.

  uint8_t EP_SIZE  : 2;   ///< Endpoint Maximum packet size
                          ///<     2’h0: 8  bytes
                          ///<     2’h1: 16 bytes
                          ///<     2’h2: 32 bytes
                          ///<     2’h3: 64 bytes

  uint8_t Reserved : 5;   ///< Reserved
} usbd_dc_ep0_ctrl_reg_t;

/** \brief Endpoint 0 Control Register */
typedef union
{
  usbd_dc_ep0_ctrl_reg_t B;
  REG_ACCESS_U8          U;
} usbd_dc_ep0_ctrl_reg_u;

/** \brief Endpoint 0 Status Register */
typedef struct
{
  uint8_t OUT_PKT_RDY  : 1;   ///< OUT packet ready.
                              ///< Hardware sets this bit to 1 and generates an interrupt when a
                              ///< data packet has been received. Software writes 1 to clear it
                              ///< after unloading the data packet from the endpoint 0 OUT FIFO.

  uint8_t IN_PKT_RDY   : 1;   ///< IN packet ready.
                              ///< Software should write 1 to it after loading a data packet into
                              ///< the endpoint 0 IN FIFO. Hardware clears it and generates an
                              ///< interrupt when the data packet has been successfully transmitted.

  uint8_t SETUP        : 1;   ///< SETUP token received.
                              ///< Hardware sets this to 1 and interrupts when the SETUP token has
                              ///< been received. Software writes 1 to clear it.

  uint8_t STALL        : 1;   ///< Sent STALL.
                              ///< Hardware sets this to 1 when the STALL handshake has been
                              ///< transmitted. Software writes 1 to clear it.

  uint8_t DATA_END     : 1;   ///< Data End.
                              ///< Software should update this bit to 1 when writing:
                              ///<  - 1 to IN_PKT_RDY for last outgoing data packet
                              ///<  - 1 to IN_PKT_RDY for a zero-length data packet
                              ///<  - 1 to OUT_PKT_RDY after servicing the last incoming data packet

  uint8_t Reserved_5_7 : 3;   ///< Reserved
} usbd_dc_ep0_sts_reg_t;

/** \brief Endpoint 0 Status Register */
typedef union
{
  usbd_dc_ep0_sts_reg_t B;
  REG_ACCESS_U8         U;
} usbd_dc_ep0_sts_reg_u;

/** \brief Endpoint 0 Buffer Length Register */
typedef struct
{
  uint8_t BUF_LEN  : 7;   ///< Indicates the number of data bytes received. Valid only if
                          ///< OUT_PKT_RDY is 1.

  uint8_t Reserved : 1;   ///< Reserved
} usbd_dc_ep0_buff_len_reg_t;

/** \brief Endpoint 0 Buffer Length Register */
typedef union
{
  usbd_dc_ep0_buff_len_reg_t B;
  REG_ACCESS_U8              U;
} usbd_dc_ep0_buff_len_reg_u;

/** \brief Endpoint 0 Buffer Register */
typedef struct
{
  uint8_t DATA;           ///< Endpoint 0 FIFO window register. A read unloads one data byte from
                          ///< the Endpoint 0 OUT FIFO. A write loads one data byte into the
                          ///< Endpoint 0 IN FIFO.
} usbd_ep0_buff_reg_t;

/** \brief Endpoint 0 Buffer Register */
typedef union
{
  usbd_ep0_buff_reg_t B;
  REG_ACCESS_U8       U;
} usbd_ep0_buff_reg_u;

/** \brief Control Endpoint 0 Data Flow Registers */
typedef struct
{
  usbd_dc_ep0_ctrl_reg_u     DC_EP0_CONTROL;        ///< 1C
  uint8_t                    Reserved_1B_1F[3];     ///< 1D 1E 1F
  usbd_dc_ep0_sts_reg_u      DC_EP0_STATUS;         ///< 20
  uint8_t                    Reserved_21_23[3];     ///< 21 22 23
  usbd_dc_ep0_buff_len_reg_u DC_EP0_BUFFER_LENGTH;  ///< 24
  uint8_t                    Reserved_25_27[3];     ///< 25 26 27
  usbd_ep0_buff_reg_u        DC_EP0_BUFFER;         ///< 28
  uint8_t                    Reserved_29_2B[3];     ///< 29 2A 2B
} usbd_ep0_regs_t;

/** \brief Endpoint Control Registers
 *  \details The different endpoints are configured by writing to the corresponding endpoint control
 *           register selected based on the corresponding offset address. This register is used to
 *           configure the endpoint type, direction, maximum packet size and double buffering. It is
 *           also used to stall the corresponding data endpoint.
 *  \note Address offset: 0x2C/0x3C/0x4C/0x5C/0x6C/0x7C/0x8C
 */
typedef struct
{
  uint8_t EP_DIR  : 1;  ///< Endpoint Direction. This parameter has to be fixed during the Set
                        ///< Configuration request.
                        ///<     0x0: EP direction selected as OUT
                        ///<     0x1: EP direction selected as IN

  uint8_t EP_MODE : 2;  ///< Endpoint Mode. This parameter has to be fixed during the Set
                        ///< Configuration request.
                        ///<     0x0: EP disabled
                        ///<     0x1: EP configured for bulk transfers
                        ///<     0x2: EP configured for interrupt transfers
                        ///<     0x3: EP configured for isochronous transfers

  uint8_t STALL   : 1;  ///< Send STALL. Valid only when the Endpoint is in bulk or interrupt mode.
                        ///< Software should write a 1 to this bit to send a STALL handshake in
                        ///< response to IN token, PING token and data phase of OUT transaction.
                        ///< Software should write a 0 to this bit to terminate the STALL
                        ///< signalling.

  uint8_t EP_SIZE : 3;  ///< Endpoint Maximum packet size. This parameter has to be fixed during the
                        ///< Set Configuration request.
                        ///<     0x0: 8    bytes
                        ///<     0x1: 16   bytes
                        ///<     0x2: 32   bytes
                        ///<     0x3: 64   bytes
                        ///<     0x4: 128  bytes
                        ///<     0x5: 256  bytes
                        ///<     0x6: 512  bytes
                        ///<     0x7: 1024 bytes

  uint8_t DBL_BUF : 1;  ///< Endpoint double buffering Enable.
                        ///<     0: double buffering disabled
                        ///<     1: double buffering enabled
} usbd_ep_X_ctrl_reg_t;

/** \brief Endpoint Control Registers */
typedef union
{
  usbd_ep_X_ctrl_reg_t B;
  REG_ACCESS_U8       U;
} usbd_ep_X_ctrl_reg_u;

/** \brief Endpoint Status Registers
 *  \details The different endpoint statuses are read by accessing the corresponding status
 *           register. The hardware reports the endpoint status in this register. Write a 1 to the
 *           corresponding register bit to clear the bit.
 *  \note Address offset: 0x30/0x40/0x50/0x60/0x70/0x80/0x90
 */
typedef struct
{
  uint8_t OUT_PKT_RDY : 1;  ///< OUT packet ready. Valid only when the Endpoint direction is OUT.
                            ///< Hardware sets this bit to 1 and generates an interrupt when a data
                            ///< packet has been received. Software writes a 1 to clear it after
                            ///< unloading the data packet from the Endpoint OUT FIFO.

  uint8_t IN_PKT_RDY  : 1;  ///< IN packet ready. Valid only when the Endpoint direction is IN.
                            ///< Software should write a 1 to this bit after loading a data packet
                            ///< into the Endpoint IN FIFO.
                            ///< Hardware clears this bit and generates an interrupt when the data
                            ///< packet has been successfully transmitted

  uint8_t OVER_RUN    : 1;  ///< Data overrun. Valid only when the Endpoint is in isochronous mode
                            ///< and the direction is OUT. Hardware sets this bit to 1 if a received
                            ///< packet cannot be loaded into the Endpoint FIFO. Software can clear
                            ///< this bit by writing a 1 to this bit.

  uint8_t UNDER_RUN   : 1;  ///< Data underrun. Valid only when the Endpoint direction is IN. Its
                            ///< function is dependent upon the Endpoint mode:
                            ///< Isochronous: Hardware sets this to 1 when a zero-length packet is
                            ///< sent in response to an IN token while IN_PKT_RDY is 0.
                            ///< Bulk/Interrupt: Hardware sets this to 1 when a NAK packet is sent
                            ///< in response to an IN token while IN_PKT_RDY is 0. Software can
                            ///< clear this bit by writing a 1 to this bit.

  uint8_t STALL       : 1;  ///< Sent STALL. Valid only when the Endpoint is in bulk or interrupt
                            ///< mode. Hardware sets this bit to 1 when the STALL handshake is
                            ///< transmitted. Software can clear this bit by writing a 1 to this bit

  uint8_t DATA_ERR    : 1;  ///< Data error. Valid only when the Endpoint is in isochronous mode and
                            ///< the direction is OUT. This flag is set to 1 by hardware if a
                            ///< received packet has a CRC-16 error. It is automatically cleared
                            ///< when software clears the OUT_PKT_RDY bit.

  uint8_t FIFO_FLUSH  : 1;  ///< FIFO Flush. Valid only when the EP direction is IN. Writing 1 to
                            ///< this bit flushes the next packet to be transmitted from the
                            ///< Endpoint IN FIFO. The FIFO pointer is reset and the IN_PKT_RDY bit
                            ///< is cleared. Hardware resets the FLUSH bit to 0 when the FIFO flush
                            ///< is complete.

  uint8_t CLR_TOGGLE  : 1;  ///< Clear data toggle. Software can write a 1 to this bit to reset the
                            ///< Endpoint data toggle to 0. This bit is always read as 0.
} usbd_ep_X_sts_reg_t;

/** \brief Endpoint Status Registers */
typedef union
{
  usbd_ep_X_sts_reg_t B;
  REG_ACCESS_U8       U;
} usbd_ep_X_sts_reg_u;

/** \brief Endpoint Buffer Length LSB Registers
 *  \details The different endpoint buffer length is read by accessing the corresponding buffer
 *           length register. This register reports the LSB of the OUT-buffer length.
 *  \note Address offset: 0x34/0x44/0x54/0x64/0x74/0x84/0x94
 */
typedef struct
{
  uint8_t BUF_LEN_LSB;  ///< Indicates the low byte of the number of received data bytes in the
                        ///< Endpoint FIFO. Valid only if OUT_PKT_RDY is 1.
} usbd_ep_X_buf_len_lsb_reg_t;

/** \brief Endpoint Buffer Length LSB Registers */
typedef union
{
  usbd_ep_X_buf_len_lsb_reg_t B;
  REG_ACCESS_U8               U;
} usbd_ep_X_buf_len_lsb_reg_u;

/** \brief Endpoint Buffer Length MSB Registers
 *  \brief The different endpoint buffer length is read by accessing the corresponding buffer length
 *         register. This register reports the MSB of the OUT-buffer length.
 *  \note Address offset: 0x35/0x45/0x55/0x65/0x75/0x85/0x95
 */
typedef struct
{
  uint8_t BUF_LEN_MSB : 3;  ///< Indicates the high 3-bit of the number of received data bytes in
                            ///< the Endpoint FIFO. Valid only if OUT_PKT_RDY is 1.

  uint8_t Reserved    : 5;  ///< Reserved
} usbd_ep_X_buf_len_msb_reg_t;

/** \brief Endpoint Buffer Length MSB Registers */
typedef union
{
  usbd_ep_X_buf_len_msb_reg_t B;
  REG_ACCESS_U8               U;
} usbd_ep_X_buf_len_msb_reg_u;

/** \brief Endpoint Buffer Registers
 *  \details The different endpoint buffer is accessed by accessing the corresponding buffer
 *           register.
 *  \note Address offset: 0x38/0x48/0x58/0x68/0x78/0x88/0x98
 */
typedef struct
{
  uint8_t BUFFER;   ///< Endpoint FIFO window register. A read unloads one data byte from the
                    ///< Endpoint OUT FIFO. A write loads one data byte into the Endpoint IN FIFO.
} usbd_ep_X_buf_reg_t;

/** \brief Endpoint Buffer Registers */
typedef union
{
  usbd_ep_X_buf_reg_t B;
  REG_ACCESS_U8       U;
} usbd_ep_X_buf_reg_u;

/** \brief Endpoint Data Flow Registers
 *  \details This is a set of registers used to access the other endpoints from endpoint 1 to
 *           endpoint 7. The register definitions are the same for the registers from endpoint 1 to
 *           endpoint 7 but they are located at different offset addresses.
 */
typedef struct
{
  usbd_ep_X_ctrl_reg_u        DC_EP_X_CONTROL;            ///< 2C       - 00
  uint8_t                     Reserved_01_03;             ///< 2D 2E 2F - 01 02 03
  usbd_ep_X_sts_reg_u         DC_EP_X_STATUS;             ///< 30       - 04
  uint8_t                     Reserved_05_07;             ///< 31 32 33 - 05 06 07
  usbd_ep_X_buf_len_lsb_reg_u DC_EP_X_BUFFER_LENGTH_LSB;  ///< 34       - 08
  usbd_ep_X_buf_len_msb_reg_u DC_EP_X_BUFFER_LENGTH_MSB;  ///< 35       - 09
  uint8_t                     Reserved_0A_0B;             ///< 36 37    - 0A 0B
  usbd_ep_X_buf_reg_u         DC_EP_X_BUFFER;             ///< 38       - 0C
  uint8_t                     Reserved_0D_0F;             ///< 39 3A 3B - 0D 0E OF
} usbd_ep_X_regs_t;

/** \brief USBD device register definition */
typedef struct
{
       uint8_t                  Reserved_00_07[8];                        ///< 00 - 07: Reserved
  __IO usbd_dc_int_ena_reg_u    DC_INT_ENABLE;                            ///< 08
       uint8_t                  Reserved_09_0B[3];                        ///< 09 - 0B: Reserved
  __IO usbd_dc_ep_int_ena_reg_u DC_EP_INT_ENABLE;                         ///< 0C
       uint8_t                  Reserved_0D_0F[3];                        ///< 0D - 0F: Reserved
  __IO usbd_dc_mode_reg_u       DC_MODE;                                  ///< 10
       uint8_t                  Reserved_11_17[7];                        ///< 11 - 17: Reserved
  __IO usbd_dc_addr_ena_reg_u   DC_ADDRESS_ENABLE;                        ///< 18
       uint8_t                  Reserved_19_1B[7];                        ///< 19 - 1B: Reserved

  /* Endpoint register list */
  __IO usbd_ep0_regs_t          USBD_EP_0;                                ///< 1C - 2B: EP 0
  __IO usbd_ep_X_regs_t         USBD_EP_X[USBD_MAX_ENDPOINT_COUNT - 1];   ///< EP register list
} usbd_regs_t;

/** \brief USBD device register definition **/
#define USBD_REG_ALIGN32 __attribute__ ((aligned (4)))

typedef volatile struct
{
  uint8_t  cmif  USBD_REG_ALIGN32;      /// 0x00 -
  uint16_t epif  USBD_REG_ALIGN32;      /// 0x04 - word
  uint8_t  cmie  USBD_REG_ALIGN32;      /// 0x08 -
  uint16_t epie  USBD_REG_ALIGN32;      /// 0x0c - word
  uint8_t  fctrl USBD_REG_ALIGN32;      /// 0x10 -
  uint16_t frame USBD_REG_ALIGN32;      /// 0x14 - word
  uint8_t  faddr USBD_REG_ALIGN32;      /// 0x18 -
  struct
  {
    uint8_t  epxcr   USBD_REG_ALIGN32;  /// 0x1c -
    uint8_t  epxsr   USBD_REG_ALIGN32;  /// 0x20 -
    uint16_t epxcnt  USBD_REG_ALIGN32;  /// 0x24 - word
    uint8_t  epxfifo USBD_REG_ALIGN32;  /// 0x28 -
  } ep[USBD_MAX_ENDPOINT_COUNT];
} ft900_usbd_regs_t;

#undef USBD_REG_ALIGN32

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/** \brief USBD Register Access
 *  \details Macros to address registers in the USBD space. Register names from the
 *           ft900_USBD_regs_t structure are used.
 *           For example: status = *((uint8_t *)&USBD->cmif); will be written as
 *           status = USBD_REG(cmif);
 */
//@{
#define USBD_REG(A)         (USBD->A)
#define USBD_EP_CR_REG(B)   (USBD->ep[B].epxcr)
#define USBD_EP_SR_REG(B)   (USBD->ep[B].epxsr)
#define USBD_EP_CNT_REG(B)  (USBD->ep[B].epxcnt)
#define USBD_EP_FIFO_REG(B) (USBD->ep[B].epxfifo)
//@}

/** @name    Definitions for USBD RAM sizes.
 *
 *  @details Definitions for maximum amount of RAM available for endpoints. There is a total of 2 kB
 *           of RAM for IN endpoints and another 2 kB for OUT endpoints (excluding the RAM allocated
 *           to endpoint 0). Therefore the total max packet for all IN endpoints and OUT endpoints
 *           must be less than this figure. If double buffering is employed for an endpoint then it
 *           will use twice the amount of RAM.
 */
//@{
#if defined(__FT930__)
#define USBD_RAMTOTAL_IN    (4096)
#define USBD_RAMTOTAL_OUT   (4096)
#else
#define USBD_RAMTOTAL_IN    (sys_check_ft900_revB()?2048:3072)
#define USBD_RAMTOTAL_OUT   (sys_check_ft900_revB()?2048:3072)
#endif
//@}


/* FUNCTION PROTOTYPES *************************************************************/


#endif /* FT900_USBD_REGISTERS_H_ */
