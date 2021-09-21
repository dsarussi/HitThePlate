#include <math.h>
#include "CBall.h"

const double pi = (double)3.1415926536;

CBall::CBall(void)
{
	int num_of_fi_values = 10;
	int num_of_theta_values = 30;

	SetBallNumOfElements(num_of_fi_values, num_of_theta_values);	
}

CBall::CBall(int num_of_fi_values, int num_of_theta_values)
{
	SetBallNumOfElements(num_of_fi_values, num_of_theta_values);
}

void CBall::SetBallNumOfElements(int num_of_fi_values, int num_of_theta_values)
{
	_num_of_fi_values = num_of_fi_values;
	_num_of_theta_values = num_of_theta_values;
	bool divide_by_area = false;
	int total_num_of_polygons = num_of_fi_values*num_of_theta_values;

	SetNumberOfPolygons(total_num_of_polygons);

	double x, y, z;

	double delta_fi = pi/num_of_fi_values;
	double delta_theta = 2*pi/num_of_theta_values;
	double current_fi;
	double next_fi = 0;

	for(int i = 0; i < num_of_fi_values; i++)
	{
		double small_fi;
		double big_fi;

		if (divide_by_area == false)
		{
			small_fi = i*delta_fi;
			big_fi = (i+1)*delta_fi;
		}
		else
		{
			current_fi = next_fi;
			next_fi = acos(cos(current_fi)-2.0/num_of_fi_values);

			small_fi = current_fi;
			big_fi = next_fi;
		}

		for(int j = 0;j < num_of_theta_values;j++)
		{
			int polygon_num = i*num_of_theta_values+j;
			CPolygon current_polygon(4);

			double small_theta = j*delta_theta;
			double big_theta = (j+1)*delta_theta;

			// first point:
			x = sin(small_fi)*cos(small_theta);
			y = sin(small_fi)*sin(small_theta);
			z = cos(small_fi);
			current_polygon.SetOnePointCoordinates(0, x, y, z);

			// second point:
			x = sin(big_fi)*cos(small_theta);
			y = sin(big_fi)*sin(small_theta);
			z = cos(big_fi);
			current_polygon.SetOnePointCoordinates(1, x, y, z);

			// third point:
			x = sin(big_fi)*cos(big_theta);
			y = sin(big_fi)*sin(big_theta);
			z = cos(big_fi);
			current_polygon.SetOnePointCoordinates(2, x, y, z);

			// fourth point:
			x = sin(small_fi)*cos(big_theta);
			y = sin(small_fi)*sin(big_theta);
			z = cos(small_fi);
			current_polygon.SetOnePointCoordinates(3, x, y, z);

			SetOnePolygon(polygon_num, current_polygon);
		} 
	}

	SetBallColors(0,1,0,1,0,1);
}

void CBall::SetBallColors(double red_component_min, double red_component_max, double green_component_min, double green_component_max, double blue_component_min, double blue_component_max)
{
	double red_component_diff = red_component_max - red_component_min;
	double green_component_diff = green_component_max - green_component_min;
	double blue_component_diff = blue_component_max - blue_component_min;
	for(int i = 0; i < _num_of_fi_values; i++)
		for(int j = 0;j < _num_of_theta_values;j++)
		{
			int polygon_num = i*_num_of_theta_values+j;
			double red = GetNewColorComponent(i,j,1,1)*red_component_diff + red_component_min;
			double green = GetNewColorComponent(i,j,1,2)*green_component_diff + green_component_min;
			double blue = GetNewColorComponent(i,j,3,2)*blue_component_diff + blue_component_min;

			SetOnePolygonColor(polygon_num, red, green, blue);
		} 
}

double CBall::GetNewColorComponent(int fi_index, int theta_index, int fi_weight, int theta_weight)
{
	double fi_val = fi_index/(1.0*_num_of_fi_values);
	double theta_val = 0.5*(1+sin(theta_index/(1.0*_num_of_theta_values)*2*pi));
	double new_color = (fi_val*fi_weight + theta_val*theta_weight)/(fi_weight + theta_weight);
	return new_color;
}
