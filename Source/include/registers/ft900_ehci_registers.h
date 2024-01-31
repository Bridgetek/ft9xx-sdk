/**
    @file ft900_ehci_registers.h

    @brief EHCI (USB Host) registers
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

#ifndef FT900_EHCI_REGISTERS_H_
#define FT900_EHCI_REGISTERS_H_

/* INCLUDES ************************************************************************/
#include <stdint.h>
#include "ft900_regs_std.h"

/* CONSTANTS ***********************************************************************/

/** Bit masks for the ECHI CAPLENGTH register **/
//@{
/** \brief Capability Register Length
    \details An offset added to register base to find out the beginning of the
    Operational Register Space.
**/
#define BIT_EHCI_CAPLENGTH       (0)
#define MASK_EHCI_CAPLENGTH      (0xFF << BIT_EHCI_HCCAP_CAPLENGTH)
/** \brief Host Controller Interface Version Number
    \details A 2-byte register containing a BCD encoding of the EHCI revision number
    supported by the host controller.
**/
#define BIT_EHCI_VERSION         (16)
#define MASK_EHCI_VERSION        (0xFFFF << BIT_EHCI_VERSION)
//@}

/** Bit masks for the ECHI HCCPARAMS register */
//@{
/** \brief Number of Ports
    \details This specifies the number of the physical downstream ports implemented on the
    host controller.
**/
#define BIT_EHCI_HCCPARAMS_NPORTS  (0)
#define MASK_EHCI_HCCPARAMS_NPORTS (0x7 << BIT_EHCI_HCCPARAMS_NPORTS)
//@}

/** Bit masks for the ECHI HCSPARAMS register */
//@{
/** \brief Programmable Frame List Flag
    \details When this bit is set to 1, the system software can specify and use a
    smaller frame list and configure the host controller via Frame List Size field
    of the USBCMD register. This requirement ensures that the frame list is always
    physically contiguous.
**/
#define BIT_EHCI_HCSPARAMS_PROG_FR_LIST_FLAG  (1)
#define MASK_EHCI_HCSPARAMS_NPORTS            (0x1 << BIT_EHCI_HCSPARAMS_PROG_FR_LIST_FLAG)
/** \brief Asynchronous Schedule Park Capability
    \details The host controller supports the park feature for HS queue heads in the
    Asynchronous Schedule. This feature can be disabled or enabled and set to a
    specific level by using the Asynchronous Schedule Park Mode Enable and Asynchronous
    Schedule Park Mode Count fields in the USBCMD register.
**/
#define BIT_EHCI_HCSPARAMS_ASYN_SCH_PARK_CAP  (2)
#define MASK_EHCI_HCSPARAMS_ASYN_SCH_PARK_CAP (0x1 << BIT_EHCI_HCSPARAMS_ASYN_SCH_PARK_CAP)
//@}

/** Bit masks for the ECHI USBCMD register */
//@{
/** \brief Interrupt Threshold Control
    \details This is used by the system software to select the maximum rate at which the
    host controller will issue the interrupts. The only valid values are as below:
        0x00 : Reserved
        0x01 ; 1 micro-frame (125us)
        0x02 ; 2 micro-frames (250us)
        0x04 ; 4 micro-frames (500us)
        0x08 ; 8 micro-frames (default : 1ms)
        0x10 ; 16 micro-frames (2ms)
        0x20 ; 32 micro-frames (4ms)
        0x40 ; 64 micro-frames (8ms)
        Note: In the FS mode, these bits are reserved.
**/
#define BIT_EHCI_USBCMD_INT_THRC  (16)
#define MASK_EHCI_USBCMD_INT_THRC (0xff << BIT_EHCI_USBCMD_INT_THRC)
/** \brief Asynchronous Schedule Park Mode Enable
    \details Software uses this to enable or disable the Park mode.
        When this is set to 1, the Park mode is enabled
**/
#define BIT_EHCI_USBCMD_ASYN_PK_EN  (11)
#define MASK_EHCI_USBCMD_ASYN_PK_EN (0x1 << BIT_EHCI_USBCMD_ASYN_PK_EN)
/** \brief Asynchronous Schedule Park Mode Count
    \details This contains a count for the number of successive transactions that the host
    controller is allowed to execute from a HS queue head on the asynchronous schedule.
**/
#define BIT_EHCI_USBCMD_ASYN_PK_CNT  (8)
#define MASK_EHCI_USBCMD_ASYN_PK_CNT (0x3 << BIT_EHCI_USBCMD_ASYN_PK_CNT)
/** \brief Interrupt on Asynchronous Advance Doorbell
    \details This is used as a doorbell by software to ring the host controller to issue
    and interrupt at the next advance of the synchronous schedule.
**/
#define BIT_EHCI_USBCMD_INT_OAAD  (6)
#define MASK_EHCI_USBCMD_INT_OAAD (0x1 << BIT_EHCI_USBCMD_INT_OAAD)
/** \brief Asynchronous Schedule Enable
    \details This controls whether the host controller skips the processing of asynchronous schedule.
        0 : Do not process the asynchronous schedule
        1 : Use the ASYNCLISTADDR register to access the asynchronous schedule
**/
#define BIT_EHCI_USBCMD_ASCH_EN  (5)
#define MASK_EHCI_USBCMD_ASCH_EN (0x1 << BIT_EHCI_USBCMD_ASCH_EN)
/** \brief Periodic Schedule Enable
    \details This controls whether the host controller skips the processing of the period schedule.
        0 : Do not process the period schedule
        1 : Use the PERIODICLISTBASE register to access the period schedule
**/
#define BIT_EHCI_USBCMD_PSCH_EN  (4)
#define MASK_EHCI_USBCMD_PSCH_EN (0x1 << BIT_EHCI_USBCMD_PSCH_EN)
/** \brief Frame List Size
    \details This specifies the size of the frame list for the periodic schedule.
        00 : 1024 elements (default value, 4096 bytes)
        01 : 512 elements (2048 bytes)
        10 : 256 elements (1024 bytes)
        11 : reserved
**/
#define BIT_EHCI_USBCMD_FRL_SIZE   (2)
#define MASK_EHCI_USBCMD_FRL_SIZE  (0x3 << BIT_EHCI_USBCMD_FRL_SIZE)
#define EHCI_USBCMD_FRL_SIZE_1024  (0 << BIT_EHCI_USBCMD_FRL_SIZE)
#define EHCI_USBCMD_FRL_SIZE_512   (1 << BIT_EHCI_USBCMD_FRL_SIZE)
#define EHCI_USBCMD_FRL_SIZE_256   (2 << BIT_EHCI_USBCMD_FRL_SIZE)
/** \brief Host Controller Reset
    \details This is used by the software to reset the host controller.
**/
#define BIT_EHCI_USBCMD_HC_RESET  (1)
#define MASK_EHCI_USBCMD_HC_RESET (0x1 << BIT_EHCI_USBCMD_HC_RESET)
/** \brief Run/Stop
    \details When this is set to 1, the host controller proceeds with the execution of schedule.
        0 : Stop
        1 : Run
**/
#define BIT_EHCI_USBCMD_RS  (0)
#define MASK_EHCI_USBCMD_RS (0x1 << BIT_EHCI_USBCMD_RS)
//@}

/** Bit masks for the ECHI USBSTS register */
//@{
/** \brief USB Interrupt
    \details The host controller sets this to 1 upon completion of a USB transaction.
**/
#define BIT_EHCI_USBSTS_USB_INT  (0)
#define MASK_EHCI_USBSTS_USB_INT (0x1 << BIT_EHCI_USBSTS_USB_INT)
/** \brief USB Error Interrupt
    \details The host controller sets this to 1 when the completion of a USB
    transaction results in an error condition.
**/
#define BIT_EHCI_USBSTS_USBERR_INT  (1)
#define MASK_EHCI_USBSTS_USBERR_INT (0x1 << BIT_EHCI_USBSTS_USBERR_INT)
/** \brief Port Change Detect
    \details The host controller sets this to 1 when any port has a change bit
    transition from 0 to 1. In addition, this bit is loaded with the OR of all of
    the PORTSC change bits.
**/
#define BIT_EHCI_USBSTS_PO_CHG_DET  (2)
#define MASK_EHCI_USBSTS_PO_CHG_DET (0x1 << BIT_EHCI_USBSTS_PO_CHG_DET)
/** \brief Frame List Rollover
    \details The host controller sets this to 1 when the Frame List Index rolls over
    from its maximum value to zero.
**/
#define BIT_EHCI_USBSTS_FRL_ROL  (3)
#define MASK_EHCI_USBSTS_FRL_ROL (0x1 << BIT_EHCI_USBSTS_FRL_ROL)
/** \brief Host System Error
    \details The host controller sets this to 1 when a serious error occurs
    during a host system access involving the host controller module.
**/
#define BIT_EHCI_USBSTS_H_SYSERR  (4)
#define MASK_EHCI_USBSTS_H_SYSERR (0x1 << BIT_EHCI_USBSTS_H_SYSERR)
/** \brief Interrupt on Async Advance
    \details This bit indicates the assertion of interrupt on Async Advance Doorbell
**/
#define BIT_EHCI_USBSTS_INT_OAA  (5)
#define MASK_EHCI_USBSTS_INT_OAA (0x1 << BIT_EHCI_USBSTS_INT_OAA)
/** \brief Host Controller Halted
    \details This is a 0 whenever the Run/Stop bit is set to 1. The host controller sets
    this to 1 after it has stopped the section as a result of the Run/Stop bit being set to 0.
**/
#define BIT_EHCI_USBSTS_HCHalted  (12)
#define MASK_EHCI_USBSTS_HCHalted (0x1 << BIT_EHCI_USBSTS_HCHalted)
/** \brief Reclamation
    \details This is a read-only status bit, and used to detect an empty of the
    asynchronous schedule.
**/
#define BIT_EHCI_USBSTS_Reclamation  (13)
#define MASK_EHCI_USBSTS_Reclamation (0x1 << BIT_EHCI_USBSTS_Reclamation)
/** \brief Periodic Schedule Status
    \details This reports the actual status of the periodic schedule.
**/
#define BIT_EHCI_USBSTS_PSCH_STS  (14)
#define MASK_EHCI_USBSTS_PSCH_STS (0x1 << BIT_EHCI_USBSTS_PSCH_STS)
/** \brief Asynchronous Schedule Status
    \details This reports the actual status of the asynchronous schedule.
**/
#define BIT_EHCI_USBSTS_ASCH_STS  (15)
#define MASK_EHCI_USBSTS_ASCH_STS (0x1 << BIT_EHCI_USBSTS_ASCH_STS)
//@}

/** Bit masks for the ECHI USBINTR register */
//@{
/** \brief USB Interrupt Enable
    \details When this is 1 and the Host USBINT bit in the USBSTS register
    is 1, the host controller will issue an interrupt at the next interrupt
    threshold.
**/
#define BIT_EHCI_USBINTR_USB_INT_EN  (0)
#define MASK_EHCI_USBINTR_USB_INT_EN (0x1 << BIT_EHCI_USBINTR_USB_INT_EN)
/** \brief USB Error Interrupt Enable
    \details When this is 1 and the USBERRINT bit in the USBSTS register
    is 1, the host controller will issue an interrupt at the next interrupt
    threshold.
**/
#define BIT_EHCI_USBINTR_USBERR_INT_EN  (1)
#define MASK_EHCI_USBINTR_USBERR_INT_EN (0x1 << BIT_EHCI_USBINTR_USBERR_INT_EN)
/** \brief Port Change Interrupt Enable
    \details When this is 1 and the Port Change Detect bit in the USBSTS
    register is 1, the host controller will issue an interrupt at the next
    interrupt threshold.
**/
#define BIT_EHCI_USBINTR_PO_CHG_INT_EN  (2)
#define MASK_EHCI_USBINTR_PO_CHG_INT_EN (0x1 << BIT_EHCI_USBINTR_PO_CHG_INT_EN)
/** \brief Frame List Rollover Enable
    \details When this is 1 and the Frame List Rollover bit in the
    USBSTS register is 1, the host controller will issue an interrupt
    at the next interrupt threshold.
**/
#define BIT_EHCI_USBINTR_FRL_ROL_EN  (3)
#define MASK_EHCI_USBINTR_FRL_ROL_EN (0x1 << BIT_EHCI_USBINTR_FRL_ROL_EN)
/** \brief Host System Error Enable
    \details When this is 1 and the Host System Error Status bit in
    the USBSTS register is 1, the host controller will issue an interrupt
    at the next interrupt threshold.
**/
#define BIT_EHCI_USBINTR_H_SYSERR_EN  (4)
#define MASK_EHCI_USBINTR_H_SYSERR_EN (0x1 << BIT_EHCI_USBINTR_H_SYSERR_EN)
/** \brief Interrupt on Async Advance Enable
    \details When this is 1 and the Interrupt on Async Advance bit in the
    USBSTS register is 1, the host controller will issue an interrupt at
    the next interrupt threshold.
**/
#define BIT_EHCI_USBINTR_INT_OAA_EN  (5)
#define MASK_EHCI_USBINTR_INT_OAA_EN (0x1 << BIT_EHCI_USBINTR_INT_OAA_EN)
//@}

