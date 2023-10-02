# Standard Makefile Template for FT9xx project compilation.

# Project name. Default name is the name of the current directory.
# On command line call "make PROJECT=firmware" to override.
# Spaces must be escaped. e.g. PROJECT=my\ project
#PROJECT?=firmware

# Build type (case sensitive), can be debug (default) or release.
# On command line call "make BUILD=release" "make BUILD=debug" to override.
#BUILD?=debug

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
INCDIRS+=hardware/include
INCDIRS+=hw/include
INCDIRS+=usb/include
INCDIRS+=drivers
# Template include directories for FreeRTOS.
#INCDIRS+=lib/FreeRTOS/Source/include lib/FreeRTOS/Source/portable/GCC/FT32
# Template include directories for lwIP
#INCDIRS+=lib/lwIP/src/arch lib/lwIP/src/include

# Additional source directories required for the compiler.
# Current directory is implied.
# All directory names with spaces must be escaped.
# Do not use source filenames with spaces.
# If directories are not found they will be ignored.
SRCDIRS+=Sources
# Template source directories for Examples.
SRCDIRS+=src
SRCDIRS+=hw/src
SRCDIRS+=usb/src
SRCDIRS+=drivers
# Template source directories for FreeRTOS.
#SRCDIRS+=lib/FreeRTOS/Source/portable/GCC/FT32 lib/FreeRTOS/Source/portable/GCC/MemMang lib/FreeRTOS/Source
# Template source directories for lwIP
#SRCDIRS+=lib/lwIP/src/api lib/lwIP/src/api lib/lwIP/src/arch lib/lwIP/src/api lib/lwIP/src/core lib/lwIP/src/core/ipv4 lib/lwIP/src/netif lib/lwIP/src/netif/ppp lib/lwIP/src/netif/ppp/polarssl

# Optional C compiler flags.
# Additional flags can be passed from the command line.
# Template for additional macros defined for FreeRTOS.
#CFLAGS+= -DFT32_FREERTOS -DFT32_PORT -DFT32_PORT_HEAP=4

# Optional linker script.
# On command line call "make LDSCRIPT=Scripts/myscript.ld" to override.
# Only one file may be specified, leave blank or omit if none.
#LDSCRIPT?=Scripts/ldscript.ld

# Additional library directories required by the linker.
# All directory names with spaces must be escaped.
# If directories are not found they will be ignored. 
#LIBDIRS?=lib

# Optional additional link libraries (you may override these).
# Do not use source filenames with spaces.
# Do not include the "lib" prefix or ".a" suffix in the name.
# Template for including D2XX device libraries.
ifeq ($(TARGET),ft93x)
	LIBS+=ft930_d2xx_dev
else
	LIBS+=ft900_d2xx_dev
endif

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
