
# Load the toolchain cmake file
if (EXISTS ${CMAKE_SOURCE_DIR}/toolchain_ft9xx.cmake)
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../toolchain_ft9xx.cmake)
elseif (EXISTS ${CMAKE_SOURCE_DIR}/../toolchain_ft9xx.cmake)
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../toolchain_ft9xx.cmake)
elseif (EXISTS $ENV{FT9XX_TOOLCHAIN}/hardware/toolchain_ft9xx.cmake)
    set(CMAKE_TOOLCHAIN_FILE $ENV{FT9XX_TOOLCHAIN}/hardware/toolchain_ft9xx.cmake)
else()
    message(FATAL_ERROR "Make sure that the FT9XX is installed correctly. Can't found the 'toolchain_ft9xx.cmake' file")
endif()

# Project setup
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Set the project name
project(ADC_Example_2)

# Make sure the target we setup is supported
ft9xx_verify_target_name(${TARGET})

# Set some default configure to project
ft9xx_setup_project(${PROJECT_NAME})

# List of source files
set(SRC_FILES
    Sources/adc_example2.c
)

# Build the executable based on the source files
add_executable(${EXECUTABLE} ${SRC_FILES})

# Add specific libs and linker option base on the target input
ft9xx_set_project_chipset(${EXECUTABLE} ${TARGET})

# Set the build type (Must be Debug or Release)
ft9xx_set_project_build_type(${EXECUTABLE} ${BUILD})

# List of include directories
target_include_directories(${EXECUTABLE} PRIVATE
    # Add your here
)

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
    # Add your here
)

# Linker library options
target_link_libraries(${EXECUTABLE} PRIVATE
    # Add your here
)

# Setup the file path for the mapfile if needed
set(OUTPUT_MAP_FILE_PATH $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.map)
ft9xx_enable_map_file(${EXECUTABLE} ${OUTPUT_MAP_FILE_PATH})

# Print bin file size after build
set(BIN_FILE_PATH $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${EXECUTABLE})
ft9xx_show_image_size(${EXECUTABLE} ${BIN_FILE_PATH})
