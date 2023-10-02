
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

# Set the project name if it is not defined in the command line. (Move to toolchain_ft9xx.cmake).
if (NOT DEFINED ${PROJECT})
	cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME DEFAULT_PROJECT_NAME)  
	string(REPLACE " " "_" PROJECT ${DEFAULT_PROJECT_NAME})
	message(STATUS "Project name set to ${PROJECT}")
endif()
project(${PROJECT})

# Make sure the target we setup is supported
ft9xx_verify_target_name(${TARGET})

# Set some default configure to project
ft9xx_setup_project(${PROJECT})

# List of source files
file(GLOB SRC_FILES CONFIGURE_DEPENDS 
	Sources/*.c
	src/*.c
	hw/src/*.c
	usb/src/*.c
	drivers/*.c
)

# Build the executable based on the source files
add_executable(${EXECUTABLE} ${SRC_FILES})

# Add specific libs and linker option base on the target input (Must be ft90x or ft93x)
ft9xx_set_project_chipset(${EXECUTABLE} ${TARGET})

# Set the build type (Must be Debug or Release)
ft9xx_set_project_build_type(${EXECUTABLE} ${BUILD})

# List of include directories
target_include_directories(${EXECUTABLE} PRIVATE
	${FT9XX_TOOLCHAIN}
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
set(OUTPUT_MAP_FILE_PATH $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.map)
ft9xx_enable_map_file(${EXECUTABLE} ${OUTPUT_MAP_FILE_PATH})

# Print bin file size after build
set(BIN_FILE_PATH $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${EXECUTABLE})
ft9xx_show_image_size(${EXECUTABLE} ${BIN_FILE_PATH})
