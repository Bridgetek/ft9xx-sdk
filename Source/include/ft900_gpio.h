/**
    @file ft900_gpio.h

    @brief
    General Purpose I/O and Pad control
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


#ifndef FT900_GPIO_H_
#define FT900_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* INCLUDES ************************************************************************/
#include <stdint.h>
#include <stddef.h>

/**
 * Pin function map for FT90x
    | Pin                               | pad_func_0 | pad_func_1 | pad_func_2 | pad_func_3 |
    | --------------------------------- | ---------- | ---------- | ---------- | ---------- |
    | VBUS_DISCH/GPIO0                  | GPIO0      |            |            |            |
    | OC_N/GPIO1                        | GPIO1      | OC_N       |            |            |
    | PSW_N/GPIO2                       | GPIO2      |            |            |            |
    | VBUS_DTC/GPIO3                    | GPIO3      | VBUS_DTC   |            |            |
    | ENET_LED0/GPIO4                   | GPIO4      | ENET_LED0  |            |            |
    | ENET_LED1/GPIO5                   | GPIO5      | ENET_LED1  |            |            |
    | ADC1/CAM_XCLK/GPIO6               | GPIO6      | CAM_XCLK   |            | ADC1       |
    | ADC2/CAM_PCLK/GPIO7               | GPIO7      | CAM_PCLK   |            | ADC2       |
    | ADC3/CAM_VD/GPIO8                 | GPIO8      | CAM_VD     |            | ADC3       |
    | ADC4/CAM_HD/GPIO9                 | GPIO9      | CAM_HD     |            | ADC4       |
    | ADC5/CAM_D7/GPIO10                | GPIO10     | CAM_D7     |            | ADC5       |
    | ADC6/CAM_D6/GPIO11                | GPIO11     | CAM_D6     |            | ADC6       |
    | ADC7/CAM_D5/GPIO12                | GPIO12     | CAM_D5     |            | ADC7       |
    | DAC1/CAM_D4/GPIO13                | GPIO13     | CAM_D4     |            | DAC1       |
    | DAC0/CAM_D3/GPIO14                | GPIO14     | CAM_D3     |            | DAC0       |
    | CAN0_TXD/CAM_D2/GPIO15            | GPIO15     | CAM_D2     | CAN0_TXD   |            |
    | CAN0_RXD/CAM_D1/GPIO16            | GPIO16     | CAM_D1     | CAN0_RXD   |            |
    | CAN1_TXD/CAM_D0/GPIO17            | GPIO17     | CAM_D0     | CAN1_TXD   |            |
    | CAN1_RXD/GPIO18                   | GPIO18     |            | CAN1_RXD   |            |
    | SD_CLK/GPIO19                     | GPIO19     | SD_CLK     |            |            |
    | SD_CMD/GPIO20                     | GPIO20     | SD_CMD     |            |            |
    | SD_DATA3/GPIO21                   | GPIO21     | SD_DATA3   |            |            |
    | SD_DATA2/GPIO22                   | GPIO22     | SD_DATA2   |            |            |
    | SD_DATA1/GPIO23                   | GPIO23     | SD_DATA1   |            |            |
    | SD_DATA0/GPIO24                   | GPIO24     | SD_DATA0   |            |            |
    | SD_CD/GPIO25                      | GPIO25     | SD_CD      |            |            |
    | SD_WP/GPIO26                      | GPIO26     | SD_WP      |            |            |
    | SPIM_CLK/GPIO27                   | GPIO27     | SPIM_CLK   |            |            |
    | SPIM_SS0/GPIO28                   | GPIO28     | SPIM_SS0   |            |            |
    | SPIM_MOSI/GPIO29                  | GPIO29     | SPIM_MOSI  |            |            |
    | SPIM_MISO/GPIO30                  | GPIO30     | SPIM_MISO  |            |            |
    | SPIM_IO2/GPIO31                   | GPIO31     | SPIM_IO2   |            |            |
    | SPIM_IO3/GPIO32                   | GPIO32     | SPIM_IO3   |            |            |
    | SPIM_SS1/GPIO33                   | GPIO33     | SPIM_SS1   |            |            |
    | SPIM_SS2/GPIO34                   | GPIO34     | SPIM_SS2   |            |            |
    | SPIM_SS3/GPIO35                   | GPIO35     | SPIM_SS3   |            |            |
    | SPIS0_CLK/GPIO36                  | GPIO36     | SPIS0_CLK  |            |            |
    | SPIS0_SS/GPIO37                   | GPIO37     | SPIS0_SS   |            |            |
    | SPIS0_MOSI/GPIO38                 | GPIO38     | SPIS0_MOSI |            |            |
    | SPIS0_MISO/GPIO39                 | GPIO39     | SPIS0_MISO |            |            |
    | SPIS1_CLK/GPIO40                  | GPIO40     | SPIS1_CLK  |            |            |
    | SPIS1_SS/GPIO41                   | GPIO41     | SPIS1_SS   |            |            |
    | SPIS1_MOSI/GPIO42                 | GPIO42     | SPIS1_MOSI |            |            |
    | SPIS1_MISO/GPIO43                 | GPIO43     | SPIS1_MISO |            |            |
    | I2C0_SCL/GPIO44                   | GPIO44     | I2C0_SCL   |            |            |
    | I2C0_SDA/GPIO45                   | GPIO45     | I2C0_SDA   |            |            |
    | I2C1_SCL/GPIO46                   | GPIO46     | I2C1_SCL   |            |            |
    | I2C1_SDA/GPIO47                   | GPIO47     | I2C1_SDA   |            |            |
    | UART0_TXD/GPIO48                  | GPIO48     |            |            | UART0_TXD  |
    | UART0_RXD/GPIO49                  | GPIO49     |            |            | UART0_RXD  |
    | UART0_RTS/GPIO50                  | GPIO50     |            |            | UART0_RTS  |
    | UART0_CTS/GPIO51                  | GPIO51     |            |            | UART0_CTS  |
    | UART0_DTR/UART1_TXD/PWM4/GPIO52   | GPIO52     | PWM4       | UART1_TXD  | UART0_DTR  |
    | UART0_DSR/UART1_RXD/PWM5/GPIO53   | GPIO53     | PWM5       | UART1_RXD  | UART0_DSR  |
    | UART0_DCD/UART1_RTS/PWM6/GPIO54   | GPIO54     | PWM6       | UART1_RTS  | UART0_DCD  |
    | UART0_RI/UART1_CTS/PWM7/GPIO55    | GPIO55     | PWM7       | UART1_CTS  | UART0_RI   |
    | PWM0/GPIO56                       | GPIO56     | PWM0       |            |            |
    | PWM1/GPIO57                       | GPIO57     | PWM1       |            |            |
    | PWM2/GPIO58                       | GPIO58     | PWM2       |            |            |
    | PWM3/GPIO59                       | GPIO59     | PWM3       |            |            |
    | I2S_SDAO/GPIO60                   | GPIO60     | I2S_SDAO   |            |            |
    | I2S_SDAI/GPIO61                   | GPIO61     | I2S_SDAI   |            |            |
    | I2S_BCLK/GPIO62                   | GPIO62     | I2S_BCLK   | I2SS_BCLK  |            |
    | I2S_LRCLK/GPIO63                  | GPIO63     | I2S_LRCLK  | I2SS_LRCLK |            |
    | I2S_MCLK/GPIO64                   | GPIO64     | I2S_MCLK   |            |            |
    | I2S_CLK22/GPIO65                  | GPIO65     | I2S_CLK22  |            |            |
    | I2S_CLK24/GPIO66                  | GPIO66     | I2S_CLK24  |            |            |

 * Pin function map for FT93x
    | Pin                               | pad_func_0 | pad_func_1 | pad_func_2 | pad_func_3 |
    | --------------------------------- | ---------- | ---------- | ---------- | ---------- |
    | SD_CLK/SPIS_CLK/GPIO0             | GPIO0      | SPIS0_CLK  | SD_CLK     |            |
    | SD_CMD/SPIS_MISO/GPIO1            | GPIO1      | SPIS0_MISO | SD_CMD     |            |
    | SD_CD/SPIS_MOSI/GPIO2             | GPIO2      | SPIS0_MOSI | SD_CD      |            |
    | SD_DATA0/SPIS_SS/GPIO3            | GPIO3      | SPIS0_SS   | SD_DATA0   |            |
    | PWM0/SD_DATA1/PWM7/GPIO4          | GPIO4      | PWM7       | SD_DATA1   | PWM0       |
    | PWM6/SD_DATA2/PWM1/GPIO5          | GPIO5      | PWM6       | SD_DATA2   | PWM1       |
    | SD_DATA3/PWM5/GPIO6               | GPIO6      | PWM5       | SD_DATA3   |            |
    | SD_WP/PWM4/GPIO7                  | GPIO7      | PWM4       | SD_WP      |            |
    | PWM3/GPIO8                        | GPIO8      | PWM3       |            |            |
    | PWM2/GPIO9                        | GPIO9      | PWM2       |            |            |
    | PWM1/GPIO10                       | GPIO10     | PWM0       |            |            |
    | PWM0/GPIO11                       | GPIO11     | PWM1       |            |            |
    | I2CS_SCL/I2CM_SCL/GPIO12          | GPIO12     | I2C0_SCL   | I2CS_SCL   |            |
    | I2CS_SDA/I2CM_SDA/GPIO13          | GPIO13     | I2C0_SDA   | I2CS_SDA   |            |
    | UART2_RXD/GPIO14                  | GPIO14     | UART2_RXD  |            |            |
    | UART2_TXD/GPIO15                  | GPIO15     | UART2_TXD  |            |            |
    | UART2_RTS/GPIO16                  | GPIO16     | UART2_RTS  |            |            |
    | UART2_CTS/GPIO17                  | GPIO17     | UART2_CTS  |            |            |
    | UART3_RXD/UART2_DTR/GPIO18        | GPIO18     | UART2_DTR  | UART3_RXD  |            |
    | UART3_TXD/UART2_DSR/GPIO19        | GPIO19     | UART2_DSR  | UART3_TXD  |            |
    | UART3_RTS/UART2_DCD/GPIO20        | GPIO20     | UART2_DCD  | UART3_RTS  |            |
    | UART3_CTS/UART2_RI/GPIO21         | GPIO21     | UART2_RI   | UART3_CTS  |            |
    | PWM3/UART0_RXD/GPIO22             | GPIO22     | UART0_RXD  | PWM3       |            |
    | PWM2/UART0_TXD/GPIO23             | GPIO23     | UART0_TXD  | PWM2       |            |
    | PWM1/UART0_RTS/GPIO24             | GPIO24     | UART0_RTS  | PWM1       |            |
    | PWM0/UART0_CTS/GPIO25             | GPIO25     | UART0_CTS  | PWM0       |            |
    | UART1_RXD/UART0_DTR/GPIO26        | GPIO26     | UART0_DTR  | UART1_TXD  |            |
    | UART1_TXD/UART0_DSR/GPIO27        | GPIO27     | UART0_DSR  | UART1_RXD  |            |
    | UART1_RTS/UART0_DCD/GPIO28        | GPIO28     | UART0_DCD  | UART1_RTS  |            |
    | SPIM_SS0/UART1_CTS/UART0_RI/GPIO29| GPIO29     | UART0_RI   | UART1_CTS  | SPIM_SS0   |
    | SPIM_SS0/GPIO30                   | GPIO30     | SPIM_SS0   |            |            |
    | SPIM_SS1/GPIO31                   | GPIO31     | SPIM_SS1   |            |            |
    | SPIM_SS2/GPIO32                   | GPIO32     | SPIM_SS2   |            |            |
    | SPIM_SS3/GPIO33                   | GPIO33     | SPIM_SS3   |            |            |
    | SPIS_CLK/SPIM_CLK/GPIO34          | GPIO34     | SPIM_CLK   | SPIS0_CLK  |            |
    | SPIS_MISO/SPIM_MISO/GPIO35        | GPIO35     | SPIM_MISO  | SPIS0_MISO |            |
    | SPIS_MOSI/SPIM_MOSI/GPIO36        | GPIO36     | SPIM_MOSI  | SPIS0_MOSI |            |
    | SPIS_SS/SPIM_IO2/GPIO37           | GPIO37     | SPIM_IO2   | SPIS0_SS   |            |
    | RTC_REF/SPIM_IO3/GPIO38           | GPIO38     | SPIM_IO3   | RTC_REF    |            |
    | VBUS_DTC/GPIO39                   | GPIO39     | VBUS_DTC   |            |            |
*/

