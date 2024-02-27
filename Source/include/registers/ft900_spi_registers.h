/**
    @file ft900_spi_registers.h

    @brief SPI registers
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


#ifndef FT900_SPI_REGISTERS_H_
#define FT900_SPI_REGISTERS_H_

/* INCLUDES ************************************************************************/

#include <stdint.h>

#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

/* Register Bitfields */
#define BIT_SPIM_SPIM_CNTL_SP_R0                  (0)
#define MASK_SPIM_SPIM_CNTL_SP_R0                 (1 << BIT_SPIM_SPIM_CNTL_SP_R0)
#define BIT_SPIM_SPIM_CNTL_SP_R1                  (1)
#define MASK_SPIM_SPIM_CNTL_SP_R1                 (1 << BIT_SPIM_SPIM_CNTL_SP_R1)
#define BIT_SPIM_SPIM_CNTL_CLK_PHA                (2)
#define MASK_SPIM_SPIM_CNTL_CLK_PHA               (1 << BIT_SPIM_SPIM_CNTL_CLK_PHA)
#define BIT_SPIM_SPIM_CNTL_CLK_POL                (3)
#define MASK_SPIM_SPIM_CNTL_CLK_POL               (1 << BIT_SPIM_SPIM_CNTL_CLK_POL)
#define BIT_SPIM_SPIM_CNTL_MSTR                   (4)
#define MASK_SPIM_SPIM_CNTL_MSTR                  (1 << BIT_SPIM_SPIM_CNTL_MSTR)
#define BIT_SPIM_SPIM_CNTL_SP_R2                  (5)
#define MASK_SPIM_SPIM_CNTL_SP_R2                 (1 << BIT_SPIM_SPIM_CNTL_SP_R2)
#define BIT_SPIM_SPIM_CNTL_SP_E                   (6)
#define MASK_SPIM_SPIM_CNTL_SP_E                  (1 << BIT_SPIM_SPIM_CNTL_SP_E)
#define BIT_SPIM_SPIM_CNTL_SP_IE                  (7)
#define MASK_SPIM_SPIM_CNTL_SP_IE                 (1 << BIT_SPIM_SPIM_CNTL_SP_IE)

#define BIT_SPIM_SPIM_STATUS_SSC_EN               (0)
#define MASK_SPIM_SPIM_STATUS_SSC_EN              (1 << BIT_SPIM_SPIM_STATUS_SSC_EN)
#define BIT_SPIM_SPIM_STATUS_RX_FIFOFULL          (1)
#define MASK_SPIM_SPIM_STATUS_RX_FIFOFULL         (1 << BIT_SPIM_SPIM_STATUS_RX_FIFOFULL)
#define BIT_SPIM_SPIM_STATUS_TX_EMPTY             (2)
#define MASK_SPIM_SPIM_STATUS_TX_EMPTY            (1 << BIT_SPIM_SPIM_STATUS_TX_EMPTY)
#define BIT_SPIM_SPIM_STATUS_THRE                 (3)
#define MASK_SPIM_SPIM_STATUS_THRE                (1 << BIT_SPIM_SPIM_STATUS_THRE)
#define BIT_SPIM_SPIM_STATUS_MOD_FAULT            (4)
#define MASK_SPIM_SPIM_STATUS_MOD_FAULT           (1 << BIT_SPIM_SPIM_STATUS_MOD_FAULT)
#define BIT_SPIM_SPIM_STATUS_SPI_BIS              (5)
#define MASK_SPIM_SPIM_STATUS_SPI_BIS             (1 << BIT_SPIM_SPIM_STATUS_SPI_BIS)
#define BIT_SPIM_SPIM_STATUS_WR_COL               (6)
#define MASK_SPIM_SPIM_STATUS_WR_COL              (1 << BIT_SPIM_SPIM_STATUS_WR_COL)
#define BIT_SPIM_SPIM_STATUS_SPI_FLAG             (7)
#define MASK_SPIM_SPIM_STATUS_SPI_FLAG            (1 << BIT_SPIM_SPIM_STATUS_SPI_FLAG)

#define BIT_SPIM_SPIM_FIFO_CNTL_FIFO_EN           (0)
#define MASK_SPIM_SPIM_FIFO_CNTL_FIFO_EN          (1 << BIT_SPIM_SPIM_FIFO_CNTL_FIFO_EN)
#define BIT_SPIM_SPIM_FIFO_CNTL_RCVR_RST          (1)
#define MASK_SPIM_SPIM_FIFO_CNTL_RCVR_RST         (1 << BIT_SPIM_SPIM_FIFO_CNTL_RCVR_RST)
#define BIT_SPIM_SPIM_FIFO_CNTL_TX_RST            (2)
#define MASK_SPIM_SPIM_FIFO_CNTL_TX_RST           (1 << BIT_SPIM_SPIM_FIFO_CNTL_TX_RST)
#define BIT_SPIM_SPIM_FIFO_CNTL_TIMEOUT           (4)
#define MASK_SPIM_SPIM_FIFO_CNTL_TIMEOUT          (1 << BIT_SPIM_SPIM_FIFO_CNTL_TIMEOUT)
#define BIT_SPIM_SPIM_FIFO_CNTL_64_BYTE           (5)
#define MASK_SPIM_SPIM_FIFO_CNTL_64_BYTE          (1 << BIT_SPIM_SPIM_FIFO_CNTL_64_BYTE)
#define BIT_SPIM_SPIM_FIFO_CNTL_RCVR_TRIG         (6)
#define MASK_SPIM_SPIM_FIFO_CNTL_RCVR_TRIG        (0x3 << BIT_SPIM_SPIM_FIFO_CNTL_RCVR_TRIG)

