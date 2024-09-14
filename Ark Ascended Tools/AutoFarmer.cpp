#include "pch.h"
#include "Features.h"
#include "Coordinates.h"
#include <windows.h> // Required for Sleep, SetCursorPos, mouse_event, GetPixel, and keybd_event
#include <sstream>   // Required for stringstream

// Function to split a string by a delimiter
std::vector<std::wstring> split(const std::wstring& s, wchar_t delimiter) {
    std::vector<std::wstring> tokens;
    std::wstring token;
    std::wstringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void AutoFarmer(HWND AutoFarm) 
{
    setCoordinates(); // Set the coordinates based on the screen resolution

    int clickInterval = 2500;
    int colorCheckInterval = 20000;
    int elapsedTime = 0;

    while (true) {
        Sleep(clickInterval);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Perform mouse click
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        elapsedTime += clickInterval;

        if (elapsedTime >= colorCheckInterval) {
            elapsedTime = 0;

            // Check color of Black Weight
            COLORREF color = GetPixelColor(blackx, blacky);
            if (color == RGB(0, 0, 0)) 
            {
                // Stop the clicking
                shouldContinueLoop = false;

                // Open Dino Inv
                keybd_event('F', 0, 0, 0);
                keybd_event('F', 0, KEYEVENTF_KEYUP, 0);

                Sleep(500); // Wait for the inventory to open

                if (!functionsRunning) {
                    break; // Exit the loop immediately
                }

                // Click Text Box
                PerformMouseClick(text2x, text2y);
                Sleep(500); // Wait for the click action

                if (!functionsRunning) {
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

                    if (!functionsRunning) {
                        break; // Exit the loop immediately
                    }

                    Sleep(800); // Wait for the text input

                    // Click drop all
                    PerformMouseClick(drop2x, drop2y);
                    Sleep(500); // Wait for the click action

                    if (!functionsRunning) {
                        break; // Exit the loop immediately
                    }

                    // Check color at promptx, prompty
                    COLORREF color = GetPixelColor(promptx, prompty);
                    if (IsColorWithinTolerance(color, RGB(193, 245, 255), 30)) // Popup Prompt color
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

                    if (!functionsRunning) {
                        break; // Exit the loop immediately
                    }
                }

                //Manually Close Inventory
                PerformMouseClick(closex, closey);
                Sleep(500); // Wait for the click action

                if (!functionsRunning) {
                    break; // Exit the loop immediately
                }

                // Restart the clicking loop
                shouldContinueLoop = true;
            }
        }
    }
}