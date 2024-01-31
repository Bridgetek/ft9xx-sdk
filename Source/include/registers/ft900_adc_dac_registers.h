/**
  @file ft900_adc_dac_registers.h

  @brief ADC/DAC registers

**/

/*
 * ============================================================================
 * History
 * =======
 */

/*
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


#ifndef FT900_ADC_DAC_REGISTERS_H_
#define FT900_ADC_DAC_REGISTERS_H_

/* INCLUDES ************************************************************************/

#include <stdint.h>
#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

#define BIT_DAC_CONF_DAC_PDB0               (0)
#define MASK_DAC_CONF_DAC_PDB0              (1 << BIT_DAC_CONF_DAC_PDB0)
#define BIT_DAC_CONF_DAC_CONT0              (1)
#define MASK_DAC_CONF_DAC_CONT0             (1 << BIT_DAC_CONF_DAC_CONT0)
#define BIT_DAC_CONF_DAC_START0             (3)
#define MASK_DAC_CONF_DAC_START0            (1 << BIT_DAC_CONF_DAC_START0)
#define BIT_DAC_CONF_DAC_PDB1               (4)
#define MASK_DAC_CONF_DAC_PDB1              (1 << BIT_DAC_CONF_DAC_PDB1)
#define BIT_DAC_CONF_DAC_CONT1              (5)
#define MASK_DAC_CONF_DAC_CONT1             (1 << BIT_DAC_CONF_DAC_CONT1)
#define BIT_DAC_CONF_DAC_START1             (7)
#define MASK_DAC_CONF_DAC_START1            (1 << BIT_DAC_CONF_DAC_START1)

#define BIT_ADC_CONF_ADC_CHANNEL            (0)
#define MASK_ADC_CONF_ADC_CHANNEL           (0x7 << BIT_ADC_CONF_ADC_CHANNEL)
#define BIT_ADC_CONF_ADC_PDB                (3)
#define MASK_ADC_CONF_ADC_PDB               (1 << BIT_ADC_CONF_ADC_PDB)
#define BIT_ADC_CONF_ADC_CONT               (4)
#define MASK_ADC_CONF_ADC_CONT              (1 << BIT_ADC_CONF_ADC_CONT)
#define BIT_ADC_CONF_ADC_EXT_VREF           (5)
#define MASK_ADC_CONF_ADC_EXT_VREF          (1 << BIT_ADC_CONF_ADC_EXT_VREF)
#define BIT_ADC_CONF_ADC_START              (7)
#define MASK_ADC_CONF_ADC_START             (1 << BIT_ADC_CONF_ADC_START)

#define BIT_IRQ_CTRL_DAC_IRQ_EN0            (0)
#define MASK_IRQ_CTRL_DAC_IRQ_EN0           (1 << BIT_IRQ_CTRL_DAC_IRQ_EN0)
#define BIT_IRQ_CTRL_DAC_IRQ_EN1            (1)
#define MASK_IRQ_CTRL_DAC_IRQ_EN1           (1 << BIT_IRQ_CTRL_DAC_IRQ_EN1)
#define BIT_IRQ_CTRL_ADC_IRQ_EN             (2)
#define MASK_IRQ_CTRL_ADC_IRQ_EN            (1 << BIT_IRQ_CTRL_ADC_IRQ_EN)
#define BIT_CONF_ADC_HALF_RATE              (6)
#define MASK_CONF_ADC_HALF_RATE             (1 << BIT_CONF_ADC_HALF_RATE)
#define BIT_CONF_ADC_8BIT_MODE              (7)
#define MASK_CONF_ADC_8BIT_MODE             (1 << BIT_CONF_ADC_8BIT_MODE)

