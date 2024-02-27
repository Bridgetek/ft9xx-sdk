/**
    @file ft900_rtc_registers.h

    @brief Real Time Clock registers
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

#ifndef FT900_RTC_REGISTERS_H_
#define FT900_RTC_REGISTERS_H_

/* INCLUDES ************************************************************************/

#include <stdint.h>
#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

/* On board RTC used in FT900 Rev B */
#define ONBOARD_RTC_TYPE_1
/* On board RTC used in FT900 Rev C and FT930 */
#define ONBOARD_RTC_TYPE_2

#if defined(ONBOARD_RTC_TYPE_2)

/* RTC Time Register */
#define BIT_RTC_HOURS           (0)
#define MASK_RTC_HOURS          (0x3F << BIT_RTC_HOURS)

#define BIT_RTC_12HR_FORMAT     (6)
#define MASK_12HR_FORMAT        (1 << BIT_RTC_12HR_FORMAT)

#define BIT_RTC_MINS            (0)
#define MASK_RTC_MINS           (0x7F << BIT_RTC_HOURS)

#define BIT_RTC_SECONDS         (0)
#define MASK_RTC_SECONDS        (0x7F << BIT_RTC_SECONDS)

/* RTC Date Register */
#define BIT_RTC_DATE            (0)
#define MASK_RTC_DATE           (0x7F << BIT_RTC_DATE)

#define BIT_RTC_WDAY            (0)
#define MASK_RTC_WDAY           (0x03 << BIT_RTC_WDAY)

#define BIT_RTC_MONTH           (0)
#define MASK_RTC_MONTH          (0x1F << BIT_RTC_MONTH)

#define BIT_RTC_CENTURY         (7)
#define MASK_RTC_CENTURY        (0x1 << BIT_RTC_CENTURY)

#define BIT_RTC_YEAR            (0)
#define MASK_RTC_YEAR           (0xFF << BIT_RTC_YEAR)

/* RTC Control Register */
#define BIT_RTC_CTRL_RTCEN      (0)
#define MASK_RTC_CTRL_RTCEN     (0x1 << BIT_RTC_CTRL_RTCEN)

#define BIT_RTC_CTRL_INTEN      (1)
#define MASK_RTC_CTRL_INTEN     (0x1 << BIT_RTC_CTRL_INTEN)

#define BIT_RTC_CTRL_A1IE       (2)
#define MASK_RTC_CTRL_A1IE      (0x1 << BIT_RTC_CTRL_A1IE)

#define BIT_RTC_CTRL_A2IE       (3)
#define MASK_RTC_CTRL_A2IE      (0x1 << BIT_RTC_CTRL_A2IE)

#define BIT_RTC_CTRL_EOSIE      (4)
#define MASK_RTC_CTRL_EOSIE     (0x1 << BIT_RTC_CTRL_EOSIE)

#define BIT_RTC_CTRL_IOSIE      (5)
#define MASK_RTC_CTRL_IOSIE     (0x1 << BIT_RTC_CTRL_IOSIE)

#define BIT_RTC_CTRL_AUCAL      (6)
#define MASK_RTC_CTRL_AUCAL     (0x1 << BIT_RTC_CTRL_AUCAL)

#define BIT_RTC_CTRL_AURFE      (7)
#define MASK_RTC_CTRL_AURFE     (0x1 << BIT_RTC_CTRL_AURFE)

#define BIT_RTC_CTRL_MARFE      (8)
#define MASK_RTC_CTRL_MARFE     (0x1 << BIT_RTC_CTRL_MARFE)

#define BIT_RTC_CTRL_WRST       (9)
#define MASK_RTC_CTRL_WRST      (0x1 << BIT_RTC_CTRL_WRST)

/* RTC Status Register */
#define BIT_RTC_STAT_A1IE       (2)
#define MASK_RTC_STAT_A1IE      (0x1u << BIT_RTC_STAT_A1IE)

