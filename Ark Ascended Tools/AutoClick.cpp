#include "pch.h"
#include "Features.h"
#include <windows.h>

extern HWND ACKey; // Handle to the dropdown (combobox)
extern HWND ACInt; // Handle to the interval input (edit control)

void AutoClicker()
{
    // 3-second delay before starting
    Sleep(3000); // Wait for 3000 milliseconds (3 seconds)

    while (true) {
        // Get the selected key from the dropdown
        int selectedKeyIndex = SendMessage(ACKey, CB_GETCURSEL, 0, 0); // Get the selected index
        int vkCode; // Virtual key code to simulate

        // Map the selected index to the corresponding virtual key
        switch (selectedKeyIndex) {
        case 0: // 'A'
            vkCode = 'A';
            break;
        case 1: // 'E'
            vkCode = 'E';
            break;
        case 2: // 'O'
            vkCode = 'O';
            break;
        case 3: // Left Mouse Button (LMB)
            vkCode = VK_LBUTTON;
            break;
        default:
            vkCode = 0; // Invalid key
            break;
        }

        // If no valid key is selected, exit the loop
        if (vkCode == 0) {
            break;
        }

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Get the interval (in milliseconds) from the edit control
        wchar_t intervalStr[10];
        GetWindowText(ACInt, intervalStr, 10); // Get the interval as a string
        int interval = _wtoi(intervalStr); // Convert to integer

        // Simulate the key press
        if (vkCode == VK_LBUTTON) {
            // If the left mouse button is selected, simulate a mouse click
            INPUT inputs[2] = {};
            inputs[0].type = INPUT_MOUSE;
            inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN; // Mouse down
            inputs[1].type = INPUT_MOUSE;
            inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;   // Mouse up

            SendInput(2, inputs, sizeof(INPUT));
        }

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        else {
            // Simulate key press
            keybd_event(vkCode, 0, 0, 0); // Key down
            Sleep(50); // Small delay
            keybd_event(vkCode, 0, KEYEVENTF_KEYUP, 0); // Key up
        }

        Sleep(interval);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }
    }
}