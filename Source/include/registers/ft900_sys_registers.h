/**
    @file ft900_sys_registers.h

    @brief Chip management registers
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

#ifndef FT900_SYS_REGISTERS_H_
#define FT900_SYS_REGISTERS_H_

/* INCLUDES ************************************************************************/

#include <stdint.h>

#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

#define BIT_SYS_CLKCFG_ENA(__peri__)     (__peri__)
#define MASK_SYS_CLKCFG_ENA(__peri__)    (1 << BIT_SYS_CLKCFG_ENA(__peri__))

/* !!!AVAILABLE from FT930 and FT900 REV C ONWARDS!!!
 * CPU_CLK_DIV - CPU Clock frequency setting:
 * 0: CPU runs at system clock speed (100 MHz)
 * 1: CPU runs at system clock / 2
 * 2: CPU runs at system clock / 4
 * 3: CPU runs at system clock / 8
 * 4: CPU runs at system clock / 64
 * 5: CPU runs at system clock / 128
 * 6: CPU runs at system clock / 512
 * Others: CPU is stopped.
 * */
#define BIT_SYS_CLKCFG_CPU_CLK_DIV  (16)
#define MASK_SYS_CLKCFG_CPU_CLK_DIV (0xF << BIT_SYS_CLKCFG_CPU_CLK_DIV)

/******************************** START of ***********************************/
/**************** BIT MASKS FOR HIGHER 16-bit WORD of PMCFG ******************/

/* Bit masks for the PMCFG register */
#if defined(__FT930__)
/** RTC Alarm Wake Up interrupt pending; write 1 to clear. This bit will be set when RTC alarm is
 *  active while it is in sleep mode. */
#define BIT_SYS_PMCFG_RTC_ALARM_IRQ_PEND  (15)
#define MASK_SYS_PMCFG_RTC_ALARM_IRQ_PEND (0x1 << BIT_SYS_PMCFG_RTC_ALARM_IRQ_PEND)

/** SLAVE Wake Up interrupt pending; write 1 to clear. This bit will be set when there is wake up
 *  event from SLAVE. */
#define BIT_SYS_PMCFG_SLAVE_PERI_IRQ_PEND  (10)
#define MASK_SYS_PMCFG_SLAVE_PERI_IRQ_PEND (0x1 << BIT_SYS_PMCFG_SLAVE_PERI_IRQ_PEND)
#else
/** RTC Alarm Wake Up interrupt pending; write 1 to clear. This bit will be set when RTC alarm is
 *  active while it is in sleep mode.
 *  !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
 * */
#define BIT_SYS_PMCFG_RTC_ALARM_IRQ_PEND  (15)
#define MASK_SYS_PMCFG_RTC_ALARM_IRQ_PEND (0x1 << BIT_SYS_PMCFG_RTC_ALARM_IRQ_PEND)

/** RTC Battery Low Detected pending; write 1 to clear. If RTC_VBAT_IRQ_EN=1, an interrupt will be
 *  generated.
 *  Note: Clear this bit before set RTC_VBAT_IRQ_EN to '1'.
 *  !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
 * */
#define BIT_SYS_PMCFG_RTC_VBAT_LOW_PEND  (14)
#define MASK_SYS_PMCFG_RTC_VBAT_LOW_PEND (0x1 << BIT_SYS_PMCFG_RTC_VBAT_LOW_PEND)

/** RTC good Battery replacement Detected pending; write 1 to clear. If RTC_VBAT_IRQ_EN=1, an
 *  interrupt will be generated.
 *  Note: Clear this bit before set RTC_VBAT_IRQ_EN to '1'.
 *  !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
 * */
#define BIT_SYS_PMCFG_RTC VBAT REPLACED_PEND  (13)
#define MASK_SYS_PMCFG_RTC VBAT REPLACED_PEND (0x1 << BIT_SYS_PMCFG_RTC VBAT REPLACED_PEND)
#endif // #if defined(__FT930__)

/** GPIO interrupt during system shut down with clock not running. */
#define BIT_SYS_PMCFG_PM_GPIO_IRQ_PEND  (9)
#define MASK_SYS_PMCFG_PM_GPIO_IRQ_PEND (0x1 << BIT_SYS_PMCFG_PM_GPIO_IRQ_PEND)

/** Slow clock 5ms timer interrupt pending; write 1 to clear. If enabled, an interrupt will be
 *  generated. */
#define BIT_SYS_PMCFG_SLOWCLK_5ms_IRQ_PEND  (8)
#define MASK_SYS_PMCFG_SLOWCLK_5ms_IRQ_PEND (0x1 << BIT_SYS_PMCFG_)

/** Remote Wakeup Interrupt pending to USB Host; write 1 to clear. If enabled, an interrupt will be
 *  generated on PM irq. */
#define BIT_SYS_PMCFG_RM_WK_HOST  (7)
#define MASK_SYS_PMCFG_RM_WK_HOST (0x1 << BIT_SYS_PMCFG_RM_WK_HOST)

/** Device Connect Interrupt pending to USB Host; write 1 to clear. If enabled, an interrupt will be
 *  generated on PM irq. */
#define BIT_SYS_PMCFG_DEV_CONN_HOST  (6)
#define MASK_SYS_PMCFG_DEV_CONN_HOST (0x1 << BIT_SYS_PMCFG_DEV_CONN_HOST)

/** Device Disconnect Interrupt pending to USB Host; write 1 to clear. If enabled, an interrupt will
 *  be generated on PM irq. */
#define BIT_SYS_PMCFG_DEV_DIS_HOST  (5)
#define MASK_SYS_PMCFG_DEV_DIS_HOST (0x1 << BIT_SYS_PMCFG_DEV_DIS_HOST)

/** Device Connect Interrupt pending to USB Device; write 1 to clear. If enabled, an interrupt will
 *  be generated on PM irq. */
#define BIT_SYS_PMCFG_DEV_CONN_DEV  (4)
#define MASK_SYS_PMCFG_DEV_CONN_DEV (0x1 << BIT_SYS_PMCFG_DEV_CONN_DEV)

/** Device Disconnect Interrupt pending to USB Device; write 1 to clear. If enabled, an interrupt
 *  will be generated on PM irq. */
#define BIT_SYS_PMCFG_DEV_DIS_DEV  (3)
#define MASK_SYS_PMCFG_DEV_DIS_DEV (0x1 << BIT_SYS_PMCFG_DEV_DIS_DEV)

/** Host Reset Interrupt pending to USB Device; write 1 to clear. If enabled, an interrupt will be
 *  generated on PM irq. */
#define BIT_SYS_PMCFG_HOST_RST_DEV  (2)
#define MASK_SYS_PMCFG_HOST_RST_DEV (0x1 << BIT_SYS_PMCFG_HOST_RST_DEV)

