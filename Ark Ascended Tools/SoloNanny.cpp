#include "pch.h"
#include "Features.h"
#include <windows.h>
#include "Coordinates.h"
#include <string>

void SoloNanny(HWND Nanny)
{
    setCoordinates(); // Set the coordinates based on the screen resolution

    while (true)
    {
        while (!IsColorWithinTolerance(GetPixelColor(invcolx, invcoly), RGB(188, 244, 255), 30))
            Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        Sleep(1000); // Wait for the click action

        // Click at xfer2X, xfer2Y
        PerformMouseClick(xfer2x, xfer2y);
        Sleep(500); // Wait for the click action

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Click at text1X, text1Y
        PerformMouseClick(text1x, text1y);
        Sleep(500); // Wait for the click action

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Retrieve the text from the Nanny drop-down box
        wchar_t selectedValue[256];
        GetWindowText(Nanny, selectedValue, 256);
        // Type the selected value
        typeText(selectedValue);

        Sleep(1000); // Wait for the text input

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Click at xfer1X, xfer1Y
        PerformMouseClick(xfer1x, xfer1y);
        Sleep(500); // Wait for the click action

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Check color at promptx, prompty
        COLORREF color = GetPixelColor(promptx, prompty);
        if (IsColorWithinTolerance(color, RGB(193, 245, 255), 30)) // Popup Prompt color
        {
            PerformMouseClick(okayx, okayy);

            Sleep(300);
        }
        else
        {
            Sleep(300);
        }

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a 15-second delay
        Sleep(15000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a 15-second delay
        Sleep(15000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a 15-second delay
        Sleep(15000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a 15-second delay
        Sleep(15000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a 15-second delay
        Sleep(15000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a 15-second delay
        Sleep(15000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a 15-second delay
        Sleep(15000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a 15-second delay
        Sleep(15000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }
    }
}