#define BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_DUAL_SPI    (0)
#define MASK_SPIM_SPIM_TNSFR_FRMT_CNTL_DUAL_SPI   (1 << BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_DUAL_SPI)
#define BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_QUAD_SPI    (1)
#define MASK_SPIM_SPIM_TNSFR_FRMT_CNTL_QUAD_SPI   (1 << BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_QUAD_SPI)
#define BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_DIR         (2)
#define MASK_SPIM_SPIM_TNSFR_FRMT_CNTL_DIR        (1 << BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_DIR)
#define BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_TX_IEN      (3)
#define MASK_SPIM_SPIM_TNSFR_FRMT_CNTL_TX_IEN     (1 << BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_TX_IEN)

/*****************************************************
 * !!! FAST_SPI available from FT900 REV C onwards!!!
 * */

#define BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_FAST_SPI    (4)
#define MASK_SPIM_SPIM_TNSFR_FRMT_CNTL_FAST_SPI   (1 << BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_FAST_SPI)

/*****************************************************/

#define BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_MULTI_REC   (5)
#define MASK_SPIM_SPIM_TNSFR_FMRT_CNTL_MULTI_REC  (1 << BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_MULTI_REC)
#define BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_BISINT_EN   (6)
#define MASK_SPIM_SPIM_TNSFR_FRMT_CNTL_BISINT_EN  (1 << BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_BISINT_EN)
#define BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_FIFO_EXT    (7)
#define MASK_SPIM_SPIM_TNSFR_FRMT_CNTL_FIFO_EXT   (1 << BIT_SPIM_SPIM_TNSFR_FRMT_CNTL_FIFO_EXT)

/*****************************************************
 * !!! Below macros for FT930 and FT900 REV C onwards!!!
 * */

#define BIT_SPIM_SPIM_CNTL_2_RX_EMPTY             (0)
#define MASK_SPIM_SPIM_CNTL_2_RX_EMPTY            (1 << BIT_SPIM_SPIM_CNTL_2_RX_EMPTY)
#define BIT_SPIM_SPIM_CNTL_2_CHG_SPR              (1)
#define MASK_SPIM_SPIM_CNTL_2_CHG_SPR             (1 << BIT_SPIM_SPIM_CNTL_2_CHG_SPR)
#define BIT_SPIM_SPIM_CNTL_2_LSBF                 (2)
#define MASK_SPIM_SPIM_CNTL_2_LSBF                (1 << BIT_SPIM_SPIM_CNTL_2_LSBF)
#define BIT_SPIM_SPIM_CNTL_2_CLSBF                (3)
#define MASK_SPIM_SPIM_CNTL_2_CLSBF               (1 << BIT_SPIM_SPIM_CNTL_2_CLSBF)
#define BIT_SPIM_SPIM_CNTL_2_BAUD_REG_EN          (7)
#define MASK_SPIM_SPIM_CNTL_2_BAUD_REG_EN         (1 << BIT_SPIM_SPIM_CNTL_2_BAUD_REG_EN)

#define BIT_SPIM_SPIM_STATUS_2_TXFIFO_EMPTY       (0)
#define MASK_SPIM_SPIM_STATUS_2_TXFIFO_EMPTY      (1 << BIT_SPIM_SPIM_STATUS_2_TXFIFO_EMPTY)
#define BIT_SPIM_SPIM_STATUS_2_TXFIFO_FULL        (1)
#define MASK_SPIM_SPIM_STATUS_2_TXFIFO_FULL       (1 << BIT_SPIM_SPIM_STATUS_2_TXFIFO_FULL)
#define BIT_SPIM_SPIM_STATUS_2_RX_EMPTY           (2)
#define MASK_SPIM_SPIM_STATUS_2_RX_EMPTY          (1 << BIT_SPIM_SPIM_STATUS_2_RX_EMPTY)
#define BIT_SPIM_SPIM_STATUS_2_RXFIFO_FULL        (3)
#define MASK_SPIM_SPIM_STATUS_2_RXFIFO_FULL       (1 << BIT_SPIM_SPIM_STATUS_2_RXFIFO_FULL)
#define BIT_SPIM_SPIM_STATUS_2_RXFULL_OVERRIDE    (4)
#define MASK_SPIM_SPIM_STATUS_2_RXFULL_OVERRIDE   (1 << BIT_SPIM_SPIM_STATUS_2_RXFULL_OVERRIDE)
#define BIT_SPIM_SPIM_STATUS_2_TXSPIF             (5)
#define MASK_SPIM_SPIM_STATUS_2_TXSPIF            (1 << BIT_SPIM_SPIM_STATUS_2_TXSPIF)
#define BIT_SPIM_SPIM_STATUS_2_TEMT               (6)
#define MASK_SPIM_SPIM_STATUS_2_TEMT              (1 << BIT_SPIM_SPIM_STATUS_2_TEMT)

#define BIT_SPIM_SPIM_FIFO_CNTL_2_RX_TRIG_EN      (0)
#define MASK_SPIM_SPIM_FIFO_CNTL_2_RX_TRIG_EN     (1 << BIT_SPIM_SPIM_FIFO_CNTL_2_RX_TRIG_EN)
#define BIT_SPIM_SPIM_FIFO_CNTL_2_TX_TRIG_EN      (1)
#define MASK_SPIM_SPIM_FIFO_CNTL_2_TX_TRIG_EN     (1 << BIT_SPIM_SPIM_FIFO_CNTL_2_TX_TRIG_EN)
#define BIT_SPIM_SPIM_FIFO_CNTL_2_TX_TRIG_LVL     (2)
#define MASK_SPIM_SPIM_FIFO_CNTL_2_TX_TRIG_LVL    (0x3 << BIT_SPIM_SPIM_FIFO_CNTL_2_TX_TRIG_LVL)

/* TYPES ***************************************************************************/

/** SAME LAYOUT REGISTER **/

