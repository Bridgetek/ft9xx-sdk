/**
    @file ft900_i2c_registers.h

    @brief I2C registers
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


#ifndef FT900_I2C_REGISTERS_H_
#define FT900_I2C_REGISTERS_H_

/* INCLUDES ************************************************************************/

#include <stdint.h>

/* CONSTANTS ***********************************************************************/

/* I2CM_SLV_ADDR bits */
#define BIT_I2CM_SLV_ADDR_RX_OP                 (0)
#define MASK_I2CM_SLV_ADDR_RX_OP                (0x01 << BIT_I2CM_SLV_ADDR_RX_OP)
#define BIT_I2CM_SLV_ADDR_0                     (1)
#define MASK_I2CM_SLV_ADDR_0                    (0x01 << BIT_I2CM_SLV_ADDR_0)
#define BIT_I2CM_SLV_ADDR_1                     (2)
#define MASK_I2CM_SLV_ADDR_1                    (0x01 << BIT_I2CM_SLV_ADDR_1)
#define BIT_I2CM_SLV_ADDR_2                     (3)
#define MASK_I2CM_SLV_ADDR_2                    (0x01 << BIT_I2CM_SLV_ADDR_2)
#define BIT_I2CM_SLV_ADDR_3                     (4)
#define MASK_I2CM_SLV_ADDR_3                    (0x01 << BIT_I2CM_SLV_ADDR_3)
#define BIT_I2CM_SLV_ADDR_4                     (5)
#define MASK_I2CM_SLV_ADDR_4                    (0x01 << BIT_I2CM_SLV_ADDR_4)
#define BIT_I2CM_SLV_ADDR_5                     (6)
#define MASK_I2CM_SLV_ADDR_5                    (0x01 << BIT_I2CM_SLV_ADDR_5)
#define BIT_I2CM_SLV_ADDR_6                     (7)
#define MASK_I2CM_SLV_ADDR_6                    (0x01 << BIT_I2CM_SLV_ADDR_6)
#define MASK_I2CM_SLV_ADDR                      (0x7F << BIT_I2CM_SLV_ADDR_0)

/* I2CM_CNTL bits */
#define BIT_I2CM_CNTL_RUN                       (0)
#define MASK_I2CM_CNTL_RUN                      (0x01 << BIT_I2CM_CNTL_RUN)
#define BIT_I2CM_CNTL_START                     (1)
#define MASK_I2CM_CNTL_START                    (0x01 << BIT_I2CM_CNTL_START)
#define BIT_I2CM_CNTL_STOP                      (2)
#define MASK_I2CM_CNTL_STOP                     (0x01 << BIT_I2CM_CNTL_STOP)
#define BIT_I2CM_CNTL_ACK                       (3)
#define MASK_I2CM_CNTL_ACK                      (0x01 << BIT_I2CM_CNTL_ACK)
#define BIT_I2CM_CNTL_HS                        (4)
#define MASK_I2CM_CNTL_HS                       (0x01 << BIT_I2CM_CNTL_HS)
#define BIT_I2CM_CNTL_ADDR                      (5)
#define MASK_I2CM_CNTL_ADDR                     (0x01 << BIT_I2CM_CNTL_ADDR)
#define BIT_I2CM_CNTL_SLV_RST                   (6)
#define MASK_I2CM_CNTL_SLV_RST                  (0x01 << BIT_I2CM_CNTL_SLV_RST)
#define BIT_I2CM_CNTL_I2C_RST                   (7)
#define MASK_I2CM_CNTL_I2C_RST                  (0x01 << BIT_I2CM_CNTL_I2C_RST)

/* I2CM_STATUS bits  */
#define BIT_I2CM_STATUS_I2C_BUSY                (0)
#define MASK_I2CM_STATUS_I2C_BUSY               (0x01 << BIT_I2CM_STATUS_I2C_BUSY)
#define BIT_I2CM_STATUS_I2C_ERR                 (1)
#define MASK_I2CM_STATUS_I2C_ERR                (0x01 << BIT_I2CM_STATUS_I2C_ERR)
#define BIT_I2CM_STATUS_ADDR_ACK                (2)
#define MASK_I2CM_STATUS_ADDR_ACK               (0x01 << BIT_I2CM_STATUS_ADDR_ACK)
#define BIT_I2CM_STATUS_DATA_ACK                (3)
#define MASK_I2CM_STATUS_DATA_ACK               (0x01 << BIT_I2CM_STATUS_DATA_ACK)
#define BIT_I2CM_STATUS_ARB_LOST                (4)
#define MASK_I2CM_STATUS_ARB_LOST               (0x01 << BIT_I2CM_STATUS_ARB_LOST)
#define BIT_I2CM_STATUS_I2C_IDLE                (5)
#define MASK_I2CM_STATUS_I2C_IDLE               (0x01 << BIT_I2CM_STATUS_I2C_IDLE)
#define BIT_I2CM_STATUS_BUS_BUSY                (6)
#define MASK_I2CM_STATUS_BUS_BUSY               (0x01 << BIT_I2CM_STATUS_BUS_BUSY)

