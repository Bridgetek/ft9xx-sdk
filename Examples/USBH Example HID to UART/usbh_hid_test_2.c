/**
  @file usbh_hid_test_2.c
  @brief
  USB HID Device Test

  This example program will translate HID keyboard scancode reports received
  from suitable HID devices detected on the USB. It is useful for keyboards
  and barcode scanners.
*/
/*
 * ============================================================================
 * History
 * =======
 * GDM 21 Jan 2023 : Created
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

/* INCLUDES ************************************************************************/

#include <stdint.h>
#include <stdio.h>

#include <ft900.h>
#include <ft900_usb.h>
#include <ft900_usb_hid.h>
#include <ft900_usbh_hid.h>
// For startup DFU mode optional feature.
#include <ft900_startup_dfu.h>

/* CONSTANTS ***********************************************************************/

/* TYPEDEFS AND STRUCTURES *********************************************************/

/**
 @struct hid_report_structure
 @brief HID Report structure to match
 hid_report_descriptor_keyboard descriptor.
 **/
typedef struct PACK hid_report_structure_t
{
    union {
        struct {
            unsigned char kbdLeftControl :1;
            unsigned char kbdLeftShift :1;
            unsigned char kbdLeftAlt :1;
            unsigned char kbdLeftGUI :1;
            unsigned char kbdRightControl :1;
            unsigned char kbdRightShift :1;
            unsigned char kbdRightAlt :1;
            unsigned char kbdRightGUI :1;
        };
        unsigned char arrayMap;
    };

    unsigned char arrayNotUsed;  // [1]
    unsigned char arrayKeyboard; // [2]
    unsigned char arrayResv1;
    unsigned char arrayResv2;
    unsigned char arrayResv3;
    unsigned char arrayResv4;
    unsigned char arrayResv5;
} hid_report_structure_t;

/**
 @name Keyboard Scan Codes Lookup table (for ASCII keys)
 @brief Lookup table for converting ASCII to scan codes.
 @details Columns are [0] ASCII character from UART terminal
                      [1] keyscan code to send in HID report.
                      [2] non-zero to set shift key pressed.
                      [3] non-zero to set ctrl key pressed.
                      [4] non-zero to set alt key pressed.
 */
//@{
struct key_mappings
{
    char msg;
    uint8_t scan;
    uint8_t shift;
    uint8_t ctrl;
    uint8_t alt;
};

/* GLOBAL VARIABLES ****************************************************************/

/* LOCAL VARIABLES *****************************************************************/

