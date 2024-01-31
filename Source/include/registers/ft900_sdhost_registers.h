/**
    @file ft900_sdhost_registers.h

    @brief SD card host controller registers
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

#ifndef FT900_SDHOST_REGISTERS_H_
#define FT900_SDHOST_REGISTERS_H_

/* INCLUDES ************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <registers/ft900_registers.h>

#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

/* TYPES ***************************************************************************/

/** \brief Auto CMD23 Argument 2 Register
 *  \details This register sets a 32-bit block count to the argument of CMD23 while executing Auto
 *           CMD23. The available block count will be limited by BLK_CNT. In this case, 65535 blocks
 *           are the maximum value.
 */
typedef struct
{
  uint32_t ARG_2;           ///< Auto CMD23 argument 2
} sdh_auto_cmd23_arg2_reg_t;

/** \brief Auto CMD23 Argument 2 Register */
typedef union
{
  sdh_auto_cmd23_arg2_reg_t B;
  REG_ACCESS_U32            U;
} sdh_auto_cmd23_arg2_reg_u;

/** \brief Block Size Register
 *  \details This register is used to configure the number of bytes in a data block.
 */
typedef struct
{
  uint16_t BLK_SIZE : 12;   ///< This register specifies the block size of data transfers for
                            ///< CMD17/18/24/25/53 and can be set with values ranging from 1 up to
                            ///< the maximum buffer size.

  uint16_t Reserved : 4;    ///< Reserved
} sdh_blk_size_reg_t;

/** \brief Block Size Register */
typedef union
{
  sdh_blk_size_reg_t B;
  REG_ACCESS_U32     U;
} sdh_blk_size_reg_u;

/** \brief Block Count Register
 *  \details The block count register is set when the BLK_CNT_EN bit is set to 1. This register is
 *           used only for the multi-block transfers. The host controller will decrease the counting
 *           number during the data transfer and stop counting when it counts down to zero. When a
 *           suspend command is completed in the SDIO transfer, the remaining block counts can be
 *           determined by reading this register. Before issuing a resume command to start a
 *           re-transfer, the host driver should restore the block counts that are previously saved.
 */
typedef struct
{
  uint32_t Reserved : 16;   ///< Reserved

  uint32_t BLK_CNT  : 16;   ///< Block count of the current transfer. Valid values are from 1 to
                            ///< 65535 blocks.
                            ///< 0000: stop counting
} sdh_blk_count_reg_t;

/** \brief Block Count Register */
typedef union
{
  sdh_blk_count_reg_t B;
  REG_ACCESS_U32      U;
} sdh_blk_count_reg_u;

/** \brief Argument 1 Register
 *  \details This register is assigned to bits[39:8] of the command field.
 */
typedef struct
{
  uint32_t ARG1;            ///< Command argument
} sdh_arg_1_reg_t;

/** \brief Argument 1 Register */
typedef union
{
  sdh_arg_1_reg_t B;
  REG_ACCESS_U32  U;
} sdh_arg_1_reg_u;

/** \brief Transfer Mode Register
 *  \details The host driver should set this register before issuing the data transfer command or
 *           resume command. When in the SDIO transfer, the values of this register should be
 *           preserved after the suspend command and should be restored before the resume command.
 */
typedef struct
{
  uint16_t Reserved_0    : 1;   ///< Reserved - Write 0 to this bit

  uint16_t BLK_CNT_EN    : 1;   ///< Block count enable.
                                ///< This bit is only valid for a multi-block transfer. When set to
                                ///< 0 the BLK_CNT register will be disabled. The multi-block
                                ///< transfer will be an infinite transfer.

  uint16_t AUTO_CMD_EN   : 2;   ///< Auto CMD enable.
                                ///< There are two methods to stop the read and write operations of
                                ///< multiple blocks:
                                ///< 01: Auto CMD12 Enable
                                ///< When this field is set to 01, the host controller will issue a
                                ///< CMD12 when the last block transfer is completed.
                                ///< 10: Auto CMD23 Enable
                                ///< When this bit field is set to 10, the host controller will
                                ///< issue a CMD23 before issuing a command specified in the Command
                                ///< Register
                                ///< 11: Reserved
                                ///< 00: Auto Command Disabled

  uint16_t TRAN_DIR_SEL  : 1;   ///< 1: Read from the card to host
                                ///< 0: Write from the host to card

  uint16_t MULTI_BLK     : 1;   ///< 1: Multiple blocks selection
                                ///< 0: Single block selection

  uint16_t Reserved_6_15 : 10;  ///< Reserved
} sdh_tnsfer_mode_reg_t;

/** \brief Transfer Mode Register */
typedef union
{
  sdh_tnsfer_mode_reg_t B;
  REG_ACCESS_U32        U;
} sdh_tnsfer_mode_reg_u;

/** \brief Command Register
 *  \details The host driver should check the Command Inhibit (CMD) and Command Inhibit (DAT) bits
 *           in the present state register to determine whether the SD bus is free to transfer.
 */
typedef struct
{
  uint32_t Reserved_0_15  : 16; ///< Reserved

  uint32_t RSP_TYPE_SEL   : 2;  ///< Response Type Select:
                                ///< 11: Response length 48 with busy check after response
                                ///< 10: Response length 48
                                ///< 01: Response length 136
                                ///< 00: No response

  uint32_t Reserved_18    : 1;  ///< Reserved

  uint32_t CMD_CRC_CHK_EN : 1;  ///< Command CRC Check Enable
                                ///< 1: The host controller will check the CRC field response to
                                ///<    determine whether the CRC is correct. CMD_CRC_ERR will be
                                ///<    triggered if an error is detected.

  uint32_t CMD_IDX_CHK_EN : 1;  ///< Command Index Check Enable
                                ///< 1: The host controller will check the index field response to
                                ///<    determine if the values are CMD_IDX. If they are not the
                                ///<    same, CMD_IDX_ERR will be triggered

  uint32_t DATA_PRE_SEL   : 1;  ///< Data Present Select
                                ///< 1: Indicates that data is present and data transfer is enabled
                                ///< 0: Under the following conditions
                                ///< a. Commands only using the CMD line
                                ///< b. Commands with no data transfer but using the busy signal on
                                ///< DAT[0]
                                ///< Resume command

  uint32_t CMD_TYPE       : 2;  ///< Command type refer table below:
                                ///<  | 11 | Abort   | CMD12/52 for writing I/O Abort in CCCR    |
                                ///<  | 10 | Resume  | CMD52 for writing Function Select in CCCR |
                                ///<  | 01 | Suspend | CMD52 for writing Bus Suspend in CCCR     |
                                ///<  | 00 | Normal  | Other commands                            |

  uint32_t CMD_IDX        : 6;  ///< Command Index
                                ///< These bits should be assigned to bits [45:40] of the command
                                ///< field

  uint32_t Reserved_30_31 : 2;  ///< Reserved
} shd_cmd_reg_t;

/** \brief Command Register */
typedef union
{
  shd_cmd_reg_t  B;
  REG_ACCESS_U32 U;
} shd_cmd_reg_u;

/** \brief Response Register
 *  \details The Host Controller stores the Auto CMD12 response in the upper word of the Response
 *           Register to avoid the Auto CMD12 response, which tends to be overwritten by the other
 *           command.
 */
typedef struct
{
  uint32_t RESPONSE_0;
  uint32_t RESPONSE_1;
  uint32_t RESPONSE_2;
  uint32_t RESPONSE_3;
} sdh_response_reg_t;

/** \brief Buffer Data Port Register
 *  \details This register uses the 32-bit Data Port Register to access the internal buffer.
 */
typedef struct
{
  uint32_t DATA_PORT;   ///< Buffer Data Port Register
} sdh_buf_data_reg_t;

/** \brief Buffer Data Port Register */
typedef union
{
  sdh_buf_data_reg_t B;
  REG_ACCESS_U32     U;
} sdh_buf_data_reg_u;

/** \brief Present State Register
 *  \details The host driver can access the status from this read-only register.
 */
