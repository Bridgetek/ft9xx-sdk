#
#
#    @file
#
#    @brief
#    Main makefile for the FT900 HAL released along with FT90x toolchain package
#
#
# ============================================================================
# History
# =======
#
# Copyright (C) Bridgetek Pte Ltd
# ============================================================================
#
# This source code ("the Software") is provided by Bridgetek Pte Ltd
# ("Bridgetek") subject to the licence terms set out
# http://brtchip.com/BRTSourceCodeLicenseAgreement/ ("the Licence Terms").
# You must read the Licence Terms before downloading or using the Software.
# By installing or using the Software you agree to the Licence Terms. If you
# do not agree to the Licence Terms then do not download or use the Software.
#
# Without prejudice to the Licence Terms, here is a summary of some of the key
# terms of the Licence Terms (and in the event of any conflict between this
# summary and the Licence Terms then the text of the Licence Terms will
# prevail).
#
# The Software is provided "as is".
# There are no warranties (or similar) in relation to the quality of the
# Software. You use it at your own risk.
# The Software should not be used in, or for, any medical device, system or
# appliance. There are exclusions of Bridgetek liability for certain types of loss
# such as: special loss or damage; incidental loss or damage; indirect or
# consequential loss or damage; loss of income; loss of business; loss of
# profits; loss of revenue; loss of contracts; business interruption; loss of
# the use of money or anticipated savings; loss of information; loss of
# opportunity; loss of goodwill or reputation; and/or loss of, damage to or
# corruption of data.
# There is a monetary cap on Bridgetek's liability.
# The Software may have subsequently been amended by another user and then
# distributed by that other user ("Adapted Software").  If so that user may
# have additional licence terms that apply to those amendments. However, Bridgetek
# has no liability in relation to those amendments.
# ============================================================================

# The TARGET and CONFIG parameters are required (they are case-sensitive). 
# The INSTALL parameter allows the source code path to be set for object files to facilitate debugging.
# Example Windows builds:
# make -B TARGET=ft900 CONFIG=Debug INSTALL="C:\Program Files (x86)\Bridgetek\FT9xx Toolchain\Toolchain\hardware"
# Example Linux builds:
# make -B TARGET=ft900 CONFIG=Debug INSTALL="/opt/ft9xx-toolchain/hardware"

.PHONY := clean all 

# Determine what GCC version to use
ifndef PREFIX
PREFIX := ft32-elf-
endif

ifndef LIBDIR
LIBDIR := lib
endif

CC := $(PREFIX)gcc
LD := $(PREFIX)ld
AS := $(PREFIX)as
AR := $(PREFIX)ar

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
MKDIR := mkdir -p
else
MKDIR := gmkdir -p
endif

SRC_DIR := ./src
INCLUDE_DIR := ./include

# Set up flags and a destination directory....
CFLAGS += -c -I$(INCLUDE_DIR) 
CFLAGS += -fmessage-length=0 -ffunction-sections
CFLAGS += -Wall -Wextra
#extension for named address spaces is only supported by gcc for plain C only, not for C99
CFLAGS += -std=gnu99 #-std=c99
ifdef INSTALL
# Release settings
ifeq ($(UNAME), Linux)
LOCALDIR := ${CURDIR}
else
LOCALDIR := $(subst /,\,$(subst /c/,C:\,$(CURDIR)))
endif
CFLAGS += -ffile-prefix-map="${LOCALDIR}"="${INSTALL}"
endif # ifdef INSTALL

ifeq ($(CONFIG), Release)
# Release settings
CFLAGS += -Os
LDFLAGS +=

else
ifeq ($(CONFIG), Debug)
# Debug settings
CFLAGS += -g3 
CFLAGS += -DDEBUG
CFLAGS += -Og
LDFLAGS +=

else
$(error Please choose CONFIG=Debug or CONFIG=Release)

endif # ifeq ($(CONFIG), Debug)
endif # ifeq ($(CONFIG), Release)

DESTDIR := $(LIBDIR)/$(CONFIG)/$(TARGET)

ifeq ($(TARGET), ft900)
CFLAGS += -D__FT900__ 

SRCFILES := adc.c \
		bootstrap.c \
        cam.c \
        can.c \
        dac.c \
        delay.c \
        ethernet.c \
        gpio.c \
        i2cm.c \
        i2cs.c \
        i2s.c \
        interrupt.c \
        memctl.c \
        pwm.c \
        pwm_pcm.c \
        rtc.c \
        sdhost.c \
        spi.c \
        sys.c \
        timers.c \
        usbd.c \
        usbdx.c \
        usbd_hbw.c\
        usbd_dfu.c \
        usbd_rndis.c \
        usbd_startup_dfu.c \
        usbh.c \
        usbhx.c \
        usbh_boms.c \
        usbh_cdcacm.c \
        usbh_hid.c \
        usbh_aoa.c \
        uart_simple.c \
        wdt.c \
        dlog.c

else
ifeq ($(TARGET), ft930)
CFLAGS += -D__FT930__ -mcompress -mft32b

SRCFILES := adc.c \
		bootstrap.c \
		dac.c \
		delay.c \
		gpio.c \
		i2cm.c \
		i2cs.c \
		interrupt.c \
		memctl.c \
		pwm.c \
		pwm_pcm.c \
		rtc.c \
		sdhost.c \
		spi.c \
		sys.c \
		timers.c \
		usbd.c \
		usbdx.c \
		usbd_dfu.c \
		usbd_rndis.c \
		usbd_startup_dfu.c \
		uart_simple.c \
		wdt.c \
		dlog.c 

else
$(error Please choose TARGET=ft900 or TARGET=ft930)
endif # ifeq ($(TARGET), ft900)
endif # ifeq ($(TARGET), ft930)

RELSRCFILES := $(addprefix $(SRC_DIR)/,$(SRCFILES))
OBJFILES := $(addprefix $(DESTDIR)/,$(notdir $(RELSRCFILES:.c=.o)))

all: $(DESTDIR)/lib$(TARGET).a
ifeq ($(CONFIG), Debug)
ifeq ($(TARGET), ft900)
	cp  $^ $(LIBDIR)
endif # ifeq ($(TARGET), ft900)
endif # ifeq ($(CONFIG), Debug)
	mv $^ $(LIBDIR)/$(CONFIG)

clean:
	-$(RM) $(OBJFILES)
	-$(RM) -r $(DESTDIR)


$(DESTDIR)/lib$(TARGET).a: $(OBJFILES) | $(DESTDIR) ; $(AR) rv $@ $^

$(DESTDIR)/%.o:        $(SRC_DIR)/%.c     | $(DESTDIR) ; $(CC) $(CFLAGS) $^ -o $@

$(DESTDIR):                                     ; $(MKDIR) $@
