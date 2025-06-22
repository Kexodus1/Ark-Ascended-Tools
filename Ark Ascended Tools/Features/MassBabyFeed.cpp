#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"

// Type Text specified
void typeText(const std::wstring& text)
{
    for (wchar_t ch : text) {
        SHORT key = VkKeyScan(ch);
        keybd_event(LOBYTE(key), 0, 0, 0);
        keybd_event(LOBYTE(key), 0, KEYEVENTF_KEYUP, 0);
        Sleep(50); // Small delay between keystrokes
    }
}

// Function for Mass Baby Feed Code
void MassBabyFeed(HWND Nanny)
{
    setCoordinates(); // Set the coordinates based on the screen resolution

    while (true)
    {
        // Check for Inv Open
        while (!IsColorWithinTolerance(GetPixelColor(invcolx, invcoly), RGB(188, 244, 255), 30))
            Sleep(500);
        if (!shouldContinueLoop) break;

        // Click at xfer2X, xfer2Y
        PerformMouseClick(xfer2x, xfer2y);
        Sleep(900); // Wait for the click action
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

        Sleep(500); // Wait for the text input
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
            if (!shouldContinueLoop) break;
            Sleep(300);
            // Close Inventory
            PerformMouseClick(closex, closey);
            if (!shouldContinueLoop) break;
        }
        else
        {
            // Close Inventory
            PerformMouseClick(closex, closey);
            if (!shouldContinueLoop) break;
        }
        Sleep(1000);
        if (!shouldContinueLoop) break;
    }
}