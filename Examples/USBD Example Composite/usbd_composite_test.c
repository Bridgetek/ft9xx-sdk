/**
  @file usbd_composite_test.c
  @brief
  USB MIDI and Keyboard HID Device Test

  This example program will implement a midi and keyboard on the USB.
 */
/*
 * ============================================================================
 * History
 * =======
 * GDM Dec 2021 : Created
 *
 * (C) Copyright, Bridgetek Pte Ltd
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
#include <string.h>
#include <ctype.h>

#include <ft900.h>
#include <ft900_usb.h>
#include <ft900_usb_audio.h>
#include <ft900_usb_hid.h>
#include <ft900_usb_dfu.h>
#include <ft900_usbd_dfu.h>
#include <ft900_usbdx.h>

/* For MikroC const qualifier will place variables in Flash
 * not just make them constant.
 */
#if defined(__GNUC__)
#define DESCRIPTOR_QUALIFIER const
#elif defined(__MIKROC_PRO_FOR_FT90x__)
#define DESCRIPTOR_QUALIFIER data
#endif

/* CONSTANTS ***********************************************************************/

/**
 @name USB and Hub Configuration
 @brief Indication of how the USB device is powered and the size of
 	 the control endpoint Max Packets.
 */
//@{
// USB Bus Powered - set to 1 for self-powered or 0 for bus-powered
#ifndef USB_SELF_POWERED
#define USB_SELF_POWERED 0
#endif // USB_SELF_POWERED
#if USB_SELF_POWERED == 1
#define USB_CONFIG_BMATTRIBUTES_VALUE (USB_CONFIG_BMATTRIBUTES_SELF_POWERED | USB_CONFIG_BMATTRIBUTES_RESERVED_SET_TO_1)
#else // USB_SELF_POWERED
#define USB_CONFIG_BMATTRIBUTES_VALUE USB_CONFIG_BMATTRIBUTES_RESERVED_SET_TO_1
#endif // USB_SELF_POWERED
// USB Endpoint Zero packet size (both must match)
#define USB_CONTROL_EP_MAX_PACKET_SIZE 64
#define USB_CONTROL_EP_SIZE USBD_EP_SIZE_64
//@}

/**
 @name Device Configuration Areas
 @brief Size and location reserved for string descriptors.
 Leaving the allocation size blank will make an array exactly the size
 of the string allocation.
 Note: Specifying the location is not supported by the GCC compiler.
 */
//@{
// String descriptors - allow a maximum of 256 bytes for this
#define STRING_DESCRIPTOR_LOCATION 0x80
#define STRING_DESCRIPTOR_ALLOCATION 0x100
//@}

/**
   @name Disable DFU function
   @brief Disable the DFU interface in this application.
   	   Normally enabled.
*/
#undef DISABLE_DFU

/**
 @name DFU Configuration
 @brief Determines the parts of the DFU specification which are supported
        by the DFU library code. Features can be disabled if required.
 */
//@{
#define DFU_ATTRIBUTES USBD_DFU_ATTRIBUTES
//@}

/**
 @name DFU_TRANSFER_SIZE definition.
 @brief Number of bytes in block, sent in each DFU_DNLOAD request
 from the DFU update program on the host. This is simplified
 in that the meaning of a block is an arbitrary number of
 bytes. This is intentionally a multiple of the maximum
 packet size for the control endpoints.
 It is used in the DFU functional descriptor as wTransferSize.
 The maximum size supported by the DFU library is 256 bytes
 which is the size of a page of Flash.
 */
//@{
#define DFU_TRANSFER_SIZE USBD_DFU_MAX_BLOCK_SIZE
#define DFU_TIMEOUT USBD_DFU_TIMEOUT
//@}

/**
 @name USB_PID_MIDIKBD configuration.
 @brief Run Time Product ID for CDC function.
 */
//@{
#define USB_PID_MIDIKBD 0x0fd3
//@}

/**
 @name WCID_VENDOR_REQUEST_CODE for WCID.
 @brief Unique vendor request code for WCID OS Vendor Extension validation.
*/
//@{
#define WCID_VENDOR_REQUEST_CODE	 0x4A   /*same WCID code as that of B-DFU */
//@}

/**
    @name Microsoft WCID Information
    @brief Definitions for WCID String Descriptors and vendor requests.
 **/
//@{
#define USB_MICROSOFT_WCID_VERSION 				 0x0100

#define USB_MICROSOFT_WCID_STRING_DESCRIPTOR	 0xEE
#define USB_MICROSOFT_WCID_STRING_LENGTH		 0x12
#define USB_MICROSOFT_WCID_STRING_SIGNATURE		 'M', 0x00, 'S', 0x00, \
	'F', 0x00, 'T', 0x00, '1', 0x00, '0', 0x00, '0', 0x00,

#define USB_MICROSOFT_WCID_STRING(A) \
		USB_MICROSOFT_WCID_STRING_LENGTH, \
		USB_DESCRIPTOR_TYPE_STRING, USB_MICROSOFT_WCID_STRING_SIGNATURE \
		A, 0x00,

#define USB_MICROSOFT_WCID_FEATURE_WINDEX_COMPAT_ID	 0x0004
//@}

/**
 @brief Endpoint definitions for MIDI interface.
 */
//@{
#define MIDI_INTERFACE                 	(0) /// First interface.
#define MIDI_INTERFACE_STREAMING       	(MIDI_INTERFACE + 1) /// First interface.
#define MIDI_EP_DATA_IN 				USBD_EP_1
#define MIDI_EP_DATA_OUT 				USBD_EP_2
#define MIDI_DATA_EP_SIZE				512
#define MIDI_DATA_USBD_EP_SIZE 			USBD_EP_SIZE_512
//@}
/**
 @brief Endpoint definitions for Keyboard interface.
 */
//@{
#define KBD_INTERFACE					(MIDI_INTERFACE_STREAMING + 1) /// Interface follows MIDI interface.
#define KBD_EP_NOTIFICATION				USBD_EP_3
#define KBD_NOTIFICATION_EP_SIZE 		0x8
#define KBD_NOTIFICATION_USBD_EP_SIZE 	USBD_EP_SIZE_8
//@}

/**
 @name DFU_USB_INTERFACE configuration..
 @brief Run Time and DFU Mode Interface Numbers.
 */
//@{
#define DFU_USB_INTERFACE_RUNTIME (KBD_INTERFACE + 1) /// Interface follows Keyboard when enabled.
#define DFU_USB_INTERFACE_DFUMODE 0 /// Interface is the one and only interface in DFU mode.
//@}

/**
 @brief USBD Pipe URB Counts.
 */
//@{
/// There is only ever one concurrent keyboard report sent.
#define URB_KBD_COUNT	1
/// Allow 2 concurrent MIDI packets to be piped.
#define URB_MIDI_DATA_IN_COUNT	2
#define URB_MIDI_DATA_OUT_COUNT	2
//@}

/** @brief String to 'type' on the host.
 *
 *  @details The string is translated in key scan codes, effectively looking like a
 *   key press to the host. The ASCII characters in the string are translated into
 *   scan codes using a look-up table.
 *   There is the capability of sending control keys (e.g. page up, function keys,
 *   delete, insert, caps lock etc) using an arbitrary escape character. In this app
 *   the character is a backslash. The next letter after this is decoded from the
 *   control scan code table rather than the ASCII scan code table. So, "\\C" will
 *   send a caps lock. This escape character can be changed in the main function.
 *   \r or \x0d is carriage return.
 *   \x08 is backspace
 *   \x1b is escape
 *   \x09 is horizontal tab
 *   \\C, \\S, \\N are caps lock, scroll lock and num lock
 *   \\r, \\l, \\d, \\u are right, left, up, down arrows
 *   \\H, \\E, \\U, \\D are home, end, page up and page down
 *   \\X is delete
 *   \\I is insert
 */
#if defined(__FT930__)
const char tty_message[] =
		"Hello, I am a \\Cft930\\C device... nice to meet you!\r";
#else
const char tty_message[] =
		"Hello, I am a \\Cft900\\C device... nice to meet you!\r";
#endif

/** @brief Tune to play to host.
 */
#define NOTE_LEN_SEMIBREVE 16
#define NOTE_LEN_MINIM 8
#define NOTE_LEN_CROTCHET_DOT 6
#define NOTE_LEN_CROTCHET 4
#define NOTE_LEN_QUAVER 2
#define NOTE_LEN_SEMIQUAVER 1

#define NOTE_D5 74
#define NOTE_CS5 73
#define NOTE_C5 72
#define NOTE_B4 71
#define NOTE_AS4 70
#define NOTE_A4 69
#define NOTE_GS4 68
#define NOTE_G4 67
#define NOTE_FS4 66
#define NOTE_F4 65
#define NOTE_E4 64
#define NOTE_DS4 63
#define NOTE_D4 62
#define NOTE_CS4 61
#define NOTE_C4 60

const uint8_t midi_tune[] =
{
		NOTE_B4, NOTE_LEN_CROTCHET,
		NOTE_B4, NOTE_LEN_CROTCHET,
		NOTE_C5, NOTE_LEN_CROTCHET,
		NOTE_D5, NOTE_LEN_CROTCHET,

		NOTE_D5, NOTE_LEN_CROTCHET,
		NOTE_C5, NOTE_LEN_CROTCHET,
		NOTE_B4, NOTE_LEN_CROTCHET,
		NOTE_A4, NOTE_LEN_CROTCHET,

		NOTE_G4, NOTE_LEN_CROTCHET,
		NOTE_G4, NOTE_LEN_CROTCHET,
		NOTE_A4, NOTE_LEN_CROTCHET,
		NOTE_B4, NOTE_LEN_CROTCHET,

		NOTE_B4, NOTE_LEN_CROTCHET_DOT,
		NOTE_A4, NOTE_LEN_QUAVER,
		NOTE_A4, NOTE_LEN_MINIM,

		NOTE_B4, NOTE_LEN_CROTCHET,
		NOTE_B4, NOTE_LEN_CROTCHET,
		NOTE_C5, NOTE_LEN_CROTCHET,
		NOTE_D5, NOTE_LEN_CROTCHET,

		NOTE_D5, NOTE_LEN_CROTCHET,
		NOTE_C5, NOTE_LEN_CROTCHET,
		NOTE_B4, NOTE_LEN_CROTCHET,
		NOTE_A4, NOTE_LEN_CROTCHET,

		NOTE_G4, NOTE_LEN_CROTCHET,
		NOTE_G4, NOTE_LEN_CROTCHET,
		NOTE_A4, NOTE_LEN_CROTCHET,
		NOTE_B4, NOTE_LEN_CROTCHET,

		NOTE_A4, NOTE_LEN_CROTCHET_DOT,
		NOTE_G4, NOTE_LEN_QUAVER,
		NOTE_G4, NOTE_LEN_MINIM,

		0, 0 // end
};

