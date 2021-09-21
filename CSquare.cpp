#include "CSquare.h"

CSquare::CSquare(void)
{
	// use the functions: SetNumberOfPoints, SetOnePointCoordinates, SetPolygonColor
	SetNumberOfPoints(4);

	SetOnePointCoordinates(0, 0, 0, 0);
	SetOnePointCoordinates(1, 1, 0, 0);
	SetOnePointCoordinates(2, 1, 1, 0);
	SetOnePointCoordinates(3, 0, 1, 0);

	SetPolygonColor(0, 0, 0);
}