/* I2CM_TIME_PERIOD bits */
#define BIT_I2CM_TIME_PERIOD_STD_FAST_FPLUS     (0)
#define MASK_I2CM_TIME_PERIOD_STD_FAST_FPLUS    (0x7F << BIT_I2CM_TIME_PERIOD_STD_FAST_FPLUS)
#define BIT_I2CM_TIME_PERIOD_HIGHSPEED          (0)
#define MASK_I2CM_TIME_PERIOD_HIGHSPEED         (0x1F << BIT_I2CM_TIME_PERIOD_HIGHSPEED)
#define BIT_I2CM_TIME_PERIOD_FS_SELECT          (6)
#define MASK_I2CM_TIME_PERIOD_FS_SELECT         (0x01 << BIT_I2CM_TIME_PERIOD_FS_SELECT)
#define BIT_I2CM_TIME_PERIOD_HS_SELECT          (7)
#define MASK_I2CM_TIME_PERIOD_HS_SELECT         (0x01 << BIT_I2CM_TIME_PERIOD_HS_SELECT)

/* I2CM_FIFO_LEN bits */
#define BIT_I2CM_FIFO_BL_0                      (0)
#define MASK_I2CM_FIFO_BL_0                     (0x01 << BIT_I2CM_FIFO_BL_0)
#define BIT_I2CM_FIFO_BL_1                      (1)
#define MASK_I2CM_FIFO_BL_1                     (0x01 << BIT_I2CM_FIFO_BL_1)
#define BIT_I2CM_FIFO_BL_2                      (2)
#define MASK_I2CM_FIFO_BL_2                     (0x01 << BIT_I2CM_FIFO_BL_2)
#define BIT_I2CM_FIFO_BL_3                      (3)
#define MASK_I2CM_FIFO_BL_3                     (0x01 << BIT_I2CM_FIFO_BL_3)
#define BIT_I2CM_FIFO_BL_4                      (4)
#define MASK_I2CM_FIFO_BL_4                     (0x01 << BIT_I2CM_FIFO_BL_4)
#define BIT_I2CM_FIFO_BL_5                      (5)
#define MASK_I2CM_FIFO_BL_5                     (0x01 << BIT_I2CM_FIFO_BL_5)
#define BIT_I2CM_FIFO_BL_6                      (6)
#define MASK_I2CM_FIFO_BL_6                     (0x01 << BIT_I2CM_FIFO_BL_6)
#define BIT_I2CM_FIFO_BL_7                      (7)
#define MASK_I2CM_FIFO_BL_7                     (0x01 << BIT_I2CM_FIFO_BL_7)
#define MASK_I2CM_FIFO_LEN                      (0xFF << BIT_I2CM_FIFO_BL_0)

/* I2CM_FIFO_INT_ENABLE bits */
#define BIT_I2CM_FIFO_INT_ENABLE_TX_EMPTY       (0)
#define MASK_I2CM_FIFO_INT_ENABLE_TX_EMPTY      (0x01 << BIT_I2CM_FIFO_INT_ENABLE_TX_EMPTY)
#define BIT_I2CM_FIFO_INT_ENABLE_TX_HALF        (1)
#define MASK_I2CM_FIFO_INT_ENABLE_TX_HALF       (0x01 << BIT_I2CM_FIFO_INT_ENABLE_TX_HALF)
#define BIT_I2CM_FIFO_INT_ENABLE_TX_FULL        (2)
#define MASK_I2CM_FIFO_INT_ENABLE_TX_FULL       (0x01 << BIT_I2CM_FIFO_INT_ENABLE_TX_FULL)
#define BIT_I2CM_FIFO_INT_ENABLE_RX_EMPTY       (3)
#define MASK_I2CM_FIFO_INT_ENABLE_RX_EMPTY      (0x01 << BIT_I2CM_FIFO_INT_ENABLE_RX_EMPTY)
#define BIT_I2CM_FIFO_INT_ENABLE_RX_HALF        (4)
#define MASK_I2CM_FIFO_INT_ENABLE_RX_HALF       (0x01 << BIT_I2CM_FIFO_INT_ENABLE_RX_HALF)
#define BIT_I2CM_FIFO_INT_ENABLE_RX_FULL        (5)
#define MASK_I2CM_FIFO_INT_ENABLE_RX_FULL       (0x01 << BIT_I2CM_FIFO_INT_ENABLE_RX_FULL)
#define BIT_I2CM_FIFO_INT_ENABLE_I2C_INT        (6)
#define MASK_I2CM_FIFO_INT_ENABLE_I2C_INT       (0x01 << BIT_I2CM_FIFO_INT_ENABLE_I2C_INT)
#define BIT_I2CM_FIFO_INT_ENABLE_DONE           (7)
#define MASK_I2CM_FIFO_INT_ENABLE_DONE          (0x01 << BIT_I2CM_FIFO_INT_ENABLE_DONE)

