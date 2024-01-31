/**
    @file ft900_can_registers.h
    @brief CANBus registers
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

#ifndef FT900_CAN_REGISTERS_H_
#define FT900_CAN_REGISTERS_H_

/* INCLUDES ************************************************************************/
#include <stdint.h>
#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

/* Bit masks for the CAN_MODE register */
#define BIT_CAN_MODE_ACC_FLTR               (0)
#define MASK_CAN_MODE_ACC_FLTR              (1 << BIT_CAN_MODE_ACC_FLTR)
#define BIT_CAN_MODE_LSTN_ONLY              (1)
#define MASK_CAN_MODE_LSTN_ONLY             (1 << BIT_CAN_MODE_LSTN_ONLY)
#define BIT_CAN_MODE_RST                    (2)
#define MASK_CAN_MODE_RST                   (1 << BIT_CAN_MODE_RST)

/* Bit masks for the CAN_CMD register */
#define BIT_CAN_CMD_ABORT_TX                (1)
#define MASK_CAN_CMD_ABORT_TX               (1 << BIT_CAN_CMD_ABORT_TX)
#define BIT_CAN_CMD_TX_REQ                  (2)
#define MASK_CAN_CMD_TX_REQ                 (1 << BIT_CAN_CMD_TX_REQ)

/* Bit masks for the CAN_STATUS register */
#define BIT_CAN_STATUS_BUS_OFF_STS          (0)
#define MARK_CAN_STATUS_BUS_OFF_STS         (1 << BIT_CAN_STATUS_BUS_OFF_STS)
#define BIT_CAN_STATUS_ERR_STS              (1)
#define MASK_CAN_STATUS_ERR_STS             (1 << BIT_CAN_STATUS_ERR_STS)
#define BIT_CAN_STATUS_TX_STS               (2)
#define MASK_CAN_STATUS_TX_STS              (1 << BIT_CAN_STATUS_TX_STS)
#define BIT_CAN_STATUS_RX_STS               (3)
#define MASK_CAN_STATUS_RX_STS              (1 << BIT_CAN_STATUS_RX_STS)
#define BIT_CAN_STATUS_TX_BUF_STS           (5)
#define MASK_CAN_STATUS_TX_BUF_STS          (1 << BIT_CAN_STATUS_TX_BUF_STS)
#define BIT_CAN_STATUS_OVRN_STS             (6)
#define MASK_CAN_STATUS_OVRN_STS            (1 << BIT_CAN_STATUS_OVRN_STS)
#define BIT_CAN_STATUS_RX_BUF_STS           (7)
#define MASK_CAN_STATUS_RX_BUF_STS          (1 << BIT_CAN_STATUS_RX_BUF_STS)
/************* Available from FT900 Rev C Onwards ***********************/
#define BIT_CAN_STATUS_DOVLD_STS            (4)  /* 1 -> the overload condition occurs due to the
                                                         internal conditions of the receiver,
                                                         which requires a delay of the next frame */
#define MASK_CAN_STATUS_DOVLD_STS           (1 << BIT_CAN_STATUS_DOVLD_STS)
/***********************************************************************/

/* Bit masks for the CAN_INT_STATUS and CAN_INT_ENABLE registers */
#define BIT_CAN_INT_STATUS_DATA_OVRN        (0)
#define MASK_CAN_INT_STATUS_DATA_OVRN       (1 << BIT_CAN_INT_STATUS_DATA_OVRN)
#define BIT_CAN_INT_STATUS_BUS_ERR          (1)
#define MASK_CAN_INT_STATUS_BUS_ERR         (1 << BIT_CAN_INT_STATUS_BUS_ERR)
#define BIT_CAN_INT_STATUS_TX               (2)
#define MASK_CAN_INT_STATUS_TX              (1 << BIT_CAN_INT_STATUS_TX)
#define BIT_CAN_INT_STATUS_RX               (3)
#define MASK_CAN_INT_STATUS_RX              (1 << BIT_CAN_INT_STATUS_RX)
#define BIT_CAN_INT_STATUS_ERR_PSV          (4)
#define MASK_CAN_INT_STATUS_ERR_PSV         (1 << BIT_CAN_INT_STATUS_ERR_PSV)
#define BIT_CAN_INT_STATUS_ERR_WRNG         (5)
#define MASK_CAN_INT_STATUS_ERR_WRN         (1 << BIT_CAN_INT_STATUS_ERR_WRNG)
#define BIT_CAN_INT_STATUS_ARB_LOST         (6)
#define MASK_CAN_INT_STATUS_ARB_LOST        (1 << BIT_CAN_INT_STATUS_ARB_LOST)
/************* Available from FT900 Rev C Onwards ***********************/
#define BIT_CAN_INT_STATUS_DOVLD	          (7)  /* Set when the overload condition occurs.
                                                    Write a 1 to clear this interrupt */
