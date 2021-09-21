#pragma once
#include "cpolygon.h"

class CCircle :
	public CPolygon
{
public:
	CCircle(void);
	CCircle(int number_of_points);
	CCircle(int number_of_points, double radius);
	void CreateCircle(int number_of_points, double radius);
};
