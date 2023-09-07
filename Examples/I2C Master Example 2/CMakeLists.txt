set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE})

# Load the toolchain cmake file
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../toolchain_ft9xx.cmake)

# This one use to by pass the test build for compiler
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

# Project setup
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(I2C_Master_Example_2)
set(EXECUTABLE ${PROJECT_NAME}.elf)
set(OUTPUT_FOLDER_PRE "")
set(OUTPUT_FOLDER_POST "")
set(OUTPUT_FOLDER_NAME "")

# Language setup
enable_language(C ASM)

# List of source files
set(SRC_FILES
    i2cm_example2.c
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
    target_link_libraries(${EXECUTABLE} PRIVATE -lft900)
    string(APPEND OUTPUT_FOLDER_PRE "FT90X")
else ()
    message(FATAL_ERROR "The CHIPSET must me FT90X.")
endif()

set(OUTPUT_FOLDER_NAME ${OUTPUT_FOLDER_PRE}_${OUTPUT_FOLDER_POST})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/${OUTPUT_FOLDER_NAME})

# List of include directories
target_include_directories(${EXECUTABLE} PRIVATE
    Sources
    Includes
    ${TOOLCHAIN_HARDWARE_INCLUDE}
)

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
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
    -Wl,--gc-sections
    -Wl,--entry=_start
    -Wl,-Map=${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.map,--cref
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