#define BIT_RTC_STAT_A2IE       (3)
#define MASK_RTC_STAT_A2IE      (0x1u << BIT_RTC_STAT_A2IE)

#define BIT_RTC_STAT_EOSIE      (4)
#define MASK_RTC_STAT_EOSIE     (0x1u << BIT_RTC_STAT_EOSIE)

#define BIT_RTC_STAT_IOSIE      (5)
#define MASK_RTC_STAT_IOSIE     (0x1u << BIT_RTC_STAT_IOSIE)
#endif

#if defined(ONBOARD_RTC_TYPE_1)

#define BIT_RTC_CCR_INTEN       (0)
#define MASK_RTC_CCR_INTEN      (1 << BIT_RTC_CCR_INTEN)
#define BIT_RTC_CCR_INTMASK     (1)
#define MASK_RTC_CCR_INTMASK    (1 << BIT_RTC_CCR_INTMASK)
#define BIT_RTC_CCR_EN          (2)
#define MASK_RTC_CCR_EN         (1 << BIT_RTC_CCR_EN)
#define BIT_RTC_CCR_WRAPEN      (3)
#define MASK_RTC_CCR_WRAPEN     (1 << BIT_RTC_CCR_WRAPEN)

#define BIT_RTC_STAT_STAT       (0)
#define MASK_RTC_STAT_STAT      (1 << BIT_RTC_STAT_STAT)

#define BIT_RTC_RSTAT_RSTAT     (0)
#define MASK_RTC_RSTAT_RSTAT    (1 << BIT_RTC_RSTAT_RSTAT)

#define BIT_RTC_EOI_EOI         (0)
#define MASK_RTC_EOI_EOI        (1 << BIT_RTC_EOI_EOI)

#endif

/* TYPES ***************************************************************************/

#if defined(ONBOARD_RTC_TYPE_2)

/** \brief Time Register
 *  \details Contains the Second, Minute, Hour counters.
 */
typedef struct
{
  /** \brief Store the second value */
  struct
  {
    uint8_t Seconds    : 4;   ///< Second in units
    uint8_t TenSeconds : 3;   ///< Second in tens
    uint8_t Reserved   : 1;   ///< Reserved
  } byte_0;

  /** \brief Store the minute value */
  struct
  {
    uint8_t Minutes    : 4;   ///< Minute in unit
    uint8_t TenMinutes : 3;   ///< Minute in ten
    uint8_t Reserved   : 1;   ///< Reserved
  } byte_1;

  /** \brief Store the hour value */
  struct
  {
    uint8_t Hours      : 4;   ///< Hour in unit
    uint8_t TenHours   : 1;   ///< Hour in ten
    uint8_t TenHours_2 : 1;   ///< Indicate 20 Hours or 0: AM, 1: PM
    uint8_t HourMode   : 1;   ///< 0: Mean 12 hours mode, 1: Mean 24 hours mode
    uint8_t Reserved   : 1;   ///< Reserved
  } byte_2;

  uint8_t Reserved;           ///< Reserved
} rtc_time_reg_t;

/** \brief Time Register */
typedef union
{
  rtc_time_reg_t B;
  REG_ACCESS_U32 U;
} rtc_time_reg_u;

/** \brief Date Register
 *  \details Contains the Day, Date, Month, Year counters.
 */
typedef struct
{
  /** \brief Store the day of the week */
  struct
  {
    uint8_t Day      : 3;     ///< Day in a weeks form 1 to 7
    uint8_t Reserved : 5;     ///< Reserved
  } byte_0;

  /** \brief Store the date */
  struct
  {
    uint8_t Date     : 4;     ///< Date in unit
    uint8_t TenDate  : 2;     ///< Data in ten
    uint8_t Reserved : 2;     ///< Reserved
  } byte_1;

  /** \brief Store month and century */
  struct
  {
    uint8_t Month        : 4; ///< Month in unit
    uint8_t TenMonth     : 1; ///< Month in ten
    uint8_t Reserved_5_6 : 2; ///< Reserved
    uint8_t Century      : 1; ///< Century
  } byte_2;

  /** \brief Store the year */
  struct
  {
    uint8_t Year    : 4;      ///< Year in unit
    uint8_t TenYear : 4;      ///< Year in ten
  } byte_3;
} rtc_date_reg_t;

