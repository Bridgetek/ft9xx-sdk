/**
    @file ft900_registers.h

    @brief FT900 registers map

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

#ifndef FT900_REGISTERS_H_
#define FT900_REGISTERS_H_

/* INCLUDES ************************************************************************/
#if defined(__FT930__)

#include <registers/ft930_epfifo_registers.h>
#include <registers/ft930_ipc_registers.h>
#include <registers/ft930_slave_cpu_registers.h>
#include <registers/ft900_adc_dac_registers.h>
#include <registers/ft900_gpio_registers.h>
#include <registers/ft900_i2c_registers.h>
#include <registers/ft900_interrupt_registers.h>
#include <registers/ft900_pwm_registers.h>
#include <registers/ft900_rtc_registers.h>
#include <registers/ft900_sdhost_registers.h>
#include <registers/ft900_spi_registers.h>
#include <registers/ft900_sys_registers.h>
#include <registers/ft900_timer_wdt_registers.h>
#include <registers/ft900_uart_registers.h>
#include <registers/ft900_flash_registers.h>
#include <registers/ft900_usbd_registers.h>

#else

#include <registers/ft900_can_registers.h>
#include <registers/ft900_cam_registers.h>
#include <registers/ft900_sdhost_registers.h>
#include <registers/ft900_spi_registers.h>
#include <registers/ft900_sys_registers.h>
#include <registers/ft900_gpio_registers.h>
#include <registers/ft900_rtc_registers.h>
#include <registers/ft900_timer_wdt_registers.h>
#include <registers/ft900_pwm_registers.h>
#include <registers/ft900_interrupt_registers.h>
#include <registers/ft900_adc_dac_registers.h>
#include <registers/ft900_i2c_registers.h>
#include <registers/ft900_i2s_registers.h>
#include <registers/ft900_uart_registers.h>
#include <registers/ft900_usbd_registers.h>
#include <registers/ft900_ehci_registers.h>
#include <registers/ft900_eth_registers.h>
#include <registers/ft900_flash_registers.h>
#include <registers/ft900_usbd_hbw_registers.h>
#endif

/* CONSTANTS ***********************************************************************/

/* TYPES ***************************************************************************/

/* GLOBAL VARIABLES ****************************************************************/

#define REGISTER_BASE_ADDR (0x10000U)

#if defined(__FT930__)

#define SYS            ((ft900_sys_regs_t *)            (REGISTER_BASE_ADDR + 0x0000))
#define SYS_N          ((sys_regs_t *)                  (REGISTER_BASE_ADDR + 0x0000))

#define GPIO           ((ft900_gpio_regs_t *)           (REGISTER_BASE_ADDR + 0x001C))
#define SLAVECPU       ((ft930_slave_control_regs_t *)  (REGISTER_BASE_ADDR + 0x00A8))

#define ADCDAC         ((ft900_adc_dac_regs_t *)        (REGISTER_BASE_ADDR + 0x00B0))
#define ADCDAC_N       ((adc_dac_regs_t *)              (REGISTER_BASE_ADDR + 0x00B0))

#define SYS_RST        ((ft900_sys_reset_regs_t *)      (REGISTER_BASE_ADDR + 0x00BC))
#define SYS_RST_N      ((sys_reset_regs_t *)            (REGISTER_BASE_ADDR + 0x00BC))

#define INTERRUPT      ((ft900_interrupt_regs_t *)      (REGISTER_BASE_ADDR + 0x0100))
#define INTERRUPT_N    ((interrupt_regs_t *)            (REGISTER_BASE_ADDR + 0x0100))

#define USBD           ((ft900_usbd_regs_t *)           (REGISTER_BASE_ADDR + 0x0200))
#define USBD_N         ((usbd_regs_t *)                 (REGISTER_BASE_ADDR + 0x0200))

#define RTC            ((ft900_rtc_regs_t *)            (REGISTER_BASE_ADDR + 0x0400))
#define RTC_N          ((rtc_regs_t *)                  (REGISTER_BASE_ADDR + 0x0400))

#define SPIM           ((ft900_spi_regs_t *)            (REGISTER_BASE_ADDR + 0x0440))
#define SPIM_N         ((spim_regs_t *)                 (REGISTER_BASE_ADDR + 0x0440))
#define SPIS0          ((ft900_spi_regs_t *)            (REGISTER_BASE_ADDR + 0x0480))
#define SPIS0_N        ((spis_regs_t *)                 (REGISTER_BASE_ADDR + 0x0480))
#define SPIS1          ((ft900_spi_regs_t *)            (REGISTER_BASE_ADDR + 0x04C0))
#define SPIS1_N        ((spis_regs_t *)                 (REGISTER_BASE_ADDR + 0x04C0))

#define I2CM           ((ft900_i2cm_regs_t *)           (REGISTER_BASE_ADDR + 0x0500))
#define I2CM_N         ((i2cm_regs_t *)                 (REGISTER_BASE_ADDR + 0x0500))
#define I2CS           ((ft900_i2cs_regs_t *)           (REGISTER_BASE_ADDR + 0x0510))
#define I2CS_N         ((i2cs_regs_t *)                 (REGISTER_BASE_ADDR + 0x0510))

