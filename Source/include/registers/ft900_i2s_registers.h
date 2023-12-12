/**
    @file ft900_i2s_registers.h

    @brief I2S registers
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

#ifndef FT900_I2S_REGISTERS_H_
#define FT900_I2S_REGISTERS_H_

/* INCLUDES ************************************************************************/

#include <stdint.h>
#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

/* CR bits */
#define BIT_I2S_CR_TX_ENABLE             (0)
#define MASK_I2S_CR_TX_ENABLE            (0x01 << BIT_I2S_CR_TX_ENABLE)
#define BIT_I2S_CR_RX_ENABLE             (1)
#define MASK_I2S_CR_RX_ENABLE            (0x01 << BIT_I2S_CR_RX_ENABLE)
#define BIT_I2S_CR_LRCLK_IN_POL          (2)
#define MASK_I2S_CR_LRCLK_IN_POL         (0x01 << BIT_I2S_CR_LRCLK_IN_POL)
#define BIT_I2S_CR_LRCLK_OUT_POL         (3)
#define MASK_I2S_CR_LRCLK_OUT_POL        (0x01 << BIT_I2S_CR_LRCLK_OUT_POL)
#define BIT_I2S_CR_BCLK_POL              (4)
#define MASK_I2S_CR_BCLK_POL             (0x01 << BIT_I2S_CR_BCLK_POL)
#define BIT_I2S_CR_IS_MASTER_22          (5)
#define MASK_I2S_CR_IS_MASTER_22         (0x01 << BIT_I2S_CR_IS_MASTER_22)
#define BIT_I2S_CR_MASTER_MODE           (6)
#define MASK_I2S_CR_MASTER_MODE          (0x01 << BIT_I2S_CR_MASTER_MODE)
#define BIT_I2S_CR_IS_MASTER_64          (7)
#define MASK_I2S_CR_IS_MASTER_64         (0x01 << BIT_I2S_CR_IS_MASTER_64)
#define BIT_I2S_CR_BIT_LENGTH_0          (8)
#define MASK_I2S_CR_BIT_LENGTH_0         (0x01 << BIT_I2S_CR_BIT_LENGTH_0)
#define BIT_I2S_CR_BIT_LENGTH_1          (9)
#define MASK_I2S_CR_BIT_LENGTH_1         (0x01 << BIT_I2S_CR_BIT_LENGTH_1)
#define MASK_I2S_CR_BIT_LENGTH           (MASK_I2S_CR_BIT_LENGTH_1 | MASK_I2S_CR_BIT_LENGTH_0)
#define BIT_I2S_CR_FORMAT_0              (10)
#define MASK_I2S_CR_FORMAT_0             (0x01 << BIT_I2S_CR_FORMAT_0)
#define BIT_I2S_CR_FORMAT_1              (11)
#define MASK_I2S_CR_FORMAT_1             (0x01 << BIT_I2S_CR_FORMAT_1)
#define MASK_I2S_CR_FORMAT               (MASK_I2S_CR_FORMAT_1 | MASK_I2S_CR_FORMAT_0)
#define BIT_I2S_CR_PADDING_0             (12)
#define MASK_I2S_CR_PADDING_0            (0x01 << BIT_I2S_CR_PADDING_0)
#define BIT_I2S_CR_PADDING_1             (13)
#define MASK_I2S_CR_PADDING_1            (0x01 << BIT_I2S_CR_PADDING_1)
#define BIT_I2S_CR_PADDING_2             (14)
#define MASK_I2S_CR_PADDING_2            (0x01 << BIT_I2S_CR_PADDING_2)
#define MASK_I2S_CR_PADDING              (MASK_I2S_CR_PADDING_2 | MASK_I2S_CR_PADDING_1 | MASK_I2S_CR_PADDING_0)
#define BIT_I2S_CR_RESET                 (15)
#define MASK_I2S_CR_RESET                (0x01 << BIT_I2S_CR_RESET)
#define MASK_I2S_CR                      (0xFFFF)