/**
 @name MIDI Emulation Constants
 @brief Sizes and timeouts for MIDI operation.
 */
//@{
/// Enable or disable demo tune sent to host.
#define MIDI_DEVICE_ENABLE
/// Echo MIDI notes sent to host on the UART.
#define MIDI_DEVICE_DEBUG_ON
/// Number of bytes in a MIDI streaming message.
#define MIDI_PACKET_SIZE sizeof(usb_audioMidiEventPacket)
/// Size of data packet sent to host for each MIDI note.
#define MIDI_DATA_IN_PACKET_SIZE MIDI_PACKET_SIZE
/// Size of data packet sent to use by host for each MIDI note.
#define MIDI_DATA_OUT_PACKET_SIZE MIDI_PACKET_SIZE
/// Time between SetIdle and commencing sending of notes (in ms).
#define MIDI_STARTUP_TIME 1000 // 1 seconds
/// Length of time between notes in ms based on a semiquaver.
#define MIDI_PERIOD 100
//@}

/**
 @name Keyboard Emulation Constants
 @brief States and timeouts for keyboard operation.
 */
//@{
/// Enable or disable demo string sent to host.
/// This can be quite annoying as it types to the window with the focus and
/// can disturb what you are working on. I keep it turned off.
#undef KDB_DEVICE_ENABLE
/// Echo keypresses sent to host on the UART.
#define KDB_DEVICE_DEBUG_ON
/// Key press state machine definitions.
#define KBD_STATE_ON      1
#define KBD_STATE_OFF     2
/// Time between SetIdle and commencing sending of keypresses (in ms).
#define KBD_STARTUP_TIME 2000 // 2 seconds
/// Length of time between key presses in a word (in ms).
#define KBD_OFF_PERIOD 50
/// Length of time between key presses between words (in ms).
#define KBD_OFF_PERIOD_LONG 300
/// How long to press key for (in ms).
#define KBD_ON_PERIOD    10
//@}

/* GLOBAL VARIABLES ****************************************************************/

/* LOCAL VARIABLES *****************************************************************/

/**
 @name usb_composite_device_interface_guid
 @brief Device Interface GUID for DFU interface in runtime.
 This property is returned by the device when asked by Windows. It will instruct
 Windows to start the WinUSB driver for the DFU interface enabling programs to
 access the DFU code.
 */
/* Referred:
 * https://github.com/pbatard/libwdi/wiki/WCID-Devices
 */
static const struct PACK USB_WCID_extended_property_descriptor usb_composite_device_interface_guid =
{
	sizeof(struct USB_WCID_extended_property_descriptor), /* dwLength */
	USB_MICROSOFT_WCID_VERSION, /* bcdVersion */
	USB_MICROSOFT_WCID_FEATURE_WINDEX_DEVICE_GUID, /* wIndex */
	1, /* wCount */
	136, /* dwSize */
	USB_MS_WCID_PROPERTY_DATATYPE_STRING_MULTI, /* dwPropertyDataType */
	42, /* wPropertyNameLength */
	{'D', 0x00, 'e', 0x00, 'v', 0x00, 'i', 0x00, 'c', 0x00, 'e', 0x00,
			'I', 0x00, 'n', 0x00, 't', 0x00, 'e', 0x00, 'r', 0x00, 'f', 0x00, 'a', 0x00, 'c', 0x00, 'e', 0x00,
			'G', 0x00, 'U', 0x00, 'I', 0x00, 'D', 0x00, 's', 0x00, 0x00, 0x00 }, /* null terminated PropertyName */
	80, /* dwPropertyDataLength */
	/* Property Value -> {E7DEB67E-C172-430F-8B54-3D1DCD25FBD8} */
	{0x7b, 0x00, 0x45, 0x00, 0x37, 0x00, 0x44, 0x00, 0x45, 0x00, 0x42, 0x00,
			0x36, 0x00, 0x37, 0x00, 0x45, 0x00, 0x2d, 0x00, 0x43, 0x00, 0x31, 0x00,
			0x37, 0x00, 0x32, 0x00, 0x2d, 0x00, 0x34, 0x00, 0x33, 0x00, 0x30, 0x00,
			0x46, 0x00, 0x2d, 0x00, 0x38, 0x00, 0x42, 0x00, 0x35, 0x00, 0x34, 0x00,
			0x2d, 0x00, 0x33, 0x00, 0x44, 0x00, 0x31, 0x00, 0x44, 0x00, 0x43, 0x00,
			0x44, 0x00, 0x32, 0x00, 0x35, 0x00, 0x46, 0x00, 0x42, 0x00, 0x44, 0x00,
			0x38, 0x00, 0x7d, 0x00,
	 0x00, 0x00, 0x00, 0x00}, /* bPropertyData */
};

/**
 @name string_descriptor
 @brief Table of USB String descriptors

 This is placed at a fixed location in the const section allowing
 up-to 256 bytes of string descriptors to be defined. These can be
 modified or replaced by a utility or binary editor without
 requiring a recompilation of the firmware.
 They are placed at offset 0x100 and reserve 0x100 bytes.
 The data is not stored in section and is therefore
 regarded as const.
 */
DESCRIPTOR_QUALIFIER /*__at(STRING_DESCRIPTOR_LOCATION)*/ uint8_t string_descriptor[STRING_DESCRIPTOR_ALLOCATION] =
{
		// String 0 is actually a list of language IDs supported by the real strings.
		0x04, USB_DESCRIPTOR_TYPE_STRING, 0x09,
		0x04, // 0409 = English (US)


		// String 1 (Manufacturer): "FTDI"
		0x0a, USB_DESCRIPTOR_TYPE_STRING, 'F', 0x00, 'T', 0x00, 'D', 0x00, 'I',
		0x00,
#if defined(__FT930__)
		// String 2 (Product): "FT930 MidiKbd"
		0x1C, USB_DESCRIPTOR_TYPE_STRING, 'F', 0x00, 'T', 0x00, '9', 0x00, '3',
		0x00, '0', 0x00, ' ', 0x00, 'M', 0x00, 'i', 0x00, 'd', 0x00, 'i', 0x00,
		'K', 0x00, 'b', 0x00, 'd', 0x00,
#else
		// String 2 (Product): "FT900 MidiKbd"
		0x1C, USB_DESCRIPTOR_TYPE_STRING, 'F', 0x00, 'T', 0x00, '9', 0x00, '0',
		0x00, '0', 0x00, ' ', 0x00, 'M', 0x00, 'i', 0x00, 'd', 0x00, 'i', 0x00,
		'K', 0x00, 'b', 0x00, 'd', 0x00,
#endif

		// String 3 (Serial Number): "FT424242"
		0x12, USB_DESCRIPTOR_TYPE_STRING, 'F', 0x00, 'T', 0x00, '4', 0x00, '2',
		0x00, '4', 0x00, '2', 0x00, '4', 0x00, '2', 0x00,

#if defined(__FT930__)
			// String 4 (DFU Product Name): "FT930 DFU Mode"
			0x1E, USB_DESCRIPTOR_TYPE_STRING, 'F', 0x00, 'T', 0x00, '9', 0x00, '3',
			0x00, '0', 0x00, ' ', 0x00, 'D', 0x00, 'F', 0x00, 'U', 0x00, ' ', 0x00,
			'M', 0x00, 'o', 0x00, 'd', 0x00, 'e', 0x00,
#else
		// String 4 (DFU Product Name): "FT900 DFU Mode"
		0x1E, USB_DESCRIPTOR_TYPE_STRING, 'F', 0x00, 'T', 0x00, '9', 0x00, '0',
		0x00, '0', 0x00, ' ', 0x00, 'D', 0x00, 'F', 0x00, 'U', 0x00, ' ', 0x00,
		'M', 0x00, 'o', 0x00, 'd', 0x00, 'e', 0x00,
#endif

		// String 5 (Interface Name): "DFU Interface"
		0x1c, USB_DESCRIPTOR_TYPE_STRING, 'D', 0x00, 'F', 0x00, 'U', 0x00, ' ',
		0x00, 'I', 0x00, 'n', 0x00, 't', 0x00, 'e', 0x00, 'r', 0x00, 'f', 0x00,
		'a', 0x00, 'c', 0x00, 'e', 0x00,

		// END OF STRINGS
		0x00
};

/**
 @name wcid_string_descriptor
 @brief USB String descriptor for WCID identification.
 */
DESCRIPTOR_QUALIFIER uint8_t wcid_string_descriptor[USB_MICROSOFT_WCID_STRING_LENGTH] = {
		USB_MICROSOFT_WCID_STRING(WCID_VENDOR_REQUEST_CODE)
};

/**
 @name config_descriptor_composite
 @brief Configuration descriptor for this device when in Run Time mode.
 */
//@{
struct PACK config_descriptor_composite
{
	USB_configuration_descriptor configuration;

	usb_audioControlInterfaceDescriptor_t interface_ac_midi;
	usb_audioControlInterfaceHeaderDescriptor_t(1) hdr_ac_midi;

	usb_audioStreamingStandardInterfaceDescriptor_t interface_ms_midi;
	usb_audioMidiStreamingInterfaceHeaderDescriptor_t hdr_ms_midi;
	usb_audioMidiJackInDescriptor_t jack_in_emb;
	usb_audioMidiJackInDescriptor_t jack_in_ext;
	usb_audioMidiOutJackDescriptor_t(1) jack_out_emb;
	usb_audioMidiOutJackDescriptor_t(1) jack_out_ext;
	usb_audioStreamingDataStandardEndpointDescriptor_t midi_data_out;
	usb_audioMidiStreamingBulkEpDescriptor_t(1) midistreaming_data_out;
	usb_audioStreamingDataStandardEndpointDescriptor_t midi_data_in;
	usb_audioMidiStreamingBulkEpDescriptor_t(1) midistreaming_data_in;

	USB_interface_descriptor hid_interface;
	USB_hid_descriptor hid;
	USB_endpoint_descriptor endpoint_hid;

	USB_interface_descriptor dfu_interface;
	USB_dfu_functional_descriptor dfu_functional;
};

