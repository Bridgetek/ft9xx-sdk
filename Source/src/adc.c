/**
    @file adc.c

    @brief  Analogue to Digital Converter
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

/* INCLUDES ************************************************************************/

#include <ft900_adc.h>
#include <ft900_asm.h>
#include <registers/ft900_registers.h>
#include <ft900_sys.h>

/* CONSTANTS ***********************************************************************/

/* GLOBAL VARIABLES ****************************************************************/

/* LOCAL VARIABLES *****************************************************************/

/* MACROS **************************************************************************/

#if defined(__FT930__)
#define ADC_MAX_CHANNEL 3
#else
#define ADC_MAX_CHANNEL 7
#endif

/* LOCAL FUNCTIONS / INLINES *******************************************************/

/* FUNCTIONS ***********************************************************************/

/** @brief Select ADC resolution.
 *  @param [in] resolution - The resolution(10bit/8bit)
 *  @returns On success a 0, otherwise -1
 *  @warning This feature is only supported in FT900 revision C
 */
int8_t adc_select_resolution(adc_resolution_t resolution)
{
  uint8_t iRet = 0;

#if defined(__FT900__)
  /* Resolution switching is only supported in FT900 revision C */
  if (sys_check_ft900_revB()) // 90x series rev B
  {
    iRet = -1;
  }
  else
  {
    if (resolution == adc_8bit)
    {
      ADCDAC_N->IRQ_CRTL.B.ADC_8BIT_MODE = ADC_8BIT_ENABLE;
    }
    else if (resolution == adc_10bit)
    {
      ADCDAC_N->IRQ_CRTL.B.ADC_8BIT_MODE = ADC_10BIT_ENABLE;
    }
    else
    {
      iRet = -1;
    }
  }
#else
  (void)resolution;
  iRet = -1;
#endif

  return iRet;
}

/** @brief Select ADC frequency.
 *  @param [in] frequency - The frequency(12.5MHz/6.25MHz)
 *  @returns On success a 0, otherwise -1
 *  @warning This feature is only supported in FT900 revision C
 */
int8_t adc_select_frequency(adc_clock_t frequency)
{
  uint8_t iRet = 0;

#if defined(__FT900__)
  /* frequency switching is only supported in FT900 revision C */
  if (sys_check_ft900_revB()) // 90x series rev B
  {
    iRet = -1;
  }
  else
  {
    if (frequency == adc_6_25_MHz)
    {
      ADCDAC_N->IRQ_CRTL.B.ADC_HALF_RATE = adc_6_25_MHz;
    }
    else if (frequency == adc_12_5_MHz)
    {
      ADCDAC_N->IRQ_CRTL.B.ADC_HALF_RATE = adc_12_5_MHz;
    }
    else
    {
      iRet = -1;
    }
  }
#else
  (void)frequency;
  iRet = -1;
#endif
  return iRet;
}

/** @brief Choose the mode that the ADC will run in
 *  @param [in] mode - The mode (single or continuous)
 *  @returns 0 on success, -1 otherwise
 */
int8_t adc_mode(adc_mode_t mode)
{
  int8_t iRet = 0;

  if (mode == adc_mode_continuous)
  {
    ADCDAC_N->ADC_CONF.B.ADC_CONT = adc_mode_continuous;
  }
  else if (mode == adc_mode_single)
  {
    ADCDAC_N->ADC_CONF.B.ADC_CONT = adc_mode_single;
  }
  else
  {
    iRet = -1;
  }

  return iRet;
}

/** @brief Start the ADC capturing
 *  @param [in] channel - The channel to select
 *  @returns 0 on success, -1 otherwise
 */
int8_t adc_start(uint8_t channel)
{
  int8_t iRet = 0;

  if (channel == 0 || channel > ADC_MAX_CHANNEL)
  {
    iRet = -1;
  }

  if (iRet == 0)
  {
    ADCDAC_N->ADC_CONF.B.ADC_START = ADC_DISABLE;
    ADCDAC_N->ADC_CONF.B.ADC_CHANNEL = channel;
    ADCDAC_N->ADC_CONF.B.ADC_START = ADC_ENABLE;
  }

  return iRet;
}

