#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"
#include "../Headers/Menus.h"

// Function for Anti AFK Code
void AntiAFK(bool isAFKMChecked, bool isAFKFDChecked)
{
    // Load hotkeys from the configuration
    LoadSettings();
    while (true)
    {
        if (!shouldContinueLoop) break;
        if (isAFKMChecked)
        {
            // Wait for 5 seconds before Starting the sequence
            Sleep(5000); // Wait 5 seconds
            if (!shouldContinueLoop) break;

            // Prone with key press
            PerformKeyPress(static_cast<BYTE>(useitHotkey), 50, 500);
            if (!shouldContinueLoop) break;

            // Wait for 55 seconds before repeating the sequence
            Sleep(55000); // Wait 55 seconds
            if (!shouldContinueLoop) break;

            // Prone key press
            PerformKeyPress(static_cast<BYTE>(useitHotkey), 50, 500);
            if (!shouldContinueLoop) break;
        }
        if (!shouldContinueLoop) break;
        // If Auto Eat \ Drink is checked
        if (isAFKFDChecked)
        {
            // Get the value entered into AFKFDM
            wchar_t afkfdmText[50];
            GetWindowText(AFKFDM, afkfdmText, 50);
            int AFKFDMValue = _wtoi(afkfdmText); // Convert to integer
            if (!shouldContinueLoop) break;

            // Ensure AFKFDMValue is within a reasonable range to prevent overflow
            if (AFKFDMValue < 0) {
                AFKFDMValue = 0;
            }

            // Perform action every AFKFDMValue minutes
            static time_t lastActionTime = 0;
            time_t currentTime = time(nullptr);
            if (!shouldContinueLoop) break;

            // Use a larger type for multiplication to avoid overflow
            long long minutesToEatDrink = static_cast<long long>(AFKFDMValue) * 60;

            // Time in minutes to eat \ drink
            if (currentTime - lastActionTime >= minutesToEatDrink)
            {
                if (!shouldContinueLoop) break;

                // Eat with settings key press
                PerformKeyPress(static_cast<BYTE>(eatingHotkey), 50, 500);
                if (!shouldContinueLoop) break;

                // Drink with settings key press
                PerformKeyPress(static_cast<BYTE>(drinkingHotkey), 50, 500);
                if (!shouldContinueLoop) break;

                // Update last action time
                lastActionTime = currentTime;
                if (!shouldContinueLoop) break;
            }
        }
    }
}