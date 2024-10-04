#include "pch.h"
#include "Coordinates.h"

// Extern variables
// inventory color #BCF4FF RGB(188, 244, 255).      
int text1x = 0, text1y = 0, text2x = 0, text2y = 0;
int xfer1x = 0, xfer1y = 0, xfer2x = 0, xfer2y = 0;
int closex = 0, closey = 0, drop1x = 0, drop1y = 0;
int drop2x = 0, drop2y = 0, blackx = 0, blacky = 0;
int invcolx = 0, invcoly = 0, xferdropx = 0, xferdropy = 0, promptx = 0, prompty = 0;
int dropcolorx = 0, dropcolory = 0, servnx = 0, servny = 0, okayx = 0, okayy = 0;
int servtx = 0, servty = 0, servjx = 0, servjy = 0;
int color1x = 0, color1y = 0, color2x = 0, color2y = 0, color3x = 0, color3y = 0,
click1X = 0, click1Y = 0, click2X = 0, click2Y = 0, click3X = 0, click3Y = 0,
click4X = 0, click4Y = 0, click5X = 0, click5Y = 0, click6X = 0, click6Y = 0,
fullfX = 0, fullfY = 0, startX = 0, startY = 0, servlcX = 0, servlcY = 0;
int DDJC1X = 0, DDJC1Y = 0, DDJC2X = 0, DDJC2Y = 0, CAJC1X = 0, CAJC1Y = 0, 
CAJC2X = 0, CAJC2Y = 0, CAJ1X = 0, CAJ1Y = 0, CAJ2X = 0, CAJ2Y = 0, CAJ3X = 0, CAJ3Y = 0,
InvMiX = 0, InvMiY = 0;
int PLInvX = 0, PLInvY = 0, PInvCX = 0, PInvCY = 0, PslotX = 0, PslotY = 0;
int tolerance = 15;