/** @brief Stop the ADC from capturing
 *  @returns 0 on success, -1 otherwise
 */
int8_t adc_stop(void)
{
  int8_t iRet = 0;

  if (ADCDAC_N->ADC_CONF.B.ADC_START)
  {
    ADCDAC_N->ADC_CONF.B.ADC_START   = ADC_DISABLE;
    ADCDAC_N->ADC_CONF.B.ADC_CHANNEL = ADC_CHANNEL_NONE;
  }
  else
  {
    iRet = -1;
  }

  return iRet;
}

/** @brief Get the number of ADC samples available
 *  @warning This function should only be called when ADC continuous mode is enabled,
 *           and should be called inside ISR context.
 *  @returns The number of ADC samples available in FIFO
 */
uint8_t adc_available(void)
{
  /* ADC counter always return 1 sample less, so we need to increment by 1 sample */
  return ADCDAC_N->DAC_ADC_CNT.B.ADC_DATA_COUNT + 1;
}

/** @brief Get the next sample from the ADC
 *  @param val A pointer to store the sample
 *  @returns The number of samples read, -1 otherwise
 */
int8_t adc_read(uint16_t *val)
{
  asm_streamin16(&ADCDAC_N->DAC0_ADC_DATA, val, 2);
  return 1;
}

/** @brief Get a collection of samples from the ADC
 *  @param [in] val - An array pointer to store the samples
 *  @param [in] len - The length of the array
 *  @warning This function will only work when the ADC is in continuous mode
 *  @returns The number of samples read, -1 otherwise
 */
int adc_readn(uint16_t *val, size_t len)
{
  int iRet = 0;
  size_t iAvailable = 0;
  uint8_t isContinuousMode = ADCDAC_N->ADC_CONF.B.ADC_CONT;

  if (isContinuousMode)
  {
    /* Make sure we only read what we can */
    iAvailable = (size_t)adc_available();
    if (iAvailable < len)
    {
      len = iAvailable;
    }
    asm_streamin16(&ADCDAC_N->DAC0_ADC_DATA, val, len * 2);
    iRet = len;
  }
  else
  {
    /* Not in continuous mode */
    iRet = -1;
  }

  return iRet;
}

/** @brief Enable the Interrupt on the ADC
 *  @returns 0 on success, -1 otherwise
 */
int8_t adc_enable_interrupt(void)
{
  ADCDAC_N->IRQ_CRTL.B.ADC_IRQ_EN = ADC_ENABLE;
  return 0;
}

/** @brief Disable the Interrupt on the ADC
 *  @returns 0 on success, -1 otherwise
 */
int8_t adc_disable_interrupt(void)
{
  ADCDAC_N->IRQ_CRTL.B.ADC_IRQ_EN = ADC_DISABLE;
  return 0;
}

/** @brief Check that the ADC has been interrupted
 *  @warning This function will clear the current interrupt bit when called
 *  @returns 1 interrupted, 0 not interrupted
 */
int8_t adc_is_interrupted(void)
{
  int8_t iRet = 0;

  if (ADCDAC_N->IRQ_STATUS_ERR.B.ADC_IRQ_PEND)
  {
    ADCDAC_N->IRQ_STATUS_ERR.B.ADC_IRQ_PEND = ADC_ENABLE;
    iRet = 1;
  }

  return iRet;
}

/** @brief Enable the ADC rail to rail mode
 *  @returns None
 */
void adc_enable_rail_rail(void)
{
  ADCDAC_N->ADC_CONF.B.ADC_EXT_VREF = ADC_ENABLE;
}

/** @brief Disable the ADC rail to rail mode
 *  @returns None
 */
void adc_disable_rail_rail(void)
{
  ADCDAC_N->ADC_CONF.B.ADC_EXT_VREF = ADC_DISABLE;
}
