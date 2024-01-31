/**
    @file ft900_timer_wdt_registers.h

    @brief Timer and Watchdog registers
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
 * ("Bridgetek") subject to the licence terms set out
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

#ifndef FT900_TIMER_WDT_REGISTERS_H_
#define FT900_TIMER_WDT_REGISTERS_H_

/* INCLUDES ************************************************************************/

#include <stdint.h>

#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

#define BIT_TIMER_CONTROL_0_SOFT_RESET            (0)
#define MASK_TIMER_CONTROL_0_SOFT_RESET           (1 << BIT_TIMER_CONTROL_0_SOFT_RESET)
#define BIT_TIMER_CONTROL_0_BLOCK_EN              (1)
#define MASK_TIMER_CONTROL_0_BLOCK_EN             (1 << BIT_TIMER_CONTROL_0_BLOCK_EN)

#define BIT_TIMER_CONTROL_1_START(__id__)         (__id__)
#define MASK_TIMER_CONTROL_1_START(__id__)        (1 << BIT_TIMER_CONTROL_1_START(__id__))
#define BIT_TIMER_CONTROL_1_STOP(__id__)          ((__id__) + 4)
#define MASK_TIMER_CONTROL_1_STOP(__id__)         (1 << BIT_TIMER_CONTROL_1_STOP(__id__))

#define BIT_TIMER_CONTROL_2_START_WDT             (0)
#define MASK_TIMER_CONTROL_2_START_WDT            (1 << BIT_TIMER_CONTROL_2_START_WDT)
#define BIT_TIMER_CONTROL_2_CLEAR_WDT             (1)
#define MASK_TIMER_CONTROL_2_CLEAR_WDT            (1 << BIT_TIMER_CONTROL_2_CLEAR_WDT)
#define BIT_TIMER_CONTROL_2_WDG_INT               (2)
#define MASK_TIMER_CONTROL_2_WDG_INT              (1 << BIT_TIMER_CONTROL_2_WDG_INT)
#define BIT_TIMER_CONTROL_2_WDG_INT_EN            (3)
#define MASK_TIMER_CONTROL_2_WDG_INT_EN           (1 << BIT_TIMER_CONTROL_2_WDG_INT_EN)

#define BIT_TIMER_CONTROL_2_PRESCALER_EN(__id__)  ((__id__) + 4)
#define MASK_TIMER_CONTROL_2_PRESCALER_EN(__id__) (1 << BIT_TIMER_CONTROL_2_PRESCALER_EN(__id__))

#define BIT_TIMER_CONTROL_3_MODE(__id__)          (__id__)
#define MASK_TIMER_CONTROL_3_MODE(__id__)         (1 << BIT_TIMER_CONTROL_3_MODE(__id__))
#define BIT_TIMER_CONTROL_3_DIRECTION(__id__)     ((__id__) + 4)
#define MASK_TIMER_CONTROL_3_DIRECTION(__id__)    (1 << BIT_TIMER_CONTROL_3_DIRECTION(__id__))

#define BIT_TIMER_CONTROL_4_CLEAR_A               (0)
#define MASK_TIMER_CONTROL_4_CLEAR_A              (1 << BIT_TIMER_CONTROL_4_CLEAR_A)
#define BIT_TIMER_CONTROL_4_CLEAR_B               (1)
#define MASK_TIMER_CONTROL_4_CLEAR_B              (1 << BIT_TIMER_CONTROL_4_CLEAR_B)
#define BIT_TIMER_CONTROL_4_CLEAR_C               (2)
#define MASK_TIMER_CONTROL_4_CLEAR_C              (1 << BIT_TIMER_CONTROL_4_CLEAR_C)
#define BIT_TIMER_CONTROL_4_CLEAR_D               (3)
#define MASK_TIMER_CONTROL_4_CLEAR_D              (1 << BIT_TIMER_CONTROL_4_CLEAR_D)

// Used in FT930 and FT90X Rev C onwards