const struct key_mappings ASCII_scancode[] =
{
        {0x0d, 40, 0, 0, 0 }, // Enter key
        {'a', 4, 0, 0, 0 }, {'A', 4, 1, 0, 0 }, {0x01, 4, 0, 1, 0 },
        {'b', 5, 0, 0, 0 }, {'B', 5, 1, 0, 0 }, {0x02, 5, 0, 1, 0 },
        {'c', 6, 0, 0, 0 }, {'C', 6, 1, 0, 0 }, {0x03, 6, 0, 1, 0 },
        {'d', 7, 0, 0, 0 }, {'D', 7, 1, 0, 0 }, {0x04, 7, 0, 1, 0 },
        {'e', 8, 0, 0, 0 }, {'E', 8, 1, 0, 0 }, {0x05, 8, 0, 1, 0 },
        {'f', 9, 0, 0, 0 }, {'F', 9, 1, 0, 0 }, {0x06, 9, 0, 1, 0 },
        {'g', 10, 0, 0, 0 }, {'G', 10, 1, 0, 0 }, {0x07, 10, 0, 1, 0 },
        {'h', 11, 0, 0, 0 }, {'H', 11, 1, 0, 0 },
        {'i', 12, 0, 0, 0 }, {'I', 12, 1, 0, 0 },
        {'j', 13, 0, 0, 0 }, {'J', 13, 1, 0, 0 }, {0x0a, 13, 0, 1, 0 },
        {'k', 14, 0, 0, 0 }, {'K', 14, 1, 0, 0 }, {0x0b, 14, 0, 1, 0 },
        {'l', 15, 0, 0, 0 }, {'L', 15, 1, 0, 0 }, {0x0c, 15, 0, 1, 0 },
        {'m', 16, 0, 0, 0 }, {'M', 16, 1, 0, 0 },
        {'n', 17, 0, 0, 0 }, {'N', 17, 1, 0, 0 }, {0x0e, 17, 0, 1, 0 },
        {'o', 18, 0, 0, 0 }, {'O', 18, 1, 0, 0 }, {0x0f, 18, 0, 1, 0 },
        {'p', 19, 0, 0, 0 }, {'P', 19, 1, 0, 0 }, {0x10, 19, 0, 1, 0 },
        {'q', 20, 0, 0, 0 }, {'Q', 20, 1, 0, 0 }, {0x11, 20, 0, 1, 0 },
        {'r', 21, 0, 0, 0 }, {'R', 21, 1, 0, 0 }, {0x12, 21, 0, 1, 0 },
        {'s', 22, 0, 0, 0 }, {'S', 22, 1, 0, 0 }, {0x13, 22, 0, 1, 0 },
        {'t', 23, 0, 0, 0 }, {'T', 23, 1, 0, 0 }, {0x14, 23, 0, 1, 0 },
        {'u', 24, 0, 0, 0 }, {'U', 24, 1, 0, 0 }, {0x15, 24, 0, 1, 0 },
        {'v', 25, 0, 0, 0 }, {'V', 25, 1, 0, 0 }, {0x16, 25, 0, 1, 0 },
        {'w', 26, 0, 0, 0 }, {'W', 26, 1, 0, 0 }, {0x17, 26, 0, 1, 0 },
        {'x', 27, 0, 0, 0 }, {'X', 27, 1, 0, 0 }, {0x18, 27, 0, 1, 0 },
        {'y', 28, 0, 0, 0 }, {'Y', 28, 1, 0, 0 }, {0x19, 28, 0, 1, 0 },
        {'z', 29, 0, 0, 0 }, {'Z', 29, 1, 0, 0 }, {0x1a, 29, 0, 1, 0 },
        {'1', 30, 0, 0, 0 }, {'!', 30, 1, 0, 0 },
        {'2', 31, 0, 0, 0 }, {'"', 31, 1, 0, 0 },
        {'3', 32, 0, 0, 0 }, //{'�', 32, 1, 0, 0 },
        {'4', 33, 0, 0, 0 }, {'$', 33, 1, 0, 0 },
        {'5', 34, 0, 0, 0 }, {'%', 34, 1, 0, 0 },
        {'6', 35, 0, 0, 0 }, {'^', 35, 1, 0, 0 },
        {'7', 36, 0, 0, 0 }, {'&', 36, 1, 0, 0 },
        {'8', 37, 0, 0, 0 }, {'*', 37, 1, 0, 0 },
        {'9', 38, 0, 0, 0 }, {'(', 38, 1, 0, 0 },
        {'0', 39, 0, 0, 0 }, {')', 39, 1, 0, 0 },
        {0x7f, 42, 0, 0, 0 },  // <BS> Backspace CTRL+?
        {0x08, 42, 0, 0, 0 },  // <BS> Backspace CTRL+H
        {0x09, 43, 0, 0, 0 },  // <TAB> Horizontal tab CTRL+I
        {' ', 44, 0, 0, 0 },
        {'-', 45, 0, 0, 0 }, {'_', 45, 1, 0, 0 },
        {'=', 46, 0, 0, 0 }, {'+', 46, 1, 0, 0 },
        {'[', 47, 0, 0, 0 }, {'{', 47, 1, 0, 0 },
        {']', 48, 0, 0, 0 }, {'}', 48, 1, 0, 0 },
        {'#', 50, 0, 0, 0 }, {'~', 50, 1, 0, 0 },
        {';', 51, 0, 0, 0 }, {':', 51, 1, 0, 0 },
        {'\'', 52, 0, 0, 0 }, {'@', 52, 1, 0, 0 },
        {',', 54, 0, 0, 0 }, {'<', 54, 1, 0, 0 },
        {'.', 55, 0, 0, 0 }, {'>', 55, 1, 0, 0 },
        {'/', 56, 0, 0, 0 }, {'?', 56, 1, 0, 0 },
        {'\\', 100, 0, 0, 0 }, {'|', 100, 1, 0, 0 },

        { 0, 0, 0, 0 }, // end marker
};
//@}

