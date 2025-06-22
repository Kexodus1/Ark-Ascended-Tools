#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"

void TribelogBot()
{
    setCoordinates(); // Set the coordinates based on the screen resolution

    while (true)
    {
        //Future Implementation of AutoFish (Depending on if they rework fishing)
        Sleep(1000);
        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }
    }
}