typedef struct
{
  uint32_t CMD_INHIBIT_CMD : 1; ///< Command Inhibit (CMD)
                                ///<     1: Cannot issue command
                                ///<     0: Issue command only with the command line

  uint32_t CMD_INHIBIT_DAT : 1; ///< Command Inhibit (DAT)
                                ///<     1: Cannot issue new commands to use the data line
                                ///<     0: Issue new commands to use the data line

  uint32_t DATA_LIN_ACT    : 1; ///< Data Line Active
                                ///< In a read transfer, this status bit is used to check whether a
                                ///< read transfer is executing on the bus. Changing this bit from 1
                                ///< to 0 will generate a BLK_GAP_EVT interrupt when SP_BLK_GAP is
                                ///< set to 1.
                                ///< 1: Under the following conditions:
                                ///< (1) After the end bit of a read command
                                ///< (2) When CONT_REQ in the block gap control register is set to
                                ///<     restart a transfer.
                                ///< 0: Under the following conditions:
                                ///< (1) When the end bit of the last data block is sent from the SD
                                ///<     bus to the host controller.
                                ///< (2) When SP_BLK_GAP is set to 1 and a read transfer is stopped
                                ///<     at the block gap.
                                ///< In a write transfer, this status bit is used to check whether a
                                ///< write transfer is executing on the bus. Changing this bit from
                                ///< 1 to 0 will generate a TRAN_CMPLT interrupt in the normal
                                ///< interrupt status register.
                                ///< 1: Under the following conditions:
                                ///< (1) After the end bit of a read command
                                ///< (2) When CONT_REQ in the block gap control register is set to
                                ///<     restart a transfer.
                                ///< 0: Under the following conditions:
                                ///< (1) When the card releases the busy signal of the last data
                                ///<     block.
                                ///< (2) When SP_BLK_GAP is set to 1 and the card releases the write
                                ///<     busy at the block gap.
                                ///< In the command with busy data line, this bit indicates whether
                                ///< a command with busy is executing on the bus. This bit will be
                                ///< set after the end bit of the command with busy and will be
                                ///< cleared when busy is de-asserted or busy is not detected after
                                ///< the end of a response.

  uint32_t Reserved_3_7    : 5; ///< Reserved

  uint32_t WR_TRAN_ACT     : 1; ///< Write Transfer Active
                                ///< 1: Under the following conditions:
                                ///< (1) After the end bit of a write command
                                ///< (2) When CONT_REQ in the block gap control register is set to
                                ///<     restart a transfer.
                                ///< 0: Under the following conditions:
                                ///< (1) After getting the CRC status of the last data block
                                ///<     specified by the transfer count.
                                ///< (2) After getting the CRC status of any block where data
                                ///<     transmission is stopped by SP_BLK_GAP.
                                ///< A BLK_GAP_EVT interrupt will be generated when SP_BLK_GAP is
                                ///< set to 1 and this bit changes to 0. This bit is useful in the
                                ///< command with a busy data line.

  uint32_t RD_TRAN_ACT     : 1; ///< Read Transfer Active
                                ///< 1: Under the following conditions:
                                ///< (1) After the end bit of a read command
                                ///< (2) When CONT_REQ in the block gap control register is set to
                                ///<     restart a transfer.
                                ///< 0: Under the following conditions:
                                ///< (1) When all data blocks specified by the block length are
                                ///<     transferred to the system.
                                ///< (2) When SP_BLK_GAP in the block gap control register is set to
                                ///<     1 and the host controller has transferred all the valid
                                ///<     data blocks to the system.
                                ///< The TRAN_CMPLT interrupt is generated when this bit changes
                                ///< from 1 to 0

  uint32_t BUF_WR_EN       : 1; ///< Buffer Write Enable
                                ///<     1: Write Enable
                                ///<     0: Write Disable

  uint32_t BUF_RD_EN       : 1; ///< Buffer Read Enable
                                ///<     1: Read Enable
                                ///<     0: Read Disable

  uint32_t Reserved_12_15  : 4; ///< Reserved

  uint32_t SYS_CARD_INSERT : 1; ///< Card Inserted
                                ///<     1: Card inserted
                                ///<     0: Reset, de-bouncing, or no card is detected

  uint32_t SYS_CARD_STABLE : 1; ///< Card State Stable
                                ///<     1: No card or card is inserted
                                ///<     0: Reset or de-bounce

  uint32_t CD_PIN_LV       : 1; ///< Card Detect Pin Level
                                ///<     1: Card is detected
                                ///<     0: Card is not detected

  uint32_t WR_PROP_LV      : 1; ///< Write Protect Pin Level
                                ///<     1: Write enabled
                                ///<     0: Write protected

  uint32_t DATA_LIN_LV     : 4; ///< Data[3:0] Line Signal Level

  uint32_t CMD_LIN_LV      : 1; ///< Command Line Signal Level

  uint32_t Reserved_25_31  : 7; ///< Reserved
} sdh_present_state_reg_t;

/** \brief Present State Register */
typedef union
{
  sdh_present_state_reg_t B;
  REG_ACCESS_U32          U;
} sdh_present_state_reg_u;

/** \brief Host Control 1 Register */
typedef struct
{
  uint8_t Reserved_0     : 1; ///< Reserved

  uint8_t DATA_WIDTH     : 1; ///< Data Width
                              ///<     1: 4-bit mode
                              ///<     0: 1-bit mode

  uint8_t Reserved_2_4   : 3; ///< Reserved

  uint8_t EXT_DATA_WIDTH : 1; ///< Extended Data Transfer Width
                              ///<     1: 8-bit bus width
                              ///<     0: Bus width is selected by the data transfer width

  uint8_t CD_TEST_LV     : 1; ///< Card Detect Test Level
                              ///<     1: Card is inserted
                              ///<     0: Card cannot be found

  uint8_t CD_SEL         : 1; ///< Card Detect Signal Selection
                              ///<     1: The test level for the card detection
                              ///<     0: The card detect pin is selected
} sdh_hst_cntl_1_reg_t;

/** \brief Host Control 1 Register */
typedef union
{
  sdh_hst_cntl_1_reg_t B;
  REG_ACCESS_U8        U;
} sdh_hst_cntl_1_reg_u;

/** \brief Power Control Register */
typedef struct
{
  uint8_t Reserved_0   : 1;   ///< Reserved

  uint8_t SD_BUS_VOL   : 3;   ///< SD Bus Voltage Select
                              ///<     111: 3.3V (Typ)
                              ///<     110: 3.0V (Typ)
                              ///<     101: 1.8V (Typ)
                              ///<     Others: Reserved

  uint8_t Reserved_4_7 : 4;   ///< Reserved
} sdh_pwr_cntl_reg_t;

/** \brief Power Control Register */
typedef union
{
  sdh_pwr_cntl_reg_t B;
  REG_ACCESS_U8      U;
} sdh_pwr_cntl_reg_u;

/** \brief Block Gap Control Register */
typedef struct
{
  uint16_t SP_BLK_GAP  : 1;   ///< 1: Stop at block gap request; the host controller will stop at
                              ///< the block gap by using READ_WAIT or stop IO_SD_CLK in a read
                              ///< transaction
                              ///< 0: the host controller will not write data to DATA_PORT

  uint16_t CONT_REQ    : 1;   ///< 1: To restart a transaction (SP_BLK_GAP must also be 1; if 0 this
                              ///<     will be aborted)
                              ///< It is cleared automatically by the host controller when:
                              ///<     a. In a read transfer, DATA_LIN_ACT changes from 0 to 1 to
                              ///<        start a read transfer.
                              ///<     b. In a write transfer, WR_TRAN_ACT changes from 0 to 1 to
                              ///<        start a write transfer.

  uint16_t READ_WAIT   : 1;   ///< 1: Enable Read Wait

  uint16_t INT_BLK_GAP : 1;   ///< 1: Check the interrupt at block gap enabled

  uint16_t Reserved    : 12;  ///< Reserved
} sdh_blk_gap_cntl_reg_t;

/** \brief Block Gap Control Register */
typedef union
{
  sdh_blk_gap_cntl_reg_t B;
  REG_ACCESS_U16         U;
} sdh_blk_gap_cntl_reg_u;

/** \brief Clock Control Register */
typedef struct
{
  uint16_t INTER_CLK_EN         : 1;  ///< 1: Internal clock will start oscillating

  uint16_t CLK_STABLE           : 1;  ///< This bit is set to 1 when the internal clock is stable

  uint16_t SD_CLK_EN            : 1;  ///< 1: IO_SD_CLK will be output

  uint16_t Reserved_3_4         : 2;  ///< Reserved

  uint16_t CLK_GEN_SEL          : 1;  ///< This bit is always set to zero.
                                      ///<     0: 10-bit divided clock mode

  uint16_t UPPER_BIT_SD_CLK_SEL : 2;  ///< SD clock frequency value 9:8 for the 10-bit divided clock
                                      ///< mode

  uint16_t LOW_BIT_SD_CLK_SEL   : 8;  ///< SD clock frequency value 7:0 for the 10-bit divided clock
                                      ///< mode. These are used to select the frequency of the
                                      ///< IO_SD_CLK pin. The base clock is 1/2 of chip system clock
                                      ///<     N: Chip system clock * (1 / 2N)
                                      ///<     0: Not supported
} sdh_clk_cntl_reg_t;

