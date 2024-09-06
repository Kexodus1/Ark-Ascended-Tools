#include "pch.h"
#include "Features.h"
#include "Coordinates.h"
#include <windows.h>
#include <string>

void AutoJoiner(HWND ServerN)
{
    setCoordinates(); // Set the coordinates based on the screen resolution
    while (true)
    {
        //Click Server Text Box
        PerformMouseClick(servnx, servny);
        Sleep(200);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Retrieve the Server Number
        wchar_t selectedValue[256];
        GetWindowText(ServerN, selectedValue, 256);
        // Type the selected value
        typeText(selectedValue);
        Sleep(500); // Wait for the text input

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        //Top Server Click
        PerformMouseClick(servtx, servty);
        Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        //Server 1st Join Button
        PerformMouseClick(servjx, servjy);
        Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Wait for pixel color to match either 2nd Join or Connection Failed
        HDC hdc = GetDC(NULL);
        bool connectionFailed = false;
        bool secondJoin = false;

        while (true)
        {
            COLORREF pixelColor = GetPixel(hdc, color2x, color2y);
            if (pixelColor == RGB(135, 79, 23)) // 2nd Join color
            {
                secondJoin = true;
                break;
            }

            pixelColor = GetPixel(hdc, color3x, color3y);
            if (pixelColor == RGB(193, 245, 255)) // Connection Failed color
            {
                connectionFailed = true;
                break;
            }

            Sleep(500); // Wait before checking again

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }

        ReleaseDC(NULL, hdc);

        // Mod Screen Join
        if (secondJoin)
        {
            //2nd Join Button 
            PerformMouseClick(click3X, click3Y);

            // Wait for pixel color to match Connection Failed
            while (GetPixel(GetDC(NULL), color3x, color3y) != RGB(193, 245, 255))
                Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            //Cancel Que Wait
            PerformMouseClick(click4X, click4Y);
            Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            //Go back to Selection
            PerformMouseClick(click5X, click5Y);
            Sleep(200);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            //Select to Join
            PerformMouseClick(click6X, click6Y);
            Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            //Select to Join
            PerformMouseClick(click6X, click6Y);
            Sleep(1000);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }
        // No Mod Screen Join
        else if (connectionFailed)
        {
            //Cancel Que Wait
            PerformMouseClick(click4X, click4Y);
            Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            //Go back to Selection
            PerformMouseClick(click5X, click5Y);
            Sleep(200);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            //Select to Join
            PerformMouseClick(click6X, click6Y);
            Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            //Select to Join
            PerformMouseClick(click6X, click6Y);
            Sleep(1000);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }
    }
}
