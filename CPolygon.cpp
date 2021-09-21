#include <stdlib.h>
#include "glut.h"

#include "CPolygon.h"

#pragma region CONSTRUCTORs & DESTRUCTOR
CPolygon::CPolygon()
{
	_num_of_points = 2;
	_points_array = new CPoint[_num_of_points];
}

CPolygon::CPolygon(int num_of_points)
{
	_num_of_points = num_of_points;
	_points_array = new CPoint[_num_of_points];
}

CPolygon::CPolygon(const CPolygon& polygon)
{
	_num_of_points = polygon._num_of_points;
	_points_array = new CPoint[_num_of_points];
	for (int i = 0; i < _num_of_points; i++)
		_points_array[i] = polygon._points_array[i].ClonePoint();
}

CPolygon::~CPolygon()
{
	delete[] _points_array;
}
#pragma endregion

#pragma region Setting CPolygon properties
void CPolygon::SetNumberOfPoints(int num_of_points)
{
	_num_of_points = num_of_points;
	delete[] _points_array;
	_points_array = new CPoint[_num_of_points];
}

void CPolygon::SetPolygonColor(Color color_component, double color_value)
{
	for (int i = 0; i < _num_of_points; i++)
		_points_array[i].SetPointColor(color_component, color_value);
}

void CPolygon::SetPolygonColor(double red_component, double green_component, double blue_component)
{
	for (int i = 0; i < _num_of_points; i++)
		_points_array[i].SetPointColor(red_component, green_component, blue_component);
}

void CPolygon::DuplicatePolygon(CPolygon polygon)
{
	SetNumberOfPoints(polygon.GetNumberOfPoints());
	for (int i = 0; i < _num_of_points; i++)
		SetOnePoint(i, polygon.GetPoint(i));
}
#pragma endregion

#pragma region Setting one point properties
void CPolygon::SetOnePoint(int point_index, CPoint point)
{
	_points_array[point_index] = point.ClonePoint();
}

void CPolygon::SetOnePointCoordinates(int point_index, double x_coordinate, double y_coordinate, double z_coordinate)
{
	_points_array[point_index].SetPointCoordinates(x_coordinate, y_coordinate, z_coordinate);
}

void CPolygon::SetOnePointColor(int point_index, Color color_component, double color_value)
{
	_points_array[point_index].SetPointColor(color_component, color_value);
}

void CPolygon::SetOnePointColor(int point_index, double red_component, double green_component, double blue_component)
{
	_points_array[point_index].SetPointColor(red_component, green_component, blue_component);
}
#pragma endregion

#pragma region Move polygon functions
void CPolygon::MovePolygon(Axis axis, double move_value)
{
	for (int i = 0; i < _num_of_points; i++)
		_points_array[i].MovePoint(axis, move_value);
}

void CPolygon::MovePolygon(double x_move, double y_move, double z_move)
{
	for (int i = 0; i < _num_of_points; i++)
		_points_array[i].MovePoint(x_move, y_move, z_move);
}

void CPolygon::MovePolygon(CPoint point_move)
{
	for (int i = 0; i < _num_of_points; i++)
		_points_array[i].MovePoint(point_move);
}

void CPolygon::MovePolygonCenter(Axis axis, double coordinate_value)
{
	CPoint p = GetPolygonCenter();
	MovePolygon(axis, coordinate_value - p.GetCoordinate(axis));
}

void CPolygon::MovePolygonCenter(double x_coordinate, double y_coordinate, double z_coordinate)
{
	CPoint p = GetPolygonCenter();
	p.ScalePoint(-1, -1, -1);
	MovePolygon(p);
	MovePolygon(x_coordinate, y_coordinate, z_coordinate);
}

void CPolygon::MovePolygonCenter(CPoint point_coordinate)
{
	CPoint p = GetPolygonCenter();
	p.ScalePoint(-1, -1, -1);
	MovePolygon(p);
	MovePolygon(point_coordinate);
}
#pragma endregion

#pragma region Scale polygon functions
void CPolygon::ScalePolygon(Axis axis, double scale_ratio)
{
	for (int i = 0; i < _num_of_points; i++)
		_points_array[i].ScalePoint(axis, scale_ratio);
}

void CPolygon::ScalePolygon(double x_ratio, double y_ratio, double z_ratio)
{
	for (int i = 0; i < _num_of_points; i++) 
		_points_array[i].ScalePoint(x_ratio, y_ratio, z_ratio);
}

void CPolygon::ScaleSelfPolygon(Axis axis, double scale_ratio)
{
	CPoint polygon_center = GetPolygonCenter();
	polygon_center.ScalePoint(-1, -1, -1);
	MovePolygon(polygon_center);
	polygon_center.ScalePoint(-1, -1, -1);
	ScalePolygon(axis, scale_ratio);
	MovePolygon(polygon_center);
}

void CPolygon::ScaleSelfPolygon(double x_ratio, double y_ratio, double z_ratio)
{
	CPoint polygon_center = GetPolygonCenter();
	polygon_center.ScalePoint(-1, -1, -1);
	MovePolygon(polygon_center);
	polygon_center.ScalePoint(-1, -1, -1);
	ScalePolygon(x_ratio, y_ratio, z_ratio);
	MovePolygon(polygon_center);
}
#pragma endregion

#pragma region Rotate polygon functions
void CPolygon::RotatePolygon(Axis axis, double rotate_value)
{
	for (int i = 0; i < _num_of_points; i++) 
		_points_array[i].RotatePoint(axis, rotate_value);
}

void CPolygon::RotateSelfPolygon(Axis axis, double rotate_value)
{
	CPoint polygon_center = GetPolygonCenter();
	polygon_center.ScalePoint(-1, -1, -1);
	MovePolygon(polygon_center);
	polygon_center.ScalePoint(-1, -1, -1);
	RotatePolygon(axis, rotate_value);
	MovePolygon(polygon_center);
}
#pragma endregion

#pragma region Draw polygon function
void CPolygon::DrawPolygon()
{
	glPolygonMode(GL_FRONT, GL_FILL);
	glBegin(GL_POLYGON);
	for(int i = 0; i < _num_of_points; i++)
		_points_array[i].DrawPoint();
	glEnd();
}
#pragma endregion

#pragma region Get functions
CPoint CPolygon::GetPoint(int point_index)
{
	return _points_array[point_index];
}	

CPoint CPolygon::GetPolygonCenter()
{
	CPoint sum(0, 0, 0);
	for (int i = 0; i < _num_of_points; i++)
		sum.MovePoint(_points_array[i]);
	double scale_ratio = 1.0/_num_of_points;
	sum.ScalePoint(scale_ratio, scale_ratio, scale_ratio);
	return sum;
}

int CPolygon::GetNumberOfPoints()
{
	return _num_of_points;
}
#pragma endregion