/* CONSTANTS ***********************************************************************/

/* TYPES ***************************************************************************/
/** @brief Pad slew rate control. */
typedef enum
{
    pad_slew_fast,  /**< Fast Slew Rate */
    pad_slew_slow   /**< Slow Slew Rate */
} pad_slew_t;

/** @brief Pad Schmitt trigger control. */
typedef enum
{
    pad_schmitt_off,    /**< Pad input is filtered through a schmitt trigger */
    pad_schmitt_on      /**< Pad input is unfiltered */
} pad_schmitt_t;

/** @brief Pad pull up and pull downs control. */
typedef enum
{
    pad_pull_none,      /**< No pull up or pull down */
    pad_pull_pullup,    /**< Weak pull up enabled */
    pad_pull_pulldown,  /**< Weak pull down enabled */
    pad_pull_keeper     /**< Weak pull up/down reflects output */
} pad_pull_t;

/** @brief Pad current drive control. */
typedef enum
{
    pad_drive_4mA,  /**< 4mA maximum current */
    pad_drive_8mA,  /**< 8mA maximum current */
    pad_drive_12mA, /**< 12mA maximum current */
    pad_drive_16mA  /**< 16mA maximum current */
} pad_drive_t;

/** @brief Pad function control. */

#if defined(__FT930__)