/** Host Resume Interrupt pending to USB Device; write 1 to clear. If enabled, an interrupt will be
 *  generated on PM irq. */
#define BIT_SYS_PMCFG_HOST_RESUME_DEV  (1)
#define MASK_SYS_PMCFG_HOST_RESUME_DEV (0x1 << BIT_SYS_PMCFG_HOST_RESUME_DEV)

/** Over current detected Interrupt pending if enabled; write 1 to clear. If enabled, an interrupt
 *  will be generated on PM irq. */
#define BIT_SYS_PMCFG_OC_DETECT  (0)
#define MASK_SYS_PMCFG_OC_DETECT (0x1 << BIT_SYS_PMCFG_OC_DETECT)

/********************************  END ***************************************/
/*****************************************************************************/

/******************************** START of ***********************************/
/**************** BIT MASKS FOR LOWER 16-bit WORD of PMCFG *******************/

#if defined(__FT900__)
/** 0 : Enables external VBUS, 1: Disables external VBUS
 * Note: When OC_DETECT_EN is set and an over current condition occurs, hardware will automatically
 *       set this bit.
 * This bit cannot be cleared by SW as long as Over Current condition exists.
 * !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
 */
#define BIT_SYS_PMCFG_PSWN  (15)
#define MASK_SYS_PMCFG_PSWN (0x1 << BIT_SYS_PMCFG_PSWN)

/** 0 : RTC Battery low detection is enabled by default; if this bit is set, PM will detect for
 *      replacement of Battery.
 * !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
 * */
#define BIT_SYS_PMCFG_RTC_VBAT_STATUS_DETECT  (14)
#define MASK_SYS_PMCFG_RTC_VBAT_STATUS_DETECT (0x1 << BIT_SYS_PMCFG_RTC_VBAT_STATUS_DETECT)

/** 1 : RTC Battery Interrupt Enable; if this bit is set, an interrupt will be generated on PM irq
 *      when RTC_VBAT_IRQ_PEND becomes active.
 * !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
 * */
#define BIT_SYS_PMCFG_RTC_VBAT_IRQ_EN  (13)
#define MASK_SYS_PMCFG_RTC_VBAT_IRQ_EN (0x1 << BIT_SYS_PMCFG_RTC_VBAT_IRQ_EN)

/** 1 : RTC Alarm Wake Up Interrupt Enable; if this bit is set, an interrupt will be generated on PM
 *      irq when RTC_ALARM_IRQ_PEND becomes active.
 * !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
 * */
#define BIT_SYS_PMCFG_RTC_ALARM_IRQ_EN  (12)
#define MASK_SYS_PMCFG_RTC_ALARM_IRQ_EN (0x1 << BIT_SYS_PMCFG_RTC_ALARM_IRQ_EN)

#elif defined(__FT930__)
/** 1 : RTC Alarm Wake Up Interrupt Enable; if this bit is set, an interrupt will be generated on PM
 *      irq when RTC_ALARM_IRQ_PEND becomes active. */
#define BIT_SYS_PMCFG_RTC_ALARM_IRQ_EN  (12)
#define MASK_SYS_PMCFG_RTC_ALARM_IRQ_EN (0x1 << BIT_SYS_PMCFG_RTC_ALARM_IRQ_EN)

/** 1 : SLAVE Wake Up Interrupt Enable; If this bit is set, an interrupt will be generated on PM irq
 *      when SLAVE_PERI_IRQ_PEND becomes active. */
#define BIT_SYS_PMCFG_SLAVE_PERI_IRQ_EN  (11)
#define MASK_SYS_PMCFG_SLAVE_PERI_IRQ_EN (0x1 << BIT_SYS_PMCFG_SLAVE_PERI_IRQ_EN)
#endif

/** 1 : Enable USB Device Phy. */
#define BIT_SYS_PMCFG_DEV_PHY_EN  (10)
#define MASK_SYS_PMCFG_DEV_PHY_EN (0x1 << BIT_SYS_PMCFG_DEV_PHY_EN)

/** 1 : disable system oscillator when powering down.\n
 *  0 : do not disable system oscillator when powering down. */
#define BIT_SYS_PMCFG_PM_PWRDN_MODE  (9)
#define MASK_SYS_PMCFG_PM_PWRDN_MODE (0x1 << BIT_SYS_PMCFG_PM_PWRDN_MODE)

/** 1 : power down system.\n
 *  This bit should be cleared after the system wakes up or at least 60-100us prior to setting it 1
 *  again. */
#define BIT_SYS_PMCFG_PM_PWRDN  (8)
#define MASK_SYS_PMCFG_PM_PWRDN (0x1 << BIT_SYS_PMCFG_PM_PWRDN)

/** 1 : enable slow clock 5ms timer interrupt. */
#define BIT_SYS_PMCFG_SLOWCLOCK_5ms_IRQ_EN  (7)
#define MASK_SYS_PMCFG_SLOWCLOCK_5ms_IRQ_EN (0x1 << BIT_SYS_PMCFG_SLOWCLOCK_5ms_IRQ_EN)

/** 1 : To start the 1-shot slow clock 5ms timer; once started it cannot be stopped.\n
 *  This bit will be cleared automatically when the timer expires. */
#define BIT_SYS_PMCFG_SLOWCLOCK_5ms_START  (6)
#define MASK_SYS_PMCFG_SLOWCLOCK_5ms_START (0x1 << BIT_SYS_PMCFG_SLOWCLOCK_5ms_START)

/** Normally host activity detection is performed only when required, setting this bit will force
 *  the PM to check for host connection activities regardless. */
#define BIT_SYS_PMCFG_FORCE_HOST_DET  (5)
#define MASK_SYS_PMCFG_FORCE_HOST_DET (0x1 << BIT_SYS_PMCFG_FORCE_HOST_DET)

/** Normally device activity detection is performed only when required, setting this bit will force
 *  the PM to check for device connection activities regardless. */
#define BIT_SYS_PMCFG_FORCE_DEV_DET  (4)
#define MASK_SYS_PMCFG_FORCE_DEV_DET (0x1 << BIT_SYS_PMCFG_FORCE_DEV_DET)

/** 1 : Enable remote wake up detection to USB host.\n
 *      Enable interrupt to pm irq when RM_WK_HOST is set. */
#define BIT_SYS_PMCFG_RM_WK_HOST_EN  (3)
#define MASK_SYS_PMCFG_RM_WK_HOST_EN (0x1 << BIT_SYS_PMCFG_RM_WK_HOST_EN)

/** 1 : Enable device connection/disconnect detection to USB Host.\n
 *      Enable interrupt to pm irq when either DEV_CONN_HOST or DEV_DIS_HOST is set. */
#define BIT_SYS_PMCFG_HOST_DETECT_EN  (2)
#define MASK_SYS_PMCFG_HOST_DETECT_EN (0x1 << BIT_SYS_PMCFG_HOST_DETECT_EN)

