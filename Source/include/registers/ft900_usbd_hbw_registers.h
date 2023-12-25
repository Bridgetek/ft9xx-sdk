/**
    @file ft900_usbd_hbw_registers.h

    @brief High Bandwidth ISO configuration registers
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


#ifndef FT900_USBD_HBW_REGISTERS_H_
#define FT900_USBD_HBW_REGISTERS_H_

/* INCLUDES ************************************************************************/

#include <stdint.h>

#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

/** Bit masks for the USBD HBW ISO IN control registers */

//@{
#define BIT_USBD_HBW_CTRL0_HBW_INI      (7)
#define MASK_USBD_HBW_CTRL0_HBW_INI     (1 << BIT_USBD_HBW_CTRL0_HBW_INI)
#define BIT_USBD_HBW_CTRL0_OVERRUN      (6)
#define MASK_USBD_HBW_CTRL0_OVERRUN     (1 << BIT_USBD_HBW_CTRL0_OVERRUN)
#define BIT_USBD_HBW_CTRL0_PTSON        (4)
#define MASK_USBD_HBW_CTRL0_PTSON       (1 << BIT_USBD_HBW_CTRL0_PTSON)
#define BIT_USBD_HBW_CTRL0_SCRON        (3)
#define MASK_USBD_HBW_CTRL0_SCRON       (1 << BIT_USBD_HBW_CTRL0_SCRON)
#define BIT_USBD_HBW_CTRL0_SET_STILL    (2)
#define MASK_USBD_HBW_CTRL0_SET_STILL   (1 << BIT_USBD_HBW_CTRL0_SET_STILL)
#define BIT_USBD_HBW_CTRL0_SET_ERROR    (1)
#define MASK_USBD_HBW_CTRL0_SET_ERROR   (1 << BIT_USBD_HBW_CTRL0_SET_ERROR)
#define BIT_USBD_HBW_CTRL0_AUTO_HEADER  (0)
#define MASK_USBD_HBW_CTRL0_AUTO_HEADER (1 << BIT_USBD_HBW_CTRL0_AUTO_HEADER)
//@}

//@{
#define BIT_USBD_HBW_CTRL1_FIFO_SIZE    (0)
#define MASK_USBD_HBW_CTRL1_FIFO_SIZE   (0x7F << BIT_USBD_HBW_CTRL1_FIFO_SIZE)
//@}

//@{
#define BIT_USBD_HBW_CTRL2_MAXPKTSIZE   (4)
#define MASK_USBD_HBW_CTRL2_MAXPKTSIZE  (0xF << BIT_USBD_HBW_CTRL2_MAXPKTSIZE)
#define BIT_USBD_HBW_CTRL2_HBWMODE      (2)
#define MASK_USBD_HBW_CTRL2_HBWMODE     (0x3 << BIT_USBD_HBW_CTRL2_HBWMODE)
#define BIT_USBD_HBW_CTRL2_THRESH_SEL   (0)
#define MASK_USBD_HBW_CTRL2_THRESH_SEL  (0x3 << BIT_USBD_HBW_CTRL2_THRESH_SEL)
//@}

//@{
#define BIT_USBD_HBW_CTRL3_HAVESPACE    (7)
#define MASK_USBD_HBW_CTRL3_HAVESPACE   (1 << BIT_USBD_HBW_CTRL3_HAVESPACE)
#define BIT_USBD_HBW_CTRL3_FULL         (6)
#define MASK_USBD_HBW_CTRL3_FULL        (1 << BIT_USBD_HBW_CTRL3_FULL)
#define BIT_USBD_HBW_CTRL3_INPRDY       (5)
#define MASK_USBD_HBW_CTRL3_INPRDY      (1 << BIT_USBD_HBW_CTRL3_INPRDY)
#define BIT_USBD_HBW_CTRL3_SEQDATA_END  (4)
#define MASK_USBD_HBW_CTRL3_SEQDATA_END (1 << BIT_USBD_HBW_CTRL3_SEQDATA_END)
#define BIT_USBD_HBW_CTRL3_ENDP_NUM     (0)
#define MASK_USBD_HBW_CTRL3_ENDP_NUM    (0xF << BIT_USBD_HBW_CTRL3_ENDP_NUM)
//@}

//@{
#define BIT_USBD_HBW_INTERRUPT_EN       (0)
#define MASK_USBD_HBW_INTERRUPT_EN      (0x7F << BIT_USBD_HBW_INTERRUPT_EN)
//@}

//@{
#define BIT_USBD_HBW_INTERRUPT_STATUS   (0)
#define MASK_USBD_HBW_INTERRUPT_STATUS  (1 << BIT_USBD_HBW_INTERRUPT_STATUS)
//@}