/** Bit masks for the ECHI FRINDEX register */
//@{
/** \brief Frame Index
    \details This is used by the host controller to index the frame into the
    Periodic Frame List. It is updated every 125us. It cannot be written unless
    the host controller is halted.
**/
#define BIT_EHCI_FRINDEX  (0)
#define MASK_EHCI_FRINDEX (0x3fff << BIT_EHCI_FRINDEX)
//@}

/** Bit masks for the ECHI PERIODICLISTBASE register */
//@{
/** \brief Periodic Frame List Base Address
    \details This 32-bit register contains the start address of the Periodic
    Frame List in the system memory. These form the upper 20 bits of the address.
**/
#define BIT_EHCI_PERI_BASADR  (12)
#define MASK_EHCI_PERI_BASADR (0xfffff << BIT_EHCI_PERI_BASADR)
//@}

/** Bit masks for the ECHI ASYNCLISTADDR register */
//@{
/** \brief Current Asynchronous List Address
    \details This 32-bit register contains the address of the next asynchronous
    queue head to be executed. These form the upper 27 bits of the address.
**/
#define BIT_EHCI_ASYNC_LADR   (5)
#define MASK_EHCI_ASYNC_LADRR (0x7ffffff << BIT_EHCI_ASYNC_LADR)
//@}

/** Bit masks for the ECHI PORTSC register */
//@{
/** \brief Test Force Enable
    \details When this is 1 the downstream facing port will be enabled in the HS mode.
    Then the Run/Stop bit must be transitioned to 1 in order to enable the transmission
    of the SOFs out of the port under test. This enables testing of the disconnect
    detection.
**/
#define BIT_EHCI_PORTSC_TST_FORCEEN  (16)
#define MASK_EHCI_PORTSC_TST_FORCEEN (0x1 << BIT_EHCI_PORTSC_TST_FORCEEN)
/** \brief Line Status
    \details These reflect the current logical levels of the D+ and D- signal lines.
**/
#define BIT_EHCI_PORTSC_LINE_STS  (10)
#define MASK_EHCI_PORTSC_LINE_STS (0x3 << BIT_EHCI_PORTSC_LINE_STS)
/** \brief Port Reset
    \details 1 : Port is in the reset state
        0 : Port is not in the reset state
        When the software writes a 1 to this bit, the bust reset sequence as defined
        in the USB specification will start. Software writes a 0 to this bit to
        terminate the bus reset sequence. Software must keep this bit at 1 long enough
        to ensure the reset sequence.
        Note : Before setting this bit, Run/Stop bit should be set to 0.
**/
#define BIT_EHCI_PORTSC_PO_RESET  (8)
#define MASK_EHCI_PORTSC_PO_RESET (0x1 << BIT_EHCI_PORTSC_PO_RESET)
/** \brief Port Suspend
    \details 1 : Port is in the suspend state
        0 : Port is not in the suspend state
        The Port Enable Bit and Suspend Bit of this register define the port state as
        follows:
        Port Enable Suspend    Port State
        0           X          Disabled
        1           0          Enabled
        1           1          Suspended
        At the suspended status, the downstream propagation of data is blocked on this
        port except for the port reset. While at the suspended state, the port is
        sensitive to resume detection.
        Writing a 0 to this bit is ignored. The host controller will unconditionally
        set this to 0 when:
        The software sets Force Port Resume bit to 0 (from 1)
        The software sets Port Reset bit to 1 (from 0)
        Note : Before setting this bit, Run/Stop bit should be set to 0.
**/
#define BIT_EHCI_PORTSC_PO_SUSP  (7)
#define MASK_EHCI_PORTSC_PO_SUSP (0x1 << BIT_EHCI_PORTSC_PO_SUSP)
/** \brief Force Port Resume
    \details 1 : Resume detection/driven on port.
        0 : No resume detected/driven on port.
        Software sets this to 1 to resume signalling. The host controller sets this to
        1 if a J-to-K transition is detected while the port is in the suspended state.
        When this transits to 1 for the detection of a J-to-K transition, the Port Change
        Detect bit in USBSTS register is also set to 1.
**/
#define BIT_EHCI_PORTSC_F_PO_RESM  (6)
#define MASK_EHCI_PORTSC_F_PO_RESM (0x1 << BIT_EHCI_PORTSC_F_PO_RESM)
/** \brief Port Enable/Disable Change
    \details 1 : Port enable/disable status has changed
        0 : No change
**/
#define BIT_EHCI_PORTSC_PO_EN_CHG  (3)
#define MASK_EHCI_PORTSC_PO_EN_CHG (0x1 << BIT_EHCI_PORTSC_PO_EN_CHG)
/** \brief Port Enable/Disable
    \details 1 : Enable
        0 : Disable
        Ports can only be enabled by the host controller as a part of the reset and enable. Software
        cannot enable a port by writing 1 to this bit.
**/
#define BIT_EHCI_PORTSC_PO_EN  (2)
#define MASK_EHCI_PORTSC_PO_EN (0x1 << BIT_EHCI_PORTSC_PO_EN)
/** \brief Connect Status Change
    \details 1 : Change in current connect status
        0 : No change
        This indicates a change has occurred in the current connect status of the port.
**/
#define BIT_EHCI_PORTSC_CONN_CHG  (1)
#define MASK_EHCI_PORTSC_CONN_CHG (0x1 << BIT_EHCI_PORTSC_CONN_CHG)
/** \brief Current Connect Status
    \details 1 : Device is presented on the port
    0 : No device is presented
    This reflects the current state of the port, and may not correspond directly to cause the
    Connect Status Change bit to be set. When TST_FORCEEN is set to 1, this signal is the output of
    u_hdiscon.
**/
#define BIT_EHCI_PORTSC_CONN_STS  (0)
#define MASK_EHCI_PORTSC_CONN_STS (0x1 << BIT_EHCI_PORTSC_CONN_STS)
//@}

/** Bit masks for the ECHI EOFTIME register */
//@{
/** \brief Transceiver Suspend Mode
    \details Active low. Places the transceiver in the suspend mode that
        draws the minimal power from the power supplies. This is part of the
        power management.
**/
#define BIT_EHCI_EOFTIME_U_SUSP_N  (6)
#define MASK_EHCI_EOFTIME_U_SUSP_N (0x1 << BIT_EHCI_EOFTIME_U_SUSP_N)
/** \brief EOF 2 Timing Points
    \details Control EOF2 timing point before next SOF.
**/
#define BIT_EHCI_EOFTIME_EOF2_Time  (4)
#define MASK_EHCI_EOFTIME_EOF2_Time (0x3 << BIT_EHCI_EOFTIME_EOF2_Time)
/** \brief EOF 1 Timing Points
    \details Control EOF1 timing point before next SOF.
        This value should be adjusted according to the maximum packet size.
**/
#define BIT_EHCI_EOFTIME_EOF1_Time  (2)
#define MASK_EHCI_EOFTIME_EOF1_Time (0x3 << BIT_EHCI_EOFTIME_EOF1_Time)
/** \brief Asynchronous Schedule Sleep Timer
    \details Controls the Asynchronous Schedule sleep timer.
        0x0 5 us
        0x1 10 us
        0x2 15 us
        0x3 20 us
**/
#define BIT_EHCI_EOFTIME_ASYN_SCH_SLPT  (0)
#define MASK_EHCI_EOFTIME_ASYN_SCH_SLPT (0x3 << BIT_EHCI_EOFTIME_ASYN_SCH_SLPT)
//@}

/** Bit masks for the ECHI BUSCTRL register */
//@{
/** \brief Host Speed Type
    \details Report Host Speed Type.
        0x0 : FS
        0x1 : LS
        0x2 : HS
        0x3 : Reserved
        WARNING: This differs from the values in the QH EPS field.
**/
#define BIT_EHCI_BUSCTRL_HOST_SPD_TYP  (9)
#define MASK_EHCI_BUSCTRL_HOST_SPD_TYP (0x3 << BIT_EHCI_BUSCTRL_HOST_SPD_TYP)
#define EHCI_BUSCTRL_HOST_SPD_TYP_HS   (0x2 << BIT_EHCI_BUSCTRL_HOST_SPD_TYP)
#define EHCI_BUSCTRL_HOST_SPD_TYP_FS   (0x0 << BIT_EHCI_BUSCTRL_HOST_SPD_TYP)
#define EHCI_BUSCTRL_HOST_SPD_TYP_LS   (0x1 << BIT_EHCI_BUSCTRL_HOST_SPD_TYP)
/** \brief VBUS Valid
    \details When the voltage on the VBUS is above the valid VBUS threshold,
        this signal is valid when the u_vbusvld signal is connected.
**/
#define BIT_EHCI_BUSCTRL_VBUS_VLD  (8)
#define MASK_EHCI_BUSCTRL_VBUS_VLD (0x1 << BIT_EHCI_BUSCTRL_VBUS_VLD)
/** \brief VBUS Off
    \details This controls the voltage on the VBUS_ON/OFF.
        0 : VBUS on
        1 : VBUS off
**/
#define BIT_EHCI_BUSCTRL_VBUS_OFF  (4)
#define MASK_EHCI_BUSCTRL_VBUS_OFF (0x1 << BIT_EHCI_BUSCTRL_VBUS_OFF)
/** \brief Half Speed Enable
    \details 1 : FIFO controller asserts the ACK to the DMA once for every 2 clock cycles
        0 : FIFO controller asserts the ACK to the DMA continuously
**/
#define BIT_EHCI_BUSCTRL_HALF_SPEED  (2)
#define MASK_EHCI_BUSCTRL_HALF_SPEED (0x1 << BIT_EHCI_BUSCTRL_HALF_SPEED)
/** \brief HDISCON Filter Select
    \details Select a timer to filter out oise on HDISCON from the UTMI+
        0 : Approximately 135 us
        1 : Approximately 270 us
**/
#define BIT_EHCI_BUSCTRL_HDISCON_FLT_SEL  (1)
#define MASK_EHCI_BUSCTRL_HDISCON_FLT_SEL (0x1 << BIT_EHCI_BUSCTRL_HDISCON_FLT_SEL)
/** \brief VBUS Valid Filter Select
    \details Select a timer to filter out oise on VBUS_VLD  from the UTMI+
        0 : Approximately 135 us
        1 : Approximately 472 us
**/
#define BIT_EHCI_BUSCTRL_VBUS_FLT_SEL  (0)
#define MASK_EHCI_BUSCTRL_VBUS_FLT_SEL (0x1 << BIT_EHCI_BUSCTRL_VBUS_FLT_SEL)
//@}