// Fields marked with * are updated with information in device_config[]
DESCRIPTOR_QUALIFIER struct config_descriptor_composite config_descriptor_composite =
{
	{
		sizeof(USB_configuration_descriptor), /* configuration.bLength */
		USB_DESCRIPTOR_TYPE_CONFIGURATION, /* configuration.bDescriptorType */
		sizeof(struct config_descriptor_composite), /* configuration.wTotalLength */
#ifndef DISABLE_DFU
		DFU_USB_INTERFACE_RUNTIME + 1, /* configuration.bNumInterfaces */
#else
		KBD_INTERFACE + 1, /* configuration.bNumInterfaces */
#endif
		0x01, /* configuration.bConfigurationValue */
		0x00, /* configuration.iConfiguration */
		USB_CONFIG_BMATTRIBUTES_VALUE, /* configuration.bmAttributes */
		0xFA /* configuration.bMaxPower */           // 500mA
	},

	// ---- INTERFACE DESCRIPTOR for MIDI Control ----

	{
		sizeof(usb_audioControlInterfaceDescriptor_t), /* interface_ac_midi.bLength */
		USB_DESCRIPTOR_TYPE_INTERFACE, /* interface_ac_midi.bDescriptorType */
		MIDI_INTERFACE, /* interface_ac_midi.bInterfaceNumber */
		0, /* interface_ac_midi.bAlternateSetting */
		0, /* interface_ac_midi.bNumEndpoints */
		USB_CLASS_AUDIO, /* interface_ac_midi.bInterfaceClass */
		USB_SUBCLASS_AUDIO_AUDIOCONTROL, /* interface_ac_midi.bInterfaceSubClass */
		USB_PROTOCOL_AUDIO_UNDEFINED, /* interface_ac_midi.bInterfaceSubClass */
		0 /* interface_ac_midi.iInterface */
	},


	{
		sizeof(usb_audioControlInterfaceHeaderDescriptor_t(1)), /* hdr_ac_midi.bLength */
		USB_DESCRIPTOR_TYPE_AUDIO_INTERFACE, /* hdr_ac_midi.bDescriptorType */
		USB_DESCRIPTOR_SUBTYPE_MIDI_MS_HEADER, /* hdr_ac_midi.bDescriptorSubtype */
		0x0100, /* hdr_ac_midi.bcdADC */
		sizeof(usb_audioControlInterfaceHeaderDescriptor_t(1)), /* hdr_ac_midi.wTotalLength */
		1, /* hdr_ac_midi.bInCollection */
		{
				MIDI_INTERFACE_STREAMING, /* hdr_ac_midi.baInterfaceNr */
		}
	},

	// ---- INTERFACE DESCRIPTOR for MIDI Streaming ----

	{
		sizeof(usb_audioStreamingStandardInterfaceDescriptor_t), /* interface_ms_midi.bLength */
		USB_DESCRIPTOR_TYPE_INTERFACE, /* interface_ms_midi.bDescriptorType */
		MIDI_INTERFACE_STREAMING, /* interface_ms_midi.bInterfaceNumber */
		0x00, /* interface_ms_midi.bAlternateSetting */
		0x02, /* interface_ms_midi.bNumEndpoints */
		USB_CLASS_AUDIO, /* interface_ms_midi.bInterfaceClass */
		USB_SUBCLASS_AUDIO_MIDISTREAMING, /* interface_ms_midi.bInterfaceSubClass */
		USB_PROTOCOL_AUDIO_UNDEFINED, /* interface_ms_midi.bInterfaceProtocol */
		0x00 /* interface_ms_midi.iInterface */ // Unused
	},


	{
		sizeof(usb_audioMidiStreamingInterfaceHeaderDescriptor_t), /* hdr_ms_midi.bLength */
		USB_DESCRIPTOR_TYPE_AUDIO_INTERFACE, /* hdr_ms_midi.bDescriptorType */
		USB_DESCRIPTOR_SUBTYPE_MIDI_MS_HEADER, /* hdr_ms_midi.bDescriptorSubtype */
		0x0100, /* hdr_ms_midi.bcdADC */
		sizeof(usb_audioMidiStreamingInterfaceHeaderDescriptor_t) +
		(sizeof(usb_audioMidiJackInDescriptor_t) * 2) +
		(sizeof(usb_audioMidiOutJackDescriptor_t(1)) * 2),// +
		//(sizeof(usb_audioStreamingDataStandardEndpointDescriptor_t) + sizeof(usb_audioMidiStreamingBulkEpDescriptor_t(1)) * 2) /* hdr_ms_midi.wTotalLength */
	},

	{
		sizeof(usb_audioMidiJackInDescriptor_t), /* jack_in_emb.bLength */
		USB_DESCRIPTOR_TYPE_AUDIO_INTERFACE, /* jack_in_emb.bDescriptorType */
		USB_DESCRIPTOR_SUBTYPE_MIDI_IN_JACK, /* jack_in_emb.bDescriptorSubtype */
		USB_AUDIO_MIDI_JACK_TYPE_EMBEDDED, /* jack_in_emb.bJackType */
		1, /* jack_in_emb.bJackID */
		0 /* jack_in_emb.iJack */
	},

	{
		sizeof(usb_audioMidiJackInDescriptor_t), /* jack_in_ext.bLength */
		USB_DESCRIPTOR_TYPE_AUDIO_INTERFACE, /* jack_in_ext.bDescriptorType */
		USB_DESCRIPTOR_SUBTYPE_MIDI_IN_JACK, /* jack_in_ext.bDescriptorSubtype */
		USB_AUDIO_MIDI_JACK_TYPE_EXTERNAL, /* jack_in_ext.bJackType */
		2, /* jack_in_ext.bJackID */
		0 /* jack_in_ext.iJack */
	},

	{
		sizeof(usb_audioMidiOutJackDescriptor_t(1)), /* jack_out_emb.bLength */
		USB_DESCRIPTOR_TYPE_AUDIO_INTERFACE, /* jack_out_emb.bDescriptorType */
		USB_DESCRIPTOR_SUBTYPE_MIDI_OUT_JACK, /* jack_out_emb.bDescriptorSubtype */
		USB_AUDIO_MIDI_JACK_TYPE_EMBEDDED, /* jack_out_emb.bJackType */
		3, /* jack_out_emb.bJackID */
		1, /* jack_out_emb.bNrInputPins */
		{
			{
				2, /* jack_out_emb.BaSource.ID */
				1, /* jack_out_emb.BaSource.Pin */
			},
    	},
		0 /* jack_out_emb.iJack */
	},

	{
		sizeof(usb_audioMidiOutJackDescriptor_t(1)), /* jack_out_ext.bLength */
		USB_DESCRIPTOR_TYPE_AUDIO_INTERFACE, /* jack_out_ext.bDescriptorType */
		USB_DESCRIPTOR_SUBTYPE_MIDI_OUT_JACK, /* jack_out_ext.bDescriptorSubtype */
		USB_AUDIO_MIDI_JACK_TYPE_EXTERNAL, /* jack_out_ext.bJackType */
		4, /* jack_out_ext.bJackID */
		1, /* jack_out_ext.bNrInputPins */
		{
			{
				1, /* jack_out_ext.BaSource.ID */
				1, /* jack_out_ext.BaSource.Pin */
			},
    	},
		0 /* jack_out_ext.iJack */
	},

	{
		sizeof(usb_audioStreamingDataStandardEndpointDescriptor_t), /* midi_data_out.bLength */
		USB_DESCRIPTOR_TYPE_ENDPOINT, /* midi_data_out.bDescriptorType */
		USB_ENDPOINT_DESCRIPTOR_EPADDR_OUT | MIDI_EP_DATA_OUT, /* midi_data_out.bEndpointAddress */
		USB_ENDPOINT_DESCRIPTOR_ATTR_BULK, /* midi_data_out.bmAttributes */
		MIDI_DATA_EP_SIZE, /* midi_data_out.wMaxPacketSize */
		0x00 /* midi_data_out.bInterval */
	},

	{
		sizeof(usb_audioMidiStreamingBulkEpDescriptor_t(1)), /* midistreaming_data_out.bLength */
		USB_DESCRIPTOR_TYPE_AUDIO_ENDPOINT, /* midistreaming_data_out.bDescriptorType */
		USB_ENDPOINT_DESCRIPTOR_MIDI_CS_MS_GENERAL, /* midistreaming_data_out.bDescriptorSubtype */
		1, /* midistreaming_data_out.bNumEmbMIDIJack */
		{
			1 /* midistreaming_data_out.BaAssocJackID */
		},
	},

	{
		sizeof(usb_audioStreamingDataStandardEndpointDescriptor_t), /* midi_data_in.bLength */
		USB_DESCRIPTOR_TYPE_ENDPOINT, /* midi_data_in.bDescriptorType */
		USB_ENDPOINT_DESCRIPTOR_EPADDR_IN | MIDI_EP_DATA_IN, /* midi_data_in.bEndpointAddress */
		USB_ENDPOINT_DESCRIPTOR_ATTR_BULK, /* midi_data_in.bmAttributes */
		MIDI_DATA_EP_SIZE, /* midi_data_in.wMaxPacketSize */
		0x00 /* midi_data_in.bInterval */
	},

	{
		sizeof(usb_audioMidiStreamingBulkEpDescriptor_t(1)), /* midistreaming_data_out.bLength */
		USB_DESCRIPTOR_TYPE_AUDIO_ENDPOINT, /* midistreaming_data_out.bDescriptorType */
		USB_ENDPOINT_DESCRIPTOR_MIDI_CS_MS_GENERAL, /* midistreaming_data_out.bDescriptorSubtype */
		1, /* midistreaming_data_out.bNumEmbMIDIJack */
		{
			3 /* midistreaming_data_out.BaAssocJackID */
		},
	},

	// ---- INTERFACE DESCRIPTOR for Keyboard ----

	{
		sizeof(USB_interface_descriptor), /* interface.bLength */
		USB_DESCRIPTOR_TYPE_INTERFACE, /* interface.bDescriptorType */
		KBD_INTERFACE, /* interface.bInterfaceNumber */
		0x00, /* interface.bAlternateSetting */
		0x01, /* interface.bNumEndpoints */
		USB_CLASS_HID, /* interface.bInterfaceClass */ // HID Class
		USB_SUBCLASS_HID_BOOT_INTERFACE, /* interface.bInterfaceSubClass */ // Boot Protocol
		USB_PROTOCOL_HID_KEYBOARD, /* interface.bInterfaceProtocol */ // Keyboard
		0x02 /* interface.iInterface */               // "FT900 Keyboard"
	},

	{
		// ---- HID DESCRIPTOR for Keyboard ----
		sizeof(USB_hid_descriptor), /* hid.bLength */
		USB_DESCRIPTOR_TYPE_HID, /* hid.bDescriptorType */
		USB_BCD_VERSION_HID_1_1, /* hid.bcdHID */
		USB_HID_LANG_NOT_SUPPORTED, /* hid.bCountryCode */
		0x01, /* hid.bNumDescriptors */
		USB_DESCRIPTOR_TYPE_REPORT, /* hid.bDescriptorType_0 */
		0x0041 /* hid.wDescriptorLength_0 */
	},

	{
		// ---- ENDPOINT DESCRIPTOR for Keyboard ----
		sizeof(USB_endpoint_descriptor), /* endpoint.bLength */
		USB_DESCRIPTOR_TYPE_ENDPOINT, /* endpoint.bDescriptorType */
		USB_ENDPOINT_DESCRIPTOR_EPADDR_IN | KBD_EP_NOTIFICATION, /* endpoint.bEndpointAddress */
		USB_ENDPOINT_DESCRIPTOR_ATTR_INTERRUPT, /* endpoint.bmAttributes */
		KBD_NOTIFICATION_EP_SIZE, /* endpoint.wMaxPacketSize */
		0x0a /* endpoint.bInterval */
	},

#ifndef DISABLE_DFU
	// ---- INTERFACE DESCRIPTOR for DFU Interface ----
	{
		sizeof(USB_interface_descriptor), /* dfu_interface.bLength */
		USB_DESCRIPTOR_TYPE_INTERFACE, /* dfu_interface.bDescriptorType */
		DFU_USB_INTERFACE_RUNTIME, /* dfu_interface.bInterfaceNumber */
		0x00, /* dfu_interface.bAlternateSetting */
		0x00, /* dfu_interface.bNumEndpoints */
		USB_CLASS_APPLICATION, /* dfu_interface.bInterfaceClass */ // bInterfaceClass: Application Specific Class
		USB_SUBCLASS_DFU, /* dfu_interface.bInterfaceSubClass */ // bInterfaceSubClass: Device Firmware Update
		USB_PROTOCOL_DFU_RUNTIME, /* dfu_interface.bInterfaceProtocol */ // bInterfaceProtocol: Runtime Protocol
		0x05 /* dfu_interface.iInterface */       // * iInterface: "DFU Interface"
	},

	// ---- FUNCTIONAL DESCRIPTOR for DFU Interface ----
	{
		sizeof(USB_dfu_functional_descriptor), /* dfu_functional.bLength */
		USB_DESCRIPTOR_TYPE_DFU_FUNCTIONAL, /* dfu_functional.bDescriptorType */
		DFU_ATTRIBUTES, /* dfu_functional.bmAttributes */  	// bmAttributes
		DFU_TIMEOUT, /* dfu_functional.wDetatchTimeOut */ // wDetatchTimeOut
		DFU_TRANSFER_SIZE, /* dfu_functional.wTransferSize */     // wTransferSize
		USB_BCD_VERSION_DFU_1_1 /* dfu_functional.bcdDfuVersion */ // bcdDfuVersion: DFU Version 1.1
	}
#endif // DISABLE_DFU
};
//@}