#define BIT_IRQ_STATUS_ERR_DAC_IRQ_PEND0    (0)
#define MASK_IRQ_STATUS_ERR_DAC_IRQ_PEND0   (1 << BIT_IRQ_STATUS_ERR_DAC_IRQ_PEND0)
#define BIT_IRQ_STATUS_ERR_DAC_IRQ_PEND1    (1)
#define MASK_IRQ_STATUS_ERR_DAC_IRQ_PEND1   (1 << BIT_IRQ_STATUS_ERR_DAC_IRQ_PEND1)
#define BIT_IRQ_STATUS_ERR_ADC_IRQ_PEND     (2)
#define MASK_IRQ_STATUS_ERR_ADC_IRQ_PEND    (1 << BIT_IRQ_STATUS_ERR_ADC_IRQ_PEND)

//#if defined(__FT930__)
#define BIT_IRQ_STATUS_ERR_ADC_BUF_ERR      (6)
#define MASK_IRQ_STATUS_ERR_ADC_BUF_ERR     (1 << BIT_IRQ_STATUS_ERR_ADC_BUF_ERR)
#define BIT_IRQ_STATUS_ERR_DAC1_BUF_ERR     (5)
#define MASK_IRQ_STATUS_ERR_DAC1_BUF_ERR    (1 << BIT_IRQ_STATUS_ERR_DAC1_BUF_ERR)
#define BIT_IRQ_STATUS_ERR_DAC0_BUF_ERR     (4)
#define MASK_IRQ_STATUS_ERR_DAC0_BUF_ERR    (1 << BIT_IRQ_STATUS_ERR_DAC0_BUF_ERR)
//#endif

#define BIT_DAC_ADC_CNT_DAC_DATA_COUNT0     (0)
#define MASK_DAC_ADC_CNT_DAC_DATA_COUNT0    (0x7F << BIT_DAC_ADC_CNT_DAC_DATA_COUNT0)
#define BIT_DAC_ADC_CNT_DAC_DATA_COUNT1     (8)
#define MASK_DAC_ADC_CNT_DAC_DATA_COUNT1    (0x7F << BIT_DAC_ADC_CNT_DAC_DATA_COUNT1)
#define BIT_DAC_ADC_CNT_ADC_DATA_COUNT      (16)
#define MASK_DAC_ADC_CNT_ADC_DATA_COUNT     (0x7F << BIT_DAC_ADC_CNT_ADC_DATA_COUNT)
#define BIT_DAC_ADC_CNT_DAC_DIVIDER         (24)
#define MASK_DAC_ADC_CNT_DAC_DIVIDER        (0x7F << BIT_DAC_ADC_CNT_DAC_DIVIDER)

#define BIT_DAC_ADC_DATA_DAC_DATA0          (0)
#define MASK_DAC_ADC_DATA_DAC_DATA0         (0x3FF << BIT_DAC_ADC_DATA_DAC_DATA0)
#define BIT_DAC_ADC_DATA_ADC_DATA           (0)
#if defined(__FT930__)
#define MASK_DAC_ADC_DATA_ADC_DATA          (0xFF << BIT_DAC_ADC_DATA_ADC_DATA)
#else
#define MASK_DAC_ADC_DATA_ADC_DATA          (0x3FF << BIT_DAC_ADC_DATA_ADC_DATA)
#endif
#define BIT_DAC_ADC_DATA_DAC_DATA1          (16)
#define MASK_DAC_ADC_DATA_DAC_DATA1         (0x3FF << BIT_DAC_ADC_DATA_DAC_DATA1)

/* TYPES ***************************************************************************/

/** @brief Register mappings for DAC and ADC registers */
typedef struct
{
  volatile uint8_t  DAC_CONF;
  volatile uint8_t  ADC_CONF;
  volatile uint8_t  IRQ_CTRL;
  volatile uint8_t  IRQ_STATUS_ERR;
  volatile uint32_t DAC_ADC_CNT;
  volatile uint16_t DAC_DATA0_ADC_DATA;
  volatile uint16_t DAC_DATA1;
} ft900_adc_dac_regs_t;

