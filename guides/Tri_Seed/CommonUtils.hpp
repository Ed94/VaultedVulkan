#pragma once



// C++ STL
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>

// Cross Window
#include "CrossWindow/CrossWindow.h"



#if defined(XWIN_WIN32)

    #include <direct.h>
    
#else

    #include <unistd.h>
    
#endif



enum class EGetCwdChoice
{
    Regular,
    WinCwd
};

#ifdef XWIN_WIN32
    constexpr EGetCwdChoice CwdChoice = EGetCwdChoice::WinCwd;

    constexpr const char* PathDivider = "\\";
#else
    constexpr EGetCwdChoice CwdChoice = EGetCwdChoice::Regular;
    
    constexpr const char* PathDivider = "/";
#endif

template<EGetCwdChoice ChoosenCwd = CwdChoice>
inline typename std::enable_if<ChoosenCwd == EGetCwdChoice::WinCwd, char* >::type
GetCwd(char* _buffer, int _bufferSize)
{
	return _getcwd(_buffer, _bufferSize);
};

template<EGetCwdChoice ChoosenCwd = CwdChoice>
inline typename std::enable_if<ChoosenCwd == EGetCwdChoice::Regular, char* >::type 
GetCwd(char* _buffer, int _bufferSize)
{   
    return getcwd(_buffer, _bufferSize);
};

template<std::size_t size = 1> 
using CharBuffer = char[size];

inline std::vector<char> readFile(const std::string& filename) 
{
    constexpr std::size_t BufferSize = 1024;

	std::string path = filename;
	
	CharBuffer<BufferSize> bufferPath;

    GetCwd(bufferPath, BufferSize);

    path += PathDivider;
    path =  bufferPath ;
	path += filename   ;
	
	std::ifstream file(path, std::ios::ate | std::ios::binary);
    
	bool exists = (bool)file;

	if (!exists || !file.is_open()) 
    {
		throw std::runtime_error("Failed to open file!");
	}

	size_t fileSize = (size_t)file.tellg();

	std::vector<char> buffer(fileSize);

	file.seekg(0);

	file.read(buffer.data(), fileSize);

	file.close();

	return buffer;
};