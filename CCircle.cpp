#include "CCircle.h"
#include <math.h>
CCircle::CCircle(void)
{
	CreateCircle(30,0.30);

}


CCircle::CCircle(int number_of_points)
{
}

CCircle::CCircle(int number_of_points, double radius)
{
}

void CCircle::CreateCircle(int number_of_points, double radius)
{
	SetNumberOfPoints(number_of_points);
	double alpha = 2*3.14/number_of_points;
	for(int i=0; i<number_of_points; i++)
	{
		double x_i = radius*cos(alpha*i);
		double y_i = radius*sin(alpha*i);
		double z_i = 0;
		SetOnePointCoordinates(i,x_i,y_i,z_i);
	}
		SetPolygonColor(80/128.0,80/128.0,80/128.0);
}
