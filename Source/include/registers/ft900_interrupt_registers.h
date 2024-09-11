/**
    @file ft900_interrupt_registers.h

    @brief Interrupt management registers
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

#ifndef FT900_INTERRUPT_REGISTERS_H_
#define FT900_INTERRUPT_REGISTERS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* INCLUDES ************************************************************************/

#include <stdint.h>
#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

#define BIT_IRQ_PRASSIGN            (0)
#define MASK_IRQ_PRASSIGN           (0x1F << BIT_IRQ_PRASSIGN)

#define BIT_IRQ_CTRL_NESTMAX        (0)
#define MASK_IRQ_CTRL_NESTMAX       (0xF << BIT_IRQ_CTRL_NESTMAX)
#define BIT_IRQ_CTRL_NESTEN         (7)
#define MASK_IRQ_CTRL_NESTEN        (1 << BIT_IRQ_CTRL_NESTEN)
#define BIT_IRQ_CTRL_MASKALL        (7)
#define MASK_IRQ_CTRL_MASKALL       (1 << BIT_IRQ_CTRL_MASKALL)

/* TYPES ***************************************************************************/

/** \brief IRQ00-03 Assignment Register */
typedef struct
{
  uint32_t PR_00_ASSIGN   : 5;    ///< Priority assignment for interrupt 0
  uint32_t Reserved_5_7   : 3;    ///< Reserved
  uint32_t PR_01_ASSIGN   : 5;    ///< Priority assignment for interrupt 1
  uint32_t Reserved_13_15 : 3;    ///< Reserved
  uint32_t PR_02_ASSIGN   : 5;    ///< Priority assignment for interrupt 2
  uint32_t Reserved_21_23 : 3;    ///< Reserved
  uint32_t PR_03_ASSIGN   : 5;    ///< Priority assignment for interrupt 3
  uint32_t Reserved_29_31 : 3;    ///< Reserved
} irq_assign_00_03_reg_t;

typedef union
{
  irq_assign_00_03_reg_t B;
  REG_ACCESS_U32         U;
} irq_assign_00_03_reg_u;

/** \brief IRQ04-07 Assignment Register */
typedef struct
{
  uint32_t PR_04_ASSIGN   : 5;    ///< Priority assignment for interrupt 4
  uint32_t Reserved_5_7   : 3;    ///< Reserved
  uint32_t PR_05_ASSIGN   : 5;    ///< Priority assignment for interrupt 5
  uint32_t Reserved_13_15 : 3;    ///< Reserved
  uint32_t PR_06_ASSIGN   : 5;    ///< Priority assignment for interrupt 6
  uint32_t Reserved_21_23 : 3;    ///< Reserved
  uint32_t PR_07_ASSIGN   : 5;    ///< Priority assignment for interrupt 7
  uint32_t Reserved_29_31 : 3;    ///< Reserved
} irq_assign_04_07_reg_t;

typedef union
{
  irq_assign_04_07_reg_t B;
  REG_ACCESS_U32         U;
} irq_assign_04_07_reg_u;

/** \brief IRQ08-11 Assignment Register */
typedef struct
{
  uint32_t PR_08_ASSIGN   : 5;    ///< Priority assignment for interrupt 8
  uint32_t Reserved_5_7   : 3;    ///< Reserved
  uint32_t PR_09_ASSIGN   : 5;    ///< Priority assignment for interrupt 9
  uint32_t Reserved_13_15 : 3;    ///< Reserved
  uint32_t PR_10_ASSIGN   : 5;    ///< Priority assignment for interrupt 10
  uint32_t Reserved_21_23 : 3;    ///< Reserved
  uint32_t PR_11_ASSIGN   : 5;    ///< Priority assignment for interrupt 11
  uint32_t Reserved_29_31 : 3;    ///< Reserved
} irq_assign_08_11_reg_t;

typedef union
{
  irq_assign_08_11_reg_t B;
  REG_ACCESS_U32         U;
} irq_assign_08_11_reg_u;

/** \brief IRQ12-15 Assignment Register */
typedef struct
{
  uint32_t PR_12_ASSIGN   : 5;    ///< Priority assignment for interrupt 12
  uint32_t Reserved_5_7   : 3;    ///< Reserved
  uint32_t PR_13_ASSIGN   : 5;    ///< Priority assignment for interrupt 13
  uint32_t Reserved_13_15 : 3;    ///< Reserved
  uint32_t PR_14_ASSIGN   : 5;    ///< Priority assignment for interrupt 14
  uint32_t Reserved_21_23 : 3;    ///< Reserved
  uint32_t PR_15_ASSIGN   : 5;    ///< Priority assignment for interrupt 15
  uint32_t Reserved_29_31 : 3;    ///< Reserved
} irq_assign_12_15_reg_t;

typedef union
{
  irq_assign_12_15_reg_t B;
  REG_ACCESS_U32         U;
} irq_assign_12_15_reg_u;

