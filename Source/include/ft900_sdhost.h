/**
    @file ft900_sdhost.h

    @brief SD Host

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

#ifndef FT900_SDHOST_H
#define FT900_SDHOST_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* INCLUDES ************************************************************************/

#include <stdint.h>
#include <stdbool.h>

#include <registers/ft900_registers.h>

/* CONSTANTS ***********************************************************************/

/** @brief SD host registers.
 *
 *  These constants are used to identify the individual sdhost registers, whatever their size.
 *  These are used to symbolically address registers via the functions read_sdhost_reg()
 *  and write_sdhost_reg().
 *
 *  This is all necessary due to the fact we can only access the registers with 32bit values.
 */
/** @brief Auto CMD23 Argument 2 Register */
#define SDH_AUTO_CMD23_ARG2                  1
/** @brief Block Size Register */
#define SDH_BLK_SIZE                         2
/** @brief Block Count Register */
#define SDH_BLK_COUNT                        3
/** @brief Argument 1 Register */
#define SDH_ARG_1                            4
/** @brief Transfer Mode Register */
#define SDH_TNSFER_MODE                      5
/** @brief Command Register */
#define SDH_CMD                              6
/** @brief Response Registers 0 */
#define SDH_RESPONSE0                        7
/** @brief Response Registers 1 */
#define SDH_RESPONSE1                        8
/** @brief Response Registers 2 */
#define SDH_RESPONSE2                        9
/** @brief Response Registers 3 */
#define SDH_RESPONSE3                       10
/** @brief Buffer Data Port Register */
#define SDH_BUF_DATA                        11
/** @brief Present State Register */
#define SDH_PRESENT_STATE                   12
/** @brief Host Control 1 Register */
#define SDH_HST_CNTL_1                      13
/** @brief Power Control Register */
#define SDH_PWR_CNTL                        14
/** @brief Block Gap Control Register */
#define SDH_BLK_GAP_CNTL                    15
/** @brief Clock Control Register */
#define SDH_CLK_CNTL                        16
/** @brief Timeout Control Register */
#define SDH_TIMEOUT_CNTL                    17
/** @brief Software Reset Register */
#define SDH_SW_RST                          18
/** @brief Normal Interrupt Status Register */
#define SDH_NRML_INT_STATUS                 19
/** @brief Error Interrupt Status Register */
#define SDH_ERR_INT_STATUS                  20
/** @brief Normal Interrupt Status Enable Register */
#define SDH_NRML_INT_STATUS_ENABLE          21
/** @brief Error Interrupt Status Enable Register */
#define SDH_ERR_INT_STATUS_ENABLE           22
/** @brief Normal Interrupt Signal Enable Register */
#define SDH_NRML_INT_SGNL_ENABLE            23
/** @brief Error Interrupt Signal Enable Register */
#define SDH_ERR_INT_SGNL_ENABLE             24
/** @brief Auto CMD12 Error Status Register */
#define SDH_AUTO_CMD12_ERR_STATUS           25
/** @brief Host Control 2 Register */
#define SDH_HST_CNTL_2                      26
/** @brief Capabilities Register 1 */
#define SDH_CAP_1                           27
/** @brief Capabilities Register 2 */
#define SDH_CAP_2                           28
/** @brief Reserved Register 1 */
#define SDH_RSRV_1                          29
/** @brief Reserved Register 2 */
#define SDH_RSRV_2                          30
/** @brief Force Event Register for Auto CMD12 Error Status */
#define SDH_FORCE_EVENT_CMD_ERR_STATUS      31
/** @brief Force Event Register for Error Interrupt Status */
#define SDH_FORCE_EVENT_ERR_INT_STATUS      32
/** @brief Reserved Register 3 */
#define SDH_RSRV_3                          33
/** @brief Reserved register 4 */
#define SDH_RSRV_4                          34
/** @brief Preset Value Register 3 */
#define SDH_PRST_INIT                       35
/** @brief Preset Value Register 3 */
#define SDH_PRST_DFLT_SPD                   36
/** @brief Preset Value Register 3 */
#define SDH_PRST_HIGH_SPD                   37
/** @brief Preset Value Register 3 */
#define SDH_PRST_SDR12                      38
/** @brief Vendor-defined Register 0 */
#define SDH_VNDR_0                          39
/** @brief Vendor-defined Register 1 */
#define SDH_VNDR_1                          40
/** @brief Vendor-defined Register 5 */
#define SDH_VNDR_5                          41

/*
 *  Data block (sector) size.
 */
#define SDHOST_BLK_SIZE                512

/*
 *  Data transfer direction definitions, these should not be modified.
 */
#define SDHOST_WRITE                        0x0000
#define SDHOST_READ                         0x0010

/*
 *  SD card types.
 */