/* CR2 bits */
#define BIT_I2S_CR2_BCLK_DIV_0           (0)
#define MASK_I2S_CR2_BCLK_DIV_0          (0x01 << BIT_I2S_CR2_BCLK_DIV_0)
#define BIT_I2S_CR2_BCLK_DIV_1           (1)
#define MASK_I2S_CR2_BCLK_DIV_1          (0x01 << BIT_I2S_CR2_BCLK_DIV_1)
#define BIT_I2S_CR2_BCLK_DIV_2           (2)
#define MASK_I2S_CR2_BCLK_DIV_2          (0x01 << BIT_I2S_CR2_BCLK_DIV_2)
#define BIT_I2S_CR2_BCLK_DIV_3           (3)
#define MASK_I2S_CR2_BCLK_DIV_3          (0x01 << BIT_I2S_CR2_BCLK_DIV_3)
#define BIT_I2S_CR2_MCLK_DIV_0           (8)
#define MASK_I2S_CR2_MCLK_DIV_0          (0x01 << BIT_I2S_CR2_MCLK_DIV_0)
#define BIT_I2S_CR2_MCLK_DIV_1           (9)
#define MASK_I2S_CR2_MCLK_DIV_1          (0x01 << BIT_I2S_CR2_MCLK_DIV_1)
#define BIT_I2S_CR2_MCLK_DIV_2           (10)
#define MASK_I2S_CR2_MCLK_DIV_2          (0x01 << BIT_I2S_CR2_MCLK_DIV_2)
#define BIT_I2S_CR2_MCLK_DIV_3           (11)
#define MASK_I2S_CR2_MCLK_DIV_3          (0x01 << BIT_I2S_CR2_MCLK_DIV_3)
#define MASK_I2S_CR2                     (0x0F0F)

/* IE bits  */
#define BIT_I2S_IE_FIFO_TX_UNDER         (0)
#define MASK_I2S_IE_FIFO_TX_UNDER        (0x01 << BIT_I2S_IE_FIFO_TX_UNDER)
#define BIT_I2S_IE_FIFO_TX_EMPTY         (1)
#define MASK_I2S_IE_FIFO_TX_EMPTY        (0x01 << BIT_I2S_IE_FIFO_TX_EMPTY)
#define BIT_I2S_IE_FIFO_TX_HALF_FULL     (2)
#define MASK_I2S_IE_FIFO_TX_HALF_FULL    (0x01 << BIT_I2S_IE_FIFO_TX_HALF_FULL)
#define BIT_I2S_IE_FIFO_TX_FULL          (3)
#define MASK_I2S_IE_FIFO_TX_FULL         (0x01 << BIT_I2S_IE_FIFO_TX_FULL)
#define BIT_I2S_IE_FIFO_TX_OVER          (4)
#define MASK_I2S_IE_FIFO_TX_OVER         (0x01 << BIT_I2S_IE_FIFO_TX_OVER)
#define BIT_I2S_IE_FIFO_RX_UNDER         (8)
#define MASK_I2S_IE_FIFO_RX_UNDER        (0x01 << BIT_I2S_IE_FIFO_RX_UNDER)
#define BIT_I2S_IE_FIFO_RX_EMPTY         (9)
#define MASK_I2S_IE_FIFO_RX_EMPTY        (0x01 << BIT_I2S_IE_FIFO_RX_EMPTY)
#define BIT_I2S_IE_FIFO_RX_HALF_FULL     (10)
#define MASK_I2S_IE_FIFO_RX_HALF_FULL    (0x01 << BIT_I2S_IE_FIFO_RX_HALF_FULL)
#define BIT_I2S_IE_FIFO_RX_FULL          (11)
#define MASK_I2S_IE_FIFO_RX_FULL         (0x01 << BIT_I2S_IE_FIFO_RX_FULL)
#define BIT_I2S_IE_FIFO_RX_OVER          (12)
#define MASK_I2S_IE_FIFO_RX_OVER         (0x01 << BIT_I2S_IE_FIFO_RX_OVER)
#define MASK_I2S_CR2                     (0x0F0F)