/** 1 : Enable device connect/disconnect to external host or external host reset detection.\n
 *      Enable interrupt to pm irq when any of DEV_CONN_DEV, DEV_DIS_DEV and HOST_RST_DEV is set. */
#define BIT_SYS_PMCFG_DEV_DETECT_EN  (1)
#define MASK_SYS_PMCFG_DEV_DETECT_EN (0x1 << BIT_SYS_PMCFG_DEV_DETECT_EN)

/** 1 : Enable Over current detection.\n
 *      Enable interrupt to pm irq when OC_DETECT is set */
#define BIT_SYS_PMCFG_OC_DETECT_EN  (0)
#define MASK_SYS_PMCFG_OC_DETECT_EN (0x1 << BIT_SYS_PMCFG_OC_DETECT_EN)

/******************************** END ****************************************/
/*****************************************************************************/

/* Bit masks for the MSC0CFG register */

/** @brief Reset all peripherals
 *  Write 1 to cause soft reset to all peripherals. It is automatically cleared. */
#define BIT_SYS_MSC0CFG_PERI_SOFTRESET  (31)
#define MASK_SYS_MSC0CFG_PERI_SOFTRESET (0x1 << BIT_SYS_MSC0CFG_PERI_SOFTRESET)

/** @brief Reset PWM
 *  Write 1 to cause soft reset to PWM. It is automatically cleared. */
#define BIT_SYS_MSC0CFG_PWM_SOFTRESET  (30)
#define MASK_SYS_MSC0CFG_PWM_SOFTRESET (0x1 << BIT_SYS_MSC0CFG_PWM_SOFTRESET)

#if defined(__FT930__)
/** Clock Select for UART4 */
#define BIT_SYS_MSC0CFG_UART4_CLKSEL  (29)
#define MASK_SYS_MSC0CFG_UART4_CLKSEL (0x1 << BIT_SYS_MSC0CFG_UART4_CLKSEL)

/** FIFO Select for UART4 */
#define BIT_SYS_MSC0CFG_UART4_FIFOSEL  (28)
#define MASK_SYS_MSC0CFG_UART4_FIFOSEL (0x1 << BIT_SYS_MSC0CFG_UART4_FIFOSEL)

/** INT Select for UART4 */
#define BIT_SYS_MSC0CFG_UART4_INTSEL  (27)
#define MASK_SYS_MSC0CFG_UART4_INTSEL (0x1 << BIT_SYS_MSC0CFG_UART4_INTSEL)

/** Clock Select for UART3 */
#define BIT_SYS_MSC0CFG_UART3_CLKSEL  (26)
#define MASK_SYS_MSC0CFG_UART3_CLKSEL (0x1 << BIT_SYS_MSC0CFG_UART3_CLKSEL)

/** FIFO Select for UART3 */
#define BIT_SYS_MSC0CFG_UART3_FIFOSEL  (25)
#define MASK_SYS_MSC0CFG_UART3_FIFOSEL (0x1 << BIT_SYS_MSC0CFG_UART3_FIFOSEL)

/** INT Select for UART3 */
#define BIT_SYS_MSC0CFG_UART3_INTSEL  (24)
#define MASK_SYS_MSC0CFG_UART3_INTSEL (0x1 << BIT_SYS_MSC0CFG_UART3_INTSEL)

/** @brief VBUS detection enable
 *  Write 1 to switch on VBUS to the detection circuitry.
 *  Write 0 to cut-off VBUS from the detection circuitry.
 */
#define BIT_SYS_MSC0CFG_USB_VBUS_EN  (22)
#define MASK_SYS_MSC0CFG_USB_VBUS_EN (0x1 << BIT_SYS_MSC0CFG_USB_VBUS_EN)

#else

/** @brief Swap I2C master and slave
 *  1 : swop the I2C master and I2C slave pad positions */
#define BIT_SYS_MSC0CFG_I2C_SWOP  (29)
#define MASK_SYS_MSC0CFG_I2C_SWOP (0x1 << BIT_SYS_MSC0CFG_I2C_SWOP)

/** @brief PWM count external trigger selection
 *  If any of the GPIO is used for this purpose, the pad must be configured solely for this use.
 *  - 0 : none
 *  - 1 : gpio 18
 *  - 2 : gpio 26
 *  - 3 : gpio 35
 *  - 4 : gpio 40
 *  - 5 : gpio 46
 *  - 6 : gpio 52
 *  - 7 : gpio 58
 */
#define BIT_SYS_MSC0CFG_PWM_TRIG_SEL  (26)
#define MASK_SYS_MSC0CFG_PWM_TRIG_SEL (0x7 << BIT_SYS_MSC0CFG_PWM_TRIG_SEL)

/** @brief CAN 0 divider
 *  1 : Extend further the divider of CAN 0 by a  factor of 16. */
#define BIT_SYS_MSC0CFG_CAN0_SLOW  (25)
#define MASK_SYS_MSC0CFG_CAN0_SLOW (0x1 << BIT_SYS_MSC0CFG_CAN0_SLOW)

/** @brief CAN 1 divider
 *  1 : Extend further the divider of CAN 1 by a  factor of 16. */
#define BIT_SYS_MSC0CFG_CAN1_SLOW  (24)
#define MASK_SYS_MSC0CFG_CAN1_SLOW (0x1 << BIT_SYS_MSC0CFG_CAN1_SLOW)

#endif

/** @brief HIGH SPEED MODE monitoring (Read Only)
 *  Available for FT930 and FT900 Rev.C ONLY. This Bit is reserved for FT900 Rev B.
 *  1: it indicates USB is in high speed mode.
 *  0: it indicates USB is in full speed mode.
 */
#define BIT_SYS_MSC0CFG_HIGH_SPED_MODE  (23)
#define MASK_SYS_MSC0CFG_HIGH_SPED_MODE (0x1 << BIT_SYS_MSC0CFG_HIGH_SPED_MODE)

/** Clock Select for UART1 */
#define BIT_SYS_MSC0CFG_UART1_CLKSEL  (21)
#define MASK_SYS_MSC0CFG_UART1_CLKSEL (0x1 << BIT_SYS_MSC0CFG_UART1_CLKSEL)

/** FIFO Select for UART1 */
#define BIT_SYS_MSC0CFG_UART1_FIFOSEL  (20)
#define MASK_SYS_MSC0CFG_UART1_FIFOSEL (0x1 << BIT_SYS_MSC0CFG_UART1_FIFOSEL)

/** INT Select for UART1 */
#define BIT_SYS_MSC0CFG_UART1_INTSEL  (19)
#define MASK_SYS_MSC0CFG_UART1_INTSEL (0x1 << BIT_SYS_MSC0CFG_UART1_INTSEL)