/** Bit masks for the ECHI BUSINTSTATUS register */
//@{
/** \brief DMA Error Interrupt
    \details This indicates that a DMA operation cannot be finished normally,
        and an error has been received.
        It can only be cleared by software and is not affected by USB bus reset.
**/
#define BIT_EHCI_BUSINTSTATUS_DMA_ERROR  (4)
#define MASK_EHCI_BUSINTSTATUS_DMA_ERROR (0x1 << BIT_EHCI_BUSINTSTATUS_DMA_ERROR)
/** \brief DMA Completion Interrupt
    \details This indicates that a DMA operation has terminated normally.
        It can only be cleared by software and is not affected by USB bus reset.
**/
#define BIT_EHCI_BUSINTSTATUS_DMA_CMPLT  (3)
#define MASK_EHCI_BUSINTSTATUS_DMA_CMPLT (0x1 << BIT_EHCI_BUSINTSTATUS_DMA_CMPLT)
/** \brief Device Plug Remove
    \details This is set to 1 when a device is removed.
**/
#define BIT_EHCI_BUSINTSTATUS_DPLGRMV  (2)
#define MASK_EHCI_BUSINTSTATUS_DPLGRMV (0x1 << BIT_EHCI_BUSINTSTATUS_DPLGRMV)
/** \brief Over Current Detection
    \details This is set to 1 when the Vbus signal does not reach the VBUS_VLD
        signal within the expected time.
**/
#define BIT_EHCI_BUSINTSTATUS_OVC  (1)
#define MASK_EHCI_BUSINTSTATUS_OVC (0x1 << BIT_EHCI_BUSINTSTATUS_OVC)
/** \brief VBUS Error
    \details This is set to 1 when the Bus Monitor state machine moves to the
        VBUS_ERROR state.
**/
#define BIT_EHCI_BUSINTSTATUS_VBUS_ERR  (0)
#define MASK_EHCI_BUSINTSTATUS_VBUS_ERR (0x1 << BIT_EHCI_BUSINTSTATUS_VBUS_ERR)
//@}

/** Bit masks for the ECHI BUSINTEN register */
//@{
/** \brief DMA Error Interrupt enable
    \details
**/
#define BIT_EHCI_BUSINTEN_DMA_ERROR_EN  (0)
#define MASK_EHCI_BUSINTEN_DMA_ERROR_EN (0x1 << BIT_EHCI_BUSINTEN_DMA_ERROR_EN)
/** \brief DMA Completion Interrupt enable
    \details
**/
#define BIT_EHCI_BUSINTEN_DMA_CMPLT_EN  (0)
#define MASK_EHCI_BUSINTEN_DMA_CMPLT_EN (0x1 << BIT_EHCI_BUSINTEN_DMA_CMPLT_EN)
/** \brief Device Plug Remove Interrupt enable
    \details
**/
#define BIT_EHCI_BUSINTEN_DPLGRMV_EN  (0)
#define MASK_EHCI_BUSINTEN_DPLGRMV_EN (0x1 << BIT_EHCI_BUSINTEN_DPLGRMV_EN)
/** \brief Over Current Detection Interrupt enable
    \details
**/
#define BIT_EHCI_BUSINTEN_OVC_EN  (0)
#define MASK_EHCI_BUSINTEN_OVC_EN (0x1 << BIT_EHCI_BUSINTEN_OVC_EN)
/** \brief VBUS Error Interrupt enable
    \details
**/
#define BIT_EHCI_BUSINTEN_VBUS_ERR_EN  (0)
#define MASK_EHCI_BUSINTEN_VBUS_ERR_EN (0x1 << BIT_EHCI_BUSINTEN_VBUS_ERR_EN)
//@}

/** Bit masks for the ECHI DMACTRLPMSET1 register */
//@{
/** \brief DMA Length
    \details The total number of bytes the DMA controller will move.
        The maximum length is 1023B.
**/
#define BIT_EHCI_DMACTRLPMSET1_DMA_LEN  (0)
#define MASK_EHCI_DMACTRLPMSET1_DMA_LEN (0x1 << BIT_EHCI_DMACTRLPMSET1_DMA_LEN)
/** \brief DMA IO to IO
    \details This restrains the DMA controller from toggling the address.
        This is set when the DMA target is not a system memory but an I/O device.
        If this is set to 1, the DMA_LEN must be an integer multiple of DWORD and
        the DMA_MADDR must be aligned to the boundary of DWORD.
**/
#define BIT_EHCI_DMACTRLPMSET1_DMA_IO  (0)
#define MASK_EHCI_DMACTRLPMSET1_DMA_IO (0x1 << BIT_EHCI_DMACTRLPMSET1_DMA_IO)
/** \brief DMA Type
    \details 0 : FIFO to Memory
        1 : Memory to FIFO
**/
#define BIT_EHCI_DMACTRLPMSET1_DMA_TYPE  (0)
#define MASK_EHCI_DMACTRLPMSET1_DMA_TYPE (0x1 << BIT_EHCI_DMACTRLPMSET1_DMA_TYPE)
/** \brief DMA Start
    \details This informs the DMA controller to initiate the DMA transfer.
        This is set to start the transfer and cleared when the DMA operation is
        completed.
        This bit cannot be cleared by software and can only be cleared by hardware
        in the case of either DMA completion or DMA error.
        If DMA_LEN and DMA_START are set at the same time, the DMA_LEN will be
        effective immediately.
**/
#define BIT_EHCI_DMACTRLPMSET1_DMA_START  (0)
#define MASK_EHCI_DMACTRLPMSET1_DMA_START (0x1 << BIT_EHCI_DMACTRLPMSET1_DMA_START)
//@}

/** Bit masks for the ECHI DMACTRLPMSET2 register */
//@{
/** \brief DMA Memory Address
    \details This is the start address of memory for DMA transfer.
**/
#define BIT_EHCI_DMACTRLPMSET2_DMA_MADDR  (0)
#define MASK_EHCI_DMACTRLPMSET2_DMA_MADDR (0xffffffff << BIT_EHCI_DMACTRLPMSET2_DMA_MADDR)
//@}

/** Bit masks for the ECHI QUEUE ELEMENT TRANSFER DESCRIPTOR structure */
//@{
/** \brief Terminate (DWORD 0 and DWORD 1)
    \details This is the last Queue Transfer Descriptor in the list. The next pointer is invalid.
**/
#define BIT_EHCI_QUEUE_TD_TERMINATE  (0)
#define MASK_EHCI_QUEUE_TD_TERMINATE (1 << BIT_EHCI_QUEUE_TD_TERMINATE)
/** \brief Next Queue TD Pointer (DWORD 0 and DWORD 1)
    \details This points to the next structure in the list.
**/
#define BIT_EHCI_QUEUE_TD_NEXT  (5)
#define MASK_EHCI_QUEUE_TD_NEXT (0x7ffffff << BIT_EHCI_QUEUE_TD_NEXT)
/** \brief Data Toggle (DWORD 2)
    \details Specifies the data toggle sequence.
**/
#define BIT_EHCI_QUEUE_TD_TOKEN_TOGGLE  (31)
#define MASK_EHCI_QUEUE_TD_TOKEN_TOGGLE (1 << BIT_EHCI_QUEUE_TD_TOKEN_TOGGLE)
/** \brief Total Bytes to Transfer (DWORD 2)
    \details Specifies the total number of bytes to transfer.
**/
#define BIT_EHCI_QUEUE_TD_TOKEN_TOTAL_TO_TRANSFER  (16)
#define MASK_EHCI_QUEUE_TD_TOKEN_TOTAL_TO_TRANSFER (0x7fff << BIT_EHCI_QUEUE_TD_TOKEN_TOTAL_TO_TRANSFER)
#define EHCI_QUEUE_TD_TOKEN_TOTAL_TO_TRANSFER(A)   (((A) << BIT_EHCI_QUEUE_TD_TOKEN_TOTAL_TO_TRANSFER) & MASK_EHCI_QUEUE_TD_TOKEN_TOTAL_TO_TRANSFER)
/** \brief Interrupt on Complete (DWORD 2)
    \details Interrupt on completion of transfer.
**/
#define BIT_EHCI_QUEUE_TD_TOKEN_IOC  (15)
#define MASK_EHCI_QUEUE_TD_TOKEN_IOC (1 << BIT_EHCI_QUEUE_TD_TOKEN_IOC)
/** \brief Current Page (DWORD 2)
    \details Index into the current page of qTD buffer pointer list.
**/
#define BIT_EHCI_QUEUE_TD_TOKEN_C_PAGE  (12)
#define MASK_EHCI_QUEUE_TD_TOKEN_C_PAGE (7 << BIT_EHCI_QUEUE_TD_TOKEN_C_PAGE)
/** \brief Error Counter (DWORD 2)
    \details Count of consecutive errors when processing this qTD. If set to a non-zero
    value then the controller will halt the endpoint if a transition from 1 to 0 is
    detected. Set to zero to ignore errors and retry forever.
**/
#define BIT_EHCI_QUEUE_TD_TOKEN_CERR  (10)
#define MASK_EHCI_QUEUE_TD_TOKEN_CERR (3 << BIT_EHCI_QUEUE_TD_TOKEN_CERR)
/** \brief PID Code (DWORD 2)
    \details Describes the encoding of the token used for this qTD.
    Valid values are : 00b OUT Token; 01b IN Token; 10b SETUP Token.
**/
#define BIT_EHCI_QUEUE_TD_TOKEN_PID   (8)
#define MASK_EHCI_QUEUE_TD_TOKEN_PID  (3 << BIT_EHCI_QUEUE_TD_TOKEN_PID)
#define EHCI_QUEUE_TD_TOKEN_PID_OUT   (0 << BIT_EHCI_QUEUE_TD_TOKEN_PID)
#define EHCI_QUEUE_TD_TOKEN_PID_IN    (1 << BIT_EHCI_QUEUE_TD_TOKEN_PID)
#define EHCI_QUEUE_TD_TOKEN_PID_SETUP (2 << BIT_EHCI_QUEUE_TD_TOKEN_PID)
/** \brief Status (DWORD 2)
    \details Reports the status of the qTD.
    Active - enable execution of the transactions in this qTD by the controller.
    Halted - set to 1 when an error occurs during the transaction.
    Data buffer error - host controller unable to keep up with incoming data or
         unable to supply outgoing data fast enough.
    Babble detected - also sets the halted bit.
    Transaction error - set to one when a device fails to respond correctly.
    Missed micro-frame.
    Split transaction state.
    Ping state ERR.
**/
#define BIT_EHCI_QUEUE_TD_TOKEN_STATUS                    (0)
#define MASK_EHCI_QUEUE_TD_TOKEN_STATUS                   (0xff << BIT_EHCI_QUEUE_TD_TOKEN_STATUS)
#define BIT_EHCI_QUEUE_TD_TOKEN_STATUS_ACTIVE             (7)
#define EHCI_QUEUE_TD_TOKEN_STATUS_ACTIVE                 (1 << BIT_EHCI_QUEUE_TD_TOKEN_STATUS_ACTIVE)
#define BIT_EHCI_QUEUE_TD_TOKEN_STATUS_HALTED             (6)
#define EHCI_QUEUE_TD_TOKEN_STATUS_HALTED                 (1 << BIT_EHCI_QUEUE_TD_TOKEN_STATUS_HALTED)
#define BIT_EHCI_QUEUE_TD_TOKEN_STATUS_DATA_BUF_ERR       (5)
#define EHCI_QUEUE_TD_TOKEN_STATUS_DATA_BUF_ERR           (1 << BIT_EHCI_QUEUE_TD_TOKEN_STATUS_DATA_BUF_ERR)
#define BIT_EHCI_QUEUE_TD_TOKEN_STATUS_BABBLE             (4)
#define EHCI_QUEUE_TD_TOKEN_STATUS_BABBLE                 (1 << BIT_EHCI_QUEUE_TD_TOKEN_STATUS_BABBLE)
#define BIT_EHCI_QUEUE_TD_TOKEN_STATUS_XACTERR            (3)
#define EHCI_QUEUE_TD_TOKEN_STATUS_XACTERR                (1 << BIT_EHCI_QUEUE_TD_TOKEN_STATUS_XACTERR)
#define BIT_EHCI_QUEUE_TD_TOKEN_STATUS_MISSED_MICROFRAME  (2)
#define EHCI_QUEUE_TD_TOKEN_STATUS_MISSED_MICROFRAME      (1 << BIT_EHCI_QUEUE_TD_TOKEN_STATUS_MISSED_MICROFRAME)
#define BIT_EHCI_QUEUE_TD_TOKEN_STATUS_SPLITX             (1)
#define EHCI_QUEUE_TD_TOKEN_STATUS_SPLITX                 (1 << BIT_EHCI_QUEUE_TD_TOKEN_STATUS_SPLITX)
#define BIT_EHCI_QUEUE_TD_TOKEN_STATUS_P_ERR              (0)
#define EHCI_QUEUE_TD_TOKEN_STATUS_P_ERR                  (1 << BIT_EHCI_QUEUE_TD_TOKEN_STATUS_P_ERR)
//@}
/** \brief Current Offset (DWORD 4)
    \details Lower 12 bits of first Buffer Pointer register containing the
    current offset within the active buffer.
**/
#define BIT_EHCI_QUEUE_TD_BUFFER_CURRENT_OFFSET           (0)
#define MASK_EHCI_QUEUE_TD_BUFFER_CURRENT_OFFSET          (0xFFF << BIT_EHCI_QUEUE_TD_BUFFER_CURRENT_OFFSET)
#define BIT_EHCI_QUEUE_TD_BUFFER_POINTER                  (12)
#define MASK_EHCI_QUEUE_TD_BUFFER_CURRENT_POINTER         (0xFFFFF << BIT_EHCI_QUEUE_TD_BUFFER_POINTER)