/** \brief Date Register */
typedef union
{
  rtc_date_reg_t B;
  REG_ACCESS_U32 U;
} rtc_date_reg_u;

/** \brief Auto Alarm 1 Register
 *  \details When counters match the configured values of this register, Alarm 1 will be asserted.
 *  \note Alarm 1 Mask Bits table
 * | Day/Date       | AALARM1 Register Mask (bit 7)     | Alarm rate                                        |
 * | (Byte 3 Bit 6) |  A1M4  |  A1M3  |  A1M2  |  A1M1  |                                                   |
 * | :------------: | :----: | :----: | :----: | :----: | :-----------------------------------------------: |
 * | X              | 1      | 1      | 1      | 1      | Alarm once per second                             |
 * | X              | 1      | 1      | 1      | 0      | Alarm when seconds match                          |
 * | X              | 1      | 1      | 0      | 0      | Alarm when minutes and seconds match              |
 * | X              | 1      | 0      | 0      | 0      | Alarm when hours, minutes and seconds match       |
 * | 0              | 0      | 0      | 0      | 0      | Alarm when date, hours, minutes and second match  |
 * | 1              | 0      | 0      | 0      | 0      | Alarm when day, hours, minutes and second match   |
 */
typedef struct
{
  /** \brief Store the second value */
  struct
  {
    uint8_t Seconds    : 4;     ///< Second in units
    uint8_t TenSeconds : 3;     ///< Second in tens
    uint8_t A1M1       : 1;     ///< AALARM1 Register Mask bit 0
  } byte_0;

  /** \brief Store the minute value */
  struct
  {
    uint8_t Minutes    : 4;     ///< Minute in unit
    uint8_t TenMinutes : 3;     ///< Minute in ten
    uint8_t A1M2       : 1;     ///< AALARM1 Register Mask bit 1
  } byte_1;

  /** \brief Store the hour value */
  struct
  {
    uint8_t Hours      : 4;     ///< Hour in unit
    uint8_t TenHours   : 1;     ///< Hour in ten
    uint8_t TenHours_2 : 1;     ///< Indicate 20 Hours or 0: AM, 1: PM
    uint8_t HourMode   : 1;     ///< 0: Mean 12 hours mode, 1: Mean 24 hours mode
    uint8_t A1M3       : 1;     ///< AALARM1 Register Mask bit 2
  } byte_2;

  /** \brief Date configuration */
  struct
  {
    uint8_t Day_Date      : 4;  ///< Day/Date in unit
    uint8_t TenDate       : 2;  ///< Date in ten
    uint8_t Mode_Day_Date : 1;  ///< 0: Date, 1: Day
    uint8_t A1M4          : 1;  ///< AALARM1 Register Mask bit 3
  } byte_3;
} rtc_aalarm1_reg_t;

/** \brief Auto Alarm 1 Register */
typedef union
{
  rtc_aalarm1_reg_t B;
  REG_ACCESS_U32    U;
} rtc_aalarm1_reg_u;