/* I2CM_FIFO_INT_PEND bits */
#define BIT_I2CM_FIFO_INT_PEND_TX_EMPTY         (0)
#define MASK_I2CM_FIFO_INT_PEND_TX_EMPTY        (0x01 << BIT_I2CM_FIFO_INT_PEND_TX_EMPTY)
#define BIT_I2CM_FIFO_INT_PEND_TX_HALF          (1)
#define MASK_I2CM_FIFO_INT_PEND_TX_HALF         (0x01 << BIT_I2CM_FIFO_INT_PEND_TX_HALF)
#define BIT_I2CM_FIFO_INT_PEND_TX_FULL          (2)
#define MASK_I2CM_FIFO_INT_PEND_TX_FULL         (0x01 << BIT_I2CM_FIFO_INT_PEND_TX_FULL)
#define BIT_I2CM_FIFO_INT_PEND_RX_EMPTY         (3)
#define MASK_I2CM_FIFO_INT_PEND_RX_EMPTY        (0x01 << BIT_I2CM_FIFO_INT_PEND_RX_EMPTY)
#define BIT_I2CM_FIFO_INT_PEND_RX_HALF          (4)
#define MASK_I2CM_FIFO_INT_PEND_RX_HALF         (0x01 << BIT_I2CM_FIFO_INT_PEND_RX_HALF)
#define BIT_I2CM_FIFO_INT_PEND_RX_FULL          (5)
#define MASK_I2CM_FIFO_INT_PEND_RX_FULL         (0x01 << BIT_I2CM_FIFO_INT_PEND_RX_FULL)
#define BIT_I2CM_FIFO_INT_PEND_I2C_INT          (6)
#define MASK_I2CM_FIFO_INT_PEND_I2C_INT         (0x01 << BIT_I2CM_FIFO_INT_PEND_I2C_INT)
#define BIT_I2CM_FIFO_INT_PEND_DONE             (7)
#define MASK_I2CM_FIFO_INT_PEND_DONE            (0x01 << BIT_I2CM_FIFO_INT_PEND_DONE)

/* I2CM_FIFO_DATA bits */
#define BIT_I2CM_FIFO_DATA_0                    (0)
#define MASK_I2CM_FIFO_DATA_0                   (0x01 << BIT_I2CM_FIFO_DATA_0)
#define BIT_I2CM_FIFO_DATA_1                    (1)
#define MASK_I2CM_FIFO_DATA_1                   (0x01 << BIT_I2CM_FIFO_DATA_1)
#define BIT_I2CM_FIFO_DATA_2                    (2)
#define MASK_I2CM_FIFO_DATA_2                   (0x01 << BIT_I2CM_FIFO_DATA_2)
#define BIT_I2CM_FIFO_DATA_3                    (3)
#define MASK_I2CM_FIFO_DATA_3                   (0x01 << BIT_I2CM_FIFO_DATA_3)
#define BIT_I2CM_FIFO_DATA_4                    (4)
#define MASK_I2CM_FIFO_DATA_4                   (0x01 << BIT_I2CM_FIFO_DATA_4)
#define BIT_I2CM_FIFO_DATA_5                    (5)
#define MASK_I2CM_FIFO_DATA_5                   (0x01 << BIT_I2CM_FIFO_DATA_5)
#define BIT_I2CM_FIFO_DATA_6                    (6)
#define MASK_I2CM_FIFO_DATA_6                   (0x01 << BIT_I2CM_FIFO_DATA_6)
#define BIT_I2CM_FIFO_DATA_7                    (7)
#define MASK_I2CM_FIFO_DATA_7                   (0x01 << BIT_I2CM_FIFO_DATA_7)
#define MASK_I2CM_FIFO_DATA                     (0xFF << BIT_I2CM_FIFO_DATA_0)

/* I2CM_TRIG bits */
#define BIT_I2CM_TRIG_RX_OP                     (7)
#define MASK_I2CM_TRIG_RX_OP                    (0x01 << BIT_I2CM_TRIG_RX_OP)

/* I2CS_OWN_ADDR bits */
#define BIT_I2CS_OWN_ADDR_0                     (0)
#define MASK_I2CS_OWN_ADDR_0                    (0x01 << BIT_I2CS_OWN_ADDR_0)
#define BIT_I2CS_OWN_ADDR_1                     (1)
#define MASK_I2CS_OWN_ADDR_1                    (0x01 << BIT_I2CS_OWN_ADDR_1)
#define BIT_I2CS_OWN_ADDR_2                     (2)
#define MASK_I2CS_OWN_ADDR_2                    (0x01 << BIT_I2CS_OWN_ADDR_2)
#define BIT_I2CS_OWN_ADDR_3                     (3)
#define MASK_I2CS_OWN_ADDR_3                    (0x01 << BIT_I2CS_OWN_ADDR_3)
#define BIT_I2CS_OWN_ADDR_4                     (4)
#define MASK_I2CS_OWN_ADDR_4                    (0x01 << BIT_I2CS_OWN_ADDR_4)
#define BIT_I2CS_OWN_ADDR_5                     (5)
#define MASK_I2CS_OWN_ADDR_5                    (0x01 << BIT_I2CS_OWN_ADDR_5)
#define BIT_I2CS_OWN_ADDR_6                     (6)
#define MASK_I2CS_OWN_ADDR_6                    (0x01 << BIT_I2CS_OWN_ADDR_6)
#define MASK_I2CS_OWN_ADDR                      (0x7F << BIT_I2CS_OWN_ADDR_0)