#define BIT_TIMER_CONTROL_4_PRESC_CLEAR_A         (4)
#define MASK_TIMER_CONTROL_4_PRESC_CLEAR_A        (1 << BIT_TIMER_CONTROL_4_PRESC_CLEAR_A)
#define BIT_TIMER_CONTROL_4_PRESC_CLEAR_B         (5)
#define MASK_TIMER_CONTROL_4_PRESC_CLEAR_B        (1 << BIT_TIMER_CONTROL_4_PRESC_CLEAR_B)
#define BIT_TIMER_CONTROL_4_PRESC_CLEAR_C         (6)
#define MASK_TIMER_CONTROL_4_PRESC_CLEAR_C        (1 << BIT_TIMER_CONTROL_4_PRESC_CLEAR_C)
#define BIT_TIMER_CONTROL_4_PRESC_CLEAR_D         (7)
#define MASK_TIMER_CONTROL_4_PRESC_CLEAR_D        (1 << BIT_TIMER_CONTROL_4_PRESC_CLEAR_D)

// Macros used in FT90X Rev B only

#define BIT_TIMER_CONTROL_4_PRESC_CLEAR           (4)
#define MASK_TIMER_CONTROL_4_PRESC_CLEAR          (1 << BIT_TIMER_CONTROL_4_PRESC_CLEAR)

// End of FT90X Rev B ONLY macros

#define BIT_TIMER_INT_TIMER_INT(__id__)           ((__id__ ) * 2)
#define MASK_TIMER_INT_TIMER_INT(__id__)          (1 << BIT_TIMER_INT_TIMER_INT(__id__))
#define BIT_TIMER_INT_TIMER_INT_EN(__id__)        (((__id__ ) * 2) + 1)
#define MASK_TIMER_INT_TIMER_INT_EN(__id__)       (1 << BIT_TIMER_INT_TIMER_INT_EN(__id__))

#define BIT_TIMER_SELECT_TIMER_WRITE_SEL          (0)
#define MASK_TIMER_SELECT_TIMER_WRITE_SEL         (0x3 << BIT_TIMER_SELECT_TIMER_WRITE_SEL)
#define BIT_TIMER_SELECT_TIMER_READ_SEL           (2)
#define MASK_TIMER_SELECT_TIMER_READ_SEL          (0x3 << BIT_TIMER_SELECT_TIMER_READ_SEL)

#define BIT_TIMER_WDG_WRITE                       (0)
#define MASK_TIMER_WDG_WRITE                      (0x1F << BIT_TIMER_WDG_WRITE)

// Macros used in FT90X Rev C

/** This bit is set if there was a second watchdog roll-over that causes a POR-like system reset.
 *  It's automatically cleared after being read.
 */
#define BIT_TIMER_WDG_STATUS                      (0)
#define MASK_TIMER_WDG_STATUS                     (1 << BIT_TIMER_WDG_STATUS)

/* TYPES ***************************************************************************/

/** \brief Timers Control Register 0 */
typedef struct
{
  uint8_t soft_reset : 1;   ///< 1: Write 1 to trigger the reset
  uint8_t block_en   : 1;   ///< 1: To enable the timer module
  uint8_t Reserved   : 6;   ///< Reserved
} timer_control_0_reg_t;

/** \brief Timers Control Register 0 */
typedef union
{
  timer_control_0_reg_t B;
  REG_ACCESS_U8         U;
} timer_control_0_reg_u;

/** \brief Timers Control Register 1 */
typedef struct
{
  uint8_t start_a : 1;      ///< 1: To trigger starting timer A
  uint8_t start_b : 1;      ///< 1: To trigger starting timer B
  uint8_t start_c : 1;      ///< 1: To trigger starting timer C
  uint8_t start_d : 1;      ///< 1: To trigger starting timer D
  uint8_t stop_a  : 1;      ///< 1: To trigger stopping timer A
  uint8_t stop_b  : 1;      ///< 1: To trigger stopping timer B
  uint8_t stop_c  : 1;      ///< 1: To trigger stopping timer C
  uint8_t stop_d  : 1;      ///< 1: To trigger stopping timer D
} timer_control_1_reg_t;