typedef enum
{
    pad_func_0      = 0, /**< Pad function 0 */
    pad_func_1      = 1, /**< Pad function 1 */
    pad_func_2      = 2, /**< Pad function 2 */
    pad_func_3      = 3, /**< Pad function 3 */

    pad_gpio0       = pad_func_0, /**< SD_CLK/SPIS_CLK/GPIO0 Pad function 0 */
    pad_gpio1       = pad_func_0, /**< SD_CMD/SPIS_MISO/GPIO1 Pad function 0 */
    pad_gpio2       = pad_func_0, /**< SD_CD/SPIS_MOSI/GPIO2 Pad function 0 */
    pad_gpio3       = pad_func_0, /**< SD_DATA0/SPIS_SS/GPIO3 Pad function 0 */
    pad_gpio4       = pad_func_0, /**< PWM0/SD_DATA1/PWM7/GPIO4 Pad function 0 */
    pad_gpio5       = pad_func_0, /**< PWM6/SD_DATA2/PWM1/GPIO5 Pad function 0 */
    pad_gpio6       = pad_func_0, /**< SD_DATA3/PWM5/GPIO6 Pad function 0 */
    pad_gpio7       = pad_func_0, /**< SD_WP/PWM4/GPIO7 Pad function 0 */
    pad_gpio8       = pad_func_0, /**< PWM3/GPIO8 Pad function 0 */
    pad_gpio9       = pad_func_0, /**< PWM2/GPIO9 Pad function 0 */
    pad_gpio10      = pad_func_0, /**< PWM1/GPIO10 Pad function 0 */
    pad_gpio11      = pad_func_0, /**< PWM0/GPIO11 Pad function 0 */
    pad_gpio12      = pad_func_0, /**< I2CS_SCL/I2CM_SCL/GPIO12 Pad function 0 */
    pad_gpio13      = pad_func_0, /**< I2CS_SDA/I2CM_SDA/GPIO13 Pad function 0 */
    pad_gpio14      = pad_func_0, /**< UART2_RXD/GPIO14 Pad function 0 */
    pad_gpio15      = pad_func_0, /**< UART2_TXD/GPIO15 Pad function 0 */
    pad_gpio16      = pad_func_0, /**< UART2_RTS/GPIO16 Pad function 0 */
    pad_gpio17      = pad_func_0, /**< UART2_CTS/GPIO17 Pad function 0 */
    pad_gpio18      = pad_func_0, /**< UART3_RXD/UART2_DTR/GPIO18 Pad function 0 */
    pad_gpio19      = pad_func_0, /**< UART3_TXD/UART2_DSR/GPIO19 Pad function 0 */
    pad_gpio20      = pad_func_0, /**< UART3_RTS/UART2_DCD/GPIO20 Pad function 0 */
    pad_gpio21      = pad_func_0, /**< UART3_CTS/UART2_RI/GPIO21 Pad function 0 */
    pad_gpio22      = pad_func_0, /**< PWM3/UART0_RXD/GPIO22 Pad function 0 */
    pad_gpio23      = pad_func_0, /**< PWM2/UART0_TXD/GPIO23 Pad function 0 */
    pad_gpio24      = pad_func_0, /**< PWM1/UART0_RTS/GPIO24 Pad function 0 */
    pad_gpio25      = pad_func_0, /**< PWM0/UART0_CTS/GPIO25 Pad function 0 */
    pad_gpio26      = pad_func_0, /**< UART1_RXD/UART0_DTR/GPIO26 Pad function 0 */
    pad_gpio27      = pad_func_0, /**< UART1_TXD/UART0_DSR/GPIO27 Pad function 0 */
    pad_gpio28      = pad_func_0, /**< UART1_RTS/UART0_DCD/GPIO28 Pad function 0 */
    pad_gpio29      = pad_func_0, /**< SPIM_SS0/UART1_CTS/UART0_RI/GPIO29 Pad function 0 */
    pad_gpio30      = pad_func_0, /**< SPIM_SS0/GPIO30 Pad function 0 */
    pad_gpio31      = pad_func_0, /**< SPIM_SS1/GPIO31 Pad function 0 */
    pad_gpio32      = pad_func_0, /**< SPIM_SS2/GPIO32 Pad function 0 */
    pad_gpio33      = pad_func_0, /**< SPIM_SS3/GPIO33 Pad function 0 */
    pad_gpio34      = pad_func_0, /**< SPIS_CLK/SPIM_CLK/GPIO34 Pad function 0 */
    pad_gpio35      = pad_func_0, /**< SPIS_MISO/SPIM_MISO/GPIO35 Pad function 0 */
    pad_gpio36      = pad_func_0, /**< SPIS_MOSI/SPIM_MOSI/GPIO36 Pad function 0 */
    pad_gpio37      = pad_func_0, /**< SPIS_SS/SPIM_IO2/GPIO37 Pad function 0 */
    pad_gpio38      = pad_func_0, /**< RTC_REF/SPIM_IO3/GPIO38 Pad function 0 */
    pad_gpio39      = pad_func_0, /**< VBUS_DTC/GPIO39 Pad function 0 */

    pad_spis0_clk_0 = pad_func_1, /**< SD_CLK/SPIS_CLK/GPIO0 Pad function 1 */
    pad_spis0_miso_1= pad_func_1, /**< SD_CMD/SPIS_MISO/GPIO1 Pad function 1 */
    pad_spis0_mosi_2= pad_func_1, /**< SD_CD/SPIS_MOSI/GPIO2 Pad function 1 */
    pad_spis0_ss_3  = pad_func_1, /**< SD_DATA0/SPIS_SS/GPIO3 Pad function 1 */
    pad_pwm7        = pad_func_1, /**< PWM0/SD_DATA1/PWM7/GPIO4 Pad function 1 */
    pad_pwm6        = pad_func_1, /**< PWM6/SD_DATA2/PWM1/GPIO5 Pad function 1 */
    pad_pwm5        = pad_func_1, /**< SD_DATA3/PWM5/GPIO6 Pad function 1 */
    pad_pwm4        = pad_func_1, /**< SD_WP/PWM4/GPIO7 Pad function 1 */
    pad_pwm3_8      = pad_func_1, /**< PWM3/GPIO8 Pad function 1 */
    pad_pwm2_9      = pad_func_1, /**< PWM2/GPIO9 Pad function 1 */
    pad_pwm0_11     = pad_func_1, /**< PWM0/GPIO11 Pad function 1 */
    pad_pwm1_10     = pad_func_1, /**< PWM1/GPIO10 Pad function 1 */
    pad_i2cm_scl    = pad_func_1, /**< I2CS_SCL/I2CM_SCL/GPIO12 Pad function 1 */
    pad_i2cm_sda    = pad_func_1, /**< I2CS_SDA/I2CM_SDA/GPIO13 Pad function 1 */
    pad_uart2_rxd   = pad_func_1, /**< UART2_RXD/GPIO14 Pad function 1 */
    pad_uart2_txd   = pad_func_1, /**< UART2_TXD/GPIO15 Pad function 1 */
    pad_uart2_rts   = pad_func_1, /**< UART2_RTS/GPIO16 Pad function 1 */
    pad_uart2_cts   = pad_func_1, /**< UART2_CTS/GPIO17 Pad function 1 */
    pad_uart2_dtr   = pad_func_1, /**< UART3_RXD/UART2_DTR/GPIO18 Pad function 1 */
    pad_uart2_dsr   = pad_func_1, /**< UART3_TXD/UART2_DSR/GPIO19 Pad function 1 */
    pad_uart2_dcd   = pad_func_1, /**< UART3_RTS/UART2_DCD/GPIO20 Pad function 1 */
    pad_uart2_ri    = pad_func_1, /**< UART3_CTS/UART2_RI/GPIO21 Pad function 1 */
    pad_uart0_rxd   = pad_func_1, /**< PWM3/UART0_RXD/GPIO22 Pad function 1 */
    pad_uart0_txd   = pad_func_1, /**< PWM2/UART0_TXD/GPIO23 Pad function 1 */
    pad_uart0_rts   = pad_func_1, /**< PWM1/UART0_RTS/GPIO24 Pad function 1 */
    pad_uart0_cts   = pad_func_1, /**< PWM0/UART0_CTS/GPIO25 Pad function 1 */
    pad_uart0_dtr   = pad_func_1, /**< UART1_RXD/UART0_DTR/GPIO26 Pad function 1 */
    pad_uart0_dsr   = pad_func_1, /**< UART1_TXD/UART0_DSR/GPIO27 Pad function 1 */
    pad_uart0_dcd   = pad_func_1, /**< UART1_RTS/UART0_DCD/GPIO28 Pad function 1 */
    pad_uart0_ri    = pad_func_1, /**< SPIM_SS0/UART1_CTS/UART0_RI/GPIO29 Pad function 1 */
    pad_spim_ss0_30 = pad_func_1, /**< SPIM_SS0/GPIO30 Pad function 1 */
    pad_spim_ss1    = pad_func_1, /**< SPIM_SS1/GPIO31 Pad function 1 */
    pad_spim_ss2    = pad_func_1, /**< SPIM_SS2/GPIO32 Pad function 1 */
    pad_spim_ss3    = pad_func_1, /**< SPIM_SS3/GPIO33 Pad function 1 */
    pad_spim_sck    = pad_func_1, /**< SPIM_CLK/SPIS_CLK/GPIO34 Pad function 1 */
    pad_spim_miso   = pad_func_1, /**< SPIS_MISO/SPIM_MISO/GPIO35 Pad function 1 */
    pad_spim_mosi   = pad_func_1, /**< SPIS_MOSI/SPIM_MOSI/GPIO36 Pad function 1 */
    pad_spim_io2    = pad_func_1, /**< SPIS_SS/SPIM_IO2/GPIO37 Pad function 1 */
    pad_spim_io3    = pad_func_1, /**< RTC_REF/SPIM_IO3/GPIO38 Pad function 1 */
    pad_vbus_dtc    = pad_func_1, /**< VBUS_DTC/GPIO39 Pad function 1 */

    pad_sd_clk      = pad_func_2, /**< SD_CLK/SPIS_CLK/GPIO0 Pad function 2 */
    pad_sd_cmd      = pad_func_2, /**< SD_CMD/SPIS_MISO/GPIO1 Pad function 2 */
    pad_sd_cd       = pad_func_2, /**< SD_CD/SPIS_MOSI/GPIO2 Pad function 2 */
    pad_sd_data0    = pad_func_2, /**< SD_DATA0/SPIS_SS/GPIO3 Pad function 2 */
    pad_sd_data1    = pad_func_2, /**< PWM0/SD_DATA1/PWM7/GPIO4 Pad function 2 */
    pad_sd_data2    = pad_func_2, /**< PWM6/SD_DATA2/PWM1/GPIO5 Pad function 2 */
    pad_sd_data3    = pad_func_2, /**< SD_DATA3/PWM5/GPIO6 Pad function 2 */
    pad_sd_wp       = pad_func_2, /**< SD_WP/PWM4/GPIO7 Pad function 2 */

    pad_i2cs_scl    = pad_func_2, /**< I2CS_SCL/I2CM_SCL/GPIO12 Pad function 2 */
    pad_i2cs_sda    = pad_func_2, /**< I2CS_SDA/I2CM_SDA/GPIO13 Pad function 2 */

    pad_uart3_rxd   = pad_func_2, /**< UART3_RXD/UART2_DTR/GPIO18 Pad function 2 */
    pad_uart3_txd   = pad_func_2, /**< UART3_TXD/UART2_DSR/GPIO19 Pad function 2 */
    pad_uart3_rts   = pad_func_2, /**< UART3_RTS/UART2_DCD/GPIO20 Pad function 2 */
    pad_uart3_cts   = pad_func_2, /**< UART3_CTS/UART2_RI/GPIO21 Pad function 2 */
    pad_pwm3_22     = pad_func_2, /**< PWM3/UART0_RXD/GPIO22 Pad function 1 */
    pad_pwm2_23     = pad_func_2, /**< PWM2/UART0_TXD/GPIO23 Pad function 1 */
    pad_pwm1_24     = pad_func_2, /**< PWM1/UART0_RTS/GPIO24 Pad function 2 */
    pad_pwm0_25     = pad_func_2, /**< PWM0/UART0_CTS/GPIO25 Pad function 2 */
    pad_uart1_txd   = pad_func_2, /**< UART1_RXD/UART0_DTR/GPIO26 Pad function 2 */
    pad_uart1_rxd   = pad_func_2, /**< UART1_TXD/UART0_DSR/GPIO27 Pad function 2 */
    pad_uart1_rts   = pad_func_2, /**< UART1_RTS/UART0_DCD/GPIO28 Pad function 2 */
    pad_uart1_cts   = pad_func_2, /**< SPIM_SS0/UART1_CTS/UART0_RI/GPIO29 Pad function 2 */

    pad_spis0_clk   = pad_func_2, /**< SPIM_CLK/SPIS_CLK/GPIO34 Pad function 2 */
    pad_spis0_miso  = pad_func_2, /**< SPIS_MISO/SPIM_MISO/GPIO35 Pad function 2 */
    pad_spis0_mosi  = pad_func_2, /**< SPIS_MOSI/SPIM_MOSI/GPIO36 Pad function 2 */
    pad_spis0_ss    = pad_func_2, /**< SPIS_SS/SPIM_IO2/GPIO37 Pad function 2 */
    pad_rtc_ref     = pad_func_2, /**< RTC_REF/SPIM_IO3/GPIO38 Pad function 2 */

    pad_spim_ss0_29 = pad_func_3, /**< SPIM_SS0/UART1_CTS/UART0_RI/GPIO29 Pad function 3 */
    pad_pwm0_4      = pad_func_3, /**< PWM0/SD_DATA1/PWM7/GPIO4 Pad function 3 */
    pad_pwm1_5      = pad_func_3, /**< PWM1/SD_DATA2/PWM6/GPIO5 Pad function 3 */
} pad_func_t;