/** Clock Select for UART2 */
#define BIT_SYS_MSC0CFG_UART2_CLKSEL  (18)
#define MASK_SYS_MSC0CFG_UART2_CLKSEL (0x1 << BIT_SYS_MSC0CFG_UART2_CLKSEL)

/** FIFO Select for UART2 */
#define BIT_SYS_MSC0CFG_UART2_FIFOSEL  (17)
#define MASK_SYS_MSC0CFG_UART2_FIFOSEL (0x1 << BIT_SYS_MSC0CFG_UART2_FIFOSEL)

/** INT Select for UART2 */
#define BIT_SYS_MSC0CFG_UART2_INTSEL  (16)
#define MASK_SYS_MSC0CFG_UART2_INTSEL (0x1 << BIT_SYS_MSC0CFG_UART2_INTSEL)

/** @brief USB Host EHCI and USB Host ATX Reset
 *  Write 1 to cause USB Host EHCI and ATX reset; it is automatically cleared immediately.
 *  Software needs to wait for EHCI to complete its reset (~200ms). */
#define BIT_SYS_MSC0CFG_HOST_RESET_ALL  (15)
#define MASK_SYS_MSC0CFG_HOST_RESET_ALL (0x1 << BIT_SYS_MSC0CFG_HOST_RESET_ALL)

/** @brief USB Host EHCI Reset.
 *  Write 1 to cause USB Host EHCI reset; it is automatically cleared immediately.
 *  Software needs to wait for EHCI to complete its reset (~200ms). */
#define BIT_SYS_MSC0CFG_HOST_RESET_EHCI  (14)
#define MASK_SYS_MSC0CFG_HOST_RESET_EHCI (0x1 << BIT_SYS_MSC0CFG_HOST_RESET_EHCI)

/** @brief USB Host ATX Reset
 *  Write 1 to cause USB Host ATX reset; it is automatically cleared immediately.
 */
#define BIT_SYS_MSC0CFG_HOST_RESET_ATX  (13)
#define MASK_SYS_MSC0CFG_HOST_RESET_ATX (0x1 << BIT_SYS_MSC0CFG_HOST_RESET_ATX)

/** @brief USB Device Wakeup
 *  1 : Drive K-state on Device USB port; software must maintain the 1ms requirement before turning
 *      it off. */
#define BIT_SYS_MSC0CFG_DEV_RMWAKEUP  (12)
#define MASK_SYS_MSC0CFG_DEV_RMWAKEUP (0x1 << BIT_SYS_MSC0CFG_DEV_RMWAKEUP)

/** @brief USB Device and USB Device ATX Reset
 *  Write 1 to cause USB Dev Controller and ATX reset; it is automatically cleared immediately. */
#define BIT_SYS_MSC0CFG_DEV_RESET_ALL  (11)
#define MASK_SYS_MSC0CFG_DEV_RESET_ALL (0x1 << BIT_SYS_MSC0CFG_DEV_RESET_ALL)

/** @brief USB Device Reset
 *  Write 1 to cause USB Dev Controller reset; it is automatically cleared immediately. */
#define BIT_SYS_MSC0CFG_DEV_RESET_CONTROLLER  (10)
#define MASK_SYS_MSC0CFG_DEV_RESET_CONTROLLER (0x1 << BIT_SYS_MSC0CFG_DEV_RESET_CONTROLLER)

/** @brief USB Device ATX Reset
 *  Write 1 to cause USB Dev ATX reset; it is automatically cleared immediately. */
#define BIT_SYS_MSC0CFG_DEV_RESET_ATX  (9)
#define MASK_SYS_MSC0CFG_DEV_RESET_ATX (0x1 << BIT_SYS_MSC0CFG_DEV_RESET_ATX)

/** @brief Ethernet PHY Reset
 *  Write 1 to cause Ethernet phy reset; it is automatically cleared immediately. */
#define BIT_SYS_MSC0CFG_MAC_RESET_PHY  (8)
#define MASK_SYS_MSC0CFG_MAC_RESET_PHY (0x1 << BIT_SYS_MSC0CFG_MAC_RESET_PHY)

/** @brief BCD Host Mode
 *  - 0 : SDP
 *  - 1 : DCP
 *  - 2 : CDPI
 *  - 3 : CDPII */
#define BIT_SYS_MSC0CFG_BCDHOST_MODE  (6)
#define MASK_SYS_MSC0CFG_BCDHOST_MODE (0x3 << BIT_SYS_MSC0CFG_BCDHOST_MODE)

/** @brief Enable BCD Host
 *  1 : enable BCD Host */
#define BIT_SYS_MSC0CFG_BCDHOST_EN  (5)
#define MASK_SYS_MSC0CFG_BCDHOST_EN (0x1 << BIT_SYS_MSC0CFG_BCDHOST_EN)

/** @brief BCD Host Software Reset (Write)
 *  - 1 : Generate software reset to
 *    + BCD Host : if BCDHOST_EN = 1
 *    + BCD Dev : if BCDDEV_EN = 1
 *  It is automatically cleared immediately */
#define BIT_SYS_MSC0CFG_BCD_SOFTRESET  (4)
#define MASK_SYS_MSC0CFG_BCD_SOFTRESET (0x1 << BIT_SYS_MSC0CFG_BCD_SOFTRESET)

/** @brief BCD Device Detection Running (Read)
 *  1 : indicates BCD Device detection is running */
#define BIT_SYS_MSC0CFG_BCDDEV_DETECT_RUNNING  (4)
#define MASK_SYS_MSC0CFG_BCDDEV_DETECT_RUNNING (0x1 << BIT_SYS_MSC0CFG_BCDDEV_DETECT_RUNNING)

/** @brief Enable BCD Device (Write)
 *  1 : enable BCD Device */
#define BIT_SYS_MSC0CFG_BCDDEV_EN  (3)
#define MASK_SYS_MSC0CFG_BCDDEV_EN (0x1 << BIT_SYS_MSC0CFG_BCDDEV_EN)

/** @brief BCD Device Detection Complete (Read)
 *  1 : indicates BCD Device detection is done */
#define BIT_SYS_MSC0CFG_BCDDEV_DETECT_COMPLETE  (3)
#define MASK_SYS_MSC0CFG_BCDDEV_DETECT_COMPLETE (0x1 << BIT_SYS_MSC0CFG_BCDDEV_DETECT_COMPLETE)

/** @brief Enable BCD Secondary Detection (Write)
 *  1 : enable secondary detection. */
#define BIT_SYS_MSC0CFG_BCDDEV_SD_EN  (2)
#define MASK_SYS_MSC0CFG_BCDDEV_SD_EN (0x1 << BIT_SYS_MSC0CFG_BCDDEV_SD_EN)

/** @brief BCD SDP Detected (Read)
 *  1 : SDP detected. */
