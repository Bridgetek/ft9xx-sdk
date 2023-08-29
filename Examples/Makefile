# Standard Makefile for FT9xx project compilation.

# Build type (case sensitive), can be debug (default) or release.
# On command line call "make BUILD=release" to change.
BUILD?=debug

# Target device type (case sensitive), can be ft90x (default) or ft93x.
# On command line call "make TARGET=ft93x" to change.
TARGET?=ft90x

# Additional include directories required (you may change these).
# All directory names with spaces must be escaped.
INCDIRS+=Includes
INCDIRS+=hardware/include
INCDIRS+=hw/include
INCDIRS+=usb/include
INCDIRS+=drivers
# Include directories for FreeRTOS.
INCDIRS+=lib/FreeRTOS/Source/include lib/FreeRTOS/Source/portable/GCC/FT32
# Include directories for lwIP
INCDIRS+=lib/lwIP/src/arch lib/lwIP/src/include

# Additional source directories required (you may change these).
# All directory names with spaces must be escaped. Do not use source filenames with spaces.
SRCDIRS+=src
SRCDIRS+=Sources
SRCDIRS+=hw/src
SRCDIRS+=usb/src
SRCDIRS+=drivers
# Source directories for FreeRTOS.
SRCDIRS+=lib/FreeRTOS/Source/portable/GCC/FT32 lib/FreeRTOS/Source/portable/GCC/MemMang lib/FreeRTOS/Source
# Source directories for lwIP
SRCDIRS+=lib/lwIP/src/api lib/lwIP/src/api lib/lwIP/src/arch lib/lwIP/src/api lib/lwIP/src/core lib/lwIP/src/core/ipv4 lib/lwIP/src/netif lib/lwIP/src/netif/ppp lib/lwIP/src/netif/ppp/polarssl

# Optional C compiler flags.
# Macros defined for FreeRTOS.
CFLAGS?= -DFT32_FREERTOS -DFT32_PORT -DFT32_PORT_HEAP=4

# Optional linker script.
LDSCRIPT?=Scripts/ldscript.ld

# Optional additional link libraries (you may override these).
ifeq ($(TARGET),ft93x)
	LIBS=ft930_d2xx_dev
else
	LIBS=ft900_d2xx_dev
endif

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

# Project name (this forms part of the filename for the output files).
# It is formed from the name of the current directory. This can be overridden.
# Spaces are changed to underscores in the project name.
PROJECT:=$(basename $(notdir $(addsuffix .dummy,$(subst $(empty) ,_,$(CURDIR)))))

