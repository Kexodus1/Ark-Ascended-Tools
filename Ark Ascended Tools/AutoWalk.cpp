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
}

void TapRightShift()
{
    // Press and release right 'Shift'
    keybd_event(VK_RSHIFT, 0x36, 0, 0); // Press right 'Shift' (scan code for right shift is 0x36)
    Sleep(50); // Small delay to simulate a key press
    keybd_event(VK_RSHIFT, 0x36, KEYEVENTF_KEYUP, 0); // Release right 'Shift'
}

void AutoWalk()
{
    while (true)
    {
        if (IsAutoRunChecked()) {
            TapRightShift(); // Tap right 'Shift' once if AutoRun is checked
        }

        keybd_event('W', 0, 0, 0); // Press 'W'

        while (shouldContinueLoop)
        {
            Sleep(10); // Adjust the sleep duration if needed

            if (!shouldContinueLoop) {
                break;
            }
        }

        ReleaseKeys(); // Release keys before exiting the function
        if (IsAutoRunChecked()) {
            TapRightShift(); // Tap right 'Shift' once if AutoRun is checked
        }

        // Exit the loop if shouldContinueLoop is false
        if (!shouldContinueLoop) {
            break;
        }
    }
}