#define MASK_CAN_INT_STATUS_DOVLD           (1 << BIT_CAN_INT_STATUS_DOVLD)
/***********************************************************************/

#define BIT_CAN_INT_ENABLE_DATA_OVRN_EN     (0)
#define MASK_CAN_INT_ENABLE_DATA_OVRN_EN    (1 << BIT_CAN_INT_ENABLE_DATA_OVRN_EN)
#define BIT_CAN_INT_ENABLE_BUS_ERR_EN       (1)
#define MASK_CAN_INT_ENABLE_BUS_ERR_EN      (1 << BIT_CAN_INT_ENABLE_BUS_ERR_EN)
#define BIT_CAN_INT_ENABLE_TX_EN            (2)
#define MASK_CAN_INT_ENABLE_TX_EN           (1 << BIT_CAN_INT_ENABLE_TX_EN)
#define BIT_CAN_INT_ENABLE_RX_EN            (3)
#define MASK_CAN_INT_ENABLE_RX_EN           (1 << BIT_CAN_INT_ENABLE_RX_EN)
#define BIT_CAN_INT_ENABLE_ERR_PSV_EN       (4)
#define MASK_CAN_INT_ENABLE_ERR_PSV_EN      (1 << BIT_CAN_INT_ENABLE_ERR_PSV_EN)
#define BIT_CAN_INT_ENABLE_ERR_WRNG_EN      (5)
#define MASK_CAN_INT_ENABLE_ERR_WRNG_EN     (1 << BIT_CAN_INT_ENABLE_ERR_WRNG_EN)
#define BIT_CAN_INT_ENABLE_ARB_LOST_EN      (6)
#define MASK_CAN_INT_ENABLE_ARB_LOST_EN     (1 << BIT_CAN_INT_ENABLE_ARB_LOST_EN)
/************* Available from FT900 Rev C Onwards ***********************/
#define BIT_CAN_INT_ENABLE_DOVLD_EN         (7) /*Mask for Data Overload interrupt */
#define MASK_CAN_INT_ENABLE_DOVLD_EN        (1 << BIT_CAN_INT_ENABLE_DOVLD_EN)
/***********************************************************************/

/* Bit masks for the CAN_BUS_TIM_0 register */
#define BIT_CAN_BUS_TIM_0_BAUD_PSCL         (0)
#define MASK_CAN_BUS_TIM_0_BAUD_PSCL        (0x3F << BIT_CAN_BUS_TIM_0_BAUD_PSCL)
#define BIT_CAN_BUS_TIM_0_SYNC_JMP_WDT      (6)
#define MASK_CAN_BUS_TIM_0_SYNC_JMP_WDT     (0x3 << BIT_CAN_BUS_TIM_0_SYNC_JMP_WDT)

/* Bit masks for the CAN_BUS_TIM_1 register */
#define BIT_CAN_BUS_TIM_1_TIM_SEG1          (0)
#define MASK_CAN_BUS_TIM_1_TIM_SEG1         (0xF << BIT_CAN_BUS_TIM_1_TIM_SEG1)
#define BIT_CAN_BUS_TIM_1_TIM_SEG2          (4)
#define MASK_CAN_BUS_TIM_1_TIM_SEG2         (0x7 << BIT_CAN_BUS_TIM_1_TIM_SEG2)
#define BIT_CAN_BUS_TIM_1_NUM_SAM           (7)
#define MASK_CAN_BUS_TIM_1_NUM_SAM          (1 << BIT_CAN_BUS_TIM_1_NUM_SAM)

