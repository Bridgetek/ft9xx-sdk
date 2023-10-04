# Standard Makefile Actions for FT9xx project compilation.

# Setup for FT9xx
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
set(TOOLCHAIN_HARDWARE_INCLUDE     "${TOOLCHAIN_DIR}/hardware/include")
set(TOOLCHAIN_HARDWARE_LIB         "${TOOLCHAIN_DIR}/hardware/lib")
set(TOOLCHAIN_HARDWARE_LIB_DEBUG   "${TOOLCHAIN_HARDWARE_LIB}/Debug")
set(TOOLCHAIN_HARDWARE_LIB_RELEASE "${TOOLCHAIN_HARDWARE_LIB}/Release")

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

macro(ft9xx_set_executable executable srcfiles libfiles ldscript)
    # Language setup
    enable_language(C ASM)

    # Add default include directory for project
    include_directories(
        ${TOOLCHAIN_HARDWARE_INCLUDE}
    )

	# Build the executable based on the source files.
	add_executable(${executable} ${srcfiles})

    # Add default compiler option for project
    target_compile_options(${executable} PRIVATE $<$<COMPILE_LANGUAGE:C>:
        -fvar-tracking-assignments
        -Wall
        -c
        -fmessage-length=0
        -ffunction-sections
		>
    )
    # Add default linker option for project
    target_link_options(${executable} PRIVATE 
        -Wl,--gc-sections
        -Wl,--entry=_start
    )

	# Reformulate srcfiles as a list.
	set(_srcfiles ${srcfiles} ${ARGN})
	# Do not load startup files if crt0 source file exists.
	foreach (srcfile IN LISTS _srcfiles)
		if (${srcfile} MATCHES ".*crt0.*\.S$")
			message(STATUS "crt0 file detected: ${srcfile}")
			target_link_libraries(${EXECUTABLE} PRIVATE -nostartfiles)
			break()
		endif()
	endforeach()
	
	if (${ldscript} MATCHES ".*\.ld$")
		message(STATUS "Linker script file: ${ldscript}")
		target_link_libraries(${EXECUTABLE} PRIVATE -Xlinker -dT "${ldscript}" )
	endif()

	# Set build-specific settings.
    if (${BUILD} MATCHES Debug)
        target_compile_options(${executable} PRIVATE $<$<COMPILE_LANGUAGE:C>:-g -Og>)
        target_link_libraries(${executable} PRIVATE -L"${TOOLCHAIN_HARDWARE_LIB_DEBUG}")
        set(ENV{FT9XX_OUTPUT_FOLDER_POST} Debug)
    elseif (${BUILD} MATCHES Release)
        target_compile_options(${executable} PRIVATE $<$<COMPILE_LANGUAGE:C>:-Os>)
        target_link_libraries(${executable} PRIVATE -L"${TOOLCHAIN_HARDWARE_LIB_RELEASE}")
        set(ENV{FT9XX_OUTPUT_FOLDER_POST} Release)
    else ()
		# Double check BUILD
        message(FATAL_ERROR "The BUILD type should be Debug or Release.")
    endif()

	# Add optional libraries before toolchain libraries.
	target_link_libraries(${EXECUTABLE} PRIVATE ${libfiles})
	
	# Set target-specific settings.
    if (${TARGET} MATCHES ft90x)
		target_compile_definitions(${executable} PRIVATE $<$<COMPILE_LANGUAGE:C>:__FT900__>)
        target_compile_definitions(${executable} PRIVATE $<$<COMPILE_LANGUAGE:ASM>:__FT900__=1>)
        target_link_options(${executable} PRIVATE -D__FT900__)
        target_link_libraries(${executable} PRIVATE -lft900)
        set(ENV{FT9XX_OUTPUT_FOLDER_PRE} FT90x)
    elseif (${TARGET} MATCHES ft93x)
        target_compile_definitions(${executable} PRIVATE $<$<COMPILE_LANGUAGE:C>:__FT930__>)
        target_compile_definitions(${executable} PRIVATE $<$<COMPILE_LANGUAGE:ASM>:__FT930__=1>)
        target_link_options(${executable} PRIVATE -D__FT930__)
        target_link_options(${executable} PRIVATE -mft32b -mcompress)
        target_link_libraries(${executable} PRIVATE -lft930)
        set(ENV{FT9XX_OUTPUT_FOLDER_PRE} FT93x)
    else ()
		# Double check TARGET
        message(FATAL_ERROR "The TARGET must me ft90x or ft93x.")
    endif()

    # Set the build mode to Debug or Release.
    set(CMAKE_BUILD_MODE ${BUILD})

	if("${OUTDIR}" STREQUAL "")
		# Set the ouput folder for the elf, bin, map,...
		set(ENV{FT9XX_OUTPUT_FOLDER_NAME} $ENV{FT9XX_OUTPUT_FOLDER_PRE}_$ENV{FT9XX_OUTPUT_FOLDER_POST})
		set(ENV{FT9XX_EXECUTABLE_OUTPUT_PATH} ${CMAKE_SOURCE_DIR}/$ENV{FT9XX_OUTPUT_FOLDER_NAME})
	else()
		set(ENV{FT9XX_EXECUTABLE_OUTPUT_PATH} ${CMAKE_SOURCE_DIR}/${OUTDIR})
	endif()
	message(STATUS "Output directory has been set to $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}.")

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

	# Enable printing of the executable program size after compilation.
    add_custom_command(TARGET ${executable}
        POST_BUILD
        # Print out size of image
        COMMAND ${CMAKE_SIZE_UTIL} --format=berkeley -x $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.elf
    )
endmacro()

macro(ft9xx_target_add_libraries target libraries)
    target_link_libraries(${target} PRIVATE ${libraries})
endmacro()

macro(ft9xx_target_add_library excutable lib_name)
    target_link_libraries(${excutable} PRIVATE ${lib_name})
endmacro()

macro(ft9xx_enable_map_file excutable)
	set(OUTPUT_MAP_FILE_PATH $ENV{FT9XX_EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.map)
    target_link_libraries(${excutable} PRIVATE
        # Enable the map file
        -Wl,-Map="${OUTPUT_MAP_FILE_PATH}"
        # Add cross-reference table to the map file
        -Wl,--cref
    )
endmacro()