/** \brief Timers Control Register 1 */
typedef union
{
  timer_control_1_reg_t B;
  REG_ACCESS_U8         U;
} timer_control_1_reg_u;

/** \brief Control Register 2 */
typedef struct
{
  uint8_t start_wdg    : 1; ///< 1: To trigger starting watch dog timer
  uint8_t clear_wdg    : 1; ///< 1: To trigger clearing watch dog timer
  uint8_t wdg_int      : 1; ///< 1: Watch-dog interrupt pending
  uint8_t wdg_int_ien  : 1; ///< 1: Enable watch dog interrupt
  uint8_t prescaler_en : 4; ///< Enables pre-scaler bits for timers D/C/B/A respectively
} timer_control_2_reg_t;

/** \brief Control Register 2 */
typedef union
{
  timer_control_2_reg_t B;
  REG_ACCESS_U8         U;
} timer_control_2_reg_u;

/** \brief Timers Control Register 3 */
typedef struct
{
  uint8_t mode      : 4;    ///< Continuous/1-shot mode bits for timers D/C/B/A respectively
                            ///<     1: 1-shot
                            ///<     0: Continuous

  uint8_t direction : 4;    ///< Counter direction bits for timers D/C/B/A respectively
                            ///<     1: Up
                            ///<     0: Down
} timer_control_3_reg_t;

/** \brief Timers Control Register 3 */
typedef union
{
  timer_control_3_reg_t B;
  REG_ACCESS_U8         U;
} timer_control_3_reg_u;

/** \brief Timers Control Register 4 (User for REV C only )*/
typedef struct
{
  uint8_t clear_a       : 1;  ///< 1: To trigger clearing timer A
  uint8_t clear_b       : 1;  ///< 1: To trigger clearing timer B
  uint8_t clear_c       : 1;  ///< 1: To trigger clearing timer C
  uint8_t clear_d       : 1;  ///< 1: To trigger clearing timer D
  uint8_t presc_clear_a : 1;  ///< 1: To trigger clearing pre-scaler A
  uint8_t presc_clear_b : 1;  ///< 1: To trigger clearing pre-scaler B
  uint8_t presc_clear_c : 1;  ///< 1: To trigger clearing pre-scaler C
  uint8_t presc_clear_d : 1;  ///< 1: To trigger clearing pre-scaler D
} timer_control_4_reg_rev_c_t;

/** \brief Timers Control Register 4 (User for REV B and FT93x )*/
typedef struct
{
  uint8_t clear_a     : 1;  ///< 1: To trigger clearing timer A
  uint8_t clear_b     : 1;  ///< 1: To trigger clearing timer B
  uint8_t clear_c     : 1;  ///< 1: To trigger clearing timer C
  uint8_t clear_d     : 1;  ///< 1: To trigger clearing timer D
  uint8_t presc_clear : 1;  ///< 1: To trigger clearing prescaler
} timer_control_4_reg_rev_b_t;

/** \brief Timers Control Register 4 */
typedef union
{
  timer_control_4_reg_rev_c_t REV_C;
  timer_control_4_reg_rev_b_t REV_B;
  timer_control_4_reg_rev_b_t FT93X;
  REG_ACCESS_U8               U;
} timer_control_4_reg_u;

/** \brief Timers Interrupt Register */
typedef struct
{
  uint8_t timer_int_a    : 1; ///< 1: Timer A interrupt pending
  uint8_t timer_int_a_en : 1; ///< 1: Enables timer A interrupt
  uint8_t timer_int_b    : 1; ///< 1: Timer B interrupt pending
  uint8_t timer_int_b_en : 1; ///< 1: Enables timer B interrupt
  uint8_t timer_int_c    : 1; ///< 1: Timer C interrupt pending
  uint8_t timer_int_c_en : 1; ///< 1: Enables timer C interrupt
  uint8_t timer_int_d    : 1; ///< 1: Timer D interrupt pending
  uint8_t timer_int_d_en : 1; ///< 1: Enables timer D interrupt
} timer_int_reg_t;