#define UART0          ((ft900_uart_regs_t *)           (REGISTER_BASE_ADDR + 0x0520))
#define UART1          ((ft900_uart_regs_t *)           (REGISTER_BASE_ADDR + 0x0530))
#define UART2          ((ft900_uart_regs_t *)           (REGISTER_BASE_ADDR + 0x0540))
#define UART3          ((ft900_uart_regs_t *)           (REGISTER_BASE_ADDR + 0x0550))

#define TIMER          ((ft900_timer_wdt_regs_t *)      (REGISTER_BASE_ADDR + 0x0560))
#define TIMER_N        ((timer_wdt_regs_t *)            (REGISTER_BASE_ADDR + 0x0560))

#define PWM            ((ft900_pwm_regs_t *)            (REGISTER_BASE_ADDR + 0x05B0))
#define PWM_N          ((pwm_regs_t *)                  (REGISTER_BASE_ADDR + 0x05B0))

#define SDHOST         ((ft900_sdhost_regs_t *)         (REGISTER_BASE_ADDR + 0x0600))
#define SDHOST_N       ((sdh_regs_t *)                  (REGISTER_BASE_ADDR + 0x0600))
#define SDHOSTVENDOR   ((ft900_sdhost_vendor_regs_t *)  (REGISTER_BASE_ADDR + 0x0700))
#define SDHOSTVENDOR_N ((sdh_vendor_regs_t *)           (REGISTER_BASE_ADDR + 0x0700))

#define FLASHCTRL      ((ft900_flash_regs_t *)          (REGISTER_BASE_ADDR + 0x0800))

#else

#define SYS            ((ft900_sys_regs_t *)            (REGISTER_BASE_ADDR + 0x0000))
#define SYS_N          ((sys_regs_t *)                  (REGISTER_BASE_ADDR + 0x0000))

#define GPIO           ((ft900_gpio_regs_t *)           (REGISTER_BASE_ADDR + 0x001C))

#define ETHPHY         ((ft900_eth_phy_conf_reg_t *)    (REGISTER_BASE_ADDR + 0x00A8))
#define ETHPHY_N       ((eth_phy_conf_reg_t *)          (REGISTER_BASE_ADDR + 0x00A8))

#define ADCDAC         ((ft900_adc_dac_regs_t *)        (REGISTER_BASE_ADDR + 0x00B0))
#define ADCDAC_N       ((adc_dac_regs_t *)              (REGISTER_BASE_ADDR + 0x00B0))

#define SYS_RST        ((ft900_sys_reset_regs_t *)      (REGISTER_BASE_ADDR + 0x00BC)) /* for FT900 Rev C onwards */
#define SYS_RST_N      ((sys_reset_regs_t *)            (REGISTER_BASE_ADDR + 0x00BC)) /* for FT900 Rev C onwards */

#define INTERRUPT      ((ft900_interrupt_regs_t *)      (REGISTER_BASE_ADDR + 0x00C0))
#define INTERRUPT_N    ((interrupt_regs_t *)            (REGISTER_BASE_ADDR + 0x00C0))

#define EHCI           ((ft900_ehci_regs_t *)           (REGISTER_BASE_ADDR + 0x0100))
#define EHCI_N         ((ehci_regs_t *)                 (REGISTER_BASE_ADDR + 0x0100))

#define USBD           ((ft900_usbd_regs_t *)           (REGISTER_BASE_ADDR + 0x0180))
#define USBD_N         ((usbd_regs_t *)                 (REGISTER_BASE_ADDR + 0x0180))

#define USBD_HBW       ((ft900_usbd_hbw_ctrl_regs_t *)  (REGISTER_BASE_ADDR + 0x0A1C)) /* for FT900 Rev C onwards */
#define USBD_HBW_N     ((usbd_hbw_ctrl_regs_t *)        (REGISTER_BASE_ADDR + 0x0A1C)) /* for FT900 Rev C onwards */

#define ETH            ((ft900_eth_regs_t *)            (REGISTER_BASE_ADDR + 0x0220))
#define ETH_N          ((eth_regs_t *)                  (REGISTER_BASE_ADDR + 0x0220))

#define CAN0           ((ft900_can_regs_t *)            (REGISTER_BASE_ADDR + 0x0240))
#define CAN0_N         ((can_regs_t *)                  (REGISTER_BASE_ADDR + 0x0240))
#define CAN1           ((ft900_can_regs_t *)            (REGISTER_BASE_ADDR + 0x0260))
#define CAN1_N         ((can_regs_t *)                  (REGISTER_BASE_ADDR + 0x0260))