/* Bit masks for the CAN_ERR_CODE (Error Code) register */
#define BIT_CAN_ERR_CODE_BIT_ERR            (0)
#define MASK_CAN_ERR_CODE_BIT_ERR           (1 << BIT_CAN_ERR_CODE_BIT_ERR)
#define BIT_CAN_ERR_CODE_STF_ERR            (1)
#define MASK_CAN_ERR_CODE_STF_ERR           (1 << BIT_CAN_ERR_CODE_STF_ERR)
#define BIT_CAN_ERR_CODE_CRC_ERR            (2)
#define MASK_CAN_ERR_CODE_CRC_ERR           (1 << BIT_CAN_ERR_CODE_CRC_ERR)
#define BIT_CAN_ERR_CODE_FRM_ERR            (3)
#define MASK_CAN_ERR_CODE_FRM_ERR           (1 << BIT_CAN_ERR_CODE_FRM_ERR)
#define BIT_CAN_ERR_CODE_ACK_ERR            (4)
#define MASK_CAN_ERR_CODE_ACK_ERR           (1 << BIT_CAN_ERR_CODE_ACK_ERR)
#define BIT_CAN_ERR_CODE_ERR_DIR            (5)
#define MASK_CAN_ERR_CODE_ERR_DIR           (1 << BIT_CAN_ERR_CODE_ERR_DIR)
#define BIT_CAN_ERR_CODE_TX_WRN             (6)
#define MASK_CAN_ERR_CODE_TX_WRN            (1 << BIT_CAN_ERR_CODE_TX_WRN)
#define BIT_CAN_ERR_CODE_RX_WRN             (7)
#define MASK_CAN_ERR_CODE_RX_WRN            (1 << BIT_CAN_ERR_CODE_RX_WRN)

/* TYPES ***************************************************************************/

/** \brief Mode register */
typedef struct
{
  uint8_t ACC_FLTR  : 1;  ///< Hardware Acceptance Filter Scheme
                          ///< Updatable only when RST is 1
                          ///< 0: Dual filter is used for hardware acceptance filter scheme
                          ///< 1: Single filter is used for hardware acceptance filter scheme
  uint8_t LSTN_ONLY : 1;  ///< Listen Only Mode
                          ///< Updatable only when RST is 1
                          ///< 0: Normal Mode
                          ///< 1: Listen only mode
  uint8_t RST       : 1;  ///< Reset Mode
                          ///< 1: Controller in reset mode; no frame reception and transmission are
                          ///< possible. This mode is used to configure the controller hardware
  uint8_t Reserved  : 5;  ///< Reserved
} can_mode_st;

typedef union
{
  can_mode_st   B;
  REG_ACCESS_U8 U;
} can_mode_u;

/** \brief Command register */
typedef struct
{
  uint8_t Reserved_1 : 1; ///< Reserved
  uint8_t ABORT_TX   : 1; ///< Abort Transmission
                          ///< When writing 1 to this bit simultaneously with TX_REQ bit,
                          ///< 1-shot transmission is performed.
                          ///< If TX_REQ has been set to 1, and the transmission has not started,
                          ///< writing a 1 to ABORT_TX will abort the request.
  uint8_t TX_REQ     : 1; ///< Transmit Request
                          ///< 1: Initiates frames transmission by Bit Stream Processor
                          ///< 0: No effect
  uint8_t Reserved_3 : 5;
} can_cmd_t;

typedef union
{
  can_cmd_t     B;
  REG_ACCESS_U8 U;
} can_cmd_u;