/* PEND bits */
#define BIT_I2S_PEND_FIFO_TX_UNDER       (0)
#define MASK_I2S_PEND_FIFO_TX_UNDER      (0x01 << BIT_I2S_PEND_FIFO_TX_UNDER)
#define BIT_I2S_PEND_FIFO_TX_EMPTY       (1)
#define MASK_I2S_PEND_FIFO_TX_EMPTY      (0x01 << BIT_I2S_PEND_FIFO_TX_EMPTY)
#define BIT_I2S_PEND_FIFO_TX_HALF_FULL   (2)
#define MASK_I2S_PEND_FIFO_TX_HALF_FULL  (0x01 << BIT_I2S_PEND_FIFO_TX_HALF_FULL)
#define BIT_I2S_PEND_FIFO_TX_FULL        (3)
#define MASK_I2S_PEND_FIFO_TX_FULL       (0x01 << BIT_I2S_PEND_FIFO_TX_FULL)
#define BIT_I2S_PEND_FIFO_TX_OVER        (4)
#define MASK_I2S_PEND_FIFO_TX_OVER       (0x01 << BIT_I2S_PEND_FIFO_TX_OVER)
#define BIT_I2S_PEND_FIFO_RX_UNDER       (8)
#define MASK_I2S_PEND_FIFO_RX_UNDER      (0x01 << BIT_I2S_PEND_FIFO_RX_UNDER)
#define BIT_I2S_PEND_FIFO_RX_EMPTY       (9)
#define MASK_I2S_PEND_FIFO_RX_EMPTY      (0x01 << BIT_I2S_PEND_FIFO_RX_EMPTY)
#define BIT_I2S_PEND_FIFO_RX_HALF_FULL   (10)
#define MASK_I2S_PEND_FIFO_RX_HALF_FULL  (0x01 << BIT_I2S_PEND_FIFO_RX_HALF_FULL)
#define BIT_I2S_PEND_FIFO_RX_FULL        (11)
#define MASK_I2S_PEND_FIFO_RX_FULL       (0x01 << BIT_I2S_PEND_FIFO_RX_FULL)
#define BIT_I2S_PEND_FIFO_RX_OVER        (12)
#define MASK_I2S_PEND_FIFO_RX_OVER       (0x01 << BIT_I2S_PEND_FIFO_RX_OVER)

/* FIFO bits */
#define BIT_I2S_FIFO_0                   (0)
#define MASK_I2S_FIFO_0                  (0x01 << BIT_I2S_FIFO_0)
#define BIT_I2S_FIFO_1                   (1)
#define MASK_I2S_FIFO_1                  (0x01 << BIT_I2S_FIFO_1)
#define BIT_I2S_FIFO_2                   (2)
#define MASK_I2S_FIFO_2                  (0x01 << BIT_I2S_FIFO_2)
#define BIT_I2S_FIFO_3                   (3)
#define MASK_I2S_FIFO_3                  (0x01 << BIT_I2S_FIFO_3)
#define BIT_I2S_FIFO_4                   (4)
#define MASK_I2S_FIFO_4                  (0x01 << BIT_I2S_FIFO_4)
#define BIT_I2S_FIFO_5                   (5)
#define MASK_I2S_FIFO_5                  (0x01 << BIT_I2S_FIFO_5)
#define BIT_I2S_FIFO_6                   (6)
#define MASK_I2S_FIFO_6                  (0x01 << BIT_I2S_FIFO_6)
#define BIT_I2S_FIFO_7                   (7)
#define MASK_I2S_FIFO_7                  (0x01 << BIT_I2S_FIFO_7)
#define BIT_I2S_FIFO_8                   (8)
#define MASK_I2S_FIFO_8                  (0x01 << BIT_I2S_FIFO_8)
#define BIT_I2S_FIFO_9                   (9)
#define MASK_I2S_FIFO_9                  (0x01 << BIT_I2S_FIFO_9)
#define BIT_I2S_FIFO_10                  (10)
#define MASK_I2S_FIFO_10                 (0x01 << BIT_I2S_FIFO_10)
#define BIT_I2S_FIFO_11                  (11)
#define MASK_I2S_FIFO_11                 (0x01 << BIT_I2S_FIFO_11)
#define BIT_I2S_FIFO_12                  (12)
#define MASK_I2S_FIFO_12                 (0x01 << BIT_I2S_FIFO_12)
#define BIT_I2S_FIFO_13                  (13)
#define MASK_I2S_FIFO_13                 (0x01 << BIT_I2S_FIFO_13)
#define BIT_I2S_FIFO_14                  (14)
#define MASK_I2S_FIFO_14                 (0x01 << BIT_I2S_FIFO_14)
#define BIT_I2S_FIFO_15                  (15)
#define MASK_I2S_FIFO_15                 (0x01 << BIT_I2S_FIFO_15)
#define MASK_I2S_FIFO                    (0xFFFF)