/**
 @name device_descriptor_midikbd
 @brief Device descriptor for Run Time mode.
 */
DESCRIPTOR_QUALIFIER USB_device_descriptor device_descriptor_midikbd =
{
		0x12, /* bLength */
		USB_DESCRIPTOR_TYPE_DEVICE, /* bDescriptorType */
		USB_BCD_VERSION_2_0, /* bcdUSB */          // V2.0
		USB_CLASS_DEVICE, /* bDeviceClass */       // Defined in interface
		USB_SUBCLASS_DEVICE, /* bDeviceSubClass */ // Defined in interface
		USB_PROTOCOL_DEVICE, /* bDeviceProtocol */ // Defined in interface
		USB_CONTROL_EP_MAX_PACKET_SIZE, /* bMaxPacketSize0 */
		USB_VID_FTDI, /* idVendor */   // idVendor: 0x0403 (FTDI)
		USB_PID_MIDIKBD, /* idProduct */ // idProduct: 0x0fe3
		0x0101, /* bcdDevice */        // 1.1
		0x01, /* iManufacturer */      // Manufacturer
		0x02, /* iProduct */           // Product
		0x03, /* iSerialNumber */      // Serial Number
		0x01 /* bNumConfigurations */
};

/**
 @name hid_report_descriptor_keyboard
 @brief HID Report descriptor for keyboard.

 See Device Class Definition for Human Interface Devices (HID) Version 1.11
 from USB Implementers� Forum USB.org

 0x05, 0x01,             Usage Page: Generic Desktop Controls
 0x09, 0x06,             Usage: Keyboard
 0xA1, 0x01,             Collection: Application
 0x05, 0x07,               Usage Page: Keyboard
 0x19, 0xE0,               Usage Minimum: Keyboard LeftControl
 0x29, 0xE7,               Usage Maximum: Keyboard Right GUI
 0x15, 0x00,               Logical Minimum: 0
 0x25, 0x01,               Logical Maximum: 1
 0x75, 0x01,               Report Size: 1
 0x95, 0x08,               Report Count: 8
 0x81, 0x02,               Input: Data (2)
 0x95, 0x01,               Report Count: 1
 0x75, 0x08,               Report Size: 8
 0x81, 0x01,               Input: Constant (1)
 0x95, 0x03,               Report Count: 3
 0x75, 0x01,               Report Size: 1
 0x05, 0x08,               Usage Page: LEDs
 0x19, 0x01,               Usage Minimum: Num Lock
 0x29, 0x03,               Usage Maximum: Scroll Lock
 0x91, 0x02,               Output: Data (2)
 0x95, 0x05,               Report Count: 5
 0x75, 0x01,               Report Size: 1
 0x91, 0x01,               Output: Constant (1)
 0x95, 0x06,               Report Count: 6
 0x75, 0x08,               Report Size: 8
 0x15, 0x00,               Logical Minimum: 0
 0x26, 0xFF, 0x00,         Logical Maximum: 255
 0x05, 0x07,               Usage Page: Keyboard/Keypad
 0x19, 0x00,               Usage Minimum: 0
 0x2A, 0xFF, 0x00,         Usage Maximum: 255
 0x81, 0x00,               Input: Data (0)
 0xC0                    End collection
 **/
//@{
DESCRIPTOR_QUALIFIER uint8_t hid_report_descriptor_keyboard[65] =
{ 0x05, 0x01, 0x09, 0x06, 0xA1, 0x01, 0x05, 0x07, 0x19, 0xE0, 0x29, 0xE7, 0x15,
		0x00, 0x25, 0x01, 0x75, 0x01, 0x95, 0x08, 0x81, 0x02, 0x95, 0x01, 0x75,
		0x08, 0x81, 0x01, 0x95, 0x03, 0x75, 0x01, 0x05, 0x08, 0x19, 0x01, 0x29,
		0x03, 0x91, 0x02, 0x95, 0x05, 0x75, 0x01, 0x91, 0x01, 0x95, 0x06, 0x75,
		0x08, 0x15, 0x00, 0x26, 0xFF, 0x00, 0x05, 0x07, 0x19, 0x00, 0x2A, 0xFF,
		0x00, 0x81, 0x00, 0xC0, };
//@}

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
 @name report_buffer
 @brief Buffer used to report back to host the current state of keypresses.
 Can be accessed from the keyboard interrupt IN endpoint or the control endpoint
 with a GET_REPORT request.
 */
hid_report_structure_t report_buffer __attribute__ ((aligned (16)));

#ifndef DISABLE_DFU
/**
 @name wcid_feature_runtime
 @brief WCID Compatible ID for DFU interface in runtime.
 */
//@{
DESCRIPTOR_QUALIFIER USB_WCID_feature_descriptor wcid_feature_runtime =
{
	sizeof(struct USB_WCID_feature_descriptor), /* dwLength */
	USB_MICROSOFT_WCID_VERSION, /* bcdVersion */
	USB_MICROSOFT_WCID_FEATURE_WINDEX_COMPAT_ID, /* wIndex */
	1, /* bCount */
	{0, 0, 0, 0, 0, 0, 0,}, /* rsv1 */
	DFU_USB_INTERFACE_RUNTIME, /* bFirstInterfaceNumber */
	1, /* rsv2 - set to 1 */
	{'W', 'I', 'N', 'U', 'S', 'B', 0x00, 0x00,}, /* compatibleID[8] */
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,}, /* subCompatibleID[8] */
	{0, 0, 0, 0, 0, 0,} /* rsv3[6] */
};

/**
 @name device_descriptor_dfumode
 @brief Device descriptor for DFU Mode.
 */
DESCRIPTOR_QUALIFIER USB_device_descriptor device_descriptor_dfumode =
{
		0x12, /* bLength */
		USB_DESCRIPTOR_TYPE_DEVICE, /* bDescriptorType */
		USB_BCD_VERSION_2_0, /* bcdUSB */          // V2.00
		USB_CLASS_DEVICE, /* bDeviceClass */       // Defined in interface
		USB_SUBCLASS_DEVICE, /* bDeviceSubClass */ // Defined in interface
		USB_PROTOCOL_DEVICE, /* bDeviceProtocol */ // Defined in interface
		USB_CONTROL_EP_MAX_PACKET_SIZE, /* bMaxPacketSize0 */    // 8
		USB_VID_FTDI, /* idVendor */   // idVendor: 0x0403 (FTDI)
		USB_DFU_PID_DFUMODE, /* idProduct */ // idProduct: 0x0fee
		USB_DFU_BCD_DEVICEID, /* bcdDevice */        // 1.1
		0x01, /* iManufacturer */      // Manufacturer
		0x04, /* iProduct */           // Product
		0x03, /* iSerialNumber */      // Serial Number
		0x01 /* bNumConfigurations */
};

/**
 @name config_descriptor_dfumode
 @brief Config descriptor for DFU Mode.
 */
//@{
struct PACK config_descriptor_dfumode
{
	USB_configuration_descriptor configuration;
	USB_interface_descriptor dfu_interface;
	USB_dfu_functional_descriptor dfu_functional;
};

