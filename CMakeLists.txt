cmake_minimum_required(3.0.0)

# Project version is currently based on github commits until first release... (Placed in minor section)
project(VaultedThermals VERSION 0.108.0)

# The library was developed in conjunction with an engine compiled in MSVC C++17. 
set(CMAKE_CXX_STANDARD 17)

# Currently I am not aware if there is use of any features that require it to be at minimum C++17
# so the standard will not be enforced.
set(CMAKE_CXX_STANDARD_REQUIRED False)	


