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

            // Wait 200ms
            Sleep(100);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Get the text from the edit control
            wchar_t text[256];
            GetWindowText(ServerN, text, 256);

            INPUT inputs[256];
            ZeroMemory(inputs, sizeof(inputs));
            size_t textLength = wcslen(text); // Calculate the length once to avoid multiple calls
            for (UINT i = 0; i < textLength; i++) 
            {
                inputs[i].type = INPUT_KEYBOARD;
                inputs[i].ki.dwFlags = KEYEVENTF_UNICODE;
                inputs[i].ki.wScan = text[i];
            }
            SendInput(static_cast<UINT>(textLength), inputs, sizeof(INPUT));

            // Wait 200ms
            Sleep(200);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // perform the first left mouse click
            SetCursorPos(click10X, click10Y);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Wait 200ms
            Sleep(100);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Perform the second left mouse click
            SetCursorPos(click20X, click20Y);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Wait 200ms
            Sleep(4500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Once the color matches, perform the third left mouse click
            SetCursorPos(click30X, click30Y);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Wait 200ms
            Sleep(8500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Once the color matches, perform the fourth left mouse click
            SetCursorPos(click40X, click40Y);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Wait 200ms
            Sleep(1000);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Perform the fifth left mouse click
            SetCursorPos(click50X, click50Y);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Wait 200ms
            Sleep(1500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }

            // Perform the sixth left mouse click
            SetCursorPos(click60X, click60Y);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

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