/* MACROS **************************************************************************/

/* LOCAL FUNCTIONS / INLINES *******************************************************/

void ISR_timer(void)
{
    //printf("ISR_timer");;
    if (timer_is_interrupted(timer_select_a))
    {
        //printf(".");
        //fflush(stdout);
        // Call USB timer handler to action transaction and hub timers.
        USBH_timer();
    }
}

void hid_testing(USBH_device_handle hHIDdev, USBH_interface_handle hHID)
{
    USBH_HID_context hidCtx;
    int8_t status;
    uint8_t hidDescBuffer[255];
    uint8_t buffer[512];
    int i;
    int desc;
    int32_t count;
    uint16_t usbVid, usbPid;
    USBH_device_info devInfo;
    USB_hid_descriptor *hidDesc;

    char *speed[3] = {"low", "full", "high"};

    USBH_HID_init(hHIDdev, hHID, &hidCtx);

    if (USBH_device_get_vid_pid(hHIDdev, &usbVid, &usbPid) == USBH_OK)
    {
        printf("VID: %04x PID: %04x\r\n", usbVid, usbPid);
    }
    if (USBH_device_get_info(hHIDdev, &devInfo) == USBH_OK)
    {
        printf("Speed: %d %s \r\n", devInfo.speed, speed[devInfo.speed]);
        printf("Address: %d \r\n", devInfo.addr);
    }

    hidDesc = (USB_hid_descriptor *)&hidDescBuffer;
    if (USBH_HID_get_hid_descriptor(&hidCtx, sizeof(USB_hid_descriptor), hidDescBuffer) == USBH_OK)
    {
        printf("Number of report descriptors %d\r\n", hidDesc->bNumDescriptors);

        // If there are multiple descriptor get them all.
        if (hidDesc->bNumDescriptors > 1)
        {
            USBH_HID_get_hid_descriptor(&hidCtx, hidDesc->bLength, hidDescBuffer);
        }
        printf("HID descriptor: ");
        for (i = 0; i < hidDesc->bLength; i++)
            printf("%02x ", hidDescBuffer[i]);
        printf("\r\n");

        // For each report descriptor read it in.
        for (desc = 1; desc <= hidDesc->bNumDescriptors; desc++)
        {
            // Location of additional bDescriptorType and wDescriptorLength defined in 6.2.1 HID Descriptor
            // Note that the first descriptor is
            uint8_t type = hidDescBuffer[(3 * (desc - 1)) + 6];
            uint16_t size = hidDescBuffer[(3 * (desc - 1)) + 7] + (hidDescBuffer[(3 * (desc - 1)) + 8] << 8);

            printf("Report descriptor %d type 0x%x size %u\r\n", desc, type, size);

            if (USBH_HID_get_report_descriptor(&hidCtx, desc, size, buffer) == USBH_OK)
            {
                printf("Report descriptor %d: ", desc);
                for (i = 0; i < size; i++)
                    printf("%02x ", buffer[i]);
                printf("\r\n");
            }
        }
    }

    printf("Setting idle\r\n");
    USBH_HID_set_idle(&hidCtx, 0);
    printf("Reports from device %d bytes:\r\n", USBH_HID_get_report_size_in(&hidCtx));

    while (1)
    {
        count = USBH_transfer(hidCtx.hHIDEpIn, buffer, USBH_HID_get_report_size_in(&hidCtx), 1000);
        if (count >= 0){
        	status = USBH_OK;
        }
        else
		{
            /* Negative values returned from USBH_transfer are errors. */
        	status = count;
		}
        //status = USBH_HID_get_report(&hidCtx, buffer);

        if (status == USBH_OK)
        {
            hid_report_structure_t *report = (hid_report_structure_t *)buffer;
            int key;

            if (report->arrayKeyboard != 0)
            {
                for (key = 0; ASCII_scancode[key].scan; key++)
                {
                    if ((ASCII_scancode[key].scan == report->arrayKeyboard)
                        && (ASCII_scancode[key].shift == (report->kbdLeftShift | report->kbdRightShift)))
                    {
                        // Add a newline if we receive a carriage return.
                        if (ASCII_scancode[key].msg == '\r')
                        {
                            printf("\n");
                        }

                        printf("%c", ASCII_scancode[key].msg);

                        // Make sure the output is sent to the UART.
                        fflush(stdout);
                        break;
                    }
                }
                if (ASCII_scancode[key].scan == 0)
                {
                    printf("?");
                }
            }
        }
        else
        {
            switch (status)
            {
            case USBH_ERR_TIMEOUT:
                /* HIDs will timeout frequently and expectedly. */
                /*printf("Timeout\r\n");*/
                 break;
            case USBH_ERR_HALTED:
                printf("Halted\r\n"); break;
            case USBH_ERR_NOT_FOUND:
                printf("Not found\r\n"); break;
            case USBH_ERR_REMOVED:
                printf("Removed\r\n"); break;
            case USBH_ERR_DATA_BUF:
                printf("Data buf error\r\n"); break;
            case USBH_ERR_RESOURCES:
                printf("Resources\r\n"); break;
            case USBH_ERR_USBERR:
                printf("USB error\r\n"); break;
            default:
                printf("Unknown error %d\r\n", status); break;
            }
            /* Exit while loop if there is any unexpected error. */
            /* This will force the calling function to reconnect. */
            if (status != USBH_ERR_TIMEOUT)
                break;
        }
    }
}