# Find all *.c files in all the directories that contian your sources.
# Note: Filenames must not have spaces. Files in the toolchain examples do not have spaces.
CSRCS:=$(wildcard *.c) $(foreach SRCDIR,$(filter-out .,$(SRCDIRS)),$(wildcard $(SRCDIR)/*.c))

# Find all .S/.s files in all the directories that contian your sources.
ASMSRCS:=$(wildcard *.S) $(foreach SRCDIR,$(filter-out .,$(SRCDIRS)),$(wildcard $(SRCDIR)/*.S))

# Find one linker script file in all the scripts directory.
LDSRCS:=$(wildcard $(LDDIR)/*.ld)

# Make a list of object files from the list of source files.
OBJS:=$(patsubst %.c, $(OUTDIR)/%.o, $(CSRCS))
OBJS+=$(patsubst %.S, $(OUTDIR)/%.o, $(ASMSRCS))

# Make a list of dependency files from the list of source files.
DEPS:=$(patsubst %.c, $(OUTDIR)/%.d, $(CSRCS))

# FT9xx specific toolchain definitions.
CC=ft32-elf-gcc
AS=ft32-elf-as
OBJCOPY=ft32-elf-objcopy
SIZE=ft32-elf-size
MKDIR=mkdir
RM=rm

# C Compiler Flags

# Flag for telling library that it is an FT900 device.
ifeq ($(TARGET),ft93x)
	CFLAGS+=-D__FT930__ 
else
	CFLAGS+=-D__FT900__ 
endif
# relative paths to include files that are needed. The search order is important.
CFLAGS+=-I"." $(patsubst %, -I "%", $(INCDIRS))
# Compilation output options
ifeq ($(BUILD),release)
	CFLAGS+=-Os
else
	CFLAGS+=-Og -g -fvar-tracking -fvar-tracking-assignments 
endif
CFLAGS+=-Wall -fmessage-length=0 -ffunction-sections 
# Toolchain default include directory incase it does not find anything in the other areas.
CFLAGS+= -I"$(FT9XX_TOOLCHAIN)\hardware\include"

# Assembler Flags
ASFLAGS+=-I"." $(patsubst %, -I "%", $(INCDIRS))

# Linker Flags 

# Location of your libft900.a file.
LDFLAGS+=-L"lib"
# Other linker options.
LDFLAGS+=-Wl,--gc-sections -Wl,--entry=_start 
# Add the optional libraries onto the linker command line.
LDLIBS:=$(patsubst %, -l%, $(LIBS))
# Add the device specific libraries and options onto the linker command line.
ifeq ($(TARGET),ft93x)
	LDFLAGS+=-mft32b -mcompress 
	LDLIBS+=-lft930
	LDFLAGS+=-D__FT930__ 
else
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
ifeq ($(BUILD),release)
	TOOLCHAINLIB= -L"$(FT9XX_TOOLCHAIN)/hardware/lib/Release"
else
	TOOLCHAINLIB= -L"$(FT9XX_TOOLCHAIN)/hardware/lib/Debug"
endif
# If the linker script path is valid then add it to the linker command line.
ifneq (,$(wildcard $(LDSCRIPT)))
	LDFLAGS+=-Xlinker -dT "$(LDSCRIPT)"
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


ft32-elf-gcc -L"lib" -Wl,--gc-sections -Wl,--entry=_start  -D__FT900__  -L"C:\Users\gordon.mcnab\AppData\Local\Bridgetek\FT9xx Toolchain\Toolchain/hardware/lib/Debug" -o "FT90x_Debug/FreeRTOS_lwIP_Example.elf"  FT90x_Debug/Sources/main.o  FT90x_Debug/lib/FreeRTOS/Source/portable/GCC/FT32/port.o  FT90x_Debug/lib/FreeRTOS/Source/portable/GCC/FT32/port_extra.o  FT90x_Debug/lib/FreeRTOS/Source/croutine.o  FT90x_Debug/lib/FreeRTOS/Source/event_groups.o  FT90x_Debug/lib/FreeRTOS/Source/list.o  FT90x_Debug/lib/FreeRTOS/Source/queue.o  FT90x_Debug/lib/FreeRTOS/Source/tasks.o  FT90x_Debug/lib/FreeRTOS/Source/timers.o  FT90x_Debug/lib/lwIP/src/api/api_lib.o  FT90x_Debug/lib/lwIP/src/api/api_msg.o  FT90x_Debug/lib/lwIP/src/api/err.o  FT90x_Debug/lib/lwIP/src/api/if_api.o  FT90x_Debug/lib/lwIP/src/api/netbuf.o  FT90x_Debug/lib/lwIP/src/api/netdb.o  FT90x_Debug/lib/lwIP/src/api/netifapi.o  FT90x_Debug/lib/lwIP/src/api/sockets.o  FT90x_Debug/lib/lwIP/src/api/tcpip.o  FT90x_Debug/lib/lwIP/src/api/api_lib.o  FT90x_Debug/lib/lwIP/src/api/api_msg.o  FT90x_Debug/lib/lwIP/src/api/err.o  FT90x_Debug/lib/lwIP/src/api/if_api.o  FT90x_Debug/lib/lwIP/src/api/netbuf.o  FT90x_Debug/lib/lwIP/src/api/netdb.o  FT90x_Debug/lib/lwIP/src/api/netifapi.o  FT90x_Debug/lib/lwIP/src/api/sockets.o  FT90x_Debug/lib/lwIP/src/api/tcpip.o  FT90x_Debug/lib/lwIP/src/arch/net.o  FT90x_Debug/lib/lwIP/src/arch/netif_ft900.o  FT90x_Debug/lib/lwIP/src/arch/sys_arch.o  FT90x_Debug/lib/lwIP/src/api/api_lib.o  FT90x_Debug/lib/lwIP/src/api/api_msg.o  FT90x_Debug/lib/lwIP/src/api/err.o  FT90x_Debug/lib/lwIP/src/api/if_api.o  FT90x_Debug/lib/lwIP/src/api/netbuf.o  FT90x_Debug/lib/lwIP/src/api/netdb.o  FT90x_Debug/lib/lwIP/src/api/netifapi.o  FT90x_Debug/lib/lwIP/src/api/sockets.o  FT90x_Debug/lib/lwIP/src/api/tcpip.o  FT90x_Debug/lib/lwIP/src/core/altcp.o  FT90x_Debug/lib/lwIP/src/core/altcp_alloc.o  FT90x_Debug/lib/lwIP/src/core/altcp_tcp.o  FT90x_Debug/lib/lwIP/src/core/def.o  FT90x_Debug/lib/lwIP/src/core/dns.o  FT90x_Debug/lib/lwIP/src/core/inet_chksum.o  FT90x_Debug/lib/lwIP/src/core/init.o  FT90x_Debug/lib/lwIP/src/core/ip.o  FT90x_Debug/lib/lwIP/src/core/mem.o  FT90x_Debug/lib/lwIP/src/core/memp.o  FT90x_Debug/lib/lwIP/src/core/netif.o  FT90x_Debug/lib/lwIP/src/core/pbuf.o  FT90x_Debug/lib/lwIP/src/core/raw.o  FT90x_Debug/lib/lwIP/src/core/stats.o  FT90x_Debug/lib/lwIP/src/core/sys.o  FT90x_Debug/lib/lwIP/src/core/tcp.o  FT90x_Debug/lib/lwIP/src/core/tcp_in.o  FT90x_Debug/lib/lwIP/src/core/tcp_out.o  FT90x_Debug/lib/lwIP/src/core/timeouts.o  FT90x_Debug/lib/lwIP/src/core/udp.o  FT90x_Debug/lib/lwIP/src/core/ipv4/autoip.o  FT90x_Debug/lib/lwIP/src/core/ipv4/dhcp.o  FT90x_Debug/lib/lwIP/src/core/ipv4/etharp.o  FT90x_Debug/lib/lwIP/src/core/ipv4/icmp.o  FT90x_Debug/lib/lwIP/src/core/ipv4/igmp.o  FT90x_Debug/lib/lwIP/src/core/ipv4/ip4.o  FT90x_Debug/lib/lwIP/src/core/ipv4/ip4_addr.o  FT90x_Debug/lib/lwIP/src/core/ipv4/ip4_frag.o  FT90x_Debug/lib/lwIP/src/netif/bridgeif.o  FT90x_Debug/lib/lwIP/src/netif/bridgeif_fdb.o  FT90x_Debug/lib/lwIP/src/netif/ethernet.o  FT90x_Debug/lib/lwIP/src/netif/lowpan6.o  FT90x_Debug/lib/lwIP/src/netif/lowpan6_ble.o  FT90x_Debug/lib/lwIP/src/netif/lowpan6_common.o  FT90x_Debug/lib/lwIP/src/netif/slipif.o  FT90x_Debug/lib/lwIP/src/netif/zepif.o  FT90x_Debug/lib/lwIP/src/netif/ppp/auth.o  FT90x_Debug/lib/lwIP/src/netif/ppp/ccp.o  FT90x_Debug/lib/lwIP/src/netif/ppp/chap-md5.o  FT90x_Debug/lib/lwIP/src/netif/ppp/chap-new.o  FT90x_Debug/lib/lwIP/src/netif/ppp/chap_ms.o  FT90x_Debug/lib/lwIP/src/netif/ppp/demand.o  FT90x_Debug/lib/lwIP/src/netif/ppp/eap.o  FT90x_Debug/lib/lwIP/src/netif/ppp/ecp.o  FT90x_Debug/lib/lwIP/src/netif/ppp/eui64.o  FT90x_Debug/lib/lwIP/src/netif/ppp/fsm.o  FT90x_Debug/lib/lwIP/src/netif/ppp/ipcp.o  FT90x_Debug/lib/lwIP/src/netif/ppp/ipv6cp.o  FT90x_Debug/lib/lwIP/src/netif/ppp/lcp.o  FT90x_Debug/lib/lwIP/src/netif/ppp/magic.o  FT90x_Debug/lib/lwIP/src/netif/ppp/mppe.o  FT90x_Debug/lib/lwIP/src/netif/ppp/multilink.o  FT90x_Debug/lib/lwIP/src/netif/ppp/ppp.o  FT90x_Debug/lib/lwIP/src/netif/ppp/pppapi.o  FT90x_Debug/lib/lwIP/src/netif/ppp/pppcrypt.o  FT90x_Debug/lib/lwIP/src/netif/ppp/pppoe.o  FT90x_Debug/lib/lwIP/src/netif/ppp/pppol2tp.o  FT90x_Debug/lib/lwIP/src/netif/ppp/pppos.o  FT90x_Debug/lib/lwIP/src/netif/ppp/upap.o  FT90x_Debug/lib/lwIP/src/netif/ppp/utils.o  FT90x_Debug/lib/lwIP/src/netif/ppp/vj.o  FT90x_Debug/lib/lwIP/src/netif/ppp/polarssl/arc4.o  FT90x_Debug/lib/lwIP/src/netif/ppp/polarssl/des.o  FT90x_Debug/lib/lwIP/src/netif/ppp/polarssl/md4.o  FT90x_Debug/lib/lwIP/src/netif/ppp/polarssl/md5.o  FT90x_Debug/lib/lwIP/src/netif/ppp/polarssl/sha1.o  FT90x_Debug/lib/FreeRTOS/Source/portable/GCC/FT32/portasm.o  -lft900_d2xx_dev -lft900 -lc -lstub

ft32-elf-gcc -nostartfiles -L"C:\Users\gordon.mcnab\AppData\Local\Bridgetek\FT9xx Toolchain\Toolchain/hardware/lib/Debug" -Wl,--gc-sections -Wl,--entry=_start -Xlinker -dT "C:/workspace/FreeRTOS lwIP Example/ld/freertos.ld" -Xlinker -Map="FreeRTOS lwIP Example.map" -Xlinker --cref -o "FreeRTOS lwIP Example.elf" ./lib/lwIP/src/netif/ppp/polarssl/arc4.o ./lib/lwIP/src/netif/ppp/polarssl/des.o ./lib/lwIP/src/netif/ppp/polarssl/md4.o ./lib/lwIP/src/netif/ppp/polarssl/md5.o ./lib/lwIP/src/netif/ppp/polarssl/sha1.o  ./lib/lwIP/src/netif/ppp/auth.o ./lib/lwIP/src/netif/ppp/ccp.o ./lib/lwIP/src/netif/ppp/chap-md5.o ./lib/lwIP/src/netif/ppp/chap-new.o ./lib/lwIP/src/netif/ppp/chap_ms.o ./lib/lwIP/src/netif/ppp/demand.o ./lib/lwIP/src/netif/ppp/eap.o ./lib/lwIP/src/netif/ppp/ecp.o ./lib/lwIP/src/netif/ppp/eui64.o ./lib/lwIP/src/netif/ppp/fsm.o ./lib/lwIP/src/netif/ppp/ipcp.o ./lib/lwIP/src/netif/ppp/ipv6cp.o ./lib/lwIP/src/netif/ppp/lcp.o ./lib/lwIP/src/netif/ppp/magic.o ./lib/lwIP/src/netif/ppp/mppe.o ./lib/lwIP/src/netif/ppp/multilink.o ./lib/lwIP/src/netif/ppp/ppp.o ./lib/lwIP/src/netif/ppp/pppapi.o ./lib/lwIP/src/netif/ppp/pppcrypt.o ./lib/lwIP/src/netif/ppp/pppoe.o ./lib/lwIP/src/netif/ppp/pppol2tp.o ./lib/lwIP/src/netif/ppp/pppos.o ./lib/lwIP/src/netif/ppp/upap.o ./lib/lwIP/src/netif/ppp/utils.o ./lib/lwIP/src/netif/ppp/vj.o  ./lib/lwIP/src/netif/bridgeif.o ./lib/lwIP/src/netif/bridgeif_fdb.o ./lib/lwIP/src/netif/ethernet.o ./lib/lwIP/src/netif/lowpan6.o ./lib/lwIP/src/netif/lowpan6_ble.o ./lib/lwIP/src/netif/lowpan6_common.o ./lib/lwIP/src/netif/slipif.o ./lib/lwIP/src/netif/zepif.o  ./lib/lwIP/src/core/ipv4/autoip.o ./lib/lwIP/src/core/ipv4/dhcp.o ./lib/lwIP/src/core/ipv4/etharp.o ./lib/lwIP/src/core/ipv4/icmp.o ./lib/lwIP/src/core/ipv4/igmp.o ./lib/lwIP/src/core/ipv4/ip4.o ./lib/lwIP/src/core/ipv4/ip4_addr.o ./lib/lwIP/src/core/ipv4/ip4_frag.o  ./lib/lwIP/src/core/altcp.o ./lib/lwIP/src/core/altcp_alloc.o ./lib/lwIP/src/core/altcp_tcp.o ./lib/lwIP/src/core/def.o ./lib/lwIP/src/core/dns.o ./lib/lwIP/src/core/inet_chksum.o ./lib/lwIP/src/core/init.o ./lib/lwIP/src/core/ip.o ./lib/lwIP/src/core/mem.o ./lib/lwIP/src/core/memp.o ./lib/lwIP/src/core/netif.o ./lib/lwIP/src/core/pbuf.o ./lib/lwIP/src/core/raw.o ./lib/lwIP/src/core/stats.o ./lib/lwIP/src/core/sys.o ./lib/lwIP/src/core/tcp.o ./lib/lwIP/src/core/tcp_in.o ./lib/lwIP/src/core/tcp_out.o ./lib/lwIP/src/core/timeouts.o ./lib/lwIP/src/core/udp.o  ./lib/lwIP/src/arch/net.o ./lib/lwIP/src/arch/netif_ft900.o ./lib/lwIP/src/arch/sys_arch.o  ./lib/lwIP/src/api/api_lib.o ./lib/lwIP/src/api/api_msg.o ./lib/lwIP/src/api/err.o ./lib/lwIP/src/api/if_api.o ./lib/lwIP/src/api/netbuf.o ./lib/lwIP/src/api/netdb.o ./lib/lwIP/src/api/netifapi.o ./lib/lwIP/src/api/sockets.o ./lib/lwIP/src/api/tcpip.o  ./lib/FreeRTOS/Source/portable/MemMang/heap_1.o ./lib/FreeRTOS/Source/portable/MemMang/heap_2.o ./lib/FreeRTOS/Source/portable/MemMang/heap_3.o ./lib/FreeRTOS/Source/portable/MemMang/heap_4.o ./lib/FreeRTOS/Source/portable/MemMang/heap_5.o  ./lib/FreeRTOS/Source/portable/GCC/FT32/port.o ./lib/FreeRTOS/Source/portable/GCC/FT32/port_extra.o ./lib/FreeRTOS/Source/portable/GCC/FT32/portasm.o  ./lib/FreeRTOS/Source/croutine.o ./lib/FreeRTOS/Source/event_groups.o ./lib/FreeRTOS/Source/list.o ./lib/FreeRTOS/Source/queue.o ./lib/FreeRTOS/Source/tasks.o ./lib/FreeRTOS/Source/timers.o  ./ld/crt0.o  ./Sources/main.o    -lft900 -lc -lstub
