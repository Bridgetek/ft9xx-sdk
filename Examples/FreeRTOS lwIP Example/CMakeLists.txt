
# Load the toolchain cmake file
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../toolchain_ft9xx.cmake)

# Project setup
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Set the project name
project(FreeRTOS_lwip_Example)

# Mention the linker script for project
set(LINKER_FILE ${CMAKE_SOURCE_DIR}/Scripts/freertos.ld)

# Set some default configure to project
ft9xx_setup_project(${PROJECT_NAME})

# List of source files
set(SRC_FILES
    # Main source
    Sources/main.c
)

# Build the executable based on the source files
add_executable(${EXECUTABLE} ${SRC_FILES})

# Add specific libs and linker option base on the target input
# WARNING: This project does not suppot FT93X
if (${TARGET} MATCHES FT93X)
    message(FATAL_ERROR "This project does not suppot FT93X.")
endif()
ft9xx_set_project_chipset(${EXECUTABLE} ${TARGET})

# Set the build type (Must be Debug or Release)
ft9xx_set_project_build_type(${EXECUTABLE} ${BUILD})

# Add the supported library
ft9xx_target_add_supported_library(${EXECUTABLE} lwip)
ft9xx_target_add_supported_library(${EXECUTABLE} FreeRTOS)

# List of include directories
target_include_directories(${EXECUTABLE} PRIVATE
    # Add your here
)

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
    -DFT32_FREERTOS
    -DFT32_PORT
    -DFT32_PORT_HEAP=4
    # Add your here
)

# Linker library options
target_link_libraries(${EXECUTABLE} PRIVATE
    # Add your here
)

# Linker options
target_link_options(${EXECUTABLE} PRIVATE
    -nostartfiles
    -Xlinker -dT ${LINKER_FILE}

    $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/crt0.o
    $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/portasm.o
)

# Build the custom crt0, this step must be PRE_BUILD
add_custom_command(TARGET ${EXECUTABLE}
    PRE_BUILD
    COMMAND ${CMAKE_ASM_COMPILER}
        ${ASM_BUILD_FLAG}
        -I"${CMAKE_SOURCE_DIR}/Includes"
        ${CMAKE_SOURCE_DIR}/Sources/crt0.S
        -o $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/crt0.o

    COMMAND ${CMAKE_ASM_COMPILER}
        ${ASM_BUILD_FLAG}
        -I"${CMAKE_SOURCE_DIR}/Includes"
        ${CMAKE_SOURCE_DIR}/lib/FreeRTOS/Source/portable/GCC/FT32/portasm.S
        -o $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/portasm.o
)

# Setup the file path for the mapfile if needed
set(OUTPUT_MAP_FILE_PATH $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.map)
ft9xx_enable_map_file(${EXECUTABLE} ${OUTPUT_MAP_FILE_PATH})

# Print bin file size after build
set(BIN_FILE_PATH $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${EXECUTABLE})
ft9xx_show_image_size(${EXECUTABLE} ${BIN_FILE_PATH})