/* TYPES ***************************************************************************/

/** @brief Register mappings for High bandwidth ISO IN endpoint configuration registers */
typedef struct
{
  __IO uint8_t auto_header;
  __IO uint8_t set_error;
  __IO uint8_t set_still;
  __IO uint8_t scron;
  __IO uint8_t ptson;
  __IO uint8_t reserved;
  __IO uint8_t overrun;
  __IO uint8_t hbw_ini;
} ft900_usbd_hbw_header_ctrl_regs_t;

/** \brief High-bandwidth Isochronous Control Register 0 */
typedef struct
{
  uint8_t AUTO_HEADER : 1;  ///< Automatically inserts the UVC header and transfer the existing FIFO
                            ///< data on the USB bus.
                            ///<     1: Enabled
                            ///<     0: Disabled
                            ///< In this mode, the FIFO size can be set up to 16 kB (note that the
                            ///< actual memory available is limited to 6 kB). The HBW engine will
                            ///< automatically decide how much data is sent on the bus based on the
                            ///< amount of data available in the FIFO.

  uint8_t SET_ERROR   : 1;  ///< Sets the transferring video frame as error image. The setting will
                            ///< be correlated to the field in UVC header.
                            ///<     1: error
                            ///<     0: normal video frame

  uint8_t SET_STILL   : 1;  ///< Sets the transferring video frame as still image. Should be set
                            ///< before the image is fed into the HBW ISO-IN FIFO.
                            ///<     1: Still image
                            ///<     0: Video stream

  uint8_t SCRON       : 1;  ///< Enables the SCR engine for the UVC header
                            ///<     1: Enabled
                            ///<     0: Disabled

  uint8_t PTSON       : 1;  ///< Enables the PTS engine for the UVC header.
                            ///<     1: Enabled
                            ///<     0: Disabled

  uint8_t Reserved_5  : 1;  ///< Reserved

  uint8_t OVERRUN     : 1;  ///< Indicates when the FIFO is overrun. The overrun condition will be
                            ///< cleared by HBW_INI.
                            ///<     1: Overrun
                            ///<     0: Normal

  uint8_t HBW_INI     : 1;  ///< Set this bit to trigger a reset to HBW isochronous IN pipe.
                            ///< Only RO bits will be reset by HBW_INI.
                            ///< Those are OVERRUN, HAVE_SPACE and FULL.
                            ///< After the reset, the bit is automatically cleared.
} usbd_hbw_ctrl0_reg_t;

/** \brief High-bandwidth Isochronous Control Register 0 */
typedef union
{
  usbd_hbw_ctrl0_reg_t B;
  REG_ACCESS_U8        U;
} usbd_hbw_ctrl0_reg_u;

/** \brief High-bandwidth Isochronous Control Register 1 */
typedef struct
{
  uint8_t FIFO_SIZE : 7;    ///< Defines the FIFO size for the HBW isochronous IN pipe.
                            ///< The FIFO size = FIFO_SIZE * 64 (bytes), and is located at the top
                            ///< of the 6kB shared memory of the USB Device.

  uint8_t Reserved  : 1;    ///< Reserved
} usbd_hbw_ctrl1_reg_t;

/** \brief High-bandwidth Isochronous Control Register 1 */
typedef union
{
  usbd_hbw_ctrl1_reg_t B;
  REG_ACCESS_U8        U;
} usbd_hbw_ctrl1_reg_u;

/** \brief High-bandwidth Isochronous Control Register 2 */
typedef struct
{
  uint8_t THSD_SEL   : 2;   ///< Sets the threshold level for the HAVESPACE indicator.
                            ///<     00: 1024 bytes
                            ///<     01: 64   bytes
                            ///<     10: 128  bytes
                            ///<     11: 256  bytes

  uint8_t HBWMODE    : 2;   ///< 00: Reserved
                            ///< 01: Expects 1 isochronous IN. (DATA0)
                            ///< 10: Expects 2 isochronous INs. (DATA1/0)
                            ///< 11: Expects 3 isochronous INs. (DATA2/1/0)

  uint8_t MAXPKTSIZE : 4;   ///< Defines the maximum packet size for the HBW isochronous IN pipe.
                            ///< Max packet size = (MAXPKTSIZE + 1) * 64 (bytes).
} usbd_hbw_ctrl2_reg_t;

/** \brief High-bandwidth Isochronous Control Register 2 */
typedef union
{
  usbd_hbw_ctrl2_reg_t B;
  REG_ACCESS_U8        U;
} usbd_hbw_ctrl2_reg_u;