typedef enum
{
    gpio_spis0_clk   = 0, /**< SD_CLK/SPIS_CLK/GPIO0 Pad function 1 */
    gpio_spis0_miso  = 1, /**< SD_CMD/SPIS_MISO/GPIO1 Pad function 1 */
    gpio_spis0_mosi  = 2, /**< SD_CD/SPIS_MOSI/GPIO2 Pad function 1 */
    gpio_spis0_ss    = 3, /**< SD_DATA0/SPIS_SS/GPIO3 Pad function 1 */
    gpio_pwm7        = 4, /**< PWM0/SD_DATA1/PWM7/GPIO4 Pad function 1 */
    gpio_pwm6        = 5, /**< PWM6/SD_DATA2/PWM1/GPIO5 Pad function 1 */
    gpio_pwm5        = 6, /**< SD_DATA3/PWM5/GPIO6 Pad function 1 */
    gpio_pwm4        = 7, /**< SD_WP/PWM4/GPIO7 Pad function 1 */
    gpio_pwm3        = 8, /**< PWM3/GPIO8 Pad function 1 */
    gpio_pwm2        = 9, /**< PWM2/GPIO9 Pad function 1 */
    gpio_pwm0        = 11, /**< PWM0/GPIO11 Pad function 1 */
    gpio_pwm1        = 10, /**< PWM1/GPIO10 Pad function 1 */
    gpio_i2cm_scl    = 12, /**< I2CS_SCL/I2CM_SCL/GPIO12 Pad function 1 */
    gpio_i2cm_sda    = 13, /**< I2CS_SDA/I2CM_SDA/GPIO13 Pad function 1 */
    gpio_uart2_rxd   = 14, /**< UART2_RXD/GPIO14 Pad function 1 */
    gpio_uart2_txd   = 15, /**< UART2_TXD/GPIO15 Pad function 1 */
    gpio_uart2_rts   = 16, /**< UART2_RTS/GPIO16 Pad function 1 */
    gpio_uart2_cts   = 17, /**< UART2_CTS/GPIO17 Pad function 1 */
    gpio_uart2_dtr   = 18, /**< UART3_RXD/UART2_DTR/GPIO18 Pad function 1 */
    gpio_uart2_dsr   = 19, /**< UART3_TXD/UART2_DSR/GPIO19 Pad function 1 */
    gpio_uart2_dcd   = 20, /**< UART3_RTS/UART2_DCD/GPIO20 Pad function 1 */
    gpio_uart2_ri    = 21, /**< UART3_CTS/UART2_RI/GPIO21 Pad function 1 */
    gpio_uart0_rxd   = 22, /**< PWM3/UART0_RXD/GPIO22 Pad function 1 */
    gpio_uart0_txd   = 23, /**< PWM2/UART0_TXD/GPIO23 Pad function 1 */
    gpio_uart0_rts   = 24, /**< PWM1/UART0_RTS/GPIO24 Pad function 1 */
    gpio_uart0_cts   = 25, /**< PWM0/UART0_CTS/GPIO25 Pad function 1 */
    gpio_uart0_dtr   = 26, /**< UART1_RXD/UART0_DTR/GPIO26 Pad function 1 */
    gpio_uart0_dsr   = 27, /**< UART1_TXD/UART0_DSR/GPIO27 Pad function 1 */
    gpio_uart0_dcd   = 28, /**< UART1_RTS/UART0_DCD/GPIO28 Pad function 1 */
    gpio_uart0_ri    = 29, /**< SPIM_SS0/UART1_CTS/UART0_RI/GPIO29 Pad function 1 */
    gpio_spim_ss0    = 30, /**< SPIM_SS0/GPIO30 Pad function 1 */
    gpio_spim_ss1    = 31, /**< SPIM_SS1/GPIO31 Pad function 1 */
    gpio_spim_ss2    = 32, /**< SPIM_SS2/GPIO32 Pad function 1 */
    gpio_spim_ss3    = 33, /**< SPIM_SS3/GPIO33 Pad function 1 */
    gpio_spim_sck    = 34, /**< SPIM_CLK/SPIS_CLK/GPIO34 Pad function 1 */
    gpio_spim_miso   = 35, /**< SPIS_MISO/SPIM_MISO/GPIO35 Pad function 1 */
    gpio_spim_mosi   = 36, /**< SPIS_MOSI/SPIM_MOSI/GPIO36 Pad function 1 */
    gpio_spim_io2    = 37, /**< SPIS_SS/SPIM_IO2/GPIO37 Pad function 1 */
    gpio_spim_io3    = 38, /**< RTC_REF/SPIM_IO3/GPIO38 Pad function 1 */
    gpio_vbus_dtc    = 39, /**< VBUS_DTC/GPIO39 Pad function 1 */

    gpio_sd_clk      = 0, /**< SD_CLK/SPIS_CLK/GPIO0 Pad function 2 */
    gpio_sd_cmd      = 1, /**< SD_CMD/SPIS_MISO/GPIO1 Pad function 2 */
    gpio_sd_cd       = 2, /**< SD_CD/SPIS_MOSI/GPIO2 Pad function 2 */
    gpio_sd_data0    = 3, /**< SD_DATA0/SPIS_SS/GPIO3 Pad function 2 */
    gpio_sd_data1    = 4, /**< PWM0/SD_DATA1/PWM7/GPIO4 Pad function 2 */
    gpio_sd_data2    = 5, /**< PWM6/SD_DATA2/PWM1/GPIO5 Pad function 2 */
    gpio_sd_data3    = 6, /**< SD_DATA3/PWM5/GPIO6 Pad function 2 */
    gpio_sd_wp       = 7, /**< SD_WP/PWM4/GPIO7 Pad function 2 */

    gpio_i2cs_scl    = 12, /**< I2CS_SCL/I2CM_SCL/GPIO12 Pad function 2 */
    gpio_i2cs_sda    = 13, /**< I2CS_SDA/I2CM_SDA/GPIO13 Pad function 2 */

    gpio_uart3_rxd   = 18, /**< UART3_RXD/UART2_DTR/GPIO18 Pad function 2 */
    gpio_uart3_txd   = 19, /**< UART3_TXD/UART2_DSR/GPIO19 Pad function 2 */
    gpio_uart3_rts   = 20, /**< UART3_RTS/UART2_DCD/GPIO20 Pad function 2 */
    gpio_uart3_cts   = 21, /**< UART3_CTS/UART2_RI/GPIO21 Pad function 2 */
    gpio_pwm3        = 22, /**< PWM3/UART0_RXD/GPIO22 Pad function 1 */
    gpio_pwm2        = 23, /**< PWM2/UART0_TXD/GPIO23 Pad function 1 */
    gpio_pwm1        = 24, /**< PWM1/UART0_RTS/GPIO24 Pad function 2 */
    gpio_pwm0        = 25, /**< PWM0/UART0_CTS/GPIO25 Pad function 2 */
    gpio_uart1_txd   = 26, /**< UART1_RXD/UART0_DTR/GPIO26 Pad function 2 */
    gpio_uart1_rxd   = 27, /**< UART1_TXD/UART0_DSR/GPIO27 Pad function 2 */
    gpio_uart1_rts   = 28, /**< UART1_RTS/UART0_DCD/GPIO28 Pad function 2 */
    gpio_uart1_cts   = 29, /**< SPIM_SS0/UART1_CTS/UART0_RI/GPIO29 Pad function 2 */

    gpio_spis0_clk   = 34, /**< SPIM_CLK/SPIS_CLK/GPIO34 Pad function 2 */
    gpio_spis0_miso  = 35, /**< SPIS_MISO/SPIM_MISO/GPIO35 Pad function 2 */
    gpio_spis0_mosi  = 36, /**< SPIS_MOSI/SPIM_MOSI/GPIO36 Pad function 2 */
    gpio_spis0_ss    = 37, /**< SPIS_SS/SPIM_IO2/GPIO37 Pad function 2 */
    gpio_rtc_ref     = 38, /**< RTC_REF/SPIM_IO3/GPIO38 Pad function 2 */

    gpio_spim_ss0    = 29, /**< SPIM_SS0/UART1_CTS/UART0_RI/GPIO29 Pad function 3 */
    gpio_pwm0        = 4, /**< PWM0/SD_DATA1/PWM7/GPIO4 Pad function 3 */
    gpio_pwm1        = 5, /**< PWM1/SD_DATA2/PWM6/GPIO5 Pad function 3 */
} gpio_func_t;

