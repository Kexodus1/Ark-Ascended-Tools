#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"
#include "../Headers/Menus.h"

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

// Function for Auto Farmer Code
void AutoFarmer(HWND AutoFarm) 
{
    setCoordinates(); // Set the coordinates based on the screen resolution
    // Load hotkeys from the configuration
    LoadSettings();

    int clickInterval = 2500;
    int colorCheckInterval = 20000;
    int elapsedTime = 0;

    while (true) {
        Sleep(clickInterval);
        if (!shouldContinueLoop) break;

        // Perform mouse click
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        if (!shouldContinueLoop) break;

        elapsedTime += clickInterval;

        if (elapsedTime >= colorCheckInterval) {
            elapsedTime = 0;

            // Check color of Dino Black Weight
            COLORREF color = GetPixelColor(blak2x, blak2y);
            if (color == RGB(0, 0, 0)) 
            {
                // Stop the clicking
                shouldContinueLoop = false;

                // Open Dino Inv
                PerformKeyPress(static_cast<BYTE>(openDinoHotkey), 100, 100);
                Sleep(500); // Wait for the inventory to open
                if (!functionsRunning) break;

                // Click Text Box
                PerformMouseClick(text2x, text2y);
                Sleep(500); // Wait for the click action
                if (!functionsRunning) break;

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

                    if (!functionsRunning) break;
                    Sleep(800); // Wait for the text input

                    // Click drop all
                    PerformMouseClick(drop2x, drop2y);
                    Sleep(500); // Wait for the click action
                    if (!functionsRunning) break;

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
                    if (!functionsRunning) break;
                }

                //Manually Close Inventory
                PerformMouseClick(closex, closey);
                Sleep(500); // Wait for the click action
                if (!functionsRunning) break;

                // Restart the clicking loop
                shouldContinueLoop = true;
            }
        }
    }
}