typedef struct
{
  uint8_t DAC0_PDB   : 1; ///< 0 : power down DAC 0 Set to 0 if DAC 0 Is not used in the chip
                          ///< configuration
  uint8_t DAC0_CONT  : 1; ///< 1 : Enable DAC 0 continuous mode; FIFO base
  uint8_t reserved_3 : 1; ///< Reserved bit
  uint8_t DAC0_START : 1; ///< Write 1 to start DAC 0 operations.
                          ///< This bit will be automatically cleared if DAC_CONT0 = 0;
                          ///< Otherwise, if DAC_CONT0=1, DAC 0 operation runs till DAC0_START is
                          ///< cleared.
  uint8_t DAC1_PDB   : 1; ///< 0 : Power down DAC 1 Set to 0 if DAC 1 Is not used in the chip
                          ///< configuration.
  uint8_t DAC1_CONT  : 1; ///< 1 : Enable DAC 1 continuous mode; fifo base
  uint8_t reserved_6 : 1; ///< Reserved bit
  uint8_t DAC1_START : 1; ///< Write 1 to start DAC 0 operations.
                          ///< This bit will be automatically cleared if DAC_CONT0 = 0;
                          ///< Otherwise, if DAC_CONT0=1, DAC 0 operation runs till DAC0_START is
                          ///< cleared.
} dac_conf_regs_t;

typedef union
{
  dac_conf_regs_t B;
  REG_ACCESS_U8 U;
} dac_conf_regs_u;

typedef struct
{
  uint8_t ADC_CHANNEL  : 3;   ///< If ADC is not used, set these bits to 0.
                              ///<  0 : No channel is selected
                              ///<  1 : Channel 1 selected
                              ///<  2 : Channel 2 selected
                              ///<  3 : Channel 3 selected
  uint8_t ADC_PDB      : 1;   ///< Set to 0 if ADC is not used in the chip configuration.
                              ///<  0 : Power down ADC
                              ///<  1 : Power up ADC
  uint8_t ADC_CONT     : 1;   ///< 1 : Enable ADC continuous mode; When continuous mode is
                              ///< enabled, samples are loaded into the FIFO
  uint8_t ADC_EXT_VREF : 1;   ///< 1 : Enable Rail-Rail Reference. The voltage reference
                              ///< supplied externally to the chip. i.e. the voltage on ADC_VREFP.
  uint8_t reserved_6   : 1;   ///< Reserved bit
  uint8_t ADC_START    : 1;   ///< Write 1 to start ADC operations. This bit will be
                              ///< automatically cleared if ADC_CONT = 0;
                              ///< Otherwise when ADC_CONT is set, ADC operation runs till ADC_START
                              ///< is cleared
} adc_conf_regs_t;

typedef union
{
  adc_conf_regs_t B;
  REG_ACCESS_U8 U;
} adc_conf_regs_u;

typedef struct
{
  uint8_t DAC0_IRQ_EN   : 1; ///< 1 : Enable DAC 0 interrupt
  uint8_t DAC1_IRQ_EN   : 1; ///< 1 : Enable DAC 1 interrupt
  uint8_t ADC_IRQ_EN    : 1; ///< 1 : Enable ADC interrupt
  uint8_t Reserved_3_5  : 3; ///< Reserved bits
  uint8_t ADC_HALF_RATE : 1; ///< 0: ADC clock is 12.5 MHz
                             ///< 1: ADC clock is 6.25 MHz
  uint8_t ADC_8BIT_MODE : 1; ///< 0: 10-bit mode
                             ///< 1: 8-bit mode
} irq_crtl_reg_t;

typedef union
{
  irq_crtl_reg_t B;
  REG_ACCESS_U8 U;
} irq_crtl_reg_u;