#else

typedef enum
{
    pad_func_0      = 0, /**< Pad function 0 */
    pad_func_1      = 1, /**< Pad function 1 */
    pad_func_2      = 2, /**< Pad function 2 */
    pad_func_3      = 3, /**< Pad function 3 */

    pad_gpio0       = pad_func_0, /**< VBUS_DISCH/GPIO0 Pad function 0 */
    pad_gpio1       = pad_func_0, /**< OC_N/GPIO1 Pad function 0 */
    pad_gpio2       = pad_func_0, /**< PSW_N/GPIO2 Pad function 0 */
    pad_gpio3       = pad_func_0, /**< VBUS_DTC/GPIO3 Pad function 0 */
    pad_gpio4       = pad_func_0, /**< ENET_LED0/GPIO4 Pad function 0 */
    pad_gpio5       = pad_func_0, /**< ENET_LED1/GPIO5 Pad function 0 */
    pad_gpio6       = pad_func_0, /**< ADC1/CAM_XCLK/GPIO6 Pad function 0 */
    pad_gpio7       = pad_func_0, /**< ADC2/CAM_PCLK/GPIO7 Pad function 0 */
    pad_gpio8       = pad_func_0, /**< ADC3/CAM_VD/GPIO8 Pad function 0 */
    pad_gpio9       = pad_func_0, /**< ADC4/CAM_HD/GPIO9 Pad function 0 */
    pad_gpio10      = pad_func_0, /**< ADC5/CAM_D7/GPIO10 Pad function 0 */
    pad_gpio11      = pad_func_0, /**< ADC6/CAM_D6/GPIO11 Pad function 0 */
    pad_gpio12      = pad_func_0, /**< ADC7/CAM_D5/GPIO12 Pad function 0 */
    pad_gpio13      = pad_func_0, /**< DAC1/CAM_D4/GPIO13 Pad function 0 */
    pad_gpio14      = pad_func_0, /**< DAC0/CAM_D3/GPIO14 Pad function 0 */
    pad_gpio15      = pad_func_0, /**< CAN0_TXD/CAM_D2/GPIO15 Pad function 0 */
    pad_gpio16      = pad_func_0, /**< CAN0_RXD/CAM_D1/GPIO16 Pad function 0 */
    pad_gpio17      = pad_func_0, /**< CAN1_TXD/CAM_D0/GPIO17 Pad function 0 */
    pad_gpio18      = pad_func_0, /**< CAN1_RXD/GPIO18 Pad function 0 */
    pad_gpio19      = pad_func_0, /**< SD_CLK/GPIO19 Pad function 0 */
    pad_gpio20      = pad_func_0, /**< SD_CMD/GPIO20 Pad function 0 */
    pad_gpio21      = pad_func_0, /**< SD_DATA3/GPIO21 Pad function 0 */
    pad_gpio22      = pad_func_0, /**< SD_DATA2/GPIO22 Pad function 0 */
    pad_gpio23      = pad_func_0, /**< SD_DATA1/GPIO23 Pad function 0 */
    pad_gpio24      = pad_func_0, /**< SD_DATA0/GPIO24 Pad function 0 */
    pad_gpio25      = pad_func_0, /**< SD_CD/GPIO25 Pad function 0 */
    pad_gpio26      = pad_func_0, /**< SD_WP/GPIO26 Pad function 0 */
    pad_gpio27      = pad_func_0, /**< SPIM_CLK/GPIO27 Pad function 0 */
    pad_gpio28      = pad_func_0, /**< SPIM_SS0/GPIO28 Pad function 0 */
    pad_gpio29      = pad_func_0, /**< SPIM_MOSI/GPIO29 Pad function 0 */
    pad_gpio30      = pad_func_0, /**< SPIM_MISO/GPIO30 Pad function 0 */
    pad_gpio31      = pad_func_0, /**< SPIM_IO2/GPIO31 Pad function 0 */
    pad_gpio32      = pad_func_0, /**< SPIM_IO3/GPIO32 Pad function 0 */
    pad_gpio33      = pad_func_0, /**< SPIM_SS1/GPIO33 Pad function 0 */
    pad_gpio34      = pad_func_0, /**< SPIM_SS2/GPIO34 Pad function 0 */
    pad_gpio35      = pad_func_0, /**< SPIM_SS3/GPIO35 Pad function 0 */
    pad_gpio36      = pad_func_0, /**< SPIS0_CLK/GPIO36 Pad function 0 */
    pad_gpio37      = pad_func_0, /**< SPIS0_SS/GPIO37 Pad function 0 */
    pad_gpio38      = pad_func_0, /**< SPIS0_MOSI/GPIO38 Pad function 0 */
    pad_gpio39      = pad_func_0, /**< SPIS0_MISO/GPIO39 Pad function 0 */
    pad_gpio40      = pad_func_0, /**< SPIS1_CLK/GPIO40 Pad function 0 */
    pad_gpio41      = pad_func_0, /**< SPIS1_SS/GPIO41 Pad function 0 */
    pad_gpio42      = pad_func_0, /**< SPIS1_MOSI/GPIO42 Pad function 0 */
    pad_gpio43      = pad_func_0, /**< SPIS1_MISO/GPIO43 Pad function 0 */
    pad_gpio44      = pad_func_0, /**< I2C0_SCL/GPIO44 Pad function 0 */
    pad_gpio45      = pad_func_0, /**< I2C0_SDA/GPIO45 Pad function 0 */
    pad_gpio46      = pad_func_0, /**< I2C1_SCL/GPIO46 Pad function 0 */
    pad_gpio47      = pad_func_0, /**< I2C1_SDA/GPIO47 Pad function 0 */
    pad_gpio48      = pad_func_0, /**< UART0_TXD/GPIO48 Pad function 0 */
    pad_gpio49      = pad_func_0, /**< UART0_RXD/GPIO49 Pad function 0 */
    pad_gpio50      = pad_func_0, /**< UART0_RTS/GPIO50 Pad function 0 */
    pad_gpio51      = pad_func_0, /**< UART0_CTS/GPIO51 Pad function 0 */
    pad_gpio52      = pad_func_0, /**< UART0_DTR/UART1_TXD/PWM4/GPIO52 Pad function 0 */
    pad_gpio53      = pad_func_0, /**< UART0_DSR/UART1_RXD/PWM5/GPIO53 Pad function 0 */
    pad_gpio54      = pad_func_0, /**< UART0_DCD/UART1_RTS/PWM6/GPIO54 Pad function 0 */
    pad_gpio55      = pad_func_0, /**< UART0_RI/UART1_CTS/PWM7/GPIO55 Pad function 0 */
    pad_gpio56      = pad_func_0, /**< PWM0/GPIO56 Pad function 0 */
    pad_gpio57      = pad_func_0, /**< PWM1/GPIO57 Pad function 0 */
    pad_gpio58      = pad_func_0, /**< PWM2/GPIO58 Pad function 0 */
    pad_gpio59      = pad_func_0, /**< PWM3/GPIO59 Pad function 0 */
    pad_gpio60      = pad_func_0, /**< I2S_SDAO/GPIO60 Pad function 0 */
    pad_gpio61      = pad_func_0, /**< I2S_SDAI/GPIO61 Pad function 0 */
    pad_gpio62      = pad_func_0, /**< I2S_BCLK/GPIO62 Pad function 0 */
    pad_gpio63      = pad_func_0, /**< I2S_LRCLK/GPIO63 Pad function 0 */
    pad_gpio64      = pad_func_0, /**< I2S_MCLK/GPIO64 Pad function 0 */
    pad_gpio65      = pad_func_0, /**< I2S_CLK22/GPIO65 Pad function 0 */
    pad_gpio66      = pad_func_0, /**< I2S_CLK24/GPIO66 Pad function 0 */

    pad_oc_n        = pad_func_1, /**< OC_N/GPIO1 Pad function 1 */
    pad_vbus_dtc    = pad_func_1, /**< VBUS_DTC/GPIO3 Pad function 1 */

    pad_enet_led0   = pad_func_1, /**< ENET_LED0/GPIO4 Pad function 1 */
    pad_enet_led1   = pad_func_1, /**< ENET_LED1/GPIO5 Pad function 1 */

    pad_cam_xclk    = pad_func_1, /**< ADC1/CAM_XCLK/GPIO6 Pad function 1 */
    pad_cam_pclk    = pad_func_1, /**< ADC2/CAM_PCLK/GPIO7 Pad function 1 */
    pad_cam_vd      = pad_func_1, /**< ADC3/CAM_VD/GPIO8 Pad function 1 */
    pad_cam_hd      = pad_func_1, /**< ADC4/CAM_HD/GPIO9 Pad function 1 */
    pad_cam_d7      = pad_func_1, /**< ADC5/CAM_D7/GPIO10 Pad function 1 */
    pad_cam_d6      = pad_func_1, /**< ADC6/CAM_D6/GPIO11 Pad function 1 */
    pad_cam_d5      = pad_func_1, /**< ADC7/CAM_D5/GPIO12 Pad function 1 */
    pad_cam_d4      = pad_func_1, /**< DAC1/CAM_D4/GPIO13 Pad function 1 */
    pad_cam_d3      = pad_func_1, /**< DAC0/CAM_D3/GPIO14 Pad function 1 */
    pad_cam_d2      = pad_func_1, /**< CAN0_TXD/CAM_D2/GPIO15 Pad function 1 */
    pad_cam_d1      = pad_func_1, /**< CAN0_RXD/CAM_D1/GPIO16 Pad function 1 */
    pad_cam_d0      = pad_func_1, /**< CAN1_TXD/CAM_D0/GPIO17 Pad function 1 */

    pad_sd_clk      = pad_func_1, /**< SD_CLK/GPIO19 Pad function 1 */
    pad_sd_cmd      = pad_func_1, /**< SD_CMD/GPIO20 Pad function 1 */
    pad_sd_data3    = pad_func_1, /**< SD_DATA3/GPIO21 Pad function 1 */
    pad_sd_data2    = pad_func_1, /**< SD_DATA2/GPIO22 Pad function 1 */
    pad_sd_data1    = pad_func_1, /**< SD_DATA1/GPIO23 Pad function 1 */
    pad_sd_data0    = pad_func_1, /**< SD_DATA0/GPIO24 Pad function 1 */
    pad_sd_cd       = pad_func_1, /**< SD_CD/GPIO25 Pad function 1 */
    pad_sd_wp       = pad_func_1, /**< SD_WP/GPIO26 Pad function 1 */

    pad_spim_sck    = pad_func_1, /**< SPIM_CLK/GPIO27 Pad function 1 */
    pad_spim_ss0    = pad_func_1, /**< SPIM_SS0/GPIO28 Pad function 1 */
    pad_spim_mosi   = pad_func_1, /**< SPIM_MOSI/GPIO29 Pad function 1 */
    pad_spim_miso   = pad_func_1, /**< SPIM_MISO/GPIO30 Pad function 1 */
    pad_spim_io2    = pad_func_1, /**< SPIM_IO2/GPIO31 Pad function 1 */
    pad_spim_io3    = pad_func_1, /**< SPIM_IO3/GPIO32 Pad function 1 */
    pad_spim_ss1    = pad_func_1, /**< SPIM_SS1/GPIO33 Pad function 1 */
    pad_spim_ss2    = pad_func_1, /**< SPIM_SS2/GPIO34 Pad function 1 */
    pad_spim_ss3    = pad_func_1, /**< SPIM_SS3/GPIO35 Pad function 1 */

    pad_spis0_clk   = pad_func_1, /**< SPIS0_CLK/GPIO36 Pad function 1 */
    pad_spis0_ss    = pad_func_1, /**< SPIS0_SS/GPIO37 Pad function 1 */
    pad_spis0_mosi  = pad_func_1, /**< SPIS0_MOSI/GPIO38 Pad function 1 */
    pad_spis0_miso  = pad_func_1, /**< SPIS0_MISO/GPIO39 Pad function 1 */
    pad_spis1_clk   = pad_func_1, /**< SPIS1_CLK/GPIO40 Pad function 1 */
    pad_spis1_ss    = pad_func_1, /**< SPIS1_SS/GPIO41 Pad function 1 */
    pad_spis1_mosi  = pad_func_1, /**< SPIS1_MOSI/GPIO42 Pad function 1 */
    pad_spis1_miso  = pad_func_1, /**< SPIS1_MISO/GPIO43 Pad function 1 */

    pad_i2c0_scl    = pad_func_1, /**< I2C0_SCL/GPIO44 Pad function 1 */
    pad_i2c0_sda    = pad_func_1, /**< I2C0_SDA/GPIO45 Pad function 1 */
    pad_i2c1_scl    = pad_func_1, /**< I2C1_SCL/GPIO46 Pad function 1 */
    pad_i2c1_sda    = pad_func_1, /**< I2C1_SDA/GPIO47 Pad function 1 */

    pad_pwm4        = pad_func_1, /**< UART0_DTR/UART1_TXD/PWM4/GPIO52 Pad function 1 */
    pad_pwm5        = pad_func_1, /**< UART0_DSR/UART1_RXD/PWM5/GPIO53 Pad function 1 */
    pad_pwm6        = pad_func_1, /**< UART0_DCD/UART1_RTS/PWM6/GPIO54 Pad function 1 */
    pad_pwm7        = pad_func_1, /**< UART0_RI/UART1_CTS/PWM7/GPIO55 Pad function 1 */
    pad_pwm0        = pad_func_1, /**< PWM0/GPIO56 Pad function 1 */
    pad_pwm1        = pad_func_1, /**< PWM1/GPIO57 Pad function 1 */
    pad_pwm2        = pad_func_1, /**< PWM2/GPIO58 Pad function 1 */
    pad_pwm3        = pad_func_1, /**< PWM3/GPIO59 Pad function 1 */

    pad_i2s_sdao    = pad_func_1, /**< I2S_SDAO/GPIO60 Pad function 1 */
    pad_i2s_sdai    = pad_func_1, /**< I2S_SDAI/GPIO61 Pad function 1 */
    pad_i2s_bclk    = pad_func_1, /**< I2S_BCLK/GPIO62 Pad function 1 */
    pad_i2s_lrclk   = pad_func_1, /**< I2S_LRCLK/GPIO63 Pad function 1 */
    pad_i2s_mclk    = pad_func_1, /**< I2S_MCLK/GPIO64 Pad function 1 */
    pad_i2s_clk22   = pad_func_1, /**< I2S_CLK22/GPIO65 Pad function 1 */
    pad_i2s_clk24   = pad_func_1, /**< I2S_CLK24/GPIO66 Pad function 1 */

    pad_can0_txd    = pad_func_2, /**< CAN0_TXD/CAM_D2/GPIO15 Pad function 2 */
    pad_can0_rxd    = pad_func_2, /**< CAN0_RXD/CAM_D1/GPIO16 Pad function 2 */
    pad_can1_txd    = pad_func_2, /**< CAN1_TXD/CAM_D0/GPIO17 Pad function 2 */
    pad_can1_rxd    = pad_func_2, /**< CAN1_RXD/GPIO18 Pad function 2 */

    pad_uart1_txd   = pad_func_2, /**< UART0_DTR/UART1_TXD/PWM4/GPIO52 Pad function 2 */
    pad_uart1_rxd   = pad_func_2, /**< UART0_DSR/UART1_RXD/PWM5/GPIO53 Pad function 2 */
    pad_uart1_rts   = pad_func_2, /**< UART0_DCD/UART1_RTS/PWM6/GPIO54 Pad function 2 */
    pad_uart1_cts   = pad_func_2, /**< UART0_RI/UART1_CTS/PWM7/GPIO55 Pad function 2 */

    pad_i2ss_bclk   = pad_func_2, /**< I2S_BCLK/GPIO62 Pad function 2 */
    pad_i2ss_lrclk  = pad_func_2, /**< I2S_LRCLK/GPIO63 Pad function 2 */

    pad_adc1        = pad_func_3, /**< ADC1/CAM_XCLK/GPIO6 Pad function 3 */
    pad_adc2        = pad_func_3, /**< ADC2/CAM_PCLK/GPIO7 Pad function 3 */
    pad_adc3        = pad_func_3, /**< ADC3/CAM_VD/GPIO8 Pad function 3 */
    pad_adc4        = pad_func_3, /**< ADC4/CAM_HD/GPIO9 Pad function 3 */
    pad_adc5        = pad_func_3, /**< ADC5/CAM_D7/GPIO10 Pad function 3 */
    pad_adc6        = pad_func_3, /**< ADC6/CAM_D6/GPIO11 Pad function 3 */
    pad_adc7        = pad_func_3, /**< ADC7/CAM_D5/GPIO12 Pad function 3 */

    pad_dac1        = pad_func_3, /**< DAC1/CAM_D4/GPIO13 Pad function 3 */
    pad_dac0        = pad_func_3, /**< DAC0/CAM_D3/GPIO14 Pad function 3 */

    pad_uart0_txd   = pad_func_3, /**< UART0_TXD/GPIO48 Pad function 3 */
    pad_uart0_rxd   = pad_func_3, /**< UART0_RXD/GPIO49 Pad function 3 */
    pad_uart0_rts   = pad_func_3, /**< UART0_RTS/GPIO50 Pad function 3 */
    pad_uart0_cts   = pad_func_3, /**< UART0_CTS/GPIO51 Pad function 3 */
    pad_uart0_dtr   = pad_func_3, /**< UART0_DTR/UART1_TXD/PWM4/GPIO52 Pad function 3 */
    pad_uart0_dsr   = pad_func_3, /**< UART0_DSR/UART1_RXD/PWM5/GPIO53 Pad function 3 */
    pad_uart0_dcd   = pad_func_3, /**< UART0_DCD/UART1_RTS/PWM6/GPIO54 Pad function 3 */
    pad_uart0_ri    = pad_func_3, /**< UART0_RI/UART1_CTS/PWM7/GPIO55 Pad function 3 */
} pad_func_t;

