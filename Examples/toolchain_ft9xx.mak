# Standard Makefile Actions for FT9xx project compilation.

# Apply sensible default values.

# Build type (case sensitive), can be Debug (default) or Release.
BUILD?=Debug
# Target device type (case sensitive), can be ft90x (default) or ft93x.
TARGET?=ft90x
# Output directories depend on build type and target device.
ifeq ($(BUILD),Release)
ifeq ($(TARGET),ft93x)
OUTDIR?=FT93x_Release
else
ifeq ($(TARGET),ft90x)
OUTDIR?=FT90x_Release
else
$(error use TARGET=ft90x or TARGET=ft93x)
endif
endif
else
ifeq ($(BUILD),Debug)
ifeq ($(TARGET),ft93x)
OUTDIR?=FT93x_Debug
else
ifeq ($(TARGET),ft90x)
OUTDIR?=FT90x_Debug
else
$(error use TARGET=ft90x or TARGET=ft93x)
endif
endif
else
$(error use BUILD=Debug or BUILD=Release)
endif
endif

# Project name (this forms part of the filename for the output files).
# If there is no variable set then form this from the name of the current
# directory with any spaces replaced by underscores.
PROJECT?=$(basename $(notdir $(addsuffix .dummy,$(subst $(empty) ,_,$(CURDIR)))))

# Build lists of files.

