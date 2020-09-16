# Cmake source was taken from: https://github.com/alaingalvan/vulkan-seed and modified for use in this guide set.

# Project Info 

cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
cmake_policy(VERSION 3.14)
project(VT_Guides
        VERSION 0.1.0
        LANGUAGES CXX
)

# =============================================================

# CMake Settings

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_SUPPRESS_REGENERATION true)
set(DCMAKE_GENERATOR_PLATFORM "x64")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

# =============================================================

# Options

set(XGFX_API VULKAN CACHE STRING "Which graphics API to use, defaults to AUTO, can be NOOP, VULKAN, OPENGL, DIRECTX12, or METAL.")
set_property(
    CACHE
    XGFX_API PROPERTY
    STRINGS VULKAN
)

# =============================================================

# Dependencies

# CrossWindow
message(STATUS "Installing crosswindow via submodule")
add_subdirectory(_ThirdParty/crosswindow)
set_property(TARGET CrossWindow PROPERTY FOLDER "Dependencies")

# CrossWindow-Graphics
#message(STATUS "Installing crosswindow-graphics via submodule")
#add_subdirectory(_ThirdParty/crosswindow-graphics)

# GLM
message(STATUS "Installing glm via submodule")
set(BUILD_STATIC_LIBS ON)
add_subdirectory(_ThirdParty/glm/glm)
set_property(TARGET glm_static PROPERTY FOLDER "Dependencies")

# =============================================================

# Cross Graphics Dependencies
find_path(VULKAN_INCLUDE_DIR NAMES vulkan/vulkan.h HINTS
    "$ENV{VULKAN_SDK}/include"
    "$ENV{VULKAN_SDK}/Include"
    "$ENV{VK_SDK_PATH}/Include")
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    find_library(XGFX_LIBRARY
        NAMES vulkan-1 vulkan vulkan.1
        HINTS
        "$ENV{VULKAN_SDK}/lib"
        "$ENV{VULKAN_SDK}/Lib"
        "$ENV{VULKAN_SDK}/Bin"
        "$ENV{VK_SDK_PATH}/Bin")
else()
    find_library(XGFX_LIBRARY
                NAMES vulkan-1 vulkan vulkan.1
                HINTS
        "$ENV{VULKAN_SDK}/Lib32"
        "$ENV{VULKAN_SDK}/Bin32"
        "$ENV{VK_SDK_PATH}/Bin32")
endif()


# =============================================================

# Sources
get_filename_component(PARENT_DIR ../ ABSOLUTE)

include_directories(${PARENT_DIR}/include/)
include_directories(_Common/)

# Make Guide project macro.
macro(MakeGuide guide)

    set(guide "${PROJECT_NAME}_${guide}")

# File Stuff
       file(GLOB_RECURSE "FILE_SOURCES_${guide}" RELATIVE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/_Common/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/${guide}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/${guide}/*.h
        ${PARENT_DIR}/include/*.hpp
    )
    
    # Solution Filters
    foreach(source IN LISTS "FILE_SOURCES_${guide}")
        get_filename_component(source_path "${source}" PATH)
        string(REPLACE "/" "\\" source_path_msvc "${source_path}")
        string(REPLACE "${guide}" "" source_path_final "${source_path_msvc}")
        source_group("${source_path_final}" FILES "${source}")
    endforeach()

# =============================================================
    
# Finalize App

    # VT Guide: Triangle Seed
    xwin_add_executable(
        ${guide}
        "${FILE_SOURCES_${guide}}"
    )

# =============================================================

# Finish Dependencies
    target_link_libraries(${guide}
        ${XGFX_LIBRARY}
        CrossWindow
        glm_static
    )

    target_include_directories(${guide}
    PUBLIC _ThirdParty/glm
    PUBLIC ${VULKAN_INCLUDE_DIR}
    )

    add_dependencies(${guide}
        CrossWindow
        glm_static
    )

    target_compile_definitions(${guide}
    PUBLIC XGFX_${XGFX_API}=1
    )

# =============================================================

# Finish Settings

    # Change output dir to bin
    set_target_properties(${guide} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
    # Change working directory to top dir to access `assets/shaders/` folder
    if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        set_property(TARGET ${guide} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/..)
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${guide})
    endif()

endmacro()

# Make all the guides.
MakeGuide(1_Intro)
MakeGuide(TriSeed)
MakeGuide(UserSpace)