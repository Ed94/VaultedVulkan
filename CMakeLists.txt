# CMAKE General -----------------------------------------------------------------------------------------

cmake_minimum_required (VERSION 3.8)

# Project version is currently based on github commits until first release... (Placed in minor section)
project ("VaultedThermals") #VERSION 0.108.0)

# C++ Configuration -------------------------------------------------------------------------------------

# The library was developed in conjunction with an engine compiled in MSVC C++17. 
#set(CMAKE_CXX_STANDARD 17)

# Currently I am not aware if there is use of any features that require it to be at minimum C++17
# so the standard will not be enforced.
#set(CMAKE_CXX_STANDARD_REQUIRED False)	

# Library Setup -----------------------------------------------------------------------------------------

# Add the cmake folder so the FindSphinx module is found
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_subdirectory ("Library")
add_subdirectory ("Doxygen")

# Doxygen -----------------------------------------------------------------------------------------------