#define BIT_SYS_MSC0CFG_BCDDEV_SDP_FOUND  (2)
#define MASK_SYS_MSC0CFG_BCDDEV_SDP_FOUND (0x1 << BIT_SYS_MSC0CFG_BCDDEV_SDP_FOUND)

/** @brief BCD Connection Enable (Write)
 *  1 : enable connection of VDP_SRC after DCP detection. */
#define BIT_SYS_MSC0CFG_BCDDEV_VDP_EN_POST_DCP  (1)
#define MASK_SYS_MSC0CFG_BCDDEV_VDP_EN_POST_DCP (0x1 << BIT_SYS_MSC0CFG_BCDDEV_VDP_EN_POST_DCP)

/** @brief BCD CPD Detected (Read)
 *  1 : CDP detected. */
#define BIT_SYS_MSC0CFG_BCDDEV_CDP_FOUND  (1)
#define MASK_SYS_MSC0CFG_BCDDEV_CDP_FOUND (0x1 << BIT_SYS_MSC0CFG_BCDDEV_CDP_FOUND)

/** @brief BCD Logic Comparison
 *  1 : disable logic comparison during BCD detections.*/
#define BIT_SYS_MSC0CFG_BCDDEV_LGC_COMP_INHIB  (0)
#define MASK_SYS_MSC0CFG_BCDDEV_LGC_COMP_INHIB (0x1 << BIT_SYS_MSC0CFG_BCDDEV_LGC_COMP_INHIB)
/** @brief BCD DCP Detected (Read)
 *  1 : DCP detected */
#define BIT_SYS_MSC0CFG_BCDDEV_DCP_FOUND  (0)
#define MASK_SYS_MSC0CFG_BCDDEV_DCP_FOUND (0x1 << BIT_SYS_MSC0CFG_BCDDEV_DCP_FOUND)

#if defined(__FT930__)
/** 1 : WatchDog Second Level Reset;
 *      If this bit is set it indicates the second level watchdog reset has occurred in the previous
 *      operation. Write '1' to clear this bit.
 *      !!! Please note this bit must be cleared to enable this function again !!! */
#define BIT_SYS_GLOBAL_RST_WDG_RESET  (2)
#define MASK_SYS_GLOBAL_RST_WDG_RESET (0x1 << BIT_SYS_GLOBAL_RST_WDG_RESET)
#endif

/** Below defines are:
 * !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
 */
/** 1 : Soft Global Reset;
 *      Write 1 to reset the system as to POR state.
 *      Reading 1 from this bit indicates a soft global reset has been performed from the previous
 *      operation.
 *      Write 0 to clear this bit.
 *      NOTE: This bit must be cleared before it can be enabled again.
 */
#define BIT_SYS_GLOBAL_RST_SOFT_RESET  (1)
#define MASK_SYS_GLOBAL_RST_SOFT_RESET (0x1 << BIT_SYS_GLOBAL_RST_SOFT_RESET)

/** 1 : External Hardware Reset;
 *      If it is set it indicates the external reset has been activated.
 *      Write '1' to clear it. */
#define BIT_SYS_GLOBAL_RST_HW_RESET  (0)
#define MASK_SYS_GLOBAL_RST_HW_RESET (0x1 << BIT_SYS_GLOBAL_RST_HW_RESET)

/* TYPES ***************************************************************************/

/** \brief Chip ID Register */
typedef struct
{
  uint32_t Chip_ID; ///< The two MSBs (09XX) depict FT900 series and the two LSBs (XXXX) shows the
                    ///< revision of the chip.
} sys_chip_id_reg_t;

/** \brief Chip ID Register */
typedef union
{
  sys_chip_id_reg_t B;
  REG_ACCESS_U32    U;
} sys_chip_id_reg_u;

/** \brief Chip Configuration Register
 *  \details This register contains read-only information. Some bits are user configurable via
 *           EFUSE. More details can be found in the EFUSE section. Specifically, bits 27..26 and
 *           bits 20..0 are EFUSE configurable.
 */
typedef struct
{
  uint32_t FLASH_CODE_RD   : 16;  ///< Each bit corresponds 16kB of FLASH location, with bit 0
                                  ///< referring to locations 0-16383. When set the data residing in
                                  ///< the said FLASH locations are not considered sensitive and
                                  ///< when copied to the program memory, the user program can
                                  ///< access these as data via LPM/LPMI instructions.
                                  ///< When cleared, the data are considered sensitive; reading them
                                  ///< from the program memory with LPM/LPMI instructions will not
                                  ///< return the correct content.

  uint32_t FLASH_WR_B0_ENA : 1;   ///< If set, FLASH write/erase to bytes 0 – 65535 is allowed;
                                  ///< otherwise, it is permanently non-writable/non-erasable.

  uint32_t FLASH_WR_B1_ENA : 1;   ///< If set, FLASH write/erase to bytes 65536 – 131071 is allowed;
                                  ///< otherwise, it is permanently non-writable/non-erasable.

  uint32_t FLASH_WR_B2_ENA : 1;   ///< If set, FLASH write/erase to bytes 131072 – 196607 is
                                  ///< allowed; otherwise, it is permanently
                                  ///< non-writable/non-erasable.

  uint32_t FLASH_WR_B3_ENA : 1;   ///< If set, FLASH write/erase to bytes 196608 – 262143 is
                                  ///< allowed; otherwise, it is permanently
                                  ///< non-writable/non-erasable.

  uint32_t FLASH_RD_ENA    : 1;   ///< If set, FLASH read via the external SPI interface is allowed;
                                  ///< otherwise, this feature is permanently disabled. Write will
                                  ///< still be available; but see bits 19-16

  uint32_t Reserved_21_25  : 5;   ///< Reserved

  uint32_t EXT_SPI_ACTIVE  : 1;   ///< If set, internal FLASH/EFUSE can be accessed via SPI Slave
                                  ///< interface during reset; otherwise, this interface is
                                  ///< permanently disabled.

  uint32_t ONE_WIRE_ACTIVE : 1;   ///< If set, one-wire debug interface is enabled; otherwise,
                                  ///< it’s permanently disabled.

  uint32_t Reserved_28     : 1;   ///< Reserved

  uint32_t _100_PIN        : 1;   ///< 1 - the device is a 100-pin device; 0 - the device is a
                                  ///< 76-pin (QFN) or 80-pin (LQFP) device.

  uint32_t MAC_ACTIVE      : 1;   ///< Ethernet module available; default value depends on device
                                  ///< model; 1 – available; 0 – not available.

  uint32_t CAN_ACTIVE      : 1;   ///< CAN modules available; the value depends on device model;
                                  ///< 1 – available; 0 – not available.
} sys_efcfg_reg_t;

/** \brief Chip Configuration Register */
typedef union
{
  sys_efcfg_reg_t B;
  REG_ACCESS_U32  U;
} sys_efcfg_reg_u;