typedef enum {
	gpio_oc_n        = 1, /**< OC_N/GPIO1 Pad function 1 */
	gpio_vbus_dtc    = 3, /**< VBUS_DTC/GPIO3 Pad function 1 */

	gpio_enet_led0   = 4, /**< ENET_LED0/GPIO4 Pad function 1 */
	gpio_enet_led1   = 5, /**< ENET_LED1/GPIO5 Pad function 1 */

	gpio_cam_xclk    = 6, /**< ADC1/CAM_XCLK/GPIO6 Pad function 1 */
	gpio_cam_pclk    = 7, /**< ADC2/CAM_PCLK/GPIO7 Pad function 1 */
	gpio_cam_vd      = 8, /**< ADC3/CAM_VD/GPIO8 Pad function 1 */
	gpio_cam_hd      = 9, /**< ADC4/CAM_HD/GPIO9 Pad function 1 */
	gpio_cam_d7      = 10, /**< ADC5/CAM_D7/GPIO10 Pad function 1 */
	gpio_cam_d6      = 11, /**< ADC6/CAM_D6/GPIO11 Pad function 1 */
	gpio_cam_d5      = 12, /**< ADC7/CAM_D5/GPIO12 Pad function 1 */
	gpio_cam_d4      = 13, /**< DAC1/CAM_D4/GPIO13 Pad function 1 */
	gpio_cam_d3      = 14, /**< DAC0/CAM_D3/GPIO14 Pad function 1 */
	gpio_cam_d2      = 15, /**< CAN0_TXD/CAM_D2/GPIO15 Pad function 1 */
	gpio_cam_d1      = 16, /**< CAN0_RXD/CAM_D1/GPIO16 Pad function 1 */
	gpio_cam_d0      = 17, /**< CAN1_TXD/CAM_D0/GPIO17 Pad function 1 */

	gpio_sd_clk      = 19, /**< SD_CLK/GPIO19 Pad function 1 */
	gpio_sd_cmd      = 20, /**< SD_CMD/GPIO20 Pad function 1 */
	gpio_sd_data3    = 21, /**< SD_DATA3/GPIO21 Pad function 1 */
	gpio_sd_data2    = 22, /**< SD_DATA2/GPIO22 Pad function 1 */
	gpio_sd_data1    = 23, /**< SD_DATA1/GPIO23 Pad function 1 */
	gpio_sd_data0    = 24, /**< SD_DATA0/GPIO24 Pad function 1 */
	gpio_sd_cd       = 25, /**< SD_CD/GPIO25 Pad function 1 */
	gpio_sd_wp       = 26, /**< SD_WP/GPIO26 Pad function 1 */

	gpio_spim_sck    = 27, /**< SPIM_CLK/GPIO27 Pad function 1 */
	gpio_spim_ss0    = 28, /**< SPIM_SS0/GPIO28 Pad function 1 */
	gpio_spim_mosi   = 29, /**< SPIM_MOSI/GPIO29 Pad function 1 */
	gpio_spim_miso   = 30, /**< SPIM_MISO/GPIO30 Pad function 1 */
	gpio_spim_io2    = 31, /**< SPIM_IO2/GPIO31 Pad function 1 */
	gpio_spim_io3    = 32, /**< SPIM_IO3/GPIO32 Pad function 1 */
	gpio_spim_ss1    = 33, /**< SPIM_SS1/GPIO33 Pad function 1 */
	gpio_spim_ss2    = 34, /**< SPIM_SS2/GPIO34 Pad function 1 */
	gpio_spim_ss3    = 35, /**< SPIM_SS3/GPIO35 Pad function 1 */

	gpio_spis0_clk   = 36, /**< SPIS0_CLK/GPIO36 Pad function 1 */
	gpio_spis0_ss    = 37, /**< SPIS0_SS/GPIO37 Pad function 1 */
	gpio_spis0_mosi  = 38, /**< SPIS0_MOSI/GPIO38 Pad function 1 */
	gpio_spis0_miso  = 39, /**< SPIS0_MISO/GPIO39 Pad function 1 */
	gpio_spis1_clk   = 40, /**< SPIS1_CLK/GPIO40 Pad function 1 */
	gpio_spis1_ss    = 41, /**< SPIS1_SS/GPIO41 Pad function 1 */
	gpio_spis1_mosi  = 42, /**< SPIS1_MOSI/GPIO42 Pad function 1 */
	gpio_spis1_miso  = 43, /**< SPIS1_MISO/GPIO43 Pad function 1 */

	gpio_i2c0_scl    = 44, /**< I2C0_SCL/GPIO44 Pad function 1 */
	gpio_i2c0_sda    = 45, /**< I2C0_SDA/GPIO45 Pad function 1 */
	gpio_i2c1_scl    = 46, /**< I2C1_SCL/GPIO46 Pad function 1 */
	gpio_i2c1_sda    = 47, /**< I2C1_SDA/GPIO47 Pad function 1 */

	gpio_pwm4        = 52, /**< UART0_DTR/UART1_TXD/PWM4/GPIO52 Pad function 1 */
	gpio_pwm5        = 53, /**< UART0_DSR/UART1_RXD/PWM5/GPIO53 Pad function 1 */
	gpio_pwm6        = 54, /**< UART0_DCD/UART1_RTS/PWM6/GPIO54 Pad function 1 */
	gpio_pwm7        = 55, /**< UART0_RI/UART1_CTS/PWM7/GPIO55 Pad function 1 */
	gpio_pwm0        = 56, /**< PWM0/GPIO56 Pad function 1 */
	gpio_pwm1        = 57, /**< PWM1/GPIO57 Pad function 1 */
	gpio_pwm2        = 58, /**< PWM2/GPIO58 Pad function 1 */
	gpio_pwm3        = 59, /**< PWM3/GPIO59 Pad function 1 */

	gpio_i2s_sdao    = 60, /**< I2S_SDAO/GPIO60 Pad function 1 */
	gpio_i2s_sdai    = 61, /**< I2S_SDAI/GPIO61 Pad function 1 */
	gpio_i2s_bclk    = 62, /**< I2S_BCLK/GPIO62 Pad function 1 */
	gpio_i2s_lrclk   = 63, /**< I2S_LRCLK/GPIO63 Pad function 1 */
	gpio_i2s_mclk    = 64, /**< I2S_MCLK/GPIO64 Pad function 1 */
	gpio_i2s_clk22   = 65, /**< I2S_CLK22/GPIO65 Pad function 1 */
	gpio_i2s_clk24   = 66, /**< I2S_CLK24/GPIO66 Pad function 1 */

	gpio_can0_txd    = 15, /**< CAN0_TXD/CAM_D2/GPIO15 Pad function 2 */
	gpio_can0_rxd    = 16, /**< CAN0_RXD/CAM_D1/GPIO16 Pad function 2 */
	gpio_can1_txd    = 17, /**< CAN1_TXD/CAM_D0/GPIO17 Pad function 2 */
	gpio_can1_rxd    = 18, /**< CAN1_RXD/GPIO18 Pad function 2 */

	gpio_uart1_txd   = 52, /**< UART0_DTR/UART1_TXD/PWM4/GPIO52 Pad function 2 */
	gpio_uart1_rxd   = 53, /**< UART0_DSR/UART1_RXD/PWM5/GPIO53 Pad function 2 */
	gpio_uart1_rts   = 54, /**< UART0_DCD/UART1_RTS/PWM6/GPIO54 Pad function 2 */
	gpio_uart1_cts   = 55, /**< UART0_RI/UART1_CTS/PWM7/GPIO55 Pad function 2 */

	gpio_i2ss_bclk   = 62, /**< I2S_BCLK/GPIO62 Pad function 2 */
	gpio_i2ss_lrclk  = 63, /**< I2S_LRCLK/GPIO63 Pad function 2 */

	gpio_adc1        = 6, /**< ADC1/CAM_XCLK/GPIO6 Pad function 3 */
	gpio_adc2        = 7, /**< ADC2/CAM_PCLK/GPIO7 Pad function 3 */
	gpio_adc3        = 8, /**< ADC3/CAM_VD/GPIO8 Pad function 3 */
	gpio_adc4        = 9, /**< ADC4/CAM_HD/GPIO9 Pad function 3 */
	gpio_adc5        = 10, /**< ADC5/CAM_D7/GPIO10 Pad function 3 */
	gpio_adc6        = 11, /**< ADC6/CAM_D6/GPIO11 Pad function 3 */
	gpio_adc7        = 12, /**< ADC7/CAM_D5/GPIO12 Pad function 3 */

	gpio_dac1        = 13, /**< DAC1/CAM_D4/GPIO13 Pad function 3 */
	gpio_dac0        = 14, /**< DAC0/CAM_D3/GPIO14 Pad function 3 */

	gpio_uart0_txd   = 48, /**< UART0_TXD/GPIO48 Pad function 3 */
	gpio_uart0_rxd   = 49, /**< UART0_RXD/GPIO49 Pad function 3 */
	gpio_uart0_rts   = 50, /**< UART0_RTS/GPIO50 Pad function 3 */
	gpio_uart0_cts   = 51, /**< UART0_CTS/GPIO51 Pad function 3 */
	gpio_uart0_dtr   = 52, /**< UART0_DTR/UART1_TXD/PWM4/GPIO52 Pad function 3 */
	gpio_uart0_dsr   = 53, /**< UART0_DSR/UART1_RXD/PWM5/GPIO53 Pad function 3 */
	gpio_uart0_dcd   = 54, /**< UART0_DCD/UART1_RTS/PWM6/GPIO54 Pad function 3 */
	gpio_uart0_ri    = 55, /**< UART0_RI/UART1_CTS/PWM7/GPIO55 Pad function 3 */
} gpio_func_t;

