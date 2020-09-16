#pragma once



// C++ STL
#include <algorithm>
#include <ctime>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

// Cross Window
#include "CrossWindow/CrossWindow.h"

enum class EPlatform
{
	EverythingElse = 0,

	// Only windows is special for now...
    Win32 = XWIN_WIN32
};

#if defined(XWIN_WIN32)
    #include <direct.h>

	constexpr auto XPlatform = EPlatform::Win32;
#else
    #include <unistd.h>

	constexpr auto XPlatform = EPlatform::EverythingElse;
#endif

template<EPlatform = EverythingElse>
struct PlatformSpecific
{
	static char* GetCwd(char* _buffer, int _bufferSize)
	{
		return getcwd(_buffer, _bufferSize);
	}
    
    static constexpr const char* PathDivider = "/";
};

template<>
struct PlatformSpecific<EPlatform::Win32>
{
	static char* GetCwd(char* _buffer, int _bufferSize)
	{
		return _getcwd(_buffer, _bufferSize);
	}

	static constexpr const char* PathDivider = "\\";
};

constexpr auto GetCwd      = PlatformSpecific<XPlatform>::GetCwd     ;
constexpr auto PathDivider = PlatformSpecific<XPlatform>::PathDivider;

// Clang-CL does not like window's offsetof macro.
template<typename StructType, typename StructMemberType>
constexpr 
std::size_t TOffsetOf(StructMemberType StructType::* _member)
{
	return reinterpret_cast<std::size_t>(&((StructType*)(0)->*_member));
}

#define OffsetOf(_MEMBEER) TOffsetOf(&_MEMBEER);

template<std::size_t size = 1> 
using CharBuffer = char[size];

inline std::vector<char> ReadFile(const std::string& filename) 
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

// Extermely barbones console out logger to file.
class LogFile
{
public:
	LogFile()
	{
		const std::time_t logTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

		std::tm calendarDate;

		// Make platform agnostic:
		localtime_s(&calendarDate, &logTime);

		std::stringstream dateStream;

		dateStream << std::put_time(&calendarDate, "%F_%I-%M-%S_%p");

		std::filesystem::path filePath(std::string("Log") + std::string("__") + dateStream.str() + std::string(".txt") );

		file.open( filePath );

		if (!file.is_open()) throw std::runtime_error("Failed to open the file to log console out.");
	}

	~LogFile()
	{
		file.close();
	}

	void Write(std::string _log)
	{
		file << _log << std::endl;
	}

private:
	std::ofstream file;
};

// Simple wrapped logger...
inline void LOG(std::string _whatToLog)
{
	static LogFile _LogFile;

	std::cout << _whatToLog << std::endl;

	_LogFile.Write(_whatToLog);
}