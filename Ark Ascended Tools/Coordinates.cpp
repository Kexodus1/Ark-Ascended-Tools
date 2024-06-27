#include "pch.h"
#include "Coordinates.h"

// Define the extern variables
// inventory color rgb(188, 244, 255)
// drop thief rgb(128, 231, 255)
//               
int text1x, text1y, text2x, text2y, xfer1x, xfer1y, xfer2x,
xfer2y, closex, closey, drop1x, drop1y, drop2x, drop2y, blackx, 
blacky, invcolx, invcoly, xferdropx, xferdropy, dropcolorx, dropcolory;

void PerformMouseClick(int x, int y) {
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void setCoordinates() {
    // Get the current screen resolution
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Check the current screen resolution and set the coordinates accordingly
    if (screenWidth == 3440 && screenHeight == 1440) {
        text1x = 773;
        text1y = 262;
        text2x = 2131;
        text2y = 265;
        xfer1x = 920;
        xfer1y = 263;
        xfer2x = 2286;
        xfer2y = 261;
        closex = 2837;
        closey = 89;
        drop1x = 2131;
        drop1y = 265;
        drop2x = 2343;
        drop2y = 261;
        blackx = 3199;
        blacky = 85;
        invcolx = 2070;
        invcoly = 180;
        xferdropx = 2349;
        xferdropy = 263;
        dropcolorx = 2726;
        dropcolory = 249;
    }
    else if (screenWidth == 2560 && screenHeight == 1440) {
        text1x = 314;
        text1y = 262;
        text2x = 1698;
        text2y = 266;
        xfer1x = 479;
        xfer1y = 262;
        xfer2x = 1835;
        xfer2y = 260;
        closex = 2400;
        closey = 84;
        drop1x = 541;
        drop1y = 263;
        drop2x = 1907;
        drop2y = 265;
        blackx = 2316;
        blacky = 89;
        invcolx = 1631;
        invcoly = 182;
    }
    else if (screenWidth == 1920 && screenHeight == 1080) {
        text1x = 228;
        text1y = 197;
        text2x = 1272;
        text2y = 197;
        xfer1x = 357;
        xfer1y = 198;
        xfer2x = 1376;
        xfer2y = 192;
        closex = 1795;
        closey = 63;
        drop1x = 407;
        drop1y = 197;
        drop2x = 1426;
        drop2y = 197;
        blackx = 1738;
        blacky = 66;
        invcolx = 1222;
        invcoly = 135;
    }
    else if (screenWidth == 1920 && screenHeight == 1200) {
        text1x = 224;
        text1y = 258;
        text2x = 1267;
        text2y = 261;
        xfer1x = 356;
        xfer1y = 256;
        xfer2x = 1374;
        xfer2y = 258;
        closex = 1796;
        closey = 131;
        drop1x = 406;
        drop1y = 254;
        drop2x = 1422;
        drop2y = 258;
        blackx = 1718;
        blacky = 75;
        invcolx = 1222;
        invcoly = 195;
    }
    else if (screenWidth == 1536 && screenHeight == 864) {
        text1x = 183;
        text1y = 158;
        text2x = 1028;
        text2y = 162;
        xfer1x = 283;
        xfer1y = 158;
        xfer2x = 1103;
        xfer2y = 157;
        closex = 1439;
        closey = 50;
        drop1x = 323;
        drop1y = 156;
        drop2x = 1142;
        drop2y = 159;
        blackx = 1390;
        blacky = 55;
        invcolx = 978;
        invcoly = 108;
    }
}