DESCRIPTOR_QUALIFIER struct config_descriptor_dfumode config_descriptor_dfumode =
{
	{
		0x09, /* configuration.bLength */
		USB_DESCRIPTOR_TYPE_CONFIGURATION, /* configuration.bDescriptorType */
		sizeof(struct config_descriptor_dfumode), /* configuration.wTotalLength */
		0x01, /* configuration.bNumInterfaces */
		0x01, /* configuration.bConfigurationValue */
		0x00, /* configuration.iConfiguration */
		USB_CONFIG_BMATTRIBUTES_VALUE, /* configuration.bmAttributes */
		0xFA /* configuration.bMaxPower */ // 500mA
	},

	// ---- INTERFACE DESCRIPTOR for DFU Interface ----
	{
		0x09, /* dfu_interface.bLength */
		USB_DESCRIPTOR_TYPE_INTERFACE, /* dfu_interface.bDescriptorType */
		DFU_USB_INTERFACE_DFUMODE, /* dfu_interface.bInterfaceNumber */
		0x00, /* dfu_interface.bAlternateSetting */
		0x00, /* dfu_interface.bNumEndpoints */
		USB_CLASS_APPLICATION, /* dfu_interface.bInterfaceClass */ // bInterfaceClass: Application Specific Class
		USB_SUBCLASS_DFU, /* dfu_interface.bInterfaceSubClass */ // bInterfaceSubClass: Device Firmware Update
		USB_PROTOCOL_DFU_DFUMODE, /* dfu_interface.bInterfaceProtocol */ // bInterfaceProtocol: Runtime Protocol
		0x05 /* dfu_interface.iInterface */
	},

	// ---- FUNCTIONAL DESCRIPTOR for DFU Interface ----
	{
		0x09, /* dfu_functional.bLength */
		USB_DESCRIPTOR_TYPE_DFU_FUNCTIONAL, /* dfu_functional.bDescriptorType */
		DFU_ATTRIBUTES, /* dfu_functional.bmAttributes */  	// bmAttributes
		DFU_TIMEOUT, /* dfu_functional.wDetatchTimeOut */ // wDetatchTimeOut
		DFU_TRANSFER_SIZE, /* dfu_functional.wTransferSize */     // wTransferSize
		USB_BCD_VERSION_DFU_1_1 /* dfu_functional.bcdDfuVersion */ // bcdDfuVersion: DFU Version 1.1
	}
};
//@}

/**
 @name device_qualifier_descriptor_midi_comp
 @brief Device qualifier descriptor for Run Time mode.
 */
DESCRIPTOR_QUALIFIER USB_device_qualifier_descriptor device_qualifier_descriptor_midi_comp =
{
		sizeof(USB_device_qualifier_descriptor), /* bLength */
		USB_DESCRIPTOR_TYPE_DEVICE_QUALIFIER, /* bDescriptorType */
		USB_BCD_VERSION_2_0, /* bcdUSB */          // V2.0
		USB_CLASS_MISCELLANEOUS, /* bDeviceClass */       // Defined in interface
		USB_SUBCLASS_COMMON_CLASS, /* bDeviceSubClass */ // Defined in interface
		USB_PROTOCOL_INTERFACE_ASSOCIATION, /* bDeviceProtocol */ // Defined in interface
		USB_CONTROL_EP_MAX_PACKET_SIZE, /* bMaxPacketSize0 */
		1, /* bNumConfigurations */
		0
};

/**
 @name wcid_feature_dfumode
 @brief WCID Compatible ID for DFU interface in DFU mode.
 */
//@{
DESCRIPTOR_QUALIFIER USB_WCID_feature_descriptor wcid_feature_dfumode =
{
	sizeof(struct USB_WCID_feature_descriptor), /* dwLength */
	USB_MICROSOFT_WCID_VERSION, /* bcdVersion */
	USB_MICROSOFT_WCID_FEATURE_WINDEX_COMPAT_ID, /* wIndex */
	1, /* bCount */
	{0, 0, 0, 0, 0, 0, 0,}, /* rsv1 */
	DFU_USB_INTERFACE_DFUMODE, /* bFirstInterfaceNumber */
	1, /* rsv2 - set to 1 */
	{'W', 'I', 'N', 'U', 'S', 'B', 0x00, 0x00,}, /* compatibleID[8] */
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,}, /* subCompatibleID[8] */
	{0, 0, 0, 0, 0, 0,} /* rsv3[6] */
};
#endif // DISABLE_DFU

/**
 @name Keyboard Scan Codes Lookup table (for ASCII keys)
 @brief Lookup table for converting ASCII to scan codes.
 @details Columns are [0] ASCII character from UART terminal
                      [1] keyscan code to send in HID report.
                      [2] non-zero to set shift key pressed.
                      [3] non-zero to set ctrl key pressed (not used).
                      [4] non-zero to set alt key pressed (not used).
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

/* NOTE: UK keyboard layout. */
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
		{'3', 32, 0, 0, 0 }, {0xa3, 32, 1, 0, 0 }, // Note £ symbol
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

/**
 @name Keyboard Scan Codes Lookup table (for control keys)
 @brief Lookup table for converting control keys to scan codes.
 The message string has these characters escaped with a backslash.
 When they are encoutered in the string then the lookup table is
 used to send the code to the host.
 */
const char CONTROL_to_scancode[][2] =
{
		{ 'r', 0x4D }, // Right
		{ 'l', 0x4B }, // Left
		{ 'd', 0x50 }, // Down
		{ 'u', 0x48 }, // Up
		{ 'C', 0x3A }, // Caps Lock
		{ 'S', 0x46 }, // Scroll Lock
		{ 'N', 0x53 }, // Num Lock
		{ '1', 0x3B }, // F1
		{ '2', 0x3C }, // F2
		{ '3', 0x3D }, // F3
		{ '4', 0x3E }, // F4
		{ '5', 0x3F }, // F5
		{ '6', 0x40 }, // F6
		{ '7', 0x41 }, // F7
		{ '8', 0x42 }, // F8
		{ '9', 0x43 }, // F9
		{ 'a', 0x44 }, // F10
		{ 'b', 0x57 }, // F11
		{ 'c', 0x58 }, // F12
		{ 'X', 0x53 }, // DEL
		{ 'I', 0x52 }, // INS
		{ 'H', 0x47 }, // Home
		{ 'U', 0x49 }, // Page Up
		{ 'D', 0x51 }, // Page Down
		{ 'E', 0x4F }, // End
		{ 0, 0 },
};

/**
 @brief Global values for enabling the HID to send a string to the host.
 */
//@{
/**
 @name report_protocol
 @brief Flag to set report protocol (0 - boot, 1 - report)
 */
static uint8_t report_protocol = 0;

/**
 @name report_enable
 @brief Flag to enable report mode (i.e. reporting active).
 */
static uint8_t report_enable = 0;

/**
 @name report_idle
 @brief Timer to set idle report period.
 */
static uint8_t report_idle = 0;

/**
 @name input_report
 @brief Flag to enable input reports (i.e. LEDs).
 */
static uint8_t input_report = 0;

/**
 @name kbd_keypress_counter
 @brief Count up ms timer to simulate keypress reports at a set interval.
 */
static volatile int16_t kbd_keypress_counter = 0;

/**
 @name report_active
 @brief This flag is used for sending data to host after host has issued USB_HID_REQUEST_CODE_SET_REPORT.
 */
static volatile uint32_t report_active = 0;
//@}

/**
 @brief Global values for enabling the MIDI to send notes to the host.
 */
//@{
/**
 @name midi_note_counter
 @brief Count up ms timer to simulate notes to be sent at a set interval.
 */
static volatile int16_t midi_note_counter = 0;
//@}

/* MACROS **************************************************************************/

/* LOCAL FUNCTIONS / INLINES *******************************************************/

static struct USBDX_pipe *get_pipe(uint8_t pipe)
{
	// There are 3 URB pipes...
	static struct USBDX_pipe pipes[3];
	struct USBDX_pipe *ret_val = NULL;

	switch (pipe) {
		case MIDI_EP_DATA_IN:
			ret_val = &pipes[0];
			break;
		case MIDI_EP_DATA_OUT:
			ret_val = &pipes[1];
			break;
		case KBD_EP_NOTIFICATION:
			ret_val = &pipes[2];
			break;
		default:
			break;

	}
	assert(ret_val!=NULL);
	return ret_val;
}

void USBD_pipe_isr(uint16_t pipe_bitfields)
{
	if (pipe_bitfields & BIT(MIDI_EP_DATA_IN))
		USBDX_pipe_process(get_pipe(MIDI_EP_DATA_IN));
	if (pipe_bitfields & BIT(MIDI_EP_DATA_OUT))
		USBDX_pipe_process(get_pipe(MIDI_EP_DATA_OUT));
	if (pipe_bitfields & BIT(KBD_EP_NOTIFICATION))
		USBDX_pipe_process(get_pipe(KBD_EP_NOTIFICATION));
}

void ISR_timer(void)
{
	if (timer_is_interrupted(timer_select_a))
	{
		// Countdown for keypress simulation.
		kbd_keypress_counter--;
		// Countdown for MIDI note sending.
		midi_note_counter--;

#ifndef DISABLE_DFU
		// Call the DFU timer to progress state machine.
		// The progression depends on the bmAttributes set in the configuration.
		USBD_DFU_timer();
#endif // DISABLE_DFU
	}
}


/**
 @brief      USB class request handler
 @details    Handle class requests from the host application.
 The bRequest value is parsed and the appropriate
 action or function is performed. Additional values
 from the USB_device_request structure are decoded
 and the DFU state machine and status updated as
 required.
 @param[in]	req - USB_device_request structure containing the
 SETUP portion of the request from the host.
 @return		status - USBD_OK if successful or USBD_ERR_*
 if there is an error or the bRequest is not
 supported.
 **/
