#include "pch.h"
#include "Features.h"
#include <windows.h> // Required for Sleep, keybd_event, and RegisterHotKey

bool IsAutoRunChecked()
{
    return SendMessage(AutoRun, BM_GETCHECK, 0, 0) == BST_CHECKED;
}

void ReleaseKeys()
{
    keybd_event('W', 0, KEYEVENTF_KEYUP, 0); // Release 'W'
    keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0); // Release 'Shift'
}

void AutoWalk()
{
    while (true)
    {
        if (IsAutoRunChecked()) {
            keybd_event(VK_SHIFT, 0, 0, 0); // Press 'Shift'
        }

        keybd_event('W', 0, 0, 0); // Press 'W'

        while (shouldContinueLoop)
        {
            Sleep(10); // Adjust the sleep duration if needed

            if (!shouldContinueLoop) {
                break;
            }

            if (!IsAutoRunChecked()) {
                keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0); // Release 'Shift' if not checked
            }
        }

        ReleaseKeys(); // Release keys before exiting the function

        // Exit the loop if shouldContinueLoop is false
        if (!shouldContinueLoop) {
            break;
        }
    }
}