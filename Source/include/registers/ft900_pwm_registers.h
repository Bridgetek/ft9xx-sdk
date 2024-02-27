/**
    @file ft900_pwm_registers.h

    @brief Pulse Width Modulation registers
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

#ifndef FT900_PWM_REGISTERS_H_
#define FT900_PWM_REGISTERS_H_

/* INCLUDES ************************************************************************/

#include <stdint.h>
#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

#define BIT_PWM_CTRL0_SOFTRESET      (0)
#define MASK_PWM_CTRL0_SOFTRESET     (1 << BIT_PWM_CTRL0_SOFTRESET)
#define BIT_PWM_CTRL0_AUDIOEN        (2)
#define MASK_PWM_CTRL0_AUDIOEN       (1 << BIT_PWM_CTRL0_AUDIOEN)
#define BIT_PWM_CTRL0_AUDIOFILTER    (3)
#define MASK_PWM_CTRL0_AUDIOFILTER   (1 << BIT_PWM_CTRL0_AUDIOFILTER)
#define BIT_PWM_CTRL0_AUDIOSCALE     (4)
#define MASK_PWM_CTRL0_AUDIOSCALE    (1 << BIT_PWM_CTRL0_AUDIOSCALE)
#define BIT_PWM_CTRL0_AUDIO8BIT      (5)
#define MASK_PWM_CTRL0_AUDIO8BIT     (1 << BIT_PWM_CTRL0_AUDIO8BIT)
#define BIT_PWM_CTRL0_AUDIOMONO      (6)
#define MASK_PWM_CTRL0_AUDIOMONO     (1 << BIT_PWM_CTRL0_AUDIOMONO)
#define BIT_PWM_CTRL0_AUDIOFIFO      (7)
#define MASK_PWM_CTRL0_AUDIOFIFO     (1 << BIT_PWM_CTRL0_AUDIOFIFO)

#define BIT_PWM_CTRL1_PWMEN          (0)
#define MASK_PWM_CTRL1_PWMEN         (1 << BIT_PWM_CTRL1_PWMEN)
#define BIT_PWM_CTRL1_PWMTRIG        (1)
#define MASK_PWM_CTRL1_PWMTRIG       (0x3 << BIT_PWM_CTRL1_PWMTRIG)
#define BIT_PWM_CTRL1_PWMBUSY        (3)
#define MASK_PWM_CTRL1_PWMBUSY       (1 << BIT_PWM_CTRL1_PWMBUSY)
#define BIT_PWM_CTRL1_PWMINTMASK     (4)
#define MASK_PWM_CTRL1_PWMINTMASK    (1 << BIT_PWM_CTRL1_PWMINTMASK)
#define BIT_PWM_CTRL1_PWMINT         (5)
#define MASK_PWM_CTRL1_PWMINT        (1 << BIT_PWM_CTRL1_PWMINT)
#define BIT_PWM_CTRL1_PCMENDIAN      (6)
#define MASK_PWM_CTRL1_PCMENDIAN     (1 << BIT_PWM_CTRL1_PCMENDIAN)

#define BIT_PWM_INTMASK_INTMASK      (0)
#define MASK_PWM_INTMASK_INTMASK     (1 << BIT_PWM_INTMASK_INTMASK)
#define BIT_PWM_INTMASK_FIFOUNDER    (1)
#define MASK_PWM_INTMASK_FIFOUNDER   (1 << BIT_PWM_INTMASK_FIFOUNDER)
#define BIT_PWM_INTMASK_FIFOOVER     (2)
#define MASK_PWM_INTMASK_FIFOOVER    (1 << BIT_PWM_INTMASK_FIFOOVER)
#define BIT_PWM_INTMASK_FIFOHALF     (3)
#define MASK_PWM_INTMASK_FIFOHALF    (1 << BIT_PWM_INTMASK_FIFOHALF)
#define BIT_PWM_INTMASK_FIFOFULL     (4)
#define MASK_PWM_INTMASK_FIFOFULL    (1 << BIT_PWM_INTMASK_FIFOFULL)
#define BIT_PWM_INTMASK_FIFOEMPTY    (5)
#define MASK_PWM_INTMASK_FIFOEMPTY   (1 << BIT_PWM_INTMASK_FIFOEMPTY)