/** \brief Clock Configuration Register */
typedef struct
{
  uint32_t CAM_ENA   : 1;   ///< 1: Enable Data Capture Interface
  uint32_t I2S_ENA   : 1;   ///< 1: Enable I2S
  uint32_t PWM_ENA   : 1;   ///< 1: Enable PWM
  uint32_t UART1_ENA : 1;   ///< 1: Enable UART 1
  uint32_t UART0_ENA : 1;   ///< 1: Enable UART 0
  uint32_t SPIS1_ENA : 1;   ///< 1: Enable SPI Slave 1
  uint32_t SPIS0_ENA : 1;   ///< 1: Enable SPI Slave 0
  uint32_t SPIM_ENA  : 1;   ///< 1: Enable SPI Master
  uint32_t I2CS_ENA  : 1;   ///< 1: Enable I2C Slave
  uint32_t I2CM_ENA  : 1;   ///< 1: Enable I2C Master
  uint32_t CAN1_ENA  : 1;   ///< 1: Enable CAN1
  uint32_t CAN0_ENA  : 1;   ///< 1: Enable CAN0
  uint32_t SD_ENA    : 1;   ///< 1: Enable SD Host
  uint32_t MAC_ENA   : 1;   ///< 1: Enable Ethernet
  uint32_t DEV_ENA   : 1;   ///< 1: Enable USB Peripheral
  uint32_t EHCI_ENA  : 1;   ///< 1: Enable USB Host
  uint32_t Reserved  : 16;  ///< Reserved
} sys_clkcfg_reg_t;

/** \brief Clock Configuration Register */
typedef union
{
  sys_clkcfg_reg_t B;
  REG_ACCESS_U32   U;
} sys_clkcfg_reg_u;

/** \brief Power Management Register */
typedef struct
{
#if defined (__FT930__)
  uint32_t Reserved_0           : 1;  ///< Reserved
#else
  uint32_t OC_DETECT_EN         : 1;  ///< 1: Enable Over current detection. Enable interrupt to PM
                                      ///<    IRQ when OC_DETECT is set
#endif

  uint32_t DEV_DETECT_EN        : 1;  ///< 1: Enable device connect/disconnect to external host or
                                      ///<    External host reset detection. Enable interrupt to PM
                                      ///<    IRQ when any of DEV_CONN_DEV, DEV_DIS_DEV and
                                      ///<    HOST_RST_DEV is set.
#if defined (__FT930__)
  uint32_t Reserved_2           : 1;  ///< Reserved
#else
  uint32_t HOST_DETECT_EN       : 1;  ///< 1: Enable device connect/disconnect detection to USB
                                      ///<    Host. Enable interrupt to PM IRQ when either
                                      ///<    DEV_CONN_HOST or DEV_DIS_HOST is set.
#endif

#if defined (__FT930__)
  uint32_t Reserved_3           : 1;  ///< Reserved
#else
  uint32_t RM_WK_HOST_EN        : 1;  ///< 1: Enable remote wake up detection to USB host. Enable
                                      ///<    interrupt to PM IRQ when RM_WK_HOST is set.
#endif

  uint32_t FORCE_DEV_DET        : 1;  ///< Normally USB device activity detection is performed only
                                      ///< when required; setting this bit will force the PM to
                                      ///< check for device connection activities regardless.
#if defined (__FT930__)
  uint32_t Reserved_5           : 1;  ///< Reserved
#else
  uint32_t FORCE_HOST_DET       : 1;  ///< Normally USB host activity detection is performed only
                                      ///< when required; setting this bit will force the PM to
                                      ///< check for host connection activities regardless.
#endif

  uint32_t SLOWCLOCK_5MS_START  : 1;  ///< 1: To start the 1-shot slow clock 5ms timer; once started
                                      ///<    it cannot be stopped. This bit will be cleared
                                      ///<    automatically when the timer expires.

  uint32_t SLOWCLOCK_5MS_IRQ_EN : 1;  ///< 1: Enable slow clock 5ms timer interrupt.

  uint32_t PM_PWRDN             : 1;  ///< 1: Power down system.
                                      ///< This bit should be cleared after the system wakes up or
                                      ///< at least 60-100us prior to setting it 1 again.

  uint32_t PM_PWRDN_MODE        : 1;  ///< 1: Disable system oscillator when powering down
                                      ///< 0: Do not disable system oscillator when powering down

  uint32_t DEV_PHY_EN           : 1;  ///< 1: Enable USB Device PHY

#if defined (__FT930__)
  uint32_t SLAVE_PERI_IRQ_EN    : 1;  ///< Note: Only valid for D2XX mode
                                      ///< SLAVE Wake Up Interrupt Enable; If this bit is set, an
                                      ///< interrupt will be generated on PM IRQ when
                                      ///< SLAVE_PERI_IRQ_PEND becomes active.
#else
  uint32_t Reserved_11          : 1;  ///< Reserved
#endif

  uint32_t RTC_ALARM_IRQ_EN     : 1;  ///< Warning: !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
                                      ///< RTC Alarm Wake Up Interrupt Enable; if this bit is set,
                                      ///< an interrupt will be generated on PM IRQ when
                                      ///< RTC_ALARM_IRQ_PEND becomes active.
#if defined (__FT930__)
  uint32_t Reserved_13          : 1;  ///< Reserved

  uint32_t Reserved_14          : 1;  ///< Reserved

  uint32_t DIS_DISCONN_DET      : 1;  ///< 1: To disable Device Disconnection detection.
                                      ///< 0: To enable Device Disconnection detection.
#else
  uint32_t RTC_VBAT_IRQ_EN        : 1;  ///< Warning: !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
                                        ///< 1: Enables the interrupt for the battery condition that
                                        ///<    was selected via bit 14.

  uint32_t RTC_VBAT_STATUS_DETECT : 1;  ///< Warning: !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
                                        ///< Chooses which RTC battery condition is detected.
                                        ///<     0: Detects if the RTC battery is low.
                                        ///<     1: Detects if a good battery has been replaced.

  uint32_t PSWN                   : 1;  ///< Warning: !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
                                        ///< 0: Set PSWN to 0 (Enables external VBUS)
                                        ///< 1: Set PSWN to 1 (Disables external VBUS)
                                        ///< When OC_DETECT_EN is set and an over current condition
                                        ///< occurs, hardware will automatically set this bit.
                                        ///< This bit cannot be cleared by software as long as the
                                        ///< condition exists.
#endif

#if defined (__FT930__)
  uint32_t Reserved_16          : 1;  ///< Reserved
#else
  uint32_t OC_DETECT            : 1;  ///< Over current detected Interrupt pending if enabled; write
                                      ///< 1 to clear. If enabled, an interrupt will be generated on
                                      ///< PM IRQ.
#endif

  uint32_t HOST_RESUME_DEV      : 1;  ///< Host Resume Interrupt pending to USB Device; write 1 to
                                      ///< clear. If enabled, an interrupt will be generated on PM
                                      ///< IRQ.

  uint32_t HOST_RST_DEV         : 1;  ///< Host Reset Interrupt pending to USB Device; write 1 to
                                      ///< clear. If enabled, an interrupt will be generated on PM
                                      ///< IRQ.

  uint32_t DEV_DIS_DEV          : 1;  ///< Device Disconnect Interrupt pending to USB Device; write
                                      ///< 1 to clear. If enabled, an interrupt will be generated on
                                      ///< PM IRQ.

  uint32_t DEV_CONN_DEV         : 1;  ///< Device Connect Interrupt pending to USB Device; write 1
                                      ///< to clear. If enabled, an interrupt will be generated on
                                      ///< PM IRQ.

#if defined (__FT930__)
  uint32_t Reserved_21_24       : 3;  ///< Reserved
#else
  uint32_t DEV_DIS_HOST         : 1;  ///< Device Disconnect Interrupt pending to USB Host; write 1
                                      ///< to clear. If enabled, an interrupt will be generated on
                                      ///< PM IRQ.

  uint32_t DEV_CONN_HOST        : 1;  ///< Device Connect Interrupt pending to USB Host; write 1 to
                                      ///< clear. If enabled, an interrupt will be generated on PM
                                      ///< IRQ.

  uint32_t RM_WK_HOST           : 1;  ///< Remote Wakeup Interrupt pending to USB Host; write 1 to
                                      ///< clear. If enabled, an interrupt will be generated on PM
                                      ///< IRQ.
#endif

  uint32_t SLOWCLK_5MS_IRQ_PEND : 1;  ///< Slow clock 5ms timer interrupt pending; write 1 to clear.
                                      ///< If enabled, an interrupt will be generated.

  uint32_t PM_GPIO_IRQ_PEND     : 1;  ///< GPIO interrupt during system shut down with clock not
                                      ///< running
#if defined (__FT930__)
  uint32_t SLAVE_PERI_IRQ_PEND  : 1;  ///< Note: Only valid for D2XX mode
                                      ///< SLAVE Wake Up interrupt pending; write 1 to clear. This
                                      ///< bit will be set when there is a wake-up event from the
                                      ///< D2XX Engine
#else
  uint32_t Reserved_26          : 1;  ///< Reserved
#endif

  uint32_t Reserved_27_28       : 2;  ///< Reserved

#if defined (__FT930__)
  uint32_t Reserved_29_30       : 2;  ///< Reserved
#else
  uint32_t RTC_VBAT_REPLACED_PEND : 1;  ///< Warning: !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
                                        ///< RTC good battery replacement detected pending: Write 1
                                        ///< to clear. If RTC_VBAT_IRQ_EN=1, an interrupt will be
                                        ///< generated. Clear this bit before setting
                                        ///< RTC_VBAT_IRQ_EN to '1'.

  uint32_t RTC_VBAT_LOW_PEND    : 1;    ///< Warning: !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
                                        ///< RTC battery low detected pending: Write 1 to clear.
                                        ///< If RTC_VBAT_IRQ_EN=1, an interrupt will be generated.
                                        ///< Clear this bit before setting RTC_VBAT_IRQ_EN to “1”.
#endif
  uint32_t RTC_ALARM_IRQ_PEND   : 1;  ///< Warning: !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
                                      ///< RTC Alarm Wake Up interrupts pending; write 1 to clear.
                                      ///< This bit will be set when the RTC alarm is active while
                                      ///< it is in sleep mode.
} sys_pmcfg_reg_t;

