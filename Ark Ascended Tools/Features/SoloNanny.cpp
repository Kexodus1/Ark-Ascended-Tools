#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"

// Function for Solo Nanny Checkbox
void SoloNanny(HWND Nanny)
{
    setCoordinates(); // Set the coordinates based on the screen resolution

    while (true)
    {
        // Wait for Inv Color
        while (!IsColorWithinTolerance(GetPixelColor(invcolx, invcoly), RGB(188, 244, 255), 30))
            Sleep(500);
        if (!shouldContinueLoop) break;

        Sleep(1000); // Wait for the click action

        // Click at xfer2X, xfer2Y
        PerformMouseClick(xfer2x, xfer2y);
        Sleep(500); // Wait for the click action
        if (!shouldContinueLoop) break;

        // Click at text1X, text1Y
        PerformMouseClick(text1x, text1y);
        Sleep(500); // Wait for the click action
        if (!shouldContinueLoop) break;

        // Retrieve the text from the Nanny drop-down box
        wchar_t selectedValue[256];
        GetWindowText(Nanny, selectedValue, 256);
        // Type the selected value
        typeText(selectedValue);

        Sleep(1000); // Wait for the text input
        if (!shouldContinueLoop) break;

        // Click at xfer1X, xfer1Y
        PerformMouseClick(xfer1x, xfer1y);
        Sleep(500); // Wait for the click action
        if (!shouldContinueLoop) break;

        // Check Menu Transitions
        COLORREF MenuTran = GetPixelColor(promptx, prompty);
        if (IsColorWithinTolerance(MenuTran, RGB(193, 245, 255), 30)) // Popup Prompt color
        {
            // Click Okay on popup
            PerformMouseClick(okayx, okayy);
            Sleep(300);
            if (!shouldContinueLoop) break;
        }
        else
        {
            Sleep(300);
            if (!shouldContinueLoop) break;
        }
        if (!shouldContinueLoop) break;

        // Add a 15-second delay
        Sleep(15000);
        if (!shouldContinueLoop) break;

        // Add a 15-second delay
        Sleep(15000);
        if (!shouldContinueLoop) break;

        // Add a 15-second delay
        Sleep(15000);
        if (!shouldContinueLoop) break;

        // Add a 15-second delay
        Sleep(15000);
        if (!shouldContinueLoop) break;

        // Add a 15-second delay
        Sleep(15000);
        if (!shouldContinueLoop) break;

        // Add a 15-second delay
        Sleep(15000);
        if (!shouldContinueLoop) break;

        // Add a 15-second delay
        Sleep(15000);
        if (!shouldContinueLoop) break;

        // Add a 15-second delay
        Sleep(15000);
        if (!shouldContinueLoop) break;
    }
}