/** Bit masks for the ECHI QUEUE HEAD structure */
//@{
/** \brief Terminate (DWORD 0)
    \details This is the last Queue Header in the list. The next pointer is invalid.
**/
#define BIT_EHCI_QUEUE_HEAD_TERMINATE  (0)
#define MASK_EHCI_QUEUE_HEAD_TERMINATE (1 << BIT_EHCI_QUEUE_HEAD_TERMINATE)
/** \brief Horizontal Link Pointer (DWORD 0)
    \details This points to the next structure in the list.
**/
#define BIT_EHCI_QUEUE_HEAD_NEXT  (5)
#define MASK_EHCI_QUEUE_HEAD_NEXT (0x7ffffff << BIT_EHCI_QUEUE_HEAD_NEXT)
/** \brief Type (DWORD 0)
    \details Specifies the type of the next structure in the list.
**/
#define BIT_EHCI_QUEUE_HEAD_TYPE  (1)
#define MASK_EHCI_QUEUE_HEAD_TYPE (3 << BIT_EHCI_QUEUE_HEAD_TYPE)
#define MASK_EHCI_QUEUE_HEAD_TYPE_iTD (0 << BIT_EHCI_QUEUE_HEAD_TYPE)
#define MASK_EHCI_QUEUE_HEAD_TYPE_QH (1 << BIT_EHCI_QUEUE_HEAD_TYPE)
#define MASK_EHCI_QUEUE_HEAD_TYPE_siTD (2 << BIT_EHCI_QUEUE_HEAD_TYPE)
#define MASK_EHCI_QUEUE_HEAD_TYPE_FSTN (3 << BIT_EHCI_QUEUE_HEAD_TYPE)
/** \brief Device Type (DWORD 1)
    \details Specifies the device address.
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CHAR_ADDRESS  (0)
#define MASK_EHCI_QUEUE_HEAD_EP_CHAR_ADDRESS (0x7F << BIT_EHCI_QUEUE_HEAD_EP_CHAR_ADDRESS)
/** \brief Inactive on Next Transaction (DWORD 1)
    \details Request that the host set the device to becomes inactive.
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CHAR_INACTIVE  (7)
#define MASK_EHCI_QUEUE_HEAD_EP_CHAR_INACTIVE (1 << BIT_EHCI_QUEUE_HEAD_EP_CHAR_INACTIVE)
/** \brief Device Endpoint Number (DWORD 1)
    \details Selects the endpoint on the device to address.
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CHAR_ENDPOINT  (8)
#define MASK_EHCI_QUEUE_HEAD_EP_CHAR_ENDPOINT (0x0f << BIT_EHCI_QUEUE_HEAD_EP_CHAR_ENDPOINT)
/** \brief Device Endpoint Speed (DWORD 1)
    \details Selects the endpoint speed on the device.
        00b Full-Speed (12Mbs)
        01b Low-Speed (1.5Mbs)
        10b High-Speed (480 Mb/s)
        11b Reserved
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CHAR_EPS   (12)
#define MASK_EHCI_QUEUE_HEAD_EP_CHAR_EPS  (3 << BIT_EHCI_QUEUE_HEAD_EP_CHAR_EPS)
#define EHCI_QUEUE_HEAD_EP_CHAR_EPS_FS    (0 << BIT_EHCI_QUEUE_HEAD_EP_CHAR_EPS)
#define EHCI_QUEUE_HEAD_EP_CHAR_EPS_LS    (1 << BIT_EHCI_QUEUE_HEAD_EP_CHAR_EPS)
#define EHCI_QUEUE_HEAD_EP_CHAR_EPS_HS    (2 << BIT_EHCI_QUEUE_HEAD_EP_CHAR_EPS)
/** \brief Device Endpoint Data Toggle (DWORD 1)
    \details Selects the endpoint data toggle.
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CHAR_DTC  (14)
#define MASK_EHCI_QUEUE_HEAD_EP_CHAR_DTC (1 << BIT_EHCI_QUEUE_HEAD_EP_CHAR_DTC)
/** \brief Device Endpoint Reclamation Flag (DWORD 1)
    \details Selects the endpoint reclamation behaviour.
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CHAR_H  (15)
#define MASK_EHCI_QUEUE_HEAD_EP_CHAR_H (1 << BIT_EHCI_QUEUE_HEAD_EP_CHAR_H)
/** \brief Device Endpoint Maximum Packet Length (DWORD 1)
    \details Selects the endpoint maximum packet length.
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CHAR_MAX_PACKET  (16)
#define MASK_EHCI_QUEUE_HEAD_EP_CHAR_MAX_PACKET (0x7ff << BIT_EHCI_QUEUE_HEAD_EP_CHAR_MAX_PACKET)
/** \brief Device Control Endpoint Flag (DWORD 1)
    \details Selects the endpoint as a control endpoint.
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CHAR_C  (27)
#define MASK_EHCI_QUEUE_HEAD_EP_CHAR_C (1 << BIT_EHCI_QUEUE_HEAD_EP_CHAR_C)
/** \brief Device Control Endpoint NAK Count Released (DWORD 1)
    \details Selects the value to use when reloading the NAK counter field.
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CHAR_RL  (28)
#define MASK_EHCI_QUEUE_HEAD_EP_CHAR_RL (0x0f << BIT_EHCI_QUEUE_HEAD_EP_CHAR_RL)
/** \brief High Bandwidth Pipe Multiplier (DWORD 2)
    \details Selects the number of transactions issued per endpoint per micro frame.
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CAPAB_MULT  (30)
#define MASK_EHCI_QUEUE_HEAD_EP_CAPAB_MULT (3 << BIT_EHCI_QUEUE_HEAD_EP_CAPAB_MULT)
/** \brief Hub Port Number (DWORD 2)
    \details Selects the hub port number for HS and LS devices.
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CAPAB_HUB_PORT  (23)
#define MASK_EHCI_QUEUE_HEAD_EP_CAPAB_HUB_PORT (0x7f << BIT_EHCI_QUEUE_HEAD_EP_CAPAB_HUB_PORT)
/** \brief Hub Address (DWORD 2)
    \details Selects the hub address for HS and LS devices.
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CAPAB_HUB_ADDR  (16)
#define MASK_EHCI_QUEUE_HEAD_EP_CAPAB_HUB_ADDR (0x7f << BIT_EHCI_QUEUE_HEAD_EP_CAPAB_HUB_ADDR)
/** \brief Split Completion Mask (DWORD 2)
    \details Selects the micro frame for executing a complete-split transaction on FS and LS devices.
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CAPAB_UFRAME_CMASK  (8)
#define MASK_EHCI_QUEUE_HEAD_EP_CAPAB_UFRAME_CMASK (0xff << BIT_EHCI_QUEUE_HEAD_EP_CAPAB_UFRAME_CMASK)
/** \brief Interrupt Schedule Mask (DWORD 2)
    \details Set to zero when endpoint it in the Asynch schedule and non-zero for an interrupt endpoint.
**/
#define BIT_EHCI_QUEUE_HEAD_EP_CAPAB_UFRAME_SMASK  (0)
#define MASK_EHCI_QUEUE_HEAD_EP_CAPAB_UFRAME_SMASK (0xff << BIT_EHCI_QUEUE_HEAD_EP_CAPAB_UFRAME_SMASK)
//@}

/**
  @name    Definitions for ECHI data structures.
  @details NOTE: These structure are EHCI defined structure and must be located in the USBH memory
                 space.
                 These are used by the library and will not be required to be used in the API.
*/
//@{