/** \brief Auto Alarm 2 Register
 *  \details When counters match the configured values of this register, Alarm 1 will be asserted.
 *  \note Alarm 2 Mask Bits table
 * | Day/Date       | AALARM1 Register Mask (bit 7)     | Alarm rate                                        |
 * | (Byte 3 Bit 6) |  A2M4  |  A2M3  |  A2M2  |  A2M1  |                                                   |
 * | :------------: | :----: | :----: | :----: | :----: | :-----------------------------------------------: |
 * | X              | 1      | 1      | 1      | 1      | Alarm once per second                             |
 * | X              | 1      | 1      | 1      | 0      | Alarm when seconds match                          |
 * | X              | 1      | 1      | 0      | 0      | Alarm when minutes and seconds match              |
 * | X              | 1      | 0      | 0      | 0      | Alarm when hours, minutes and seconds match       |
 * | 0              | 0      | 0      | 0      | 0      | Alarm when date, hours, minutes and second match  |
 * | 1              | 0      | 0      | 0      | 0      | Alarm when day, hours, minutes and second match   |
 */
typedef struct
{
  /** \brief Store the second value */
  struct
  {
    uint8_t Seconds    : 4;     ///< Second in units
    uint8_t TenSeconds : 3;     ///< Second in tens
    uint8_t A2M1       : 1;     ///< AALARM2 Register Mask bit 0
  } byte_0;

  /** \brief Store the minute value */
  struct
  {
    uint8_t Minutes    : 4;     ///< Minute in unit
    uint8_t TenMinutes : 3;     ///< Minute in ten
    uint8_t A2M2       : 1;     ///< AALARM2 Register Mask bit 1
  } byte_1;

  /** \brief Store the hour value */
  struct
  {
    uint8_t Hours      : 4;     ///< Hour in unit
    uint8_t TenHours   : 1;     ///< Hour in ten
    uint8_t TenHours_2 : 1;     ///< Indicate 20 Hours or 0: AM, 1: PM
    uint8_t HourMode   : 1;     ///< 0: Mean 12 hours mode, 1: Mean 24 hours mode
    uint8_t A2M3       : 1;     ///< AALARM2 Register Mask bit 2
  } byte_2;

  /** \brief Date configuration */
  struct
  {
    uint8_t Day_Date      : 4;  ///< Day/Date in unit
    uint8_t TenDate       : 2;  ///< Date in ten
    uint8_t Mode_Day_Date : 1;  ///< 0: Date, 1: Day
    uint8_t A2M4          : 1;  ///< AALARM2 Register Mask bit 3
  } byte_3;
} rtc_aalarm2_reg_t;

/** \brief Auto Alarm 2 Register */
typedef union
{
  rtc_aalarm1_reg_t B;
  REG_ACCESS_U32    U;
} rtc_aalarm2_reg_u;

/** \brief Control Register */
typedef struct
{
  uint32_t RTCEN         : 1;   ///< RTC Enable
                                ///<     1: Enables the RTC.
                                ///<     0: Disables the RTC. Interrupt and alarms will also be
                                ///<        disabled, and the RTC counters will be held.

  uint32_t INTEN         : 1;   ///< Interrupt Enable bit. When this bit is disabled, no interrupt
                                ///< occurs.
                                ///< Note: This bit must be ‘0’ during auto calibration.

  uint32_t A1IE          : 1;   ///< Alarm 1 Interrupt Enable
                                ///< Alarm 1 will cause an interrupt if this bit is enabled.

  uint32_t A2IE          : 1;   ///< Alarm 2 Interrupt Enable
                                ///< Alarm 2 will cause an interrupt if this bit is enabled.

  uint32_t CATIM_0       : 1;   ///< Calibration Time bit 0

  uint32_t IOSIE_CATIM_1 : 1;   ///< Internal Oscillator Stop Interrupt Enable / Calibration Time
                                ///< bit 1. An Oscillator Stop event will cause an interrupt if this
                                ///< bit is enabled. For calibration, this is bit 1 of the
                                ///< calibration time.

  uint32_t AUCAL         : 1;   ///< Write ‘1’ to this bit to enable auto calibration. The
                                ///< calibration time depends on bit 5 and 4 of this register.

  uint32_t ARFEN         : 1;   ///< Auto Refresh Enable
                                ///< When this bit is turned on, time and date counters from
                                ///< Alive will be updated to the Wrapper registers every second.

  uint32_t MRFEN         : 1;   ///< Manual Refresh Enable
                                ///< Write 1 to this bit to update time and date counters from
                                ///< Alive to Wrapper once. This bit will be cleared automatically
                                ///< after updating. Poll this bit to get the status of the Manual
                                ///< Refresh function.
                                ///<     1: Updating
                                ///<     0: Done

  uint32_t WRST_BS       : 1;   ///< Write ‘1’ to this bit to start writing target registers.
                                ///< Read this bit to check the status.
                                ///<     1: Busy
                                ///<     0: Ready
                                ///< This bit is auto cleared.

  uint32_t Reserved      : 22;  ///< Reserved
} rtc_ctrl_reg_t;

