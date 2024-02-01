# Standard Makefile Template for FT9xx project compilation.

# Project name. Default name is the name of the current directory.
# On command line call "make PROJECT=firmware" to override.
# Spaces must be escaped. e.g. PROJECT=my\ project
#PROJECT?=firmware

# Build type (case sensitive), can be Debug (default) or Release.
# On command line call "make BUILD=Release" "make BUILD=Debug" to override.
#BUILD?=Debug

# Target device type (case sensitive), can be ft90x (default) or ft93x.
# On command line call "make TARGET=ft93x" or "make TARGET=ft90x" to override.
#TARGET?=ft90x

# Output directories (you may override this). 
# Default is one of "FT90x_Release", "FT90x_Debug", "FT93x_Release" or 
#  "FT93x_Debug" depending on build type and target device.
# On command line call "make OUTDIR=build" to override.
#OUTDIR?=FT90x_Debug

# Additional include directories required for the compiler.
# Current directory is implied.
# All directory names with spaces must be escaped.
# If directories are not found they will be ignored.
INCDIRS+=Includes
# Template include directories for Examples.
INCDIRS+=hw/include
INCDIRS+=usb/include
INCDIRS+=drivers
# Template include directories for FreeRTOS.
# INCDIRS+=lib/FreeRTOS/Source/include lib/FreeRTOS/Source/portable/GCC/FT32
# Template include directories for lwIP
# INCDIRS+=lib/lwIP/src/arch lib/lwIP/src/include
# Template include directories for FatFS.
# INCDIRS+=lib/FatFS lib/FatFS/option
# Template include directories for tinyprintf.
# INCDIRS+=lib/tinyprintf

# Additional source directories required for the compiler.
# Current directory is implied.
# All directory names with spaces must be escaped.
# Do not use source filenames with spaces.
# If directories are not found they will be ignored.
SRCDIRS+=Sources
# Template source directories for Examples.
SRCDIRS+=hw/src
SRCDIRS+=usb/src
SRCDIRS+=drivers
# Template source directories for FreeRTOS.
# SRCDIRS+=lib/FreeRTOS/Source/portable/GCC/FT32 lib/FreeRTOS/Source/portable/MemMang lib/FreeRTOS/Source
# Template source directories for lwIP.
# SRCDIRS+=lib/lwIP/src/api lib/lwIP/src/arch lib/lwIP/src/core lib/lwIP/src/core/ipv4 lib/lwIP/src/netif lib/lwIP/src/netif/ppp lib/lwIP/src/netif/ppp/polarssl
# Template source directories for FatFS.
# SRCDIRS+=lib/FatFS lib/FatFS/option
# Template source directories for tinyprintf.
# SRCDIRS+=lib/tinyprintf

# Optional C compiler flags.
# Additional flags can be passed from the command line.
# Template for additional macros defined for FreeRTOS.
# CFLAGS+= -DFT32_FREERTOS -DFT32_PORT -DFT32_PORT_HEAP=4

# Additional library directories required by the linker.
# All directory names with spaces must be escaped.
# If directories are not found they will be ignored. 
# LIBDIRS?=lib

# Optional additional link libraries (you may override these).
# Do not use source filenames with spaces.
# Do not include the "lib" prefix or ".a" suffix in the name.
# LIBS+=mylib

# Optional additional link libraries (you may override these) for a target.
# Do not use source filenames with spaces.
# Do not include the "lib" prefix or ".a" suffix in the name.
# LIBS_FT900+=myft900lib
# LIBS_FT930+=myft930lib
# Template for including d2xx_dev (USB device) libraries.
# LIBS_FT900+=ft900_d2xx_dev
# Template for including d2xx_dev_rtos (USB device) libraries.
# LIBS_FT900+=ft900_d2xx_dev_rtos
# Template for including d2xx_host (USB host) libraries.
# LIBS_FT900+=ft900_d2xx_host
# Template for including d2xx_dev (USB device) libraries.
# LIBS_FT930+=ft930_d2xx_dev

# Include the toolchain makefile which contains the recipie and
# command line generation code.
# The toolchain makefile is found in the root directory of the toolchain
# installation.
# If there is a local copy then that will be used instead.
ifneq (,$(wildcard toolchain_ft9xx.mak))
include toolchain_ft9xx.mak
else
ifneq (,$(wildcard ../toolchain_ft9xx.mak))
include ../toolchain_ft9xx.mak
else
ifneq (,$(wildcard $(subst $(empty) ,\ ,$(FT9XX_TOOLCHAIN))\toolchain_ft9xx.mak))
include $(subst $(empty) ,\ ,$(FT9XX_TOOLCHAIN))\toolchain_ft9xx.mak
else
$(error Make sure that the FT9XX is installed correctly. Can't find the 'toolchain_ft9xx.mak' file)
endif
endif
endif