/** Bit masks for the High Speed ECHI ISOCHRONOUS TRANSFER DESCRIPTOR structure */
//@{
/** \brief Terminate (DWORD 0 and DWORD 1)
    \details This is the last Isochronous Transfer Descriptor in the list. The next pointer is
             invalid.
**/
#define BIT_EHCI_ISO_TD_TERMINATE  (0)
#define MASK_EHCI_ISO_TD_TERMINATE (1 << BIT_EHCI_ISO_TD_TERMINATE)
/** \brief Next iTD Pointer (DWORD 0)
    \details This points to the next structure in the list.
**/
#define BIT_EHCI_ISO_TD_NEXT  (5)
#define MASK_EHCI_ISO_TD_NEXT (0x7ffffff << BIT_EHCI_ISO_TD_NEXT)
/** \brief Type (DWORD 0)
    \details Specifies the type of the next structure in the list.
**/
#define BIT_EHCI_ISO_TD_TYPE  (1)
#define MASK_EHCI_ISO_TD_TYPE (3 << BIT_EHCI_ISO_TD_TYPE)
#define MASK_EHCI_ISO_TD_TYPE_iTD (0 << BIT_EHCI_ISO_TD_TYPE)
#define MASK_EHCI_ISO_TD_TYPE_QH (1 << BIT_EHCI_ISO_TD_TYPE)
#define MASK_EHCI_ISO_TD_TYPE_siTD (2 << BIT_EHCI_ISO_TD_TYPE)
#define MASK_EHCI_ISO_TD_TYPE_FSTN (3 << BIT_EHCI_ISO_TD_TYPE)
/** \brief Transaction Status and Control Lists (DWORDS 1 to 8)
**/
/** \brief Status (DWORDS 1 to 8)
    \details Reports the status of the iTD.
    Active - enable execution of the transactions in this qTD by the controller.
    Data buffer error - host controller unable to keep up with incoming data or
         unable to supply outgoing data fast enough.
    Babble detected - also sets the halted bit.
    Transaction error - set to one when a device fails to respond correctly.
**/
#define BIT_EHCI_ISO_TD_STATUS              (28)
#define MASK_EHCI_ISO_TD_STATUS             (0xf << BIT_EHCI_ISO_TD_STATUS)
#define BIT_EHCI_ISO_TD_STATUS_ACTIVE       (31)
#define EHCI_ISO_TD_STATUS_ACTIVE           (1 << BIT_EHCI_ISO_TD_STATUS_ACTIVE)
#define BIT_EHCI_ISO_TD_STATUS_DATA_BUF_ERR (30)
#define EHCI_ISO_TD_STATUS_DATA_BUF_ERR     (1 << BIT_EHCI_ISO_TD_STATUS_DATA_BUF_ERR)
#define BIT_EHCI_ISO_TD_STATUS_BABBLE       (29)
#define EHCI_ISO_TD_STATUS_BABBLE           (1 << BIT_EHCI_ISO_TD_STATUS_BABBLE)
#define BIT_EHCI_ISO_TD_STATUS_XACTERR      (28)
#define EHCI_ISO_TD_STATUS_XACTERR          (1 << BIT_EHCI_ISO_TD_STATUS_XACTERR)
//@}
/** \brief Transaction Length (DWORDS 1 to 8)
    \details Specifies the total number of bytes to transfer.
**/
#define BIT_EHCI_ISO_TD_TRANSACTION_LENGTH   (16)
#define MASK_EHCI_ISO_TD_TRANSACTION_LENGTH  (0xfff << BIT_EHCI_ISO_TD_TRANSACTION_LENGTH)
#define EHCI_ISO_TD_TRANSACTION_LENGTH(A)    (((A) << BIT_EHCI_ISO_TD_TRANSACTION_LENGTH ) & MASK_EHCI_ISO_TD_TRANSACTION_LENGTH)
/** \brief Interrupt on Complete (DWORDS 1 to 8)
    \details Interrupt on completion of transfer.
**/
#define BIT_EHCI_ISO_TD_IOC  (15)
#define MASK_EHCI_ISO_TD_IOC (1 << BIT_EHCI_ISO_TD_IOC)
/** \brief Page Select (DWORDS 1 to 8)
    \details Entry in Buffer Page Pointer List to use for buffer address.
**/
#define BIT_EHCI_ISO_TD_PG  (12)
#define MASK_EHCI_ISO_TD_PG (0x7 << BIT_EHCI_ISO_TD_PG)
/** \brief Transaction Offset (DWORDS 1 to 8)
    \details Offset within buffer pointer to by Page Select register.
**/
#define BIT_EHCI_ISO_TD_OFFSET  (0)
#define MASK_EHCI_ISO_TD_OFFSET (0xfff << BIT_EHCI_ISO_TD_OFFSET)
/** \brief Transaction Offset (DWORDS 9 to 15)
    \details Buffer Pointer (4Kb aligned).
**/
#define BIT_EHCI_ISO_TD_BUFFER_POINTER  (12)
#define MASK_EHCI_ISO_TD_BUFFER_POINTER (0xfffff << BIT_EHCI_ISO_TD_BUFFER_POINTER)
/** \brief Endpoint Number (DWORD 9)
    \details Endpoint number.
**/
#define BIT_EHCI_ISO_TD_EP_NUMBER (8)
#define MASK_EHCI_ISO_TD_EP_NUMBER (0xf << BIT_EHCI_ISO_TD_EP_NUMBER)
/** \brief Device Address (DWORD 9)
    \details Device address.
**/
#define BIT_EHCI_ISO_TD_ADDRESS  (0)
#define MASK_EHCI_ISO_TD_ADDRESS (0x7f << BIT_EHCI_ISO_TD_ADDRESS)
/** \brief Direction (DWORD 10)
    \details Endpoint direction.
**/
#define BIT_EHCI_ISO_TD_DIRECTION  (11)
#define MASK_EHCI_ISO_TD_DIRECTION (1 << BIT_EHCI_ISO_TD_DIRECTION)
/** \brief Max Packet Size (DWORD 10)
    \details Endpoint Maximum Packet Size.
**/
#define BIT_EHCI_ISO_TD_MAX_PACKET  (0)
#define MASK_EHCI_ISO_TD_MAX_PACKET (0x7ff << BIT_EHCI_ISO_TD_MAX_PACKET)
/** \brief Multi (DWORD 11)
    \details Issue multiple transactions per micro-frame.
**/
#define BIT_EHCI_ISO_TD_MULTI  (0)
#define MASK_EHCI_ISO_TD_MULTI (0x3 << BIT_EHCI_ISO_TD_MULTI)

/** Bit masks for the Full Speed ECHI ISOCHRONOUS TRANSFER DESCRIPTOR structure */
//@{
/** \brief Terminate (DWORD 0 and DWORD 1)
    \details This is the last Isochronous Transfer Descriptor in the list. The next pointer is invalid.
**/
#define BIT_EHCI_SPLIT_ISO_TD_TERMINATE  (0)
#define MASK_EHCI_SPLIT_ISO_TD_TERMINATE (1 << BIT_EHCI_SPLIT_ISO_TD_TERMINATE)
/** \brief Next iTD Pointer (DWORD 0)
    \details This points to the next structure in the list.
**/
#define BIT_EHCI_SPLIT_ISO_TD_NEXT  (5)
#define MASK_EHCI_SPLIT_ISO_TD_NEXT (0x7ffffff << BIT_EHCI_SPLIT_ISO_TD_NEXT)
/** \brief Type (DWORD 0)
    \details Specifies the type of the next structure in the list.
**/
#define BIT_EHCI_SPLIT_ISO_TD_TYPE       (1)
#define MASK_EHCI_SPLIT_ISO_TD_TYPE      (3 << BIT_EHCI_SPLIT_ISO_TD_TYPE)
#define MASK_EHCI_SPLIT_ISO_TD_TYPE_iTD  (0 << BIT_EHCI_SPLIT_ISO_TD_TYPE)
#define MASK_EHCI_SPLIT_ISO_TD_TYPE_QH   (1 << BIT_EHCI_SPLIT_ISO_TD_TYPE)
#define MASK_EHCI_SPLIT_ISO_TD_TYPE_siTD (2 << BIT_EHCI_SPLIT_ISO_TD_TYPE)
#define MASK_EHCI_SPLIT_ISO_TD_TYPE_FSTN (3 << BIT_EHCI_SPLIT_ISO_TD_TYPE)

/** \brief Direction (DWORD 1)
    \details Endpoint direction.
**/
#define BIT_EHCI_SPLIT_ISO_TD_DIRECTION  (31)
#define MASK_EHCI_SPLIT_ISO_TD_DIRECTION (1 << BIT_EHCI_SPLIT_ISO_TD_DIRECTION)
/** \brief Port Number (DWORD 1)
    \details Port number.
**/
#define BIT_EHCI_SPLIT_ISO_TD_PORT_NUMBER  (24)
#define MASK_EHCI_SPLIT_ISO_TD_PORT_NUMBER (0x3f << BIT_EHCI_SPLIT_ISO_TD_EP_NUMBER)
/** \brief Hub Address (DWORD 1)
    \details Hub Address.
**/
#define BIT_EHCI_SPLIT_ISO_TD_HUB_ADDR  (16)
#define MASK_EHCI_SPLIT_ISO_TD_HUB_ADDR (0x7f << BIT_EHCI_SPLIT_ISO_TD_HUB_ADDR)
/** \brief Endpoint Number (DWORD 1)
    \details Endpoint number.
**/
#define BIT_EHCI_SPLIT_ISO_TD_EP_NUMBER  (8)
#define MASK_EHCI_SPLIT_ISO_TD_EP_NUMBER (0xf << BIT_EHCI_SPLIT_ISO_TD_EP_NUMBER)
/** \brief Device Address (DWORD 1)
    \details Device address.
**/
#define BIT_EHCI_SPLIT_ISO_TD_ADDRESS  (0)
#define MASK_EHCI_SPLIT_ISO_TD_ADDRESS (0x7f << BIT_EHCI_SPLIT_ISO_TD_ADDRESS)
/** \brief Split Completion Mask (DWORD 2)
    \details Selects the micro frame for executing a complete-split transaction on FS and LS devices.
**/
#define BIT_EHCI_SPLIT_ISO_TD_UFRAME_CMASK (8)
#define MASK_EHCI_SPLIT_ISO_TD_UFRAME_CMASK (0xff << BIT_EHCI_SPLIT_ISO_TD_UFRAME_CMASK)
/** \brief Interrupt Schedule Mask (DWORDS 2 and 3)
    \details Set to zero when endpoint it in the Async schedule and non-zero for an interrupt endpoint.
**/
#define BIT_EHCI_SPLIT_ISO_TD_UFRAME_SMASK  (0)
#define MASK_EHCI_SPLIT_ISO_TD_UFRAME_SMASK (0xff << BIT_EHCI_SPLIT_ISO_TD_UFRAME_SMASK)
/** \brief Interrupt on Complete (DWORD 3)
    \details Interrupt on completion of transfer.
**/
#define BIT_EHCI_SPLIT_ISO_TD_IOC  (31)
#define MASK_EHCI_SPLIT_ISO_TD_IOC (1 << BIT_EHCI_SPLIT_ISO_TD_IOC)
/** \brief Page Select (DWORD 3)
    \details Indicates which data page to append the current offset to to make the buffer address.
**/
#define BIT_EHCI_SPLIT_ISO_TD_PAGE  (30)
#define MASK_EHCI_SPLIT_ISO_TD_PAGE (1 << BIT_EHCI_SPLIT_ISO_TD_PAGE)
/** \brief Transaction Length (DWORD 3)
    \details Specifies the total number of bytes to transfer.
**/
#define BIT_EHCI_SPLIT_ISO_TD_TRANSACTION_LENGTH    (16)
#define MASK_EHCI_SPLIT_ISO_TD_TRANSACTION_LENGTH   (0x3ff << BIT_EHCI_SPLIT_ISO_TD_TRANSACTION_LENGTH)
#define EHCI_SPLIT_ISO_TD_TRANSACTION_LENGTH(A)     (((A) << BIT_EHCI_SPLIT_ISO_TD_TRANSACTION_LENGTH) & MASK_EHCI_SPLIT_ISO_TD_TRANSACTION_LENGTH)
/** \brief Transaction Status and Control Lists (DWORDS 1 to 8)
**/
/** \brief Status (DWORD 3)
    \details Reports the status of the siTD.
    Active - enable execution of the transactions in this qTD by the controller.
    Data buffer error - host controller unable to keep up with incoming data or
         unable to supply outgoing data fast enough.
    Babble detected - also sets the halted bit.
    Transaction error - set to one when a device fails to respond correctly.
**/
#define BIT_EHCI_SPLIT_ISO_TD_STATUS                    (0)
#define MASK_EHCI_SPLIT_ISO_TD_STATUS                   (0xff << BIT_EHCI_SPLIT_ISO_TD_STATUS)
#define BIT_EHCI_SPLIT_ISO_TD_STATUS_ACTIVE             (7)
#define EHCI_SPLIT_ISO_TD_STATUS_ACTIVE                 (1 << BIT_EHCI_SPLIT_ISO_TD_STATUS_ACTIVE)
#define BIT_EHCI_SPLIT_ISO_TD_STATUS_ERR                (6)
#define EHCI_SPLIT_ISO_TD_STATUS_ERR                    (1 << BIT_EHCI_SPLIT_ISO_TD_STATUS_ERR)
#define BIT_EHCI_SPLIT_ISO_TD_STATUS_DATA_BUF_ERR       (5)
#define EHCI_SPLIT_ISO_TD_STATUS_DATA_BUF_ERR           (1 << BIT_EHCI_SPLIT_ISO_TD_STATUS_DATA_BUF_ERR)
#define BIT_EHCI_SPLIT_ISO_TD_STATUS_BABBLE             (4)
#define EHCI_SPLIT_ISO_TD_STATUS_BABBLE                 (1 << BIT_EHCI_SPLIT_ISO_TD_STATUS_BABBLE)
#define BIT_EHCI_SPLIT_ISO_TD_STATUS_XACTERR            (3)
#define EHCI_SPLIT_ISO_TD_STATUS_XACTERR                (1 << BIT_EHCI_SPLIT_ISO_TD_STATUS_XACTERR)
#define BIT_EHCI_SPLIT_ISO_TD_STATUS_MISSED_MICROFRAME  (2)
#define EHCI_SPLIT_ISO_TD_STATUS_MISSED_MICROFRAME      (1 << BIT_EHCI_SPLIT_ISO_TD_STATUS_MISSED_MICROFRAME)
#define BIT_EHCI_SPLIT_ISO_TD_STATUS_SPLITX             (1)
#define EHCI_SPLIT_ISO_TD_STATUS_SPLITX                 (1 << BIT_EHCI_SPLIT_ISO_TD_STATUS_SPLITX)
/** \brief Transaction Offset (DWORD 4)
    \details Offset within buffer pointer to by Page Select register.
**/
#define BIT_EHCI_SPLIT_ISO_TD_OFFSET  (0)
#define MASK_EHCI_SPLIT_ISO_TD_OFFSET (0xfff << BIT_EHCI_SPLIT_ISO_TD_OFFSET)
/** \brief Buffer Pointer (DWORDS 4 and 5)
    \details Buffer Pointer (4Kb aligned).
**/
#define BIT_EHCI_SPLIT_ISO_TD_BUFFER_POINTER  (12)
#define MASK_EHCI_SPLIT_ISO_TD_BUFFER_POINTER (0xfffff << BIT_EHCI_SPLIT_ISO_TD_BUFFER_POINTER)
/** \brief Transaction Position (DWORD 5)
    \details Used to send the first, middle or last part of a split.
**/
#define BIT_EHCI_SPLIT_ISO_TD_TRANSACTION_POS  (3)
#define MASK_EHCI_SPLIT_ISO_TD_TRANSACTION_POS (0x3 << BIT_EHCI_SPLIT_ISO_TD_TRANSACTION_POS)
/** \brief Transaction Count (DWORD 5)
    \details Initialise with the number of splits required.
**/
#define BIT_EHCI_SPLIT_ISO_TD_T_COUNT  (0)
#define MASK_EHCI_SPLIT_ISO_TD_T_COUNT (0x7 << BIT_EHCI_SPLIT_ISO_TD_T_COUNT)
//@}

