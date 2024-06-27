#ifndef COORDINATES_H
#define COORDINATES_H

#include <windows.h>

// Declare extern variables
extern int text1x, text1y, text2x, text2y, xfer1x, xfer1y, xfer2x, xfer2y, 
closex, closey, drop1x, drop1y, drop2x, drop2y, blackx, blacky, invcolx, invcoly, 
xferdropx, xferdropy, dropcolorx, dropcolory;

// Declare the function to set the coordinates
void setCoordinates();
void PerformMouseClick(int x, int y);

#endif // COORDINATES_H