#define BIT_PWM_INTSTATUS_INTMASK    (0)
#define MASK_PWM_INTSTATUS_INTMASK   (1 << BIT_PWM_INTSTATUS_INTMASK)
#define BIT_PWM_INTSTATUS_FIFOUNDER  (1)
#define MASK_PWM_INTSTATUS_FIFOUNDER (1 << BIT_PWM_INTSTATUS_FIFOUNDER)
#define BIT_PWM_INTSTATUS_FIFOOVER   (2)
#define MASK_PWM_INTSTATUS_FIFOOVER  (1 << BIT_PWM_INTSTATUS_FIFOOVER)
#define BIT_PWM_INTSTATUS_FIFOHALF   (3)
#define MASK_PWM_INTSTATUS_FIFOHALF  (1 << BIT_PWM_INTSTATUS_FIFOHALF)
#define BIT_PWM_INTSTATUS_FIFOFULL   (4)
#define MASK_PWM_INTSTATUS_FIFOFULL  (1 << BIT_PWM_INTSTATUS_FIFOFULL)
#define BIT_PWM_INTSTATUS_FIFOEMPTY  (5)
#define MASK_PWM_INTSTATUS_FIFOEMPTY (1 << BIT_PWM_INTSTATUS_FIFOEMPTY)

#define BIT_PCM_VOLUME_VOLUME        (0)
#define MASK_PCM_VOLUME_VOLUME       (0x1F << BIT_PWM_VOLUME_VOLUME)

/* TYPES ***************************************************************************/

/** \brief PCM Control Register */
typedef struct
{
  uint8_t PWM_SOFT_RESET  : 1;    ///< Set to 1 to reset PWM.

  uint8_t PWM_DEV_EN      : 1;    ///< Set to 1 to enable PWM. This bit is not really used.

  uint8_t PCM_EN          : 1;    ///< Set to 1 if channel 0 and channel 1 are used for PCM playback.

  uint8_t PWM_CH01_FILTER : 1;    ///< Set to 1 if PCM filter is required. This is valid only
                                  ///< with PWM_CH01_AUTO and PCM_EN set.

  uint8_t PWM_CH01_SCALE  : 1;    ///< Set to 1 if automatic scaling of data is required.

  uint8_t PWM_CH01_8BIT   : 1;    ///< Set to 1 for 8-bit audio data.

  uint8_t PWM_CH01_MONO   : 1;    ///< Set to 1 for mono audio. Both channels will playback
                                  ///< the same data.

  uint8_t PWM_CH01_AUTO   : 1;    ///< Set to 1 to use channels 0 & 1 for audio playback via
                                  ///< the internal FIFO.
} pwm_ctrl0_reg_t;

/** \brief PCM Control Register */
typedef union
{
  pwm_ctrl0_reg_t B;
  REG_ACCESS_U8   U;
} pwm_ctrl0_reg_u;

/** \brief PWM Control Register */
typedef struct
{
  uint8_t PWM_EN           : 1;   ///< Set to 1 to enable PWM.

  uint8_t PWM_TRIGGER_EN   : 2;   ///< PWM trigger enable:
                                  ///<     | 00 | Disabled      |
                                  ///<     | 01 | Positive Edge |
                                  ///<     | 10 | Negative Edge |
                                  ///<     | 11 | Any Edge      |

  uint8_t PWM_BUSY         : 1;   ///< Is the PWM is busy

  uint8_t PWM_INT_MASK     : 1;   ///< Interrupt mask bit for PWM_INT

  uint8_t PWM_INT          : 1;   ///< PWM Interrupt

  uint8_t PCM_BIYTEREVERSE : 1;   ///< 0: Data is treated as in big endian format
                                  ///<    For 8-bit, this has no effect.
                                  ///< 1: Data is treated as in little endian format
                                  ///<    For 8-bit, this has no effect.
                                  ///<    For 16-bit, the lower and upper bytes are swapped.

  uint8_t Reserved         : 1;   ///< Reserved
} pwm_ctrl1_reg_t;