# Find all *.c files in all the directories that contian your sources.
# Note: Filenames must not have spaces. Files in the toolchain examples do not have spaces.
CSRCS:=$(wildcard *.c) $(foreach SRCDIR,$(filter-out .,$(SRCDIRS)),$(wildcard $(SRCDIR)/*.c))

# Find all .S/.s files in all the directories that contian your sources.
ASMSRCS:=$(wildcard *.S) $(foreach SRCDIR,$(filter-out .,$(SRCDIRS)),$(wildcard $(SRCDIR)/*.S))

# Find one linker script file in all the scripts directory.
LDSRCS:=$(wildcard Scripts/*.ld)

# Make a list of object files from the list of C source files.
OBJS:=$(patsubst %.c, $(OUTDIR)/%.o, $(CSRCS))
# Add the list of ASM source files to the list of object files.
OBJS+=$(patsubst %.S, $(OUTDIR)/%.o, $(ASMSRCS))

# Make a list of dependency files from the list of C source files.
DEPS:=$(patsubst %.c, $(OUTDIR)/%.d, $(CSRCS))

# FT9xx specific toolchain definitions.
CC=ft32-elf-gcc
AS=ft32-elf-as
OBJCOPY=ft32-elf-objcopy
SIZE=ft32-elf-size
MKDIR=mkdir
RM=rm

# C Compiler Flags

# Flag for telling source files that it is an FT90x or FT93x device.
ifeq ($(TARGET),ft93x)
	CFLAGS+=-D__FT930__ 
else
	CFLAGS+=-D__FT900__ 
endif
# Paths to include files that are needed. The search order is important.
CFLAGS+=-I"." $(patsubst %, -I "%", $(INCDIRS))
# Compilation output options for Debug and Release builds.
ifeq ($(BUILD),Release)
	CFLAGS+=-Os
else
	CFLAGS+=-Og -g -fvar-tracking -fvar-tracking-assignments 
endif
CFLAGS+=-Wall -fmessage-length=0 -ffunction-sections 
# Toolchain default include directory incase it does not find anything in the
# other include directories. Note this the last -I parameter.
CFLAGS+= -I"$(FT9XX_TOOLCHAIN)/hardware/include"

# Assembler Flags

ASFLAGS+=-I"." $(patsubst %, -I "%", $(INCDIRS))
ifeq ($(TARGET),ft93x)
	ASFLAGS+=--defsym __FT930__=1
else
	ASFLAGS+=--defsym __FT900__=1
endif

# Linker Flags 

# Standard linker options.
LDFLAGS+=-Wl,--gc-sections -Wl,--entry=_start 
# Paths to any additional library search directories that are needed. The 
# search order is important.
LDFLAGS+=$(patsubst %, -L"%", $(LIBDIRS))
# Add the optional libraries onto the linker command line.
LDLIBS:=$(patsubst %, -l%, $(LIBS))
# Add the device specific libraries and options onto the linker command line.
ifeq ($(TARGET),ft93x)
	LDFLAGS+=-mft32b -mcompress 
	LDLIBS+=$(patsubst %, -l%, $(LIBS_FT930))
	LDLIBS+=-lft930
	LDFLAGS+=-D__FT930__ 
else
	LDLIBS+=$(patsubst %, -l%, $(LIBS_FT900))
	LDLIBS+=-lft900
	LDFLAGS+=-D__FT900__ 
endif
# Add the standard libraries onto the linker command line.
LDLIBS+=-lc -lstub
# Detect an assembler file with crt0 in the name and use it as the start file.
ifneq ($(findstring crt0,$(ASMSRCS)),)
	LDFLAGS+=-nostartfiles
endif
# Toolchain default library directory incase it does not find anything in the other areas.
ifeq ($(BUILD),Release)
	TOOLCHAINLIB= -L"$(FT9XX_TOOLCHAIN)/hardware/lib/Release"
else
	TOOLCHAINLIB= -L"$(FT9XX_TOOLCHAIN)/hardware/lib/Debug"
endif
# If the linker script path is valid then add it to the linker command line.
ifneq (,$(firstword $(LDSRCS)))
	LDFLAGS+=-Xlinker -dT "$(firstword $(LDSRCS))"
endif

# Recipie

FINAL:=$(OUTDIR)/$(PROJECT)

# Convert ELF file to binary image for programming an display image size.
all: $(FINAL).elf
	@echo Invoking: FT9xx Flash File Generator
	$(OBJCOPY) --output-target binary "$<" "$(patsubst %.elf,%.bin,$<)"
	@echo Invoking: FT9xx Display Image Size
	$(SIZE) --format=berkeley -x "$<"
	@echo Finished building: SIZE

# Link object files to ELF file.
$(FINAL).elf: $(OBJS)
	@echo Building target: $@
	@echo Invoking: FT9xx GCC Linker
	$(CC) $(LDFLAGS) $(TOOLCHAINLIB) -o "$@" $(OBJS) $(LDLIBS)
	@echo Finished building target: $@

# Rebuild if there are header file changes.
ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif

# Build C files to object files.
$(OUTDIR)/%.o: %.c
# Create binary directory.
	@-$(MKDIR) -p "$(dir $@)"
# Build file in the binary directory (produce dependency files as well).
	@echo Building file: $<
	$(CC) $(CFLAGS) -c "$<"  -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@"
	@echo Finished building: $<

# Build S files to object files.
$(OUTDIR)/%.o: %.S
# Create binary directory.
	@-$(MKDIR) -p "$(dir $@)"
# Build file in the binary directory (produce dependency files as well).
	@echo Building file: $<
	$(AS) $(ASFLAGS) -o "$@" "$<"
	@echo Finished building: $<

$(OUTDIR)/%.o: %.s
# Create binary directory.
	@-$(MKDIR) -p "$(dir $@)"
# Build file in the binary directory (produce dependency files as well).
	@echo Building file: $<
	$(AS) $(ASFLAGS) -o "$@" "$<"
	@echo Finished building: $<

clean:
# Remove object, dependency and target files in the output directory.
	-$(RM) -rf $(OBJS) $(DEPS) $(FINAL).elf $(FINAL).bin

info: 
	# Project: $(PROJECT)
	# Final target: $(FINAL)
	# Output dir: $(OUTDIR)
	# Source dirs: $(SRCDIRS)
	# C Sources: $(CSRCS)
	# ASM Sources: $(ASMSRCS)
	# Objects: $(OBJS)