/* TYPES ***************************************************************************/

/** \brief This register has information on the host controller interface specification number
 *         implemented in this host controller.*/
typedef struct
{
  uint32_t CAPLENGTH     : 8;  ///< Capability Register Length
                               ///< It is used as an offset added to the register base to find out
                               ///< the beginning of the Operational Register Space

  uint32_t Reserved_8_15 : 8;  ///< Reserved

  uint32_t HCIVERSION    : 16; ///< Host Controller Interface Version Number
                               ///< It is a 2-byte register containing a BCD encoding of the EHCI
                               ///< revision number supported by the host controller
} hc_cap_reg_t;

typedef union
{
  hc_cap_reg_t   B;
  REG_ACCESS_U32 U;
} hc_cap_reg_u;

/** \brief This register specifies the number of downstream ports implemented in this host
 *         controller.*/
typedef struct
{
  uint32_t N_PORTS  : 4;    ///< Number of Ports
                            ///< This specifies the number of the physical downstream ports
                            ///< implemented on the host controller

  uint32_t reserved : 28;   ///< Reserved
} hc_structural_params_t;

typedef union
{
  hc_structural_params_t B;
  REG_ACCESS_U32         U;
} hc_structural_params_u;

typedef struct
{
  uint32_t Reserved_1        : 1;   ///< Reserved

  uint32_t PROG_FR_LIST_FLAG : 1;   ///< Programmable Frame List Flag
                                    ///< When this bit is set to 1, the system software can specify
                                    ///< and use a smaller frame list and configure the host
                                    ///< controller via Frame List Size field of the USBCMD
                                    ///< register. This requirement ensures that the frame list is
                                    ///< always physically contiguous.

  uint32_t ASYN_SCH_PARK_CAP : 1;   ///< Asynchronous Schedule Park Capability
                                    ///< The host controller supports the park feature for HS queue
                                    ///< heads in the Asynchronous Schedule. This feature can be
                                    ///< disabled or enabled and set to a specific level by using
                                    ///< the Asynchronous Schedule Park Mode Enable and Asynchronous
                                    ///< Schedule Park Mode Count fields in the USBCMD register

  uint32_t Reserved_3        : 29;  ///< Reserved
} hc_capability_params_t;

typedef union
{
  hc_capability_params_t B;
  REG_ACCESS_U32         U;
} hc_capability_params_u;

/** \brief The command register is used by the software to schedule the command to be executed by
 * the USB host controller hardware.*/
typedef struct
{
  uint32_t RS             : 1;  ///< Run/Stop
                                ///< When this is set to 1, the host controller proceeds with the
                                ///< execution of schedule. 0: Stop, 1: Run

  uint32_t HC_RESET       : 1;  ///< Host Controller Reset
                                ///< This is used by the software to reset the host controller.

  uint32_t FRL_SIZE       : 2;  ///< Frame List Size
                                ///< This specifies the size of the frame list.
                                ///< 00: 1024 elements (default value, 4096 bytes)
                                ///< 01: 512 elements (2048 bytes)
                                ///< 10: 256 elements (1024 bytes)
                                ///< 11: reserved

  uint32_t PSCH_EN        : 1;  ///< Periodic Schedule Enable
                                ///< This controls whether the host controller skips the processing
                                ///< of the period schedule.
                                ///< 0: Do not process the period schedule
                                ///< 1: Use the PERIODICLISTBASE register to access the period
                                ///<    schedule

  uint32_t ASCH_EN        : 1;  ///< Asynchronous Schedule Enable
                                ///< This controls whether the host controller skips the processing
                                ///< of asynchronous schedule.
                                ///< 0: Do not process the asynchronous schedule
                                ///< 1: Use the ASYNCLISTADDR register to access the asynchronous
                                ///<    schedule

  uint32_t INT_OAAD       : 1;  ///< Interrupt on Asynchronous Advance Doorbell
                                ///< This is used as a doorbell by software to ring the host
                                ///< controller to issue and interrupt at the next advance of the
                                ///< synchronous schedule.

  uint32_t Reserved_7     : 1;  ///< Reserved

  uint32_t ASYN_PK_CNT    : 2;  ///< Asynchronous Schedule Park Mode Count
                                ///< This contains a count for the number of successive transactions
                                ///< that the host controller is allowed to execute from a
                                ///< high-speed queue head on the asynchronous schedule.

  uint32_t Reserved_10    : 1;  ///< Reserved

  uint32_t ASYN_PK_EN     : 1;  ///< Asynchronous Schedule Park Mode Enable
                                ///< Software uses this to enable or disable the Park mode. When
                                ///< this is set to 1, the Park mode is enabled

  uint32_t Reserved_12_15 : 4;  ///< Reserved

  uint32_t INT_THRC       : 8;  ///< Interrupt Threshold Control
                                ///< This is used by the system software to select the maximum rate
                                ///< at which the host controller will issue the interrupts. The
                                ///< only valid values are as below:
                                ///< 0x00: Reserved
                                ///< 0x01: 1 micro-frame (125us)
                                ///< 0x02: 2 micro-frames (250us)
                                ///< 0x04: 4 micro-frames (500us)
                                ///< 0x08: 8 micro-frames (default: 1ms)
                                ///< 0x10: 16 micro-frames (2ms)
                                ///< 0x20: 32 micro-frames (4ms)
                                ///< 0x40: 64 micro-frames (8ms)
                                ///< Note: In the FS mode, these bits are reserved.

  uint32_t Reserved_24_31 : 8; ///< Reserved
} hc_usb_command_reg_t;

typedef union
{
  hc_usb_command_reg_t B;
  REG_ACCESS_U32       U;
} hc_usb_command_reg_u;

/** \brief This register indicates the status of the USB host controller. This register is updated
 *         by the USB host controller hardware. Software clears a bit by writing 1 to the bit. */
typedef struct
{
  uint32_t USB_INT        : 1;    ///< USB Interrupt
                                  ///< The host controller sets this to 1 upon completion of a USB
                                  ///< transaction

  uint32_t USBERR_INT     : 1;    ///< USB Error Interrupt
                                  ///< The host controller sets this to 1 when the completion of a
                                  ///< USB transaction results in an error condition

  uint32_t PO_CHG_DET     : 1;    ///< Port Change Detect
                                  ///< The host controller sets this to 1 when any port has a change
                                  ///< bit transition from 0 to 1. In addition, this bit is loaded
                                  ///< with the OR of all of the PORTSC change bits.

  uint32_t FRL_ROL        : 1;    ///< Frame List Rollover
                                  ///< The host controller sets this to 1 when the Frame List Index
                                  ///< rolls over from its maximum value to zero.

  uint32_t H_SYSERR       : 1;    ///< Host System Error
                                  ///< The host controller sets this to 1 when a serious error
                                  ///< occurs during a host system access involving the host
                                  ///< controller module.

  uint32_t INT_OAA        : 1;    ///< Interrupt on Async Advance
                                  ///< This bit indicates the assertion of interrupt on Async
                                  ///< Advance Doorbell

  uint32_t Reserved_6_11  : 6;    ///< Reserved

  uint32_t HCHalted       : 1;    ///< Host Controller Halted
                                  ///< This is a 0 whenever the Run/Stop bit is set to 1. The host
                                  ///< controller sets this to 1 after it has stopped the section as
                                  ///< a result of the Run/Stop bit being set to 0.

  uint32_t Reclamation    : 1;    ///< Reclamation
                                  ///< This is a read-only status bit, and used to detect an empty
                                  ///< of the asynchronous schedule

  uint32_t PSCH_STS       : 1;    ///< Periodic Schedule Status
                                  ///< This reports the actual status of the periodic schedule.

  uint32_t ASCH_STS       : 1;    ///< Asynchronous Schedule Status
                                  ///< This reports the actual status of the asynchronous schedule.

  uint32_t Reserved_16_31 : 16;   ///< Reserved
} hc_usb_status_reg_t;

typedef union
{
  hc_usb_status_reg_t B;
  REG_ACCESS_U32      U;
} hc_usb_status_reg_u;

/** \brief This register enables the required host controller interrupts. The interrupts enabled by
 *         this register toggle the interrupt pin when the interrupt condition occurs. Interrupts
 *         not enabled in this register do not toggle the interrupt pin but the status can be read
 *         by polling the interrupt status register.*/
typedef struct
{
  uint32_t USB_INT_EN    : 1;   ///< USB Interrupt Enable
                                ///< When this is 1 and the Host USBINT bit in the USBSTS register
                                ///< is 1, the host controller will issue an interrupt at the next
                                ///< interrupt threshold.

  uint32_t USBERR_INT_EN : 1;   ///< USB Error Interrupt Enable
                                ///< When this is 1 and the USBERRINT bit in the USBSTS register is
                                ///< 1, the host controller will issue an interrupt at the next
                                ///< interrupt threshold.

  uint32_t PO_CHG_INT_EN : 1;   ///< Port Change Interrupt Enable
                                ///< When this is 1 and the Port Change Detect bit in the USBSTS
                                ///< register is 1, the host controller will issue an interrupt at
                                ///< the next interrupt threshold.

  uint32_t FRL_ROL_EN    : 1;   ///< Frame List Rollover Enable
                                ///< When this is 1 and the Frame List Rollover bit in the USBSTS
                                ///< register is 1, the host controller will issue an interrupt at
                                ///< the next interrupt threshold.

  uint32_t H_SYSERR_EN   : 1;   ///< Host System Error Enable
                                ///< When this is 1 and the Host System Error Status bit in the
                                ///< USBSTS register is 1, the host controller will issue an
                                ///< interrupt at the next interrupt threshold.

  uint32_t INT_OAA_EN    : 1;   ///< Interrupt on Async Advance Enable
                                ///< When this is 1 and the Interrupt on Async Advance bit in the
                                ///< USBSTS register is 1, the host controller will issue an
                                ///< interrupt at the next interrupt threshold.

  uint32_t Reserved      : 26;  ///< Reserved
} hc_usb_int_enable_reg_t;

typedef union
{
  hc_usb_int_enable_reg_t B;
  REG_ACCESS_U32          U;
} hc_usb_int_enable_reg_u;

/** \brief This register is used by the host controller to index the periodic frame. The register is
 *         updated every 125 microseconds.*/
typedef struct
{
  uint32_t FRINDEX : 14;  ///< Frame Index
                          ///< This is used by the host controller to index the frame into the
                          ///< Periodic Frame List. It is updated every 125us. It cannot be written
                          ///< unless the host controller is halted.

  uint32_t Reserved : 18; ///< Reserved
} hc_frame_index_reg_t;

