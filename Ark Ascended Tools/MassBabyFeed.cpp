#include "pch.h"
#include "Features.h"
#include <windows.h>
#include "Coordinates.h"
#include <string>

void typeText(const std::wstring& text)
{
    for (wchar_t ch : text) {
        SHORT key = VkKeyScan(ch);
        keybd_event(LOBYTE(key), 0, 0, 0);
        keybd_event(LOBYTE(key), 0, KEYEVENTF_KEYUP, 0);
        Sleep(50); // Small delay between keystrokes
    }
}

void MassBabyFeed(HWND Nanny)
{
    setCoordinates(); // Set the coordinates based on the screen resolution

    while (true)
    {
        while (GetPixel(GetDC(NULL), invcolx, invcoly) != RGB(188, 244, 255))
            Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Click at xfer2X, xfer2Y
        PerformMouseClick(xfer2x, xfer2y);
        Sleep(900); // Wait for the click action

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Click at text1X, text1Y
        PerformMouseClick(text1x, text1y);
        Sleep(500); // Wait for the click action

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Retrieve the text from the Nanny drop-down box
        wchar_t selectedValue[256];
        GetWindowText(Nanny, selectedValue, 256);
        // Type the selected value
        typeText(selectedValue);

        Sleep(500); // Wait for the text input

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Click at xfer1X, xfer1Y
        PerformMouseClick(xfer1x, xfer1y);
        Sleep(500); // Wait for the click action

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Check color at promptx, prompty
        COLORREF color = GetPixel(GetDC(NULL), promptx, prompty);
        if (color == RGB(193, 245, 255)) // Assuming red color is RGB(255, 0, 0)
        {
            PerformMouseClick(okayx, okayy);

            Sleep(300);

            PerformMouseClick(closex, closey);
        }
        else
        {
            PerformMouseClick(closex, closey);
        }
        Sleep(1000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }
    }
}