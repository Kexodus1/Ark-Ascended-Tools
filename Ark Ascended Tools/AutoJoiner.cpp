#include "pch.h"
#include "Features.h"
#include "Coordinates.h"
#include <windows.h>
#include <string>

void SendTextInput(HWND ServerN) {
    wchar_t text[256];
    GetWindowText(ServerN, text, 256);

    for (int i = 0; text[i] != '\0'; ++i) {
        SHORT key = VkKeyScan(text[i]);
        if (key == -1) {
            // Handle characters that cannot be converted
            continue;
        }
        BYTE virtualKey = LOBYTE(key);
        BYTE shiftState = HIBYTE(key);

        // Press Shift if needed
        if (shiftState & 1) {
            keybd_event(VK_SHIFT, 0, 0, 0);
        }

        keybd_event(virtualKey, 0, 0, 0);
        keybd_event(virtualKey, 0, KEYEVENTF_KEYUP, 0);

        // Release Shift if needed
        if (shiftState & 1) {
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
        }
    }
}

void AutoJoiner(HWND ServerN)
{
    // Get the current screen resolution
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int color1x = 0, color1y = 0, color2x = 0, color2y = 0, color3x = 0, color3y = 0,
        click1X = 0, click1Y = 0, click2X = 0, click2Y = 0, click3X = 0, click3Y = 0,
        click4X = 0, click4Y = 0, click5X = 0, click5Y = 0, click6X = 0, click6Y = 0,
        click7X = 0, click7Y = 0, click9X = 0, click9Y = 0;

    // Check the current screen resolution and set the coordinates accordingly
    if (screenWidth == 3440 && screenHeight == 1440)
    {
        color1x = 657;
        color1y = 438;
        color2x = 1072;
        color2y = 1246;
        color3x = 1641;
        color3y = 486;
        click9X = 2635;
        click9Y = 259;
        click1X = 2721;
        click1Y = 1190;
        click2X = 2721;
        click2Y = 1259;
        click3X = 1082;
        click3Y = 1245;
        click4X = 1866;
        click4Y = 971;
        click5X = 664;
        click5Y = 1173;
        click6X = 1142;
        click6Y = 756;
        click7X = 1142;
        click7Y = 756;

    }
    else if (screenWidth == 2560 && screenHeight == 1440)
    {
        color1x = 219;
        color1y = 438;
        color2x = 632;
        color2y = 1241;
        color3x = 1177;
        color3y = 482;
        click1X = 2272;
        click1Y = 1189;
        click2X = 2269;
        click2Y = 1258;
        click3X = 619;
        click3Y = 1247;
        click4X = 1398;
        click4Y = 973;
        click5X = 222;
        click5Y = 1172;
        click6X = 713;
        click6Y = 790;
        click7X = 713;
        click7Y = 790;
    }
    else if (screenWidth == 1920 && screenHeight == 1080)
    {
        color1x = 970;
        color1y = 327;
        color2x = 476;
        color2y = 932;
        color3x = 937;
        color3y = 369;
        click1X = 1688;
        click1Y = 896;
        click2X = 1709;
        click2Y = 943;
        click3X = 469;
        click3Y = 933;
        click4X = 1070;
        click4Y = 729;
        click5X = 169;
        click5Y = 877;
        click6X = 529;
        click6Y = 582;
        click7X = 529;
        click7Y = 582;
    }
    else if (screenWidth == 1920 && screenHeight == 1200)
    {
        color1x = 164;
        color1y = 389;
        color2x = 421;
        color2y = 1031;
        color3x = 892;
        color3y = 406;
        click1X = 1711;
        click1Y = 955;
        click2X = 1718;
        click2Y = 1005;
        click3X = 417;
        click3Y = 1037;
        click4X = 1069;
        click4Y = 806;
        click5X = 170;
        click5Y = 937;
        click6X = 524;
        click6Y = 647;
        click7X = 524;
        click7Y = 647;
    }
    else if (screenWidth == 1536 && screenHeight == 864)
    {
        color1x = 775;
        color1y = 262;
        color2x = 387;
        color2y = 744;
        color3x = 710;
        color3y = 294;
        click1X = 726;
        click1Y = 265;
        click2X = 1362;
        click2Y = 754;
        click3X = 415;
        click3Y = 743;
        click4X = 857;
        click4Y = 582;
        click5X = 139;
        click5Y = 703;
        click6X = 421;
        click6Y = 454;
        click7X = 421;
        click7Y = 454;
    }
    while (true)
    {
        while (GetPixel(GetDC(NULL), color1x, color1y) != RGB(218, 218, 149))
            Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        PerformMouseClick(click9X, click9Y);
        Sleep(200);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        SendTextInput(ServerN);
        Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        PerformMouseClick(click1X, click1Y);
        PerformMouseClick(click2X, click2Y);

        // Wait for pixel color to match
        while (GetPixel(GetDC(NULL), color2x, color2y) != RGB(135, 79, 23))
            Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        PerformMouseClick(click3X, click3Y);

        // Wait for pixel color to match
        while (GetPixel(GetDC(NULL), color3x, color3y) != RGB(193, 245, 255))
            Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        PerformMouseClick(click4X, click4Y);
        PerformMouseClick(click5X, click5Y);
        Sleep(200);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        PerformMouseClick(click6X, click6Y);
        Sleep(500);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }

        PerformMouseClick(click7X, click7Y);
        Sleep(1000);

        if (!shouldContinueLoop) {
            break; // Exit the loop immediately
        }
    }
}