/* I2CS_CNTL bits */
#define BIT_I2CS_CNTL_SEND_FIN_CLR              (2)
#define MASK_I2CS_CNTL_SEND_FIN_CLR             (0x01 << BIT_I2CS_CNTL_SEND_FIN_CLR)
#define BIT_I2CS_CNTL_REC_FIN_CLR               (3)
#define MASK_I2CS_CNTL_REC_FIN_CLR              (0x01 << BIT_I2CS_CNTL_REC_FIN_CLR)
#define BIT_I2CS_CNTL_DEV_ACTV                  (6)
#define MASK_I2CS_CNTL_DEV_ACTV                 (0x01 << BIT_I2CS_CNTL_DEV_ACTV)
#define BIT_I2CS_CNTL_I2C_RST                   (7)
#define MASK_I2CS_CNTL_I2C_RST                  (0x01 << BIT_I2CS_CNTL_I2C_RST)

/* I2CS_STATUS bits  */
#define BIT_I2CS_STATUS_RX_REQ                  (0)
#define MASK_I2CS_STATUS_RX_REQ                 (0x01 << BIT_I2CS_STATUS_RX_REQ)
#define BIT_I2CS_STATUS_TX_REQ                  (1)
#define MASK_I2CS_STATUS_TX_REQ                 (0x01 << BIT_I2CS_STATUS_TX_REQ)
#define BIT_I2CS_STATUS_SEND_FIN                (2)
#define MASK_I2CS_STATUS_SEND_FIN               (0x01 << BIT_I2CS_STATUS_SEND_FIN)
#define BIT_I2CS_STATUS_REC_FIN                 (3)
#define MASK_I2CS_STATUS_REC_FIN                (0x01 << BIT_I2CS_STATUS_REC_FIN)
#define BIT_I2CS_STATUS_BUS_ACTV                (4)
#define MASK_I2CS_STATUS_BUS_ACTV               (0x01 << BIT_I2CS_STATUS_BUS_ACTV)
#define BIT_I2CS_STATUS_DEV_ACTV                (6)
#define MASK_I2CS_STATUS_DEV_ACTV               (0x01 << BIT_I2CS_STATUS_DEV_ACTV)

/* I2CS_FIFO_INT_ENABLE bits */
#define BIT_I2CS_FIFO_INT_ENABLE_TX_EMPTY       (0)
#define MASK_I2CS_FIFO_INT_ENABLE_TX_EMPTY      (0x01 << BIT_I2CS_FIFO_INT_ENABLE_TX_EMPTY)
#define BIT_I2CS_FIFO_INT_ENABLE_TX_HALF        (1)
#define MASK_I2CS_FIFO_INT_ENABLE_TX_HALF       (0x01 << BIT_I2CS_FIFO_INT_ENABLE_TX_HALF)
#define BIT_I2CS_FIFO_INT_ENABLE_TX_FULL        (2)
#define MASK_I2CS_FIFO_INT_ENABLE_TX_FULL       (0x01 << BIT_I2CS_FIFO_INT_ENABLE_TX_FULL)
#define BIT_I2CS_FIFO_INT_ENABLE_RX_EMPTY       (3)
#define MASK_I2CS_FIFO_INT_ENABLE_RX_EMPTY      (0x01 << BIT_I2CS_FIFO_INT_ENABLE_RX_EMPTY)
#define BIT_I2CS_FIFO_INT_ENABLE_RX_HALF        (4)
#define MASK_I2CS_FIFO_INT_ENABLE_RX_HALF       (0x01 << BIT_I2CS_FIFO_INT_ENABLE_RX_HALF)
#define BIT_I2CS_FIFO_INT_ENABLE_RX_FULL        (5)
#define MASK_I2CS_FIFO_INT_ENABLE_RX_FULL       (0x01 << BIT_I2CS_FIFO_INT_ENABLE_RX_FULL)
#define BIT_I2CS_FIFO_INT_ENABLE_I2C_INT        (6)
#define MASK_I2CS_FIFO_INT_ENABLE_I2C_INT       (0x01 << BIT_I2CS_FIFO_INT_ENABLE_I2C_INT)
#define BIT_I2CS_FIFO_INT_ENABLE_DONE           (7)
#define MASK_I2CS_FIFO_INT_ENABLE_DONE          (0x01 << BIT_I2CS_FIFO_INT_ENABLE_DONE)

/* I2CS_FIFO_INT_PEND bits */
#define BIT_I2CS_FIFO_INT_PEND_TX_EMPTY         (0)
#define MASK_I2CS_FIFO_INT_PEND_TX_EMPTY        (0x01 << BIT_I2CS_FIFO_INT_PEND_TX_EMPTY)
#define BIT_I2CS_FIFO_INT_PEND_TX_HALF          (1)
#define MASK_I2CS_FIFO_INT_PEND_TX_HALF         (0x01 << BIT_I2CS_FIFO_INT_PEND_TX_HALF)
#define BIT_I2CS_FIFO_INT_PEND_TX_FULL          (2)
#define MASK_I2CS_FIFO_INT_PEND_TX_FULL         (0x01 << BIT_I2CS_FIFO_INT_PEND_TX_FULL)
#define BIT_I2CS_FIFO_INT_PEND_RX_EMPTY         (3)
#define MASK_I2CS_FIFO_INT_PEND_RX_EMPTY        (0x01 << BIT_I2CS_FIFO_INT_PEND_RX_EMPTY)
#define BIT_I2CS_FIFO_INT_PEND_RX_HALF          (4)
#define MASK_I2CS_FIFO_INT_PEND_RX_HALF         (0x01 << BIT_I2CS_FIFO_INT_PEND_RX_HALF)
#define BIT_I2CS_FIFO_INT_PEND_RX_FULL          (5)
#define MASK_I2CS_FIFO_INT_PEND_RX_FULL         (0x01 << BIT_I2CS_FIFO_INT_PEND_RX_FULL)
#define BIT_I2CS_FIFO_INT_PEND_I2C_INT          (6)
#define MASK_I2CS_FIFO_INT_PEND_I2C_INT         (0x01 << BIT_I2CS_FIFO_INT_PEND_I2C_INT)
#define BIT_I2CS_FIFO_INT_PEND_DONE             (7)
#define MASK_I2CS_FIFO_INT_PEND_DONE            (0x01 << BIT_I2CS_FIFO_INT_PEND_DONE)

