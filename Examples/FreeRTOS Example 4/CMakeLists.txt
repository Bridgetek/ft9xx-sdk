set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE})

# Load the toolchain cmake file
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../toolchain_ft9xx.cmake)

# This one use to by pass the test build for compiler
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

# Project setup
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(FreeRTOS_Example_4)
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

    # Main source
    free_rtos_example4.c
)

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
    target_link_libraries(${EXECUTABLE} PRIVATE -lft900_d2xx_dev_rtos -lft900)
    string(APPEND OUTPUT_FOLDER_PRE "FT90X")
    set(ASM_BUILD_FLAG --defsym __FT900__=1)
elseif (${CHIPSET} MATCHES FT93X)
    target_compile_definitions(${EXECUTABLE} PRIVATE -D__FT930__)
    target_link_options(${EXECUTABLE} PRIVATE -mft32b -mcompress)
    target_link_libraries(${EXECUTABLE} PRIVATE -lft930_d2xx_dev -lft930)
    string(APPEND OUTPUT_FOLDER_PRE "FT93X")
    set(ASM_BUILD_FLAG --defsym __FT930__=1)
else ()
    message(FATAL_ERROR "The CHIPSET must me FT90X or FT93X.")
endif()

set(OUTPUT_FOLDER_NAME ${OUTPUT_FOLDER_PRE}_${OUTPUT_FOLDER_POST})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/${OUTPUT_FOLDER_NAME})

# List of include directories
target_include_directories(${EXECUTABLE} PRIVATE
    lib/FreeRTOS/Source/include
    lib/FreeRTOS/Source/portable/GCC/FT32
    lib/tinyprintf
    src
    include
    ${TOOLCHAIN_HARDWARE_INCLUDE}
)

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
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

# Build the custom crt0 for d2xx
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