typedef union
{
  hc_frame_index_reg_t B;
  REG_ACCESS_U32       U;
} hc_frame_index_reg_u;

/** \brief This register contains the beginning address of the periodic frame list in the system
 *         memory. */
typedef struct
{
  uint32_t Reserved      : 12;  ///< Reserved

  uint32_t PERI_BASE_ADR : 20;  ///< Periodic Frame List Base Address
                                ///< This 32-bit register contains the start address of the Periodic
                                ///<  Frame List in the system memory. These form the upper 20 bits
                                ///< of the address.
} hc_periodic_list_base_reg_t;

typedef union
{
  hc_periodic_list_base_reg_t B;
  REG_ACCESS_U32              U;
} hc_periodic_list_base_reg_u;

/** \brief This register contains the address of the next asynchronous queue head to be executed. */
typedef struct
{
  uint32_t Reserved   : 5;  ///< Reserved

  uint32_t ASYNC_LADR : 27; ///< Current Asynchronous List Address
                            ///< This 32-bit register contains the address of the next asynchronous
                            ///< queue head to be executed. These form the upper 27 bits of the
                            ///< address.
} hc_async_list_addr_reg_t;

typedef union
{
  hc_async_list_addr_reg_t B;
  REG_ACCESS_U32           U;
} hc_async_list_addr_reg_u;

/** \brief This register is reset only by hardware when the power is initially applied or in
 *         response to a host controller reset.*/
typedef struct
{
  uint32_t CONN_STS       : 1;  ///< Current Connect Status
                                ///< 1: Device is presented on the port
                                ///< 0: No device is presented
                                ///< This reflects the current state of the port and may not
                                ///< correspond directly to cause the Connect Status Change bit to
                                ///< be set.

  uint32_t CONN_CHG       : 1;  ///< Connect Status Change
                                ///< 1: Change in current connect status
                                ///< 0: No change
                                ///< This indicates a change has occurred in the current connect
                                ///< status of the port.

  uint32_t PO_EN          : 1;  ///< Port Enable/Disable
                                ///< 1: Enable
                                ///< 0: Disable
                                ///< Ports can only be enabled by the host controller as a part of
                                ///< the reset and enable. Software cannot enable a port by writing
                                ///< a "1" to this bit. Writing a "0" to this bit to disable the
                                ///< port is possible however.

  uint32_t PO_EN_CHG      : 1;  ///< Port Enable/Disable Change
                                ///< 1: Port enable/disable status has changed
                                ///< 0: No change

  uint32_t Reserved_4_5   : 2;  ///< Reserved

  uint32_t F_PO_RESM      : 1;  ///< Force Port Resume
                                ///< 1: Resume detection/driven on port.
                                ///< 0: No resume detected/driven on port.
                                ///< Software sets this to 1 to resume signaling.
                                ///< The host controller sets this to 1 if a J-to-K transition is
                                ///< detected while the port is in the suspended state. When this
                                ///< transits to 1 for the detection of a J-to-K transition, the
                                ///< Port Change Detect bit in USBSTS register is also set to 1.

  uint32_t PO_SUSP        : 1;  ///< Port Suspend
                                ///< 1: Port is in the suspend state
                                ///< 0: Port is not in the suspend state
                                ///< The Port Enable Bit and Suspend Bit of this register define the
                                ///< port state as follows.

  uint32_t PO_RESET       : 1;  ///< | Port Enable, Suspend | Port State |
                                ///< | :------------------: | :--------: |
                                ///< | 0X                   | Disabled   |
                                ///< | 10                   | Enabled    |
                                ///< | 11                   | Suspended  |
                                ///< At the suspended status, the downstream propagation of data is
                                ///< blocked on this port except for the port reset. While at the
                                ///< suspended state, the port is sensitive to resume detection.
                                ///< Writing a 0 to this bit is ignored. The host controller will
                                ///< unconditionally set this to 0 when:
                                ///< The software sets Force Port Resume bit to 0 (from 1)
                                ///< The software sets Port Reset bit to 1 (from 0)
                                ///< Note: Before setting this bit, Run/Stop bit should be set to 0.

  uint32_t Reserved_9     : 1;  ///< Reserved
  uint32_t LINE_STS       : 2;  ///< Line Status
                                ///< These reflect the current logical levels of the D+ and D-
                                ///< signal lines.

  uint32_t Reserved_12_15 : 4;  ///< Reserved
  uint32_t TST_FORCEEN    : 1;  ///< Test Force Enable
                                ///< When this is 1 the downstream facing port will be enabled in
                                ///< the high-speed mode. Then the Run/Stop bit must be transitioned
                                ///< to 1 in order to enable the transmission of the SOFs out of the
                                ///< port under test. This enables testing of the disconnect
                                ///< detection.

  uint32_t Reserved_17_31 : 15; ///< Reserved
} hc_port_stt_ctr_reg_t;

typedef union
{
  hc_port_stt_ctr_reg_t B;
  REG_ACCESS_U32        U;
} hc_port_stt_ctr_reg_u;

/** \brief EOF Time & Asynchronous Schedule Sleep Timer Register */
typedef struct
{
  uint32_t ASYN_SCH_SLPT : 2;   ///< Asynchronous Schedule Sleep Timer
                                ///< Controls the Asynchronous Schedule sleep timer.
                                ///<    | 0x0 | 5  us |
                                ///<    | 0x1 | 10 us |
                                ///<    | 0x2 | 15 us |
                                ///<    | 0x3 | 20 us |

  uint32_t EOF1_Time     : 2;   ///< EOF1 Timing Points
                                ///< Controls EOF1 timing point before next SOF. This value should
                                ///< be adjusted according to the maximum packet size.
                                ///< High-Speed EOF1 Time
                                ///<    | 0x0 | 540 clocks (30MHz): 18 us |
                                ///<    | 0x1 | 360 clocks (30MHz): 12 us |
                                ///<    | 0x2 | 180 clocks (30MHz):  6 us |
                                ///<    | 0x3 | 720 clocks (30MHz): 24 us |
                                ///< Full-Speed EOF1 Time
                                ///<    | 0x0 | 1600  clocks (30MHz): 53.3 us |
                                ///<    | 0x1 | 1400  clocks (30MHz): 46.6 us |
                                ///<    | 0x2 | 1200  clocks (30MHz):   40 us |
                                ///<    | 0x3 | 21000 clocks (30MHz):  700 us |
                                ///< Low-Speed EOF1 Time
                                ///<    | 0x0 | 3750 clocks (30MHz): 125 us |
                                ///<    | 0x1 | 3500 clocks (30MHz): 116 us |
                                ///<    | 0x2 | 3250 clocks (30MHz): 108 us |
                                ///<    | 0x3 | 4000 clocks (30MHz): 133 us |

  uint32_t EOF2_Time     : 2;   ///< EOF2 Timing Points
                                ///< Controls EOF2 timing point before the next SOF.
                                ///< High-Speed EOF2 Time
                                ///<    | 0x0 |  2 clocks (30MHz):  66 ns |
                                ///<    | 0x1 |  4 clocks (30MHz): 133 ns |
                                ///<    | 0x2 |  8 clocks (30MHz): 266 ns |
                                ///<    | 0x3 | 16 clocks (30MHz): 533 ns |
                                ///< Full-Speed EOF2 Time
                                ///<    | 0x0 |  20 clocks (30MHz):   666 ns |
                                ///<    | 0x1 |  40 clocks (30MHz): 1.333 us |
                                ///<    | 0x2 |  80 clocks (30MHz): 2.666 us |
                                ///<    | 0x3 | 160 clocks (30MHz): 5.333 us |
                                ///< Low-Speed EOF2 Time
                                ///<    | 0x0 |  40 clocks (30MHz): 1.333 us |
                                ///<    | 0x1 |  80 clocks (30MHz): 2.666 us |
                                ///<    | 0x2 | 160 clocks (30MHz): 5.333 us |
                                ///<    | 0x3 | 320 clocks (30MHz): 10.66 us |

  uint32_t U_SUSP_N      : 2;   ///< Transceiver Suspend Mode
                                ///< Active low.
                                ///< Places the transceiver in the suspend mode that draws the
                                ///< minimal power from the power supplies. This is part of the
                                ///< power management.

  uint32_t Reserved      : 24;  ///< Reserved
} hc_eof_time_reg_t;

typedef union
{
  hc_eof_time_reg_t B;
  REG_ACCESS_U32    U;
} hc_eof_time_reg_u;

/** \brief Bus Monitor Control/Status Register */
typedef struct
{
  uint32_t VBUS_FLT_SEL    : 1;   ///< Select a timer to filter out noise on VBUS_VLD from the UTMI+
                                  ///<    0: Approximately 135 us
                                  ///<    1: Approximately 472 us

  uint32_t HDISCON_FLT_SEL : 1;   ///< Select a timer to filter out noise on HDISCON from the UTMI+
                                  ///<    0: Approximately 135 us
                                  ///<    1: Approximately 270 us

  uint32_t Reserved_2_3    : 2;   ///< Reserved. These bits should remain ‘0’.

  uint32_t VBUS_OFF        : 1;   ///< VBUS OFF - This controls the voltage on the VBUS_ON/OFF.
                                  ///<    0: VBUS on
                                  ///<    1: VBUS off

  uint32_t Reserved_5_7    : 3;   ///< Reserved. These bits should remain ‘0’.

  uint32_t VBUS_VLD        : 1;   ///< VBUS Valid - When the voltage on the VBUS is above the valid
                                  ///< VBUS threshold, this signal is valid.

  uint32_t HOST_SPD_TYP    : 2;   ///< Host Speed Type
                                  ///<    0x2: HS
                                  ///<    0x0: FS
                                  ///<    0x1: LS
                                  ///<    0x3: Reserved

  uint32_t REserved_11_31  : 21;  ///< Reserved
} hc_bus_ctrl_stt_reg_t;

typedef union
{
  hc_bus_ctrl_stt_reg_t B;
  REG_ACCESS_U32        U;
}
hc_bus_ctrl_stt_reg_u;

/** \brief Master Protection Information Setting Register */
typedef struct
{
  uint32_t HPROT    : 4;  ///< Master Protection Information
                          ///< For programmable HPROT, software can use this to implement some
                          ///< level of protection.

  uint32_t Reserved : 28; ///< Reserved
} hc_master_protect_reg_t;

typedef union
{
  hc_master_protect_reg_t B;
  REG_ACCESS_U32          U;
} hc_master_protect_reg_u;

/** \brief Vendor Specific IO Control Register */
typedef struct
{
  uint32_t VCTL      : 5; ///< Vendor-Specific Test Mode Control
                          ///< The programmed value is delivered to the PHY via the U_VCTL output.

  uint32_t VCTLOAD_N : 1; ///< Vendor-Specific Test Mode Control Load.
                          ///< This controls the active low output U_VCTLOAD_N to the PHY.
                          ///< Setting this to 1 makes U_VCTLOAD_N output a 1.
                          ///< Setting this to 0 makes U_VCTLOAD_N output a 0.

  uint32_t Reserved : 26; ///< Reserved
} hc_vendor_ctrl_reg_t;

typedef union
{
  hc_vendor_ctrl_reg_t B;
  REG_ACCESS_U32       U;
} hc_vendor_ctrl_reg_u;

/** \brief  Vendor Specific Status Register */
typedef struct
{
  uint32_t VSTS     : 8;  ///< Vendor-Specific Test Mode Status
  uint32_t Reserved : 24; ///< Reserved
} hc_vendor_status_reg_t;