#endif

/** @brief Pad direction control. */
typedef enum
{
    pad_dir_input,      /**< Input */
    pad_dir_output,     /**< Output */
    pad_dir_open_drain  /**< Open Drain */
} pad_dir_t;

/** @brief GPIO Interrupt control */
typedef enum
{
    gpio_int_edge_falling,  /**< Interrupt on a falling edge */
    gpio_int_edge_raising   /**< Interrupt on a raising edge */
} gpio_int_edge_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/** @brief Set the pad function for a named GPIO
 *  Macro to set the gpio_function for a function. This will select the gpio_func_t
 *  (GPIO number) and the pad_func_t (function value) from the enumeration by
 *  appending the macro parameter A to form the enumerator value.
 *  For example to select the UART0 txd function (on GPIO48) and rxd (on GPIO49):
 *  	SET_GPIO_FUNCTION(uart0_txd);
 *  	SET_GPIO_FUNCTION(uart0_rxd);
 *  This is equivalent to:
 *  	gpio_function(gpio_uart0_txd, pad_uart0_txd);
 *  	gpio_function(gpio_uart0_rxd, pad_uart0_rxd);
 */
#define SET_GPIO_FUNCTION(A) gpio_function(gpio_##A, pad_##A)

/* FUNCTION PROTOTYPES *************************************************************/

