# Malware anslysis of key loggers

When analysing a malware sample, and interesting function call to look for is the function

SetWindowsHookEx()

From the Microsoft documentation it says:

> Installs an application-defined hook procedure into a hook chain. You would install a hook procedure to monitor the system for certain types of events. These events are associated either with a specific thread or with all threads in the same desktop as the calling thread

So we can use this function to monitor for certain system events which sounds perfect for a keylogger.
To make this work the WH_KEYBOARD_LL hook type can be used to receive messages from keyboard input. You can see an example of this at the Microsoft page here https://learn.microsoft.com/en-us/windows/win32/winmsg/using-hooks

## Malware Analysis
As part of any malware analysis you will want to open the binary up in a tool like PEView. If the binary was created as a Windows executable then the PE file structure should be visible within PEView. As part of the PE file structure is a list of dynamically linked libraries and function names that are used from the Windows SDK.
As you can see below SetWindosHookExA is being used in our example application.



SetWindowsHookExA shows in the PE file structure.This is a good indicator that the malware may be using key logging.
