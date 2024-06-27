#include "pch.h"
#include "Features.h"
#include <windows.h>
#include "Coordinates.h"
#include <string>

void DropThief()
{
    setCoordinates(); // Set the coordinates based on the screen resolution

    while (true)
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
}