/** @brief Configure the direction of a pin
 *  @param num The GPIO number
 *  @param dir The direction
 *  @returns On success a 0, otherwise -1
 */
int8_t gpio_dir(uint8_t num, pad_dir_t dir);

/** @brief Configure the slew rate for a pin
 *  @param num The GPIO number
 *  @param slew The slew rate of the pin
 *  @returns On success a 0, otherwise -1
 */
int8_t gpio_slew(uint8_t num, pad_slew_t slew);

/** @brief Configure the schmitt trigger for a pin
 *  @param num The GPIO number
 *  @param schmitt The Schmitt trigger configuration
 *  @returns On success a 0, otherwise -1
 */
int8_t gpio_schmitt(uint8_t num, pad_schmitt_t schmitt);

/** @brief Configure the pull up/down for a pin
 *  @param num The GPIO number
 *  @param pull The pullup/down configuration
 *  @returns On success a 0, otherwise -1
 */
int8_t gpio_pull(uint8_t num, pad_pull_t pull);

/** @brief Configure the maximum current drive for a pin
 *  @param num The GPIO number
 *  @param drive The maximum current
 *  @returns On success a 0, otherwise -1
 */
int8_t gpio_idrive(uint8_t num, pad_drive_t drive);

/** @brief Configure the alternative function for a pin
 *  @param num The GPIO number
 *  @param func The function that the pin should use
 *  @returns On success a 0, otherwise -1
 */
int8_t gpio_function(uint8_t num, pad_func_t func);

/** @brief Write a value to a GPIO pin
 *  @param num The GPIO number
 *  @param val The value to write
 *  @returns On success a 0, otherwise -1
 */
int8_t gpio_write(uint8_t num, uint8_t val);

/** @brief Read a value from a GPIO pin
 *  @param num The GPIO number
 *  @returns The value of the pin (1 = high, 0 = low), otherwise -1
 */
int8_t gpio_read(uint8_t num);

/** @brief Toggle the value of a GPIO pin
 *  @param num The GPIO number
 *  @returns On success a 0, otherwise -1
 */
int8_t gpio_toggle(uint8_t num);

/** @brief Enable an interrupt on a GPIO pin
 *  @param num The GPIO number
 *  @param edge The edge at which to trigger on
 *  @returns On success a 0, otherwise -1
 */
int8_t gpio_interrupt_enable(uint8_t num, gpio_int_edge_t edge);

/** @brief Disable an interrupt on a GPIO pin
 *  @param num The GPIO number
 *  @returns On success a 0, otherwise -1
 */
int8_t gpio_interrupt_disable(uint8_t num);

/** @brief Check if an interrupt has happened on a GPIO pin
 *  @param num The GPIO number
 *  @returns On no interrupt 0, on an interrupt 1, otherwise -1
 */
int8_t gpio_is_interrupted(uint8_t num);


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* FT900_GPIO_H_ */
