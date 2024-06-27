#include "pch.h"
#include "Features.h"
#include <windows.h>

// Timer display and increment/decrement amounts
int timerValue = 0;
const int TIME_INCREMENT = 10; // Adjust as needed

// Function to update the timer display
void UpdateTimerDisplay()
{
    wchar_t hrText[3], mnText[3], scText[3];
    swprintf_s(hrText, L"%02d", timerValue / 3600);
    swprintf_s(mnText, L"%02d", (timerValue / 60) % 60);
    swprintf_s(scText, L"%02d", timerValue % 60);

    SetWindowText(TimerHR, hrText);
    SetWindowText(TimerMN, mnText);
    SetWindowText(TimerSC, scText);
}

// Update timer hours
void UpdateTimerHours(int hoursToAdd)
{
    timerValue += hoursToAdd * 3600;
    if (timerValue < 0) {
        timerValue = 0; // Prevent negative timer values
    }
    UpdateTimerDisplay();
}

// Update timer minutes
void UpdateTimerMinutes(int minutesToAdd)
{
    timerValue += minutesToAdd * 60;
    if (timerValue < 0) {
        timerValue = 0; // Prevent negative timer values
    }
    UpdateTimerDisplay();
}

// Update timer seconds
void UpdateTimerSeconds(int secondsToAdd)
{
    timerValue += secondsToAdd;
    if (timerValue < 0) {
        timerValue = 0; // Prevent negative timer values
    }
    UpdateTimerDisplay();
}

// Function to handle increasing time
void OnIncreaseHours()
{
    UpdateTimerHours(1);
}

void OnDecreaseHours()
{
    UpdateTimerHours(-1);
}

void OnIncreaseMinutes()
{
    UpdateTimerMinutes(1);
}

void OnDecreaseMinutes()
{
    UpdateTimerMinutes(-1);
}

void OnIncreaseSeconds()
{
    UpdateTimerSeconds(1);
}

void OnDecreaseSeconds()
{
    UpdateTimerSeconds(-1);
}

LRESULT CALLBACK TimerBoxProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Handle button clicks
        switch (wmId)
        {
        case 1: // Handle hours up button
            OnIncreaseHours();
            break;
        case 2: // Handle hours down button
            OnDecreaseHours();
            break;
        case 3: // Handle minutes up button
            OnIncreaseMinutes();
            break;
        case 4: // Handle minutes down button
            OnDecreaseMinutes();
            break;
        case 5: // Handle seconds up button
            OnIncreaseSeconds();
            break;
        case 6: // Handle seconds down button
            OnDecreaseSeconds();
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
        }
    }
    break;

    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

// Main timer function (entry point)
void Timer()
{
    // Implement your timer loop or logic here
    // This could include waiting for certain events or timing intervals
    while (true)
    {
        // Example: Sleep for some interval (e.g., 1 second)
        Sleep(1000);

        // Example: Check if shouldContinueLoop flag is false to exit the loop
        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        // Example: Check for other conditions or events to adjust timer
    }
}
