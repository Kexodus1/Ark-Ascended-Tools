#ifndef COORDINATES_H
#define COORDINATES_H

#include <windows.h>

// Declare extern variables
extern int text1x, text1y, text2x, text2y, xfer1x, xfer1y, xfer2x, xfer2y, 
closex, closey, drop1x, drop1y, drop2x, drop2y, blackx, blacky, invcolx, invcoly, 
xferdropx, xferdropy, dropcolorx, dropcolory, servnx, servny, promptx, prompty, 
okayx, okayy, servtx, servty, servjx, servjy;
extern int color1x, color1y, color2x, color2y, color3x, color3y,
click1X, click1Y, click2X, click2Y, click3X, click3Y,
click4X, click4Y, click5X, click5Y, click6X, click6Y,
fullfX, fullfY, startX, startY;
extern int DDJC1X, DDJC1Y, DDJC2X, DDJC2Y, CAJC1X, CAJC1Y,
CAJC2X, CAJC2Y, CAJ1X, CAJ1Y, CAJ2X, CAJ2Y, CAJ3X, CAJ3Y;

// Declare the BYTE variables
extern BYTE rMin, rMax;
extern BYTE gMin, gMax;
extern BYTE bMin, bMax;

// Declare the function to set the coordinates
void setCoordinates();
void PerformMouseClick(int x, int y);

#endif // COORDINATES_H