/** \brief PWM Control Register */
typedef union
{
  pwm_ctrl1_reg_t B;
  REG_ACCESS_U8   U;
} pwm_ctrl1_reg_u;

/** \brief PWM Pre-scaler Register */
typedef struct
{
  uint8_t PRESCALER;    ///< 8-bit Pre-scaler value. The actual prescaler value is (PRESCALER + 1).
} pwm_prescaler_reg_t;

/** \brief PWM Pre-scaler Register */
typedef union
{
  pwm_prescaler_reg_t B;
  REG_ACCESS_U8       U;
} pwm_prescaler_reg_u;

/** \brief PWM Counter Register (LSB) */
typedef struct
{
  uint8_t CNT16_LSB;    ///< 16-bit counter LSB. The actual counter value is:
                        ///<    (CNT16_MSB << 8) + CNT16_LSB + 1
} pwm_cntl_reg_t;

/** \brief PWM Counter Register (LSB) */
typedef union
{
  pwm_cntl_reg_t B;
  REG_ACCESS_U8  U;
} pwm_cntl_reg_u;

/** \brief PWM Counter Register (MSB) */
typedef struct
{
  uint8_t CNT16_MSB;    ///< 16-bit counter MSB.
} pwm_cnth_reg_t;

/** \brief PWM Counter Register (MSB) */
typedef union
{
  pwm_cnth_reg_t B;
  REG_ACCESS_U8  U;
} pwm_cnth_reg_u;

/** \brief Comparator 0 Value Register (LSB) */
typedef struct
{
  uint8_t CMP16_0_LSB;  ///< LSB of comparator 0 16-bit value.
} pwm_cmp0l_reg_t;

