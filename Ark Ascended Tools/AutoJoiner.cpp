#include "pch.h"
#include "Features.h"
#include "Coordinates.h"
#include <windows.h>
#include <string>

void SendTextInput(HWND ServerN) {
    wchar_t text[256];
    GetWindowText(ServerN, text, 256);

    for (int i = 0; text[i] != '\0'; ++i) {
        SHORT key = VkKeyScan(text[i]);
        if (key == -1) {
            // Handle characters that cannot be converted
            continue;
        }
        BYTE virtualKey = LOBYTE(key);
        BYTE shiftState = HIBYTE(key);

        // Press Shift if needed
        if (shiftState & 1) {
            keybd_event(VK_SHIFT, 0, 0, 0);
        }

        keybd_event(virtualKey, 0, 0, 0);
        keybd_event(virtualKey, 0, KEYEVENTF_KEYUP, 0);

        // Release Shift if needed
        if (shiftState & 1) {
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
        }
    }
}

void AutoJoiner(HWND ServerN)
{
    setCoordinates(); // Set the coordinates based on the screen resolution
    while (true)
    {
        while (GetPixel(GetDC(NULL), color1x, color1y) != RGB(218, 218, 149))
            Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        //Click Server Text Box
        PerformMouseClick(servnx, servny);
        Sleep(200);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        SendTextInput(ServerN);
        Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        PerformMouseClick(click1X, click1Y);
        Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        PerformMouseClick(click2X, click2Y);
        Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Wait for pixel color to match
        while (GetPixel(GetDC(NULL), color2x, color2y) != RGB(135, 79, 23))
            Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        PerformMouseClick(click3X, click3Y);

        // Wait for pixel color to match
        while (GetPixel(GetDC(NULL), color3x, color3y) != RGB(193, 245, 255))
            Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        PerformMouseClick(click4X, click4Y);
        Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        PerformMouseClick(click5X, click5Y);
        Sleep(200);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        PerformMouseClick(click6X, click6Y);
        Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        PerformMouseClick(click7X, click7Y);
        Sleep(1000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }
    }
}
