#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"

// Function for Backup Joiner checkbox code
void BackupJoiner(HWND ServerN)
{
    setCoordinates(); // Set the coordinates based on the screen resolution
        while (true)
        {
            //Click Server Text Box
            PerformMouseClick(servnx, servny);
            Sleep(200);
            if (!shouldContinueLoop) break;

            // Retrieve the Server Number
            wchar_t selectedValue[256];
            GetWindowText(ServerN, selectedValue, 256);
            // Type the selected value
            typeText(selectedValue);
            Sleep(1000); // Wait for the text input
            if (!shouldContinueLoop) break;

            //Top Server Click
            PerformMouseClick(servtx, servty);
            Sleep(500);
            if (!shouldContinueLoop) break;

            //Server 1st Join Button
            PerformMouseClick(servjx, servjy);
            Sleep(500);
            if (!shouldContinueLoop) break;

            // Wait 4500ms
            Sleep(4500);
            if (!shouldContinueLoop) break;

            //2nd Join Button 
            PerformMouseClick(click3X, click3Y);
            if (!shouldContinueLoop) break;

            // Wait 8500ms
            Sleep(8500);
            if (!shouldContinueLoop) break;

            //Cancel Que Wait
            PerformMouseClick(click4X, click4Y);
            if (!shouldContinueLoop) break;

            // Wait 1000ms
            Sleep(1000);
            if (!shouldContinueLoop) break;

            //Go back to Selection
            PerformMouseClick(click5X, click5Y);
            if (!shouldContinueLoop) break;

            // Wait 1500ms
            Sleep(1500);
            if (!shouldContinueLoop) break;

            //Select to Join
            PerformMouseClick(click6X, click6Y);
            if (!shouldContinueLoop) break;

            // Add a delay to control the speed of the loop
            Sleep(500);
            if (!shouldContinueLoop) break;
        }
}