/** \brief Control Register */
typedef union
{
  rtc_ctrl_reg_t B;
  REG_ACCESS_U32 U;
} rtc_ctrl_reg_u;

/** \brief Status Register */
typedef struct
{
  uint32_t Reserved_0    : 2;   ///< Reserved

  uint32_t A1INT         : 1;   ///< Alarm 1 Interrupt
                                ///< 1: the timers match the value of the Auto Alarm 1
                                ///< Register; an interrupt will be asserted if
                                ///< RTC_CTRL[2] (A1IE) is set.

  uint32_t A2INT         : 1;   ///< Alarm 2 Interrupt
                                ///< 1: the timers match the value of the Auto Alarm 2
                                ///< Register; an interrupt will be asserted if
                                ///< RTC_CTRL[3] (A2IE) is set.

  uint32_t Reserved_4    : 1;   ///< Reserved

  uint32_t IOSINT        : 1;   ///< Internal Oscillator Stop Interrupt
                                ///< 1: Two continuous values are the same after a defined period of
                                ///< time, i.e., the oscillator has stopped. If RTC_CTRL[5] (IOSIE)
                                ///< is enabled, an interrupt will be asserted.

  uint32_t AUCAL_DONE    : 1;   ///< 1: Auto Calibration Completed.
                                ///< This bit should be cleared by writing ‘1’ to it after the
                                ///< calibration process.

  uint32_t Reserved_7_31 : 25;  ///< Reserved
} rtc_stat_reg_t;

/** \brief Status Register */
typedef union
{
  rtc_stat_reg_t B;
  REG_ACCESS_U32 U;
} rtc_stat_reg_u;

/** \brief Trimming Register */
typedef struct
{
  uint32_t TRIM_VAL  : 16;      ///< The trimming value. After auto calibration, the new value will
                                ///< be loaded automatically. The user may also write to this
                                ///< register manually.

  uint32_t TRIM_TIME : 16;      ///< The trimming period (in seconds). The default value is 0x03E8,
                                ///< or 1000 seconds. After auto calibration, the new value will be
                                ///< loaded automatically. The user may also write to this register
                                ///< manually, but the value should match the trimming period used
                                ///< for the calibration.
} rtc_trim_reg_t;

/** \brief Trimming Register */
typedef union
{
  rtc_trim_reg_t B;
  REG_ACCESS_U32 U;
} rtc_trim_reg_u;

/** \brief Sleep Time Register
 *  \details Contains the Second, Minute, Hour values when the system power is turned off.
 */
typedef struct
{
  /** \brief Store the second value */
  struct
  {
    uint8_t Seconds    : 4;   ///< Second in units
    uint8_t TenSeconds : 3;   ///< Second in tens
    uint8_t Reserved   : 1;   ///< Reserved
  } byte_0;

  /** \brief Store the minute value */
  struct
  {
    uint8_t Minutes    : 4;   ///< Minute in unit
    uint8_t TenMinutes : 3;   ///< Minute in ten
    uint8_t Reserved   : 1;   ///< Reserved
  } byte_1;

  /** \brief Store the hour value */
  struct
  {
    uint8_t Hours      : 4;   ///< Hour in unit
    uint8_t TenHours   : 1;   ///< Hour in ten
    uint8_t TenHours_2 : 1;   ///< Indicate 20 Hours or 0: AM, 1: PM
    uint8_t HourMode   : 1;   ///< 0: Mean 12 hours mode, 1: Mean 24 hours mode
    uint8_t Reserved   : 1;   ///< Reserved
  } byte_2;

  uint8_t Reserved;           ///< Reserved
} rtc_sleep_time_reg_t;