int8_t class_req_cb(USB_device_request *req)
{
	int8_t status = USBD_ERR_NOT_SUPPORTED;
	uint8_t interface = LSB(req->wIndex) & 0x0F;
	uint8_t request = req->bRequest;

	// For DFU requests the SETUP packet must be addressed to the
	// the DFU interface on the device.

	// For DFU requests ensure the recipient is an interface...
	if ((req->bmRequestType & USB_BMREQUESTTYPE_RECIPIENT_MASK) ==
			USB_BMREQUESTTYPE_RECIPIENT_INTERFACE)
	{
		// ...and that the interface is the correct Runtime interface
		if (USBD_DFU_is_runtime())
		{
#ifndef DISABLE_DFU

			// Handle Class Requests for the DFU Interface.

			if (interface == DFU_USB_INTERFACE_RUNTIME)
			{
				// Handle only DFU_DETATCH, DFU_GETSTATE and DFU_GETSTATUS
				// when in Runtime mode. Table 3.2 DFU_DETACH is mandatory
				// in Runtime mode, DFU_GETSTATE and DFU_GETSTATUS are
				// optional.
				switch (request)
				{
				case USB_CLASS_REQUEST_DETACH:
					USBD_DFU_class_req_detach(req->wValue);
					status = USBD_OK;
					break;
				case USB_CLASS_REQUEST_GETSTATUS:
					USBD_DFU_class_req_getstatus(req->wLength);
					status = USBD_OK;
					break;
				case USB_CLASS_REQUEST_GETSTATE:
					USBD_DFU_class_req_getstate(req->wLength);
					status = USBD_OK;
					break;
				}
			}
			else
#endif // DISABLE_DFU

			// Handle Class Requests for the Keyboard Interface.

			if (interface == KBD_INTERFACE)
			{
				switch (req->bRequest)
				{
				case USB_HID_REQUEST_CODE_SET_IDLE:
					report_enable = 1;
					report_idle = req->wValue >> 8;
					USBD_transfer_ep0(USBD_DIR_IN, NULL, 0, 0);
					status = USBD_OK;
					break;

				case USB_HID_REQUEST_CODE_GET_IDLE:
					USBD_transfer_ep0(USBD_DIR_IN, &report_idle, 1, 1);
					// ACK packet
					USBD_transfer_ep0(USBD_DIR_OUT, NULL, 0, 0);
					status = USBD_OK;
					break;

				case USB_HID_REQUEST_CODE_SET_PROTOCOL:
					USBD_transfer_ep0(USBD_DIR_IN, NULL, 0, 0);
					report_protocol = req->wValue & 0xff;
					// ACK packet
					USBD_transfer_ep0(USBD_DIR_OUT, NULL, 0, 0);
					status = USBD_OK;
					break;

				case USB_HID_REQUEST_CODE_GET_PROTOCOL:
					USBD_transfer_ep0(USBD_DIR_IN, &report_protocol, 1, 1);
					// ACK packet
					USBD_transfer_ep0(USBD_DIR_OUT, NULL, 0, 0);
					status = USBD_OK;
					break;

				case USB_HID_REQUEST_CODE_GET_REPORT:
					USBD_transfer_ep0(USBD_DIR_IN, (uint8_t *) &report_buffer,
							sizeof(report_buffer), sizeof(report_buffer));
					// ACK packet
					USBD_transfer_ep0(USBD_DIR_OUT, NULL, 0, 0);
					status = USBD_OK;
					break;

				case USB_HID_REQUEST_CODE_SET_REPORT:
					// dummy read of one byte
					USBD_transfer_ep0(USBD_DIR_OUT, &input_report, 1, 1);
					// Update LED status on GPIO P0
					//P0 = input_report;
					// Acknowledge SETUP
					USBD_transfer_ep0(USBD_DIR_IN, NULL, 0, 0);
					// We only send data after host has issued this command.
					report_active = 1;
					status = USBD_OK;
					break;
				}
			}

			// There are NO Class Requests for the MIDI Interface.

		}
		// ...or the correct DFU Mode interface
		else
		{
#ifndef DISABLE_DFU
			if (interface == DFU_USB_INTERFACE_DFUMODE)
			{
				// Handle remaining DFU class requests when in DFU Mode.
				// Table 3.2 DFU_DETACH is not supported in DFU Mode.
				switch (req->bRequest)
				{
				case USB_CLASS_REQUEST_DNLOAD:
					/* Block number passed in wValue gives the start address of
					 * to program based on the size of the transfer size.
					 */
					USBD_DFU_class_req_download(req->wValue * DFU_TRANSFER_SIZE,
							req->wLength);
					status = USBD_OK;
					break;

				case USB_CLASS_REQUEST_UPLOAD:
					/* Block number passed in wValue gives the start address of
					 * to program based on the size of the transfer size.
					 */
					USBD_DFU_class_req_upload(req->wValue * DFU_TRANSFER_SIZE,
							req->wLength);
					status = USBD_OK;
					break;

				case USB_CLASS_REQUEST_GETSTATUS:
					USBD_DFU_class_req_getstatus(req->wLength);
					status = USBD_OK;
					break;

				case USB_CLASS_REQUEST_GETSTATE:
					USBD_DFU_class_req_getstate(req->wLength);
					status = USBD_OK;
					break;
				case USB_CLASS_REQUEST_CLRSTATUS:
					USBD_DFU_class_req_clrstatus();
					status = USBD_OK;
					break;
				case USB_CLASS_REQUEST_ABORT:
					USBD_DFU_class_req_abort();
					status = USBD_OK;
					break;

				default:
					// Unknown or unsupported request.
					break;
				}
			}
#endif			
		}
	}

	return status;
}

#define CLAMP(t, max) if ((t) > (max)) (t) = (max)
/**
 @brief      USB standard request handler for GET_DESCRIPTOR
 @details    Handle standard GET_DESCRIPTOR requests from the host
 application.
 The hValue is parsed and the appropriate device,
 configuration or string descriptor is selected.
 For device and configuration descriptors the DFU
 state machine determines which descriptor to use.
 For string descriptors the lValue selects which
 string from the string_descriptors table to use.
 The string table is automatically traversed to find
 the correct string and the length is taken from the
 string descriptor.
 @param[in]	req - USB_device_request structure containing the
 SETUP portion of the request from the host.
 @return		status - USBD_OK if successful or USBD_ERR_*
 if there is an error or the bmRequestType is not
 supported.
 **/
int8_t standard_req_get_descriptor(USB_device_request *req, uint8_t **buffer, uint16_t *len)
{
	uint8_t *src = NULL;
	uint16_t length = req->wLength;
	uint8_t interface = LSB(req->wIndex) & 0x0F;
	uint8_t hValue = req->wValue >> 8;
	uint8_t lValue = req->wValue & 0x00ff;
	uint8_t i;
	uint8_t slen;

	switch (hValue)
	{
	case USB_DESCRIPTOR_TYPE_DEVICE:
#ifndef DISABLE_DFU
		if (USBD_DFU_is_runtime())
		{
			// Get the device descriptor for MIDI and Keyboard composite.
			src = (uint8_t *) &device_descriptor_midikbd;
		}
		else
		{
			// Get the device descriptor when switched to DFU mode.
			src = (uint8_t *) &device_descriptor_dfumode;
		}
#else
		src = (uint8_t *) &device_descriptor_midikbd;
#endif // DISABLE_DFU

		if (length > sizeof(USB_device_descriptor)) // too many bytes requested
				length = sizeof(USB_device_descriptor); // Entire structure.
		break;

	case USB_DESCRIPTOR_TYPE_CONFIGURATION:
#ifndef DISABLE_DFU
		if (USBD_DFU_is_runtime())
		{
			// Get the configuration descriptor for MIDI and Keyboard composite.
			src = (uint8_t *) &config_descriptor_composite;
			if (length > sizeof(config_descriptor_composite)) // too many bytes requested
				length = sizeof(config_descriptor_composite); // Entire structure.
		}
		else
		{
			// Get the configuration descriptor when switched to DFU mode.
			src = (uint8_t *) &config_descriptor_dfumode;
			if (length > sizeof(config_descriptor_dfumode)) // too many bytes requested
				length = sizeof(config_descriptor_dfumode); // Entire structure.
		}
#else // DISABLE_DFU
		src = (uint8_t *) &config_descriptor_composite;
		if (length > sizeof(config_descriptor_composite)) // too many bytes requested
			length = sizeof(config_descriptor_composite); // Entire structure.
#endif // DISABLE_DFU

		break;

	case USB_DESCRIPTOR_TYPE_DEVICE_QUALIFIER:
		src = (uint8_t *) &device_qualifier_descriptor_midi_comp;
		CLAMP(length, sizeof(USB_device_qualifier_descriptor));
		break;

	case USB_DESCRIPTOR_TYPE_STRING:
#ifndef DISABLE_DFU
		// Special case: WCID descriptor
		if (lValue == USB_MICROSOFT_WCID_STRING_DESCRIPTOR)
		{
			src = (uint8_t *)wcid_string_descriptor;
			length = sizeof(wcid_string_descriptor);
			break;
		}
#endif // DISABLE_DFU
		// Find the nth string in the string descriptor table
		i = 0;
		while ((slen = string_descriptor[i]) > 0)
		{
			// Point to start of string descriptor in __code segment
			// Typecast prevents warning for losing const when USBD_transfer
			// is called
			src = (uint8_t *) &string_descriptor[i];
			if (lValue == 0)
			{
				break;
			}
			i += slen;
			lValue--;
		}
		if (lValue > 0)
		{
			// String not found
			return USBD_ERR_NOT_SUPPORTED;
		}
		// Update the length returned only if it is less than the requested
		// size
		if (length > slen)
		{
			length = slen;
		}

		break;

	case USB_DESCRIPTOR_TYPE_REPORT:

		// Return a report descriptor for the keyboard interface.

		if (interface == KBD_INTERFACE)
		{
			src = (uint8_t *) &hid_report_descriptor_keyboard;
			if (length > sizeof(hid_report_descriptor_keyboard))
			{
				length = sizeof(hid_report_descriptor_keyboard); // Entire structure.
			}
		}
		else
		{
			return USBD_ERR_NOT_SUPPORTED;
		}
		break;

	default:
		return USBD_ERR_NOT_SUPPORTED;
	}

	*buffer = src;
	*len = length;

	return USBD_OK;
}

/**
 @brief      USB vendor request handler
 @details    Handle vendor requests from the host application.
 The bRequest value is parsed and the appropriate
 action or function is performed. Additional values
 and provided to other handlers.
 There are no vendor requests requiring handling in
 this firmware.
 @param[in]	req - USB_device_request structure containing the
 SETUP portion of the request from the host.
 @return		status - USBD_OK if successful or USBD_ERR_*
 if there is an error or the bRequest is not
 supported.
 **/
