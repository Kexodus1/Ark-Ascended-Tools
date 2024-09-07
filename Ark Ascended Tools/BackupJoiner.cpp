#include "pch.h"
#include "Features.h"
#include "Coordinates.h"
#include <windows.h> // Required for Sleep, SetCursorPos, and mouse_event

void BackupJoiner(HWND ServerN)
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
            Sleep(1000); // Wait for the text input

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

            // Wait 2500ms
            Sleep(2500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            //2nd Join Button 
            PerformMouseClick(click3X, click3Y);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Wait 3500ms
            Sleep(3500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            //Cancel Que Wait
            PerformMouseClick(click4X, click4Y);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Wait 200ms
            Sleep(1000);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            //Go back to Selection
            PerformMouseClick(click5X, click5Y);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Wait 200ms
            Sleep(1500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            //Select to Join
            PerformMouseClick(click6X, click6Y);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Add a delay to control the speed of the loop
            Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }
}