/** \brief Sleep Time Register */
typedef union
{
  rtc_sleep_time_reg_t B;
  REG_ACCESS_U32       U;
} rtc_sleep_time_reg_u;

/** \brief Sleep Date Register
 *  \details Contains Day, Date, Month, Year counters when the system power is turned off.
 */
typedef struct
{
  /** \brief Store the day of the week */
  struct
  {
    uint8_t Day      : 3;     ///< Day in a weeks form 1 to 7
    uint8_t Reserved : 5;     ///< Reserved
  } byte_0;

  /** \brief Store the date */
  struct
  {
    uint8_t Date     : 4;     ///< Date in unit
    uint8_t TenDate  : 2;     ///< Data in ten
    uint8_t Reserved : 2;     ///< Reserved
  } byte_1;

  /** \brief Store month and century */
  struct
  {
    uint8_t Month        : 4; ///< Month in unit
    uint8_t TenMonth     : 1; ///< Month in ten
    uint8_t Reserved_5_6 : 2; ///< Reserved
    uint8_t Century      : 1; ///< Century
  } byte_2;

  /** \brief Store the year */
  struct
  {
    uint8_t Year    : 4;      ///< Year in unit
    uint8_t TenYear : 4;      ///< Year in ten
  } byte_3;
} rtc_sleep_date_reg_t;

/** \brief Sleep Date Register */
typedef union
{
  rtc_sleep_date_reg_t B;
  REG_ACCESS_U32       U;
} rtc_sleep_date_reg_u;

/** \brief Compare Period Register
 *  \details Contains the Oscillator Stop compare period which is automatically detected. The user
 *           should set the compare period within the range of 100ms ~ 2s based on the system clock
 *           cycle, where the system clock is 100 MHz.
 */
typedef struct
{
  uint32_t Compare_Period : 3;  ///< Configuration table:
                                ///<   | 0 | 0 | 0| Auto detection is turned off                    |
                                ///<   | 0 | 0 | 0| Auto detect per 100,000 system clock cycles     |
                                ///<   | 0 | 0 | 0| Auto detect per 1,000,000 system clock cycles   |
                                ///<   | 0 | 0 | 0| Auto detect per 10,000,000 system clock cycles  |
                                ///<   | 0 | 0 | 0| Auto detect per 100,000,000 system clock cycles |

  uint32_t Reserved       : 29; ///< Reserved
} rtc_comp_per_reg_t;

/** \brief Compare Period Register */
typedef union
{
  rtc_comp_per_reg_t B;
  REG_ACCESS_U32     U;
} rtc_comp_per_reg_u;

/** \brief Miscellaneous Register */
typedef struct
{
  uint32_t Reserved_0_7   : 8;  ///< Reserved

  uint32_t SEL_VBAT       : 1;  ///< Battery Low Detection Threshold Selection. The battery low
                                ///< interrupt will be triggered if the battery level falls below
                                ///< the threshold selected here.
                                ///<     0: 84% of VCCK
                                ///<     1: 80% of VCCK
                                ///< Where VCCK is the core voltage (~1.2V).

  uint32_t Reserved_9_15  : 7;  ///< Reserved

  uint32_t DUMMY          : 1;  ///< This is a Read/Write dummy bit. This bit can be used to
                                ///< indicate whether the RTC power has been interrupted after the
                                ///< system is initialized. For example, write “1” to this bit
                                ///< during system initialization. After that, if both Battery and
                                ///< system power are removed, this bit will be reset to “0”.

  uint32_t Reserved_17_31 : 15; ///< Reserved
} rtc_misc_reg_t;