/** \brief Power Management Register */
typedef union
{
  sys_pmcfg_reg_t B;
  REG_ACCESS_U32  U;
} sys_pmcfg_reg_u;

/** \brief Test & Set Register */
typedef struct
{
  uint32_t TEST_SET : 1;  ///< This register is used as a binary semaphore. Upon a read, a 0
                          ///< indicates that the semaphore has been granted to the reader and a 1
                          ///< indicates that it has already been taken.
                          ///< CAUTION: Only the granted thread or process shall write a 1 to return
                          ///< the semaphore.

  uint32_t Reserved : 31; ///< Reserved
} sys_ptstnset_reg_t;

/** \brief Test & Set Register */
typedef union
{
  sys_ptstnset_reg_t B;
  REG_ACCESS_U32     U;
} sys_ptstnset_reg_u;

/** \brief Test & Set Shadow Register */
typedef struct
{
  uint32_t TEST_SET : 1;  ///< This register is used as a binary semaphore. Upon a read, a 0
                          ///< indicates that the semaphore has been granted to the reader and a 1
                          ///< indicates that it has already been taken.
                          ///< CAUTION: Only the granted thread or process shall write a 1 to return
                          ///< the semaphore.

  uint32_t Reserved : 31; ///< Reserved
} sys_ptstnsetr_reg_t;

/** \brief Test & Set Shadow Register */
typedef union
{
  sys_ptstnsetr_reg_t B;
  REG_ACCESS_U32      U;
} sys_ptstnsetr_reg_u;