/* RX Count */
#define BIT_I2S_RX_COUNT_0               (0)
#define MASK_I2S_RX_COUNT_0              (0x01 << BIT_I2S_RX_COUNT_0)
#define BIT_I2S_RX_COUNT_1               (1)
#define MASK_I2S_RX_COUNT_1              (0x01 << BIT_I2S_RX_COUNT_1)
#define BIT_I2S_RX_COUNT_2               (2)
#define MASK_I2S_RX_COUNT_2              (0x01 << BIT_I2S_RX_COUNT_2)
#define BIT_I2S_RX_COUNT_3               (3)
#define MASK_I2S_RX_COUNT_3              (0x01 << BIT_I2S_RX_COUNT_3)
#define BIT_I2S_RX_COUNT_4               (4)
#define MASK_I2S_RX_COUNT_4              (0x01 << BIT_I2S_RX_COUNT_4)
#define BIT_I2S_RX_COUNT_5               (5)
#define MASK_I2S_RX_COUNT_5              (0x01 << BIT_I2S_RX_COUNT_5)
#define BIT_I2S_RX_COUNT_6               (6)
#define MASK_I2S_RX_COUNT_6              (0x01 << BIT_I2S_RX_COUNT_6)
#define BIT_I2S_RX_COUNT_7               (7)
#define MASK_I2S_RX_COUNT_7              (0x01 << BIT_I2S_RX_COUNT_7)
#define BIT_I2S_RX_COUNT_8               (8)
#define MASK_I2S_RX_COUNT_8              (0x01 << BIT_I2S_RX_COUNT_8)
#define BIT_I2S_RX_COUNT_9               (9)
#define MASK_I2S_RX_COUNT_9              (0x01 << BIT_I2S_RX_COUNT_9)
#define BIT_I2S_RX_COUNT_10              (10)
#define MASK_I2S_RX_COUNT_10             (0x01 << BIT_I2S_RX_COUNT_10)
#define BIT_I2S_RX_COUNT_11              (11)
#define MASK_I2S_RX_COUNT_11             (0x01 << BIT_I2S_RX_COUNT_11)
#define BIT_I2S_RX_COUNT_12              (12)
#define MASK_I2S_RX_COUNT_12             (0x01 << BIT_I2S_RX_COUNT_12)
#define BIT_I2S_RX_COUNT_13              (13)
#define MASK_I2S_RX_COUNT_13             (0x01 << BIT_I2S_RX_COUNT_13)
#define BIT_I2S_RX_COUNT_14              (14)
#define MASK_I2S_RX_COUNT_14             (0x01 << BIT_I2S_RX_COUNT_14)
#define BIT_I2S_RX_COUNT_15              (15)
#define MASK_I2S_RX_COUNT_15             (0x01 << BIT_I2S_RX_COUNT_15)
#define MASK_I2S_RX_COUNT                (0xFFFF)