/** \brief Status register */
typedef struct
{
  uint8_t BUS_OFF_STS : 1;  ///< Bus Off Status
                            ///< 1: Node is in bus off state and cannot transmit and receive frames.
                            ///< When the transmit error counter exceeds the limit of 255, this bit
                            ///< will be set to 1, the CAN controller sets reset mode, and if
                            ///< enabled an error warning interrupt is generated. The transmit error
                            ///< counter is then set to 127 and receive error counter is cleared.
                            ///< The CAN controller stays in reset mode until the CPU clears the
                            ///< reset mode bit. Once this is completed the CAN controller waits for
                            ///< 128 occurrences of the bus free signal (11 consecutive recessive
                            ///< bits) counting down the transmit error counter. After that this bit
                            ///< is cleared (bus on), the error counters are reset and the error
                            ///< warning interrupt is generated if enabled.
  uint8_t ERR_STS     : 1;  ///< Error Status
                            ///< 1: when at least one of CAN error counters has reached error
                            ///< warning limit (96). This bit is automatically cleared when the
                            ///< error counter is below the limit.
  uint8_t TX_STS      : 1;  ///< Transmit Status
                            ///< 1: when the CAN core is transmitting a message.
  uint8_t RX_STS      : 1;  ///< Receive Status
                            ///< 1: when the CAN core is receiving a message.
  uint8_t Reserved    : 1;  ///< Reserved
  uint8_t TX_BUF_STS  : 1;  ///< Transmit Buffer Status
                            ///< 1: transmit buffer can be written.
                            ///< 0: transmission in progress and transmit buffer is locked such that
                            ///<    no data write can be accepted
  uint8_t OVRN_STS    : 1;  ///< Data Overrun Status
                            ///< 1: when RX FIFO encounters overrun.
                            ///< 0: no overrun occurred since the last clear data overrun command
                            ///< This bit is cleared when a 1 is written to DATA_OVRN bit.
  uint8_t RX_BUF_STS  : 1;  ///< Receive Buffer Status:
                            ///< 1: at least one message is in RX FIFO.
                            ///< 0: no message is in RX FIFO
} can_status_t;

typedef union
{
  can_status_t  B;
  REG_ACCESS_U8 U;
} can_status_u;

/** \brief Interrupt status register */
typedef struct
{
  uint8_t DATA_OVRN : 1;  ///< Data Overrun Interrupt
                          ///< Set when the RX FIFO overrun has occurred.
                          ///< Write a 1 to clear this interrupt.
  uint8_t BUS_ERR   : 1;  ///< Bus Error Interrupt
                          ///< Set when the CAN core encounters a bus error while transmitting or
                          ///< receiving a message. Write a 1 to clear this interrupt.
  uint8_t TX        : 1;  ///< Transmission Interrupt
                          ///< Set after a successful transmission.
                          ///< Write a 1 to reset the write pointer to TX RAM before writing the
                          ///< next frame of data.
  uint8_t RX        : 1;  ///< Receive Interrupt
                          ///< Set when there is at least one message in the RX FIFO.
                          ///< Write a 1 to decrement the RX message counter (NUM_FRM). NUM_FRM is
                          ///< not decremented automatically.
                          ///< Note that this flag is cleared after the first message is read. The
                          ///< interrupt handler should check how many messages there are (NUM_FRM)
                          ///< and read all of them out.
  uint8_t ERR_PSV   : 1;  ///< Error Passive Interrupt
                          ///< Set when CAN core has reached or exceeded error passive level.
                          ///< Write a 1 to clear this interrupt
  uint8_t ERR_WRNG  : 1;  ///< Error Warning Interrupt
                          ///< Set when there is a change in ERR_STS or BUS_OFF_STS bits of Status
                          ///< register. Write a 1 to clear this interrupt.
  uint8_t ARB_LOST  : 1;  ///< Arbitration Lost Interrupt
                          ///< Set when the CAN core has lost arbitration during transmission of its
                          ///< own message and become a receiver. Write a 1 to clear this interrupt.
  uint8_t Reserved  : 1;  ///< Reserved
} can_int_status_t;

typedef union
{
  can_int_status_t B;
  REG_ACCESS_U8    U;
} can_int_status_u;

/** \brief Interrupt enable register */
typedef struct
{
  uint8_t DATA_OVRN_EN : 1; ///< Mask for DATA_OVRN interrupt.
  uint8_t BUS_ERR_EN   : 1; ///< Mask for BUS_ERR interrupt.
  uint8_t TX_EN        : 1; ///< Mask for TX interrupt.
  uint8_t RX_EN        : 1; ///< Mask for RX interrupt.
  uint8_t ERR_PSV_EN   : 1; ///< Mask for ERR_PSV interrupt.
  uint8_t ERR_WRNG_EN  : 1; ///< Mask for ERR_WRNG interrupt.
  uint8_t ARB_LOST_EN  : 1; ///< Mask for ARB_LOST interrupt
  uint8_t Reserved     : 2; ///< Reserved
} can_int_enable_t;

typedef union
{
  can_int_enable_t B;
  REG_ACCESS_U8    U;
} can_int_enable_u;

