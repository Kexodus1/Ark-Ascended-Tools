#include "pch.h"
#include "Resource.h"
#include "Features.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

// Declare hInst as an external variable
extern HINSTANCE hInst;

// Global variables for timer
int TimerHours = 0;
int TimerMinutes = 0;
int TimerSeconds = 0;
UINT_PTR TimerID = 0; // Timer ID for tracking the timer

// Button Clicks for Timer up/down
void HandleButtonClick(HWND hWnd, WPARAM wParam) {
    wchar_t currentText[3];
    int value;

    switch (LOWORD(wParam)) {
    case 1: // Hours Up Button (hHUB)
        GetWindowText(TimerHR, currentText, 3);
        value = _wtoi(currentText);
        value = (value + 1) % 24; // Wrap around at 24 hours
        swprintf_s(currentText, L"%02d", value);
        SetWindowText(TimerHR, currentText);
        break;

    case 2: // Hours Down Button (hHDB)
        GetWindowText(TimerHR, currentText, 3);
        value = _wtoi(currentText);
        value = (value + 23) % 24; // Wrap around at 24 hours
        swprintf_s(currentText, L"%02d", value);
        SetWindowText(TimerHR, currentText);
        break;

    case 3: // Minutes Up Button (hMUB)
        GetWindowText(TimerMN, currentText, 3);
        value = _wtoi(currentText);
        value = (value + 1) % 60; // Wrap around at 60 minutes
        swprintf_s(currentText, L"%02d", value);
        SetWindowText(TimerMN, currentText);
        break;

    case 4: // Minutes Down Button (hMDB)
        GetWindowText(TimerMN, currentText, 3);
        value = _wtoi(currentText);
        value = (value + 59) % 60; // Wrap around at 60 minutes
        swprintf_s(currentText, L"%02d", value);
        SetWindowText(TimerMN, currentText);
        break;

    case 5: // Seconds Up Button (hSUB)
        GetWindowText(TimerSC, currentText, 3);
        value = _wtoi(currentText);
        value = (value + 1) % 60; // Wrap around at 60 seconds
        swprintf_s(currentText, L"%02d", value);
        SetWindowText(TimerSC, currentText);
        break;

    case 6: // Seconds Down Button (hSDB)
        GetWindowText(TimerSC, currentText, 3);
        value = _wtoi(currentText);
        value = (value + 59) % 60; // Wrap around at 60 seconds
        swprintf_s(currentText, L"%02d", value);
        SetWindowText(TimerSC, currentText);
        break;

    default:
        break;
    }
}

void CALLBACK TimerProc(HWND hWnd, UINT message, UINT_PTR idTimer, DWORD dwTime) {
    // Update timer display in respective controls
    wchar_t timerText[20];
    swprintf_s(timerText, L"%02d:", TimerHours);
    SetWindowText(TimerHR, timerText);

    swprintf_s(timerText, L"%02d:", TimerMinutes);
    SetWindowText(TimerMN, timerText);

    swprintf_s(timerText, L"%02d", TimerSeconds);
    SetWindowText(TimerSC, timerText);

    // Decrement timer
    if (TimerSeconds > 0) {
        TimerSeconds--;
    }
    else {
        if (TimerMinutes > 0) {
            TimerMinutes--;
            TimerSeconds = 59;
        }
        else {
            if (TimerHours > 0) {
                TimerHours--;
                TimerMinutes = 59;
                TimerSeconds = 59;
            }
            else {
                // Timer reached zero, stop the timer
                KillTimer(hWnd, TimerID);
                // Stop the functions
                shouldContinueLoop = false;
                // Wait for threads to terminate
                Sleep(100);
                functionsRunning = false;
                // Update UI: Change button text to "Start"
                SetWindowText(hButton, L"Start - F4");
                // Redraw the button to update its appearance
                RedrawWindow(hButton, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);
                // Play sound if TimerSND is checked
                if (SendMessage(TimerSND, BM_GETCHECK, 0, 0) == BST_CHECKED) 
                {
                    // Play sound from resource
                    PlaySound(MAKEINTRESOURCE(IDR_WAVE), hInst, SND_RESOURCE | SND_ASYNC);
                }
            }
        }
    }
}

void StartTimer(HWND hWnd, int hours, int minutes, int seconds) 
{
    // Set initial timer values
    TimerHours = hours;
    TimerMinutes = minutes;
    TimerSeconds = seconds;

    // Set a timer to trigger every second (1000 milliseconds)
    TimerID = SetTimer(hWnd, 1, 1000, TimerProc);
}
