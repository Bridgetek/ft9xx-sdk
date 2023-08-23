# Note: In user configurable variables: No quotes, escape spaces (e.g. my\ directory).

# Build type, can be debug or release.
# On command line call "make BUILD=release" to change.
BUILD?=debug

# Target device type, can be ft90x or ft93x.
# On command line call "make TARGET=ft93x" to change.
TARGET?=ft90x

# Project name (this forms part of the filename for the output files).
PROJECT=firmware\ test

# All include directories required (you may change this).
INCDIRS+= hardware\include
INCDIRS+= usb\include
INCDIRS+= drivers

# All source directories required (you may change this).
# NO files with spaces are allowed in any of these directories.
SRCDIRS+= .
SRCDIRS+= src
SRCDIRS+= usb/src
SRCDIRS+= hw/src
SRCDIRS+= drivers

# Output directory (you may change this).
ifeq ($(BUILD),release)
	ifeq ($(TARGET),ft93x)
		OUTDIR=FT93x_Release
	else
		OUTDIR=FT90x_Release
	endif
else
	ifeq ($(TARGET),ft93x)
		OUTDIR=FT93x_Debug
	else
		OUTDIR=FT90x_Debug
	endif
endif

# Nothing to change below this point...

# Make a version of dir and notdir that is safe with spaces (since it is passed a list).
s? = $(subst $(empty) ,?,$1)
?s = $(subst ?, ,$1)
notdirx = $(call ?s,$(notdir $(call s?,$1)))
dirx = $(call ?s,$(dir $(call s?,$1)))

# Find all *.c files in the top directory, then all the other directories that contian your sources.
SRCS:= $(foreach SRCDIR,$(SRCDIRS),$(wildcard $(SRCDIR)/*.c))

# Make a list of object files from the list of source files.
OBJS:= $(patsubst %.c, $(OUTDIR)/%.o, $(SRCS))

# FT9xx specific files.
CC=ft32-elf-gcc
OBJCOPY=ft32-elf-objcopy
SIZE=ft32-elf-size
MKDIR=mkdir

# Toolchain default include directory incase it does not find anything in the other areas.
TOOLCHAININC= -I"$(FT9XX_TOOLCHAIN)\hardware\include"
# Flag for telling library that it is an FT900 device.
ifeq ($(TARGET),ft93x)
	CFLAGS+=-D__FT930__ 
else
	CFLAGS+=-D__FT900__ 
endif
# relative paths to include files that are needed. The search order is important.
CFLAGS+=$(patsubst %, -I "%", $(INCDIRS))
# Compilation output options
ifeq ($(BUILD),release)
	CFLAGS+=-Os
else
	CFLAGS+=-Og -g -fvar-tracking -fvar-tracking-assignments 
endif
CFLAGS+=-Wall -fmessage-length=0 -ffunction-sections 

# Location of your libft900.a file.
LDFLAGS+=-L"lib"
# Other linker options.
LDFLAGS+=-Wl,--gc-sections -Wl,--entry=_start 
ifeq ($(TARGET),ft93x)
	LDFLAGS+=-mft32b -mcompress 
	LDLIB=ft930
else
	LDLIB=ft900
endif
# Toolchain default library directory incase it does not find anything in the other areas.
TOOLCHAINLIB= -L"$(FT9XX_TOOLCHAIN)\hardware\lib\Debug"

FINAL=$(OUTDIR)/$(PROJECT)

all: $(FINAL).elf
	@echo Invoking: FT9xx Flash File Generator
	$(OBJCOPY) --output-target binary "$<"  $(FINAL).bin
	@echo Invoking: FT9xx Display Image Size
	$(SIZE) --format=berkeley -x "$<"
	@echo Finished building: SIZE

$(FINAL).elf: $(OBJS)
	@echo Building target: $@
	@echo Invoking: FT9xx GCC Linker
	$(CC) $(LDFLAGS) $(TOOLCHAINLIB) -o "$@" $(OBJS) -l$(LDLIB) -lc -lstub
	@echo Finished building target: $@

$(OUTDIR)/%.o: %.c
# Create binary directory.
	@-$(MKDIR) -p "$(call dirx,$@)"
# Build file in the binary directory.
	@echo Building file: $<
	$(CC) $(CFLAGS) $(TOOLCHAININC) -c "$<" -o "$@"
	@echo Finished building: $<

clean:
	$(RM) $(OUTDIR)/*