/** \brief Receive message register */
typedef struct
{
  uint8_t NUM_FRM  : 5; ///< Number of stored message frames
                        ///< This shows the number of frames stored in the RX FIFO. The value is
                        ///< incremented on each successful frame reception and decremented by
                        ///< clearing the RX interrupt. Up to 21 messages can be stored. This
                        ///< equation shows the calculation:
                        ///< n = 64 / (3 + data_length_code)
  uint8_t Reserved : 3; ///< Reserved
} can_rx_msg_t;

typedef union
{
  can_rx_msg_t  B;
  REG_ACCESS_U8 U;
} can_rx_msg_u;

/** \brief Bus Timing 0 Register */
typedef struct
{
  uint8_t BAUD_PSCL    : 6; ///< Synchronisation Jump Width
                            ///< This allows compensation for phase shifts between clocks of
                            ///< different bus controllers. The maximum number of clock cycles a bit
                            ///< period may be changed by one resynchronization is defined by
                            ///< SYNC_JMP_WDT as:
                            ///< T SYNC_JMP_WDT:
                            ///< tsclk x (2 x SYNC_JMP_WDT [1] + SYNC_JMP_WDT [0] + 1)
  uint8_t SYNC_JMP_WDT : 2; ///< Baud Rate Prescaler
                            ///< Baud rate can be set using this equation:
                            ///< BAUD_PSCL:
                            ///< (32 x BAUL_PSCL[5] + 16 x BAUD_PSCL[4] + 8 x BAUD_PSCL[3] + 4 x
                            ///< BAUD_PSCL[2] + 2 x BAUD_PSCL[1] +
                            ///< BAUD_PSCL[0])
                            ///< The period of CAN system clock tsclk is thus:
                            ///< tsclk: 2 x tclk x BAUD_PSCL
} can_bus_tim_0_t;

typedef union
{
  can_bus_tim_0_t B;
  REG_ACCESS_U8   U;
} can_bus_tim_0_u;

/** \brief Bus Timing 1 Register */
typedef struct
{
  uint8_t TIM_SEG1 : 4;   ///< Number of bus level samples
                          ///< 0: bus level is sampled once (recommended for high-speed buses)
                          ///< 1: bus level is sampled three times (recommended for low/medium speed
                          ///< buses where there is a benefit from filtering spikes)
  uint8_t TIM_SEG2 : 3;   ///< Number of clock cycles per Time Segment 2
                          ///< tTIM_SEG2 = tsclk x (4 x TIM_SEG1[2] + 2 x
                          ///<             TIM_SEG1[1] + TIM_SEG1[0] + 1)
  uint8_t NUM_SAM  : 1;   ///< Number of clock cycles per Time Segment 1
                          ///< tTIM_SEG1 = tsclk x (8 x TIM_SEG1[3] + 4 x TIM_SEG1[2]
                          ///<                      + 2 x TIM_SEG1[1] + TIM_SEG1[0] + 1)
} can_bus_tim_1_t;

typedef union
{
  can_bus_tim_1_t B;
  REG_ACCESS_U8   U;
} can_bus_tim_1_u;

/** \brief Transmit Buffer Register */
typedef struct
{
  uint8_t CAN_TX_BUF_0; ///< This is used to write a CAN frame for transmission. When write is
                        ///< performed on CAN_TX_BUF_3, the internal write pointer will be
                        ///< automatically incremented. This pointer can be reset by writing a 1 to
                        ///< TX of the Interrupt Status register
  uint8_t CAN_TX_BUF_1; ///< This is used to write a CAN frame for transmission. When write is
                        ///< performed on CAN_TX_BUF_3, the internal write pointer will be
                        ///< automatically incremented. This pointer can be reset by writing a 1 to
                        ///< TX of the Interrupt Status register
  uint8_t CAN_TX_BUF_2; ///< This is used to write a CAN frame for transmission. When write is
                        ///< performed on CAN_TX_BUF_3, the internal write pointer will be
                        ///< automatically incremented. This pointer can be reset by writing a 1 to
                        ///< TX of the Interrupt Status register
  uint8_t CAN_TX_BUF_3; ///< This is used to write a CAN frame for transmission. When write is
                        ///< performed on CAN_TX_BUF_3, the internal write pointer will be
                        ///< automatically incremented. This pointer can be reset by writing a 1 to
                        ///< TX of the Interrupt Status register
} can_tx_buf_t;

