#include "pch.h"
#include "Features.h"
#include <windows.h> // Required for Sleep, SetCursorPos, and mouse_event

void BackupJoiner(HWND ServerN)
{
    {
        // Get the current screen resolution
        int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        int screenHeight = GetSystemMetrics(SM_CYSCREEN);

        int click10X = 0, click10Y = 0, click20X = 0, click20Y = 0, click30X = 0, click30Y = 0,
            click40X = 0, click40Y = 0, click50X = 0, click50Y = 0, click60X = 0, click60Y = 0,
            click90X = 0, click90Y = 0;

        // Check the current screen resolution and set the coordinates accordingly
        if (screenWidth == 3440 && screenHeight == 1440)
        {
            click90X = 2608;
            click90Y = 261;
            click10X = 1633;
            click10Y = 435;
            click20X = 2725;
            click20Y = 1261;
            click30X = 1080;
            click30Y = 1243;
            click40X = 1865;
            click40Y = 971;
            click50X = 667;
            click50Y = 1170;
            click60X = 1131;
            click60Y = 769;

        }

        else if (screenWidth == 2560 && screenHeight == 1440)
        {
            click10X = 1287;
            click10Y = 436;
            click20X = 2284;
            click20Y = 1258;
            click30X = 705;
            click30Y = 1246;
            click40X = 1428;
            click40Y = 969;
            click50X = 218;
            click50Y = 1173;
            click60X = 703;
            click60Y = 778;
        }

        else if (screenWidth == 1920 && screenHeight == 1080)
        {
            click10X = 1016;
            click10Y = 330;
            click20X = 1713;
            click20Y = 943;
            click30X = 521;
            click30Y = 933;
            click40X = 1057;
            click40Y = 728;
            click50X = 170;
            click50Y = 867;
            click60X = 525;
            click60Y = 563;
        }

        else if (screenWidth == 1920 && screenHeight == 1200)
        {
            click10X = 971;
            click10Y = 381;
            click20X = 1729;
            click20Y = 998;
            click30X = 478;
            click30Y = 1034;
            click40X = 1082;
            click40Y = 809;
            click50X = 169;
            click50Y = 936;
            click60X = 525;
            click60Y = 636;
        }
        else if (screenWidth == 1536 && screenHeight == 864)
        {
            click10X = 692;
            click10Y = 263;
            click20X = 1324;
            click20Y = 760;
            click30X = 422;
            click30Y = 749;
            click40X = 837;
            click40Y = 583;
            click50X = 113;
            click50Y = 700;
            click60X = 422;
            click60Y = 469;
        }
        while (true)
        {
            // perform the first left mouse click
            SetCursorPos(click90X, click90Y);
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
}