/** \brief Clock Control Register */
typedef union
{
  sdh_clk_cntl_reg_t B;
  REG_ACCESS_U16     U;
} sdh_clk_cntl_reg_u;

/** \brief Timeout Control Register
 *  \details This host driver should set the timeout value according to the capabilities register.
 *           The value of DATA_TIMER indicates the data line timeout times.
 */
typedef struct
{
  uint8_t DATA_TIMER : 4;   ///< 1111: Reserved
                            ///< 1110: Chip system clk x 2^27
                            ///< 1101: Chip system clk x 2^26
                            ///< ...
                            ///< 0000: Chip system clk x 2^13

  uint8_t Reserved   : 4;   ///< Reserved
} sdh_timeout_cntl_reg_t;

/** \brief Timeout Control Register */
typedef union
{
  sdh_timeout_cntl_reg_t B;
  REG_ACCESS_U8          U;
} sdh_timeout_cntl_reg_u;

/** \brief Software Reset Register
 *  \details A reset pulse will be generated when this bit is set to 1. This bit will be
 *           automatically cleared once the reset pulse is issued.
 */
typedef struct
{
  uint8_t SOFT_RST_ALL : 1;           ///< 1: Software reset for all
  uint8_t SOFT_RST_CMD : 1;           ///< 1: Software reset for command line
  uint8_t SOFT_RST_DAT : 1;           ///< 1: Software reset for data line
  uint8_t Reserved     : 5;           ///< Reserved
} sdh_sw_rst_reg_t;

/** \brief Software Reset Register */
typedef union
{
  sdh_sw_rst_reg_t B;
  REG_ACCESS_U8    U;
} sdh_sw_rst_reg_u;

/** \brief Normal Interrupt Status Register
 *  \details The interrupt status can be latched by setting the Normal Interrupt Status Enable
 *           register corresponding bit to 1.
 */
typedef struct
{
  uint16_t CMD_CMPLT     : 1;   ///< 1: Command Complete
  uint16_t TRAN_CMPLT    : 1;   ///< 1: Transfer Complete
  uint16_t BLK_GAP_EVT   : 1;   ///< 1: Block Gap Event
  uint16_t Reserved_3    : 1;   ///< Write 0 to this bit
  uint16_t BUF_WR_RDY    : 1;   ///< 1: Buffer Write Ready
  uint16_t BUF_RD_RDY    : 1;   ///< 1: Buffer Read Ready
  uint16_t CARD_INSERT   : 1;   ///< 1: Card Inserted
  uint16_t CARD_REMOVE   : 1;   ///< 1: Card Remove
  uint16_t CARD_INT      : 1;   ///< 1: Card Interrupt
  uint16_t Reserved_9_14 : 6;   ///< Reserved
  uint16_t ERR_INT       : 1;   ///< 1: Error Interrupt
} sdh_nrml_int_sts_reg_t;

/** \brief Normal Interrupt Status Register */
typedef union
{
  sdh_nrml_int_sts_reg_t B;
  REG_ACCESS_U16         U;
} sdh_nrml_int_sts_reg_u;

/** \brief Error Interrupt Status Register
 *  \details The interrupt status can be latched by setting the Error Interrupt Status Enable
 *           Register corresponding bit to 1.
 */
typedef struct
{
  uint16_t CMD_TIMEOUT_ERR  : 1;  ///< Command Timeout error
  uint16_t CMD_CRC_ERR      : 1;  ///< Command CRC error
  uint16_t CMD_ERR_BIT_ERR  : 1;  ///< Command End Bit error
  uint16_t CMD_IDX_ERR      : 1;  ///< Command Index error
  uint16_t DATA_TIMEOUT_ERR : 1;  ///< Data Timeout error
  uint16_t DATA_CRC_ERR     : 1;  ///< Data CRC error
  uint16_t DATA_END_BIT_ERR : 1;  ///< Data End Bit error
  uint16_t CUR_LIM_ERR      : 1;  ///< Current limit error
  uint16_t AUTO_CMD12_ERR   : 1;  ///< Auto CMD12 error
  uint16_t Reserved_10      : 1;  ///< Reserved - Write 0 to this bit
  uint16_t Reserved_11      : 1;  ///< Reserved - Write 0 to this bit
  uint16_t Reserved_12_15   : 3;  ///< Reserved
} sdh_err_int_sts_reg_t;

/** \brief Error Interrupt Status Register */
typedef union
{
  sdh_err_int_sts_reg_t B;
  REG_ACCESS_U16        U;
} sdh_err_int_sts_reg_u;

/** \brief Normal Interrupt Status Enable Register
 *  \details If the corresponding bit of the interrupt source in the normal interrupt status enable
 *           register is set to 1, the interrupt becomes active, which is latched and available for
 *           the host driver in the normal interrupt status register.
 */
typedef struct
{
  uint16_t CMD_CMPLT_ST_EN   : 1; ///< Command Complete status enable
  uint16_t TRAN_CMPLT_ST_EN  : 1; ///< Transfer Complete status enable
  uint16_t BLK_GAP_EVT_ST_EN : 1; ///< Block Gap Event status enable
  uint16_t Reserved_3        : 1; ///< Reserved - Write 0 to this bit
  uint16_t BUF_WR_RDY_ST_EN  : 1; ///< Buffer Write Ready status enable
  uint16_t BUF_RD_RDY_ST_EN  : 1; ///< Buffer Read Ready status enable
  uint16_t CARD_INSERT_ST_EN : 1; ///< Card Insert status enable
  uint16_t CARD_REMOVE_ST_EN : 1; ///< Card Remove status enable
  uint16_t CARD_INT_ST_EN    : 1; ///< Card Interrupt status enable
  uint16_t Reserved          : 7; ///< Reserved
} sdh_nrml_int_enb_reg_t;

/** \brief Normal Interrupt Status Enable Register */
typedef union
{
  sdh_nrml_int_enb_reg_t B;
  REG_ACCESS_U16         U;
} sdh_nrml_int_enb_reg_u;

/** \brief Error Interrupt Status Enable Register
 *  \details If the corresponding bit of the interrupt source in the Error Interrupt Status Enable
 *           Register is set to 1 and if the interrupt becomes active, the active state will be
 *           latched and will be available for the host driver in this register.
 */
typedef struct
{
  uint16_t CMD_TIMEOUT_ERR_ST_EN  : 1;  ///< Command Timeout error status enable
  uint16_t CMD_CRC_ERR_ST_EN      : 1;  ///< Command CRC error status enable
  uint16_t CMD_END_BIT_ERR_ST_EN  : 1;  ///< Command End Bit error status enable
  uint16_t CMD_IDX_ERR_ST_EN      : 1;  ///< Command Index error status enable
  uint16_t DATA_TIMEOUT_ERR_ST_EN : 1;  ///< Data Timeout error status enable
  uint16_t DATA_CRC_ERR_ST_EN     : 1;  ///< Data CRC error status enable
  uint16_t DATA_END_BIT_ERR_ST_EN : 1;  ///< Data End Bit error status enable
  uint16_t CUR_LIM_ERR_ST_EN      : 1;  ///< Current limit error status enable
  uint16_t AUTO_CMD12_ERR_ST_EN   : 1;  ///< Auto CMD12 error status enable
  uint16_t Reserved_10_15         : 6;  ///< Reserved
} sdh_err_nrml_int_enb_reg_t;

/** \brief Error Interrupt Status Enable Register */
typedef struct
{
  sdh_err_nrml_int_enb_reg_t B;
  REG_ACCESS_U16             U;
} sdh_err_nrml_int_enb_reg_u;

/** \brief Normal Interrupt Signal Enable Register
 *  \details This register is used to select the interrupt status that is notified to the host
 *           system as an interrupt. These interrupt statuses share the same interrupt line.
 */