/* I2CS_TRIG bits */
#define BIT_I2CS_TRIG_RX_OP                     (7)
#define MASK_I2CS_TRIG_RX_OP                    (0x01 << BIT_I2CS_TRIG_RX_OP)

/* TYPES ***************************************************************************/

/** \brief Slave Address Register */
typedef struct
{
  uint8_t RX_OP    : 1;   ///< 0: Next operation is a transmission
                          ///< 1: Next operation is a reception

  uint8_t SLV_ADDR : 7;   ///< This is 7-bit address bits
} i2cm_slv_addr_reg_t;

typedef union
{
  i2cm_slv_addr_reg_t B;
  REG_ACCESS_U8       U;
} i2cm_slv_addr_reg_u;

/** \brief Control Register */
typedef struct
{
  uint8_t RUN     : 1;    ///< Setting this will cause the Bus controller to be active.

  uint8_t START   : 1;    ///< Setting this will cause the START or Repeated START condition to be
                          ///< generated.

  uint8_t STOP    : 1;    ///< Setting this will cause the STOP condition to be generated.

  uint8_t ACK     : 1;    ///< This bit should normally be set when the Master is in the receiver
                          ///< mode to generate ACK. It must be cleared when the master requires no
                          ///< further data from the Slave transmitter.

  uint8_t HS      : 1;    ///< Setting this together with the RUN bit switches the Bus controller
                          ///< into high-speed mode.

  uint8_t ADDR    : 1;    ///< Setting this together with the RUN bit will cause the generation of
                          ///< a START condition and transmission of a Slave address.

  uint8_t SLV_RST : 1;    ///< If set together with the RUN bit, the master will generate 9 I2C
                          ///< clocks without generating the START condition to recover a blocking
                          ///< Slave device to a known state. A STOP condition will be generated.
                          ///< This bit will be automatically cleared.

  uint8_t I@C_RST : 1;    ///< Resets the whole I2C Master controller.
} i2cm_cntl_reg_t;

/** \brief Status Register */
typedef struct
{
  uint8_t I2C_BUSY : 1;   ///< 1: Indicates that the Bus controller is receiving / transmitting data
                          ///<    on the bus; other status bits of the Status register are not valid

  uint8_t I2C_ERR  : 1;   ///< 1: Indicates an error occurred during the last operation – ARB_LOST,
                          ///<    DATA_ACK or ADDR_ACK

  uint8_t ADDR_ACK : 1;   ///< 1: Indicates that during the last operation the slave address wasn’t
                          ///<    acknowledged.

  uint8_t DATA_ACK : 1;   ///< 1: Indicates that during the last transmit operation data wasn’t
                          ///<    acknowledged.

  uint8_t ARB_LOST : 1;   ///< 1: Indicates that during the last operation the Bus controller lost
                          ///<    the arbitration

  uint8_t I2C_IDLE : 1;   ///< 1: Indicates the Bus controller is in the IDLE state.

  uint8_t BUS_BUSY : 1;   ///< 1: Indicates the Bus is Busy, and access is not possible.
                          ///<    It’s reset by START/STOP conditions.

  uint8_t Reserved : 1;   ///< Reserved
} i2cm_status_reg_t;

typedef union
{
  i2cm_cntl_reg_t   B;
  i2cm_status_reg_t B;
  REG_ACCESS_U8   U;
} i2cm_cntl_sts_reg_u;

/** \brief Receive / Transmit Data Register */
typedef struct
{
  uint8_t DATA;           ///< When read, this is the data received in the last transaction.
                          ///< When written, this is the data to be transmitted in the next
                          ///< transaction.
} i2cm_data_reg_t;

typedef union
{
  i2cm_data_reg_t B;
  REG_ACCESS_U8   U;
} i2cm_data_reg_u;

/** \brief Timer Period Register */
typedef struct
{
  uint8_t SCL_LP   : 7;   ///< Frequency scaler used in STANDARD_FAST and FAST_PLUS modes. The value
                          ///< is appended with a 1 at LSB to make it 8-bit.
                          ///< SCL_PERIOD = (SCL_LP[6] * 128 + SCL_LP[5] * 64 +
                          ///<               SCL_LP[4] * 32  + SCL_LP[3] * 16 +
                          ///<               SCL_LP[2] * 8   + SCL_LP[1] * 4  +
                          ///<               SCL_LP[0] * 2 + 1) * CLK_PERIOD

  uint8_t TIME_ENB : 1;   ///< Cleared to use this register.
} i2cm_time_period_reg_t;

