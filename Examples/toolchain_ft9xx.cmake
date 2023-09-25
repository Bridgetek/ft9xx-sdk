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

macro(ft9xx_setup_project projectName)
    set(EXECUTABLE ${projectName}.elf)

    # Language setup
    enable_language(C ASM)

    # Add default include directory for project
    include_directories(
        Sources
        Includes
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

    link_libraries(-lc -lstub)
endmacro()

macro(ft9xx_target_add_libraries target libraries)
    target_link_libraries(${target} PRIVATE ${libraries})
endmacro()

macro(ft9xx_set_project_chipset excutable chipset)
    if (${chipset} MATCHES FT90X)
        target_compile_definitions(${excutable} PRIVATE -D__FT900__)
        target_link_libraries(${excutable} PRIVATE -lft900)
        set(ENV{FT9XX_OUTPUT_FOLDER_PRE} FT90X)
    elseif (${chipset} MATCHES FT93X)
        target_compile_definitions(${excutable} PRIVATE -D__FT930__)
        target_link_options(${excutable} PRIVATE -mft32b -mcompress)
        target_link_libraries(${excutable} PRIVATE -lft930)
        set(ENV{FT9XX_OUTPUT_FOLDER_PRE} FT93X)
    else ()
        message(FATAL_ERROR "The TARGET must me FT90X or FT93X.")
    endif()
endmacro()

macro(ft9xx_set_project_build_type excutable mode)
    # Setup library for linker step
    if (${mode} MATCHES Debug)
        target_link_libraries(${excutable} PRIVATE -L"${TOOLCHAIN_HARDWARE_LIB_DEBUG}")
        target_compile_options(${excutable} PRIVATE -g -Og)
        set(ENV{FT9XX_OUTPUT_FOLDER_POST} Debug)
    elseif (${mode} MATCHES Release)
        target_link_libraries(${excutable} PRIVATE -L"${TOOLCHAIN_HARDWARE_LIB_RELEASE}")
        target_compile_options(${excutable} PRIVATE -O3)
        set(ENV{FT9XX_OUTPUT_FOLDER_POST} Release)
    else ()
        message(FATAL_ERROR "The build type should be Debug or Release.")
    endif()

    message(STATUS "ENV{FT9XX_OUTPUT_FOLDER_PRE}: $ENV{FT9XX_OUTPUT_FOLDER_PRE}")

    # Set the ouput folder for the elf, bin, map,...
    set(ENV{FT9XX_OUTPUT_FOLDER_NAME} $ENV{FT9XX_OUTPUT_FOLDER_PRE}_$ENV{FT9XX_OUTPUT_FOLDER_POST})
    set(ENV{FT9XX_EXECUTABLE_OUTPUT_PATH} ${CMAKE_SOURCE_DIR}/$ENV{FT9XX_OUTPUT_FOLDER_NAME})

    set_target_properties(${excutable}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "$ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}"
    )

    # Print the size of excutable file after build *.elf successfully
    add_custom_command(TARGET ${excutable}
        POST_BUILD
        # Create bin file
        COMMAND ${CMAKE_OBJCOPY} --output-target binary
            $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.elf
            $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.bin
    )
endmacro()

macro(ft9xx_enable_map_file excutable output_path)
    target_link_options(${excutable} PRIVATE
        # Enable the map file
        -Wl,-Map=${output_path}
        # Add cross-reference table to the map file
        -Wl,--cref
    )
endmacro()

macro(ft9xx_show_image_size target excutable_path)
    add_custom_command(TARGET ${target}
        POST_BUILD
        # Print out size of image
        COMMAND ${CMAKE_SIZE_UTIL} --format=berkeley -x ${excutable_path}
    )
endmacro()