typedef struct
{
  uint16_t CMD_CMPLT_SIG_EN   : 1;    ///< Command Complete signal enable
  uint16_t TRAN_CMPLT_SIG_EN  : 1;    ///< Transfer Complete signal enable
  uint16_t BLK_GAP_EVT_SIG_EN : 1;    ///< Block Gap Event signal enable
  uint16_t Reserved_3         : 1;    ///< Reserved - Write 0 to this bit
  uint16_t BUF_WR_RDY_SIG_EN  : 1;    ///< Buffer Write Ready signal enable
  uint16_t BUF_RD_RDY_SIG_EN  : 1;    ///< Buffer Read Ready signal enable
  uint16_t CARD_INSERT_SIG_EN : 1;    ///< Card Insert signal enable
  uint16_t CARD_REMOVE_SIG_EN : 1;    ///< Card Remove signal enable
  uint16_t CARD_INT_SIG_EN    : 1;    ///< Card Interrupt signal enable
  uint16_t Reserved_9_15      : 7;    ///< Reserved
} sdh_nrml_int_sgnl_enb_reg_t;

/** \brief Normal Interrupt Signal Enable Register */
typedef union
{
  sdh_nrml_int_sgnl_enb_reg_t B;
  REG_ACCESS_U16              U;
} sdh_nrml_int_sgnl_enb_reg_u;

/** \brief Error Interrupt Signal Enable Register
 *  \details This register is used to select the interrupt status that is regarded by the host
 *           system as an interrupt. These interrupt statuses share the same interrupt line.
 */
typedef struct
{
  uint16_t CMD_TIMEOUT_ERR_SIG_EN  : 1; ///< Command Timeout error signal enable
  uint16_t CMD_CRC_ERR_SIG_EN      : 1; ///< Command CRC error signal enable
  uint16_t CMD_END_BIT_ERR_SIG_EN  : 1; ///< Command End Bit error signal enable
  uint16_t CMD_IDX_ERR_SIG_EN      : 1; ///< Command Index error signal enable
  uint16_t DATA_TIMEOUT_ERR_SIG_EN : 1; ///< Data Timeout error signal enable
  uint16_t DATA_CRC_ERR_SIG_EN     : 1; ///< Data CRC error signal enable
  uint16_t DATA_END_BIT_ERR_SIG_EN : 1; ///< Data End Bit error signal enable
  uint16_t CUR_LIM_ERR_SIG_EN      : 1; ///< Current limit error signal enable
  uint16_t AUTO_CMD12_ERR_SIG_EN   : 1; ///< Auto CMD12 error signal enable
  uint16_t Reserved                : 7; ///< Reserved
} sdh_err_int_sgnl_enb_reg_t;

/** \brief Error Interrupt Signal Enable Register */
typedef union
{
  sdh_err_int_sgnl_enb_reg_t B;
  REG_ACCESS_U16             U;
} sdh_err_int_sgnl_enb_reg_u;

/** \brief Auto CMD12 Error Status Register
 *  \details When the auto_cmd12_en register is set to 1 and the auto cmd12 error status register is
 *           set, the host driver will check this register to identify what kind of error happens
 *           during executing AUTO CMD12. This register is valid only when the auto_cmd12_err is set
 *           to 1.
 */
typedef struct
{
  uint16_t AUTO_CMD12_NO_EX     : 1;  ///< Auto CMD12 not executed
  uint16_t AUTO_CMD_TIMEOUT_ERR : 1;  ///< Auto CMD timeout error
  uint16_t AUTO_CMD_CRC_ERR     : 1;  ///< Auto CMD CRC error
  uint16_t AUTO_CMD_END_BIT_ERR : 1;  ///< Auto CMD end bit error
  uint16_t AUTO_CMD_IDX_ERR     : 1;  ///< Auto CMD index error
  uint16_t Reserved_5_6         : 2;  ///< Reserved
  uint16_t CMD_NO_EX_BY_CMD12   : 1;  ///< Command not executed by Auto CMD12 error
  uint16_t Reserved_8_15        : 8;  ///< Reserved
} sdh_auto_cmd12_err_sts_reg_t;

/** \brief Auto CMD12 Error Status Register */
typedef union
{
  sdh_auto_cmd12_err_sts_reg_t B;
  REG_ACCESS_U16               U;
} sdh_auto_cmd12_err_sts_reg_u;

/** \brief Host Control 2 Register */
typedef struct
{
  uint16_t Reserved_0_6   : 7;  ///< Reserved

  uint16_t SAMPLE_CLK_SEL : 1;  ///< Sampling clock select
                                ///< 0: Fixed clock is used to sample data

  uint16_t Reserved_8_13  : 6;  ///< Reserved

  uint16_t ASYN_INT_EN    : 1;  ///< Asynchronous Interrupt Enable

  uint16_t PRESET_VAL_EN  : 1;  ///< 0: SDCLK and driver strength are controlled by the host driver
                                ///< 1: automatic selection by the pre-set value
} sdh_host_cntl_2_reg_t;

/** \brief Host Control 2 Register */
typedef union
{
  sdh_host_cntl_2_reg_t B;
  REG_ACCESS_U16        U;
} sdh_host_cntl_2_reg_u;

/** \brief Capabilities Register 1 */
typedef struct
{
  uint32_t TIMEOUT_CLK_FREQ       : 6;  ///< 0: Get information via another method
  uint32_t Reserved_6             : 1;  ///< Reserved
  uint32_t TIMEOUT_CLK_UNIT       : 1;  ///< 1: MHz
  uint32_t BASE_CLK_FOR_SD_CLK    : 8;  ///< 0: Get information via another method
  uint32_t MAX_BLK_LEN            : 2;  ///< 2: 2048 bytes
  uint32_t _8BIT_SUPPORT          : 1;  ///< 0: 8-bit not supported
  uint32_t Reserved_19_20         : 2;  ///< Reserved
  uint32_t HI_SPEED_SUPPORT       : 1;  ///< 1: High speed supported
  uint32_t Reserved_21            : 1;  ///< Reserved
  uint32_t SUSPEND_RESUME_SUPPORT : 1;  ///< 0 supported : Suspend / Resume not
  uint32_t VOLTAGE_3_3_SUPPORT    : 1;  ///< Voltage supports 3.3V
  uint32_t Reserved_25_27         : 3;  ///< 0: not supported
  uint32_t BUT_64_SUPPORT         : 1;  ///< 0: not supported
  uint32_t ASYNC_INT_SUPPORT      : 1;  ///< 0: not supported
  uint32_t SLOT_TYPE              : 2;  ///< Removable Card Slot
} sdh_cap_1_reg_t;

/** \brief Capabilities Register 1 */
typedef union
{
  sdh_cap_1_reg_t B;
  REG_ACCESS_U32  U;
} sdh_cap_1_reg_u;

/** \brief Capabilities Register 2 */
typedef struct
{
  uint32_t SDR50_SUPPORT    : 1;    ///< Not supported
  uint32_t SDR104_SUPPORT   : 1;    ///< Not supported
  uint32_t DDR50_SUPPORT    : 1;    ///< Not supported
  uint32_t Reserved_3       : 1;    ///< Reserved
  uint32_t DRIVER_A_SUPPORT : 1;    ///< Not supported
  uint32_t DRIVER_C_SUPPORT : 1;    ///< Not supported
  uint32_t DRIVER_D_SUPPORT : 1;    ///< Not supported
  uint32_t Reserved_7_15    : 9;    ///< Reserved
  uint32_t CLK_MULTI        : 8;    ///< Not supported
  uint32_t Reserved_24_31   : 8;    ///< Reserved
} sdh_cap_2_reg_t;

/** \brief Capabilities Register 2 */
typedef union
{
  sdh_cap_2_reg_t B;
  REG_ACCESS_U32  U;
} sdh_cap_2_reg_u;

/** \brief Force Event Register for Auto CMD Error Status
 *  \details The Force Event register is not a physical register. It is an address to which the Auto
 *           CMD error status register can be written. The force event register is only for
 *           debugging.
 */
typedef struct
{
  uint16_t R_CMD12_NO_EX        : 1;  ///< Force event for the Auto CMD12 Not Executed
  uint16_t R_CMD_TIMEOUT_ERR    : 1;  ///< Force event for the Auto CMD Timeout Error
  uint16_t R_CMD_CRC_ERR        : 1;  ///< Force event for the Auto CMD CRC Error
  uint16_t R_CMD_END_BIT_ERR    : 1;  ///< Force event for the Auto CMD End Bit Error
  uint16_t R_CMD_IDX_ERR        : 1;  ///< Force event for the Auto CMD Index Error
  uint16_t Reserved_5_6         : 2;  ///< Reserved
  uint16_t R_CMD_NO_EX_BY_CMD12 : 1;  ///< Force event for the Command Not Executed by Auto CMD12 Error
  uint16_t Reserved_8_15        : 8;  ///< Reserved
} sdh_force_evt_cmd_err_sts_reg_t;

