#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"

// Function Auto Join Server Code
void AutoJoiner(HWND ServerN)
{
    setCoordinates(); // Set the coordinates based on the screen resolution
    while (shouldContinueLoop) {
        // Check color at coordinates before clicking Server Text Box
        while (true)
        {
            COLORREF pixelColor = GetPixelColor(servlcX, servlcY);
            if (IsColorWithinTolerance(pixelColor, RGB(255, 255, 255), 0)) {
                // Continue with the rest of the code if the color matches
                break;
            }
            if (!shouldContinueLoop) break;
            else {
                // Simulate a mouse click if the color does not match
                PerformMouseClick(click6X, click6Y);
                Sleep(1000); // Wait for a bit before rechecking
            }
            if (!shouldContinueLoop) break;
        }
        // Click Server Text Box
        PerformMouseClick(servnx, servny);
        Sleep(200);
        if (!shouldContinueLoop) break;
        // Retrieve the Server Number
        wchar_t selectedValue[256];
        GetWindowText(ServerN, selectedValue, 256);
        // Type the selected value
        typeText(selectedValue);
        Sleep(500); // Wait for the text input
        if (!shouldContinueLoop) break;
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
            COLORREF pixelColor = GetPixelColor(servtx, servty);
            if (IsColorWithinTolerance(pixelColor, RGB(83, 39, 1), tolerance) ||
                IsColorWithinTolerance(pixelColor, RGB(61, 27, 2), tolerance)) // Top Server Color
            {
                break; // Exit the loop if the color matches
            }
        }
        if (!shouldContinueLoop) break;
        // Server 1st Join Button
        PerformMouseClick(servjx, servjy);
        Sleep(500);
        if (!shouldContinueLoop) break;
        // Wait for pixel color to match either Server Full Fail, Connection Failed, or Mod Screen Join
        bool ServerFullFail = false;
        bool ConnectionFailed = false;
        bool ModScreenJoin = false;
        while (true)
        {
            COLORREF pixelColor = GetPixelColor(color1x, color1y);
            if (IsColorWithinTolerance(pixelColor, RGB(193, 245, 255), tolerance)) // Server Full Fail color
            {
                ServerFullFail = true;
                break;
            }
            pixelColor = GetPixelColor(color2x, color2y);
            if (IsColorWithinTolerance(pixelColor, RGB(135, 79, 23), tolerance)) // Mod Screen Join color
            {
                ModScreenJoin = true;
                break;
            }
            pixelColor = GetPixelColor(color3x, color3y);
            if (IsColorWithinTolerance(pixelColor, RGB(193, 245, 255), tolerance)) // Connection Failed color
            {
                ConnectionFailed = true;
                break;
            }
            Sleep(500); // Wait before checking again
            if (!shouldContinueLoop) break;
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
                COLORREF pixelColor = GetPixelColor(color1x, color1y);
                if (IsColorWithinTolerance(pixelColor, RGB(193, 245, 255), tolerance)) // Server Full Fail color
                {
                    ServerFullFail = true;
                    FullConnFail = false;
                }
                else
                {
                    pixelColor = GetPixelColor(color3x, color3y);
                    if (IsColorWithinTolerance(pixelColor, RGB(193, 245, 255), tolerance)) // Connection Failed color
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
                if (!shouldContinueLoop) break;
                // Ark main menu start button
                PerformMouseClick(startX, startY);
                Sleep(500);
                if (!shouldContinueLoop) break;
                // Select to Join
                PerformMouseClick(click6X, click6Y);
                Sleep(500);
                if (!shouldContinueLoop) break;
            }
            // Handle Connection Failed
            else if (ConnectionFailed)
            {
                // Cancel Que Wait
                PerformMouseClick(click4X, click4Y);
                Sleep(500);
                if (!shouldContinueLoop) break;
                // Go back to Selection
                PerformMouseClick(click5X, click5Y);
                Sleep(200);
                if (!shouldContinueLoop) break;
                // Select to Join
                PerformMouseClick(click6X, click6Y);
                Sleep(500);
                if (!shouldContinueLoop) break;
            }
        }
        // Connection Failed popup
        else if (ConnectionFailed)
        {
            //Cancel Que Wait
            PerformMouseClick(click4X, click4Y);
            Sleep(500);
            if (!shouldContinueLoop) break;
            //Go back to Selection
            PerformMouseClick(click5X, click5Y);
            Sleep(200);
            if (!shouldContinueLoop) break;
            //Select to Join
            PerformMouseClick(click6X, click6Y);
            Sleep(500);
            if (!shouldContinueLoop) break;
        }
        // Server Full Fail popup
        else if (ServerFullFail)
        {
            // Server full accept button
            PerformMouseClick(fullfX, fullfY);
            Sleep(500);
            if (!shouldContinueLoop) break;
            // Ark main menu start button
            PerformMouseClick(startX, startY);
            Sleep(500);
            if (!shouldContinueLoop) break;
            //Select to Join
            PerformMouseClick(click6X, click6Y);
            Sleep(500);
            if (!shouldContinueLoop) break;
        }
    }
}