# the name of the target operating system
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR FT9XX)

# This one use to by pass the test build for compiler
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

# Search command for Linux/Windows
if(MINGW OR CYGWIN OR WIN32)
    # Get the path form the binutils search
    execute_process(
        COMMAND where ft32-elf-gcc
            OUTPUT_VARIABLE
            BINUTILS_PATH
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    message(STATUS "Test BINUTILS_PATH: ${BINUTILS_PATH}")
    cmake_path(SET TOOLCHAIN_DIR NORMALIZE "$ENV{FT9XX_TOOLCHAIN}")
    set(TOOLCHAIN_PREFIX ft32-elf-)
    set(EXTENTION ".exe")
elseif(UNIX OR APPLE)
    set(COMPILER_PATH    /opt/ft32/bin)
    set(TOOLCHAIN_DIR    /opt/ft9xxtoolchain/)
    set(BINUTILS_PATH    ${COMPILER_PATH}/ft32-elf-gcc)
    set(TOOLCHAIN_PREFIX ${COMPILER_PATH}/ft32-elf-)
    set(EXTENTION "")
endif()

# which compilers to use for C and C++
set(CMAKE_C_COMPILER   ${TOOLCHAIN_PREFIX}gcc${EXTENTION})
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}as${EXTENTION})
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++${EXTENTION})
set(CMAKE_OBJCOPY      ${TOOLCHAIN_PREFIX}objcopy${EXTENTION} CACHE INTERNAL "Objcopy tool")
set(CMAKE_SIZE_UTIL    ${TOOLCHAIN_PREFIX}size${EXTENTION}    CACHE INTERNAL "Size tool")

# where is the target environment located
set(CMAKE_FIND_ROOT_PATH ${BINUTILS_PATH})

# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# --------------------------------------------------------------------------- #
# Define the list of toolchain suport
set(TOOLCHAIN_DRIVER_INCLUDE       "${TOOLCHAIN_DIR}/drivers")
set(TOOLCHAIN_HARDWARE_INCLUDE     "${TOOLCHAIN_DIR}/hardware/include")
set(TOOLCHAIN_HARDWARE_LIB         "${TOOLCHAIN_DIR}/hardware/lib")
set(TOOLCHAIN_HARDWARE_LIB_DEBUG   "${TOOLCHAIN_DIR}/hardware/lib/Debug")
set(TOOLCHAIN_HARDWARE_LIB_RELEASE "${TOOLCHAIN_DIR}/hardware/lib/Release")
set(TOOLCHAIN_3RDPARTY_LIB         "${TOOLCHAIN_DIR}/3rdparty")

# --------------------------------------------------------------------------- #
# Set and test defaults.
if("${BUILD}" STREQUAL "")
	set (BUILD "Debug")
	message(STATUS "Build type has been set to ${BUILD}.")
else()
	set(build_list Debug Release)
	if(${BUILD} IN_LIST build_list)
		message(STATUS "Build type is ${BUILD}")
	else()
		message(FATAL_ERROR "The BUILD parameter must be Debug or Release. \"${BUILD}\" not allowed.")
	endif()
endif()

if("${TARGET}" STREQUAL "")
	set (TARGET "ft90x")
	message(STATUS "Target has been set to ${TARGET}.")
else()
	set(target_list ft90x ft93x)
	if(${TARGET} IN_LIST target_list)
		message(STATUS "Target chipset is ${TARGET}")
	else()
		message(FATAL_ERROR "The TARGET must be ft90x or ft93x. \"${TARGET}\" not allowed.")
	endif()
endif()

# --------------------------------------------------------------------------- #
# Define the macro which support build process

macro(ft9xx_setup_project)
    # Language setup
    enable_language(C ASM)

    # Add default include directory for project
    include_directories(
        ${TOOLCHAIN_HARDWARE_INCLUDE}
    )

    # Add default compiler option for project
    add_compile_options(
        -fvar-tracking-assignments
        -Wall
        -c
        -fmessage-length=0
        -ffunction-sections
    )

    # Add default linker option for project
    add_link_options(
        -Wl,--gc-sections
        -Wl,--entry=_start
    )

endmacro()