typedef union
{
  can_tx_buf_t   B;
  REG_ACCESS_U32 U;
} can_tx_buf_u;

typedef struct
{
  uint8_t CAN_RX_BUF_0; ///< This is used to read a received CAN frame. When read is performed on
                        ///< CAN_RX_BUF_3, the internal read pointer will be automatically
                        ///< incremented.
  uint8_t CAN_RX_BUF_1; ///< This is used to read a received CAN frame. When read is performed on
                        ///< CAN_RX_BUF_3, the internal read pointer will be automatically
                        ///< incremented.
  uint8_t CAN_RX_BUF_2; ///< This is used to read a received CAN frame. When read is performed on
                        ///< CAN_RX_BUF_3, the internal read pointer will be automatically
                        ///< incremented.
  uint8_t CAN_RX_BUF_3; ///< This is used to read a received CAN frame. When read is performed on
                        ///< CAN_RX_BUF_3, the internal read pointer will be automatically
                        ///< incremented.
} can_rx_buf_t;

typedef union
{
  can_rx_buf_t   B;
  REG_ACCESS_U32 U;
} can_rx_buf_u;

typedef struct
{
  uint8_t CAN_ACC_CODE_BIT_0 : 1;
  uint8_t CAN_ACC_CODE_BIT_1 : 1;
  uint8_t CAN_ACC_CODE_BIT_2 : 1;
  uint8_t CAN_ACC_CODE_BIT_3 : 1;
  uint8_t CAN_ACC_CODE_BIT_4 : 1;
  uint8_t CAN_ACC_CODE_BIT_5 : 1;
  uint8_t CAN_ACC_CODE_BIT_6 : 1;
  uint8_t CAN_ACC_CODE_BIT_7 : 1;
} can_acc_code_t;

typedef union
{
  can_acc_code_t B;
  REG_ACCESS_U8  U;
} can_acc_code_u;

/** \brief This register determines which bits in CAN_ACC_CODE_* is used for the acceptance filter.
  *        A 1 at a particular bit means that the corresponding bit in CAN_ACC_CODE_* will not be
  *        compared.*/
typedef struct
{
  uint8_t CAN_ACC_MASK_BIT_0 : 1;
  uint8_t CAN_ACC_MASK_BIT_1 : 1;
  uint8_t CAN_ACC_MASK_BIT_2 : 1;
  uint8_t CAN_ACC_MASK_BIT_3 : 1;
  uint8_t CAN_ACC_MASK_BIT_4 : 1;
  uint8_t CAN_ACC_MASK_BIT_5 : 1;
  uint8_t CAN_ACC_MASK_BIT_6 : 1;
  uint8_t CAN_ACC_MASK_BIT_7 : 1;
} can_acc_mask_t;

typedef union
{
  can_acc_mask_t B;
  REG_ACCESS_U8  U;
} can_acc_mask_u;

/** \brief Error Code Capture Register */
typedef struct
{
  uint8_t BIT_ERR : 1;  ///< Bit error occurred.
  uint8_t STF_ERR : 1;  ///< Stuff error occurred.
  uint8_t CRC_ERR : 1;  ///< CRC error occurred.
  uint8_t FRM_ERR : 1;  ///< Form error occurred.
  uint8_t ACK_ERR : 1;  ///< ACK error occurred.
  uint8_t ERR_DIR : 1;  ///< Direction of transfer when error occurred.
                        ///< 0: transmission ,1: reception
  uint8_t TX_WRN  : 1;  ///< Set when TX_ERR counter is greater than or equal to 96.
  uint8_t RX_WRN  : 1;  ///< Set when RX_ERR counter is greater than or equal to 96.
} can_err_code_t;

typedef struct
{
  can_err_code_t B;
  REG_ACCESS_U8  U;
} can_err_code_u;

/** \brief Receive Error Counter Register */
typedef struct
{
  uint8_t RX_ERR;       ///< This is the current receive error counter. If a bus off event occurs,
                        ///< it is initialized to 0.
} can_rx_err_cntr_t;

typedef union
{
  can_rx_err_cntr_t B;
  REG_ACCESS_U8     U;
} can_rx_err_cntr_u;