/** \brief High Speed Timer Period Register */
typedef struct
{
  uint8_t SCL_HP   : 5;   ///< Frequency scalar used in FAST mode. The value is appended with a 1 at
                          ///< the LSB and prepended with 2 0’s to make it 8-bit.
                          ///< SCL_PERIOD = (SCL_HP[4] * 32 + SCL_HP[3] * 16 +
                          ///<               SCL_HP[2] * 8  + SCL_HP[1] * 4  +
                          ///<               SCL_HP[0] * 2 + 1) * CLK_PERIOD

  uint8_t Reserved : 1;   ///< Reserved

  uint8_t FAST     : 1;   ///< Set to indicate to the Bus controller to use FAST generic timing
                          ///< parameters.

  uint8_t TIME_ENB : 1;   ///< Set to use this register.
} i2cm_hs_time_period_reg_t;

typedef union
{
  i2cm_time_period_reg_t    B0;
  i2cm_hs_time_period_reg_t B1;
  REG_ACCESS_U8             U;
} i2cm_time_period_reg_u;

/** \brief FIFO Mode Byte Length */
typedef struct
{
  uint8_t FIFO_BL;        ///< Number of bytes (FIFO_BL + 1) to transmit / receive when FIFO mode is
                          ///< enabled
} i2cm_fifo_len_reg_t;

typedef union
{
  i2cm_fifo_len_reg_t B;
  REG_ACCESS_U8       U;
} i2cm_fifo_len_reg_u;

/** \brief FIFO Mode Interrupt Enable */
typedef struct
{
  uint8_t TX_EMPTY : 1;   ///< TX FIFO Empty interrupt enable
  uint8_t TX_HALF  : 1;   ///< TX FIFO Half Full interrupt enable
  uint8_t TX_FULL  : 1;   ///< TX FIFO Full interrupt enable
  uint8_t RX_EMPTY : 1;   ///< RX FIFO Empty interrupt enable
  uint8_t RX_HALF  : 1;   ///< RX FIFO Half Full interrupt enable
  uint8_t RX_FULL  : 1;   ///< RX FIFO Full interrupt enable
  uint8_t I2C_INT  : 1;   ///< I2C Interrupt status
  uint8_t DONE     : 1;   ///< FIFO_BL operation completed Interrupt
} i2cm_fifo_int_ena_reg_t;

typedef union
{
  i2cm_fifo_int_ena_reg_t B;
  REG_ACCESS_U8           U;
} i2cm_fifo_int_ena_reg_u;

/** \brief FIFO Mode Interrupt Pending */
typedef struct
{
  uint8_t TX_EMPTY : 1;   ///< TX FIFO Empty interrupt pending
  uint8_t TX_HALF  : 1;   ///< TX FIFO Half Full interrupt pending
  uint8_t TX_FULL  : 1;   ///< TX FIFO Full interrupt pending
  uint8_t RX_EMPTY : 1;   ///< RX FIFO Empty interrupt pending
  uint8_t RX_HALF  : 1;   ///< RX FIFO Half Full interrupt pending
  uint8_t RX_FULL  : 1;   ///< RX FIFO Full interrupt pending
  uint8_t I2C_INT  : 1;   ///< I2C Interrupt pending
  uint8_t DONE     : 1;   ///< FIFO_BL operation complete interrupt pending
} i2cm_fifo_int_pend_reg_t;

typedef union
{
  i2cm_fifo_int_pend_reg_t B;
  REG_ACCESS_U8            U;
} i2cm_fifo_int_pend_reg_u;

/** \brief FIFO Data Register */
typedef struct
{
  uint8_t FIFO_DATA;      ///< FIFO Data Read from RX Buffer
} i2cm_fifo_data_reg_t;

typedef union
{
  i2cm_fifo_data_reg_t B;
  REG_ACCESS_U8        U;
} i2cm_fifo_data_reg_u;

/** \brief Trigger Register */
typedef struct
{
  uint8_t Reserved_0_6 : 7;   ///< Reserved
  uint8_t RX_OP        : 1;   ///< A write to this register triggers the FIFO mode operation. Set
                              ///< this bit to 1 for RX, and 0 for TX FIFO operations.
                              ///< The operation will end when FIFO_BL expires.
} i2cm_trig_reg_t;

typedef union
{
  i2cm_trig_reg_t B;
  REG_ACCESS_U8   U;
} i2cm_trig_reg_u;

/** @brief Register mappings for I2C Master registers */
typedef struct
{
  __IO i2cm_slv_addr_reg_u      I2CM_SLV_ADDR;          ///< Slave address register
  __IO i2cm_cntl_sts_reg_u      I2CM_CNTL_STATUS;       ///< Control and Status register
  __IO i2cm_data_reg_u          I2CM_DATA;              ///< Receive / transmit data register
  __IO i2cm_time_period_reg_u   I2CM_TIME_PERIOD;       ///< Timer period register
  __IO i2cm_fifo_len_reg_u      I2CM_FIFO_LEN;          ///< FIFO mode byte length register
  __IO i2cm_fifo_int_ena_reg_u  I2CM_FIFO_INT_ENABLE;   ///< FIFO mode interrupt enable register
  __IO i2cm_fifo_int_pend_reg_u I2CM_FIFO_INT_PEND;     ///< FIFO mode interrupt pending register
  __IO i2cm_fifo_data_reg_u     I2CM_FIFO_DATA;         ///< FIFO mode interrupt pending register
  __IO i2cm_trig_reg_u          I2CM_TRIG;              ///< FIFO transfer trigger register
} i2cm_regs_t;