/* TX Count */
#define BIT_I2S_TX_COUNT_0               (0)
#define MASK_I2S_TX_COUNT_0              (0x01 << BIT_I2S_TX_COUNT_0)
#define BIT_I2S_TX_COUNT_1               (1)
#define MASK_I2S_TX_COUNT_1              (0x01 << BIT_I2S_TX_COUNT_1)
#define BIT_I2S_TX_COUNT_2               (2)
#define MASK_I2S_TX_COUNT_2              (0x01 << BIT_I2S_TX_COUNT_2)
#define BIT_I2S_TX_COUNT_3               (3)
#define MASK_I2S_TX_COUNT_3              (0x01 << BIT_I2S_TX_COUNT_3)
#define BIT_I2S_TX_COUNT_4               (4)
#define MASK_I2S_TX_COUNT_4              (0x01 << BIT_I2S_TX_COUNT_4)
#define BIT_I2S_TX_COUNT_5               (5)
#define MASK_I2S_TX_COUNT_5              (0x01 << BIT_I2S_TX_COUNT_5)
#define BIT_I2S_TX_COUNT_6               (6)
#define MASK_I2S_TX_COUNT_6              (0x01 << BIT_I2S_TX_COUNT_6)
#define BIT_I2S_TX_COUNT_7               (7)
#define MASK_I2S_TX_COUNT_7              (0x01 << BIT_I2S_TX_COUNT_7)
#define BIT_I2S_TX_COUNT_8               (8)
#define MASK_I2S_TX_COUNT_8              (0x01 << BIT_I2S_TX_COUNT_8)
#define BIT_I2S_TX_COUNT_9               (9)
#define MASK_I2S_TX_COUNT_9              (0x01 << BIT_I2S_TX_COUNT_9)
#define BIT_I2S_TX_COUNT_10              (10)
#define MASK_I2S_TX_COUNT_10             (0x01 << BIT_I2S_TX_COUNT_10)
#define BIT_I2S_TX_COUNT_11              (11)
#define MASK_I2S_TX_COUNT_11             (0x01 << BIT_I2S_TX_COUNT_11)
#define BIT_I2S_TX_COUNT_12              (12)
#define MASK_I2S_TX_COUNT_12             (0x01 << BIT_I2S_TX_COUNT_12)
#define BIT_I2S_TX_COUNT_13              (13)
#define MASK_I2S_TX_COUNT_13             (0x01 << BIT_I2S_TX_COUNT_13)
#define BIT_I2S_TX_COUNT_14              (14)
#define MASK_I2S_TX_COUNT_14             (0x01 << BIT_I2S_TX_COUNT_14)
#define BIT_I2S_TX_COUNT_15              (15)
#define MASK_I2S_TX_COUNT_15             (0x01 << BIT_I2S_TX_COUNT_15)
#define MASK_I2S_TX_COUNT                (0xFFFF)

/* TYPES ***************************************************************************/

/** \brief Configuration Register 1 */
typedef struct
{
  uint16_t TX_Enable          : 1;    ///< 1: Enable the transmit channel.

  uint16_t RX_Enable          : 1;    ///< 1: Enable the receive channel.

  uint16_t LRCLK_In_Polarity  : 1;    ///< 1: Invert the polarity of LRCLK for transmission.

  uint16_t LRCLK_Out_Polarity : 1;    ///< 1: Invert the polarity of LRCLK for reception.

  uint16_t BCLK_Polarity      : 1;    ///< 1: Invert the polarity of BCLK.

  uint16_t IsMaster22         : 1;    ///< This is valid for I2S Master mode only.
                                      ///<   1: Use 22.5792MHz input as the reference clock.
                                      ///<   0: Use 24.576MHz input as the reference clock.

  uint16_t MasterMode         : 1;    ///< 1: Set I2S to the Master Mode.

  uint16_t IsMaster64         : 1;    ///< This is valid for I2S Master mode only.
                                      ///<   1: 32 BCLK cycles per channel.
                                      ///<   0: 16 BCLK cycles per channel.

  uint16_t Bit_Length         : 2;    ///< 0: 16-bit Format.
                                      ///< 1: 20-bit Format.
                                      ///< 2: 24-bit Format.
                                      ///< 3: 32-bit Format

  uint16_t Format             : 2;    ///< 0: I2S Format.
                                      ///< 1: Left Justified Format.
                                      ///< 2: Right Justified Format.
                                      ///< Others: Reserved

  uint16_t Padding            : 3;    ///< 0: No padding required (bit length = number of bclk cycles)
                                      ///< 1: 4 extra 0 bits are added.
                                      ///< 2: 8 extra 0 bits are added.
                                      ///< 3: 12 extra 0 bits are added.
                                      ///< 4: 16 extra 0 bits are added.
                                      ///< Others: Reserved

  uint16_t Soft_Reset         : 1;    ///< 1: To turn on the soft reset.
                                      ///< 0: To turn off the soft reset.
} i2s_config_1_reg_t;