int8_t vendor_req_cb(USB_device_request *req)
{
	int8_t status = USBD_ERR_NOT_SUPPORTED;
#ifndef DISABLE_DFU
	uint16_t length = req->wLength;

	// For Microsoft WCID only.
	// Request for Compatible ID Feature Descriptors.
	// Check the request code and wIndex.
	if ((req->bRequest == WCID_VENDOR_REQUEST_CODE) && (req->bmRequestType & USB_BMREQUESTTYPE_DIR_DEV_TO_HOST))
	{
		if (req->wIndex == USB_MICROSOFT_WCID_FEATURE_WINDEX_COMPAT_ID)
		{
			if (length > sizeof(wcid_feature_runtime)) // too many bytes requested
				length = sizeof(wcid_feature_runtime); // Entire structure.
			// Return a compatible ID feature descriptor.
			if (USBD_DFU_is_runtime())
			{
				USBD_transfer_ep0(USBD_DIR_IN, (uint8_t *) &wcid_feature_runtime,
						length, length);
			}
			else
			{
				USBD_transfer_ep0(USBD_DIR_IN, (uint8_t *) &wcid_feature_dfumode,
						length, length);
			}
			// ACK packet
			USBD_transfer_ep0(USBD_DIR_OUT, NULL, 0, 0);
			status = USBD_OK;
		}
		else if (req->wIndex == USB_MICROSOFT_WCID_FEATURE_WINDEX_DEVICE_GUID)
		{
			/*  as opposed to the Compatible ID, Device GUID can be queried using an Interface or/and Device Request */
			if (((req->bmRequestType & USB_BMREQUESTTYPE_RECIPIENT_MASK) == USB_BMREQUESTTYPE_RECIPIENT_DEVICE)
					|| ((req->bmRequestType & USB_BMREQUESTTYPE_RECIPIENT_MASK) == USB_BMREQUESTTYPE_RECIPIENT_INTERFACE))
			{
				if (LSB(req->wValue) == DFU_USB_INTERFACE_RUNTIME)
				{
					if (length > sizeof(usb_composite_device_interface_guid)) // too many bytes requested
					{
						length = sizeof(usb_composite_device_interface_guid); // Entire structure.
					}
					// Return the extended property for the interface requested.
					USBD_transfer_ep0(USBD_DIR_IN, (uint8_t *)&usb_composite_device_interface_guid,
							length, length);
					// ACK packet
					USBD_transfer_ep0(USBD_DIR_OUT, NULL, 0, 0);
					status = USBD_OK;
				}
			}
		}
	}
#endif // DISABLE_DFU
	(void)req;

	return status;
}

/**
 @brief      USB suspend callback
 @details    Called when the USB bus enters the suspend state.
 @param[in]	status - unused.
 @return		N/A
 **/
void suspend_cb(uint8_t status)
{
	(void) status;
	return;
}

/**
 @brief      USB resume callback
 @details    Called when the USB bus enters the resume state
 prior to restating after a suspend.
 @param[in]  status - unused.
 @return     N/S
 **/
void resume_cb(uint8_t status)
{
	(void) status;
	return;
}

/**
 @brief      USB reset callback
 @details    Called when the USB bus enters the reset state.
 @param[in]	status - unused.
 @return		N/A
 **/
void reset_cb(uint8_t status)
{
	(void) status;

	USBD_set_state(USBD_STATE_DEFAULT);

	// If we are at DFUSTATE_MANIFEST_WAIT_RESET stage and do
	// not support detach then the DFU will reset the chip and
	// run the new firmware.
	// From the DFUSTATE_APPIDLE state advance to DFUSTATE_DFUIDLE.
	// Other states will not advance the state machine or may
	// move this to DFUSTATE_DFUERROR if it is inappropriate to
	// find a reset at that stage.
	USBD_DFU_reset();

	return;
}

/* For debugging endpoint transactions. */
void ep_cb(USBD_ENDPOINT_NUMBER ep_number)
{
	printf("EP%d\r\n", ep_number);
}

/* Signal true for callback. */
bool midi_out_on_data_ready(struct USBDX_pipe *pp)
{
	return true;
}

/**
 @brief      Setup MIDI device interface
 @details    Called to initialise the USB device for MIDI.
 This also initialises the URB pipes used to transfer data to/from the host via the USB.
 @return		N/A
 **/
static void midi_init(void)
{
	USBD_create_endpoint(MIDI_EP_DATA_OUT, USBD_EP_BULK, USBD_DIR_OUT,
			MIDI_DATA_USBD_EP_SIZE, USBD_DB_ON, NULL /*ep_cb*/);
	USBD_create_endpoint(MIDI_EP_DATA_IN, USBD_EP_BULK, USBD_DIR_IN,
			MIDI_DATA_USBD_EP_SIZE, USBD_DB_ON, NULL /*ep_cb*/);

	static uint8_t midi_in_buf[MIDI_DATA_IN_PACKET_SIZE * URB_MIDI_DATA_IN_COUNT];
	static uint8_t midi_out_buf[MIDI_DATA_OUT_PACKET_SIZE * URB_MIDI_DATA_OUT_COUNT];
	static struct USBDX_urb midi_in_urb[URB_MIDI_DATA_IN_COUNT];
	static struct USBDX_urb midi_out_urb[URB_MIDI_DATA_OUT_COUNT];
	struct USBDX_pipe *pp;

	/* ACM */
	pp = get_pipe(MIDI_EP_DATA_IN);
	USBDX_pipe_init(pp, MIDI_EP_DATA_IN, MIDI_EP_DATA_IN | USB_ENDPOINT_DESCRIPTOR_EPADDR_IN,
			midi_in_urb, midi_in_buf, URB_MIDI_DATA_IN_COUNT);

	pp = get_pipe(MIDI_EP_DATA_OUT);
	USBDX_pipe_init(pp, MIDI_EP_DATA_OUT, MIDI_EP_DATA_OUT,
			midi_out_urb, midi_out_buf, URB_MIDI_DATA_OUT_COUNT);

	USBDX_register_on_ready(pp, midi_out_on_data_ready);
}

/**
 @brief      Setup keyboard device interface
 @details    Called to initialise the USB device for the keyboard.
 This also initialises the URB pipe used to transfer data to the host via the USB.
 @return		N/A
 **/
static void kbd_init(void)
{
	static uint8_t kbd_int_buf[KBD_NOTIFICATION_EP_SIZE * URB_KBD_COUNT] __attribute__ ((aligned (16)));
	static struct USBDX_urb kbd_int_urb[URB_KBD_COUNT];
	struct USBDX_pipe *pp;

	pp = get_pipe(KBD_EP_NOTIFICATION);
	USBDX_pipe_init(pp, KBD_EP_NOTIFICATION, KBD_EP_NOTIFICATION | USB_ENDPOINT_DESCRIPTOR_EPADDR_IN,
			kbd_int_urb, kbd_int_buf, URB_KBD_COUNT);

	USBD_create_endpoint(KBD_EP_NOTIFICATION, USBD_EP_INT, USBD_DIR_IN,
			KBD_NOTIFICATION_USBD_EP_SIZE, USBD_DB_OFF, NULL /*ep_cb*/);
}

/**
 * @brief Send a USB-MIDI event packet (for NOTE ON or NOTE OFF only)
 * @details Format a 32 bit packet to send to the host.
 * The Code Index Number (CIN) and Cable Number (CN) are passed to the function with
 * the note and force parameters to form the 32 bit MIDI event packet.
 * See Section 4 of the MIDI 1.0 specifications.
 * @param cin - Code Index Number 4 bits.
 * @param cn - Cable Number 4 bits.
 * @param note - Mapped note to play/stop.
 * @param force - Velocity of note 7 bits.
 */
static void send_midi_note_packet(uint8_t cin, uint8_t cn, uint8_t note, uint8_t force)
{
	struct USBDX_pipe *ppMidi = get_pipe(MIDI_EP_DATA_IN);

	CRITICAL_SECTION_BEGIN
	/* Force acquire USB IN buffer */
	struct USBDX_urb *urb = USBDX_force_acquire_urb_for_app(ppMidi);

	uint16_t free = usbdx_urb_get_app_to_process(urb);
	/* If have enough URB space */
	if (free >= MIDI_DATA_IN_PACKET_SIZE)
	{
		usb_audioMidiEventPacket *pmsg = (usb_audioMidiEventPacket *)urb->ptr;
		urb->ptr += sizeof(usb_audioMidiEventPacket);

		pmsg->bmCIN_CN = ((cn & 0xf) << 4) | (cin & 0xf);
		pmsg->bMIDI_0 = (cin & 0xf) << 4;
		pmsg->bMIDI_1 = note;
		pmsg->bMIDI_2 = force;

		USBDX_submit_urb(ppMidi, urb);
	}
	CRITICAL_SECTION_END
}

/**
 * @brief Receive and decode a USB-MIDI event packet (for NOTE ON or NOTE OFF only)
 * @details Format a 32 bit packet received from the host.
 * Pointers to the Code Index Number (CIN) and Cable Number (CN) are passed to the
 * function with pointers for the note and force values.
 * The values are decoded from the 32 bit MIDI event packet.
 * See Section 4 of the MIDI 1.0 specifications.
 * @param cin - Code Index Number 4 bits.
 * @param cn - Cable Number 4 bits.
 * @param note - Mapped note to play/stop.
 * @param force - Velocity of note 7 bits.
 */
static uint8_t receive_midi_note_packet(uint8_t *cin, uint8_t *cn, uint8_t *note, uint8_t *force)
{
	bool valid = false;
	struct USBDX_pipe *pp = get_pipe(MIDI_EP_DATA_OUT);

	CRITICAL_SECTION_BEGIN
	struct USBDX_urb *urb = usbdx_get_app_urb(pp);

	if (likely(usbdx_urb_owned_by_app(urb)))
	{
		uint16_t urb_len = usbdx_urb_get_app_to_process(urb);

		if (urb_len >= MIDI_DATA_OUT_PACKET_SIZE)
		{
			usb_audioMidiEventPacket *pmsg = (usb_audioMidiEventPacket *)urb->ptr;

			if (((pmsg->bmCIN_CN & 0xf) == USB_AUDIO_MIDI_EVENT_CIN_NOTE_OFF) ||
					((pmsg->bmCIN_CN & 0xf) == USB_AUDIO_MIDI_EVENT_CIN_NOTE_ON))
			{
				*cin = pmsg->bmCIN_CN & 0xf;
				*cn = (pmsg->bmCIN_CN >> 4) & 0xf;
				*note = pmsg->bMIDI_1;
				*force = pmsg->bMIDI_2;

				/* Can send out all URB buffer, queue URB back to USBD */
				USBDX_submit_urb(pp, urb);
				valid = true;
			}
		}
	}
	else
	{
		usbdx_set_app_paused(pp);
		valid = false;
	}

	CRITICAL_SECTION_END

	return valid;
}

/** @brief Main testing loop for the keyboard and MIDI emulation.
 */