typedef struct
{
  uint32_t TST_JSTA   : 1;    ///< When this is set to 1, D+/D- are set to HS J state.

  uint32_t TST_KSTA   : 1;    ///< When this is set to 1, D+/D- are set to HS K state.

  uint32_t TST_PKT    : 1;    ///< Test Packet
                              ///< Upon entering HS mode and setting this bit to 1, the test packet
                              ///< data defined in the USB specification has to be written. The host
                              ///< controller will repeatedly send the packet defined in the UTMI
                              ///< specification to the transceiver.

  uint32_t TST_MOD    : 1;    ///< Test Mode
                              ///< When this is set to 1, the host controller will enter the test
                              ///< mode. This test mode can save the simulation time.
                              ///< In the normal mode, the host controller uses a counter for 10ms
                              ///< detection of the USB reset. This is reduced in test mode.

  uint32_t TST_LOOPBK : 1;    ///< FIFO Loop Back Mode
                              ///< When this is set to 1, the host controller will enter the
                              ///< loop-back mode.

  uint32_t Reserved   : 27;   ///< Reserved
} hc_test_reg_t;

typedef union
{
  hc_test_reg_t  B;
  REG_ACCESS_U32 U;
} hc_test_reg_u;

/** \brief DMA Error Interrupt
 *  \details This indicates that a DMA operation cannot be finished normally, and an error has been
 *           received. It can only be cleared by software and is not affected by USB bus reset.
 */
typedef struct
{
  uint32_t VBUS_ERR  : 1;   ///< VBUS Error
                            ///< This is set to 1 when the Bus Monitor state machine moves to the
                            ///< VBUS_ERROR state.

  uint32_t OVC       : 1;   ///< Over Current Detection
                            ///< This is set to 1 when the Vbus signal does not reach the VBUS_VLD
                            ///< signal within the expected time.

  uint32_t DPLGRMV   : 1;   ///< Device Plug Remove
                            ///< This is set to 1 when a device is removed.

  uint32_t DM_CMPLT  : 1;   ///< DMA Completion Interrupt
                            ///< This indicates that a DMA operation has terminated normally.
                            ///< It can only be cleared by software and is not affected by USB bus
                            ///< reset.

  uint32_t DMA_ERROR : 1;   ///< DMA Error Interrupt
                            ///< This indicates that a DMA operation cannot be finished normally,
                            ///< and an error has been received. It can only be cleared by software
                            ///< and is not affected by USB bus reset.

  uint32_t Reserved  : 27;  ///< Reserved
} hc_bus_int_sts_reg_t;

typedef union
{
  hc_bus_int_sts_reg_t B;
  REG_ACCESS_U32       U;
} hc_bus_int_sts_reg_u;

/** \brief DMA Error Interrupt enable */
typedef struct
{
  uint32_t VBUS_ERR_EN  : 1;    ///< VBUS Error Interrupt enable

  uint32_t OVC_EN       : 1;    ///< Over Current Detection Interrupt enable

  uint32_t DPLGRMV_EN   : 1;    ///< Device Plug Remove Interrupt enable

  uint32_t DMA_CMPLT_EN : 1;    ///< DMA Completion Interrupt enable

  uint32_t DMA_ERROR_EN : 1;    ///< DMA Error Interrupt enable

  uint32_t Reserved     : 27;   ///< Reserved
} hc_bus_int_ena_reg_t;

typedef union
{
  hc_bus_int_ena_reg_t B;
  REG_ACCESS_U32       U;
} hc_bus_int_ena_reg_u;

/** \brief EHCI device registers definition */
typedef struct
{
  __IO hc_cap_reg_u                HC_CAP_REG;        ///< 0x00 HC Capability Register
  __IO hc_structural_params_u      HCSPARAMS;         ///< 0x04 HC Structural Parameters
  __IO hc_capability_params_u      HCCPARAMS;         ///< 0x08 HC Capability Parameters
       uint32_t                    Reserved_0x0c;     ///< 0x0C
  __IO hc_usb_command_reg_u        USBCMD;            ///< 0x10 HC USB Command Register
  __IO hc_usb_status_reg_u         USBSTS;            ///< 0x14 HC USB Status Register
  __IO hc_usb_int_enable_reg_u     USBINTR;           ///< 0x18 HC USB Interrupt Enable Register
  __IO hc_frame_index_reg_u        FRINDEX;           ///< 0x1C HC USB Interrupt Enable Register
       uint32_t                    Reserved_0x20;     ///< 0x20
  __IO hc_periodic_list_base_reg_u PERIODICLISTBASE;  ///< 0x24 HC Periodic Frame List Base Address Register
  __IO hc_async_list_addr_reg_u    ASYNCLISTADDR;     ///< 0x28 HC Current Asynchronous List Address Register
       uint32_t                    reserved_0x2c;     ///< 0x2C
  __IO hc_port_stt_ctr_reg_u       PORTSC;            ///< 0x30 HC Port Status and Control Register
  __IO hc_eof_time_reg_u           EOF_TIME;          ///< 0x34 Asynchronous Schedule Sleep Timer Register
       uint32_t                    reserved_0x38;     ///< 0x38
       uint32_t                    reserved_0x3c;     ///< 0x3C
  __IO hc_bus_ctrl_stt_reg_u       BUS_CTRL;          ///< 0x40 Bus Monitor Control / Status Register
  __IO hc_bus_int_sts_reg_u        BUSINTSTATUS;      ///< 0x44 Bus Monitor Interrupt Status Register
  __IO hc_bus_int_ena_reg_u        BUSINTEN;          ///< 0x48 Bus Monitor Interrupt Enable Register
       uint32_t                    reserved_0x4c;     ///< 0x4C
  __IO hc_test_reg_u               TEST_REG;          ///< 0x50 Test Register
  __IO hc_vendor_ctrl_reg_u        VENDOR_CTRL;       ///< 0x54 Vendor Specific IO Control Register
  __IO hc_vendor_status_reg_t      VENDOR_STATUS;     ///< 0x58 Vendor Specific IO Status Register
       uint32_t                    reserved_0x5c;     ///< 0x5C
       uint32_t                    reserved_0x60;     ///< 0x60
       uint32_t                    reserved_0x64;     ///< 0x64
       uint32_t                    reserved_0x68;     ///< 0x68
       uint32_t                    reserved_0x6c;     ///< 0x6C
       uint32_t                    HC_RSRV1;          ///< 0x70 Reserved register
       uint32_t                    HC_RSRV2;          ///< 0x74 Reserved register
  __IO hc_master_protect_reg_u     HPROT;             ///< 0x78 Master Protection Information Setting Register
} ehci_regs_t;

/** \brief EHCI device register definition */
typedef struct
{
  volatile uint32_t hccaplength;     /// 0x00 HC Capability Register
  volatile uint32_t hcsparams;       /// 0x04 HCSPARAMS � HC Structural Parameters
  volatile uint32_t hccparams;       /// 0x08 HCCPARAMS � HC Capability Parameters
  uint32_t reserved_0x0c;            //  0x0C
  volatile uint32_t usbcmd;          /// 0x10 USBCMD � HC USB Command Register
  volatile uint32_t usbsts;          /// 0x14 USBSTS � HC USB Status Register
  volatile uint32_t usbintr;         /// 0x18 USBINTR � HC USB Interrupt Enable Register
  volatile uint32_t frindex;         /// 0x1c FRINDEX � HC Frame Index Register
  uint32_t reserved_0x20;            //  0x20
  volatile uint32_t periodiclistaddr;/// 0x24 PERIODICLISTBASE � HC Periodic Frame List Base Address Register
  volatile uint32_t asynclistaddr;   /// 0x28 ASYNCLISTADDR � HC Current Asynchronous List Address Register
  uint32_t reserved_0x2c;            //  0x2C
  volatile uint32_t portsc;          /// 0x30 PORTSC � HC Port Status and Control Register
  volatile uint32_t eoftime;         /// 0x34 EOF Time & Asynchronous Schedule Sleep Timer Register
  uint32_t reserved_0x38;            //  0x38
  uint32_t reserved_0x3c;            //  0x3C
  volatile uint32_t busctrl;         /// 0x40 Bus Monitor Control / Status Register
  volatile uint32_t busintstatus;    /// 0x44 Bus Monitor Interrupt Status Register
  volatile uint32_t businten;        /// 0x48 Bus Monitor Interrupt Enable Register
  uint32_t reserved_0x4c;            //  0x4C
  volatile uint32_t testregister;    /// 0x50 Test Register
  volatile uint32_t vendorctrl;      /// 0x54 Vendor Specific IO Control Register
  volatile uint32_t vendorstatus;    /// 0x58 Vendor Specific IO Status Register
  uint32_t reserved_0x5c;            //  0x5C
  uint32_t reserved_0x60;            //  0x60
  uint32_t reserved_0x64;            //  0x64
  uint32_t reserved_0x68;            //  0x68
  uint32_t reserved_0x6c;            //  0x6C
  volatile uint32_t dmactrlpmset1;   /// 0x70 DMA Controller Parameter Setting 1 Register
  volatile uint32_t dmactrlpmset2;   /// 0x74 DMA Controller Parameter Setting 2 Register
  volatile uint32_t hprot;           /// 0x78 HPROT � Master Protection Information Setting Register
} ft900_ehci_regs_t;

/** \brief EHCI Ram definition
    \details Typedef to facilitate pointers to EHCI RAM
**/
typedef uint32_t volatile ft900_ehci_ram_t;

/* GLOBAL VARIABLES ****************************************************************/

/* MACROS **************************************************************************/

/** \brief EHCI RAM address decode
    \details Macros to facilitate converting between byte addresses in EHCI RAM and offsets
             used by referencing ft900_ehci_ram_t array.
**/
#define EHCI_RAM_OFFSET(A)  (A / sizeof(ft900_ehci_ram_t))
#define EHCI_RAM_ADDRESS(A) (A * sizeof(ft900_ehci_ram_t))

/** \brief EHCI RAM address conversion
    \details Macros to facilitate converting between addresses in EHCI RAM and CPU addresses.
**/
#define EHCI_HC_TO_CPU(A) ((uint32_t)&EHCI_RAM[0] + (uint32_t)(A))
#define EHCI_CPU_TO_HC(A) ((uint32_t)(A) - (uint32_t)&EHCI_RAM[0])

/** \brief EHCI Queue Next Address
    \details Macros to find the address of the "next" pointers in qTD and qH structures.
**/
#define EHCI_NEXT_QH(A)       (A & MASK_EHCI_QUEUE_HEAD_NEXT)
#define EHCI_TYPE_QH(A)       (A & MASK_EHCI_QUEUE_HEAD_TYPE)
#define EHCI_TERMINATE_QH(A)  (A & MASK_EHCI_QUEUE_HEAD_TERMINATE)
#define EHCI_NEXT_TD(A)       (A & MASK_EHCI_QUEUE_TD_NEXT)
#define EHCI_TERMINATE_TD(A)  (A & MASK_EHCI_QUEUE_TD_TERMINATE)

/** \brief EHCI Register Access
    \details Macros to address registers in the EHCI space. Register names from the
             ft900_ehci_regs_t structure are used.
             For example: status = *((uint32_t *)&EHCI->usbsts); will be written as
                          status = EHCI_REG(usbsts);
**/
#define EHCI_REG(A) (*(uint32_t *)&(EHCI->A))

/** \brief EHCI Register Access
    \details Macros to address memory as 32 bit accesses in the EHCI space.
             For example: status = *((uint32_t *)&qtd->token); will be written as
                          status = EHCI_MEM(qtd->token);
**/
#define EHCI_MEM(A) (*(uint32_t *)&(A))

/**
    @name    Definitions for ECHI RAM addresses.
    @details Definitions for default EHCI RAM layout.
             These are used by the library and will not be required to be
             used in the API.
             EHCI_PERIODIC_ADDR is a byte offset from the start of EHCI memory.
             EHCI_PERIODIC_SIZE is the number of entries in the periodic list.
             EHCI_RAM_ALIGN is the alignment criteria for addressing structure.
 */
//@{
#define EHCI_PERIODIC_ADDR   (0x0000)
#define EHCI_PERIODIC_SIZE   (0x100)
#define EHCI_RAM_ALIGN       (0x20)
//@}


/* FUNCTION PROTOTYPES *************************************************************/


#endif /* FT900_EHCI_REGISTERS_H_ */
