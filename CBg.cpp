#include "CBg.h"

CBg::CBg(void)
{
	SetNumberOfPoints(4);
	SetOnePointCoordinates(1, 20, 20, -90);
	SetOnePointCoordinates(2, -20, 20, -90);
	SetOnePointCoordinates(3, -20, -20, -90);
	SetOnePointCoordinates(0, 20, -20, -90);
	
	SetOnePointColor(0,0.3,0.4,0.5);
	SetOnePointColor(1,0.3,0.7,0.7);
	SetOnePointColor(2,0.3,0.7,0.7);
	SetOnePointColor(3,0.3,0.4,0.5);
}