macro(ft9xx_set_executable executable srcfiles)
	# Build the executable based on the source files
	add_executable(${executable} ${srcfiles})

	# Set target-specific settings.
    if (${TARGET} MATCHES ft90x)
        target_compile_definitions(${executable} PRIVATE -D__FT900__)
        target_link_libraries(${executable} PRIVATE -lft900)
        set(ENV{FT9XX_OUTPUT_FOLDER_PRE} FT90x)
    elseif (${TARGET} MATCHES ft93x)
        target_compile_definitions(${executable} PRIVATE -D__FT930__)
        target_link_options(${executable} PRIVATE -mft32b -mcompress)
        target_link_libraries(${executable} PRIVATE -lft930)
        set(ENV{FT9XX_OUTPUT_FOLDER_PRE} FT93x)
    else ()
		# Double check TARGET
        message(FATAL_ERROR "The TARGET must me ft90x or ft93x.")
    endif()

	# Set build-specific settings.
    if (${BUILD} MATCHES Debug)
        target_compile_options(${executable} PRIVATE -g -Og)
        target_link_libraries(${executable} PRIVATE -L"${TOOLCHAIN_HARDWARE_LIB_DEBUG}")
        set(ENV{FT9XX_OUTPUT_FOLDER_POST} Debug)
    elseif (${BUILD} MATCHES Release)
        target_compile_options(${executable} PRIVATE -O3)
        target_link_libraries(${executable} PRIVATE -L"${TOOLCHAIN_HARDWARE_LIB_RELEASE}")
        set(ENV{FT9XX_OUTPUT_FOLDER_POST} Release)
    else ()
		# Double check BUILD
        message(FATAL_ERROR "The BUILD type should be Debug or Release.")
    endif()

    # This is the CMAKE value should be set also
    set(CMAKE_BUILD_MODE ${BUILD})

    # Set the ouput folder for the elf, bin, map,...
    set(ENV{FT9XX_OUTPUT_FOLDER_NAME} $ENV{FT9XX_OUTPUT_FOLDER_PRE}_$ENV{FT9XX_OUTPUT_FOLDER_POST})
    set(ENV{FT9XX_EXECUTABLE_OUTPUT_PATH} ${CMAKE_SOURCE_DIR}/$ENV{FT9XX_OUTPUT_FOLDER_NAME})

    # Setup the output folder for the build
    set_target_properties(${executable}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "$ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}"
    )

    # Print the size of excutable file after build *.elf successfully
    add_custom_command(TARGET ${executable}
        POST_BUILD
        # Create bin file
        COMMAND ${CMAKE_OBJCOPY} --output-target binary
            $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.elf
            $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.bin
    )

    # Setup library for linker step
    target_link_libraries(${executable} PRIVATE -lc -lstub)
endmacro()

macro(ft9xx_target_add_libraries target libraries)
    target_link_libraries(${target} PRIVATE ${libraries})
endmacro()

macro(ft9xx_target_add_library excutable lib_name)
    target_link_libraries(${excutable} PRIVATE ${lib_name})
endmacro()

macro(ft9xx_enable_map_file excutable)
	set(OUTPUT_MAP_FILE_PATH $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.map)
    target_link_options(${excutable} PRIVATE
        # Enable the map file
        -Wl,-Map=${OUTPUT_MAP_FILE_PATH}
        # Add cross-reference table to the map file
        -Wl,--cref
    )
endmacro()

macro(ft9xx_show_image_size excutable)
	set(BIN_FILE_PATH $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${excutable})
    add_custom_command(TARGET ${excutable}
        POST_BUILD
        # Print out size of image
        COMMAND ${CMAKE_SIZE_UTIL} --format=berkeley -x ${BIN_FILE_PATH}
    )
endmacro()

