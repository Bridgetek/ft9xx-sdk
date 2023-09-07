set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE})

# Load the toolchain cmake file
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../toolchain_ft9xx.cmake)

# This one use to by pass the test build for compiler
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

# Project setup
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(FreeRTOS_lwIP_Example LANGUAGES C ASM)
set(EXECUTABLE ${PROJECT_NAME}.elf)
set(LINKER_FILE ${CMAKE_SOURCE_DIR}/ld/freertos.ld)
set(OUTPUT_FOLDER_PRE "")
set(OUTPUT_FOLDER_POST "")
set(OUTPUT_FOLDER_NAME "")

# Language setup
enable_language(C ASM)

# List of source files
set(SRC_FILES
    # Free RTOS source
    lib/FreeRTOS/Source/portable/MemMang/heap_1.c
    lib/FreeRTOS/Source/portable/MemMang/heap_2.c
    lib/FreeRTOS/Source/portable/MemMang/heap_3.c
    lib/FreeRTOS/Source/portable/MemMang/heap_4.c
    lib/FreeRTOS/Source/portable/MemMang/heap_5.c

    lib/FreeRTOS/Source/portable/GCC/FT32/port.c
    lib/FreeRTOS/Source/portable/GCC/FT32/port_extra.c

    lib/FreeRTOS/Source/croutine.c
    lib/FreeRTOS/Source/event_groups.c
    lib/FreeRTOS/Source/list.c
    lib/FreeRTOS/Source/queue.c
    lib/FreeRTOS/Source/tasks.c
    lib/FreeRTOS/Source/timers.c

    # lwIP
    lib/lwIP/src/netif/ppp/polarssl/arc4.c
    lib/lwIP/src/netif/ppp/polarssl/des.c
    lib/lwIP/src/netif/ppp/polarssl/md4.c
    lib/lwIP/src/netif/ppp/polarssl/md5.c
    lib/lwIP/src/netif/ppp/polarssl/sha1.c

    lib/lwIP/src/netif/ppp/auth.c
    lib/lwIP/src/netif/ppp/ccp.c
    lib/lwIP/src/netif/ppp/chap-md5.c
    lib/lwIP/src/netif/ppp/chap-new.c
    lib/lwIP/src/netif/ppp/chap_ms.c
    lib/lwIP/src/netif/ppp/demand.c
    lib/lwIP/src/netif/ppp/eap.c
    lib/lwIP/src/netif/ppp/ecp.c
    lib/lwIP/src/netif/ppp/eui64.c
    lib/lwIP/src/netif/ppp/fsm.c
    lib/lwIP/src/netif/ppp/ipcp.c
    lib/lwIP/src/netif/ppp/ipv6cp.c
    lib/lwIP/src/netif/ppp/lcp.c
    lib/lwIP/src/netif/ppp/magic.c
    lib/lwIP/src/netif/ppp/mppe.c
    lib/lwIP/src/netif/ppp/multilink.c
    lib/lwIP/src/netif/ppp/ppp.c
    lib/lwIP/src/netif/ppp/pppapi.c
    lib/lwIP/src/netif/ppp/pppcrypt.c
    lib/lwIP/src/netif/ppp/pppoe.c
    lib/lwIP/src/netif/ppp/pppol2tp.c
    lib/lwIP/src/netif/ppp/pppos.c
    lib/lwIP/src/netif/ppp/upap.c
    lib/lwIP/src/netif/ppp/utils.c
    lib/lwIP/src/netif/ppp/vj.c

    lib/lwIP/src/netif/bridgeif.c
    lib/lwIP/src/netif/bridgeif_fdb.c
    lib/lwIP/src/netif/ethernet.c
    lib/lwIP/src/netif/lowpan6.c
    lib/lwIP/src/netif/lowpan6_ble.c
    lib/lwIP/src/netif/lowpan6_common.c
    lib/lwIP/src/netif/slipif.c
    lib/lwIP/src/netif/zepif.c

    lib/lwIP/src/core/ipv4/autoip.c
    lib/lwIP/src/core/ipv4/dhcp.c
    lib/lwIP/src/core/ipv4/etharp.c
    lib/lwIP/src/core/ipv4/icmp.c
    lib/lwIP/src/core/ipv4/igmp.c
    lib/lwIP/src/core/ipv4/ip4.c
    lib/lwIP/src/core/ipv4/ip4_addr.c
    lib/lwIP/src/core/ipv4/ip4_frag.c

    lib/lwIP/src/core/altcp.c
    lib/lwIP/src/core/altcp_alloc.c
    lib/lwIP/src/core/altcp_tcp.c
    lib/lwIP/src/core/def.c
    lib/lwIP/src/core/dns.c
    lib/lwIP/src/core/inet_chksum.c
    lib/lwIP/src/core/init.c
    lib/lwIP/src/core/ip.c
    lib/lwIP/src/core/mem.c
    lib/lwIP/src/core/memp.c
    lib/lwIP/src/core/netif.c
    lib/lwIP/src/core/pbuf.c
    lib/lwIP/src/core/raw.c
    lib/lwIP/src/core/stats.c
    lib/lwIP/src/core/sys.c
    lib/lwIP/src/core/tcp.c
    lib/lwIP/src/core/tcp_in.c
    lib/lwIP/src/core/tcp_out.c
    lib/lwIP/src/core/timeouts.c
    lib/lwIP/src/core/udp.c

    lib/lwIP/src/arch/net.c
    lib/lwIP/src/arch/netif_ft900.c
    lib/lwIP/src/arch/sys_arch.c

    lib/lwIP/src/api/api_lib.c
    lib/lwIP/src/api/api_msg.c
    lib/lwIP/src/api/err.c
    lib/lwIP/src/api/if_api.c
    lib/lwIP/src/api/netbuf.c
    lib/lwIP/src/api/netdb.c
    lib/lwIP/src/api/netifapi.c
    lib/lwIP/src/api/sockets.c
    lib/lwIP/src/api/tcpip.c

    # Main source
    Sources/main.c
)

