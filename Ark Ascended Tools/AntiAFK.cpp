#include "pch.h"
#include "Features.h"
#include <windows.h> // Required for Sleep, SetCursorPos, and mouse_event

// Function to contain the code for case 3
void AntiAFK(bool isAFKMChecked, bool isAFKFDChecked)
{
    while (true)
    {
        if (isAFKMChecked)
        {
            // Wait for 5 seconds before Starting the sequence
            Sleep(5000); // Wait 5 seconds

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Simulate 'd' key press for 500ms
            keybd_event('D', 0, 0, 0); // Press 'D'
            Sleep(500); // Wait 500 milliseconds
            keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release 'D'
            Sleep(500); // Wait 500 milliseconds

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Simulate 'a' key press for 500ms
            keybd_event('A', 0, 0, 0); // Press 'A'
            Sleep(500); // Wait 500 milliseconds
            keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release 'A'
            Sleep(500); // Wait 500 milliseconds

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Simulate 'x' key press
            keybd_event('X', 0, 0, 0); // Press 'X'
            Sleep(50); // Wait 50 milliseconds
            keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release 'X'
            Sleep(500); // Wait 500 milliseconds

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Wait for 50 seconds before repeating the sequence
            Sleep(55000); // Wait 55 seconds

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Simulate 'x' key press
            keybd_event('X', 0, 0, 0); // Press 'X'
            Sleep(50); // Wait 50 milliseconds
            keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release 'X'
            Sleep(500); // Wait 500 milliseconds

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        if (isAFKFDChecked)
        {
            // Get the value entered into AFKFDM (assuming it's an edit control)
            wchar_t afkfdmText[50];
            GetWindowText(AFKFDM, afkfdmText, 50);
            int AFKFDMValue = _wtoi(afkfdmText); // Convert to integer

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Perform action every AFKFDMValue minutes
            static time_t lastActionTime = 0;
            time_t currentTime = time(nullptr);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            if (currentTime - lastActionTime >= AFKFDMValue * 60)
            {
                if (!shouldContinueLoop) {
                    break; // Exit the loop immediately
                }

                // Simulate '9' key press
                keybd_event('9', 0, 0, 0); // Press 'X'
                Sleep(50); // Wait 50 milliseconds
                keybd_event('9', 0, KEYEVENTF_KEYUP, 0); // Release 'X'
                Sleep(500); // Wait 500 milliseconds

                if (!shouldContinueLoop) {
                    break; // Exit the loop immediately
                }

                // Simulate '0' key press
                keybd_event('0', 0, 0, 0); // Press 'X'
                Sleep(50); // Wait 50 milliseconds
                keybd_event('0', 0, KEYEVENTF_KEYUP, 0); // Release 'X'
                Sleep(500); // Wait 500 milliseconds

                if (!shouldContinueLoop) {
                    break; // Exit the loop immediately
                }

                // Update last action time
                lastActionTime = currentTime;
            }
        }
        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }
    }
}