/** \brief Timers Interrupt Register */
typedef union
{
  timer_int_reg_t B;
  REG_ACCESS_U8   U;
} timer_int_reg_u;

/** \brief Timers A..D Select Register */
typedef struct
{
  uint8_t timer_write_sel : 2;  ///< Selects one of timers or pre-scalers A/B/C/D to write.
                                ///<     0: timer/pre-scaler A
                                ///<     1: timer/pre-scaler B
                                ///<     2: timer/pre-scaler C
                                ///<     3: timer/pre-scaler D

  uint8_t timer_read_sel  : 2;  ///< Selects one of timers or pre-scalers A/B/C/D to read.
                                ///<     0: timer/pre-scaler A
                                ///<     1: timer/pre-scaler B
                                ///<     2: timer/pre-scaler C
                                ///<     3: timer/pre-scaler D

  uint8_t Reserved        : 4;  ///< Reserved
} timer_select_reg_t;

/** \brief Timers A..D Select Register */
typedef union
{
  timer_select_reg_t B;
  REG_ACCESS_U8      U;
} timer_select_reg_u;

/** \brief Watchdog Start Value */
typedef struct
{
  uint8_t timer_wdg_write : 5;  ///< Sets the watchdog duration in the number of system clock
                                ///< cycles. The number of clock cycles is equal to
                                ///< 2^timer_wdg_write.
                                ///< | timer_wdg_write | Number of cycles |
                                ///< | :-------------- | :--------------- |
                                ///< | 5’h00           | 1                |
                                ///< | 5’h01           | 2                |
                                ///< | ...             | ...              |
                                ///< | 5’h1E           | 1,073,741,824    |
                                ///< | 5’h1F           | 2,147,483,648    |

  uint8_t Reserved        : 3;  ///< Reserved
} timer_wdg_reg_t;

/** \brief Watchdog Start Value */
typedef union
{
  timer_wdg_reg_t B;
  REG_ACCESS_U8   U;
} timer_wdg_reg_u;

/** \brief Timer A..D Start Value 7:0 */
typedef struct
{
  uint8_t timer_write_7_0;      ///< Writes the LSB of the timer start value
} timer_write_lsb_reg_t;

/** \brief Timer A..D Start Value 7:0 */
typedef union
{
  timer_write_lsb_reg_t B;
  REG_ACCESS_U8         U;
} timer_write_lsb_reg_u;

/** \brief Timer A..D Start Value 15:8 */
typedef struct
{
  uint8_t timer_write_15_8;     ///< Writes the MSB of the timer start value
} timer_write_msb_reg_t;

/** \brief Timer A..D Start Value 15:8 */
typedef union
{
  timer_write_msb_reg_t B;
  REG_ACCESS_U8         U;
} timer_write_msb_reg_u;

/** \brief Pre-scaler Start Value 7:0 */
typedef struct
{
  uint8_t timer_presc_7_0;      ///< Writes the LSB of the timer pre-scaler start value
} timer_presc_lsb_reg_t;

/** \brief Pre-scaler Start Value 7:0 */
typedef union
{
  timer_presc_lsb_reg_t B;
  REG_ACCESS_U8         U;
} timer_presc_lsb_reg_u;

/** \brief Pre-scaler Start Value 15:8 */
typedef struct
{
  uint8_t timer_presc_15_8;     ///< Writes MSB of the timer pre-scaler start value
} timer_presc_msb_reg_t;

/** \brief Pre-scaler Start Value 15:8 */
typedef union
{
  timer_presc_msb_reg_t B;
  REG_ACCESS_U8         U;
} timer_presc_msb_reg_u;