/** \brief Force Event Register for Auto CMD Error Status */
typedef union
{
  sdh_force_evt_cmd_err_sts_reg_t B;
  REG_ACCESS_U16                  U;
} sdh_force_evt_cmd_err_sts_reg_u;

/** \brief Force Event for Error Interrupt Status Register
 *  \details The Force Event register is not a physical register. It is an address to which the
 *           error interrupt status register can be written. This Force Event register is for
 *           debugging only. The effect of writing to this address will be reflected in the error
 *           interrupt status register if the corresponding bit of the error interrupt status enable
 *           register is set.
 */
typedef struct
{
  uint16_t R_CMD_TIMEOUT_ERR  : 1;  ///< Force Event for the Command Timeout Error
  uint16_t R_CMD_CRC_ERR      : 1;  ///< Force Event for the Command CRC Error
  uint16_t R_CMD_END_BIT_ERR  : 1;  ///< Force Event for the Command End Bit Error
  uint16_t R_CMD_IDX_ERR      : 1;  ///< Force Event for the Command Index Error
  uint16_t R_DATA_TIMEOUT_ERR : 1;  ///< Force Event for the Data Timeout Error
  uint16_t R_DATA_CRC_ERR     : 1;  ///< Force Event for the Data CRC Error
  uint16_t R_DATA_END_BIT_ERR : 1;  ///< Force Event for the Data End Bit Error
  uint16_t R_CUR_LIMIT_ERR    : 1;  ///< Force Event for the Current Limit Error
  uint16_t R_AUTP_CMD_ERR     : 1;  ///< Force Event for the Auto CMD Error
  uint16_t Reserved_9_15      : 7;  ///< Reserved
} sdh_force_evt_err_int_sts_reg_t;

/** \brief Force Event for Error Interrupt Status Register */
typedef union
{
  sdh_force_evt_err_int_sts_reg_t B;
  REG_ACCESS_U16                  U;
} sdh_force_evt_err_int_sts_reg_u;

/** \brief Preset value for initialization */
typedef struct
{
  uint16_t SDCLK_FREQ_SEL : 10; ///< SDCLK Frequency Select Value
                                ///< The 10-bit pre-set value for setting the SDCLK Frequency
                                ///< Select in the Clock Control. The register is described by a
                                ///< host system.

  uint16_t CLK_GEN_SEL    : 1;  ///< Clock Generator Select Value
                                ///< The version does not support the programmable clock generator
                                ///< and is fixed to 0.

  uint16_t Reserved_11_13 : 3;  ///< Reserved

  uint16_t DRIVER_STR_SEL : 2;  ///< Driver Strength Select Value
                                ///< Driver Strength is supported by the 1.8- V signalling bus speed
                                ///< modes. This field is meaningless for the 3.3-V signalling.
                                ///<     11: Driver type D is selected
                                ///<     10: Driver type C is selected
                                ///<     01: Driver type A is selected
                                ///<     00: Driver type B is selected
} sdh_prst_init_reg_t;

/** \brief Preset value for initialization */
typedef union
{
  sdh_prst_init_reg_t B;
  REG_ACCESS_U16      U;
} sdh_prst_init_reg_u;

/** \brief Preset value for default speed */
typedef struct
{
  uint16_t SDCLK_FREQ_SEL : 10; ///< SDCLK Frequency Select Value
                                ///< The 10-bit pre-set value for setting the SDCLK Frequency Select
                                ///< in the Clock Control. The register is described by a host
                                ///< system.

  uint16_t CLK_GEN_SEL    : 1;  ///< Clock Generator Select Value
                                ///< The version does not support the programmable clock generator
                                ///< and is fixed to 0.

  uint16_t Reserved_11_15 : 5;  ///< Reserved
} sdh_prst_dflt_spd_reg_t;

/** \brief Preset value for default speed */
typedef union
{
  sdh_prst_dflt_spd_reg_t B;
  REG_ACCESS_U16          U;
} sdh_prst_dflt_spd_reg_u;

/** \brief Preset value for the high speed */
typedef struct
{
  uint16_t SDCLK_FREQ_SEL : 10;   ///< SDCLK Frequency Select Value
                                  ///< The 10-bit pre-set value for setting the SDCLK Frequency
                                  ///< Select in the Clock Control. The register is described by a
                                  ///< host system.

  uint16_t CLK_GEN_SEL    : 1;    ///< Clock Generator Select Value
                                  ///< The version does not support the programmable clock generator
                                  ///< and is fixed to 0.

  uint16_t Reserved_11_15 : 5;    ///< Reserved
} sdh_prst_high_spd_reg_t;

/** \brief Preset value for the high speed */
typedef union
{
  sdh_prst_high_spd_reg_t B;
  REG_ACCESS_U16          U;
} sdh_prst_high_spd_reg_u;

/** \brief Preset value for SDR12 */
typedef struct
{
  uint16_t SDCLK_FREQ_SEL : 10;   ///< SDCLK Frequency Select Value
                                  ///< The 10-bit pre-set value for setting the SDCLK Frequency
                                  ///< Select in the Clock Control. The register is described by a
                                  ///< host system.

  uint16_t CLK_GEN_SEL    : 1;    ///< Clock Generator Select Value
                                  ///< The version does not support the programmable clock generator
                                  ///< and is fixed to 0.

  uint16_t Reserved_11_13 : 3;    ///< Reserved

  uint16_t DRIVER_STR_SEL : 2;    ///< Driver Strength Select Value
                                  ///< Driver Strength is supported by the 1.8-V signalling bus
                                  ///< speed modes. This field is meaningless for the 3.3-V
                                  ///< signalling.
                                  ///<     11: Driver type D is selected
                                  ///<     10: Driver type C is selected
                                  ///<     01: Driver type A is selected
                                  ///<     00: Driver type B is selected
} sdh_prst_sdr12_reg_t;

/** \brief Preset value for SDR12 */
typedef union
{
  sdh_prst_sdr12_reg_t B;
  REG_ACCESS_U16       U;
} sdh_prst_sdr12_reg_u;

/** \brief Preset value for SDR25 */
typedef struct
{
  uint16_t SDCLK_FREQ_SEL : 10;   ///< SDCLK Frequency Select Value
                                  ///< The 10-bit pre-set value for setting the SDCLK Frequency
                                  ///< Select in the Clock Control. The register is described by a
                                  ///< host system.

  uint16_t CLK_GEN_SEL    : 1;    ///< Clock Generator Select Value
                                  ///< The version does not support the programmable clock generator
                                  ///< and is fixed to 0

  uint16_t Reserved_11_13 : 3;    ///< Reserved

  uint16_t DRIVER_STR_SEL : 2;    ///< Driver Strength Select Value
                                  ///< Driver Strength is supported by the 1.8-V signalling bus
                                  ///< speed modes. This field is meaningless for the 3.3-V
                                  ///< signalling.
                                  ///<     11: Driver type D is selected
                                  ///<     10: Driver type C is selected
                                  ///<     01: Driver type A is selected
                                  ///<     00: Driver type B is selected
} sdh_prst_sdr25_reg_t;

/** \brief Preset value for SDR25 */
typedef union
{
  sdh_prst_sdr25_reg_t B;
  REG_ACCESS_U16       U;
} sdh_prst_sdr25_reg_u;

/** \brief Preset value for SDR50 */
typedef struct
{
  uint16_t SDCLK_FREQ_SEL : 10;   ///< SDCLK Frequency Select Value
                                  ///< The 10-bit pre-set value for setting the SDCLK Frequency
                                  ///< Select in the Clock Control. The register is described by a
                                  ///< host system.

  uint16_t CLK_GEN_SEL    : 1;    ///< Clock Generator Select Value
                                  ///< The version does not support the programmable clock generator
                                  ///< and is fixed to 0

  uint16_t Reserved_11_13 : 3;    ///< Reserved

  uint16_t DRIVER_STR_SEL : 2;    ///< Driver Strength Select Value
                                  ///< Driver Strength is supported by the 1.8-V signalling bus
                                  ///< speed modes. This field is meaningless for the 3.3-V
                                  ///< signalling
                                  ///<     11: Driver type D is selected
                                  ///<     10: Driver type C is selected
                                  ///<     01: Driver type A is selected
                                  ///<     00: Driver type B is selected
} sdh_prst_sdr50_reg_t;

/** \brief Preset value for SDR50 */
typedef union
{
  sdh_prst_sdr50_reg_t B;
  REG_ACCESS_U16       U;
} sdh_prst_sdr50_reg_u;

