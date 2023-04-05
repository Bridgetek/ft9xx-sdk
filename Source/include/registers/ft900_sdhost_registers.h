/**
    @file

    @brief
    SD card host controller registers

    
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

#ifndef FT900_SDHOST_REGISTERS_H_
#define FT900_SDHOST_REGISTERS_H_

/* INCLUDES ************************************************************************/
#include <stdint.h>
#include <stdbool.h>

#include <registers/ft900_registers.h>

/* CONSTANTS ***********************************************************************/

/* TYPES ***************************************************************************/

/** @brief FT900 32 bit registers
 *  These are used to provide the actual 32bit address of the sdhost registers
 *  These are named arbitrarily
 */
/** @brief Register mappings for SPI registers - for FT900 Rev B  */
typedef struct
{
	volatile uint32_t unused0;
	/** @brief Block Size Register & Block Count Register */
	volatile uint32_t BS_BC;
	/** @brief Argument 1 Register */
    volatile uint32_t ARG1;
    /** @brief Transfer Mode Register & Command Register */
    volatile uint32_t TM_CMD;
    /** @brief Response Register 0 */
    volatile uint32_t RESPONSE0;
    /** @brief Response Register 1 */
    volatile uint32_t RESPONSE1;
    /** @brief Response Register 2 */
    volatile uint32_t RESPONSE2;
    /** @brief Response Register 3 */
    volatile uint32_t RESPONSE3;
    /** @brief Buffer Data Port Register */
    volatile uint32_t BUFDATAPORT;
    /** @brief Present State Register */
    volatile uint32_t PRESENTSTATE;
    /** @brief Host Control 1 Register & Power Control Register & Block Gap Control Register */
    volatile uint32_t HOSTCTRL1_PWR_BLKGAP;
    /** @brief Clock Control Register & Timeout Control Register & Software Reset Register */
    volatile uint32_t CLK_TIMEOUT_SWRESET;
    /** @brief Normal Interrupt Status Register & Error Interrupt Status Register */
    volatile uint32_t NORMINTSTATUS_ERRINTSTATUS;
    /** @brief Normal Interrupt Status Enable Reg. & Error Interrupt Status Enable Reg. */
    volatile uint32_t NORMINTSTATUSEN_ERRINTSTATUSEN;
    /** @brief Normal Interrupt Signal Enable Reg. & Error Interrupt Signal Enable Reg. */
    volatile uint32_t NORMINTSIGEN_ERRINTSIGEN;
    /** @brief Auto CMD12 Error Status Register & Host Control 2 Register */
    volatile uint32_t AUTOCMD12_HOSTCTRL2;
    /** @brief Capabilities Register 0 */
    volatile uint32_t CAP0;
    /** @brief Capabilities Register 1 */
    volatile uint32_t CAP1;
    /** @brief Maximum Current Capabilities Register 0 */
    volatile uint32_t MAXCURRENTCAP0;
    /** @brief Maximum Current Capabilities Register 1 */
    volatile uint32_t MAXCURRENTCAP1;
    /** @brief Force Event Reg. for Auto CMD12 Error Status & Force Event Reg. for Error Interrupt Status */
    volatile uint32_t FORCEEVENTCMD12_FORCEEVENTERRINT;
    /** @brief ADMA Error Status Register */
    volatile uint32_t ADMAERRORSTATUS;
    /** @brief ADMA System Address Register */
    volatile uint32_t ADMASYSADDR;
	volatile uint32_t unused1;
    /** @brief Preset Value Register 0 */
    volatile uint32_t PRESETVALUE0;
    /** @brief Preset Value Register 1 */
    volatile uint32_t PRESETVALUE1;
    /** @brief Preset Value Register 2 */
    volatile uint32_t PRESETVALUE2;
    /** @brief Preset Value Register 3 */
    volatile uint32_t PRESETVALUE3;
} ft900_sdhost_regs_t;

typedef struct
{
	/** @brief Vendor-defined Register 0 */
	volatile uint32_t VENDOR0;
	/** @brief Vendor-defined Register 1 */
    volatile uint32_t VENDOR1;
	volatile uint32_t unused2;
	volatile uint32_t unused3;
	volatile uint32_t unused4;
    /** @brief Vendor-defined Register 5 */
    volatile uint32_t VENDOR5;
} ft900_sdhost_vendor_regs_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#endif /* FT900_SDHOST_REGISTERS_H_ */