/** \brief Timer A..D Current Value 7:0 */
typedef struct
{
  uint8_t timer_read_7_0;       ///< Reads the MSB of the timer start value
} timer_read_lsb_reg_t;

/** \brief Timer A..D Current Value 7:0 */
typedef union
{
  timer_read_lsb_reg_t B;
  REG_ACCESS_U8        U;
} timer_read_lsb_reg_u;

/** \brief Timer A..D Current Value 15:8 */
typedef struct
{
  uint8_t timer_read_15_8;      ///< Reads the MSB of the timer start value
} timer_read_msb_reg_t;

/** \brief Timer A..D Current Value 15:8 */
typedef union
{
  timer_read_msb_reg_t B;
  REG_ACCESS_U8        U;
} timer_read_msb_reg_u;

/** \brief Watchdog Status Register
 *  \warning !!! Available in FT90x Rev C onwards !!!
 */
typedef struct
{
  uint8_t WDG_STATUS : 1;       ///< This bit is set if there was a second watchdog roll-over that
                                ///< causes a POR-like system reset. It is automatically cleared
                                ///< after being read.

  uint8_t Reserved   : 7;       ///< Reserved
} timer_wdg_status_reg_t;

/** \brief Watchdog Status Register */
typedef union
{
  timer_wdg_status_reg_t B;
  REG_ACCESS_U8          U;
} timer_wdg_status_reg_u;

/** \brief Register mappings for Timer registers */
typedef struct
{
  __IO timer_control_0_reg_u  TIMER_CONTROL_0;
  __IO timer_control_1_reg_u  TIMER_CONTROL_1;
  __IO timer_control_2_reg_u  TIMER_CONTROL_2;
  __IO timer_control_3_reg_u  TIMER_CONTROL_3;
  __IO timer_control_4_reg_u  TIMER_CONTROL_4;
  __IO timer_int_reg_u        TIMER_INT;
  __IO timer_select_reg_u     TIMER_SELECT;
  __IO timer_wdg_reg_u        TIMER_WDG;
  __IO timer_write_lsb_reg_u  TIMER_WRITE_LSB;
  __IO timer_write_msb_reg_u  TIMER_WRITE_MSB;
  __IO timer_presc_lsb_reg_u  TIMER_PRESC_LSB;
  __IO timer_presc_msb_reg_u  TIMER_PRESC_MSB;
  __IO timer_read_lsb_reg_u   TIMER_READ_LSB;
  __IO timer_read_msb_reg_u   TIMER_READ_MSB;
       uint8_t                TIMER_RESERVED;    ///< Reserved
  __IO timer_wdg_status_reg_u TIMER_WDG_STATUS;  ///< !!! Available in FT90x Rev C onwards !!!
} timer_wdt_regs_t;

/** @brief Register mappings for Timer registers */
typedef struct
{
  __IO uint8_t TIMER_CONTROL_0;
  __IO uint8_t TIMER_CONTROL_1;
  __IO uint8_t TIMER_CONTROL_2;
  __IO uint8_t TIMER_CONTROL_3;
  __IO uint8_t TIMER_CONTROL_4;
  __IO uint8_t TIMER_INT;
  __IO uint8_t TIMER_SELECT;
  __IO uint8_t TIMER_WDG;
  __IO uint8_t TIMER_WRITE_LS;
  __IO uint8_t TIMER_WRITE_MS;
  __IO uint8_t TIMER_PRESC_LS;
  __IO uint8_t TIMER_PRESC_MS;
  __IO uint8_t TIMER_READ_LS;
  __IO uint8_t TIMER_READ_MS;
  __IO uint8_t TIMER_RESERVED;    /* Unused */
  __IO uint8_t TIMER_WDG_STATUS;  /* !!! Available in FT90x Rev C onwards!!! */
} ft900_timer_wdt_regs_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#endif /* FT900_TIMER_WDT_REGISTERS_H_ */