/** \brief Preset value for SDR104 */
typedef struct
{
  uint16_t SDCLK_FREQ_SEL : 10;   ///< SDCLK Frequency Select Value
                                  ///< The 10-bit pre-set value for setting the SDCLK Frequency
                                  ///< Select in the Clock Control. The register is described by a
                                  ///< host system.

  uint16_t CLK_GEN_SEL    : 1;    ///< Clock Generator Select Value
                                  ///< The version does not support the programmable clock generator
                                  ///< and is fixed to 0

  uint16_t Reserved_11_13 : 3;    ///< Reserved

  uint16_t DRIVER_STR_SEL : 2;    ///< Driver Strength Select Value
                                  ///< Driver Strength is supported by the 1.8- V signalling bus
                                  ///< speed modes. This field is meaningless for the 3.3-V
                                  ///< signalling
                                  ///<     11: Driver type D is selected
                                  ///<     10: Driver type C is selected
                                  ///<     01: Driver type A is selected
                                  ///<     00: Driver type B is selected
} sdh_prst_sdr104_reg_t;

/** \brief Preset value for SDR104 */
typedef union
{
  sdh_prst_sdr104_reg_t B;
  REG_ACCESS_U16        U;
} sdh_prst_sdr104_reg_u;

/** \brief Preset value for DDR50 */
typedef struct
{
  uint16_t SDCLK_FREQ_SEL : 10;   ///< SDCLK Frequency Select Value
                                  ///< The 10-bit pre-set value for setting the SDCLK Frequency
                                  ///< Select in the Clock Control. The register is described by a
                                  ///< host system.

  uint16_t CLK_GEN_SEL    : 1;    ///< Clock Generator Select Value
                                  ///< The version does not support the programmable clock generator
                                  ///< and is fixed to 0

  uint16_t Reserved_11_13 : 3;    ///< Reserved

  uint16_t DRIVER_STR_SEL : 2;    ///< Driver Strength Select Value
                                  ///< Driver Strength is supported by the 1.8-V signalling bus
                                  ///< speed modes. This field is  meaningless for the 3.3-V
                                  ///< signalling
                                  ///<     11: Driver type D is selected
                                  ///<     10: Driver type C is selected
                                  ///<     01: Driver type A is selected
                                  ///<     00: Driver type B is selected
} sdh_prst_ddr50_reg_t;

/** \brief Preset value for DDR50 */
typedef union
{
  sdh_prst_ddr50_reg_t B;
  REG_ACCESS_U16       U;
} sdh_prst_ddr50_reg_u;

/** \brief Host Controller Version Register */
typedef struct
{
  uint16_t SPEC_VER_NUM : 8;      ///< Specification Version Number
  uint16_t VNDR_VER_NUM : 8;      ///< Vendor Version Number
} sdh_hc_ver_reg_t;

/** \brief Host Controller Version Register */
typedef union
{
  sdh_hc_ver_reg_t B;
  REG_ACCESS_U16   U;
} sdh_hc_ver_reg_u;

/** \brief Vendor-defined 0 Register */
typedef struct
{
  uint32_t P_LAT_EN       : 1;    ///< 1: Use the pulse latching function for the read data and
                                  ///< response. Should always be set to 1.

  uint32_t Reserved_1_7   : 7;    ///< Reserved

  uint32_t P_LAT_OFF      : 6;    ///< Pulse latch offset
                                  ///< When the host controller uses the pulse latch to sample the
                                  ///< read data and response, users need to set the latch offset to
                                  ///< correctly sample the value. The values set should be smaller
                                  ///< than the SDCLK Frequency Select
                                  ///<     0x3F: Latch value at the 63rd 1/2 chip frequency clock
                                  ///<           rising edge after the SCLK edge
                                  ///<     ...
                                  ///<     0x01: Latch value at the 1st
                                  ///<     0x00: Latch value at SCLK edge

  uint32_t Reserved_14_15 : 2;    ///< Reserved

  uint32_t INT_EDGE_SEL   : 1;    ///< 1: The CMD and DAT line output at the rising edge of SCLK
                                  ///< 0: The CMD and DAT line output at the falling edge of SCLK

  uint32_t Reserved_17_23 : 7;    ///< Reserved

  uint32_t N_CRC          : 4;    ///< Write CRC Status Wait Cycle
                                  ///< The host controller is used to set 5 SCLK clock cycles for
                                  ///< the specifications and round-chip effect. Users can add the
                                  ///< wait cycle for other factors.

  uint32_t Reserved_28_31 : 4;    ///< Reserved
} sdh_vndr_0_reg_t;

/** \brief Vendor-defined 0 Register */
typedef union
{
  sdh_vndr_0_reg_t B;
  REG_ACCESS_U32   U;
} sdh_vndr_0_reg_u;

/** \brief Vendor-defined 1 Register */
typedef struct
{
  uint32_t MMC_BOOT        : 2;   ///< MMC Booting Mode Selection
                                  ///<     11: MMC Bus Test mode
                                  ///<     10: MMC Alternative Boot Mode
                                  ///<     01: MMC Boot mode
                                  ///<     00: Normal mode

  uint32_t MMC_BOOT_ACK_EN : 1;   ///< MMC Booting Mode Acknowledge Enable

  uint32_t Reserved_3_7    : 5;   ///< Reserved

  uint32_t N_CR            : 3;   ///< N_CR Timing: Users can add the response wait cycle for other
                                  ///< factors. The host controller is set to 64 SCLK clock cycles.

  uint32_t Reserved_12_15  : 4;   ///< Reserved

  uint32_t N_SB            : 3;   ///< N_SB Timing: Users can add the busy wait cycle for other
                                  ///< factors. The host controller is set to 5 SCLK clock cycles.

  uint32_t Reserved_19_23  : 5;   ///< Reserved

  uint32_t CMD_CONFLICT_EN : 1;   ///< 1: Enable host controller to check the CMD line conflict
                                  ///<    error

  uint32_t Reserved_25_31  : 7;   ///< Reserved
} sdh_vndr_1_reg_t;

/** \brief Vendor-defined 1 Register */
typedef union
{
  sdh_vndr_1_reg_t B;
  REG_ACCESS_U16   U;
} sdh_vndr_1_reg_u;

/** \brief Vendor-defined 2 Register */
typedef struct
{
  uint32_t CLK_CTRL_SW_RST : 1;   ///< 1: To reset the clock control of the host controller
  uint32_t Reserved        : 31;  ///< Reserved
} sdh_vndr_2_reg_t;

/** \brief Vendor-defined 2 Register */
typedef union
{
  sdh_vndr_2_reg_t B;
  REG_ACCESS_U32   U;
} sdh_vndr_2_reg_u;

/** \brief Vendor-defined 5 Register */
typedef struct
{
  uint32_t DB_TIMEOUT    : 4;     ///< Card Insertion De-bounce Cycle
                                  ///< 0 : 29 chip system clock cycles
                                  ///< 1 : 210 chip system clock cycles
                                  ///< ...
                                  ///< 15: 224 chip system clock cycles

  uint32_t Reserved_4_31 : 28;    ///< Reserved
} sdh_vndr_5_reg_t;

/** \brief Vendor-defined 5 Register */
typedef union
{
  sdh_vndr_5_reg_t B;
  REG_ACCESS_U32   U;
} sdh_vndr_5_reg_u;

/** \brief Vendor-defined 6 Register */
typedef struct
{
  uint32_t HBURST_INCR : 1;       ///< 0: AHB master uses SINGLE and INCR4 as the AHB burst type
  uint32_t Reserved    : 31;      ///< Reserved
} sdh_vndr_6_reg_t;

/** \brief Vendor-defined 6 Register */
typedef union
{
  sdh_vndr_6_reg_t B;
  REG_ACCESS_U32   U;
} sdh_vndr_6_reg_u;

/** \brief Vendor-defined 7 Register */
typedef struct
{
  uint32_t AHB_RESP_ERR_STS : 1;  ///< This bit is set when the AHB master receives an error type
                                  ///< response

  uint32_t Reserved         : 31; ///< Reserved
} sdh_vndr_7_reg_t;

/** \brief Vendor-defined 7 Register */
typedef union
{
  sdh_vndr_7_reg_t B;
  REG_ACCESS_U32   U;
} sdh_vndr_7_reg_u;

/** \brief Vendor-defined 8 Register */
typedef struct
{
  uint32_t AHB_RESP_ERR_STS_EN : 1;   ///< 1: Enable the AHB master response error status
  uint32_t Reserved            : 31;  ///< Reserved
} sdh_vndr_8_reg_t;