/** \brief Control Register */
typedef struct
{
  uint8_t SP_R_0_1 : 2;   ///< Together with SP_R2, they define the SPI clock rate
                          ///<     | SP_R2 | SP_R1 | SP_R0 | System Clock divided by |
                          ///<     | 0     | 0     | 0     | 4                       |
                          ///<     | 0     | 0     | 1     | 8                       |
                          ///<     | 0     | 1     | 0     | 16                      |
                          ///<     | 0     | 1     | 1     | 32                      |
                          ///<     | 1     | 0     | 0     | 64                      |
                          ///<     | 1     | 0     | 1     | 128                     |
                          ///<     | 1     | 1     | 0     | 256                     |
                          ///<     | 1     | 1     | 1     | 512                     |

  uint8_t CLK_PHA  : 1;   ///< Clock phase
                          ///<     0: Shift Data Out on Falling edge; capture Data In on Rising edge
                          ///<     1: Shift Data Out on Rising edge; capture Data In on Falling edge

  uint8_t CLK_POL  : 1;   ///< Clock polarity select
                          ///<     0: High level; SCK idles Low
                          ///<     1: Low level ; SCK idles high

  uint8_t MSTR     : 1;   ///< 1: To enable this SPI Master

  uint8_t SP_R2    : 1;   ///< See table at SP_R1 and SP_R0

  uint8_t SP_E     : 1;   ///< SPI System enable; 1 to enable.

  uint8_t SP_IE    : 1;   ///< 1: To enable SPI Master interrupt
} spim_cntl_reg_t;

/** \brief Control Register */
typedef union
{
  spim_cntl_reg_t B;
  REG_ACCESS_U8   U;
} spim_cntl_reg_u;

/** \brief Control Register (Slave mode) */
typedef spim_cntl_reg_u spis_cntl_reg_u;

/** \brief Status Register */
typedef struct
{
  uint8_t SSC_EN      : 1;  ///< Slave Select Control Enable
                            ///<     1: Auto SS assertions enabled
                            ///<     0: Auto SS assertions disabled – SS always shows
                            ///<        contents of Slave Select Control Register.

  uint8_t RX_FIFOFULL : 1;  ///< Receiver FIFO Full

  uint8_t TX_EMPTY    : 1;  ///< Transmitter Empty
                            ///<     0: TX FIFO contains at least one byte.
                            ///<     1: TX FIFO is empty

  uint8_t THRE        : 1;  ///< SPI in IDLE state with TX FIFO or THR register empty
                            ///<     0: Transmission is in progress

  uint8_t MOD_FAULT   : 1;  ///< SPI mode-fault error status flag. This flag is set if the SS pin
                            ///< goes to active low.

  uint8_t SPI_BIS     : 1;  ///< Indicates end of transmission from SPIM_ALT_DATA register. This
                            ///< flag can generate an interrupt if enabled by
                            ///< SPIM_TNSFR_FRMT_CNTL[6] = 1

  uint8_t WR_COL      : 1;  ///< Write collision error status flag. The flag is automatically set if
                            ///< the SPDR is written when the TX register is full (in FIFO Mode when
                            ///< the TX FIFO is full).

  uint8_t SPI_FLAG    : 1;  ///< Interrupt request; this flag is automatically set to one at the end
                            ///< of an SPI transfer.
} spim_status_reg_t;

/** \brief Receiver and Transmitter Data Registers */
typedef union
{
  uint8_t       SPDR_RX;    ///< Data from last Receive operation
  uint8_t       SPDR_TX;    ///< Data for next Transmit operation
  REG_ACCESS_U8 U;          ///< Access via unsigned char
} spim_data_reg_u;

/** \brief Receiver and Transmitter Data Registers (Slave mode) */
typedef spim_data_reg_u spis_data_reg_u;

/** \brief Slave Select Control Register */
typedef struct
{
  uint8_t DATA;             ///< SS7-SS0 pin select
                            ///<     0: assigned SS while Master transfer is active
                            ///<     1: SS is forced to logic 1
} spim_slv_sel_cntl_reg_t;

/** \brief Slave Select Control Register */
typedef union
{
  spim_slv_sel_cntl_reg_t B;
  REG_ACCESS_U8           U;
} spim_slv_sel_cntl_reg_u;

/** \brief Slave Select Control Register (Slave mode) */
typedef spim_slv_sel_cntl_reg_u spis_slv_sel_cntl_reg_u;

/** \brief Transfer Format Control Register */
typedef struct
{
  uint8_t DUAL_SPI   : 1;   ///< 0: Enable DUAL SPI transfer

  uint8_t QUAD_SPI   : 1;   ///< 1: Enable QUAD SPI transfer

  uint8_t DIR        : 1;   ///< 1: Performs multichannel READ (Requires DUAL/QUAD mode to be
                            ///<    enabled)

  uint8_t TX_IEN     : 1;   ///< 1: Transmitter FIFO Empty interrupt enabled

  uint8_t Reserved_4 : 1;   ///< Reserved

  uint8_t MULTI_REC  : 1;   ///< 1: Allow continuous reception of data without the necessity of
                            ///<    loading the TX FIFO

  uint8_t BISINT_EN  : 1;   ///< 1: Enable interrupt generation after the transfer is complete from
                            ///<    SPIM_ALT_DATA register

  uint8_t FIFO_EXT   : 1;   ///< 1: Enable FIFO extension and allow 16 bits data transfer to / from
                            ///<    FIFO
} spim_tnsfr_frmt_cntl_reg_t;

/** \brief Transfer Format Control Register */
typedef union
{
  spim_tnsfr_frmt_cntl_reg_t B;
  REG_ACCESS_U8              U;
} spim_tnsfr_frmt_cntl_reg_u;

/** \brief Transfer Format Control Register (Slave mode) */
typedef spim_tnsfr_frmt_cntl_reg_u spis_tnsfr_frmt_cntl_reg_u;

/** \brief Alternative SPI Master Data Register */
typedef struct
{
  uint8_t DATA;             ///< Alternative SPI Mode Data register. Data transmitted through this
                            ///< register are done as a single channel SPI only regardless of
                            ///< QUAD/DUAL mode setting
} spim_alt_data_reg_t;