/** \brief IRQ16-19 Assignment Register */
typedef struct
{
  uint32_t PR_16_ASSIGN   : 5;    ///< Priority assignment for interrupt 16
  uint32_t Reserved_5_7   : 3;    ///< Reserved
  uint32_t PR_17_ASSIGN   : 5;    ///< Priority assignment for interrupt 17
  uint32_t Reserved_13_15 : 3;    ///< Reserved
  uint32_t PR_18_ASSIGN   : 5;    ///< Priority assignment for interrupt 18
  uint32_t Reserved_21_23 : 3;    ///< Reserved
  uint32_t PR_19_ASSIGN   : 5;    ///< Priority assignment for interrupt 19
  uint32_t Reserved_29_31 : 3;    ///< Reserved
} irq_assign_16_19_reg_t;

typedef union
{
  irq_assign_16_19_reg_t B;
  REG_ACCESS_U32         U;
} irq_assign_16_19_reg_u;

/** \brief IRQ20-23 Assignment Register */
typedef struct
{
  uint32_t PR_20_ASSIGN   : 5;    ///< Priority assignment for interrupt 20
  uint32_t Reserved_5_7   : 3;    ///< Reserved
  uint32_t PR_21_ASSIGN   : 5;    ///< Priority assignment for interrupt 21
  uint32_t Reserved_13_15 : 3;    ///< Reserved
  uint32_t PR_22_ASSIGN   : 5;    ///< Priority assignment for interrupt 22
  uint32_t Reserved_21_23 : 3;    ///< Reserved
  uint32_t PR_23_ASSIGN   : 5;    ///< Priority assignment for interrupt 23
  uint32_t Reserved_29_31 : 3;    ///< Reserved
} irq_assign_20_23_reg_t;

typedef union
{
  irq_assign_20_23_reg_t B;
  REG_ACCESS_U32         U;
} irq_assign_20_23_reg_u;

/** \brief IRQ24-27 Assignment Register */
typedef struct
{
  uint32_t PR_24_ASSIGN   : 5;    ///< Priority assignment for interrupt 24
  uint32_t Reserved_5_7   : 3;    ///< Reserved
  uint32_t PR_25_ASSIGN   : 5;    ///< Priority assignment for interrupt 25
  uint32_t Reserved_13_15 : 3;    ///< Reserved
  uint32_t PR_26_ASSIGN   : 5;    ///< Priority assignment for interrupt 26
  uint32_t Reserved_21_23 : 3;    ///< Reserved
  uint32_t PR_27_ASSIGN   : 5;    ///< Priority assignment for interrupt 27
  uint32_t Reserved_29_31 : 3;    ///< Reserved
} irq_assign_24_27_reg_t;

typedef union
{
  irq_assign_24_27_reg_t B;
  REG_ACCESS_U32         U;
} irq_assign_24_27_reg_u;

/** \brief IRQ28-31 Assignment Register */
typedef struct
{
  uint32_t PR_28_ASSIGN   : 5;    ///< Priority assignment for interrupt 28
  uint32_t Reserved_5_7   : 3;    ///< Reserved
  uint32_t PR_29_ASSIGN   : 5;    ///< Priority assignment for interrupt 29
  uint32_t Reserved_13_15 : 3;    ///< Reserved
  uint32_t PR_30_ASSIGN   : 5;    ///< Priority assignment for interrupt 30
  uint32_t Reserved_21_23 : 3;    ///< Reserved
  uint32_t PR_31_ASSIGN   : 5;    ///< Priority assignment for interrupt 31
  uint32_t Reserved_29_31 : 3;    ///< Reserved
} irq_assign_28_31_reg_t;

typedef union
{
  irq_assign_28_31_reg_t B;
  REG_ACCESS_U32         U;
} irq_assign_28_31_reg_u;

typedef struct
{
  uint32_t Nested_Depth          : 4;   ///< Maximum number of nested interrupts permitted
                                        ///< (Nested Depth + 1); minimum 1 level, and maximum 16
                                        ///< levels.

  uint32_t Reserved_4_6          : 3;   ///< Reserved

  uint32_t Nested_Interrupt      : 1;   ///< Set to 1 to enable nested interrupts. This bit shall be
                                        ///< set or cleared while the Global Interrupt Mask is
                                        ///< enabled.

  uint32_t Reserved_8_30         : 23;  ///< Reserved

  uint32_t Global_Interrupt_Mask : 1;   ///< Set to 1 to mask all interrupts.
} irq_cntl_reg_t;

/** @brief Register mappings for Interrupt registers */
typedef struct
{
  __IO irq_assign_00_03_reg_u IRQ_00_03;
  __IO irq_assign_04_07_reg_u IRQ_04_07;
  __IO irq_assign_08_11_reg_u IRQ_08_11;
  __IO irq_assign_12_15_reg_u IRQ_12_15;
  __IO irq_assign_16_19_reg_u IRQ_16_19;
  __IO irq_assign_20_23_reg_u IRQ_20_23;
  __IO irq_assign_24_27_reg_u IRQ_24_27;
  __IO irq_assign_28_31_reg_u IRQ_28_31;
  __IO irq_cntl_reg_t         IRQ_CNTL;
} interrupt_regs_t;

/** @brief Register mappings for Interrupt registers */
typedef struct
{
  __IO uint8_t IRQ[32];
  union
  {
    struct
    {
      __IO uint8_t nesting;
      __IO uint8_t rsvd0;
      __IO uint8_t rsvd1;
      __IO uint8_t global_mask;
    };
    __IO uint32_t IRQ_CTRL;
  };
} ft900_interrupt_regs_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* FT900_INTERRUPT_REGISTERS_H_ */
