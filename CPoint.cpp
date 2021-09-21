#include <math.h>

#include "CPoint.h"
#include "glut.h"

const float PI = (float)3.1415926536;

#pragma region Constructors

CPoint::CPoint()
{
	_x_coordinate = 0;
	_y_coordinate = 0;
	_z_coordinate = 0;
	_red_component = 0;
	_green_component = 0;
	_blue_component = 0;
}

CPoint::CPoint(double x_coordinate, double y_coordinate, double z_coordinate)
{
	_x_coordinate = x_coordinate;
	_y_coordinate = y_coordinate;
	_z_coordinate = z_coordinate;
	_red_component = 0;
	_green_component = 0;
	_blue_component = 0;
}

CPoint::CPoint(double x_coordinate, double y_coordinate, double z_coordinate, double r_color, double g_color, double b_color)
{
	_x_coordinate = x_coordinate;
	_y_coordinate = y_coordinate;
	_z_coordinate = z_coordinate;
	_red_component = r_color;
	_green_component = g_color;
	_blue_component = b_color;
}
#pragma endregion

#pragma region Move point functions
void CPoint::MovePoint(Axis axis, double move_value)
{
	switch (axis)
	{
	case X_AXIS:
		MovePointX(move_value);
		break;
	case Y_AXIS:
		MovePointY(move_value);
		break;
	case Z_AXIS:
		MovePointZ(move_value);
		break;
	}
}

void CPoint::MovePointX(double x_move)
{
	_x_coordinate += x_move;
}

void CPoint::MovePointY(double y_move)
{
	_y_coordinate += y_move;
}

void CPoint::MovePointZ(double z_move)
{
	_z_coordinate += z_move;
}

void CPoint::MovePoint(double x_move, double y_move, double z_move)
{
	MovePointX(x_move);
	MovePointY(y_move);
	MovePointZ(z_move);
}

void CPoint::MovePoint(CPoint point_move)
{
	MovePointX(point_move.GetX());
	MovePointY(point_move.GetY());
	MovePointZ(point_move.GetZ());
}
#pragma endregion

#pragma region Set point location functions
void CPoint::SetPointCoordinate(Axis axis, double coordinate_value)
{
	switch (axis)
	{
	case X_AXIS:
		SetPointX(coordinate_value);
		break;
	case Y_AXIS:
		SetPointY(coordinate_value);
		break;
	case Z_AXIS:
		SetPointZ(coordinate_value);
		break;
	}
}

void CPoint::SetPointX(double x_coordinate)
{
	_x_coordinate = x_coordinate;
}

void CPoint::SetPointY(double y_coordinate)
{
	_y_coordinate = y_coordinate;
}

void CPoint::SetPointZ(double z_coordinate)
{
	_z_coordinate = z_coordinate;
}

void CPoint::SetPointCoordinates(double x_coordinate, double y_coordinate, double z_coordinate)
{
	SetPointX(x_coordinate);
	SetPointY(y_coordinate);
	SetPointZ(z_coordinate);
}
#pragma endregion

#pragma region Scale point functions
void CPoint::ScalePoint(Axis axis, double scale_ratio)
{
	switch (axis)
	{
	case X_AXIS:
		_x_coordinate *= scale_ratio;
		break;
	case Y_AXIS:
		_y_coordinate *= scale_ratio;
		break;
	case Z_AXIS:
		_z_coordinate *= scale_ratio;
		break;
	}
}

void CPoint::ScalePoint(double x_ratio, double y_ratio, double z_ratio)
{
	_x_coordinate *= x_ratio;
	_y_coordinate *= y_ratio;
	_z_coordinate *= z_ratio;
}
#pragma endregion

#pragma region Rotate point functions
void CPoint::RotatePoint(Axis axis, double rotate_value)
{
	switch (axis)
	{
	case X_AXIS:
		RotatePointX(rotate_value);
		break;
	case Y_AXIS:
		RotatePointY(rotate_value);
		break;
	case Z_AXIS:
		RotatePointZ(rotate_value);
		break;
	}
}

void CPoint::RotatePointX(double x_rotate)
{
	double angle_in_radians = x_rotate * PI / 180;
	double original_y_coordinate = _y_coordinate;
	double cos_value = cos(angle_in_radians);
	double sin_value = sin(angle_in_radians);
	_y_coordinate = original_y_coordinate*cos_value - _z_coordinate*sin_value;
	_z_coordinate = original_y_coordinate*sin_value + _z_coordinate*cos_value;
}

void CPoint::RotatePointY(double y_rotate)
{
	double angle_in_radians = y_rotate * PI/180;
	double original_x_coordinate = _x_coordinate;
	double cos_value = cos(angle_in_radians);
	double sin_value = sin(angle_in_radians);
	_x_coordinate = _z_coordinate*sin_value + original_x_coordinate*cos_value;
	_z_coordinate = _z_coordinate*cos_value - original_x_coordinate*sin_value;
}

void CPoint::RotatePointZ(double z_rotate)
{
	double angle_in_radians = z_rotate * PI/180;
	double original_x_coordinate = _x_coordinate;
	double cos_value = cos(angle_in_radians);
	double sin_value = sin(angle_in_radians);
	_x_coordinate = original_x_coordinate*cos_value - _y_coordinate*sin_value;
	_y_coordinate = original_x_coordinate*sin_value + _y_coordinate*cos_value;
}
#pragma endregion

#pragma region Set point color functions
void CPoint::SetPointColor(Color color, double color_value)
{
	switch (color)
	{
	case RED_COMPONENT:
		SetPointRed(color_value);
		break;
	case GREEN_COMPONENT:
		SetPointGreen(color_value);
		break;
	case BLUE_COMPONENT:
		SetPointBlue(color_value);
		break;
	}
}

void CPoint::SetPointRed(double r_color)
{
	_red_component = r_color;
}

void CPoint::SetPointGreen(double g_color)
{
	_green_component = g_color;
}

void CPoint::SetPointBlue(double b_color)
{
	_blue_component = b_color;
}

void CPoint::SetPointColor(double r_color, double g_color, double b_color)
{
	SetPointRed(r_color);
	SetPointGreen(g_color);
	SetPointBlue(b_color);
}
#pragma endregion

#pragma region Get functions
CPoint CPoint::ClonePoint()
{
	CPoint new_point(GetX(), GetY(), GetZ(), GetRed(), GetGreen(), GetBlue());
	return new_point;
}

double CPoint::GetCoordinate(Axis axis)
{
	switch (axis)
	{
	case X_AXIS:
		return GetX();
		break;
	case Y_AXIS:
		return GetY();
		break;
	case Z_AXIS:
		return GetZ();
		break;
	default:
		return 0;
	}
}

double CPoint::GetColor(Color color)
{
	switch (color)
	{
	case RED_COMPONENT:
		return GetRed();
		break;
	case GREEN_COMPONENT:
		return GetGreen();
		break;
	case BLUE_COMPONENT:
		return GetBlue();
		break;
	default:
		return -1;
	}
}

double CPoint::GetX()
{
	return _x_coordinate;
}

double CPoint::GetY()
{
	return _y_coordinate;
}

double CPoint::GetZ()
{
	return _z_coordinate;
}

double CPoint::GetRed()
{
	return _red_component;
}

double CPoint::GetGreen()
{
	return _green_component;
}

double CPoint::GetBlue()
{
	return _blue_component;
}
#pragma endregion

#pragma region Draw function
void CPoint::DrawPoint()
{
	glColor3f(_red_component, _green_component, _blue_component);
	glVertex3f(_x_coordinate, _y_coordinate, _z_coordinate);
}
#pragma endregion