typedef union
{
  i2s_config_1_reg_t B;
  REG_ACCESS_U16     U;
} i2s_config_1_reg_u;

/** \brief Configuration Register 2 */
typedef struct
{
  uint16_t BCLK_Divider   : 4;    ///< This is valid for I2S Master mode only.
                                  ///< 0: No division (MCLK = reference clock).
                                  ///< 1: Divide by 2.
                                  ///< 2: Divide by 3.
                                  ///< 3: Divide by 4.
                                  ///< 4: Divide by 6.
                                  ///< 5: Divide by 8.
                                  ///< 6: Divide by 12.
                                  ///< 7: Divide by 16.
                                  ///< 8: Divide by 24.
                                  ///< 9: Divide by 32.
                                  ///< A: Divide by 48.
                                  ///< B: Divide by 64.
                                  ///< Others: Reserved.

  uint16_t Reserved_4_7   : 4;    ///< Reserved

  uint16_t MCLK_Divider   : 4;    ///< This is valid for I2S Master mode only.
                                  ///< 0: No division (MCLK = reference clock).
                                  ///< 1: Divide by 2.
                                  ///< 2: Divide by 3.
                                  ///< 3: Divide by 4.
                                  ///< 4: Divide by 6.
                                  ///< 5: Divide by 8.
                                  ///< 6: Divide by 12.
                                  ///< 7: Divide by 16.
                                  ///< 8: Divide by 24.
                                  ///< 9: Divide by 32.
                                  ///< A: Divide by 48.
                                  ///< B: Divide by 64.
                                  ///< Others: Reserved.

  uint16_t Reserved_12_15 : 4;    ///< Reserved
} i2s_config_2_reg_t;

typedef union
{
  i2s_config_2_reg_t B;
  REG_ACCESS_U16     U;
} i2s_config_2_reg_u;

typedef struct
{
  uint16_t TX_FIFO_Under  : 1;    ///< 1: Enable Transmit FIFO Underflow Interrupt.
  uint16_t TX_FIFO_Empty  : 1;    ///< 1: Enable Transmit FIFO Empty Interrupt.
  uint16_t TX_FIFO_Half   : 1;    ///< 1: Enable Transmit FIFO Half Full Interrupt.
  uint16_t TX_FIFO_Full   : 1;    ///< 1: Enable Transmit FIFO Full Interrupt.
  uint16_t TX_FIFO_Ov     : 1;    ///< 1: Enable Transmit FIFO Overflow Interrupt.
  uint16_t Reserved_5_7   : 3;    ///< Reserved
  uint16_t RX_FIFO_Under  : 1;    ///< 1: Enable Receive FIFO Underflow Interrupt.
  uint16_t RX_FIFO_Empty  : 1;    ///< 1: Enable Receive FIFO Empty Interrupt.
  uint16_t RX_FIFO_Half   : 1;    ///< 1: Enable Receive FIFO Half Full Interrupt.
  uint16_t RX_FIFO_Full   : 1;    ///< 1: Enable Receive FIFO Full Interrupt.
  uint16_t RX_FIFO_Ov     : 1;    ///< 1: Enable Receive FIFO Overflow Interrupt.
  uint16_t Reserved_13_15 : 3;    ///< Reserved
} i2s_irq_enb_reg_t;

typedef union
{
  i2s_irq_enb_reg_t B;
  REG_ACCESS_U16    U;
} i2s_irq_enb_reg_u;