/** \brief High-bandwidth Isochronous Control Register 3 */
typedef struct
{
  uint8_t HBW_ENDP_NUM : 4; ///< Hooks up the HBW isochronous IN pipe to an endpoint number.
                            ///<     4’h0: disable this pipe
                            ///<     Others: specify an endpoint number

  uint8_t SEQDATA_END  : 1; ///< Set this bit to indicate the end of sequential data.
                            ///< 1: triggers an end flag to terminate a sequential data

  uint8_t HBWINPRDY    : 1; ///< Set this bit to indicate the data in the FIFO is ready to be
                            ///< transferred on the USB bus.
                            ///< 1: data is ready
                            ///< In this mode, only up to (3 * maximum packet size) of the FIFO will
                            ///< be used. The software needs to check the HAVE_SPACE bit to continue
                            ///< feeding in data.
                            ///< NOTE: HBWINPRDY should not be set when AUTO_HEADER is being enabled.
                            ///< Otherwise, unexpected behavior may occur.

  uint8_t FULL         : 1; ///< Indicates the status of the HBW FIFO
                            ///<     1: Full
                            ///<     0: Not full

  uint8_t HAVE_SPACE   : 1; ///< Indicates that there is still at least one burst space correlated
                            ///< to THSD_SEL.
                            ///<     1: At least 1 burst space for data is available
                            ///<     0: Not enough space
} usbd_hbw_ctrl3_reg_t;

/** \brief High-bandwidth Isochronous Control Register 3 */
typedef union
{
  usbd_hbw_ctrl3_reg_t B;
  REG_ACCESS_U8        U;
} usbd_hbw_ctrl3_reg_u;

/** \brief High-bandwidth Interrupt Enable Register */
typedef struct
{
  uint8_t HBW_INTEN : 1;    ///< Interrupt Enable for the HBW pipe
                            ///<     1: enabled
                            ///<     0: disabled
                            ///< Note that after the HBW pipe is hooked up to certain endpoint
                            ///< number, the normal (i.e., non-HBW) interrupts for that endpoint
                            ///< will be disabled.

  uint8_t Reserved  : 7;    ///< Reserved
} usbd_hbw_int_ena_reg_t;

/** \brief High-bandwidth Interrupt Enable Register */
typedef union
{
  usbd_hbw_int_ena_reg_t B;
  REG_ACCESS_U8          U;
} usbd_hbw_int_ena_reg_u;

/** \brief High-bandwidth Interrupt Status Register */
typedef struct
{
  uint8_t HBW_INTR : 1;     ///< Interrupt Status for HBW pipe.
                            ///<     1: An interrupt event has occurred (caused by HAVE_SPACE)
                            ///<     0: No interrupt event has occurred

  uint8_t Reserved : 7;     ///< Reserved
} usbd_hbw_int_sts_reg_t;

/** \brief High-bandwidth Interrupt Status Register */
typedef union
{
  usbd_hbw_int_sts_reg_t B;
  REG_ACCESS_U8          U;
} usbd_hbw_int_sts_reg_u;

/** \brief High-bandwidth Isochronous IN Support & Registers */
typedef struct
{
  __IO usbd_hbw_ctrl0_reg_u   HBWCTRL0;        ///< 00
       uint8_t                Reserved_01_03;  ///< 01 - 03
  __IO usbd_hbw_ctrl1_reg_u   HBWCTRL1;        ///< 04
       uint8_t                Reserved_05_07;  ///< 05 - 07
  __IO usbd_hbw_ctrl2_reg_u   HBWCTRL2;        ///< 08
       uint8_t                Reserved_09_11;  ///< 09 - 11
  __IO usbd_hbw_ctrl3_reg_u   HBWCTRL3;        ///< 12
       uint8_t                Reserved_13_15;  ///< 13 - 15
  __IO usbd_hbw_int_ena_reg_u HBW_INT_ENABLE;  ///< 16
       uint8_t                Reserved_17_19;  ///< 17 - 19
  __IO usbd_hbw_int_sts_reg_u HBW_INT_STATUS;  ///< 20
       uint8_t                Reserved_21_23;  ///< 21 - 23
} usbd_hbw_ctrl_regs_t;

/** \brief High-bandwidth Isochronous IN Support & Registers */
typedef struct
{
  __IO uint32_t ctrl0;
  __IO uint32_t ctrl1;
  __IO uint32_t ctrl2;
  __IO uint32_t ctrl3;
  __IO uint32_t interrupt_en;
  __IO uint32_t interrupt_status;
} ft900_usbd_hbw_ctrl_regs_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#endif /* FT900_USBD_HBW_REGISTERS_H_ */
