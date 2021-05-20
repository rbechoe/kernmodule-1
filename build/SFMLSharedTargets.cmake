# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.18)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget sfml-system sfml-main sfml-window OpenGL sfml-network sfml-graphics Freetype OpenAL Vorbis FLAC sfml-audio)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target sfml-system
add_library(sfml-system SHARED IMPORTED)

set_target_properties(sfml-system PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/SFML-2.5.1/include"
)

# Create imported target sfml-main
add_library(sfml-main STATIC IMPORTED)

set_target_properties(sfml-main PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/SFML-2.5.1/include"
)

# Create imported target sfml-window
add_library(sfml-window SHARED IMPORTED)

set_target_properties(sfml-window PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/SFML-2.5.1/include"
  INTERFACE_LINK_LIBRARIES "sfml-system"
)

# Create imported target OpenGL
add_library(OpenGL INTERFACE IMPORTED)

set_target_properties(OpenGL PROPERTIES
  INTERFACE_LINK_LIBRARIES "opengl32;glu32"
)

# Create imported target sfml-network
add_library(sfml-network SHARED IMPORTED)

set_target_properties(sfml-network PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/SFML-2.5.1/include"
  INTERFACE_LINK_LIBRARIES "sfml-system"
)

# Create imported target sfml-graphics
add_library(sfml-graphics SHARED IMPORTED)

set_target_properties(sfml-graphics PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/SFML-2.5.1/include"
  INTERFACE_LINK_LIBRARIES "sfml-window"
)

# Create imported target Freetype
add_library(Freetype INTERFACE IMPORTED)

set_target_properties(Freetype PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/SFML-2.5.1/extlibs/headers/freetype2"
  INTERFACE_LINK_LIBRARIES "C:/SFML-2.5.1/extlibs/libs-mingw/x64/libfreetype.a"
)

# Create imported target OpenAL
add_library(OpenAL INTERFACE IMPORTED)

set_target_properties(OpenAL PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/SFML-2.5.1/extlibs/headers/AL"
  INTERFACE_LINK_LIBRARIES "C:/SFML-2.5.1/extlibs/libs-mingw/x64/libopenal32.a"
)

# Create imported target Vorbis
add_library(Vorbis INTERFACE IMPORTED)

set_target_properties(Vorbis PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "OV_EXCLUDE_STATIC_CALLBACKS"
  INTERFACE_INCLUDE_DIRECTORIES "C:/SFML-2.5.1/extlibs/headers;C:/SFML-2.5.1/extlibs/headers"
  INTERFACE_LINK_LIBRARIES "C:/SFML-2.5.1/extlibs/libs-mingw/x64/libvorbisenc.a;C:/SFML-2.5.1/extlibs/libs-mingw/x64/libvorbisfile.a;C:/SFML-2.5.1/extlibs/libs-mingw/x64/libvorbis.a;C:/SFML-2.5.1/extlibs/libs-mingw/x64/libogg.a"
)

# Create imported target FLAC
add_library(FLAC INTERFACE IMPORTED)

set_target_properties(FLAC PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "FLAC__NO_DLL"
  INTERFACE_INCLUDE_DIRECTORIES "C:/SFML-2.5.1/extlibs/headers"
  INTERFACE_LINK_LIBRARIES "C:/SFML-2.5.1/extlibs/libs-mingw/x64/libFLAC.a"
)

# Create imported target sfml-audio
add_library(sfml-audio SHARED IMPORTED)

set_target_properties(sfml-audio PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/SFML-2.5.1/include"
  INTERFACE_LINK_LIBRARIES "sfml-system"
)

# Import target "sfml-system" for configuration "Release"
set_property(TARGET sfml-system APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sfml-system PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/HKU/kernmodule-1/build/lib/libsfml-system.a"
  IMPORTED_LOCATION_RELEASE "C:/HKU/kernmodule-1/build/lib/sfml-system-2.dll"
  )

# Import target "sfml-main" for configuration "Release"
set_property(TARGET sfml-main APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sfml-main PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "C:/HKU/kernmodule-1/build/lib/libsfml-main.a"
  )

# Import target "sfml-window" for configuration "Release"
set_property(TARGET sfml-window APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sfml-window PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/HKU/kernmodule-1/build/lib/libsfml-window.a"
  IMPORTED_LOCATION_RELEASE "C:/HKU/kernmodule-1/build/lib/sfml-window-2.dll"
  )

# Import target "sfml-network" for configuration "Release"
set_property(TARGET sfml-network APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sfml-network PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/HKU/kernmodule-1/build/lib/libsfml-network.a"
  IMPORTED_LOCATION_RELEASE "C:/HKU/kernmodule-1/build/lib/sfml-network-2.dll"
  )

# Import target "sfml-graphics" for configuration "Release"
set_property(TARGET sfml-graphics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sfml-graphics PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/HKU/kernmodule-1/build/lib/libsfml-graphics.a"
  IMPORTED_LOCATION_RELEASE "C:/HKU/kernmodule-1/build/lib/sfml-graphics-2.dll"
  )

# Import target "sfml-audio" for configuration "Release"
set_property(TARGET sfml-audio APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sfml-audio PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/HKU/kernmodule-1/build/lib/libsfml-audio.a"
  IMPORTED_LOCATION_RELEASE "C:/HKU/kernmodule-1/build/lib/sfml-audio-2.dll"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