/** \brief Vendor-defined 8 Register */
typedef union
{
  sdh_vndr_8_reg_t B;
  REG_ACCESS_U32   U;
} sdh_vndr_8_reg_u;

/** \brief Vendor-defined 9 Register */
typedef struct
{
  uint32_t AHB_RESP_ERR_SIG_EN : 1;   ///< 1: Enable the interrupt generation when the AHB master
                                      ///<    response status is set

  uint32_t Reserved            : 31;  ///< Reserved
} sdh_vndr_9_reg_t;

/** \brief Vendor-defined 9 Register */
typedef union
{
  sdh_vndr_9_reg_t B;
  REG_ACCESS_U32   U;
} sdh_vndr_9_reg_u;

/** \brief Hardware Attributes Register */
typedef struct
{
  uint32_t HW_CONFIG : 8;             ///< 8: Async
                                      ///< 7: 4-bit SD data bus
                                      ///< 6: CPRM present
                                      ///< 5: DLL absent
                                      ///< 4:0 DATA FIFO is 4k SRAM

  uint32_t Reserved  : 24;            ///< Reserved
} sdh_hw_attr_reg_t;

/** \brief Hardware Attributes Register */
typedef union
{
  sdh_hw_attr_reg_t B;
  REG_ACCESS_U32    U;
} sdh_hw_attr_reg_u;

/** \brief Cipher Mode Control Register
 *  \details This register is the configurable register for the CPRM function. When the CPRM
 *           function is used, this register will be used to select the mode of the cipher function
 *           to encrypt or decrypt.
 */
typedef struct
{
  uint32_t C2_G_EN         : 1;   ///< C2 One Way Function Enable

  uint32_t C2_E_EN         : 1;   ///< C2 Encryption with EBC Mode Enable

  uint32_t C2_ECBC_EN      : 1;   ///< C2 Encryption with C-CBC Mode Enable

  uint32_t C2_D_EN         : 1;   ///< C2 Decryption with EBC Mode Enable

  uint32_t C2_DCBC_EN      : 1;   ///< C2 Decryption with C-CBC Mode Enable

  uint32_t RNGC2_G_EN      : 1;   ///< C2 Random Number Generator Enable

  uint32_t AUTO_C2_ECBC_EN : 1;   ///< Auto C2 Encryption with C-CBC Mode Enable
                                  ///< In this mode, data written to the buffer will be
                                  ///< automatically encrypted and sent to the TX FIFO. The data
                                  ///< lengths should be multiples of 8 bytes.

  uint32_t AUTO_C2_DCBC_EN : 1;   ///< Auto C2 Decryption with C-CBC Mode Enable
                                  ///< In this mode, data will be automatically decrypted and sent
                                  ///< to the buffer. The data lengths should be multiples of 8
                                  ///< bytes.

  uint32_t SEC_ACCESS_EN   : 1;   ///< Secret Constant Table Access Enable
                                  ///< This bit must be enabled before writing or reading the secret
                                  ///< constant table. Once this bit is enabled, the firmware will
                                  ///< always access from the very beginning of the secret constant
                                  ///< table.

  uint32_t CH_ENDIAN       : 1;   ///< Change Endianness
                                  ///< In this mode, the endianness of the encrypted data will be
                                  ///< changed before being written to the TX FIFO. In this mode,
                                  ///< the endianness of data from the RX FIFO will be changed
                                  ///< before decryption.

  uint32_t SWAP_HL         : 1;   ///< 1: Swap the high/low word of the encrypted data to TX FIFO
                                  ///<    The high-word and low-word of the encrypted data will be
                                  ///<    swapped before being written to TX FIFO. The highword and
                                  ///<    low-word of the encrypted data will be swapped before
                                  ///<    decryption.

  uint32_t Reserved        : 21;  ///< Reserved
} sdh_cpr_mod_cntl_reg_t;

/** \brief Cipher Mode Control Register */
typedef union
{
  sdh_cpr_mod_cntl_reg_t B;
  REG_ACCESS_U32         U;
} sdh_cpr_mod_cntl_reg_u;

/** \brief Cipher Mode Status Register */
typedef struct
{
  uint32_t CP_RDY   : 1;    ///< Cipher is ready
                            ///< When this bit is set to 1, reading 0x19C and 0x1A0 will retrieve
                            ///< cipher or plain text

  uint32_t Reserved : 31;   ///< Reserved
} sdh_cpr_mod_sts_reg_t;

/** \brief Cipher Mode Status Register */
typedef union
{
  sdh_cpr_mod_sts_reg_t B;
  REG_ACCESS_U32        U;
} sdh_cpr_mod_sts_reg_u;

/** \brief Cipher Mode Status Enable Register */
typedef struct
{
  uint32_t RDY_SIG_EN : 1;  ///< Cipher Ready Signal Enable
  uint32_t Reserved   : 31; ///< Reserved
} sdh_cpr_mod_sig_en_reg_t;

/** \brief Cipher Mode Status Enable Register */
typedef union
{
  sdh_cpr_mod_sig_en_reg_t B;
  REG_ACCESS_U32           U;
} sdh_cpr_mod_sig_en_reg_u;

/** \brief Input Data LSB Register */
typedef struct
{
  uint32_t DATA;            ///< Input port for the input data bits 31:0
} sdh_in_data_lsb_reg_t;

/** \brief Input Data LSB Register */
typedef union
{
  sdh_in_data_lsb_reg_t B;
  REG_ACCESS_U32        U;
} sdh_in_data_lsb_reg_u;

/** \brief Input Data MSB Register */
typedef struct
{
  uint32_t DATA;            ///< Input port for the input data bits 63:32
} sdh_in_data_msb_reg_t;

/** \brief Input Data MSB Register */
typedef union
{
  sdh_in_data_msb_reg_t B;
  REG_ACCESS_U32        U;
} sdh_in_data_msb_reg_u;

/** \brief Input Key LSB Register */
typedef struct
{
  uint32_t KEY;             ///< Input port for the input key bits 31:0
} sdh_in_key_lsb_reg_t;

typedef union
{
  sdh_in_key_lsb_reg_t B;
  REG_ACCESS_U32       U;
} sdh_in_key_lsb_reg_u;

/** \brief Key MSB Register */
typedef struct
{
  uint32_t KEY;             ///< Input port for the input key bits 63:32
} sdh_in_key_msb_reg_t;

/** \brief Key MSB Register */
typedef union
{
  sdh_in_key_msb_reg_t B;
  REG_ACCESS_U32       U;
} sdh_in_key_msb_reg_u;

/** \brief Output Data LSB Register */
typedef struct
{
  uint32_t DATA;            ///< Output port for the output data bits 31:0
} sdh_out_data_lsb_reg_t;

/** \brief Output Data LSB Register */
typedef union
{
  sdh_out_data_lsb_reg_t B;
  REG_ACCESS_U32     U;
} sdh_out_data_lsb_reg_u;

/** \brief Output Data MSB Register */
typedef struct
{
  uint32_t DATA;            ///< Output port for the output data bits 63:32
} sdh_out_data_msb_reg_t;

/** \brief Output Data MSB Register */
typedef union
{
  sdh_out_data_msb_reg_t B;
  REG_ACCESS_U32         U;
} sdh_out_data_msb_reg_u;

/** \brief Secret Constant Table Data Port */
typedef struct
{
  uint32_t DATA_PORT : 8;   ///< Secret constant table data port.
                            ///< 256 bytes are needed; this port should be written 256 times to
                            ///< initialize the secret constant table

  uint32_t Reserved  : 24;  ///< Reserved
} sdh_scrt_cons_data_reg_t;

typedef union
{
  sdh_scrt_cons_data_reg_t B;
  REG_ACCESS_U32           U;
} sdh_scrt_cons_data_reg_u;

