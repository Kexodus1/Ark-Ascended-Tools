#include "pch.h"
#include "Features.h"
#include <windows.h>
#include "Coordinates.h"
#include <string>

void AutoGrabber()
{
    setCoordinates(); // Set the coordinates based on the screen resolution

    while (true)
    {
        // Get the selected item from the AutoGrab drop-down box
        int selIndex = SendMessage(AutoGrab, CB_GETCURSEL, 0, 0);
        WCHAR selItem[256] = {0};
        SendMessage(AutoGrab, CB_GETLBTEXT, selIndex, (LPARAM)selItem);
        selItem[255] = 0; // Ensure null-termination

        if (wcscmp(selItem, L"Air Drop") == 0)
        {
            while (GetPixel(GetDC(NULL), dropcolorx, dropcolory) != RGB(188, 244, 255))
                Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            PerformMouseClick(xferdropx, xferdropy);
            Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            PerformMouseClick(xferdropx, xferdropy);
            Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            PerformMouseClick(closex, closey);
            Sleep(30000);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }
        else if (wcscmp(selItem, L"Raptor Claus") == 0)
        {
            while (GetPixel(GetDC(NULL), dropcolorx, dropcolory) != RGB(188, 244, 255))
                Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            PerformMouseClick(xferdropx, xferdropy);
            Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            PerformMouseClick(xferdropx, xferdropy);
            Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            PerformMouseClick(closex, closey);
            Sleep(30000);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }
        else if (wcscmp(selItem, L"Death Bag") == 0)
        {
            while (GetPixel(GetDC(NULL), invcolx, invcoly) != RGB(188, 244, 255))
                Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            PerformMouseClick(xfer2x, xfer2y);
            Sleep(550);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Check color at promptx, prompty
            COLORREF color = GetPixel(GetDC(NULL), promptx, prompty);
            if (color == RGB(193, 245, 255)) // Assuming red color is RGB(255, 0, 0)
            {
                PerformMouseClick(okayx, okayy);
                if (!shouldContinueLoop) {
                    break; // Exit the loop immediately
                }
                Sleep(300);

                PerformMouseClick(closex, closey);
                if (!shouldContinueLoop) {
                    break; // Exit the loop immediately
                }
            }
            else
            {
                PerformMouseClick(closex, closey);
            }

            Sleep(5000);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }
        else if (wcscmp(selItem, L"Empty Crop Plots") == 0)
        {
            while (GetPixel(GetDC(NULL), invcolx, invcoly) != RGB(188, 244, 255))
                Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            PerformMouseClick(xfer2x, xfer2y);
            Sleep(550);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            PerformMouseClick(xfer1x, xfer1y);
            Sleep(300);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            PerformMouseClick(xfer1x, xfer1y);
            Sleep(300);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Check color at promptx, prompty
            COLORREF color = GetPixel(GetDC(NULL), promptx, prompty);
            if (color == RGB(193, 245, 255)) // Assuming red color is RGB(255, 0, 0)
            {
                PerformMouseClick(okayx, okayy);

                Sleep(300);

                PerformMouseClick(closex, closey);
            }
            else
            {
                PerformMouseClick(closex, closey);
            }

            Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }
    }
}