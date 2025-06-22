#ifndef COORDINATES_H
#define COORDINATES_H

// Universal Inventory Extern Coords
extern int text1x, text1y, text2x, text2y;
extern int xfer1x, xfer1y, xfer2x, xfer2y;
extern int closex, closey, drop1x, drop1y;
extern int drop2x, drop2y, slot1x, slot1y;
extern int slot2x, slot2y, blak1x, blak1y;
extern int blak2x, blak2y, invcolx, invcoly;
extern int xferdropx, xferdropy, dropcolorx,
dropcolory, promptx, prompty, okayx, okayy;
// Auto Join Extern Coords
extern int servnx, servny,servtx, servty, servjx, servjy,
color1x, color1y, color2x, color2y, color3x, color3y,
click1X, click1Y, click2X, click2Y, click3X, click3Y,
click4X, click4Y, click5X, click5Y, click6X, click6Y,
fullfX, fullfY, startX, startY, servlcX, servlcY;
// ClubARK Extern Coords
extern int DDJC1X, DDJC1Y, DDJC2X, DDJC2Y, CAINVX, CAINVY,
CAJC1X, CAJC1Y, CAJC2X, CAJC2Y, CAJ1X, CAJ1Y, CAJ2X, CAJ2Y,
CAJ3X, CAJ3Y, InvMiX, InvMiY, CATM1X, CATM1Y, CATM2X, CATM2Y,
CATM3X, CATM3Y, DDAC1X, DDAC1Y, CDJ1X, CDJ1Y; 
// AFK XP Party Extern Coords
extern int PInvCX, PInvCY, EatinX, EatinY, DrinkX, DrinkY,
Buff1X, Buff1Y, Buff2X, Buff2Y, Buff3X, Buff3Y, Buff4X, Buff4Y,
PoopnX, PoopnY;
extern int tolerance;
// ClubARK Blob Extern Colors
extern BYTE rMin, rMax;
extern BYTE gMin, gMax;
extern BYTE bMin, bMax;

// Function to set the coordinates
void setCoordinates();
// Mouse click Function
void PerformMouseClick(int x, int y);
//Basic Key press
void PerformKeyPress(BYTE vkCode, int keyDownDelay, int keyUpDelay);
// Get color and add tolerances
COLORREF GetPixelColor(int x, int y);
bool IsColorWithinTolerance(COLORREF pixelColor, COLORREF targetColor, int tolerance);

#endif // COORDINATES_H