# CMAKE General -----------------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.14.0)

# Project version is currently based on github commits until first release... (Placed in minor section)
project(VaultedThermals VERSION 0.108.0)

include(ExternalProject)
include(FetchContent)

# C++ Configuration -------------------------------------------------------------------------------------

# The library was developed in conjunction with an engine compiled in MSVC C++17. 
set(CMAKE_CXX_STANDARD 17)

# Currently I am not aware if there is use of any features that require it to be at minimum C++17
# so the standard will not be enforced.
set(CMAKE_CXX_STANDARD_REQUIRED False)	

# Library Setup -----------------------------------------------------------------------------------------

#add_subdirectory(Library)

# Define library directory enviornmental variable.
set(Project_Library_Directory "Library")

# Define Library file index
set(LibFiles VaultedThermals)

# Index library files
#foreach(file ${LibFiles})
#    list(APPEND LibraryFiles ${Project_Library_Directory}/VaultedThermals/${file}.hpp)
#endforeach()

#list(APPEND LibraryFiles VaultedThermals.hpp)
 
#add_library(VaultedThermals ${LibraryFiles})

# CMAKE_GitClone ----------------------------------------------------------------------------------------

include(cmake/gitclone/cmake/GitUtils.cmake)

# Doxygen -----------------------------------------------------------------------------------------------

find_package(Doxygen)

# Check if doxygen is already installed on the users machine.
if (DOXYGEN_FOUND)

	# Set the I/O doxy files.
	set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxygen/Doxyfile.in)
	set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.out)

	# Request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # Note: Do not put "ALL" - this builds docs together with application EVERY TIME!
    add_custom_target( docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )

else (DOXYGEN_FOUND)

	# Doxygen was not found on users machine, cloning from github repository.
	#git_clone(
	#	PROJECT_NAME Doxygen
	#	GIT_URL https://github.com/doxygen/doxygen
	#	GIT_BRANCH master
	#	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Doxygen/Repository
	#)

	#ExternalProject_Add(
		# Name of library
		#Local_Doxygen

		# Cloning from gitub
		#GIT_REPOSITORY https://github.com/doxygen/doxygen
		#GIT_TAG origin/master

		# Arguments for building
	#	CMAKE_ARGS 
	#)

	# Building cloned repository...

	# Become aware of directory

	# See if built version can be used.
	#if (DOXYGEN_FOUND)

		# Set the I/O doxy files.
	#	set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxygen/Doxyfile.in)
	#	set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.out)

		# Request to configure the file
	#	configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
	#	message("Doxygen build started")

		# Note: Do not put "ALL" - this builds docs together with application EVERY TIME!
	#	add_custom_target( docs
		#	COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
	#		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		#	COMMENT "Generating API documentation with Doxygen"
		#	VERBATIM )

#	else (DOXYGEN_FOUND)

		#Doxygen not found, rip.
		message("Doxygen need to be installed to generate the doxygen documentation.")

	#endif (DOXYGEN_FOUND)

endif (DOXYGEN_FOUND)
