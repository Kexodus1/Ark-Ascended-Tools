#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"

void PVPTools()
{
    setCoordinates(); // Set the coordinates based on the screen resolution

    while (true)
    {
        // Get the selected item from the PVPTools drop-down box
        LRESULT selIndex = SendMessage(PVPTool, CB_GETCURSEL, 0, 0);
        if (selIndex != CB_ERR) // Ensure the selection is valid
        {
            WCHAR selItem[256] = { 0 };
            SendMessage(PVPTool, CB_GETLBTEXT, (WPARAM)selIndex, (LPARAM)selItem);
            selItem[255] = 0; // Ensure null-termination

            // Death Bag code
            if (wcscmp(selItem, L"Death Bag Grab") == 0)
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
            // Auto Flak code
            else if (wcscmp(selItem, L"Auto Flak Changer") == 0)
            {
            }
        }
    }
}