/**
    @file ft900_flash_registers.h

    @brief Flash controller access registers.
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

#ifndef FT900_REGISTERS_FLASH_H_
#define FT900_REGISTERS_FLASH_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* INCLUDES ************************************************************************/

#include <stdint.h>
#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

/* TYPES ***************************************************************************/

/** \brief Flash Configuration Register */
typedef struct
{
  uint8_t SPI_CLK  : 2;   ///< The serial SPI clock speed to the serial flash
                          ///< 0x0: Flash SPI clock speed = 1/2 System clock speed
                          ///< 0x1: Flash SPI clock speed = 1/3 System clock speed
                          ///< 0x2: Flash SPI clock speed = 1/4 System clock speed
                          ///< 0x3: Flash SPI clock speed = 1/5 System clock speed

  uint8_t Reserved : 6;   ///< Reserved
} flash_cfg_reg_t;

typedef union
{
  flash_cfg_reg_t B;
  REG_ACCESS_U8   U;
} flash_cfg_reg_u;

/** \brief Flash Status Register */
typedef struct
{
  uint8_t WR_IN_PROGRESS   : 1;   ///< 1: Flash Write Operations in Progress

  uint8_t Reserved_1_3     : 3;   ///< Reserved

  uint8_t DATA_WRITE_READY : 1;   ///< 1: Data for write can be written to data write port

  uint8_t DATA_READ_READY  : 1;   ///< 1: Data for read is available at data read port

  uint8_t CONTROL_BUSY     : 1;   ///< 1: The control unit is busy. This means no other command
                                  ///<    should be issued.
                                  ///< When this bit is set, bits 7, 3-0 may not be valid until
                                  ///< this bit is cleared.

  uint8_t Reserved_7       : 1;   ///< Reserved
} flash_status_reg_t;

typedef union
{
  flash_status_reg_t B;
  REG_ACCESS_U8      U;
} flash_status_reg_u;

/** @brief Register mappings for Flash Control registers */
typedef struct
{
  __IO uint8_t            RSADDR0;
  __IO uint8_t            RSADDR1;
  __IO uint8_t            RSADDR2;
  __IO uint8_t            FSADDR0;
  __IO uint8_t            FSADDR1;
  __IO uint8_t            FSADDR2;
  __IO uint8_t            BLENGTH0;
  __IO uint8_t            BLENGTH1;
  __IO uint8_t            BLENGTH2;
  __IO uint8_t            COMMAND;
       uint8_t            Reserved10;
  __IO uint8_t            SEMAPHORE;
  __IO flash_cfg_reg_u    CONFIG;
  __IO flash_status_reg_u STATUS;
  __IO uint8_t            CRCL;
  __IO uint8_t            CRCH;
       uint8_t            reserved16[0x6c];
  __IO uint8_t            CHIPID0;
  __IO uint8_t            CHIPID1;
  __IO uint8_t            CHIPID2;
  __IO uint8_t            CHIPID3;
  __IO uint8_t            DRWDATA;
} flash_regs_t;

/** @brief Register mappings for Flash Control registers */
typedef struct
{
  __IO uint8_t RSADDR0;     // 0x00
  __IO uint8_t RSADDR1;
  __IO uint8_t RSADDR2;
  __IO uint8_t FSADDR0;
  __IO uint8_t FSADDR1;
  __IO uint8_t FSADDR2;
  __IO uint8_t BLENGTH0;
  __IO uint8_t BLENGTH1;
  __IO uint8_t BLENGTH2;
  __IO uint8_t COMMAND;
       uint8_t reserved10;
  __IO uint8_t SEMAPHORE;
  __IO uint8_t CONFIG;
  __IO uint8_t STATUS;
  __IO uint8_t CRCL;
  __IO uint8_t CRCH;        // 0x0f
       uint8_t reserved16[0x6c];
  __IO uint8_t CHIPID0;     // 0x7c
  __IO uint8_t CHIPID1;
  __IO uint8_t CHIPID2;
  __IO uint8_t CHIPID3;
  __IO uint8_t DRWDATA;     // 0x80
} ft900_flash_regs_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* FT900_REGISTERS_FLASH_H_ */