typedef struct
{
  uint16_t TX_FIFO_Under  : 1;  ///< 1: Transmit FIFO Underflow Interrupt Pending. Write 1 to clear.
  uint16_t TX_FIFO_Empty  : 1;  ///< 1: Transmit FIFO Empty Interrupt Pending. Write 1 to clear.
  uint16_t TX_FIFO_Half   : 1;  ///< 1: Transmit FIFO Half Full Interrupt Pending. Write 1 to clear.
  uint16_t TX_FIFO_Full   : 1;  ///< 1: Transmit FIFO Full Interrupt Pending. Write 1 to clear.
  uint16_t TX_FIFO_Ov     : 1;  ///< 1: Transmit FIFO Overflow Interrupt Pending. Write 1 to clear.
  uint16_t Reserved_5_7   : 3;  ///< Reserved
  uint16_t RX_FIFO_Under  : 1;  ///< 1: Receive FIFO Underflow Interrupt Pending. Write 1 to clear.
  uint16_t RX_FIFO_Empty  : 1;  ///< 1: Receive FIFO Empty Interrupt Pending. Write 1 to clear.
  uint16_t RX_FIFO_Half   : 1;  ///< 1: Receive FIFO Half Full Interrupt Pending. Write 1 to clear.
  uint16_t RX_FIFO_Full   : 1;  ///< 1: Receive FIFO Full Interrupt Pending. Write 1 to clear.
  uint16_t RX_FIFO_Ov     : 1;  ///< 1: Receive FIFO Overflow Interrupt Pending. Write 1 to clear.
  uint16_t Reserved_13_15 : 3;  ///< Reserved
} i2s_irq_pend_reg_t;

typedef union
{
  i2s_irq_pend_reg_t B;
  REG_ACCESS_U16     U;
} i2s_irq_pend_reg_u;

/** \brief Transmit/Receive Data Register */
typedef union
{
  uint16_t       RX_FIFO_Data;  ///< Data window for writing data to the transmit FIFO.
  uint16_t       TX_FIFO_Data;  ///< Data window for reading data from the receive FIFO.
  REG_ACCESS_U16 U;
} i2s_wr_data_reg_u;

/** \brief RX Count Register */
typedef struct
{
  uint16_t RX_FIFO_Data_Count;  ///< Indicates the amount of data in the Receive FIFO.
} i2s_rx_count_reg_t;

typedef union
{
  i2s_rx_count_reg_t B;
  REG_ACCESS_U16     U;
} i2s_rx_count_reg_u;

typedef struct
{
  uint16_t TX_FIFO_Data_Count;  ///< Indicates the amount of data in the Transmit FIFO.
} i2s_tx_count_reg_t;

typedef union
{
  i2s_tx_count_reg_t B;
  REG_ACCESS_U16     U;
} i2s_tx_count_reg_u;

/** @brief Register mappings for I2S registers */
typedef struct
{
  __IO i2s_config_1_reg_u I2S_CR;
  __IO i2s_config_2_reg_u I2S_CR2;
  __IO i2s_irq_enb_reg_u  I2S_IRQ_EN;
  __IO i2s_irq_pend_reg_u I2S_IRQ_PEND;
  __IO i2s_wr_data_reg_u  I2S_RW_DATA;
       uint16_t           RESERVED10;
  __IO i2s_rx_count_reg_u I2S_RX_COUNT;
  __IO i2s_tx_count_reg_u I2S_TX_COUNT;
} i2s_regs_t;

/** @brief Register mappings for I2S registers */
typedef struct
{
  __IO uint16_t I2S_CR;
  __IO uint16_t I2S_CR2;
  __IO uint16_t I2S_IRQ_EN;
  __IO uint16_t I2S_IRQ_PEND;
  __IO uint16_t I2S_RW_DATA;
       uint16_t RESERVED10;
  __IO uint16_t I2S_RX_COUNT;
  __IO uint16_t I2S_TX_COUNT;
} ft900_i2s_regs_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#endif /* FT900_I2S_REGISTERS_H_ */
