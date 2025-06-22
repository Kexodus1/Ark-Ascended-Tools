#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"
#include "../Headers/Menus.h"

// Function to check if Jump Jump Blobs in RGB range
bool isBLOBColorRange(BYTE red, BYTE green, BYTE blue, BYTE rMin, BYTE rMax, BYTE gMin, BYTE gMax, BYTE bMin, BYTE bMax) {
    return (red >= rMin && red <= rMax) && (green >= gMin && green <= gMax) && (blue >= bMin && blue <= bMax);
}

// Function to move the mouse cursor left and right until the color matches
void MoveMouseUntilColorMatches(int x, int y, COLORREF targetColor, int tolerance) {
    POINT cursorPos;
    bool moveLeft = true;

    while (!IsColorWithinTolerance(GetPixelColor(x, y), targetColor, tolerance)) {
        // Get current cursor position
        GetCursorPos(&cursorPos);

        // Move the cursor left and right by 4 pixels
        if (moveLeft) {
            SetCursorPos(cursorPos.x - 4, cursorPos.y);
        }
        else {
            SetCursorPos(cursorPos.x + 4, cursorPos.y);
        }

        // Toggle direction
        moveLeft = !moveLeft;

        // Wait for a short period before checking the color again
        Sleep(100); // Adjust the delay as needed

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }
    }
}

// Function to simulate a key press and hold down
void PerformKeyDown(BYTE virtualKey) {
    // Set up the INPUT structure
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = virtualKey; // Virtual-key code
    input.ki.dwFlags = 0; // 0 means key down

    // Send the key down event
    SendInput(1, &input, sizeof(INPUT));
}

// Function to release a key
void PerformKeyUp(BYTE virtualKey) {
    // Set up the INPUT structure
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = virtualKey; // Virtual-key code
    input.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release

    // Send the key up event
    SendInput(1, &input, sizeof(INPUT));
}