function(ft9xx_target_add_supported_library excutable lib_name)
    set(supported_lib_list fatfs FreeRTOS lwip mbedtls tinyprintf)
    if (${lib_name} IN_LIST supported_lib_list)
        message(STATUS "Found the lib ${lib_name} in the '3rdparty libraries'")
    else()
        message(FATAL_ERROR "The lib '${lib_name}' is not supported by FT9XX toolchain")
    endif()

    # Get the current value of the SOURCES property.
    get_target_property(current_source_list ${excutable} SOURCES)

    if (${lib_name} MATCHES lwip)
        list(APPEND current_source_list
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/polarssl/arc4.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/polarssl/des.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/polarssl/md4.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/polarssl/md5.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/polarssl/sha1.c

            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/auth.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/ccp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/chap-md5.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/chap-new.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/chap_ms.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/demand.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/eap.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/ecp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/eui64.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/fsm.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/ipcp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/ipv6cp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/lcp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/magic.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/mppe.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/multilink.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/ppp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/pppapi.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/pppcrypt.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/pppoe.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/pppol2tp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/pppos.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/upap.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/utils.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ppp/vj.c

            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/bridgeif.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/bridgeif_fdb.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/ethernet.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/lowpan6.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/lowpan6_ble.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/lowpan6_common.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/slipif.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/netif/zepif.c

            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/ipv4/autoip.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/ipv4/dhcp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/ipv4/etharp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/ipv4/icmp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/ipv4/igmp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/ipv4/ip4.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/ipv4/ip4_addr.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/ipv4/ip4_frag.c

            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/altcp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/altcp_alloc.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/altcp_tcp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/def.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/dns.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/inet_chksum.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/init.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/ip.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/mem.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/memp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/netif.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/pbuf.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/raw.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/stats.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/sys.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/tcp.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/tcp_in.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/tcp_out.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/timeouts.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/core/udp.c

            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/arch/net.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/arch/netif_ft900.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/arch/sys_arch.c

            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/api/api_lib.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/api/api_msg.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/api/err.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/api/if_api.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/api/netbuf.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/api/netdb.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/api/netifapi.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/api/sockets.c
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/api/tcpip.c
        )
        target_include_directories(${excutable} PRIVATE
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/arch
            ${TOOLCHAIN_3RDPARTY_LIB}/lwip/src/include
        )
    elseif (${lib_name} MATCHES FreeRTOS)
        list(APPEND current_source_list
            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/portable/MemMang/heap_1.c
            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/portable/MemMang/heap_2.c
            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/portable/MemMang/heap_3.c
            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/portable/MemMang/heap_4.c
            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/portable/MemMang/heap_5.c

            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/portable/GCC/FT32/port.c
            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/portable/GCC/FT32/port_extra.c

            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/croutine.c
            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/event_groups.c
            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/list.c
            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/queue.c
            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/tasks.c
            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/timers.c
        )
        target_include_directories(${excutable} PRIVATE
            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/include
            ${TOOLCHAIN_3RDPARTY_LIB}/FreeRTOS/Source/portable/GCC/FT32
        )
    elseif (${lib_name} MATCHES tinyprintf)
        list(APPEND current_source_list
            ${TOOLCHAIN_3RDPARTY_LIB}/tinyprintf/tinyprintf.c
        )
        target_include_directories(${excutable} PRIVATE
            ${TOOLCHAIN_3RDPARTY_LIB}/tinyprintf
        )
    elseif (${lib_name} MATCHES fatfs)
        list(APPEND current_source_list
            ${TOOLCHAIN_3RDPARTY_LIB}/fatfs/option/syscall.c
            ${TOOLCHAIN_3RDPARTY_LIB}/fatfs/option/unicode.c
            ${TOOLCHAIN_3RDPARTY_LIB}/fatfs/ff.c
            ${TOOLCHAIN_3RDPARTY_LIB}/fatfs/ffsystem.c
            ${TOOLCHAIN_3RDPARTY_LIB}/fatfs/ffunicode.c
        )
        target_include_directories(${excutable} PRIVATE
            ${TOOLCHAIN_3RDPARTY_LIB}/fatfs
            ${TOOLCHAIN_DRIVER_INCLUDE}
        )
    # elseif (${lib_name} MATCHES tiniprintf)
    else()
        message(FATAL_ERROR "The lib '${lib_name}' is not supported by FT9XX toolchain")
    endif()

    # Set the SOURCES property to the new list of source files.
    set_property(TARGET ${excutable} PROPERTY SOURCES ${current_source_list})
endfunction()