/** \brief Miscellaneous Register */
typedef union
{
  rtc_misc_reg_t B;
  REG_ACCESS_U32 U;
} rtc_misc_reg_u;

/** @brief Register mappings for RTC registers in case of RTC hw used in FT900 Rev C and FT930 */
typedef struct
{
  __IO rtc_time_reg_u       RTC_TIME;
  __IO rtc_date_reg_u       RTC_DATE;
  __IO rtc_aalarm1_reg_u    RTC_AALARM1;
  __IO rtc_aalarm2_reg_u    RTC_AALARM2;
  __IO rtc_ctrl_reg_u       RTC_CTRL;
  __IO rtc_stat_reg_u       RTC_STAT;
  __IO rtc_trim_reg_u       RTC_TRIM;
  __IO rtc_sleep_time_reg_u RTC_SLEEP_TIME;
  __IO rtc_sleep_date_reg_u RTC_SLEEP_DATE;
  __IO rtc_comp_per_reg_u   RTC_COMP_PER;
  __IO rtc_misc_reg_u       RTC_MISC;
} rtc_regs_t;

/** @brief Register mappings for RTC registers in case of RTC hw used in FT900 Rev C and FT930 */
typedef struct
{
  __IO uint32_t RTC_TIME;
  __IO uint32_t RTC_DATE;
  __IO uint32_t RTC_AALARM1;
  __IO uint32_t RTC_AALARM2;
  __IO uint32_t RTC_CTRL;
  __IO uint32_t RTC_STA;
  __IO uint32_t RTC_TRIMMING;
  __IO uint32_t RTC_SLE_TIME;
  __IO uint32_t RTC_SLE_DATE;
  __IO uint32_t RTC_COMP_PER;
  __IO uint32_t RTC_VREF_TRIM;
} ft900_rtc_regs_t;
#endif

#if defined(ONBOARD_RTC_TYPE_1)

/** \brief Current Counter Value Register */
typedef struct
{
  uint32_t DATA;  ///< This is the current value of the internal counter.
                  ///< This value always is read coherently.
} rtc_ccvr_reg_t;

/** \brief Current Counter Value Register */
typedef union
{
  rtc_ccvr_reg_t B;
  REG_ACCESS_U32 U;
} rtc_ccvr_reg_u;

/** \brief Counter Match Register */
typedef struct
{
  uint32_t DATA;  ///< When the internal counter matches this register, an interrupt is generated if
                  ///< enabled. When appropriate, this value is written coherently. Only when all
                  ///< relevant bytes have been written will the new value be effective.
} rtc_cmr_reg_t;

/** \brief Counter Match Register */
typedef union
{
  rtc_cmr_reg_t  B;
  REG_ACCESS_U32 U;
} rtc_cmr_reg_u;

/** \brief Counter Load Register */
typedef struct
{
  uint32_t DATA;  ///< Loaded in the counter as the loaded value, which is written coherently.
} rtc_clr_reg_t;

/** \brief Counter Load Register */
typedef union
{
  rtc_clr_reg_t  B;
  REG_ACCESS_U32 U;
} rtc_clr_reg_u;

/** \brief Counter Control Register */
typedef struct
{
  uint32_t RTC_IEN  : 1;    ///< Allows the user to disable interrupt generation.
                            ///<     0: Interrupt disabled
                            ///<     1: Interrupt enabled

  uint32_t RTC_MASK : 1;    ///< Allows the user to mask a generated interrupt.
                            ///<     0: Interrupt unmasked
                            ///<     1: Interrupt masked

  uint32_t RTC_EN   : 1;    ///< Allows the user to control counting in the counter.
                            ///<     0: Counter disabled
                            ///<     1: Counter enabled

  uint32_t RTC_WEN  : 1;    ///< Allows the user to force the counter to wrap when a match occurs
                            ///< instead of waiting until the maximum count is reached.
                            ///<     0: wrap disabled
                            ///<     1: wrap enabled

  uint32_t Reserved : 28;   ///< Reserved
} rtc_ccr_reg_t;

