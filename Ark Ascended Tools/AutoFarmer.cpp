#include "pch.h"
#include "Features.h"
#include <windows.h> // Required for Sleep, SetCursorPos, mouse_event, GetPixel, and keybd_event
#include <string>    // Required for string handling
#include <vector>    // Required for vector
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
    HDC hdc = GetDC(NULL);
    int clickInterval = 5000;
    int colorCheckInterval = 20000;
    int elapsedTime = 0;

    // Get the current screen resolution
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int color1x, color1y, click1X, click1Y, click2X, click2Y, click3X, click3Y;

    // Check the current screen resolution and set the coordinates accordingly
    if (screenWidth == 3440 && screenHeight == 1440)
    {
        color1x = 3199;
        color1y = 85;
        click1X = 2131;
        click1Y = 265;
        click2X = 2343;
        click2Y = 261;
        click3X = 2837;
        click3Y = 89;

    }
    else if (screenWidth == 2560 && screenHeight == 1440)
    {
        color1x = 2316;
        color1y = 89;
        click1X = 1698;
        click1Y = 266;
        click2X = 1907;
        click2Y = 265;
        click3X = 2400;
        click3Y = 84;
    }
    else if (screenWidth == 1920 && screenHeight == 1080)
    {
        color1x = 1738;
        color1y = 66;
        click1X = 1272;
        click1Y = 197;
        click2X = 1426;
        click2Y = 197;
        click3X = 1795;
        click3Y = 63;
    }
    else if (screenWidth == 1920 && screenHeight == 1200)
    {
        color1x = 1718;
        color1y = 75;
        click1X = 1267;
        click1Y = 261;
        click2X = 1422;
        click2Y = 258;
        click3X = 1796;
        click3Y = 131;
    }
    else if (screenWidth == 1536 && screenHeight == 864)
    {
        color1x = 1390;
        color1y = 55;
        click1X = 1028;
        click1Y = 162;
        click2X = 1142;
        click2Y = 159;
        click3X = 1439;
        click3Y = 50;
    }

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

            // Check color
            COLORREF color = GetPixel(hdc, color1x, color1y);
            if (color == RGB(0, 0, 0)) 
            {
                // Stop the clicking
                shouldContinueLoop = false;

                // Press 'i'
                keybd_event('F', 0, 0, 0);
                keybd_event('F', 0, KEYEVENTF_KEYUP, 0);

                Sleep(500); // Wait for the inventory to open

                if (!functionsRunning) {
                    break; // Exit the loop immediately
                }

                // Click
                SetCursorPos(click1X, click1Y);
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

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

                    Sleep(500); // Wait for the text input

                    // Click
                    SetCursorPos(click2X, click2Y);
                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

                    Sleep(500); // Wait for the click action

                    if (!functionsRunning) {
                        break; // Exit the loop immediately
                    }

                    // Click
                    SetCursorPos(click1X, click1Y);
                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

                    Sleep(500); // Wait for the click action

                    if (!functionsRunning) {
                        break; // Exit the loop immediately
                    }
                }

                //Manually Close Inventory
                SetCursorPos(click3X, click3Y);
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

                Sleep(500); // Wait for the inventory to close

                if (!functionsRunning) {
                    break; // Exit the loop immediately
                }

                // Restart the clicking loop
                shouldContinueLoop = true;
            }
        }
    }

    ReleaseDC(NULL, hdc);
}