# the name of the target operating system
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR FT9XX)

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