/** \brief Alternative SPI Master Data Register */
typedef union
{
  spim_alt_data_reg_t B;
  REG_ACCESS_U8       U;
} spim_alt_data_reg_u;

/** \brief Alternative SPI Master Data Register (Slave mode) */
typedef spim_alt_data_reg_u spis_alt_data_reg_u;

/** \brief FIFO Control Register */
typedef struct
{
  uint8_t FIFO_EN    : 1;   ///< RX and TX FIFO’s enable

  uint8_t RCVR_RST   : 1;   ///< Write 1 to RX FIFO and its logic; The shift register is not
                            ///< affected; This bit will clear itself

  uint8_t TX_RST     : 1;   ///< Write 1 to TX FIFO and its logic; The shift register is not
                            ///< affected; This bit will clear itself

  uint8_t Reserved_3 : 1;   ///< Reserved

  uint8_t TIMEOUT    : 1;   ///< 1: Enable Timeout i

  uint8_t _64_BYTE   : 5;   ///< 1: 64 Byte deep FIFOs enabled

  uint8_t RCVR_TRIG  : 2;   ///< RCVR FIFO Trigger Level
                            ///<     | Bits | Standard FIFO | Extended FIFO |
                            ///<     |      | Mode (16W)*   | Mode (64W)*   |
                            ///<     | :--: | :-----------: | :-----------: |
                            ///<     | 00   | 01            | 01            |
                            ///<     | 01   | 04            | 16            |
                            ///<     | 10   | 08            | 32            |
                            ///<     | 11   | 14            | 56            |
                            ///< Note:* Depends on SFCR[5] value
} spim_fifo_cntl_reg_t;

/** \brief SPI Master RX FIFO Count Register */
typedef struct
{
  uint8_t RX_FIFO_COUNT : 7;  ///< The number of data entries available in the RX FIFO. The data can
                              ///< be 8-bit or 32-bit, depending on the FIFO extension setting. Note
                              ///< that the counter can only count up to 63, then rolls back to 0.
                              ///< If it is 0 and SPI_FLAG bit is 1, it means there are 64 data
                              ///< entries in the FIFO.

  uint8_t Reserved      : 1;  ///< Reserved
} spim_rx_fifo_count_reg_t;

/** \brief SPI Master RX FIFO Count Register (Slave mode) */
typedef spim_rx_fifo_count_reg_t spis_rx_fifo_count_reg_t;

/***********************/
/** EXTENDED SPI PART **/
/***********************/

/** \brief Control Register 2 */
typedef struct
{
  uint8_t RX_EMPTY      : 1;  ///< Receiver data empty
                              ///< 1: The receiver data register (SPI mode) or the receiver FIFO
                              ///<    (FIFO mode) is empty.

  uint8_t CHG_SPR       : 1;  ///< Controls the SPI clock rate together with SPR[2:0] and FAST_SPI.
                              ///<  Refer to the SPIM_CNTL register.

  uint8_t LSBF          : 1;  ///< 1: The data in SPIM_DATA is sent/received with the
                              ///<    least-significant bit first. This bit affects both TX and RX
                              ///<    operations.
                              ///< 0: The data in SPIM_DATA is sent/received with the
                              ///<    most-significant bit first.

  uint8_t ALT_DATA_LSBF : 1;  ///< 1: The data in the SPIM_ALT_DATA register (normally used for SPI
                              ///<    commands) is sent with the least significant bit first. This
                              ///<    bit affects only the TX operation.
                              ///< 0: The data in the SPIM_ALT_DATA register is sent on the bus with
                              ///<    the most-significant bit first.

  uint8_t Reserved_4_6  : 3;  ///< Reserved

  uint8_t BAUD_REG_EN   : 1;  ///< 1: The SPIM_BAUD register is used to generate the SPI clock.
                              ///< 0: The SPIM_BAUD register is disabled. The SPI clock rate is
                              ///<    controlled by SPR[2:0], FAST_SPI and CHG_SPR.
} spim_cntl_2_reg_t;

/** \brief Control Register 2 */
typedef union
{
  spim_cntl_2_reg_t B;
  REG_ACCESS_U8     U;
} spim_cntl_2_reg_u;

/** \brief Status Register 2 */
typedef struct
{
  uint8_t TX_EMPTY            : 1;  ///< 1: The transmitter data register (SPI mode) or the
                                    ///<    transmitter FIFO (FIFO mode) is empty and the bus
                                    ///<    transaction is completed.

  uint8_t TX_FIFO_FULL        : 1;  ///< 1: TX FIFO is full.
                                    ///< 0: There is at least an empty entry in the TX FIFO.

  uint8_t RX_EMPTY            : 1;  ///< 1: The receiver data register (SPI mode) or the receiver
                                    ///<    FIFO (FIFO mode) is empty.

  uint8_t RX_FIFO_FULL        : 1;  ///< 1: RX FIFO is full.
                                    ///< 0: There is at least an empty entry in the RX FIFO.

  uint8_t RX_FULL_OVER_RIDDEN : 1;  ///< 1: RX FIFO overflows and data has been overridden. This bit
                                    ///<    is cleared by reading the SPIM_DATA register.

  uint8_t TX_SPI_FLAG         : 1;  ///< 1: Indicates that the vacant entries in the TX FIFO are
                                    ///<    more than the TX FIFO trigger level.

  uint8_t TEMT                : 1;  ///< 1: In SPI mode, it indicates that the transmitter data
                                    ///<    register and the shift register are both empty. In FIFO
                                    ///<    mode, it indicates that the transmitter FIFO and the
                                    ///<    shift register are both empty.
                                    ///< 0: Indicates that either the transmitter data
                                    ///<    register/transmitter FIFO or the shift register
                                    ///<    contains a character data.

  uint8_t Reserved            : 1;  ///< Reserved
} spim_sts_2_reg_t;

/** \brief Status Register 2 */
typedef union
{
  spim_sts_2_reg_t B;
  REG_ACCESS_U8    U;
} spim_sts_2_reg_u;