message(STATUS "CMAKE_ASM_FLAGS ${CMAKE_ASM_FLAGS}")

# Build the executable based on the source files
add_executable(${EXECUTABLE} ${SRC_FILES})

# Setup library for linker step
if (${CMAKE_BUILD_TYPE} MATCHES Debug)
    target_link_libraries(${EXECUTABLE} PRIVATE -L"${TOOLCHAIN_HARDWARE_LIB_DEBUG}")
    target_compile_options(${EXECUTABLE} PRIVATE -Og)
    string(APPEND OUTPUT_FOLDER_POST "Debug")
elseif (${CMAKE_BUILD_TYPE} MATCHES Release)
    target_link_libraries(${EXECUTABLE} PRIVATE -L"${TOOLCHAIN_HARDWARE_LIB_RELEASE}")
    string(APPEND OUTPUT_FOLDER_POST "Release")
else ()
    message(FATAL_ERROR "The build type should be Debug or Release.")
endif ()

# Add specific libs and linker option
if (${CHIPSET} MATCHES FT90X)
    target_compile_definitions(${EXECUTABLE} PRIVATE -D__FT900__)
    target_link_libraries(${EXECUTABLE} PRIVATE -lft900)
    string(APPEND OUTPUT_FOLDER_PRE "FT90X")
    set(ASM_BUILD_FLAG --defsym __FT900__=1)
else ()
    message(FATAL_ERROR "The CHIPSET must me FT90X.")
endif()

set(OUTPUT_FOLDER_NAME ${OUTPUT_FOLDER_PRE}_${OUTPUT_FOLDER_POST})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/${OUTPUT_FOLDER_NAME})

# List of include directories
target_include_directories(${EXECUTABLE} PRIVATE
    lib/lwIP/src/arch
    lib/lwIP/src/include

    lib/FreeRTOS/Source/include
    lib/FreeRTOS/Source/portable/GCC/FT32

    Includes
    ${TOOLCHAIN_HARDWARE_INCLUDE}
)

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
    -DFT32_FREERTOS
    -DFT32_PORT
    -DFT32_PORT_HEAP=4

    -fvar-tracking-assignments
    -Wall
    -c
    -fmessage-length=0
    -ffunction-sections
    # Add your here
)

# Linker library options
target_link_libraries(${EXECUTABLE} PRIVATE
    -lc
    -lstub
    # Add your here
)

# Linker options
target_link_options(${EXECUTABLE} PRIVATE
    -nostartfiles
    -Xlinker -dT ${LINKER_FILE}

    -Wl,--gc-sections
    -Wl,--entry=_start
    -Wl,-Map=${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.map,--cref

    ${EXECUTABLE_OUTPUT_PATH}/crt0.o
    ${EXECUTABLE_OUTPUT_PATH}/portasm.o
)

# Build the custom crt0
add_custom_command(TARGET ${EXECUTABLE}
    PRE_BUILD
    COMMAND ${CMAKE_ASM_COMPILER}
        ${ASM_BUILD_FLAG}
        -I"${CMAKE_SOURCE_DIR}/Includes"
        ${CMAKE_SOURCE_DIR}/ld/crt0.S
        -o ${EXECUTABLE_OUTPUT_PATH}/crt0.o

    COMMAND ${CMAKE_ASM_COMPILER}
        ${ASM_BUILD_FLAG}
        -I"${CMAKE_SOURCE_DIR}/Includes"
        ${CMAKE_SOURCE_DIR}/lib/FreeRTOS/Source/portable/GCC/FT32/portasm.S
        -o ${EXECUTABLE_OUTPUT_PATH}/portasm.o
)

# Print the size of excutable file after build *.elf successfully
add_custom_command(TARGET ${EXECUTABLE}
    POST_BUILD
    # Create bin file
    COMMAND ${CMAKE_OBJCOPY}
        --output-target binary
        ${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.elf
        ${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.bin
    # Print out size of image
    COMMAND ${CMAKE_SIZE_UTIL}
        --format=berkeley
        -x ${EXECUTABLE_OUTPUT_PATH}/${EXECUTABLE}
)