/** @brief Register mappings for I2C Master registers */
typedef struct
{
  __IO uint8_t I2CM_SLV_ADDR;         ///< Slave address register
  __IO uint8_t I2CM_CNTL_STATUS;      ///< Control and Status register
  __IO uint8_t I2CM_DATA;             ///< Receive / transmit data register
  __IO uint8_t I2CM_TIME_PERIOD;      ///< Timer period register
  __IO uint8_t I2CM_FIFO_LEN;         ///< FIFO mode byte length register
  __IO uint8_t I2CM_FIFO_INT_ENABLE;  ///< FIFO mode interrupt enable register
  __IO uint8_t I2CM_FIFO_INT_PEND;    ///< FIFO mode interrupt pending register
  __IO uint8_t I2CM_FIFO_DATA;        ///< FIFO data register
  __IO uint8_t I2CM_TRIG;             ///< FIFO transfer trigger register
} ft900_i2cm_regs_t;

/** \brief Own Address Register */
typedef struct
{
  uint8_t OWN_ADDR : 7;       ///< This is the seven address bits of the Slave controller.
  uint8_t Reserved : 1;       ///< Reserved
} i2cs_own_addr_reg_t;

typedef union
{
  i2cs_own_addr_reg_t B;
  REG_ACCESS_U8       U;
} i2cs_own_addr_reg_u;

/** \brief Control Register */
typedef struct
{
  uint8_t Reserved_0_1 : 2;   ///< Reserved

  uint8_t SEND_FIN_CLR : 1;   ///< Writing 1 to this bit clears SEND_FIN bit from the Status
                              ///< register.

  uint8_t REC_FIN_CLR  : 3;   ///< Writing 1 to this bit clears REC_FIN bit from the Status
                              ///< register.

  uint8_t Reserved_4_5 : 2;   ///< Reserved

  uint8_t DEV_ACTV     : 1;   ///< Device Active
                              ///< 1: Enables the Slave controller operations
                              ///< 0: Disables the Slave controller operations
                              ///< Writing a 1 sets DEV_ACTV to 1 immediately while writing 0 will
                              ///< not be effective immediately if there is any on-going
                              ///< transmission. It’s suggested that this bit is polled if a 0 is
                              ///< written.

  uint8_t I2C_RST      : 1;   ///< Setting this bit will reset the whole Slave controller.
} i2cs_cntl_reg_t;

/** \brief Status Register */
typedef struct
{
  uint8_t RX_REQ     : 1;     ///< 1: Indicates the Slave controller has received data from the
                              ///<    Master. It is automatically cleared by reading of I2CS_DATA.

  uint8_t TX_REQ     : 1;     ///< 1: Indicates the Slave controller is addressed as transmitter and
                              ///<    requires data from the host device.

  uint8_t SEND_FIN   : 1;     ///< 1: Indicates that the Master has ended the receive operation. It
                              ///<    means no more TX_REQ will be set during this single or burst
                              ///<    send operation. It is cleared by writing 1 to SEND_FINCLR bit
                              ///<    in the Control register.

  uint8_t REC_FIN    : 1;     ///< 1: Indicates that the Master has ended the transmit operation. It
                              ///<    means no more RX_REQ will be set during this single or bursts
                              ///<    receive operation. It is cleared by writing 1 to REC_FINCLR
                              ///<    bit in the Control register.

  uint8_t BUS_ACTV   : 1;     ///< 1: Indicates that there is transmission: send, receive or own
                              ///<    address detection in progress

  uint8_t Reserved_5 : 1;     ///< Reserved

  uint8_t DEV_ACTV   : 1;     ///< Device Active
                              ///< 1: Enables the Slave controller operations
                              ///< 0: Disables the Slave controller operations
                              ///< Writing a 1 set DEV_ACTV to 1 immediately while writing 0 will
                              ///< not be effective immediately if there is any on-going
                              ///< transmission. It’s suggested that this bit is polled if a 0 is
                              ///< written.

  uint8_t Reserved_7 : 1;     ///< Reserved
} i2cs_status_reg_t;

typedef union
{
  i2cs_cntl_reg_t   B0;
  i2cs_status_reg_t B1;
  REG_ACCESS_U8     U;
} i2cs_cntl_sts_reg_u;

/** \brief Receive / Transmit Data Register */
typedef struct
{
  uint8_t DATA;               ///< When read, this is the data received in the last  transaction.
                              ///< When written, this is the data to be transmitted in the
                              ///< next transaction.
} i2cs_data_reg_t;

typedef union
{
  i2cs_data_reg_t B;
  REG_ACCESS_U8   U;
} i2cs_data_reg_u;