/** \brief Status Register 2 (Slave) */
typedef spim_sts_2_reg_u spis_sts_2_reg_u;

/** \brief FIFO Control Register 2 */
typedef struct
{
  uint8_t RX_TRIGGER_EN  : 1;   ///< 1 : Than the enables interrupt when the RX FIFO level is
                                ///<     greater RX trigger level

  uint8_t TX_TRIGGER_EN  : 1;   ///< 1 : Than the TX trigger level. enables interrupt when the TX
                                ///<     FIFO level is greater

  uint8_t TX_TRIGGER_1_0 : 2;   ///< Transmitter FIFO Trigger Level, depending on the FIFO depth
                                ///< specified in the SPIM_FIFO_CNTL register.
                                ///<     | TX_TRIGGER | Trigger level | Trigger level in |
                                ///<     | [1:0]      | in 16-level   | 64-level FIFO    |
                                ///<     |            | FIFO Mode     | mode             |
                                ///<     | :--------- | :------------ | :--------------- |
                                ///<     | 00         | 1 level       | 1 level          |
                                ///<     | 01         | 4 levels      | 16 levels        |
                                ///<     | 10         | 8 levels      | 32 levels        |
                                ///<     | 11         | 14 levels     | 56 levels        |

  uint8_t Reserved_4_7   : 4;   ///< Reserved
} spim_fifo_cntl_2_reg_t;

/** \brief FIFO Control Register 2 */
typedef union
{
  spim_fifo_cntl_2_reg_t B;
  REG_ACCESS_U8          U;
} spim_fifo_cntl_2_reg_u;

/** \brief FIFO Control Register 2 (Slave) */
typedef spim_fifo_cntl_2_reg_u spis_fifo_cntl_2_reg_u;

/** \brief SPI Master TX FIFO Count Register */
typedef struct
{
  uint8_t TX_FIFO_COUNT : 7;  ///< The number of data entries available in the TX FIFO. The data can
                              ///< be 8-bit or 32-bit, depending on the FIFO extension setting. Note
                              ///< that the counter can only count up to 63, then rolls back to 0.
                              ///< If it is 0 and SPI_FLAG bit is 1, it means there are 64 data
                              ///< entries in the FIFO.

  uint8_t Reserved      : 1;  ///< Reserved
} spim_tx_fifo_count_reg_t;

/** \brief SPI Master TX FIFO Count Register */
typedef union
{
  spim_tx_fifo_count_reg_t B;
  REG_ACCESS_U8            U;
} spim_tx_fifo_count_reg_u;

/** \brief SPI Master TX FIFO Count Register (Slave) */
typedef spim_tx_fifo_count_reg_u spis_tx_fifo_count_reg_u;

/** \brief SPI Master Baud Register
 *  \details When the BAUD_REG_EN bit (SPIM_CNTL_2[7]) is set, the Baud register allows the user to
 *           specify an accurate SPI clock rate which ranges from 1/2 to 1/256 of the system clock
 *           rate with a resolution of 1 system clock cycle. The SPI clock period is calculated as
 *           the system clock period multiplied by the value stored in the SPIM_BAUD register. When
 *           the SPIM_BAUD register holds an even number, the SPI clock low time is equal to the SPI
 *           clock high time. When the SPIM_BAUD register holds an odd number, the default state of
 *           the SPI clock specified by SPIM_CNTL[3] (CPOL) is 1 system clock period longer than the
 *           other state.
 */
typedef struct
{
  uint8_t BAUD_FACTOR;        ///< The number of data entries available in the TX FIFO. The data can
                              ///< be 8-bit or 32-bit, depending on the FIFO extension setting. Note
                              ///< that the counter can only count up to 63, then rolls back to 0.
                              ///< If it is 0 and SPI_FLAG bit is 1, it means there are 64 data
                              ///< entries in the FIFO.
} spim_baud_reg_t;

/** \brief SPI Master Baud Register */
typedef struct
{
  spim_baud_reg_t B;
  REG_ACCESS_U8   U;
} spim_baud_reg_u;

/** \brief SPI Master Baud Register */
typedef spim_baud_reg_u spis_baud_reg_u;

/****************************************/
/** SPECIFIC CHIP REGISTER DEFINITIONS **/
/****************************************/

#if defined(__FT900__)

/** \brief Status Register (For REV C)*/
typedef struct
{
  uint8_t SSC_EN      : 1;  ///< Slave Select Control Enable
                            ///<     1: Auto SS assertions enabled
                            ///<     0: Auto SS assertions disabled – SS always shows
                            ///<        contents of Slave Select Control Register.

  uint8_t Reserved_1_2 : 1; ///< Reserved

  uint8_t THRE         : 1; ///< SPI in IDLE state with TX FIFO or THR register empty
                            ///<     0: Transmission is in progress

  uint8_t MOD_FAULT    : 1; ///< SPI mode-fault error status flag. This flag is set if the SS pin
                            ///< goes to active low.

  uint8_t SPI_BIS      : 1; ///< Indicates end of transmission from SPIM_ALT_DATA register. This
                            ///< flag can generate an interrupt if enabled by
                            ///< SPIM_TNSFR_FRMT_CNTL[6] = 1

  uint8_t WR_COL       : 1; ///< Write collision error status flag. The flag is automatically set if
                            ///< the SPDR is written when the TX register is full (in FIFO Mode when
                            ///< the TX FIFO is full).

  uint8_t SPI_FLAG     : 1; ///< Interrupt request; this flag is automatically set to one at the end
                            ///< of an SPI transfer.
} spim_status_rev_c_reg_t;

/** \brief Status Register */
typedef union
{
  spim_status_reg_t       REV_B;
  spim_status_rev_c_reg_t REV_C;
  REG_ACCESS_U8           U;
} spim_status_reg_u;

/** \brief Status Register (Slave) */
typedef union
{
  spim_status_reg_t       REV_B;
  spim_status_rev_c_reg_t REV_C;
  REG_ACCESS_U8           U;
} spis_status_reg_u;