#define SD_V1	0x01
#define SD_V2	0x02
#define MMC_V3	0x03
#define MMC		0x04

/* TYPES ***************************************************************************/

/*
 *  The type SDHOST_STATUS is returned from the API function calls
 */

typedef enum {
    SDHOST_OK = 0,				/* OK */
    SDHOST_ERROR,				/* general error */
    SDHOST_CARD_INSERTED,			/* card inserted */
    SDHOST_CARD_REMOVED,			/* card removed */
    SDHOST_INVALID_RESPONSE_TYPE,		/* invalid response */
    SDHOST_CMD_TIMEOUT,				/* command timeout */
    SDHOST_UNUSABLE_CARD,			/* card is unusable */
	SDHOST_CMD1_FAILED,				/* command 1 (send op cond) failed */
    SDHOST_CMD2_FAILED,				/* command 2 (get CID) failed */
    SDHOST_CMD3_FAILED,				/* command 3 (get RCA) failed */
    SDHOST_CMD8_FAILED,				/* command 8 (voltage check) failed */
    SDHOST_CMD9_FAILED,				/* command 9 (send CSD) failed */
    SDHOST_CMD55_FAILED,			/* command 55 (app cmd) failed */
    SDHOST_ACMD41_FAILED,			/* command 41 failed */
    SDHOST_CANNOT_ENTER_TRANSFER_STATE,		/* cannot enter transfer state */
    SDHOST_CANNOT_SET_CARD_BUS_WIDTH,		/* cannot set bus width */
	SDHOST_CANNOT_SET_CARD_HIGH_SPEED,		/* cannot set high speed */
    SDHOST_RESPONSE_ERROR,			/* response error */
    SDHOST_WRITE_ERROR,				/* read error */
    SDHOST_READ_ERROR,				/* write error */
	SDHOST_NOT_INITIALISED,			/* host is not initialised by driver */
	SDHOST_CARD_NOT_INITIALISED,	/* card is not initialised by driver */
} SDHOST_STATUS;

/*
 *  sdhost context
 */
typedef struct
{
        SDHOST_STATUS  internalStatus;  /* internal status, mainly for debugging */
        bool            isSDSCCard;     /* is Secure digital standard capacity */
        uint8_t 		cardType;		/* SDv2/SDv1/MMCv3 card */
        uint32_t		capacity;		/* Total capacity in blocks */
        uint32_t		block_size;		/* Erase block size */
        uint32_t        CID[4];         /* card ID */
        uint32_t        CSD[4];         /* card specific data */
        uint32_t        OCR;            /* operations condition register*/
        uint16_t        RCA;            /* relative card address */
} sdhost_context_t;

/* FUNCTIONS ***********************************************************************/

/** @brief Function used for initializing system registers.
*/
void sdhost_sys_init(void);

/** @brief Function initializes SD Host device.
*/
void sdhost_init(void);

/** @brief Check to see if a card is inserted
 *  @returns either SDHOST_CARD_INSERTED or SDHOST_CARD_REMOBVED
 */
SDHOST_STATUS sdhost_card_detect(void);

/** @brief Identifies and initializes the inserted card
 *  @returns either SDHOST_ERROR or SDHOST_OK
 */
SDHOST_STATUS sdhost_card_init(void);

/** @brief Transfer data to/from SD card
 *  @param [in] direction SDHOST_READread or SDHOST_WRITE
 *  @param buf address of memory data to be read or written
 *  @param [in] numBytes size of data to be written
 *  @param [in] addr address of SD card to written to or read from
 *  @returns SDHOST_STATUS enum indicationg on outcome of operation
 */
SDHOST_STATUS sdhost_transfer_data(uint8_t direction, void *buf, uint32_t numBytes, uint32_t addr);

/** @brief Abort current sdhost operation
 *  @returns
 */
SDHOST_STATUS sdhost_abort(void);

/** @brief Get the internal properties of the attached card (context)
 *  @returns A pointer to SD HOST context
 */
sdhost_context_t *sdhost_get_context(void);

/** @brief Get the capacity of the attached card.
 *  @returns The capacity of the card in blocks.
 */
uint32_t sdhost_get_capacity(void);

/** @brief Get the number of blocks to erase for the attached card.
 *  @returns The number of blocks in an allocation unit to use for erasing.
 */
uint32_t sdhost_get_erase_block_count(void);

/** @brief Get the block size (sector size) of the attached card.
 *  @returns The number of bytes in each block on the card.
 */
uint32_t sdhost_get_block_size(void);

/** @brief Read the SD STATUS register of the card
 *  @param [out] pBuff Pointer to buffer to store status register dump
 */
void sdhost_get_card_status_reg(uint32_t* pBuff);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* FT900_SDHOST_H */
