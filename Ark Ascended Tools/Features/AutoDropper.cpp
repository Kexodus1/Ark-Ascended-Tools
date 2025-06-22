#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"

// Function for Auto Dropper Code
void AutoDropper(HWND AutoDrop)
{
    setCoordinates(); // Set the coordinates based on the screen resolution
    while (true)
    {
        while (!IsColorWithinTolerance(GetPixelColor(invcolx, invcoly), RGB(188, 244, 255), 30))
            Sleep(500);
        if (!shouldContinueLoop) break;

        // Click Text Box
        PerformMouseClick(text2x, text2y);
        Sleep(500); // Wait for the click action
        if (!shouldContinueLoop) break;

        // Get text from the AutoFarm box
        wchar_t buffer[256];
        GetWindowText(AutoDrop, buffer, 256);

        // Split the text by commas
        std::vector<std::wstring> items = split(buffer, L',');

        // Type each item followed by drop all
        for (const auto& item : items)
        {
            // Type the item
            for (int i = 0; item[i] != '\0'; ++i)
            {
                SHORT key = VkKeyScan(item[i]);
                keybd_event(LOBYTE(key), 0, 0, 0);
                keybd_event(LOBYTE(key), 0, KEYEVENTF_KEYUP, 0);
            }
            if (!shouldContinueLoop) break;
            Sleep(800); // Wait for the text input

            // Click drop all
            PerformMouseClick(drop2x, drop2y);
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
            }
            else
            {
                Sleep(200);
                if (!shouldContinueLoop) break;
            }

            // Click text box
            PerformMouseClick(text2x, text2y);
            Sleep(500); // Wait for the click action
            if (!shouldContinueLoop) break;
        }

        //Manually Close Inventory
        PerformMouseClick(closex, closey);
        Sleep(500); // Wait for the click action
        if (!shouldContinueLoop) break;
    }
}