/** \brief FIFO Control Register */
typedef struct
{
  uint8_t FIFO_EN    : 1;   ///< RX and TX FIFO’s enable

  uint8_t RCVR_RST   : 1;   ///< Write 1 to RX FIFO and its logic; The shift register is not
                            ///< affected; This bit will clear itself

  uint8_t TX_RST     : 1;   ///< Write 1 to TX FIFO and its logic; The shift register is not
                            ///< affected; This bit will clear itself

  uint8_t Reserved_3 : 1;   ///< Reserved

  uint8_t TIMEOUT    : 1;   ///< 1: Enable Timeout i

  uint8_t _64_BYTE   : 5;   ///< 1: 64 Byte deep FIFOs enabled

  uint8_t RX_TRIGGER : 2;   ///< RCVR FIFO Trigger Level
                            ///<     | Bits | Standard FIFO | Extended FIFO |
                            ///<     |      | Mode (16W)*   | Mode (64W)*   |
                            ///<     | :--: | :-----------: | :-----------: |
                            ///<     | 00   | 01            | 01            |
                            ///<     | 01   | 04            | 16            |
                            ///<     | 10   | 08            | 32            |
                            ///<     | 11   | 14            | 56            |
                            ///< Note:* Depends on SFCR[5] value
} spim_fifo_cntl_rev_c_reg_t;

/** \brief FIFO Control Register */
typedef union
{
  spim_fifo_cntl_reg_t       REV_B;
  spim_fifo_cntl_rev_c_reg_t REV_C;
  REG_ACCESS_U8              U;
} spim_fifo_cntl_reg_u;

/** \brief FIFO Control Register (Slave) */
typedef union
{
  spim_fifo_cntl_rev_c_reg_t B;
  REG_ACCESS_U8              U;
} spis_fifo_cntl_reg_u;

/** \brief SPI Master RX FIFO Count Register */
typedef struct
{
  uint8_t DATA;             ///< The number of bytes available in the RX FIFO. Note that the counter
                            ///< can only count up to 63, then rolls back to 0. If it is 0 and
                            ///< SPI_FLAG bit is 1, it means there are 64 bytes in the FIFO
} spim_rx_fifo_count_rev_b_reg_t;

/** \brief SPI Master RX FIFO Count Register */
typedef union
{
  spim_rx_fifo_count_rev_b_reg_t REV_B;
  spim_rx_fifo_count_reg_t       REV_C;
  REG_ACCESS_U8                  U;
} spim_rx_fifo_count_reg_u;

/** \brief Control Register 2 (Slave) */
typedef struct
{
  uint8_t RX_EMPTY      : 1;  ///< Receiver data empty
                              ///< 1: The receiver data register (SPI mode) or the receiver FIFO
                              ///<    (FIFO mode) is empty.

  uint8_t CHG_SPR       : 1;  ///< Determines the maximum SPI clock rate together with SPR[2:0] and
                              ///< FAST_SPI. Refer to the SPIS_CNTL register.

  uint8_t LSBF          : 1;  ///< 1: The data in SPIS_DATA is sent/received with the
                              ///<    least-significant bit first. This bit affects both TX and RX
                              ///<    operations.
                              ///< 0: The data in SPIS_DATA is sent/received with the
                              ///<    most-significant bit first.

  uint8_t ALT_DATA_LSBF : 1;  ///< 1: The data in the SPIS_ALT_DATA register (normally used for SPI
                              ///<    commands) is sent with the least-significant bit first. This
                              ///<    bit affects only the TX operation.
                              ///< 0: The data in the SPIS_ALT_DATA register is sent on the bus with
                              ///<    the most-significant bit first.

  uint8_t Reserved_4_6  : 3;  ///< Reserved

  uint8_t Reserved_7    : 1;  ///< Reserved - This bit should always be ‘0’.
} spis_cntl_2_reg_t;

/** \brief Control Register 2 (Slave) */
typedef union
{
  spis_cntl_2_reg_t B;
  REG_ACCESS_U8     U;
} spis_cntl_2_reg_u;

/** \brief Register mappings for SPI registers - for FT900 Rev B */
typedef struct
{
  __IO spim_cntl_reg_u            SPIM_CNTL;             ///< 00
       uint8_t                    Reserved_01_03[3];     ///< 01 - 03
  __IO spim_status_reg_u          SPIM_STATUS;           ///< 04
       uint8_t                    Reserved_05_07[3];     ///< 05 - 07
  __IO spim_data_reg_u            SPIM_DATA;             ///< 08
       uint8_t                    Reserved_09_11[3];     ///< 09 - 11
  __IO spim_slv_sel_cntl_reg_u    SPIM_SLV_SEL_CNTL;     ///< 12
       uint8_t                    Reserved_13_15[3];     ///< 13 - 15
  __IO spim_fifo_cntl_reg_u       SPIM_FIFO_CNTL;        ///< 16
       uint8_t                    Reserved_17_19[3];     ///< 17 - 19
  __IO spim_tnsfr_frmt_cntl_reg_u SPIM_TNSFR_FRMT_CNTL;  ///< 20
       uint8_t                    Reserved_21_23[3];     ///< 21 - 23
  __IO spim_alt_data_reg_u        SPIM_ALT_DATA;         ///< 24
       uint8_t                    Reserved_25_27[3];     ///< 25 - 27
  __IO spim_rx_fifo_count_reg_u   SPIM_RX_FIFO_COUNT;    ///< 28
       uint8_t                    Reserved_29_31[3];     ///< 29 - 31
} spim_origin_regs_t;

