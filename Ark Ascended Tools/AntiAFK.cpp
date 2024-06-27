#include "pch.h"
#include "Features.h"
#include <windows.h> // Required for Sleep, SetCursorPos, and mouse_event

// Function to contain the code for case 3
void AntiAFK()
{
    while (true)
    {
        // Add a delay before pressing 's' key
        Sleep(10000); // Optional delay between key presses

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('A', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('D', 0, 0, 0); // Press the 'w' key
        Sleep(500); // Hold the 'w' key for 500 milliseconds
        keybd_event('D', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(5000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('0x69', 0, 0, 0); // Press the '9' key
        keybd_event('0x69', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(9000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('0x39', 0, 0, 0); // Press the '0' key
        keybd_event('0x39', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Add a delay to control the speed of the loop
        Sleep(120000);            // Add a delay before pressing 's' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        keybd_event('X', 0, 0, 0); // Press the 'w' key
        keybd_event('X', 0, KEYEVENTF_KEYUP, 0); // Release the 'w' key

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

    }
}
