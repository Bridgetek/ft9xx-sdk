# Build type (case sensitive), can be debug (default) or release.
# On command line call "make BUILD=release" to change.
BUILD?=debug

# Target device type (case sensitive), can be ft90x (default) or ft93x.
# On command line call "make TARGET=ft93x" to change.
TARGET?=ft90x

# All include directories required (you may change these).
# The add function formats the directory path to help make cope with spaces.
INCDIRS+= $(call add,.)
INCDIRS+= $(call add,hardware/include)
INCDIRS+= $(call add,usb/include)
INCDIRS+= $(call add,drivers)

# All source directories required (you may change these).
# The add function formats the directory path to help make cope with spaces.
SRCDIRS+=$(call add,.)
SRCDIRS+=$(call add,usb/src)
SRCDIRS+=$(call add,hw/src)
SRCDIRS+=$(call add,src)
SRCDIRS+=$(call add,drivers)

# Output directories (you may override these).
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

# Protect spaces from make.
add=$(subst $(empty) ,?,$1)

# Project name (this forms part of the filename for the output files).
# It is formed from the name of the current directory. This can be overridden.
PROJECT:= $(subst ?,\ ,$(basename $(notdir $(addsuffix .c,$(subst $(empty) ,?,$(CURDIR))))))

# Find all *.c files in all the directories that contian your sources.
# On Windows 'ls' and 'sed' are installed by the FT9xx Toolchain.
# The '?' is substituted to help make cope with spaces in files.
SRCS:=$(foreach SRCDIR,$(SRCDIRS),$(shell ls -b "$(subst ?, ,$(SRCDIR))/"*.c 2>/dev/null | sed 's/ /\?/g'))

# Make a list of object files from the list of source files.
OBJS:= $(patsubst %.c, $(OUTDIR)/%.o, $(SRCS))

# Remove the '?' which helped make cope with spaces in files.
SRCS:= $(subst ?, ,$(SRCS))
OBJS:= $(subst ?, ,$(OBJS))

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
CFLAGS+=$(subst ?, ,$(patsubst %, -I "%", $(INCDIRS)))
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
ifeq ($(BUILD),release)
	TOOLCHAINLIB= -L"$(FT9XX_TOOLCHAIN)/hardware/lib/Release"
else
	TOOLCHAINLIB= -L"$(FT9XX_TOOLCHAIN)/hardware/lib/Debug"
endif

FINAL:=$(OUTDIR)/$(PROJECT)

all: $(FINAL).elf
	@echo Invoking: FT9xx Flash File Generator
	$(OBJCOPY) --output-target binary "$<" "$(patsubst %.elf,%.bin,$<)"
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
	@-$(MKDIR) -p "$(subst ?, ,$(dir $(subst $(empty) ,?,$@)))"
# Build file in the binary directory.
	@echo Building file: $<
	$(CC) $(CFLAGS) $(TOOLCHAININC) -c "$<" -o "$@"
	@echo Finished building: $<

clean:
	$(RM) $(OUTDIR)/*

info: 
	# Project: $(PROJECT)
	# Final target: $(FINAL)
	# Source dirs: $(SRCDIRS)
	# Sources: $(SRCS)
	# Objects: $(OBJS)
