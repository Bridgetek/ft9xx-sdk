# the name of the target operating system
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR FT9XX)

# Search command for Linux/Windows
if(MINGW OR CYGWIN OR WIN32)
    set(UTIL_SEARCH_CMD where)
elseif(UNIX OR APPLE)
    set(UTIL_SEARCH_CMD which)
endif()

# Set the toolchain prefix
set(TOOLCHAIN_PREFIX ft32-elf-)

# Get the path form the binutils search
execute_process(
    COMMAND ${UTIL_SEARCH_CMD} ${TOOLCHAIN_PREFIX}gcc
        OUTPUT_VARIABLE
        BINUTILS_PATH
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Get the folder that contain toolchain
get_filename_component(FT9XX_TOOLCHAIN_DIR ${BINUTILS_PATH} DIRECTORY)

# which compilers to use for C and C++
set(CMAKE_C_COMPILER   ${TOOLCHAIN_PREFIX}gcc.exe)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}as.exe)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++.exe)
set(CMAKE_OBJCOPY      ${TOOLCHAIN_PREFIX}objcopy CACHE INTERNAL "Objcopy tool")
set(CMAKE_SIZE_UTIL    ${TOOLCHAIN_PREFIX}size    CACHE INTERNAL "Size tool")

# where is the target environment located
set(CMAKE_FIND_ROOT_PATH ${BINUTILS_PATH})

# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# --------------------------------------------------------------------------- #
# Default configure

# Default toolchain path
set(TOOLCHAIN_HARDWARE_INCLUDE     "$ENV{FT9XX_TOOLCHAIN}/hardware/include")
set(TOOLCHAIN_HARDWARE_LIB         "$ENV{FT9XX_TOOLCHAIN}/hardware/lib")
set(TOOLCHAIN_HARDWARE_LIB_DEBUG   "$ENV{FT9XX_TOOLCHAIN}/hardware/lib/Debug")
set(TOOLCHAIN_HARDWARE_LIB_RELEASE "$ENV{FT9XX_TOOLCHAIN}/hardware/lib/Release")

# Setup the default compile flag for debug/release build type
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Og -g -fvar-tracking -fvar-tracking-assignments -Wall -c -fmessage-length=0 -ffunction-sections")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-fvar-tracking -fvar-tracking-assignments -Wall -c -fmessage-length=0 -ffunction-sections")
