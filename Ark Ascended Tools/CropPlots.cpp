#include "pch.h"
#include "Features.h"
#include <windows.h>
#include "Coordinates.h"
#include <string>

void CropPlots()
{
    setCoordinates(); // Set the coordinates based on the screen resolution

    while (true)
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

        PerformMouseClick(closex, closey);
        Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }
    }
}