/** \brief FIFO Mode Byte Length */
typedef struct
{
  uint8_t FIFO_BL;            ///< Number of bytes (FIFO_BL + 1) to transmit / receive when FIFO
                              ///< mode is enabled
} i2cs_fifo_len_reg_t;

typedef union
{
  i2cs_fifo_len_reg_t B;
  REG_ACCESS_U8       U;
} i2cs_fifo_len_reg_u;

/** \brief FIFO Mode Interrupt Enable */
typedef struct
{
  uint8_t TX_EMPTY : 1;       ///< TX FIFO Empty interrupt enable
  uint8_t TX_HALF  : 1;       ///< TX FIFO Half Full interrupt enable
  uint8_t TX_FULL  : 1;       ///< TX FIFO Full interrupt enable
  uint8_t RX_EMPTY : 1;       ///< RX FIFO Empty interrupt enable
  uint8_t RX_HALF  : 1;       ///< RX FIFO Half Full interrupt enable
  uint8_t RX_FULL  : 1;       ///< RX FIFO Full interrupt enable
  uint8_t I2C_INT  : 1;       ///< I2C Interrupt
  uint8_t DONE     : 1;       ///< FIFO_BL operation completed Interrupt
} i2cs_fifo_int_ena_reg_t;

typedef union
{
  i2cs_fifo_int_ena_reg_t B;
  REG_ACCESS_U8           U;
} i2cs_fifo_int_ena_reg_u;

/** \brief Mode Interrupt Pending */
typedef struct
{
  uint8_t TX_EMPTY : 1;       ///< TX FIFO Empty interrupt pending
  uint8_t TX_HALF  : 1;       ///< TX FIFO Half Full interrupt pending
  uint8_t TX_FULL  : 1;       ///< TX FIFO Full interrupt pending
  uint8_t RX_EMPTY : 1;       ///< RX FIFO Empty interrupt pending
  uint8_t RX_HALF  : 1;       ///< RX FIFO Half Full interrupt pending
  uint8_t RX_FULL  : 1;       ///< RX FIFO Full interrupt pending
  uint8_t I2C_INT  : 1;       ///< I2C Interrupt pending
  uint8_t DONE     : 1;       ///< FIFO_BL operation complete interrupt pending
} i2cs_fifo_int_pend_reg_t;

typedef union
{
  i2cs_fifo_int_pend_reg_t B;
  REG_ACCESS_U8            U;
} i2cs_fifo_int_pend_reg_u;

/** \brief FIFO Data Register */
typedef struct
{
  uint8_t FIFO_DATA;          ///< FIFO Data Read from the RX Buffer
} i2cs_fifo_data_reg_t;

typedef union
{
  i2cs_fifo_data_reg_t B;
  REG_ACCESS_U8        U;
} i2cs_fifo_data_reg_u;

/** \brief Trigger Register */
typedef struct
{
  uint8_t Reserved_0_6 : 7;   ///< Reserved
  uint8_t RX_OP        : 1;   ///< A write to this register triggers the FIFO mode operation. Set
                              ///< this bit to 1 for RX, and 0 for TX FIFO operations.
                              ///< The operation will end when FIFO_BL expires.
} i2cs_trig_reg_t;

typedef union
{
  i2cs_trig_reg_t B;
  REG_ACCESS_U8   U;
} i2cs_trig_reg_u;

/** @brief Register mappings for I2C Slave registers */
typedef struct
{
  __IO i2cs_own_addr_reg_u     I2CS_OWN_ADDR;         ///< Own address register
  __IO i2cs_cntl_sts_reg_u     I2CS_CNTL_STATUS;      ///< Control and Status register __IO uint8_t DATA;
  __IO i2cs_data_reg_u         I2CS_DATA;             ///< Receive / transmit data register
       uint8_t                 I2CS_UNUSED_3;         ///< Reserved
  __IO i2cs_fifo_len_reg_u     I2CS_FIFO_LEN;         ///< FIFO mode byte length register
  __IO i2cs_fifo_int_ena_reg_u I2CS_FIFO_INT_ENABLE;  ///< FIFO mode interrupt enable register
  __IO i2cs_fifo_data_reg_u    I2CS_FIFO_DATA;        ///< FIFO data register
  __IO i2cs_trig_reg_u         I2CS_TRIG;             ///< FIFO transfer trigger register
} i2cs_regs_t;

/** @brief Register mappings for I2C Slave registers */
typedef struct
{
  __IO uint8_t I2CS_OWN_ADDR;         ///< Own address register
  __IO uint8_t I2CS_CNTL_STATUS;      ///< Control and Status register __IO uint8_t DATA;
  __IO uint8_t I2CS_DATA;             ///< Receive / transmit data register
       uint8_t I2CS_UNUSED3;          ///< Reserved
  __IO uint8_t I2CS_FIFO_LEN;         ///< FIFO mode byte length register
  __IO uint8_t I2CS_FIFO_INT_ENABLE;  ///< FIFO mode interrupt enable register
  __IO uint8_t I2CS_FIFO_INT_PEND;    ///< FIFO mode interrupt pending register
  __IO uint8_t I2CS_FIFO_DATA;        ///< FIFO data register
  __IO uint8_t I2CS_TRIG;             ///< FIFO transfer trigger register
} ft900_i2cs_regs_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#endif /* FT900_I2C_REGISTERS_H_ */