static void composite_test(void)
{
	int8_t status;

#ifdef KDB_DEVICE_ENABLE
	unsigned char key;
	unsigned char kbd_state = KBD_STATE_ON; // First action is a keypress.
	unsigned short kbd_delay = KBD_ON_PERIOD;
	unsigned char kbd_scancode_key;
	unsigned char kbd_scancode_shift;
	const char *pmsg = tty_message; // Pointer to message to send to host
	struct USBDX_pipe *ppKbd = get_pipe(KBD_EP_NOTIFICATION);

	CRITICAL_SECTION_BEGIN
	// Wait an initial delay for OS to setup keyboard.
	kbd_keypress_counter = KBD_STARTUP_TIME;
	CRITICAL_SECTION_END
#endif // KDB_DEVICE_ENABLE

#ifdef MIDI_DEVICE_ENABLE
	const uint8_t *ptune = midi_tune; // Pointer to note to send to host
	unsigned short midi_delay = MIDI_PERIOD;
	uint8_t midi_note, cin, cn, force;
	uint8_t midi_last_note = 0;

	CRITICAL_SECTION_BEGIN
	// Wait an initial delay for OS to setup MIDI device.
	midi_note_counter = MIDI_STARTUP_TIME;
	CRITICAL_SECTION_END
#endif // MIDI_DEVICE_ENABLE

	// Loop until disconnected.
	do
	{
		/* Note that report_idle timer is not implemented - assumed to be zero (infinite) */
		if (USBD_get_state() == USBD_STATE_CONFIGURED)
		{
#ifdef MIDI_DEVICE_ENABLE
			/* Interface 1: Endpoint 1 - MIDI IN! */

			if (midi_note_counter < 0)
			{
				if (*ptune > 0)
				{
					midi_note = *ptune++;
					midi_delay = *ptune++;

					CRITICAL_SECTION_BEGIN
					midi_note_counter = MIDI_PERIOD * midi_delay;
					CRITICAL_SECTION_END

					// Turn on the next note
					send_midi_note_packet(USB_AUDIO_MIDI_EVENT_CIN_NOTE_ON, 0, midi_note, 127);

#ifdef MIDI_DEVICE_DEBUG_ON
					printf("-> %d %d; ", midi_note, midi_delay);
#endif // MIDI_DEVICE_DEBUG_ON
				}

				if (midi_last_note > 0)
				{
					// Turn off the previous note
					send_midi_note_packet(USB_AUDIO_MIDI_EVENT_CIN_NOTE_OFF, 0, midi_last_note, 0);
					midi_last_note = 0;
				}
			}


			if (receive_midi_note_packet(&cin, &cn, &midi_note, &force))
			{
#ifdef MIDI_DEVICE_DEBUG_ON
				printf("<- %x %d (%d); ", cin, midi_note, force);
#endif // MIDI_DEVICE_DEBUG_ON
			}

#endif // MIDI_DEVICE_ENABLE

#ifdef KDB_DEVICE_ENABLE
			/* Interface 2: Endpoint 3 - Keyboard! */

			/* Keyboard emulation code. */
			if ((report_enable) && (report_active))
			{
				if ((*pmsg > 0) || (kbd_state == KBD_STATE_OFF))
				{
					if (kbd_keypress_counter < 0)
					{
						CRITICAL_SECTION_BEGIN
						kbd_keypress_counter = kbd_delay;
						CRITICAL_SECTION_END

						// Wait until any previous keypress has been sent
						switch (kbd_state)
						{
						case KBD_STATE_ON:
							kbd_delay = KBD_ON_PERIOD;
							kbd_state = KBD_STATE_OFF;

							// Clear any previous key scan codes.
							kbd_scancode_key = 0;
							kbd_scancode_shift = 0;

							// Check escape code for NON-ASCII keys
							// This is an arbitrary character to signify an escape code
							if (*pmsg != '\\')
							{
								// Decode normal non-escaped keypresses into
								// key scan codes.
								for (key = 0; ASCII_scancode[key].scan; key++)
								{
									if (ASCII_scancode[key].msg == *pmsg)
									{
										kbd_scancode_key = ASCII_scancode[key].scan;
										kbd_scancode_shift = ASCII_scancode[key].shift;
										break;
									}
								}

#ifdef KDB_DEVICE_DEBUG_ON
								// For debugging display character sent.
								if (isgraph(*pmsg) || isspace(*pmsg))
									printf("%c",*pmsg);
								else
									printf("\\x%02x",*pmsg);
#endif // KDB_DEVICE_DEBUG_ON

								// Next character.
								pmsg++;
							}
							else
							{
								// CONTROL key decode.
								// Next character is control key.
								pmsg++;
								for (key = 0; CONTROL_to_scancode[key][0];
										key++)
								{
									if (CONTROL_to_scancode[key][1] == *pmsg)
									{
										kbd_scancode_key = CONTROL_to_scancode[key][0];
										break;
									}
								}

#ifdef KDB_DEVICE_DEBUG_ON
								// For debugging display control character sent.
								printf("\\\\%c",*pmsg);
#endif // KDB_DEVICE_DEBUG_ON

								pmsg++;
							}

							report_buffer.arrayKeyboard = kbd_scancode_key;
							report_buffer.kbdRightShift = kbd_scancode_shift;
							break;

						case KBD_STATE_OFF:
							kbd_delay = KBD_OFF_PERIOD;
							if (*pmsg == ' ')
								kbd_delay = KBD_OFF_PERIOD_LONG;
							kbd_state = KBD_STATE_ON;

							memset(&report_buffer, 0, sizeof(hid_report_structure_t));
							//report_buffer.arrayKeyboard = 0x00;
							//report_buffer.arrayMap = 0;
							break;

						default:
							break;
						}

						CRITICAL_SECTION_BEGIN
						/* Force acquire USB IN buffer */
						struct USBDX_urb *urb = USBDX_force_acquire_urb_for_app(ppKbd);

						uint16_t free = usbdx_urb_get_app_to_process(urb);
						/* If have enough URB space */
						if (free >= sizeof(hid_report_structure_t))
						{
							asm_memcpy8(&report_buffer, urb->ptr, sizeof(hid_report_structure_t));
							urb->ptr += sizeof(hid_report_structure_t);
							USBDX_submit_urb(ppKbd, urb);
						}
						CRITICAL_SECTION_END
					}
				}
			}
#endif // KDB_DEVICE_ENABLE
		}

		status = (USBD_get_state() < USBD_STATE_DEFAULT)?USBD_ERR_NOT_CONFIGURED:USBD_OK;

	} while (status == USBD_OK);

	// Disconnected from host.
}

static uint8_t usbd_testing(void)
{
	int8_t status;
	USBD_ctx usb_ctx;

	memset(&usb_ctx, 0, sizeof(usb_ctx));

	usb_ctx.standard_req_cb = NULL;
	usb_ctx.get_descriptor_cb = standard_req_get_descriptor;
	usb_ctx.class_req_cb = class_req_cb;
	usb_ctx.vendor_req_cb = vendor_req_cb;
	usb_ctx.suspend_cb = suspend_cb;
	usb_ctx.resume_cb = resume_cb;
	usb_ctx.reset_cb = reset_cb;
	usb_ctx.lpm_cb = NULL;
	usb_ctx.speed = USBD_SPEED_HIGH;

	// Initialise the USB device with a control endpoint size
	// of 8 to 64 bytes. This must match the size for bMaxPacketSize0
	// defined in the device descriptor.
	usb_ctx.ep0_size = USB_CONTROL_EP_SIZE;
	//usb_ctx.ep0_cb = ep_cb;

	USBD_initialise(&usb_ctx);
	midi_init();
	kbd_init();

	for (;;)
	{
		if (!USBD_is_connected())
		{
			continue;
		}
		/* Get USB speed */
		USBD_attach();
		USBD_connect();

		if (USBD_get_state() >= USBD_STATE_DEFAULT)
		{
			if (USBD_DFU_is_runtime())
			{
				// Start the emulation code.
				composite_test();
			}
			else
			{
				// In DFU mode. Process USB requests.
				do{
					status = (USBD_get_state() < USBD_STATE_DEFAULT)?USBD_ERR_NOT_CONFIGURED:USBD_OK;
				}while (status == USBD_OK);
			}
		}
		printf("Restarting\r\n");
	}

	return 0;
}

void powermanagement_ISR(void)
{
	if (SYS->PMCFG_H & MASK_SYS_PMCFG_DEV_CONN_DEV)
	{
		// Clear connection interrupt
		SYS->PMCFG_H = MASK_SYS_PMCFG_DEV_CONN_DEV;
		USBD_attach();
	}

	if (SYS->PMCFG_H & MASK_SYS_PMCFG_DEV_DIS_DEV)
	{
		// Clear disconnection interrupt
		SYS->PMCFG_H = MASK_SYS_PMCFG_DEV_DIS_DEV;
		USBD_detach();
	}

	if (SYS->PMCFG_H & MASK_SYS_PMCFG_HOST_RST_DEV)
	{
		// Clear Host Reset interrupt
		SYS->PMCFG_H = MASK_SYS_PMCFG_HOST_RST_DEV;
		USBD_resume();
	}

	if (SYS->PMCFG_H & MASK_SYS_PMCFG_HOST_RESUME_DEV)
	{
		// Clear Host Resume interrupt
		SYS->PMCFG_H = MASK_SYS_PMCFG_HOST_RESUME_DEV;
		if(! (SYS->MSC0CFG & MASK_SYS_MSC0CFG_DEV_RMWAKEUP))
		{
			// If we are driving K-state on Device USB port;
			// We must maintain the 1ms requirement before resuming the phy
			USBD_resume();
		}
	}
}

/* FUNCTIONS ***********************************************************************/

int main(void)
{
	sys_reset_all();

	/* Enable the UART Device... */
	sys_enable(sys_device_uart0);
#if defined(__FT930__)
    /* Make GPIO23 function as UART0_TXD and GPIO22 function as UART0_RXD... */
    gpio_function(23, pad_uart0_txd); /* UART0 TXD */
    gpio_function(22, pad_uart0_rxd); /* UART0 RXD */
#else
	/* Make GPIO48 function as UART0_TXD and GPIO49 function as UART0_RXD... */
	gpio_function(48, pad_uart0_txd); /* UART0 TXD */
	gpio_function(49, pad_uart0_rxd); /* UART0 RXD */
#endif
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

	/* Timer A = 1ms */
	timer_prescaler(timer_select_a, 1000);
	timer_init(timer_select_a, 100, timer_direction_down, timer_prescaler_select_on, timer_mode_continuous);
	timer_enable_interrupt(timer_select_a);
	timer_start(timer_select_a);

	interrupt_attach(interrupt_timers, (int8_t)interrupt_timers, ISR_timer);

	interrupt_attach(interrupt_0, (int8_t)interrupt_0, powermanagement_ISR);
	interrupt_enable_globally();

	printf("(C) Copyright, Bridgetek Pte Ltd \r\n");
	printf("--------------------------------------------------------------------- \r\n");
	printf("Welcome to USB Composite Device Example... \r\n");
	printf("\r\n");
	printf("Emulate a keyboard and a MIDI device connected to the USB Device Port.\r\n");
	printf("Also enable the DFU function.\r\n");
	printf("--------------------------------------------------------------------- \r\n");

	usbd_testing();

	interrupt_detach(interrupt_timers);
	interrupt_disable_globally();

	sys_disable(sys_device_timer_wdt);

	// Wait forever...
	for (;;);

	return 0;
}