int8_t hub_scan_for_hid(USBH_device_handle hDev, int level)
{
    int8_t status = USBH_ERR_NOT_FOUND;
    USBH_device_handle hNext;
    USBH_interface_handle hInterface;
    uint8_t usbClass;
    uint8_t usbSubclass;
    uint8_t usbProtocol;

    do {
        // Search all the interfaces on this device for a HID interface
        status = USBH_get_interface_list(hDev, &hInterface);
        while (status == USBH_OK)
        {
               if (USBH_interface_get_class_info(hInterface, &usbClass, &usbSubclass, &usbProtocol) == USBH_OK)
            {
                   // If it is a HID interface then use that...
                   if (usbClass == USB_CLASS_HID)
                   //if (usbClass == USB_CLASS_VENDOR)
                   {
                       printf("HID device found at level %d\r\n", level);
                       hid_testing(hDev, hInterface);
                   }
            }
               // Next interface on this device
            status = USBH_get_next_interface(hInterface, &hInterface);
        }

        // Get any child devices of this device (i.e. this is a hub).
        status = USBH_get_device_list(hDev, &hNext);
        if (status == USBH_OK)
        {
            // Recursively scan.
            status = hub_scan_for_hid(hNext, level + 1);
        }

        // Get any other devices on the same device.
        status = USBH_get_next_device(hDev, &hNext);
        if (status == USBH_OK)
        {
            hDev = hNext;
        }

    } while (status == USBH_OK);
    return status;
}

