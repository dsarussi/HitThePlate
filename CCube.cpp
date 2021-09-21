#include "CCube.h"
#include "CSquare.h"

CCube::CCube(void)
{
	SetNumberOfPolygons(6);

	CSquare square_in_cube;
	
	// first polygon
	square_in_cube.MovePolygonCenter(0.5, 0.5, 1);
	square_in_cube.SetPolygonColor(0, 0.3, 0.7);
	SetOnePolygon(0, square_in_cube);

	// second polygon
	square_in_cube.RotatePolygon(Y_AXIS, 90);
	square_in_cube.MovePolygonCenter(1, 0.5, 0.5);
	square_in_cube.SetPolygonColor(0.4, 0, 0.7);
	SetOnePolygon(1, square_in_cube);

		// third polygon
	square_in_cube.RotatePolygon(Y_AXIS, 90);
	square_in_cube.MovePolygonCenter(0.5, 0.5, 0);
	square_in_cube.SetPolygonColor(0.2, 0, 0.8);
	SetOnePolygon(2, square_in_cube);

	// fourth polygon
	square_in_cube.RotatePolygon(Y_AXIS, 90);
	square_in_cube.MovePolygonCenter(0, 0.5, 0.5);
	square_in_cube.SetPolygonColor(0.4, 0.5, 0.7);
	SetOnePolygon(3, square_in_cube);

	// fifth polygon
	square_in_cube.RotatePolygon(Z_AXIS, 90);
	square_in_cube.MovePolygonCenter(0.5, 0, 0.5);
	square_in_cube.SetPolygonColor(0.3, 0, 0.9);
	SetOnePolygon(4, square_in_cube);

	// sixth polygon
	square_in_cube.RotatePolygon(Z_AXIS, 180);
	square_in_cube.MovePolygonCenter(0.5, 1, 0.5);
	square_in_cube.SetPolygonColor(1, 0.4, 0.3);
	SetOnePolygon(5, square_in_cube);
}