/** \brief Comparator 0 Value Register (LSB) */
typedef union
{
  pwm_cmp0l_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp0l_reg_u;

/** \brief Comparator 0 Value Register (MSB) */
typedef struct
{
  uint8_t CMP16_0_MSB;  ///< MSB of comparator 0 16-bit value.
} pwm_cmp0h_reg_t;

/** \brief Comparator 0 Value Register (MSB) */
typedef union
{
  pwm_cmp0h_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp0h_reg_u;

/** \brief Comparator 1 Value Register (LSB) */
typedef struct
{
  uint8_t CMP16_1_LSB;  ///< LSB of comparator 1 16-bit value.
} pwm_cmp1l_reg_t;

/** \brief Comparator 1 Value Register (LSB) */
typedef union
{
  pwm_cmp1l_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp1l_reg_u;

/** \brief Comparator 1 Value Register (MSB) */
typedef struct
{
  uint8_t CMP16_1_MSB;  ///< MSB of comparator 1 16-bit value.
} pwm_cmp1h_reg_t;

/** \brief Comparator 1 Value Register (MSB) */
typedef union
{
  pwm_cmp1h_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp1h_reg_u;

/** \brief Comparator 2 Value Register (LSB) */
typedef struct
{
  uint8_t CMP16_2_LSB;  ///< LSB of comparator 2 16-bit value.
} pwm_cmp2l_reg_t;

/** \brief Comparator 2 Value Register (LSB) */
typedef union
{
  pwm_cmp2l_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp2l_reg_u;

/** \brief Comparator 2 Value Register (MSB) */
typedef struct
{
  uint8_t CMP16_2_MSB;  ///< MSB of comparator 2 16-bit value.
} pwm_cmp2h_reg_t;

/** \brief Comparator 2 Value Register (MSB) */
typedef union
{
  pwm_cmp2h_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp2h_reg_u;

/** \brief Comparator 3 Value Register (LSB) */
typedef struct
{
  uint8_t CMP16_3_LSB;  ///< LSB of comparator 3 16-bit value.
} pwm_cmp3l_reg_t;

typedef union
{
  pwm_cmp3l_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp3l_reg_u;

/** \brief Comparator 3 Value Register (MSB) */
typedef struct
{
  uint8_t CMP16_3_MSB;  ///< MSB of comparator 3 16-bit value.
} pwm_cmp3h_reg_t;

/** \brief Comparator 3 Value Register (MSB) */
typedef union
{
  pwm_cmp3h_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp3h_reg_u;

/** \brief Comparator 4 Value Register (LSB) */
typedef struct
{
  uint8_t CMP16_4_LSB;  ///< LSB of comparator 4 16-bit value.
} pwm_cmp4l_reg_t;

/** \brief Comparator 4 Value Register (LSB) */
typedef union
{
  pwm_cmp4l_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp4l_reg_u;

/** \brief Comparator 4 Value Register (MSB) */
typedef struct
{
  uint8_t CMP16_4_MSB;  ///< MSB of comparator 4 16-bit value.
} pwm_cmp4h_reg_t;

/** \brief Comparator 4 Value Register (MSB) */
typedef union
{
  pwm_cmp4h_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp4h_reg_u;

/** \brief Comparator 5 Value Register (LSB) */
typedef struct
{
  uint8_t CMP16_5_LSB;  ///< LSB of comparator 5 16-bit value.
} pwm_cmp5l_reg_t;

/** \brief Comparator 5 Value Register (LSB) */
typedef union
{
  pwm_cmp5l_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp5l_reg_u;

/** \brief Comparator 5 Value Register (MSB) */
typedef struct
{
  uint8_t CMP16_5_MSB;  ///< MSB of comparator 5 16-bit value.
} pwm_cmp5h_reg_t;

/** \brief Comparator 5 Value Register (MSB) */
typedef union
{
  pwm_cmp5h_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp5h_reg_u;

/** \brief Comparator 6 Value Register (LSB) */
typedef struct
{
  uint8_t CMP16_6_LSB;  ///< LSB of comparator 6 16-bit value.
} pwm_cmp6l_reg_t;

/** \brief Comparator 6 Value Register (LSB) */
typedef union
{
  pwm_cmp6l_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp6l_reg_u;

/** \brief Comparator 6 Value Register (MSB) */
typedef struct
{
  uint8_t CMP16_6_MSB;  ///< MSB of comparator 6 16-bit value.
} pwm_cmp6h_reg_t;

/** \brief Comparator 6 Value Register (MSB) */
typedef union
{
  pwm_cmp6h_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp6h_reg_u;

/** \brief Comparator 6 Value Register (LSB) */
typedef struct
{
  uint8_t CMP16_7_LSB;  ///< LSB of comparator 7 16-bit value.
} pwm_cmp7l_reg_t;

/** \brief Comparator 6 Value Register (LSB) */
typedef union
{
  pwm_cmp7l_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp7l_reg_u;

/** \brief Comparator 7 Value Register (MSB) */
typedef struct
{
  uint8_t CMP16_7_MSB;  ///< MSB of comparator 7 16-bit value.
} pwm_cmp7h_reg_t;

/** \brief Comparator 7 Value Register (MSB) */
typedef union
{
  pwm_cmp7h_reg_t B;
  REG_ACCESS_U8   U;
} pwm_cmp7h_reg_u;

/** \brief Channel 0 OUT Toggle Comparator Mask Register */
typedef struct
{
  uint8_t TOGGLE_EN_0;  ///< Channel 0 PWM OUT toggle comparator mask (each bit corresponds to
                        ///< 1 comparator)
} pwd_toggle_0_reg_t;

/** \brief Channel 0 OUT Toggle Comparator Mask Register */
typedef union
{
  pwd_toggle_0_reg_t B;
  REG_ACCESS_U8      U;
} pwd_toggle_0_reg_u;

/** \brief Channel 1 OUT Toggle Comparator Mask Register */
typedef struct
{
  uint8_t TOGGLE_EN_1;  ///< Channel 1 PWM OUT toggle comparator mask (each bit corresponds to
                        ///< 1 comparator)
} pwd_toggle_1_reg_t;

/** \brief Channel 1 OUT Toggle Comparator Mask Register */
typedef union
{
  pwd_toggle_1_reg_t B;
  REG_ACCESS_U8      U;
} pwd_toggle_1_reg_u;

/** \brief Channel 2 OUT Toggle Comparator Mask Register */
typedef struct
{
  uint8_t TOGGLE_EN_2;  ///< Channel 2 PWM OUT toggle comparator mask (each bit corresponds to
                        ///< 1 comparator)
} pwd_toggle_2_reg_t;

/** \brief Channel 2 OUT Toggle Comparator Mask Register */
typedef union
{
  pwd_toggle_2_reg_t B;
  REG_ACCESS_U8      U;
} pwd_toggle_2_reg_u;

/** \brief Channel 3 OUT Toggle Comparator Mask Register */
typedef struct
{
  uint8_t TOGGLE_EN_3;  ///< Channel 3 PWM OUT toggle comparator mask (each bit corresponds to
                        ///< 1 comparator)
} pwd_toggle_3_reg_t;

/** \brief Channel 3 OUT Toggle Comparator Mask Register */
typedef union
{
  pwd_toggle_3_reg_t B;
  REG_ACCESS_U8      U;
} pwd_toggle_3_reg_u;

/** \brief Channel 4 OUT Toggle Comparator Mask Register */
typedef struct
{
  uint8_t TOGGLE_EN_4;  ///< Channel 4 PWM OUT toggle comparator mask (each bit corresponds to
                        ///< 1 comparator)
} pwd_toggle_4_reg_t;

/** \brief Channel 4 OUT Toggle Comparator Mask Register */
typedef union
{
  pwd_toggle_4_reg_t B;
  REG_ACCESS_U8      U;
} pwd_toggle_4_reg_u;

/** \brief Channel 5 OUT Toggle Comparator Mask Register */
typedef struct
{
  uint8_t TOGGLE_EN_5;  ///< Channel 5 PWM OUT toggle comparator mask (each bit corresponds to
                        ///< 1 comparator)
} pwd_toggle_5_reg_t;

/** \brief Channel 5 OUT Toggle Comparator Mask Register */
typedef union
{
  pwd_toggle_5_reg_t B;
  REG_ACCESS_U8      U;
} pwd_toggle_5_reg_u;

/** \brief Channel 6 OUT Toggle Comparator Mask Register */
typedef struct
{
  uint8_t TOGGLE_EN_6;  ///< Channel 6 PWM OUT toggle comparator mask (each bit corresponds to
                        ///< 1 comparator)
} pwd_toggle_6_reg_t;


/** \brief Channel 6 OUT Toggle Comparator Mask Register */
typedef union
{
  pwd_toggle_6_reg_t B;
  REG_ACCESS_U8      U;
} pwd_toggle_6_reg_u;

/** \brief Channel 7 OUT Toggle Comparator Mask Register */
typedef struct
{
  uint8_t TOGGLE_EN_7;  ///< Channel 7 PWM OUT toggle comparator mask (each bit corresponds to
                        ///< 1 comparator)
} pwd_toggle_7_reg_t;

/** \brief Channel 7 OUT Toggle Comparator Mask Register */
typedef union
{
  pwd_toggle_7_reg_t B;
  REG_ACCESS_U8      U;
} pwd_toggle_7_reg_u;

/** \brief PWM OUT Clear Enable Register */
typedef struct
{
  uint8_t CLR_EN;       ///< PWM Out clear enable
} pwd_out_clr_en_reg_t;

/** \brief PWM OUT Clear Enable Register */
typedef union
{
  pwd_out_clr_en_reg_t B;
  REG_ACCESS_U8        U;
} pwd_out_clr_en_reg_u;

/** \brief Control Block CMP8 Value Register */
typedef struct
{
  uint8_t CTRL_BL_CMP8; ///< Control block CMP8 value.
                        ///<    0: Continuous
                        ///<    1: One-shot, 2 - 255
} pwd_ctrl_bl_cmp8_reg_t;

/** \brief Control Block CMP8 Value Register */
typedef union
{
  pwd_ctrl_bl_cmp8_reg_t B;
  REG_ACCESS_U8          U;
} pwd_ctrl_bl_cmp8_reg_u;

/** \brief PWM Initialization Register */
typedef struct
{
  uint8_t INIT;         ///< PWM Initialisation register
} pwd_init_reg_t;

/** \brief PWM Initialization Register */
typedef union
{
  pwd_init_reg_t B;
  REG_ACCESS_U8  U;
} pwd_init_reg_u;

/** \brief PWM Interrupt Mask Register */
typedef struct
{
  uint8_t PWM_INT_MASK    : 1;  ///< PWM_INT interrupt mask (same as bit[4] of PWM_CTRL)
  uint8_t FIFO_UNDER_MASK : 1;  ///< FIFO underflow interrupt mask
  uint8_t FIFO_OV_MASK    : 1;  ///< FIFO overflow interrupt mask
  uint8_t FIFO_HALF_MASK  : 1;  ///< FIFO half full interrupt mask
  uint8_t FIFO_FULL_MASK  : 1;  ///< FIFO full interrupt mask
  uint8_t FIFO_EMPTY_MASK : 1;  ///< FIFO empty interrupt mask
  uint8_t Reserved        : 2;  ///< Reserved
} pwm_int_mask_reg_t;

/** \brief PWM Interrupt Mask Register */
typedef union
{
  pwm_int_mask_reg_t B;
  REG_ACCESS_U8      U;
} pwm_int_mask_reg_u;

/** \brief PWM Interrupt Status Register */
typedef struct
{
  uint8_t PWM_INT    : 1;  ///< PWM interrupt; write 1 to clear. (same as bit[5] of PWM_CTRL1)
  uint8_t FIFO_UNDER : 1;  ///< FIFO underflow interrupt; write 1 to clear.
  uint8_t FIFO_OV    : 1;  ///< FIFO overflow interrupt mask; write 1 to clear.
  uint8_t FIFO_HALF  : 1;  ///< FIFO half full interrupt mask; write 1 to clear.
  uint8_t FIFO_FULL  : 1;  ///< FIFO full interrupt mask; write 1 to clear.
  uint8_t FIFO_EMPTY : 1;  ///< FIFO empty interrupt mask; write 1 to clear.
  uint8_t Reserved   : 2;  ///< Reserved
} pwm_int_sts_reg_t;

/** \brief PWM Interrupt Status Register */
typedef union
{
  pwm_int_sts_reg_t B;
  REG_ACCESS_U8     U;
} pwm_int_sts_reg_u;

/** \brief PWM Data Sampling Frequency High Byte Register */
typedef struct
{
  uint8_t PWM_SAMPLE_FREQ_H;  ///< PWM Data Sampling Frequency High Byte
} pwm_samp_freq_h_reg_t;

/** \brief PWM Data Sampling Frequency High Byte Register */
typedef union
{
  pwm_samp_freq_h_reg_t B;
  REG_ACCESS_U8         U;
} pwm_samp_freq_h_reg_u;

/** \brief PWM Data Sampling Frequency Low Byte Register */
typedef struct
{
  uint8_t PWM_SAMPLE_FREQ_L;  ///< PWM Data Sampling Frequency Low Byte
} pwm_samp_freq_l_reg_t;

/** \brief PWM Data Sampling Frequency Low Byte Register */
typedef union
{
  pwm_samp_freq_l_reg_t B;
  REG_ACCESS_U8         U;
} pwm_samp_freq_l_reg_u;

/** \brief PCM Volume Register */
typedef struct
{
  uint8_t Volume_Control : 5; ///< | 0x01      | ~6.25%                  |
                              ///< | 0x02      | ~12.5%                  |
                              ///< | 0x03      | ~19%                    |
                              ///< | 0x04      | ~25%                    |
                              ///< | 0x05      | ~31%                    |
                              ///< | 0x06      | ~37%                    |
                              ///< | 0x07      | ~44%                    |
                              ///< | 0x08      | ~50%                    |
                              ///< | 0x09      | ~56%                    |
                              ///< | 0x0A      | ~63%                    |
                              ///< | 0x0B      | ~69%                    |
                              ///< | 0x0C      | ~75%                    |
                              ///< | 0x0D      | ~81%                    |
                              ///< | 0x0E      | ~88%                    |
                              ///< | 0x0F      | ~94%                    |
                              ///< | 0x10      | ~100%                   |
                              ///< | 0x11-0x1F | Illegal; forced to 0x10 |

  uint8_t Reserved       : 3; ///< Reserved
} pwm_pcm_volume_reg_t;

/** \brief PCM Volume Register */
typedef union
{
  pwm_pcm_volume_reg_t B;
  REG_ACCESS_U8        U;
} pwm_pcm_volume_reg_u;

/** \brief PCM Buffer Register */
typedef struct
{
  uint16_t Buffer_Data;       ///< The entry point to the FIFO. It must be written in 16-bit. For
                              ///< 8-bit data, the upper 8-bit will be ignored.
} pwm_buff_reg_t;

/** \brief PCM Buffer Register */
typedef union
{
  pwm_buff_reg_t B;
  REG_ACCESS_U8  U;
} pwm_buff_reg_u;

/** @brief Registers mappings for PWM and PWM Audio registers */
typedef struct
{
  __IO pwm_ctrl0_reg_u        PWM_CTRL0;
  __IO pwm_ctrl1_reg_u        PWM_CTRL1;
  __IO pwm_prescaler_reg_u    PWM_PRESCALER;
  __IO pwm_cntl_reg_u         PWM_CNTL;
  __IO pwm_cnth_reg_u         PWM_CNTH;
  __IO pwm_cmp0l_reg_u        PWM_CMP0L;
  __IO pwm_cmp0h_reg_u        PWM_CMP0H;
  __IO pwm_cmp1l_reg_u        PWM_CMP1L;
  __IO pwm_cmp1h_reg_u        PWM_CMP1H;
  __IO pwm_cmp2l_reg_u        PWM_CMP2L;
  __IO pwm_cmp2h_reg_u        PWM_CMP2H;
  __IO pwm_cmp3l_reg_u        PWM_CMP3L;
  __IO pwm_cmp3h_reg_u        PWM_CMP3H;
  __IO pwm_cmp4l_reg_u        PWM_CMP4L;
  __IO pwm_cmp4h_reg_u        PWM_CMP4H;
  __IO pwm_cmp5l_reg_u        PWM_CMP5L;
  __IO pwm_cmp5h_reg_u        PWM_CMP5H;
  __IO pwm_cmp6l_reg_u        PWM_CMP6L;
  __IO pwm_cmp6h_reg_u        PWM_CMP6H;
  __IO pwm_cmp7l_reg_u        PWM_CMP7L;
  __IO pwm_cmp7h_reg_u        PWM_CMP7H;
  __IO pwd_toggle_0_reg_u     PWM_TOGGLE_0;
  __IO pwd_toggle_1_reg_u     PWM_TOGGLE_1;
  __IO pwd_toggle_2_reg_u     PWM_TOGGLE_2;
  __IO pwd_toggle_3_reg_u     PWM_TOGGLE_3;
  __IO pwd_toggle_4_reg_u     PWM_TOGGLE_4;
  __IO pwd_toggle_5_reg_u     PWM_TOGGLE_5;
  __IO pwd_toggle_6_reg_u     PWM_TOGGLE_6;
  __IO pwd_toggle_7_reg_u     PWM_TOGGLE_7;
  __IO pwd_out_clr_en_reg_u   PWM_OUT_CLR_EN;
  __IO pwd_ctrl_bl_cmp8_reg_u PWM_CTRL_BL_CMP8;
  __IO pwd_init_reg_u         PWM_INIT;
  __IO pwm_int_mask_reg_u     PWM_INT_MASK;
  __IO pwm_int_sts_reg_u      PWM_INT_STATUS;
  __IO pwm_samp_freq_h_reg_u  PWM_SAMPLE_FREQ_H;
  __IO pwm_samp_freq_l_reg_u  PWM_SAMPLE_FREQ_L;
  __IO pwm_pcm_volume_reg_u   PCM_VOLUME;
       uint8_t                Reserved[23];
  __IO pwm_buff_reg_u         PWM_BUFFER;
} pwm_regs_t;

/** @brief Registers mappings for PWM and PWM Audio registers */
typedef struct
{
  __IO uint8_t  PWM_CTRL0;
  __IO uint8_t  PWM_CTRL1;
  __IO uint8_t  PWM_PRESCALER;
  __IO uint8_t  PWM_CNTL;
  __IO uint8_t  PWM_CNTH;
  __IO uint8_t  PWM_CMP0L;
  __IO uint8_t  PWM_CMP0H;
  __IO uint8_t  PWM_CMP1L;
  __IO uint8_t  PWM_CMP1H;
  __IO uint8_t  PWM_CMP2L;
  __IO uint8_t  PWM_CMP2H;
  __IO uint8_t  PWM_CMP3L;
  __IO uint8_t  PWM_CMP3H;
  __IO uint8_t  PWM_CMP4L;
  __IO uint8_t  PWM_CMP4H;
  __IO uint8_t  PWM_CMP5L;
  __IO uint8_t  PWM_CMP5H;
  __IO uint8_t  PWM_CMP6L;
  __IO uint8_t  PWM_CMP6H;
  __IO uint8_t  PWM_CMP7L;
  __IO uint8_t  PWM_CMP7H;
  __IO uint8_t  PWM_TOGGLE0;
  __IO uint8_t  PWM_TOGGLE1;
  __IO uint8_t  PWM_TOGGLE2;
  __IO uint8_t  PWM_TOGGLE3;
  __IO uint8_t  PWM_TOGGLE4;
  __IO uint8_t  PWM_TOGGLE5;
  __IO uint8_t  PWM_TOGGLE6;
  __IO uint8_t  PWM_TOGGLE7;
  __IO uint8_t  PWM_OUT_CLR_EN;
  __IO uint8_t  PWM_CTRL_BL_CMP8;
  __IO uint8_t  PWM_INIT;
  __IO uint8_t  PWM_INTMASK;
  __IO uint8_t  PWM_INTSTATUS;
  __IO uint8_t  PWM_SAMPLE_FREQ_H;
  __IO uint8_t  PWM_SAMPLE_FREQ_L;
  __IO uint8_t  PCM_VOLUME;
       uint8_t  UNUSED37;
       uint8_t  UNUSED38;
       uint8_t  UNUSED39;
       uint8_t  UNUSED40;
       uint8_t  UNUSED41;
       uint8_t  UNUSED42;
       uint8_t  UNUSED43;
       uint8_t  UNUSED44;
       uint8_t  UNUSED45;
       uint8_t  UNUSED46;
       uint8_t  UNUSED47;
       uint8_t  UNUSED48;
       uint8_t  UNUSED49;
       uint8_t  UNUSED50;
       uint8_t  UNUSED51;
       uint8_t  UNUSED52;
       uint8_t  UNUSED53;
       uint8_t  UNUSED54;
       uint8_t  UNUSED55;
       uint8_t  UNUSED56;
       uint8_t  UNUSED57;
       uint8_t  UNUSED58;
       uint8_t  UNUSED59;
  __IO uint16_t PWM_BUFFER;
} ft900_pwm_regs_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#endif /* FT900_PWM_REGISTERS_H_ */
