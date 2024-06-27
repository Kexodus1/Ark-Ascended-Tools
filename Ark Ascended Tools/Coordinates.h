#ifndef COORDINATES_H
#define COORDINATES_H

#include <windows.h>

// Declare extern variables
extern int text1x, text1y, text2x, text2y, xfer1x, xfer1y, xfer2x, xfer2y, 
closex, closey, drop1x, drop1y, drop2x, drop2y, blackx, blacky, invcolx, invcoly, 
xferdropx, xferdropy, dropcolorx, dropcolory, servnx, servny;
extern int color1x, color1y, color2x, color2y, color3x, color3y,
click1X, click1Y, click2X, click2Y, click3X, click3Y,
click4X, click4Y, click5X, click5Y, click6X, click6Y,
click7X, click7Y;
extern int click10X, click10Y, click20X, click20Y, click30X, click30Y,
click40X, click40Y, click50X, click50Y, click60X, click60Y;

// Declare the function to set the coordinates
void setCoordinates();
void PerformMouseClick(int x, int y);

#endif // COORDINATES_H