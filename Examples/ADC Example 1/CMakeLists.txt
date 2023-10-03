
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

# Set the project name to the current directory if it is not defined in the command line.
if (NOT DEFINED ${PROJECT})
	get_filename_component(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)
	string(REPLACE " " "_" PROJECT ${PROJECT_DIR})
	message(STATUS "Project name set to ${PROJECT}")
endif()

project(${PROJECT})
set(EXECUTABLE ${PROJECT}.elf)

# Setup project default configure to project
ft9xx_setup_project()

# List of source files
file(GLOB SRC_FILES CONFIGURE_DEPENDS 
	Sources/*.c
	src/*.c
	hw/src/*.c
	usb/src/*.c
	drivers/*.c
)

# Replace perform add_executable and make default settings for BUILD and TARGET.
ft9xx_set_executable(${EXECUTABLE} ${SRC_FILES})

# List of include directories
target_include_directories(${EXECUTABLE} PRIVATE
	Includes
	hardware/include
	hw/include
	usb/include
	drivers
)

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
	# Add your compiler options here
)

# Linker library options
target_link_libraries(${EXECUTABLE} PRIVATE
    # Add your libraries here:
	# ft900_d2xx_dev
	# ft930_d2xx_dev
	# ftd2xx_host
)

# Setup the file path for the mapfile if needed
ft9xx_enable_map_file(${EXECUTABLE})

# Print bin file size after build
ft9xx_show_image_size(${EXECUTABLE})