uint8_t usbh_testing(void)
{
    int8_t status;
    USBH_device_handle hRootDev;
    USBH_STATE connect;

    USBH_initialise(NULL);

    while (1)
    {
        USBH_get_connect_state(USBH_ROOT_HUB_HANDLE, USBH_ROOT_HUB_PORT, &connect);
        if (connect == USBH_STATE_NOTCONNECTED)
        {
            printf("\r\nPlease plug in a USB Device\r\n");

            // Detect usb device connect
            do
            {
                status = USBH_process();
                USBH_get_connect_state(USBH_ROOT_HUB_HANDLE, USBH_ROOT_HUB_PORT, &connect);
            } while (connect == USBH_STATE_NOTCONNECTED);
        }
        printf("\r\nUSB Device Detected\r\n");

        do{
            status = USBH_process();
            USBH_get_connect_state(USBH_ROOT_HUB_HANDLE, USBH_ROOT_HUB_PORT, &connect);
        } while (connect < USBH_STATE_ENUMERATED);

        if (connect == USBH_STATE_ENUMERATED)
        {
            printf("USB Devices Enumerated\r\n");
        }
        else
        {
            printf("USB Devices Partially Enumerated\r\n");
        }

        // Get the first device (device on root hub)
        status = USBH_get_device_list(USBH_ROOT_HUB_HANDLE, &hRootDev);
        if (status != USBH_OK)
        {
            // Report the error code.
            printf("%d\r\n", status);
        }
        else
        {
            // Perform the actual testing.
            status = hub_scan_for_hid(hRootDev, 1);
        }

        if ((status != USBH_ERR_REMOVED) && (status != USBH_ERR_TIMEOUT))
        {
            if(status == USBH_ERR_NOT_FOUND)
            {
                printf("HID device isn't found!\r\n");
            }
            printf("\r\nPlease remove the connected USB Device\r\n");
        }
        // Detect usb device disconnect
        do
        {
            status = USBH_process();
            USBH_get_connect_state(USBH_ROOT_HUB_HANDLE, USBH_ROOT_HUB_PORT, &connect);
        } while (connect != USBH_STATE_NOTCONNECTED);
    }

    return 0;
}

/* FUNCTIONS ***********************************************************************/

int main(void)
{
    /* Check for a USB device connection and initiate a DFU firmware download or
       upload operation. This will timeout and return control here if no host PC
       program contacts the device's DFU interface. USB device mode is disabled
       before returning.
    */
    STARTUP_DFU();

    /* Enable the UART Device... */
    sys_enable(sys_device_uart0);

    /* Make GPIO48 function as UART0_TXD and GPIO49 function as UART0_RXD... */
    gpio_function(48, pad_uart0_txd); /* UART0 TXD */
    gpio_function(49, pad_uart0_rxd); /* UART0 RXD */
    uart_open(UART0,                    /* Device */
              1,                        /* Prescaler = 1 */
              UART_DIVIDER_19200_BAUD,  /* Divider = 1302 */
              uart_data_bits_8,         /* No. Data Bits */
              uart_parity_none,         /* Parity */
              uart_stop_bits_1);        /* No. Stop Bits */

    /* Print out a welcome message... */
    uart_puts(UART0,
        "\x1B[2J" /* ANSI/VT100 - Clear the Screen */
        "\x1B[H"  /* ANSI/VT100 - Move Cursor to Home */
        );

    sys_enable(sys_device_timer_wdt);

    interrupt_attach(interrupt_timers, (int8_t)interrupt_timers, ISR_timer);
    interrupt_enable_globally();

    /* Timer A = 1ms */
    timer_prescaler(timer_select_a, 1000);
    timer_init(timer_select_a, 100, timer_direction_down, timer_prescaler_select_on, timer_mode_continuous);
    timer_enable_interrupt(timer_select_a);
    timer_start(timer_select_a);

    printf("Copyright (C) Bridgetek Pte Ltd \r\n"
        "--------------------------------------------------------------------- \r\n"
        "Welcome to USBH HID Tester Example 2... \r\n"
        "\r\n"
        "Find and displays reports received from HID keyboard devices connected to \r\n"
        "the USB Host Port.\r\n\n"
        "\'Timeout\' can be displayed when the connected HID device does not \r\n"
        "respond to the host requests; it does not indicate an error! Try to move\r\n"
        "the HID mouse or press any key on the HID keyboard to generate HID reports.\r\n"
    	"HID reports from keyboards and barcode scanners will be converted to ASCII."
        "--------------------------------------------------------------------- \r\n"
        );

    uart_disable_interrupt(UART0, uart_interrupt_tx);
    uart_disable_interrupt(UART0, uart_interrupt_rx);

    usbh_testing();

    interrupt_detach(interrupt_timers);
    interrupt_disable_globally();
    sys_disable(sys_device_timer_wdt);

    // Wait forever...
    for (;;);

    return 0;

}