// Function for AFK Club ARK Code
void ClubARK()
{
    setCoordinates(); // Set the coordinates based on the screen resolution
    LoadSettings();
    Sleep(3000); // 3 Second Delay before Start

    bool firstLoop = true; // Flag to track the first loop
    while (true)
    {
        // Get the selected item from the Club ARK game drop-down box
        LRESULT selIndex = SendMessage(ClubARKGame, CB_GETCURSEL, 0, 0);
        if (selIndex != CB_ERR) // Ensure the selection is valid
        {
            WCHAR selItem[256] = { 0 };
            SendMessage(ClubARKGame, CB_GETLBTEXT, (WPARAM)selIndex, (LPARAM)selItem);
            selItem[255] = 0; // Ensure null-termination

            // Duck Duck Jump Code
            if (wcscmp(selItem, L"Duck Duck Jump") == 0)
            {
                // When Started Change Gamma
                if (firstLoop)
                {
                    if (!shouldContinueLoop) break;
                    // Open Console
                    PerformKeyPress(VK_OEM_3, 10, 0);
                    Sleep(25);
                    if (!shouldContinueLoop) break;

                    // Type for Gamma
                    std::wostringstream gammaText;
                    gammaText << L"gamma " << std::to_wstring(gamma1) << L"." << std::to_wstring(gamma2);
                    typeText(gammaText.str());
                    Sleep(300); // Wait for the text input
                    if (!shouldContinueLoop) break;

                    // Enter Gamma
                    PerformKeyPress(VK_RETURN, 10, 0);
                    Sleep(25);
                    if (!shouldContinueLoop) break;
                    firstLoop = false; // Set the flag to false after first execution
                }

                // Color of Alpha Pink (Starts Crouch or Jump)
                COLORREF DDJC1 = GetPixelColor(DDJC1X, DDJC1Y);
                if (IsColorWithinTolerance(DDJC1, RGB(255, 169, 152), 35)) // color is FFA998
                {
                    // Capture the current value of DDJC2X as a base
                    int DDJC2AX = DDJC2X;
                    int DDJC2AY = DDJC2Y;
                    int cafovValue = fov;

                    // Adjust DDJC2X based on the difference from 50
                    int adjustX = (50 - cafovValue) * 4;
                    int adjustY = (cafovValue - 50) * 0.25;
                    DDJC2AX = DDJC2X + adjustX; // Apply adjustment relative to current DDJC2X
                    DDJC2AY = DDJC2Y + adjustY; // Apply adjustment relative to current DDJC2X

                    // Now check the color at the updated DDJC2X, DDJC2Y
                    COLORREF color = GetPixelColor(DDJC2AX, DDJC2Y);
                    BYTE red = GetRValue(color);
                    BYTE green = GetGValue(color);
                    BYTE blue = GetBValue(color);

                    // Log the RGB values to a file for debugging
                    //FILE* logFile;
                    //errno_t err = fopen_s(&logFile, "rgb.txt", "a");
                    //if (err == 0 && logFile != NULL) {
                    //    // Log coordinates separately from RGB values to avoid format specifier issues
                    //    fprintf(logFile, "Color at coordinates (%d, %d):\n", DDJC2AX, DDJC2Y);
                    //    fprintf(logFile, "R=%d, G=%d, B=%d\n", (int)red, (int)green, (int)blue);
                    //    fclose(logFile);
                    //}

                    // Check if the BLOB color is within the specified range
                    //if (isBLOBColorRange(red, green, blue, rMin, rMax, gMin, gMax, bMin, bMax))
                    COLORREF BLOBS = GetPixelColor(DDJC2AX, DDJC2AY);
                    if (IsColorWithinTolerance(BLOBS, RGB(170, 170, 170), 85))
                    {
                        // Simulate spacebar key press
                        PerformKeyPress(VK_SPACE, 40, 0);
                    }
                    else
                    {
                        // Simulate Crouching key press
                        PerformKeyPress('S', 10, 0);
                    }
                }
                // Menu navigation for Duck Duck Jump
                else
                {
                    // Color of Green Health Bar
                    COLORREF CAINV = GetPixelColor(CAINVX, CAINVY);
                    if (IsColorWithinTolerance(CAINV, RGB(0, 140, 118), 20)) // color is 008C76
                    {
                        // Inventory Mission Button
                        PerformMouseClick(InvMiX, InvMiY);
                        Sleep(600); // Wait 600 milliseconds
                        if (!shouldContinueLoop) break;
                    }
                    else {
                        Sleep(5000); // Wait 5 Seconds
                        if (!shouldContinueLoop) break;

                        // Open Inventory
                        PerformKeyPress(static_cast<BYTE>(openPlayerHotkey), 100, 1000);  // Simulate other keys
                        Sleep(500);
                        if (!shouldContinueLoop) break;
                    }

                    // Code to Auto Make Tribe
                    // Color of Red Need Tribe (M)
                    COLORREF CATM1 = GetPixelColor(CATM1X, CATM1Y);
                    if (IsColorWithinTolerance(CATM1, RGB(255, 8, 0), 20)) // color is FF0800
                    {
                        // Tribe Manager Button 
                        PerformMouseClick(CATM2X, CATM2Y);
                        Sleep(600); // Wait 600 milliseconds
                        if (!shouldContinueLoop) break;

                        // Create Tribe Button 
                        PerformMouseClick(CATM3X, CATM3Y);
                        Sleep(600); // Wait 600 milliseconds
                        if (!shouldContinueLoop) break;

                        // Inventory Mission Button
                        PerformMouseClick(InvMiX, InvMiY);
                        Sleep(600); // Wait 600 milliseconds
                        if (!shouldContinueLoop) break;
                    }
                    else {
                        Sleep(10); // Wait 100 milliseconds
                        if (!shouldContinueLoop) break;
                    }

                    // Color of White Menu Bar
                    COLORREF CAJC1 = GetPixelColor(CAJC1X, CAJC1Y);
                    if (CAJC1 == RGB(255, 255, 255)) // color is FFFFFF
                    {
                        // MiniGames Click 
                        PerformMouseClick(CAJ1X, CAJ1Y);
                        Sleep(600); // Wait 600 milliseconds
                        if (!shouldContinueLoop) break;

                        // Duck Duck Jump Alpha Click 
                        PerformMouseClick(CAJ2X, CAJ2Y);
                        Sleep(600); // Wait 600 milliseconds
                        if (!shouldContinueLoop) break;

                        // Join Game Click 
                        PerformMouseClick(CAJ3X, CAJ3Y);
                        Sleep(600); // Wait 600 milliseconds
                        if (!shouldContinueLoop) break;

                        Sleep(10000); // Wait 10 Seconds
                        if (!shouldContinueLoop) break;
                    }
                    else
                    {
                        Sleep(10); // Wait 500 milliseconds
                        if (!shouldContinueLoop) break;
                    }
                }
            }
            // Doed Dodge Code
            else if (wcscmp(selItem, L"Doed Dodge") == 0)
            {
                // When Started Enable RSHIFT
                if (firstLoop)
                {
                    if (!shouldContinueLoop) break;
                    keybd_event(VK_LSHIFT, 0x2A, 0, 0);
                    Sleep(25);
                    keybd_event(VK_LSHIFT, 0x2A, KEYEVENTF_KEYUP, 0);
                    Sleep(25);
                    if (!shouldContinueLoop) break;

                    keybd_event(VK_RSHIFT, 0x36, 0, 0);
                    Sleep(25);
                    keybd_event(VK_RSHIFT, 0x36, KEYEVENTF_KEYUP, 0);
                    Sleep(25);
                    if (!shouldContinueLoop) break;
                    firstLoop = false; // Set the flag to false after first execution
                }
                // Color of Alpha Pink (Starts Doed)
                COLORREF DDJC1 = GetPixelColor(DDAC1X, DDAC1Y);
                if (IsColorWithinTolerance(DDJC1, RGB(255, 169, 152), 35)) // color is FFA998
                {
                    DWORD64 startTime = GetTickCount64(); // Get current time for periodic actions
                    while (IsColorWithinTolerance(GetPixelColor(DDAC1X, DDAC1Y), RGB(255, 169, 152), 35)) {
                        // Hold 'W' key
                        PerformKeyDown('W'); // Press and hold 'W'
                        if (!shouldContinueLoop) break;

                        // Jump every 3 seconds
                        if (GetTickCount64() - startTime >= 1500) {
                            PerformKeyPress(VK_SPACE, 10, 0);
                            startTime = GetTickCount64(); // Reset the timer
                        }
                        if (!shouldContinueLoop) break;

                        // Retrieve the value from the CATurn edit box
                        TCHAR buffer[10];
                        GetWindowText(CATurn, buffer, 10); // Get text from the edit box
                        // Convert the retrieved text to an integer
                        int TurnTime = std::stoi(buffer) * 1;
                        // Turn away From Wall
                        PerformKeyPress(VK_RIGHT, doedturn, 10);
                        if (!shouldContinueLoop) break;

                        Sleep(115); // Small delay to control loop frequency and avoid excessive resource usage
                    }
                    
                    // Release 'W' key when the color is gone
                    PerformKeyUp('W');
                    if (!shouldContinueLoop) break;
                }
                // Menu navigation for Duck Duck Jump
                else
                {
                    Sleep(5000); // Wait 5 Seconds
                    if (!shouldContinueLoop) break;

                    // Open Inventory
                    PerformKeyPress(static_cast<BYTE>(openPlayerHotkey), 100, 1000);  // Simulate other keys
                    Sleep(500);
                    if (!shouldContinueLoop) break;

                    // Inventory Mission Button
                    PerformMouseClick(InvMiX, InvMiY);
                    Sleep(600); // Wait 600 milliseconds
                    if (!shouldContinueLoop) break;

                    // Code to Auto Make Tribe
                    // Color of Red Need Tribe (M)
                    COLORREF CATM1 = GetPixelColor(CATM1X, CATM1Y);
                    if (IsColorWithinTolerance(CATM1, RGB(255, 8, 0), 20)) // color is FF0800
                    {
                        // Tribe Manager Button 
                        PerformMouseClick(CATM2X, CATM2Y);
                        Sleep(600); // Wait 600 milliseconds
                        if (!shouldContinueLoop) break;

                        // Create Tribe Button 
                        PerformMouseClick(CATM3X, CATM3Y);
                        Sleep(600); // Wait 600 milliseconds
                        if (!shouldContinueLoop) break;

                        // Inventory Mission Button
                        PerformMouseClick(InvMiX, InvMiY);
                        Sleep(600); // Wait 600 milliseconds
                        if (!shouldContinueLoop) break;
                    }
                    else {
                        Sleep(10); // Wait 100 milliseconds
                        if (!shouldContinueLoop) break;
                    }

                    // Color of White Menu Bar
                    COLORREF CAJC1 = GetPixelColor(CAJC1X, CAJC1Y);
                    if (CAJC1 == RGB(255, 255, 255)) // color is FFFFFF
                    {
                        // MiniGames Click 
                        PerformMouseClick(CAJ1X, CAJ1Y);
                        Sleep(600); // Wait 600 milliseconds
                        if (!shouldContinueLoop) break;

                        // Doed Dodge Alpha Click 
                        PerformMouseClick(CDJ1X, CDJ1Y);
                        Sleep(600); // Wait 600 milliseconds
                        if (!shouldContinueLoop) break;

                        // Set Mouse over Join
                        SetCursorPos(CAJ3X, CAJ3Y);
                        Sleep(500); // Wait 500 milliseconds
                        if (!shouldContinueLoop) break;

                        // Wait for pixel color to match Yellow Join
                        MoveMouseUntilColorMatches(CAJC2X, CAJC2Y, RGB(255, 240, 0), 15);
                        Sleep(500); // Wait 500 milliseconds
                        if (!shouldContinueLoop) break;

                        // Join Game Click 
                        PerformMouseClick(CAJ3X, CAJ3Y);
                        Sleep(600); // Wait 600 milliseconds
                        if (!shouldContinueLoop) break;

                        Sleep(10000); // Wait 10 Seconds
                        if (!shouldContinueLoop) break;
                    }
                    else
                    {
                        Sleep(10); // Wait 500 milliseconds
                        if (!shouldContinueLoop) break;
                    }
                }
            }
        }
        if (!shouldContinueLoop) break;
    }
}