/** \brief Counter Control Register */
typedef union
{
  rtc_ccr_reg_t  B;
  REG_ACCESS_U32 U;
} rtc_ccr_reg_u;

typedef struct
{
  uint32_t RTC_STAT : 1;    ///< This is the masked raw status
                            ///<     0: Interrupt is inactive
                            ///<     1: Interrupt is active (regardless of polarity)

  uint32_t Reserved : 31;   ///< Reserved
} rtcl_stat_reg_t;

/** \brief Interrupt Status Register */
typedef union
{
  rtcl_stat_reg_t B;
  REG_ACCESS_U32 U;
} rtcl_stat_reg_u;

/** \brief Interrupt Raw Status Register */
typedef struct
{
  uint32_t RTC_RSTAT : 1;   ///< 0: Interrupt is inactive
                            ///< 1: Interrupt is active (regardless of polarity)

  uint32_t Reserved  : 31;  ///< Reserved
} rtc_rstat_reg_t;

/** \brief Interrupt Raw Status Register */
typedef union
{
  rtc_rstat_reg_t B;
  REG_ACCESS_U32  U;
} rtc_rstat_reg_u;

/** \brief End of Interrupt Register */
typedef struct
{
  uint32_t RTC_EOI  : 1;    ///< By reading this location, the match interrupt is cleared.
                            ///< Performing read-to-clear on interrupts, the interrupt is cleared at
                            ///< the end of the read.

  uint32_t Reserved : 31;   ///< Reserved
} rtc_eoi_reg_t;

/** \brief End of Interrupt Register */
typedef union
{
  rtc_eoi_reg_t  B;
  REG_ACCESS_U32 U;
} rtc_eoi_reg_u;

/** \brief Component Version Register */
typedef struct
{
  uint32_t RTC_COMP_VERSION;  ///< ASCII value for each number in the version, followed by
                              ///< *. 32_30_33_2A represents the version 2.03*.
} rtc_comp_ver_reg_t;

/** \brief Component Version Register */
typedef struct
{
  rtc_comp_ver_reg_t B;
  REG_ACCESS_U32     U;
} rtc_comp_ver_reg_u;

/** @brief Register mappings for RTC registers in case of RTC hw used in FT900 rev B*/
typedef struct
{
  __IO rtc_ccvr_reg_u     RTC_CCVR;
  __IO rtc_cmr_reg_u      RTC_CMR;
  __IO rtc_clr_reg_u      RTC_CLR;
  __IO rtc_ccr_reg_u      RTC_CCR;
  __IO rtcl_stat_reg_u    RTC_STAT;
  __IO rtc_rstat_reg_u    RTC_RSTAT;
  __IO rtc_eoi_reg_u      RTC_EOI;
  __IO rtc_comp_ver_reg_u RTC_COMP_VERSION;
} rtc_legacy_regs_t;

/** @brief Register mappings for RTC registers in case of RTC hw used in
 * FT900 rev B*/
typedef struct
{
  __IO uint32_t RTC_CCVR;
  __IO uint32_t RTC_CMR;
  __IO uint32_t RTC_CLR;
  __IO uint32_t RTC_CCR;
  __IO uint32_t RTC_STAT;
  __IO uint32_t RTC_RSTAT;
  __IO uint32_t RTC_EOI;
  __IO uint32_t RTC_COMP_VERSION;
} ft900_rtc_legacy_regs_t;
#endif


/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/


#endif /* FT900_RTC_REGISTERS_H_ */
