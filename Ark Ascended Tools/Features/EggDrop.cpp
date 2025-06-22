#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"
#include "../Headers/Menus.h"

// Function for Egg Dropper Code
void EggDrop(HWND SpacingD)
{
    setCoordinates(); // Set the coordinates based on the screen resolution
    // Load hotkeys from the configuration
    LoadSettings();
    // 3 Second Delay before starting
    Sleep(3000);

    while (true) {
        if (!shouldContinueLoop) break;
        // Get the value from SpacingD and calculate the delay
        wchar_t spacingText[10];
        GetWindowText(SpacingD, spacingText, 10);
        int spacingValue = _wtoi(spacingText); // Convert to integer

        if (spacingValue <= 0) {
            spacingValue = 1; // Fallback to a default value if input is invalid
        }

        // Calculate the delay in milliseconds (spacingValue * 10ms)
        int delay = spacingValue * 10;

        // Open Inventory
        PerformKeyPress(static_cast<BYTE>(openPlayerHotkey), 100, 100);
        Sleep(500);
        if (!shouldContinueLoop) break;

        // Click Text Box
        PerformMouseClick(text1x, text1y);
        Sleep(100);
        if (!shouldContinueLoop) break;

        // Type for fert eggs
        typeText(L"fert");
        Sleep(500); // Wait for the text input
        if (!shouldContinueLoop) break;

        // Click 1st Slot 
        PerformMouseClick(slot1x, slot1y);
        Sleep(100);
        if (!shouldContinueLoop) break;

        // Drop Egg (O)
        PerformKeyPress('O', 100, 100);
        Sleep(100);
        if (!shouldContinueLoop) break;

        // Close Inventory
        PerformMouseClick(closex, closey);
        Sleep(750);
        if (!shouldContinueLoop) break;

        // Press the 'S' key for the calculated delay
        PerformKeyPress('S', delay, 100);
        Sleep(100);
        if (!shouldContinueLoop) break;
    }
}