#define RTCL           ((ft900_rtc_legacy_regs_t *)     (REGISTER_BASE_ADDR + 0x0280)) /* for FT900 Rev B */
#define RTCL_N         ((rtc_legacy_regs_t *)           (REGISTER_BASE_ADDR + 0x0280)) /* for FT900 Rev B */
#define RTC            ((ft900_rtc_regs_t *)            (REGISTER_BASE_ADDR + 0x0900)) /* for FT900 Rev C onwards */
#define RTC_N          ((rtc_regs_t *)                  (REGISTER_BASE_ADDR + 0x0900)) /* for FT900 Rev C onwards */

#define SPIM           ((ft900_spi_regs_t *)            (REGISTER_BASE_ADDR + 0x02A0)) /* for FT900 Rev B */
#define SPIM_N         ((spim_origin_regs_t *)          (REGISTER_BASE_ADDR + 0x02A0)) /* for FT900 Rev B */
#define SPIM_EX        ((ft900_spi_regs_ex_t *)         (REGISTER_BASE_ADDR + 0x02A0)) /* for FT900 Rev C onwards */
#define SPIM_EX_N      ((spim_regs_ex_t *)              (REGISTER_BASE_ADDR + 0x02A0)) /* for FT900 Rev C onwards */
#define SPIS0          ((ft900_spi_regs_t *)            (REGISTER_BASE_ADDR + 0x02C0)) /* for FT900 Rev B */
#define SPIS0_N        ((spis_origin_regs_t *)          (REGISTER_BASE_ADDR + 0x02C0)) /* for FT900 Rev B */
#define SPIS0_EX       ((ft900_spi_regs_ex_t *)         (REGISTER_BASE_ADDR + 0x02C0)) /* for FT900 Rev C onwards */
#define SPIS0_EX_N     ((spis_extend_regs_t *)          (REGISTER_BASE_ADDR + 0x02C0)) /* for FT900 Rev C onwards */
#define SPIS1          ((ft900_spi_regs_t *)            (REGISTER_BASE_ADDR + 0x02E0)) /* for FT900 Rev B */
#define SPIS1_N        ((spis_origin_regs_t *)          (REGISTER_BASE_ADDR + 0x02E0)) /* for FT900 Rev B */
#define SPIS1_EX       ((ft900_spi_regs_ex_t *)         (REGISTER_BASE_ADDR + 0x02E0)) /* for FT900 Rev C onwards */
#define SPIS1_EX_N     ((spis_extend_regs_t *)          (REGISTER_BASE_ADDR + 0x02E0)) /* for FT900 Rev C onwards */

#define I2CM           ((ft900_i2cm_regs_t *)           (REGISTER_BASE_ADDR + 0x0300))
#define I2CM_N         ((i2cm_regs_t *)                 (REGISTER_BASE_ADDR + 0x0300))
#define I2CS           ((ft900_i2cs_regs_t *)           (REGISTER_BASE_ADDR + 0x0310))
#define I2CS_N         ((i2cs_regs_t *)                 (REGISTER_BASE_ADDR + 0x0310))

#define UART0          ((ft900_uart_regs_t *)           (REGISTER_BASE_ADDR + 0x0320))
#define UART1          ((ft900_uart_regs_t *)           (REGISTER_BASE_ADDR + 0x0330))

#define TIMER          ((ft900_timer_wdt_regs_t *)      (REGISTER_BASE_ADDR + 0x0340))
#define TIMER_N        ((timer_wdt_regs_t *)            (REGISTER_BASE_ADDR + 0x0340))

#define I2S            ((ft900_i2s_regs_t *)            (REGISTER_BASE_ADDR + 0x0350))
#define I2S_N          ((i2s_regs_t *)                  (REGISTER_BASE_ADDR + 0x0350))

#define CAM            ((ft900_cam_regs_t *)            (REGISTER_BASE_ADDR + 0x0360))
#define CAM_N          ((cam_regs_t *)                  (REGISTER_BASE_ADDR + 0x0360))

#define PWM            ((ft900_pwm_regs_t *)            (REGISTER_BASE_ADDR + 0x03C0))
#define PWM_N          ((pwm_regs_t *)                  (REGISTER_BASE_ADDR + 0x03C0))

#define SDHOST         ((ft900_sdhost_regs_t *)         (REGISTER_BASE_ADDR + 0x0400))
#define SDHOST_N       ((sdh_regs_t *)                  (REGISTER_BASE_ADDR + 0x0400))
#define SDHOSTVENDOR   ((ft900_sdhost_vendor_regs_t *)  (REGISTER_BASE_ADDR + 0x0500))
#define SDHOSTVENDOR_N ((sdh_vendor_regs_t *)           (REGISTER_BASE_ADDR + 0x0500))

#define FLASHCTRL      ((ft900_flash_regs_t *)          (REGISTER_BASE_ADDR + 0x0800))
#define FLASHCTRL_N    ((flash_regs_t *)                (REGISTER_BASE_ADDR + 0x0800))

#define EHCI_RAM       ((ft900_ehci_ram_t *)            (REGISTER_BASE_ADDR + 0x1000))
#define EHCI_RAM_SIZE                                   (0x2000)

#endif

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/


#endif /* FT900_REGISTERS_H_ */