/** \brief Register mappings for SPI (Slave) registers - for FT900 Rev B */
typedef struct
{
  __IO spis_cntl_reg_u            SPIS_CNTL;             ///< 00
       uint8_t                    Reserved_01_03[3];     ///< 01 - 03
  __IO spis_status_reg_u          SPIS_STATUS;           ///< 4
       uint8_t                    Reserved_05_07[3];     ///< 05 - 07
  __IO spis_data_reg_u            SPIS_DATA;             ///< 8
       uint8_t                    Reserved_09_11[3];     ///< 09 - 11
  __IO spis_slv_sel_cntl_reg_u    SPIS_SLV_SEL_CNTL;     ///< 12
       uint8_t                    Reserved_13_15[3];     ///< 13 - 15
  __IO spis_fifo_cntl_reg_u       SPIS_FIFO_CNTL;        ///< 16
       uint8_t                    Reserved_17_19[3];     ///< 17 - 19
  __IO spis_tnsfr_frmt_cntl_reg_u SPIS_TNSFR_FRMT_CNTL;  ///< 20
       uint8_t                    Reserved_21_23[3];     ///< 21 - 23
  __IO spis_alt_data_reg_u        SPIM_ALT_DATA;         ///< 24
       uint8_t                    Reserved_25_27[3];     ///< 25 - 27
  __IO spis_rx_fifo_count_reg_t   SPIM_RX_FIFO_COUNT;    ///< 28
       uint8_t                    Reserved_29_31[3];     ///< 29 - 31
} spis_origin_regs_t;

/** \brief Extension to the SPI register set */
typedef struct
{
  __IO spim_cntl_2_reg_u        SPIM_CNTL_2;            ///< 00
       uint8_t                  Reserved_01_15[15];     ///< 01 - 15
  __IO spim_sts_2_reg_u         SPIM_STATUS_2;          ///< 16
       uint8_t                  Reserved_17_19[3];      ///< 17 - 19
  __IO spim_fifo_cntl_2_reg_u   SPIM_FIFO_CNTL_2;       ///< 20
       uint8_t                  Reserved_21_23[3];      ///< 21 - 23
  __IO spim_tx_fifo_count_reg_u SPIM_TX_FIFO_COUNT;     ///< 24
       uint8_t                  Reserved_25_27[3];      ///< 25 - 27
  __IO spim_baud_reg_u          SPIM_BAUD;              ///< 28
       uint8_t                  Reserved_29_31[3];      ///< 29 - 31
} spim_extend_regs_t;

/** \brief Register mappings for SPI (Slave) registers - for FT900 Rev C
 *  \note We don't have the SPIS_BAUD register on FT90x Rev C
 */
typedef struct
{
  __IO spis_cntl_2_reg_u        SPIS_CNTL_2;            ///< 00
       uint8_t                  Reserved_01_15[15];     ///< 01 - 15
  __IO spis_sts_2_reg_u         SPIS_STATUS_2;          ///< 16
       uint8_t                  Reserved_17_19[3];      ///< 17 - 19
  __IO spis_fifo_cntl_2_reg_u   SPIS_FIFO_CNTL_2;       ///< 20
       uint8_t                  Reserved_21_23[3];      ///< 21 - 23
  __IO spis_tx_fifo_count_reg_u SPIS_TX_FIFO_COUNT;     ///< 24
       uint8_t                  Reserved_25_27[3];      ///< 25 - 27
} spis_extend_regs_t;

/** \brief Register mappings for SPI registers - for FT900 Rev C */
typedef struct
{
  __IO spim_origin_regs_t origin;

  // CNTL_2 starts at a different address base (at 0x10940 for REV C).
       uint32_t           Reserved_Access[416];
  __IO spim_extend_regs_t extend;
} spim_regs_ex_t;

/** \brief Register mappings for SPI (Slave) registers - for FT900 Rev C */
typedef struct
{
  __IO spis_origin_regs_t origin;

  // CNTL_2 starts at a different address base.
       uint32_t           Reserved_Access[416];
  __IO spis_extend_regs_t extend;
} spis_regs_ex_t;

/** @brief Register mappings for SPI registers - for FT900 Rev B */
typedef struct
{
  __IO uint32_t CNTL;
  __IO uint32_t STATUS;
  __IO uint32_t DATA;
  __IO uint32_t SLV_SEL_CNTL;
  __IO uint32_t FIFO_CNTL;
  __IO uint32_t TNSFR_FRMT_CNTL;
  __IO uint32_t ALT_DATA;
  __IO uint32_t RCV_FIFO_COUNT;
} ft900_spi_regs_t;

/** @brief Register mappings for SPI registers - for FT900 Rev C */
typedef struct
{
  __IO uint32_t CNTL;
  __IO uint32_t STATUS;
  __IO uint32_t DATA;
  __IO uint32_t SLV_SEL_CNTL;
  __IO uint32_t FIFO_CNTL;
  __IO uint32_t TNSFR_FRMT_CNTL;
  __IO uint32_t ALT_DATA;
  __IO uint32_t RCV_FIFO_COUNT;
  // CNTL_2 starts at a different address base.
       uint32_t Reserved_Access[416];

  /* Below are extension to the SPI register set */
  __IO uint32_t CNTL_2;
       uint32_t reserved[3];
  __IO uint32_t STATUS_2;
  __IO uint32_t FIFO_CNTL_2;
  __IO uint32_t TX_FIFO_COUNT;
  __IO uint32_t BAUD;
} ft900_spi_regs_ex_t;

#else

/** \brief Status Register */
typedef union
{
  spim_status_reg_t B;
  REG_ACCESS_U8     U;
} spim_status_reg_u;

/** \brief Status Register (Slave) */
typedef spim_status_reg_u spis_status_reg_u;

/** \brief FIFO Control Register */
typedef union
{
  spim_fifo_cntl_reg_t B;
  REG_ACCESS_U8        U;
} spim_fifo_cntl_reg_u;

/** \brief FIFO Control Register (Slave) */
typedef spim_fifo_cntl_reg_u spis_fifo_cntl_reg_u;

/** \brief SPI Master RX FIFO Count Register */
typedef union
{
  spim_rx_fifo_count_reg_t B;
  REG_ACCESS_U8            U;
} spim_rx_fifo_count_reg_u;