typedef struct
{
  uint8_t DAC0_IRQ_PEND : 1; ///< DAC 0 Interrupt Pending when set. Write a 1 to clear this bit.
  uint8_t DAC1_IRQ_PEND : 1; ///< DAC 1 Interrupt Pending when set. Write a 1 to clear this bit.
  uint8_t ADC_IRQ_PEND  : 1; ///< ADC Interrupt Pending when set. Write a “1” to clear this bit.
  uint8_t Reserved_3    : 1; ///< Reserved bit
  uint8_t DAC0_BUF_ERR  : 1; ///< Buffer underflow/overflow error; this is sticky. Cleared by
                             ///< DAC 0 reset or DAC 0 power down.
  uint8_t DAC1_BUF_ERR  : 1; ///< Buffer underflow/overflow error; this is sticky. Cleared by
                             ///< DAC 1 reset or DAC 1 power down.
  uint8_t ADC_BUF_ERR   : 1; ///< Buffer underflow/overflow error; this is sticky. Cleared by
                             ///< ADC 1 reset or ADC 1 power down.
  uint8_t Reserved_7    : 1; ///< Reserved bit
} irq_status_err_t;

typedef union
{
  irq_status_err_t B;
  REG_ACCESS_U8 U;
} irq_status_err_u;

typedef struct
{
  uint32_t DAC0_DATA_COUNT : 8; ///< The FIFO contains the numbers of samples for conversion. This
                                ///< is equal to DAC1_DATA_COUNT plus one
  uint32_t DAC1_DATA_COUNT : 8; ///< The FIFO contains the numbers of samples for conversion. This
                                ///< is equal to  DAC1_DATA_COUNT plus one.
  uint32_t ADC_DATA_COUNT  : 8; ///< The amount of data available for reading in the ADC FIFO at the
                                ///< most recent interrupt. Note this value does not reflect the
                                ///< amount of data available in real time.
  uint32_t DAC_DIVIDER     : 7; ///< This determines the DAC 1 and DAC 0 conversion rate. The rate
                                ///< is determined by: Peripheral clock freq / (DAC_DIVIDER + 1)
                                ///< The maximum conversion rate is 1MHz.
  uint32_t Reserved_31     : 1; ///< Reserved bit
} dac_adc_cnt_t;

typedef union
{
  dac_adc_cnt_t B;
  REG_ACCESS_U32 U;
} dac_adc_cnt_u;

typedef struct
{
  /* The DAC0 and ADC data share this 10 bits space to get data, ADC use only 8 bits */
  union
  {
    uint16_t DAC0_DATA : 10;    ///< DAC 0 Data write window for DAC 0 FIFO; If byte access is used,
                                ///< a write to the FIFO occurs only when the high byte is written.
                                ///< Hence the upper bits should be written last in this case
    uint16_t ADC_DATA  : 8;     ///< ADC Data read window from FIFO for ADC.
  } DAC0_ADC_DATA;

  uint16_t Reserved_10_15 : 6;  ///< Reserved bits
} dac0_adc_data_t;

typedef union
{
  dac0_adc_data_t B;
  REG_ACCESS_U16 U;
} dac0_adc_data_u;

typedef struct
{
  uint16_t DAC1_DATA      : 10; ///< DAC 1 Data write window for DAC 1 FIFO; If byte access is used,
                                ///< a write to the FIFO occurs only when the high byte is written.
                                ///< Hence the upper bits should be written last in this case.
  uint16_t Reserved_11_15 : 6;  ///< Reserved bits
} dac1_data_t;

typedef union
{
  dac1_data_t    B;
  REG_ACCESS_U16 U;
} dac1_data_u;

/** @brief Register mappings for DAC and ADC registers */
typedef struct
{
  __IO dac_conf_regs_u  DAC_CONF;
  __IO adc_conf_regs_u  ADC_CONF;
  __IO irq_crtl_reg_u   IRQ_CRTL;
  __IO irq_status_err_u IRQ_STATUS_ERR;
  __IO dac_adc_cnt_u    DAC_ADC_CNT;
  __IO dac0_adc_data_u  DAC0_ADC_DATA;
  __IO dac1_data_u      DAC1_DATA;
} adc_dac_regs_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#endif /* FT900_ADC_DAC_REGISTERS_H_ */
