#include "pch.h"
#include "Features.h"
#include "Coordinates.h"
#include <windows.h>
#include <string>

void typeText(const std::wstring& text);

// Function to press 'A' key ten times
void pressAKeyTenTimes() {
    for (int i = 0; i < 10; ++i) {
        keybd_event('A', 0, 0, 0); // Key down
        Sleep(50); // Small delay between key down and key up
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Key up
        Sleep(100); // Small delay between key presses
    }
}

// Function to press LMB for 30 seconds
//void PerformLMBClickForSeconds() {
//    const int clickDuration = 30 * 1000; // Seconds in milliseconds
//    ULONGLONG startTime = GetTickCount64(); // Get the current time
//
//    while (GetTickCount64() - startTime < clickDuration) {
//        if (!shouldContinueLoop) {
//            break; // Exit the loop immediately if stop condition is met
//        }
//        // Perform LMB click
//        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); // Mouse button down
//       Sleep(100); // Wait for the specified interval
//        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Mouse button up
//        Sleep(400); // Wait for the specified interval before the next click
//    }
//}

// Function for Case 12
void XPParty(bool isXPSoupChecked, bool isXPEaDrChecked, bool isXPToiletChecked)
{
    Sleep(3000); // 3 Second Delay before Start
    setCoordinates(); // Set the coordinates based on the screen resolution

    int SleepInterval = 100; // Check interval (in milliseconds)
    int Broth = 1; // Timer for '1' key press (20 minutes)
    int Chili = 1; // Timer for '2' key press (15 minutes)
    int Eatin = 1; // Timer for '1' key press (20 minutes)
    int Drink = 1; // Timer for '2' key press (15 minutes)

    const int press1Interval = 20 * 60 * 1000; // 20 minutes in milliseconds
    const int press2Interval = 15 * 60 * 1000; // 15 minutes in milliseconds
    const int press9Interval = 55 * 60 * 1000; // 55 minutes in milliseconds
    const int press0Interval = 25 * 60 * 1000; // 25 minutes in milliseconds

    while (true) {
        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }
        // Increment timers
        Broth += SleepInterval;
        Chili += SleepInterval;
        Eatin += SleepInterval;
        Drink += SleepInterval;
        // Code for Soups checked
        if (isXPSoupChecked) {
            // Broth Press '1' every 20 minutes
            if (Broth >= press1Interval) {
                keybd_event('1', 0, 0, 0); // Key down
                Sleep(50);
                keybd_event('1', 0, KEYEVENTF_KEYUP, 0); // Key up
                Sleep(100);
                Broth = 0; // Reset the timer for '1'
            }
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            // Chili Press '2' every 15 minutes
            if (Chili >= press2Interval) {
                keybd_event('2', 0, 0, 0); // Key down
                Sleep(50);
                keybd_event('2', 0, KEYEVENTF_KEYUP, 0); // Key up
                Sleep(100);
                Chili = 0; // Reset the timer for '2'
            }
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }
        // Code for Eat/Drink Checked
        if (isXPEaDrChecked) {
            // Broth Press '9' every 55 minutes
            if (Eatin >= press1Interval) {
                keybd_event('9', 0, 0, 0); // Key down
                Sleep(50);
                keybd_event('9', 0, KEYEVENTF_KEYUP, 0); // Key up
                Sleep(100);
                Eatin = 0; // Reset the timer for '9'
            }
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            // Chili Press '0' every 25 minutes
            if (Drink >= press2Interval) {
                keybd_event('0', 0, 0, 0); // Key down
                Sleep(50);
                keybd_event('0', 0, KEYEVENTF_KEYUP, 0); // Key up
                Sleep(100);
                Drink = 0; // Reset the timer for '0'
            }
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }
        // Code for XPToilet functionality
        if (isXPToiletChecked) {
            Sleep(1000);

            // Open Inventory w/ TAB
            keybd_event(VK_TAB, 0, 0, 0); // Press 'TAB'
            Sleep(100); // Wait 100 milliseconds
            keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0); // Release 'TAB'
            Sleep(1000); // Wait 1000 milliseconds

            if (!shouldContinueLoop) break;

            // Click Crafting Tab
            PerformMouseClick(PInvCX, PInvCY);
            Sleep(500);

            if (!shouldContinueLoop) break;

            // Click Player Text Input
            PerformMouseClick(text1x, text1y);
            Sleep(500);

            if (!shouldContinueLoop) break;

            // Type for Drawing Paper
            typeText(L"draw");
            Sleep(500); // Wait for the text input

            if (!shouldContinueLoop) break;

            // Move mouse to 1st crafting slot
            PerformMouseClick(PslotX, PslotY);
            Sleep(500);

            if (!shouldContinueLoop) break;

            // Press A 10 Times
            pressAKeyTenTimes();

            if (!shouldContinueLoop) break;

            // Close Inventory
            PerformMouseClick(closex, closey);
            Sleep(500);

            if (!shouldContinueLoop) break;

            // Perform LMB click for X seconds
            // PerformLMBClickForSeconds();
            // if (!shouldContinueLoop) break;

            // Press Numberpad +
            keybd_event(VK_ADD, 0, 0, 0); // Press 'NUMPAD +'
            Sleep(100); // Wait 100 milliseconds
            keybd_event(VK_ADD, 0, KEYEVENTF_KEYUP, 0); // Release 'NUMPAD +'
            Sleep(500); // Wait 1000 milliseconds

            Sleep(10000);
            if (!shouldContinueLoop) break;
        }
        else {
            // Press A continuously if XPToilet is NOT checked
            keybd_event('A', 0, 0, 0); // Key down
            Sleep(100);
            keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Key up
            Sleep(500);

            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }
    }
}