/** \brief Transmit Error Counter Register */
typedef struct
{
  uint8_t TX_ERR;     ///< This is the low-byte of the current transmit error counter as the width
                      ///< of the transmit error counter is 9-bit.
                      ///< If a bus off event occurs, it is initialized to 127 to count the minimum
                      ///< protocol defined time (128 occurrences of bus free signal). Reading
                      ///< TX_ERR during this time gives information about the status of the bus off
                      ///< recovery.
} can_tx_err_cntr_t;

typedef union
{
  can_tx_err_cntr_t B;
  REG_ACCESS_U8     U;
} can_tx_err_cntr_u;

/** \brief Arbitration Lost Code Capture Register */
typedef struct
{
  uint8_t ARB_CODE : 5; ///< This contains the bit position at which arbitration was lost during
                        ///< transmission of a message. This register is not updated until the
                        ///< previous arbitration lost interrupt has been acknowledged.
} can_arb_lost_code_t;

typedef union
{
  can_arb_lost_code_t B;
  REG_ACCESS_U8       U;
} can_arb_lost_code_u;

/** @brief Register mappings for CAN registers */
typedef struct
{
  __IO can_mode_u          CAN_MODE;
  __IO can_cmd_u           CAN_CMD;
  __IO can_status_u        CAN_STATUS;
  __IO can_int_status_u    CAN_INT_STATUS;
  __IO can_int_enable_u    CAN_INT_ENABLE;
  __IO can_rx_msg_u        CAN_RX_MSG;
  __IO can_bus_tim_0_u     CAN_BUS_TIM_0;
  __IO can_bus_tim_1_u     CAN_BUS_TIM_1;
  __IO can_tx_buf_u        CAN_TX_BUF;
  __IO can_rx_buf_u        CAN_RX_BUF;
  __IO can_acc_code_u      CAN_ACC_CODE_0;
  __IO can_acc_code_u      CAN_ACC_CODE_1;
  __IO can_acc_code_u      CAN_ACC_CODE_2;
  __IO can_acc_code_u      CAN_ACC_CODE_3;
  __IO can_acc_mask_u      CAN_ACC_MASK_0;
  __IO can_acc_mask_u      CAN_ACC_MASK_1;
  __IO can_acc_mask_u      CAN_ACC_MASK_2;
  __IO can_acc_mask_u      CAN_ACC_MASK_3;
  __IO can_err_code_u      CAN_ERR_CODE;
  __IO can_rx_err_cntr_u   CAN_RX_ERR_CNTR;
  __IO can_tx_err_cntr_u   CAN_TX_ERR_CNTR;
  __IO can_arb_lost_code_u CAN_ARB_LOST_CODE;
} can_regs_t;

/** @brief Register mappings for CAN registers */
typedef struct
{
  __IO uint8_t  CAN_MODE;
  __IO uint8_t  CAN_CMD;
  __IO uint8_t  CAN_STATUS;
  __IO uint8_t  CAN_INT_STATUS;
  __IO uint8_t  CAN_INT_ENABLE;
  __IO uint8_t  CAN_RX_MSG;
  __IO uint8_t  CAN_BUS_TIM_0;
  __IO uint8_t  CAN_BUS_TIM_1;
  __IO uint32_t CAN_TX_BUF;
  __IO uint32_t CAN_RX_BUF;
  __IO uint8_t  CAN_ACC_CODE_0;
  __IO uint8_t  CAN_ACC_CODE_1;
  __IO uint8_t  CAN_ACC_CODE_2;
  __IO uint8_t  CAN_ACC_CODE_3;
  __IO uint8_t  CAN_ACC_ENABLE_0;
  __IO uint8_t  CAN_ACC_ENABLE_1;
  __IO uint8_t  CAN_ACC_ENABLE_2;
  __IO uint8_t  CAN_ACC_ENABLE_3;
  __IO uint8_t  CAN_ERR_CODE;
  __IO uint8_t  CAN_RX_ERR_CNTR;
  __IO uint8_t  CAN_TX_ERR_CNTR;
  __IO uint8_t  CAN_ARB_LOST_CODE;
} ft900_can_regs_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#endif /* FT900_CAN_REGISTERS_H_ */
