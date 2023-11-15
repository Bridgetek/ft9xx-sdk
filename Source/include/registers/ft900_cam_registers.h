/**
    @file ft900_cam_registers.h

    @brief Camera/Parallel interface registers
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


#ifndef FT900_CAM_REGISTERS_H_
#define FT900_CAM_REGISTERS_H_

/* INCLUDES ************************************************************************/

#include <stdint.h>
#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/
#define BIT_CAM_REG1_THRESHOLD      (0)
#define MASK_CAM_REG1_THRESHOLD     (0xFFF << BIT_CAM_REG1_THRESHOLD)
#define BIT_CAM_REG1_TRIGPAT0       (12)
#define MASK_CAM_REG1_TRIGPAT0      (1 << BIT_CAM_REG1_TRIGPAT0)
#define BIT_CAM_REG1_TRIGPAT1       (13)
#define MASK_CAM_REG1_TRIGPAT1      (1 << BIT_CAM_REG1_TRIGPAT1)
#define BIT_CAM_REG1_TRIGPAT2       (14)
#define MASK_CAM_REG1_TRIGPAT2      (1 << BIT_CAM_REG1_TRIGPAT2)
#define BIT_CAM_REG1_TRIGPAT3       (15)
#define MASK_CAM_REG1_TRIGPAT3      (1 << BIT_CAM_REG1_TRIGPAT3)
#define BIT_CAM_REG1_COUNT          (16)
#define MASK_CAM_REG1_COUNT         (0xFFFF << BIT_CAM_REG1_COUNT)

#define BIT_CAM_REG2_FULLNESS       (0)
#define MASK_CAM_REG2_FULLNESS      (0xFFF << BIT_CAM_REG2_FULLNESS)

#define BIT_CAM_REG4_INTEN          (0)
#define MASK_CAM_REG4_INTEN         (1 << BIT_CAM_REG4_INTEN)
#define BIT_CAM_REG4_CLKSENSE       (1)
#define MASK_CAM_REG4_CLKSENSE      (1 << BIT_CAM_REG4_CLKSENSE)
#define BIT_CAM_REG4_HASDATA        (2)
#define MASK_CAM_REG4_HASDATA       (1 << BIT_CAM_REG4_HASDATA)

/* TYPES ***************************************************************************/

typedef struct
{
  uint32_t THRESHOLD : 12;  ///< Specifies the threshold value for the HAS_DATA signal.
                            ///< It must be a multiple of 4 bytes.
  uint32_t TRIG_PAT  : 4 ;  ///< This specifies the data capture trigger position.
                            ///< Data capture starts on the cycle when trigger
                            ///< transitions from 0 to 1
                            ///<    En[1]/VD | En[0]/HD | Trigger
                            ///<        0    |     0    | TRIG_PAT[0]
                            ///<        0    |     1    | TRIG_PAT[1]
                            ///<        1    |     0    | TRIG_PAT[2]
                            ///<        1    |     1    | TRIG_PAT[3]
  uint32_t COUNT     : 16;  ///< Number of bytes to capture after the last trigger event.
                            ///< This must be in multiple of 4 bytes
} dcap_reg_1_t;

typedef union
{
  dcap_reg_1_t   B;
  REG_ACCESS_U32 U;
} dcap_reg_1_u;

typedef struct
{
  uint32_t FULLNESS    : 12; ///< Specifies the number of bytes that can be safely
                             ///< read from the FIFO. Its value is always a multiple of 4.
  uint32_t Reserved_12 : 24;
} dcap_reg_2_t;

typedef union
{
  dcap_reg_2_t   B;
  REG_ACCESS_U32 U;
} dcap_reg_2_u;

typedef struct
{
  uint32_t DATA; ///< Next four samples from the FIFO. Reading this will remove the
                 ///< sample from the FIFO. When FULLNESS is 0, the effect is
                 ///< non-deterministic
} dcap_reg_3_t;

typedef union
{
  dcap_reg_3_t   B;
  REG_ACCESS_U32 U;
} dcap_reg_3_u;

typedef struct
{
  uint32_t INT_ENB    : 1 ;   ///< 1: enable interrupt; an interrupt will be generated
                              ///< when HAS_DATA = 1
  uint32_t CLK_SENSE  : 1 ;   ///< 1: capture data on clock rising edge
  uint32_t HAS_DATA   : 1 ;   ///< Set when FIFO contains at least THRESHOLD bytes.
  uint32_t Reserved_4 : 29;
} dcap_reg_4_t;

typedef union
{
  dcap_reg_4_t   B;
  REG_ACCESS_U32 U;
} dcap_reg_4_u;

typedef struct
{
  __IO dcap_reg_1_u CAM_REG1;
  __IO dcap_reg_2_u CAM_REG2;
  __IO dcap_reg_3_u CAM_REG3;
  __IO dcap_reg_4_u CAM_REG4;
} cam_regs_t;

/** @brief Register mappings for CAM registers */
typedef struct
{
  __IO uint32_t CAM_REG1;
  __IO uint32_t CAM_REG2;
  __IO uint32_t CAM_REG3;
  __IO uint32_t CAM_REG4;
} ft900_cam_regs_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#endif /* FT900_CAM_REGISTERS_H_ */
