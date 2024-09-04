#include "pch.h"
#include "Features.h"
#include "Coordinates.h"
#include <windows.h> // Required for Sleep, SetCursorPos, mouse_event, GetPixel, and keybd_event
#include <sstream>   // Required for stringstream

// Function to split a string by a delimiter

void AutoDropper(HWND AutoFarm)
{
    setCoordinates(); // Set the coordinates based on the screen resolution
    while (true)
    {
        while (GetPixel(GetDC(NULL), invcolx, invcoly) != RGB(188, 244, 255))
            Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Click Text Box
        PerformMouseClick(text2x, text2y);
        Sleep(500); // Wait for the click action

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Get text from the AutoFarm box
        wchar_t buffer[256];
        GetWindowText(AutoFarm, buffer, 256);

        // Split the text by commas
        std::vector<std::wstring> items = split(buffer, L',');

        // Type each item followed by a click at (300, 400)
        for (const auto& item : items)
        {
            // Type the item
            for (int i = 0; item[i] != '\0'; ++i)
            {
                SHORT key = VkKeyScan(item[i]);
                keybd_event(LOBYTE(key), 0, 0, 0);
                keybd_event(LOBYTE(key), 0, KEYEVENTF_KEYUP, 0);
            }

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            Sleep(800); // Wait for the text input

            // Click drop all
            PerformMouseClick(drop2x, drop2y);
            Sleep(500); // Wait for the click action

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Check color at promptx, prompty #C1F5FF
            COLORREF color = GetPixel(GetDC(NULL), promptx, prompty);
            if (color == RGB(193, 245, 255)) // Assuming red color is RGB(255, 0, 0)
            {
                PerformMouseClick(okayx, okayy);
                Sleep(200);
            }
            else
            {
                Sleep(200);
            }

            // Click text box
            PerformMouseClick(text2x, text2y);
            Sleep(500); // Wait for the click action

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }

        //Manually Close Inventory
        PerformMouseClick(closex, closey);
        Sleep(500); // Wait for the click action

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }
    }
}