/** \brief Control Register 2 (Slave) */
typedef spim_cntl_2_reg_u spis_cntl_2_reg_u;

/** \brief Register mappings for SPI (Master) registers - for FT930 */
typedef struct
{
  __IO spim_cntl_reg_u            SPIM_CNTL;             ///< 00
       uint8_t                    Reserved_01_03[3];     ///< 01 - 03
  __IO spim_status_reg_u          SPIM_STATUS;           ///< 04
       uint8_t                    Reserved_05_07[3];     ///< 05 - 07
  __IO spim_data_reg_u            SPIM_DATA;             ///< 08
       uint8_t                    Reserved_09_11[3];     ///< 09 - 11
  __IO spim_slv_sel_cntl_reg_u    SPIM_SLV_SEL_CNTL;     ///< 12
       uint8_t                    Reserved_13_15[3];     ///< 13 - 15
  __IO spim_fifo_cntl_reg_u       SPIM_FIFO_CNTL;        ///< 16
       uint8_t                    Reserved_17_19[3];     ///< 17 - 19
  __IO spim_tnsfr_frmt_cntl_reg_u SPIM_TNSFR_FRMT_CNTL;  ///< 20
       uint8_t                    Reserved_21_23[3];     ///< 21 - 23
  __IO spim_alt_data_reg_u        SPIM_ALT_DATA;         ///< 24
       uint8_t                    Reserved_25_27[3];     ///< 25 - 27
  __IO spim_rx_fifo_count_reg_u   SPIM_RX_FIFO_COUNT;    ///< 28
       uint8_t                    Reserved_29_31[3];     ///< 29 - 31

  /* Below are extension to the SPI register set */
  __IO spim_cntl_2_reg_u          SPIM_CNTL_2;           ///< 00
       uint8_t                    Reserved_01_15_[15];   ///< 01 - 15
  __IO spim_sts_2_reg_u           SPIM_STATUS_2;         ///< 16
       uint8_t                    Reserved_17_19_[3];    ///< 17 - 19
  __IO spim_fifo_cntl_2_reg_u     SPIM_FIFO_CNTL_2;      ///< 20
       uint8_t                    Reserved_21_23_[3];    ///< 21 - 23
  __IO spim_tx_fifo_count_reg_u   SPIM_TX_FIFO_COUNT;    ///< 24
       uint8_t                    Reserved_25_27_[3];    ///< 25 - 27
  __IO spim_baud_reg_u            SPIM_BAUD;             ///< 28
       uint8_t                    Reserved_29_31_[3];    ///< 29 - 31
} spim_regs_t;

/** \brief Register mappings for SPI (Slave) registers - for FT930 */
typedef struct
{
  __IO spis_cntl_reg_u            SPIS_CNTL;              ///< 00
       uint8_t                    Reserved_01_03[3];      ///< 01 - 03
  __IO spis_status_reg_u          SPIS_STATUS;            ///< 04
       uint8_t                    Reserved_05_07[3];      ///< 05 - 07
  __IO spis_data_reg_u            SPIS_DATA;              ///< 08
       uint8_t                    Reserved_09_11[3];      ///< 09 - 11
       uint8_t                    SPIS_SLV_SEL_CNTL;      ///< 12 - Reserved
       uint8_t                    Reserved_13_15[3];      ///< 13 - 15
  __IO spis_fifo_cntl_reg_u       SPIS_FIFO_CNTL;         ///< 16
       uint8_t                    Reserved_17_19[3];      ///< 17 - 19
  __IO spis_tnsfr_frmt_cntl_reg_u SPIS_TNSFR_FRMT_CNTL;   ///< 20
       uint8_t                    Reserved_21_23[3];      ///< 21 - 23
  __IO spis_alt_data_reg_u        SPIS_ALT_DATA;          ///< 24
       uint8_t                    Reserved_25_27[3];      ///< 25 - 27
  __IO spis_rx_fifo_count_reg_t   SPIS_RX_FIFO_COUNT;     ///< 28
       uint8_t                    Reserved_29_31[3];      ///< 29 - 31

  /* Below are extension to the SPI register set */
  __IO spis_cntl_2_reg_u          SPIS_CNTL_2;            ///< 00
       uint8_t                    Reserved_01_15_[15];    ///< 01 - 15
  __IO spis_status_reg_u          SPIS_STATUS_2;          ///< 16
       uint8_t                    Reserved_17_19_[3];     ///< 17 - 19
  __IO spis_fifo_cntl_2_reg_u     SPIS_FIFO_CNTL_2;       ///< 20
       uint8_t                    Reserved_21_23_[3];     ///< 21 - 23
  __IO spis_tx_fifo_count_reg_u   SPIS_TX_FIFO_COUNT;     ///< 24
       uint8_t                    Reserved_25_27_[3];     ///< 25 - 27
  __IO spis_baud_reg_u            SPIS_BAUD;              ///< 28
       uint8_t                    Reserved_29_31_[3];     ///< 29 - 31
} spis_regs_t;

/** @brief Register mappings for SPI registers - for FT930 */
typedef struct
{
  __IO uint32_t CNTL;
  __IO uint32_t STATUS;
  __IO uint32_t DATA;
  __IO uint32_t SLV_SEL_CNTL;
  __IO uint32_t FIFO_CNTL;
  __IO uint32_t TNSFR_FRMT_CNTL;
  __IO uint32_t ALT_DATA;
  __IO uint32_t RCV_FIFO_COUNT;

  /* Below are extension to the SPI register set */
  __IO uint32_t CNTL_2;
       uint32_t reserved[3];
  __IO uint32_t STATUS_2;
  __IO uint32_t FIFO_CNTL_2;
  __IO uint32_t TX_FIFO_COUNT;
  __IO uint32_t BAUD;
} ft900_spi_regs_t;

#endif

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/


#endif /* FT900_SPI_REGISTERS_H_ */