/** \brief SD-Host register mapping for FT9xx */
typedef struct
{
  __IO sdh_auto_cmd23_arg2_reg_u       SDH_AUTO_CMD23_ARG2;
  __IO sdh_blk_size_reg_u              SDH_BLK_SIZE;
  __IO sdh_blk_count_reg_u             SDH_BLK_COUNT;
  __IO sdh_arg_1_reg_u                 SDH_ARG_1;
  __IO sdh_tnsfer_mode_reg_u           SDH_TNSFER_MODE;
  __IO shd_cmd_reg_u                   SDH_CMD;
  __IO sdh_response_reg_t              SDH_RESPONSE;
  __IO sdh_buf_data_reg_u              SDH_BUF_DATA;
  __IO sdh_present_state_reg_u         SDH_PRESENT_STATE;
  __IO sdh_hst_cntl_1_reg_u            SDH_HST_CNTL_1;
  __IO sdh_pwr_cntl_reg_u              SDH_PWR_CNTL;
  __IO sdh_clk_cntl_reg_u              SDH_CLK_CNTL;
  __IO sdh_timeout_cntl_reg_t          SDH_TIMEOUT_CNTL;
  __IO sdh_sw_rst_reg_t                SDH_SW_RST;
  __IO sdh_nrml_int_sts_reg_u          SDH_NRML_INT_STATUS;
  __IO sdh_err_int_sts_reg_u           SDH_ERR_INT_STATUS;
  __IO sdh_nrml_int_enb_reg_u          SDH_NRML_INT_ENABLE;
  __IO sdh_nrml_int_sgnl_enb_reg_u     SDH_NRML_INT_SGNL_ENABLE;
  __IO sdh_err_int_sgnl_enb_reg_u      SDH_ERR_INT_SGNL_ENABLE;
  __IO sdh_auto_cmd12_err_sts_reg_u    SDH_AUTO_CMD12_ERR_STATUS;
  __IO sdh_host_cntl_2_reg_u           SDH_HOST_CNTL_2;
  __IO sdh_cap_1_reg_u                 SDH_CAP_1;
  __IO sdh_cap_2_reg_u                 SDH_CAP_2;
       uint32_t                        SDH_RSRV_1;                      ///< Reserved
       uint32_t                        SDH_RSRV_2;                      ///< Reserved
  __IO sdh_force_evt_cmd_err_sts_reg_u SDH_FORCE_EVT_CMD_ERR_STATUS;
  __IO sdh_force_evt_err_int_sts_reg_u SDH_FORCE_EVT_ERR_INT_STATUS;
       uint32_t                        SDH_RSRV_3;                      ///< Reserved
       uint32_t                        SDH_RSRV_4;                      ///< Reserved
  __IO sdh_prst_init_reg_u             SDH_PRST_INIT;
  __IO sdh_prst_dflt_spd_reg_u         SDH_PRST_DFLT_SPD;
  __IO sdh_prst_high_spd_reg_u         SDH_PRST_HIGH_SPD;
  __IO sdh_prst_sdr12_reg_u            SDH_PRST_SDR12;
  __IO sdh_prst_sdr25_reg_u            SDH_PRST_SDR25;
  __IO sdh_prst_sdr50_reg_u            SDH_PRST_SDR50;
  __IO sdh_prst_sdr104_reg_u           SDH_PRST_SDR104;
  __IO sdh_prst_ddr50_reg_u            SDH_PRST_DDR50;
       uint32_t                        SDH_RSRV_5;                      ///< Reserved
  __IO sdh_hc_ver_reg_u                SDH_HC_VER;
} sdh_regs_t;

/** @brief FT900 32 bit registers
 *  These are used to provide the actual 32bit address of the sdhost registers
 *  These are named arbitrarily
 */
/** @brief Register mappings for SPI registers - for FT900 Rev B */
typedef struct
{
  __IO uint32_t unused0;
  /** @brief Block Size Register & Block Count Register */
  __IO uint32_t BS_BC;
  /** @brief Argument 1 Register */
  __IO uint32_t ARG1;
  /** @brief Transfer Mode Register & Command Register */
  __IO uint32_t TM_CMD;
  /** @brief Response Register 0 */
  __IO uint32_t RESPONSE0;
  /** @brief Response Register 1 */
  __IO uint32_t RESPONSE1;
  /** @brief Response Register 2 */
  __IO uint32_t RESPONSE2;
  /** @brief Response Register 3 */
  __IO uint32_t RESPONSE3;
  /** @brief Buffer Data Port Register */
  __IO uint32_t BUFDATAPORT;
  /** @brief Present State Register */
  __IO uint32_t PRESENTSTATE;
  /** @brief Host Control 1 Register & Power Control Register & Block Gap Control Register */
  __IO uint32_t HOSTCTRL1_PWR_BLKGAP;
  /** @brief Clock Control Register & Timeout Control Register & Software Reset Register */
  __IO uint32_t CLK_TIMEOUT_SWRESET;
  /** @brief Normal Interrupt Status Register & Error Interrupt Status Register */
  __IO uint32_t NORMINTSTATUS_ERRINTSTATUS;
  /** @brief Normal Interrupt Status Enable Reg. & Error Interrupt Status Enable Reg. */
  __IO uint32_t NORMINTSTATUSEN_ERRINTSTATUSEN;
  /** @brief Normal Interrupt Signal Enable Reg. & Error Interrupt Signal Enable Reg. */
  __IO uint32_t NORMINTSIGEN_ERRINTSIGEN;
  /** @brief Auto CMD12 Error Status Register & Host Control 2 Register */
  __IO uint32_t AUTOCMD12_HOSTCTRL2;
  /** @brief Capabilities Register 0 */
  __IO uint32_t CAP0;
  /** @brief Capabilities Register 1 */
  __IO uint32_t CAP1;
  /** @brief Maximum Current Capabilities Register 0 */
  __IO uint32_t MAXCURRENTCAP0;
  /** @brief Maximum Current Capabilities Register 1 */
  __IO uint32_t MAXCURRENTCAP1;
  /** @brief Force Event Reg. for Auto CMD12 Error Status & Force Event Reg.
   *         for Error Interrupt Status */
  __IO uint32_t FORCEEVENTCMD12_FORCEEVENTERRINT;
  /** @brief ADMA Error Status Register */
  __IO uint32_t ADMAERRORSTATUS;
  /** @brief ADMA System Address Register */
  __IO uint32_t ADMASYSADDR;
  __IO uint32_t unused1;
  /** @brief Preset Value Register 0 */
  __IO uint32_t PRESETVALUE0;
  /** @brief Preset Value Register 1 */
  __IO uint32_t PRESETVALUE1;
  /** @brief Preset Value Register 2 */
  __IO uint32_t PRESETVALUE2;
  /** @brief Preset Value Register 3 */
  __IO uint32_t PRESETVALUE3;
} ft900_sdhost_regs_t;

/** \brief SD-Host vendor register mapping for FT9xx */
typedef struct
{
  __IO sdh_vndr_0_reg_u         SDH_VNDR_0;
  __IO sdh_vndr_1_reg_u         SDH_VNDR_1;
  __IO sdh_vndr_2_reg_u         SDH_VNDR_2;
       uint32_t                 SDH_VNDR_3;             ///< Reserved
       uint32_t                 SDH_VNDR_4;             ///< Reserved
  __IO sdh_vndr_5_reg_u         SDH_VNDR_5;
  __IO sdh_vndr_6_reg_u         SDH_VNDR_6;
  __IO sdh_vndr_7_reg_u         SDH_VNDR_7;
  __IO sdh_vndr_8_reg_u         SDH_VNDR_8;
  __IO sdh_vndr_9_reg_u         SDH_VNDR_9;
       uint32_t                 SDH_RSRV_6;             ///< Reserved
  __IO sdh_hw_attr_reg_u        SDH_HW_ATTR;
  __IO sdh_cpr_mod_cntl_reg_u   SDH_CPR_MOD_CNTL;
  __IO sdh_cpr_mod_sts_reg_u    SDH_CPR_MOD_STATUS;
  __IO sdh_cpr_mod_sig_en_reg_u SDH_CPR_MOD_STATUS_EN;
  __IO sdh_in_data_lsb_reg_u    SDH_IN_DATA_LSB;
  __IO sdh_in_data_msb_reg_u    SDH_IN_DATA_MSB;
  __IO sdh_in_key_lsb_reg_u     SDH_IN_KEY_LSB;
  __IO sdh_in_key_msb_reg_u     SDH_IN_KEY_MSB;
  __IO sdh_out_data_lsb_reg_u   SDH_OUT_DATA_LSB;
  __IO sdh_out_data_msb_reg_u   SDH_OUT_DATA_MSB;
  __IO sdh_scrt_cons_data_reg_u SDH_SCRT_CONS_DATA;
} sdh_vendor_regs_t;

typedef struct
{
  /** @brief Vendor-defined Register 0 */
  __IO uint32_t VENDOR0;
  /** @brief Vendor-defined Register 1 */
  __IO uint32_t VENDOR1;
  __IO uint32_t unused2;
  __IO uint32_t unused3;
  __IO uint32_t unused4;
  /** @brief Vendor-defined Register 5 */
  __IO uint32_t VENDOR5;
} ft900_sdhost_vendor_regs_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/* FUNCTION PROTOTYPES *************************************************************/

#endif /* FT900_SDHOST_REGISTERS_H_ */
