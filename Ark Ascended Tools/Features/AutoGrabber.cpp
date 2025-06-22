#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"

// Function for Auto Grabber Code
void AutoGrabber()
{
    setCoordinates(); // Set the coordinates based on the screen resolution

    while (true)
    {
        // Get the selected item from the AutoGrab drop-down box
        LRESULT selIndex = SendMessage(AutoGrab, CB_GETCURSEL, 0, 0);
        if (selIndex != CB_ERR) // Ensure the selection is valid
        {
            WCHAR selItem[256] = { 0 };
            SendMessage(AutoGrab, CB_GETLBTEXT, (WPARAM)selIndex, (LPARAM)selItem);
            selItem[255] = 0; // Ensure null-termination

            // Air Drop code
            if (wcscmp(selItem, L"Air Drop") == 0)
            {
                // Check for when Inv Open
                while (!IsColorWithinTolerance(GetPixelColor(dropcolorx, dropcolory), RGB(188, 244, 255), 30))
                    Sleep(500);
                if (!shouldContinueLoop) break;

                // Transfer All Click
                PerformMouseClick(xferdropx, xferdropy);
                Sleep(300);
                if (!shouldContinueLoop) break;

                // Transfer All Click
                PerformMouseClick(xferdropx, xferdropy);
                Sleep(300);
                if (!shouldContinueLoop) break;

                // Close Drop Inv
                PerformMouseClick(closex, closey);
                Sleep(10000); // Delay before Restarting
                if (!shouldContinueLoop) break;
            }
            // Raptor Claus Code
            else if (wcscmp(selItem, L"Raptor Claus") == 0)
            {
                // Check for when Inv Open
                while (!IsColorWithinTolerance(GetPixelColor(dropcolorx, dropcolory), RGB(188, 244, 255), 30))
                    Sleep(500);
                if (!shouldContinueLoop) break;

                // Transfer All Click
                PerformMouseClick(xferdropx, xferdropy);
                Sleep(500);
                if (!shouldContinueLoop) break;

                // Transfer All Click
                PerformMouseClick(xferdropx, xferdropy);
                Sleep(500);
                if (!shouldContinueLoop) break;

                // Close Drop Inv
                PerformMouseClick(closex, closey);
                Sleep(30000); // Delay before Restarting
                if (!shouldContinueLoop) break;
            }
            // Grab Death Bag Code
            else if (wcscmp(selItem, L"Death Bag") == 0)
            {
                // Check for when Inv Open
                while (!IsColorWithinTolerance(GetPixelColor(invcolx, invcoly), RGB(188, 244, 255), 30))
                    Sleep(500);
                if (!shouldContinueLoop) break;

                // Transfer All Click
                PerformMouseClick(xfer2x, xfer2y);
                Sleep(550);
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
                Sleep(5000); // Delay before Restarting
                if (!shouldContinueLoop) break;
            }
            // Code to Empty Snails
            else if (wcscmp(selItem, L"Empty Snails") == 0)
            {
                // Check for Inv Open
                while (!IsColorWithinTolerance(GetPixelColor(invcolx, invcoly), RGB(188, 244, 255), 30))
                    Sleep(500);
                if (!shouldContinueLoop) break;

                // Click Text Box
                PerformMouseClick(text2x, text2y);
                Sleep(300); // Wait for the click action
                if (!shouldContinueLoop) break;

                // Type for paste
                typeText(L"past");
                Sleep(300); // Wait for the text input
                if (!shouldContinueLoop) break;

                // Transfer All from
                PerformMouseClick(xfer2x, xfer2y);
                Sleep(550);
                if (!shouldContinueLoop) break;

                // Click Text Box
                PerformMouseClick(text2x, text2y);
                Sleep(300); // Wait for the click action
                if (!shouldContinueLoop) break;

                // Type for paste
                typeText(L"poly");
                Sleep(300); // Wait for the text input
                if (!shouldContinueLoop) break;

                // Transfer All from
                PerformMouseClick(xfer2x, xfer2y);
                Sleep(550);
                if (!shouldContinueLoop) break;

                // Close Inventory
                PerformMouseClick(closex, closey);
                if (!shouldContinueLoop) break;

                Sleep(500); // Delay before Restarting
                if (!shouldContinueLoop) break;
            }
            // Code to Empty Crop Plots
            else if (wcscmp(selItem, L"Empty Crop Plots") == 0)
            {
                // Check for Inv Open
                while (!IsColorWithinTolerance(GetPixelColor(invcolx, invcoly), RGB(188, 244, 255), 30))
                    Sleep(500);
                if (!shouldContinueLoop) break;

                // Transfer All from
                PerformMouseClick(xfer2x, xfer2y);
                Sleep(550);
                if (!shouldContinueLoop) break;

                // Transfer All to
                PerformMouseClick(xfer1x, xfer1y);
                Sleep(300);
                if (!shouldContinueLoop) break;

                // Transfer All to
                PerformMouseClick(xfer1x, xfer1y);
                Sleep(300);
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
                Sleep(500); // Delay before Restarting
                if (!shouldContinueLoop) break;
            }
        }
    }
}