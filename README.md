# Malware analysis of key loggers

When analysing a malware sample, and interesting function call to look for is the function

SetWindowsHookEx()

From the Microsoft documentation it says:

> Installs an application-defined hook procedure into a hook chain. You would install a hook procedure to monitor the system for certain types of events. These events are associated either with a specific thread or with all threads in the same desktop as the calling thread

So we can use this function to monitor for certain system events which sounds perfect for a keylogger.
To make this work the WH_KEYBOARD_LL hook type can be used to receive messages from keyboard input. You can see an example of this at the Microsoft page here https://learn.microsoft.com/en-us/windows/win32/winmsg/using-hooks

## Malware Analysis
As part of any malware analysis you will want to open the binary up in a tool like PEView. If the binary was created as a Windows executable then the PE file structure should be visible within PEView. As part of the PE file structure is a list of dynamically linked libraries and function names that are used from the Windows SDK.
As you can see below SetWindosHookExA is being used in our example application.

![Example from PEView](/example.jpg)

SetWindowsHookExA shows in the PE file structure.This is a good indicator that the malware may be using key logging.

## Licence

I learned about how to use SetWindowsHookEx by looking at code from Alexander Rymdeko-Harvey. You can view his GitHub page at https://github.com/killswitch-GUI/SetWindowsHookEx-Keylogger

His licence is attributed here.

File: SetWindowsHookEx-Keylogger Project
Author: Alexander Rymdeko-Harvey(@Killswitch-GUI)
License: BSD 3-Clause
Copyright (c) 2016, Alexander Rymdeko-Harvey All rights reserved.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
