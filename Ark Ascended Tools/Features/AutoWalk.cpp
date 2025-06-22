#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"

// Release Keys when Stopped
void ReleaseKeys()
{
    keybd_event('W', 0, KEYEVENTF_KEYUP, 0); // Release 'W'
}

// Run Modifier
void TapRightShift()
{
    // Press and release right 'Shift'
    keybd_event(VK_RSHIFT, 0x36, 0, 0); // Press right 'Shift' (scan code for right shift is 0x36)
    Sleep(50); // Small delay to simulate a key press
    keybd_event(VK_RSHIFT, 0x36, KEYEVENTF_KEYUP, 0); // Release right 'Shift'
}

// Function for aAuto Walk / Run Code
void AutoWalk(bool isAutoRunChecked)
{
    while (true)
    {
        if (isAutoRunChecked) {
            TapRightShift(); // Tap right 'Shift' once if AutoRun is checked
        }

        keybd_event('W', 0, 0, 0); // Press 'W'

        while (shouldContinueLoop)
        {
            Sleep(10);
            if (!shouldContinueLoop) break;
        }

        ReleaseKeys(); // Release keys before exiting the function
        if (isAutoRunChecked) {
            TapRightShift(); // Tap right 'Shift' once if AutoRun is checked
        }
        if (!shouldContinueLoop) break;
    }
}