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

# VT Guide: Triangle Seed
    file(GLOB_RECURSE FILE_SOURCES_TriSeed RELATIVE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Tri_Seed/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Tri_Seed/*.h
        ${PARENT_DIR}/include/*.hpp
    )
    
    # Solution Filters
    foreach(source IN LISTS FILE_SOURCES_TriSeed)
        get_filename_component(source_path "${source}" PATH)
        string(REPLACE "/" "\\" source_path_msvc "${source_path}")
        string(REPLACE "Tri_Seed" "" source_path_final "${source_path_msvc}")
        source_group("${source_path_final}" FILES "${source}")
    endforeach()
    
# VT Guide: User Space
    file(GLOB_RECURSE FILE_SOURCES_UserSpace RELATIVE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/UserSpace/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/UserSpace/*.h
        ${PARENT_DIR}/include/*.hpp
    )

    # Solution Filters
    foreach(source IN LISTS FILE_SOURCES_UserSpace)
        get_filename_component(source_path "${source}" PATH)
        string(REPLACE "/" "\\" source_path_msvc "${source_path}")
        string(REPLACE "UserSpace" "" source_path_final "${source_path_msvc}")
        source_group("${source_path_final}" FILES "${source}")
    endforeach()

# =============================================================

# Finalize App

# VT Guide: Triangle Seed
xwin_add_executable(
    "${PROJECT_NAME}_TriSeed"
    "${FILE_SOURCES_TriSeed}"
)

# VT Guide: User Space
xwin_add_executable(
    "${PROJECT_NAME}_UserSpace"
    "${FILE_SOURCES_UserSpace}"
)

# =============================================================

# Finish Dependencies

# VT Guide: Triangle Seed
    target_link_libraries(
        "${PROJECT_NAME}_TriSeed"
        ${XGFX_LIBRARY}
        #CrossWindowGraphics
        CrossWindow
        glm_static
    )

    target_include_directories(
        "${PROJECT_NAME}_TriSeed"
    PUBLIC _ThirdParty/glm
    PUBLIC ${VULKAN_INCLUDE_DIR}
    )

    add_dependencies(
        "${PROJECT_NAME}_TriSeed"
        #CrossWindowGraphics
        CrossWindow
        glm_static
    )

    target_compile_definitions(
        "${PROJECT_NAME}_TriSeed"
    PUBLIC XGFX_${XGFX_API}=1
    )

# VT Guide: User Space
    target_link_libraries(
        "${PROJECT_NAME}_UserSpace"
        ${XGFX_LIBRARY}
        #CrossWindowGraphics
        CrossWindow
        glm_static
    )

    target_include_directories(
        "${PROJECT_NAME}_UserSpace"
    PUBLIC _ThirdParty/glm
    PUBLIC ${VULKAN_INCLUDE_DIR}
    )

    add_dependencies(
        "${PROJECT_NAME}_UserSpace"
        #CrossWindowGraphics
        CrossWindow
        glm_static
    )

    target_compile_definitions(
        "${PROJECT_NAME}_UserSpace"
    PUBLIC XGFX_${XGFX_API}=1
    )

# =============================================================

# Finish Settings

# VT Guide: Triangle Seed
    # Change output dir to bin
    set_target_properties("${PROJECT_NAME}_TriSeed" PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
    # Change working directory to top dir to access `assets/shaders/` folder
    if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        set_property(TARGET "${PROJECT_NAME}_TriSeed" PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/..)
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "${PROJECT_NAME}_TriSeed")
    endif()
    
# VT Guide: Triangle Seed
    # Change output dir to bin
    set_target_properties("${PROJECT_NAME}_UserSpace" PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
    # Change working directory to top dir to access `assets/shaders/` folder
    if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        set_property(TARGET "${PROJECT_NAME}_UserSpace" PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/..)
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "${PROJECT_NAME}_UserSpace")
    endif()