// Basic Mouse click
void PerformMouseClick(int x, int y) {
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

// Color Tolerances to allow variance
bool IsColorWithinTolerance(COLORREF pixelColor, COLORREF targetColor, int tolerance) {
    int targetR = GetRValue(targetColor);
    int targetG = GetGValue(targetColor);
    int targetB = GetBValue(targetColor);

    int pixelR = GetRValue(pixelColor);
    int pixelG = GetGValue(pixelColor);
    int pixelB = GetBValue(pixelColor);

    return (abs(pixelR - targetR) <= tolerance &&
        abs(pixelG - targetG) <= tolerance &&
        abs(pixelB - targetB) <= tolerance);
}

// Function to get the color of a pixel at specific coordinates
COLORREF GetPixelColor(int x, int y) {
    HDC hdcScreen = GetDC(NULL); // Get the device context of the screen
    COLORREF color = GetPixel(hdcScreen, x, y); // Get the color at the pixel
    ReleaseDC(NULL, hdcScreen); // Release the device context
    return color;
}

// Define the range for Club Ark blob colors
BYTE rMin = 0, rMax = 255;
BYTE gMin = 0, gMax = 255;
BYTE bMin = 0, bMax = 255;

void setCoordinates() {
    // Get the current screen resolution
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Check the current screen resolution and set the coordinates accordingly
    if (screenWidth == 3840 && screenHeight == 2160) {
        // 3840x2160
        // Inventory Coords
        text1x = 467;       text1y = 397;       // Player Inventory Text Box
        text2x = 2532;      text2y = 394;       // Dino Inventory Text Box
        xfer1x = 717;       xfer1y = 395;       // Player Xfer All Button
        xfer2x = 2753;      xfer2y = 395;       // Dino Xfer All Button
        closex = 3597;      closey = 133;       // Close (x) Button top right Inv
        drop1x = 810;       drop1y = 397;       // Player Drop All Button
        drop2x = 2852;      drop2y = 397;       // Dino Drop All Button
        blackx = 3469;      blacky = 141;       // Black Weight Box top right
        invcolx = 2542;     invcoly = 269;      // Inventory open color check
        xferdropx = 2855;   xferdropy = 393;    // Air Drop Xfer All Button
        dropcolorx = 3329;  dropcolory = 275;   // Air Drop color check
        promptx = 1880;     prompty = 730;      // Menu Transitions color check
        okayx = 1700;       okayy = 1460;       // Menu Transitions okay button
        // Auto join Server Coords
        color1x = 1796;     color1y = 840;      // Server full popup color check (M)
        color2x = 950;      color2y = 1864;     // Join server popup color check
        color3x = 2022;     color3y = 696;      // Connection Failed color check (F)
        servlcX = 1519;     servlcY = 375;      // White server list color check (A)
        servnx = 3229;      servny = 383;       // Server Number text box
        servtx = 1747;      servty = 654;       // Top Server click \ color check
        servjx = 3423;      servjy = 1888;      // Bottom right Join button click
        click3X = 1050;     click3Y = 1864;     // Join server popup box
        click4X = 2123;     click4Y = 1457;     // Cancel on Connection failed screen
        click5X = 337;      click5Y = 1763;     // Back button on server list
        click6X = 1050;     click6Y = 1108;     // Join server list button
        fullfX = 1906;      fullfY = 1461;      // Server Full Fail popup accept
        startX = 1915;      startY = 1717;      // Ark Main Menu Start Button
        // AFK Club ARK Coords
        DDJC1X = 3107;      DDJC1Y = 630;       // Alpha Color detection
        DDJC2X = 2586;      DDJC2Y = 1030;      // Color location of blobs
        CAJC1X = 2231;      CAJC1Y = 359;       // Color of White Mission Board Bar
        InvMiX = 1861;      InvMiY = 150;       // Inventory Mission Click
        CAJC2X = 3086;      CAJC2Y = 292;       // Color of Yellow Join
        CAJ1X = 1076;       CAJ1Y = 591;        // MiniGames Click 
        CAJ2X = 1181;       CAJ2Y = 1194;       // Duck Duck Jump Alpha Click
        CAJ3X = 3257;       CAJ3Y = 295;        // Join Game Click
        rMin = 0;           rMax = 255;         // Duck Duck Jump red blob color to jump
        gMin = 110;         gMax = 255;         // Duck Duck Jump green blob color to jump
        bMin = 90;          bMax = 255;         // Duck Duck Jump blue blob color to jump
    }
    else if (screenWidth == 3840 && screenHeight == 1080) {
        // 3840x1080
        // Inventory Coords
        text1x = 1200;      text1y = 197;       // Player Inventory Text Box
        text2x = 2223;      text2y = 195;       // Dino Inventory Text Box
        xfer1x = 1315;      xfer1y = 196;       // Player Xfer All Button
        xfer2x = 2339;      xfer2y = 196;       // Dino Xfer All Button
        closex = 2758;      closey = 68;        // Close (x) Button top right Inv
        drop1x = 1367;      drop1y = 198;       // Player Drop All Button
        drop2x = 2386;      drop2y = 195;       // Dino Drop All Button
        blackx = 3658;      blacky = 67;        // Black Weight Box top right
        invcolx = 2231;     invcoly = 135;      // Inventory open color check
        xferdropx = 2388;   xferdropy = 197;    // Air Drop Xfer All Button
        dropcolorx = 2650;  dropcolory = 136;   // Air Drop color check
        promptx = 1899;     prompty = 354;      // Menu Transitions color check
        okayx = 1813;       okayy = 728;        // Menu Transitions okay button
        // Auto join Server Coords
        color1x = 1857;     color1y = 421;      // Server full popup color check (M)
        color2x = 1492;     color2y = 932;      // Join server popup color check
        color3x = 1970;     color3y = 348;      // Connection Failed color check (F)
        servlcX = 1721;     servlcY = 187;      // White server list color check (A)
        servnx = 2616;      servny = 191;       // Server Number text box
        servtx = 1862;      servty = 327;       // Top Server click \ color check
        servjx = 2606;      servjy = 944;       // Bottom right Join button click
        click3X = 1492;     click3Y = 932;      // Join server popup box
        click4X = 2025;     click4Y = 728;      // Cancel on Connection failed screen
        click5X = 1126;     click5Y = 881;      // Back button on server list
        click6X = 1485;     click6Y = 552;      // Join server list button
        fullfX = 1911;      fullfY = 728;       // Server Full Fail popup accept
        startX = 1909;      startY = 855;       // Ark Main Menu Start Button
        // AFK Club ARK Coords
        DDJC1X = 3481;      DDJC1Y = 315;       // Alpha Color detection
        DDJC2X = 2506;      DDJC2Y = 492;       // Color location of blobs
        CAJC1X = 2073;      CAJC1Y = 179;       // Color of White Mission Board Bar
        InvMiX = 1894;      InvMiY = 73;        // Inventory Mission Click
        CAJC2X = 2502;      CAJC2Y = 143;       // Color of Yellow Join
        CAJ1X = 1401;       CAJ1Y = 293;        // MiniGames Click 
        CAJ2X = 1509;       CAJ2Y = 593;        // Duck Duck Jump Alpha Click
        CAJ3X = 2589;       CAJ3Y = 145;        // Join Game Click
        rMin = 0;           rMax = 255;         // Duck Duck Jump red blob color to jump
        gMin = 110;         gMax = 255;         // Duck Duck Jump green blob color to jump
        bMin = 70;          bMax = 255;         // Duck Duck Jump blue blob color to jump
    }
    else if (screenWidth == 3440 && screenHeight == 1440) {
        // 3440x1440
        // Inventory Coords
        text1x = 773;       text1y = 262;       // Player Inventory Text Box
        text2x = 2131;      text2y = 265;       // Dino Inventory Text Box
        xfer1x = 920;       xfer1y = 263;       // Player Xfer All Button
        xfer2x = 2286;      xfer2y = 261;       // Dino Xfer All Button
        closex = 2837;      closey = 89;        // Close (x) Button top right Inv
        drop1x = 2131;      drop1y = 265;       // Player Drop All Button
        drop2x = 2343;      drop2y = 261;       // Dino Drop All Button
        blackx = 3199;      blacky = 85;        // Black Weight Box top right
        invcolx = 2070;     invcoly = 180;      // Inventory open color check
        xferdropx = 2349;   xferdropy = 263;    // Air Drop Xfer All Button
        dropcolorx = 2659;  dropcolory = 182;   // Air Drop color check
        promptx = 1603;     prompty = 487;      // Menu Transitions color check
        okayx = 1565;       okayy = 971;        // Menu Transitions okay button
        // XP Party
        PLInvX = 1460;      PLInvY = 226;       // Player Inventory white bar under You
        PInvCX = 1318;      PInvCY = 181;       // Player Inventory crafting button
        PslotX = 732;       PslotY = 374;       // Player Inventory 1st crafting slot
        // Auto join Server Coords
        color1x = 1638;     color1y = 558;      // Server full popup color check (M)
        color2x = 1072;     color2y = 1246;     // Join server popup color check
        color3x = 1786;     color3y = 463;      // Connection Failed color check (F)
        servlcX = 1453;     servlcY = 248;      // White server list color check (A)
        servnx = 2608;      servny = 261;       // Server Number text box
        servtx = 1633;      servty = 435;       // Top Server click \ color check
        servjx = 2725;      servjy = 1261;      // Bottom right Join button click
        click3X = 1082;     click3Y = 1245;     // Join server popup box
        click4X = 1866;     click4Y = 971;      // Cancel on Connection failed screen
        click5X = 664;      click5Y = 1173;     // Back button on server list
        click6X = 1142;     click6Y = 756;      // Join server list button
        fullfX = 1709;      fullfY = 973;       // Server Full Fail popup accept
        startX = 1707;      startY = 1140;      // Ark Main Menu Start Button
        // AFK Club ARK Coords
        DDJC1X = 2953;      DDJC1Y = 421;       // Alpha Color detection
        DDJC2X = 2375;      DDJC2Y = 676;       // Color location of blobs
        CAJC1X = 1786;      CAJC1Y = 238;       // Color of White Mission Board Bar
        InvMiX = 1683;      InvMiY = 103;       // Inventory Mission Click
        CAJC2X = 2509;      CAJC2Y = 168;       // Color of Yellow Join
        CAJ1X = 1019;       CAJ1Y = 392;        // MiniGames Click 
        CAJ2X = 1126;       CAJ2Y = 788;        // Duck Duck Jump Alpha Click
        CAJ3X = 2614;       CAJ3Y = 197;        // Join Game Click
        rMin = 0;           rMax = 255;         // Duck Duck Jump red blob color to jump
        gMin = 60;          gMax = 255;         // Duck Duck Jump green blob color to jump
        bMin = 105;         bMax = 255;         // Duck Duck Jump blue blob color to jump
    }
    else if (screenWidth == 2560 && screenHeight == 1440) {
        // 2560x1440
        // Inventory Coords
        text1x = 314;       text1y = 262;       // Player Inventory Text Box
        text2x = 1698;      text2y = 266;       // Dino Inventory Text Box
        xfer1x = 479;       xfer1y = 262;       // Player Xfer All Button
        xfer2x = 1835;      xfer2y = 260;       // Dino Xfer All Button
        closex = 2400;      closey = 84;        // Close (x) Button top right Inv
        drop1x = 541;       drop1y = 263;       // Player Drop All Button
        drop2x = 1907;      drop2y = 265;       // Dino Drop All Button
        blackx = 2316;      blacky = 89;        // Black Weight Box top right
        invcolx = 1631;     invcoly = 182;      // Inventory open color check
        xferdropx = 1907;   xferdropy = 266;    // Air Drop Xfer All Button
        dropcolorx = 2217;  dropcolory = 184;   // Air Drop color check
        promptx = 1162;     prompty = 487;      // Menu Transitions color check
        okayx = 1134;       okayy = 968;        // Menu Transitions okay button
        // Auto join Server Coords
        color1x = 1198;     color1y = 561;      // Server full popup color check (M)
        color2x = 632;      color2y = 1241;     // Join server popup color check
        color3x = 1345;     color3y = 463;      // Connection Failed color check (F)
        servlcX = 1014;     servlcY = 245;      // White server list color check (A)
        servnx = 2139;      servny = 262;       // Server Number text box
        servtx = 1197;      servty = 438;       // Top Server click \ color check
        servjx = 2269;      servjy = 1258;      // Bottom right Join button click
        click3X = 619;      click3Y = 1247;     // Join server popup box
        click4X = 1398;     click4Y = 973;      // Cancel on Connection failed screen
        click5X = 222;      click5Y = 1172;     // Back button on server list
        click6X = 713;      click6Y = 790;      // Join server list button
        fullfX = 1268;      fullfY = 969;       // Server Full Fail popup accept
        startX = 1265;      startY = 1144;      // Ark Main Menu Start Button
        // AFK Club ARK Coords
        DDJC1X = 2073;      DDJC1Y = 420;       // Alpha Color detection
        DDJC2X = 1754;      DDJC2Y = 676;       // Color location of blobs
        CAJC1X = 1345;      CAJC1Y = 238;       // Color of White Mission Board Bar
        InvMiX = 1243;      InvMiY = 103;       // Inventory Mission Click
        CAJC2X = 2061;      CAJC2Y = 192;       // Color of Yellow Join
        CAJ1X = 665;        CAJ1Y = 393;        // MiniGames Click 
        CAJ2X = 725;        CAJ2Y = 788;        // Duck Duck Jump Alpha Click
        CAJ3X = 2174;       CAJ3Y = 197;        // Join Game Click
        rMin = 0;           rMax = 255;         // Duck Duck Jump red blob color to jump
        gMin = 60;          gMax = 255;         // Duck Duck Jump green blob color to jump
        bMin = 105;         bMax = 255;         // Duck Duck Jump blue blob color to jump
    }
    else if (screenWidth == 1920 && screenHeight == 1080) {
        // 1920x1080
        // Inventory Coords
        text1x = 228;       text1y = 197;       // Player Inventory Text Box
        text2x = 1272;      text2y = 197;       // Dino Inventory Text Box
        xfer1x = 357;       xfer1y = 198;       // Player Xfer All Button
        xfer2x = 1376;      xfer2y = 192;       // Dino Xfer All Button
        closex = 1795;      closey = 63;        // Close (x) Button top right Inv
        drop1x = 407;       drop1y = 197;       // Player Drop All Button
        drop2x = 1426;      drop2y = 197;       // Dino Drop All Button
        blackx = 1738;      blacky = 66;        // Black Weight Box top right
        invcolx = 1222;     invcoly = 135;      // Inventory open color check
        xferdropx = 1425;   xferdropy = 197;    // Air Drop Xfer All Button
        dropcolorx = 1665;  dropcolory = 136;   // Air Drop color check
        promptx = 869;      prompty = 365;      // Menu Transitions color check
        okayx = 856;        okayy = 726;        // Menu Transitions okay button
        // Auto join Server Coords
        color1x = 896;      color1y = 420;      // Server full popup color check (M)
        color2x = 476;      color2y = 932;      // Join server popup color check
        color3x = 1011;     color3y = 348;      // Connection Failed color check (F)
        servlcX = 762;      servlcY = 186;      // White server list color check (A)
        servnx = 1608;      servny = 194;       // Server Number text box
        servtx = 730;       servty = 312;       // Top Server click \ color check
        servjx = 1709;      servjy = 943;       // Bottom right Join button click
        click3X = 469;      click3Y = 933;      // Join server popup box
        click4X = 1070;     click4Y = 729;      // Cancel on Connection failed screen
        click5X = 169;      click5Y = 877;      // Back button on server list
        click6X = 529;      click6Y = 582;      // Join server list button
        fullfX = 954;       fullfY = 728;       // Server Full Fail popup accept
        startX = 954;       startY = 859;       // Ark Main Menu Start Button
        // AFK Club ARK Coords
        DDJC1X = 1561;      DDJC1Y = 314;       // Alpha Color detection
        DDJC2X = 1325;      DDJC2Y = 515;       // Color location of blobs
        CAJC1X = 1041;      CAJC1Y = 178;       // Color of White Mission Board Bar
        InvMiX = 931;       InvMiY = 77;        // Inventory Mission Click
        CAJC2X = 1542;      CAJC2Y = 144;       // Color of Yellow Join
        CAJ1X = 516;        CAJ1Y = 294;        // MiniGames Click 
        CAJ2X = 547;        CAJ2Y = 593;        // Duck Duck Jump Alpha Click
        CAJ3X = 1629;       CAJ3Y = 147;        // Join Game Click
        rMin = 0;           rMax = 255;         // Duck Duck Jump red blob color to jump
        gMin = 150;         gMax = 255;         // Duck Duck Jump green blob color to jump
        bMin = 95;          bMax = 255;         // Duck Duck Jump blue blob color to jump
    }
    else if (screenWidth == 1920 && screenHeight == 1200) {
        // 1920x1200
        // Inventory Coords
        text1x = 224;       text1y = 258;       // Player Inventory Text Box
        text2x = 1267;      text2y = 261;       // Dino Inventory Text Box
        xfer1x = 356;       xfer1y = 256;       // Player Xfer All Button
        xfer2x = 1374;      xfer2y = 258;       // Dino Xfer All Button
        closex = 1796;      closey = 131;       // Close (x) Button top right Inv
        drop1x = 406;       drop1y = 254;       // Player Drop All Button
        drop2x = 1422;      drop2y = 258;       // Dino Drop All Button
        blackx = 1718;      blacky = 75;        // Black Weight Box top right
        invcolx = 1222;     invcoly = 195;      // Inventory open color check
        xferdropx = 1425;   xferdropy = 258;    // Air Drop Xfer All Button
        dropcolorx = 1665;  dropcolory = 196;   // Air Drop color check
        promptx = 861;      prompty = 405;      // Menu Transitions color check
        okayx = 838;        okayy = 813;        // Menu Transitions okay button
        // Auto join Server Coords
        color1x = 891;      color1y = 465;      // Server full popup color check (M)
        color2x = 421;      color2y = 1031;     // Join server popup color check
        color3x = 1014;     color3y = 386;      // Connection Failed color check (F)
        servlcX = 760;      servlcY = 245;      // White server list color check (A)
        servnx = 1602;      servny = 257;       // Server Number text box
        servtx = 897;       servty = 386;       // Top Server click \ color check
        servjx = 1718;      servjy = 1005;      // Bottom right Join button click
        click3X = 478;      click3Y = 1034;     // Join server popup box
        click4X = 1069;     click4Y = 806;      // Cancel on Connection failed screen
        click5X = 170;      click5Y = 937;      // Back button on server list
        click6X = 524;      click6Y = 647;      // Join server list button
        fullfX =  953;      fullfY = 812;       // Server Full Fail popup accept
        startX = 948;       startY = 922;       // Ark Main Menu Start Button
    }
    else if (screenWidth == 1536 && screenHeight == 864) {
        // 1536x864
        // Inventory Coords
        text1x = 183;       text1y = 158;       // Player Inventory Text Box
        text2x = 1028;      text2y = 162;       // Dino Inventory Text Box
        xfer1x = 283;       xfer1y = 158;       // Player Xfer All Button
        xfer2x = 1103;      xfer2y = 157;       // Dino Xfer All Button
        closex = 1439;      closey = 50;        // Close (x) Button top right Inv
        drop1x = 323;       drop1y = 156;       // Player Drop All Button
        drop2x = 1142;      drop2y = 159;       // Dino Drop All Button
        blackx = 1390;      blacky = 55;        // Black Weight Box top right
        invcolx = 978;      invcoly = 108;      // Inventory open color check
        xferdropx = 1141;   xferdropy = 157;    // Air Drop Xfer All Button
        dropcolorx = 1333;  dropcolory = 109;   // Air Drop color check
        promptx = 696;      prompty = 292;      // Menu Transitions color check
        okayx = 680;        okayy = 580;        // Menu Transitions okay button
        // Auto join Server Coords
        color1x = 717;      color1y = 336;      // Server full popup color check (M)
        color2x = 387;      color2y = 744;      // Join server popup color check
        color3x = 808;      color3y = 279;      // Connection Failed color check (F)
        servlcX = 603;      servlcY = 146;      // White server list color check (A)
        servnx = 1279;      servny = 156;       // Server Number text box
        servtx = 714;       servty = 262;       // Top Server click \ color check
        servjx = 1362;      servjy = 754;       // Bottom right Join button click
        click3X = 425;      click3Y = 745;      // Join server popup box
        click4X = 857;      click4Y = 582;      // Cancel on Connection failed screen
        click5X = 139;      click5Y = 703;      // Back button on server list
        click6X = 421;      click6Y = 454;      // Join server list button
        fullfX = 761;       fullfY = 582;       // Server Full Fail popup accept
        startX = 759;       startY = 688;       // Ark Main Menu Start Button
    }
}