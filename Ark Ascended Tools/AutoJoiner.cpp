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
        // Click Server Text Box
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

        // Top Server Click \ Check
        while (true)
        {
            // Perform Top Server Click
            PerformMouseClick(servtx, servty);
            Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Check color for Top Server
            COLORREF pixelColor = GetPixel(GetDC(NULL), servtx, servty);
            if (pixelColor == RGB(83, 39, 1) || pixelColor == RGB(128, 64, 2)) // Top Server Color
            {
                break; // Exit the loop if the color matches
            }
        }

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Server 1st Join Button
        PerformMouseClick(servjx, servjy);
        Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Wait for pixel color to match either Server Full Fail, Connection Failed, or Mod Screen Join
        bool ServerFullFail = false;
        bool ConnectionFailed = false;
        bool ModScreenJoin = false;

        while (true)
        {
            COLORREF pixelColor = GetPixel(GetDC(NULL), color1x, color1y);
            if (pixelColor == RGB(193, 245, 255)) // Server Full Fail color
            {
                ServerFullFail = true;
                break;
            }

            pixelColor = GetPixel(GetDC(NULL), color2x, color2y);
            if (pixelColor == RGB(135, 79, 23)) // Mod Screen Join color
            {
                ModScreenJoin = true;
                break;
            }

            pixelColor = GetPixel(GetDC(NULL), color3x, color3y);
            if (pixelColor == RGB(193, 245, 255)) // Connection Failed color
            {
                ConnectionFailed = true;
                break;
            }

            Sleep(500); // Wait before checking again

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }

        // Mod Screen Join
        if (ModScreenJoin)
        {
            //2nd Join Button
            PerformMouseClick(click3X, click3Y);

            // Wait for pixel color to match either Server Full Fail or Connection Failed
            bool FullConnFail = true;
            while (FullConnFail)
            {
                COLORREF pixelColor = GetPixel(GetDC(NULL), color1x, color1y);
                if (pixelColor == RGB(193, 245, 255)) // Server Full Fail color
                {
                    ServerFullFail = true;
                    FullConnFail = false;
                }
                else
                {
                    pixelColor = GetPixel(GetDC(NULL), color3x, color3y);
                    if (pixelColor == RGB(193, 245, 255)) // Connection Failed color
                    {
                        ConnectionFailed = true;
                        FullConnFail = false;
                    }
                }
                Sleep(500); // Wait before checking again

                if (!shouldContinueLoop) {
                    FullConnFail = false; // Exit the loop immediately
                }
            }
            // Handle Server Full Fail
            if (ServerFullFail)
            {
                // Server full accept button
                PerformMouseClick(fullfX, fullfY);
                Sleep(500);

                if (!shouldContinueLoop) {
                    break; // Exit the loop immediately
                }

                // Ark main menu start button
                PerformMouseClick(startX, startY);
                Sleep(500);

                if (!shouldContinueLoop) {
                    break; // Exit the loop immediately
                }

                // Select to Join
                PerformMouseClick(click6X, click6Y);
                Sleep(500);

                if (!shouldContinueLoop) {
                    break; // Exit the loop immediately
                }

                // Select to Join
                PerformMouseClick(click6X, click6Y);
                Sleep(1000);

                if (!shouldContinueLoop) {
                    break; // Exit the loop immediately
                }
            }
            // Handle Connection Failed
            else if (ConnectionFailed)
            {
                // Cancel Que Wait
                PerformMouseClick(click4X, click4Y);
                Sleep(500);

                if (!shouldContinueLoop) {
                    break; // Exit the loop immediately
                }

                // Go back to Selection
                PerformMouseClick(click5X, click5Y);
                Sleep(200);

                if (!shouldContinueLoop) {
                    break; // Exit the loop immediately
                }

                // Select to Join
                PerformMouseClick(click6X, click6Y);
                Sleep(500);

                if (!shouldContinueLoop) {
                    break; // Exit the loop immediately
                }

                // Select to Join
                PerformMouseClick(click6X, click6Y);
                Sleep(1000);

                if (!shouldContinueLoop) {
                    break; // Exit the loop immediately
                }
            }
        }
        // Connection Failed popup
        else if (ConnectionFailed)
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
        // Server Full Fail popup
        else if (ServerFullFail)
        {
            // Server full accept button
            PerformMouseClick(fullfX, fullfY);
            Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Ark main menu start button
            PerformMouseClick(startX, startY);
            Sleep(500);

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
