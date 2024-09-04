#include "pch.h"
#include "Features.h"
#include <windows.h> // Required for Sleep, SetCursorPos, and mouse_event
#include "Coordinates.h"

// Function to check if Jump Jump Blobs in RGB range
bool isBLOBColorRange(BYTE red, BYTE green, BYTE blue, BYTE rMin, BYTE rMax, BYTE gMin, BYTE gMax, BYTE bMin, BYTE bMax) {
    return (red >= rMin && red <= rMax) && (green >= gMin && green <= gMax) && (blue >= bMin && blue <= bMax);
}

// Function to move the mouse cursor left and right until the color matches
void MoveMouseUntilColorMatches(HDC hdc, int x, int y, COLORREF targetColor) {
    POINT cursorPos;
    bool moveLeft = true;

    while (GetPixel(hdc, x, y) != targetColor) {
        // Get current cursor position
        GetCursorPos(&cursorPos);

        // Move the cursor left and right by 4 pixels
        if (moveLeft) {
            SetCursorPos(cursorPos.x - 4, cursorPos.y);
        }
        else {
            SetCursorPos(cursorPos.x + 4, cursorPos.y);
        }

        // Toggle direction
        moveLeft = !moveLeft;

        // Wait for a short period before checking the color again
        Sleep(100); // Adjust the delay as needed

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }
    }
}

// Function to contain the code for case 10
void ClubARK()
{
    setCoordinates(); // Set the coordinates based on the screen resolution
    HDC hdc = GetDC(NULL);

    // Set the thread priority to highest
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

    while (true)
    {
        // Color of Alpha Pink
        COLORREF color = GetPixel(hdc, DDJC1X, DDJC1Y);
        if (color == RGB(255, 169, 152)) // color is FFA998
        {             
            // Check color at DDJC2X, DDJC2Y (the blobs)
            COLORREF color = GetPixel(hdc, DDJC2X, DDJC2Y);
            BYTE red = GetRValue(color);
            BYTE green = GetGValue(color);
            BYTE blue = GetBValue(color);

            // Log the RGB values to a file
            //FILE* logFile;
            //errno_t err = fopen_s(&logFile, "rgb.txt", "a");
            //if (err == 0 && logFile != NULL) {
            //    fprintf(logFile, "Color at (%d, %d): R=%d, G=%d, B=%d\n", DDJC2X, DDJC2Y, red, green, blue);
            //    fclose(logFile);
            //}

            // Check if the BLOB color is within the specified range
            if (isBLOBColorRange(red, green, blue, rMin, rMax, gMin, gMax, bMin, bMax)) 
            {
                // Simulate spacebar key press
                keybd_event(VK_SPACE, 0, 0, 0); // Press spacebar
                Sleep(90); // Wait 90 milliseconds
                keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0); // Release spacebar
            }
            else 
            {
                // Simulate 'C' key press
                keybd_event('C', 0, 0, 0); // Press 'C'
                Sleep(10); // Wait 10 milliseconds
                keybd_event('C', 0, KEYEVENTF_KEYUP, 0); // Release 'C'
            }
        }
        else
        {
            Sleep(5000); // Wait 500 milliseconds
            
            if (!shouldContinueLoop)
            {
                 break; // Exit the loop immediately
            }

            // Simulate 'E' key press
            keybd_event('E', 0, 0, 0); // Press 'E'
            Sleep(100); // Wait 100 milliseconds
            keybd_event('E', 0, KEYEVENTF_KEYUP, 0); // Release 'E'
            Sleep(1000); // Wait 1000 milliseconds

            if (!shouldContinueLoop)
            {
                break; // Exit the loop immediately
            }

            // Color of White Menu Bar
            COLORREF color = GetPixel(hdc, CAJC1X, CAJC1Y);
            if (color == RGB(255, 255, 255)) // color is FFFFFF
            {

                // Wait for pixel color to match White Bar (Original Code)
                // while (GetPixel(hdc, CAJC1X, CAJC1Y) != RGB(255, 255, 255))
                Sleep(500); // Wait 500 milliseconds

                if (!shouldContinueLoop)
                {
                    break; // Exit the loop immediately
                }

                //MiniGames Click 
                PerformMouseClick(CAJ1X, CAJ1Y);
                Sleep(600); // Wait 500 milliseconds

                if (!shouldContinueLoop)
                {
                    break; // Exit the loop immediately
                }

                //Duck Duck Jump Alpha Click 
                PerformMouseClick(CAJ2X, CAJ2Y);
                Sleep(600); // Wait 500 milliseconds

                if (!shouldContinueLoop)
                {
                    break; // Exit the loop immediately
                }

                SetCursorPos(CAJ3X, CAJ3Y);
                Sleep(500); // Wait 500 milliseconds

                if (!shouldContinueLoop)
                {
                    break; // Exit the loop immediately
                }

                // Wait for pixel color to match Yellow Join
                MoveMouseUntilColorMatches(hdc, CAJC2X, CAJC2Y, RGB(255, 240, 0));
                Sleep(500); // Wait 500 milliseconds

                if (!shouldContinueLoop)
                {
                    break; // Exit the loop immediately
                }

                //Join Game Click 
                PerformMouseClick(CAJ3X, CAJ3Y);
                Sleep(500); // Wait 500 milliseconds

                if (!shouldContinueLoop)
                {
                    break; // Exit the loop immediately
                }
                Sleep(10000); // Wait 10,000 milliseconds
            }
            else
            {
                Sleep(500);
                if (!shouldContinueLoop)
                {
                    break; // Exit the loop immediately
                }
            }
        }
        if (!shouldContinueLoop)
        {
            break; // Exit the loop immediately
        }
    }
    ReleaseDC(NULL, hdc);
}