/** \brief Miscellaneous Configuration Register */
typedef struct
{
  uint32_t BCDDEV_DCP_FOUND__LGC_COMP_INHIB  : 1; ///< Read : 1 - DCP detected
                                                  ///< Write: 1 - Disables logic comparison during
                                                  ///<            BCD detections

  uint32_t BCDDEV_CDP_FOUND__VDP_EN_POST_DCP : 1; ///< Read : 1 - CDP detected
                                                  ///< Write: 1 - Enables connection of VDP_SRC
                                                  ///<            after DCP detection

  uint32_t BCDDEV_SDP_FOUND__SD_EN           : 1; ///< Read : 1 - SDP detected
                                                  ///< Write: 1 - Enables secondary detection

  uint32_t BCDDEV_DETECT_COMPLETE__EN        : 1; ///< Read : 1 - Indicates BCD Device detection is
                                                  ///<            one
                                                  ///< Write: 1 - Enables BCD Device

  uint32_t BCDDEV_DETECT_RUNNING__SOFTRESET  : 1; ///< Read : 1 - Indicates BCD Device detection is
                                                  ///<            running
                                                  ///< Write: 1 - Generate software reset to:
                                                  ///<             - BCD Host if BCDHOST_EN is 1.
                                                  ///<             - BCD Dev if BCDDEV_EN is 1.
                                                  ///<            It is automatically cleared
                                                  ///<            immediately.

  uint32_t BCDHOST_EN           : 1;  ///< 1: Enable BCD Host

  uint32_t BCDHOST_MODE         : 2;  ///< Battery Charging Device (BCD) Host Mode:
                                      ///<     0: Standard Downstream Port (SDP)
                                      ///<     1: Dedicated Charging Port (DCP)
                                      ///<     2: Reserved
                                      ///<     3: Charging Downstream Port (CDP)

  uint32_t MAC_RESET_PHY        : 1;  ///< Write 1 to cause Ethernet PHY reset; it is automatically
                                      ///< cleared immediately.

  uint32_t DEV_RESET_ATX        : 1;  ///< Write 1 to cause USB Dev ATX reset; it is automatically
                                      ///< cleared immediately.

  uint32_t DEV_RESET_CONTROLLER : 1;  ///< Write 1 to cause USB Dev Controller reset; it is
                                      ///< automatically cleared immediately.

  uint32_t DEV_RESET_ALL        : 1;  ///< Write 1 to cause USB Dev Controller and ATX reset; it is
                                      ///< automatically cleared immediately.

  uint32_t DEV_RMWAKEUP         : 1;  ///< 1: Drive K-state on Device USB port; software must
                                      ///<    maintain the 1ms requirement before turning it off.

  uint32_t HOST_RESET_ATX       : 1;  ///< Write 1 to cause USB Host PHY reset; it is automatically
                                      ///< cleared immediately.

  uint32_t HOST_RESET_EHCI      : 1;  ///< Write 1 to cause USB Host EHCI reset; it is automatically
                                      ///< cleared immediately. Software needs to wait for EHCI to
                                      ///< complete its reset (~200ms).

  uint32_t HOST_RESET_ALL       : 1;  ///< Write 1 to cause USB Host EHCI and PHY reset; it is
                                      ///< automatically cleared immediately. Software needs to wait
                                      ///< for EHCI to complete its reset (~200ms).

  uint32_t UART1_INTSEL         : 1;  ///< INT Selection for UART 1. Refer to UART chapter for more
                                      ///< information on this bit.

  uint32_t UART1_FIFOSEL        : 1;  ///< FIFO Selection for UART 1. Refer to UART chapter for more
                                      ///< information on this bit.

  uint32_t UART1_CLKSEL         : 1;  ///< Clock Select for UART 1. Refer to UART chapter for more
                                      ///< information on this bit.

  uint32_t UART0_INTSEL         : 1;  ///< INT Selection for UART 0. Refer to UART chapter for more
                                      ///< information on this bit.

  uint32_t UART0_FIFOSEL        : 1;  ///< FIFO Selection for UART 0. Refer to UART chapter for more
                                      ///< information on this bit.

  uint32_t UART0_CLKSEL         : 1;  ///< Clock Select for UART 0. Refer to UART chapter for more
                                      ///< information on this bit.

  uint32_t CAN1_SLOW            : 1;  ///< 1: Extend further the divider of CAN 1 by a factor of 16.

  uint32_t CAN0_SLOW            : 1;  ///< 1: Extend further the divider of CAN 0 by a factor of 16.

  uint32_t Reserved_24_25       : 2;  ///< Reserved

  uint32_t PWM_TRIG_SEL         : 3;  ///< PWM count external trigger selection (See PWM)
                                      ///< If any of the GPIO is used for this purpose, the pad must
                                      ///< be configured solely for this use.
                                      ///<     0: None
                                      ///<     1: GPIO 18
                                      ///<     2: GPIO 26
                                      ///<     3: GPIO 35
                                      ///<     4: GPIO 40
                                      ///<     5: GPIO 46
                                      ///<     6: GPIO 52
                                      ///<     7: GPIO 58

  uint32_t I2C_SWOP             : 1;  ///< 0: I2C master function is available at GPIO44 and GPIO45
                                      ///<    and I2C slave function is available at GPIO46 and
                                      ///<    GPIO47
                                      ///< 1: swap the I2C master and I2C slave GPIO positions

  uint32_t PWM_SOFTRESET        : 1;  ///< Write 1 to cause soft reset to PWM. It is automatically
                                      ///< cleared.

  uint32_t PERI_SOFTRESET       : 1;  ///< Write 1 to cause soft reset to all peripherals. It is
                                      ///< automatically cleared.
} sys_msc0cfg_reg_t;

/** \brief Miscellaneous Configuration Register */
typedef union
{
  sys_msc0cfg_reg_t B;
  REG_ACCESS_U32    U;
} sys_msc0cfg_reg_u;

/** \brief Register mappings for System level registers */
typedef struct
{
  __IO sys_chip_id_reg_u   CHIP_ID;
  __IO sys_efcfg_reg_u     EFCFG;
  __IO sys_clkcfg_reg_u    CLKCFG;
  __IO sys_pmcfg_reg_u     PMCFG;
  __IO sys_ptstnset_reg_u  PTSTNSET;
  __IO sys_ptstnsetr_reg_u PTSTNSETR;
  __IO sys_msc0cfg_reg_u   MSC0CFG;
} sys_regs_t;

/** @brief Register mappings for System level registers */
typedef struct
{
  __IO uint32_t CHIPID;
  __IO uint32_t EFCFG;
  __IO uint32_t CLKCFG;
  __IO uint16_t PMCFG_L;
  __IO uint16_t PMCFG_H;
  __IO uint32_t PTSTNSET;
  __IO uint32_t PTSTNSETR;
  __IO uint32_t MSC0CFG;
} ft900_sys_regs_t;

/** \brief Global Reset/Status Register
 *  \warning !!!AVAILABLE FROM FT900 REV C ONWARDS!!!
 */
typedef struct
{
  __IO uint32_t HW_RESET   : 1;   ///< External Hardware Reset
                                  ///< If it is set, it indicates the external hardware reset has
                                  ///< been performed. Write “1” to clear it.

  __IO uint32_t SOFT_RESET : 1;   ///< Soft Global Reset
                                  ///< Write “1” to reset the system to POR state.
                                  ///< Write “0” to clear this bit. This bit must be cleared before
                                  ///< it can be enabled again.
                                  ///< When "1" is read from this bit, it indicates the soft global
                                  ///< reset has been performed from the previous operation.

#if defined(__FT930__)
       uint32_t WDG_RESET  : 1;   ///< Watchdog Second Level Reset; if this bit is set it indicates
                                  ///< the second level watchdog reset has occurred in the previous
                                  ///< operation.
                                  ///< Write “1” to clear this bit. Please note this bit
                                  ///< must be cleared to enable this function again.

       uint32_t Reserved   : 29;  ///< Reserved
#else
       uint32_t Reserved   : 30;  ///< Reserved
#endif
} sys_reset_regs_t;

/** \brief Global Reset/Status Register */
typedef struct
{
  __IO uint8_t RESET_STATUS;
  __IO uint8_t RESERVED1;
  __IO uint8_t RESERVED2;
  __IO uint8_t RESERVED3;
} ft900_sys_reset_regs_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#endif /* FT900_SYS_REGISTERS_H_ */
