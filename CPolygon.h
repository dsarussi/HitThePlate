#pragma once

#include "CPoint.h"

class CPolygon
{
public:
#pragma region CONSTRUCTORs & DESTRUCTOR
	/// The basic constructor - creates a new instance of CPolygon class with 2 points, all at (0,0,0)
	CPolygon();

	/// A constructor with given number of points - creates a new instance of CPolygon class with all points at (0,0,0)
	/// Parameters:
	///		num_of_points - The number of points
	CPolygon(int num_of_points);

	/// Copy constuctor - create a new copy of the given polygon
	/// Parameters:
	///		polygon - The polygon to be copied
	CPolygon(const CPolygon& polygon);

	/// The destructor of the class - required to free memory allocation
	~CPolygon();
#pragma endregion

#pragma region Setting polygon properties
	/// Change the number of points in the polygon. All points created at (0,0,0)
	/// Parameters:
	///		num_of_points - The number of points		
	void SetNumberOfPoints(int num_of_points);

	/// Set polygon's color in a given color component
	/// Parameters:
	/// 	color_component - The color component in which the polygon's color will be changed
	/// 	color_value - The new color's component value
	void SetPolygonColor(Color color_component, double color_value);

	/// Set polygon's color in all color components
	/// Parameters:
	/// 	red_component - The new red component of the polygon's color
	/// 	green_component - The new green component of the polygon's color
	/// 	blue_component - The new blue component of the polygon's color
	void SetPolygonColor(double red_component, double green_component, double blue_component);

	/// Change the polygon to be with the same array of points as the given polygon
	/// Parameters:
	///		polygon - the original polygon
	void DuplicatePolygon(CPolygon polygon);
#pragma endregion

#pragma region Setting one point properties
	/// Change one point in the polygon to a given point
	/// Parameters:
	/// 	point_index - The index of the point in the polygon to be changed
	/// 	point - The new point in the polygon
	void SetOnePoint(int point_index, CPoint point);

	/// Change location of one point in the polygon to a given coordinates
	/// Parameters:
	/// 	point_index - The index of the point in the polygon to be changed
	/// 	x_coordinate - The new coordinate value of the point in the x axis
	/// 	y_coordinate - The new coordinate value of the point in the y axis
	/// 	z_coordinate - The new coordinate value of the point in the z axis
	void SetOnePointCoordinates(int point_index, double x_coordinate, double y_coordinate, double z_coordinate);

	/// Change one point's color in a given color component
	/// Parameters:
	/// 	point_index - The index of the point in the polygon to be changed
	/// 	color_component - The color component in which the point's color will be changed
	/// 	color_value - The new color's component value
	void SetOnePointColor(int point_index, Color color_component, double color_value);

	/// Change one point's color in all color components
	/// Parameters:
	/// 	point_index - The index of the point in the polygon to be changed
	/// 	red_component - The new red component of the point's color
	/// 	green_component - The new green component of the point's color
	/// 	blue_component - The new blue component of the point's color
	void SetOnePointColor(int point_index, double red_component, double green_component, double blue_component);
#pragma endregion

#pragma region Move polygon functions
	/// Move polygon in a given axis
	/// Parameters:
	///		axis - The axis in which the polygon will be moved
	///		move_value - The value in which the polygon will be moved
	void MovePolygon(Axis axis, double move_value);

	/// Move polygon in all axes
	/// Parameters:
	///		x_move - The value in which the polygon will be moved in the x axis
	/// 	y_move - The value in which the polygon will be moved in the y axis
	/// 	z_move - The value in which the polygon will be moved in the z axis
	void MovePolygon(double x_move, double y_move,double z_move);

	/// Move polygon by the coordinate of another point
	/// Parameters:
	/// 	point_move - The point with the coordinate in which the polygon will be moved
	void MovePolygon(CPoint point_move);

	/// Change polygon's center in a given axis
	/// Parameters:
	///		axis - The axis in which the polygon will be moved
	///		coordinate_value - The new coordinate value of the polygon's center in the given axis
	void MovePolygonCenter(Axis axis, double coordinate_value);

	/// Change polygon's center in all axes
	/// Parameters:
	/// 	x_coordinate - The new coordinate value of the polygon's center in the x axis
	/// 	y_coordinate - The new coordinate value of the polygon's center in the y axis
	/// 	z_coordinate - The new coordinate value of the polygon's center in the z axis
	void MovePolygonCenter(double x_coordinate, double y_coordinate,double z_coordinate);

	/// Change polygon's center by the coordinate of another point
	/// Parameters:
	/// 	point_coordinate - The point with the coordinate to which the polygon's center will be changed to
	void MovePolygonCenter(CPoint point_coordinate);
#pragma endregion

#pragma region Scale polygon functions
	/// Scale polygon in a given axis, relativly to (0,0,0)
	/// Parameters:
	/// 	axis - The axis in which the polygon will be scaled
	/// 	scale_ratio - The ratio in which the polygon will be scaled
	void ScalePolygon(Axis axis, double scale_ratio);

	/// Scale polygon in all axes, relativly to (0,0,0)
	/// Parameters:
	/// 	x_ratio - The ratio in which the polygon will be scaled in the x axis
	/// 	y_ratio - The ratio in which the polygon will be scaled in the y axis
	/// 	z_ratio - The ratio in which the polygon will be scaled in the z axis
	void ScalePolygon(double x_ratio, double y_ratio, double z_ratio);

	/// Scale polygon in a given axis, relativly to the polygon center
	/// Parameters:
	/// 	axis - The axis in which the polygon will be scaled
	/// 	scale_ratio - The ratio in which the polygon will be scaled
	void ScaleSelfPolygon(Axis axis, double scale_ratio);

	/// Scale polygon in all axes, relativly to the polygon center
	/// Parameters:
	/// 	x_ratio - The ratio in which the polygon will be scaled in the x axis
	/// 	y_ratio - The ratio in which the polygon will be scaled in the y axis
	/// 	z_ratio - The ratio in which the polygon will be scaled in the z axis
	void ScaleSelfPolygon(double x_ratio, double y_ratio, double z_ratio);
#pragma endregion

#pragma region Rotate polygon functions
	/// Rotate polygon around a given axis, relativly to (0,0,0)
	/// Parameters:
	/// 	axis - The axis which the polygon will be rotated around
	/// 	rotate_value - The angle (in degrees) in which the polygon will be rotated
	void RotatePolygon(Axis axis, double rotate_value);

	/// Rotate polygon around a given axis, relativly to the polygon center
	/// Parameters:
	/// 	axis - The axis which the polygon will be rotated around
	/// 	rotate_value - The angle (in degrees) in which the polygon will be rotated
	void RotateSelfPolygon(Axis axis, double rotate_value);
#pragma endregion

#pragma region Draw polygon function
	/// Draws the polygon, using the graphic library
	void DrawPolygon();
#pragma endregion

#pragma region Get functions
	/// Get one point from the polygon
	/// Parameters:
	/// 	point_index - The index of the point in the polygon to be returned
	/// Returns:
	///		The point in the given index
	CPoint GetPoint(int point_index);

	/// Returns the center of the polygon
	CPoint GetPolygonCenter();

	/// Returns the number of points in the polygon
	int GetNumberOfPoints();
#pragma endregion

private:
#pragma region Private variables
	/// Number of points in the polygon
	int _num_of_points;

	/// Array of the points in the polygon
	CPoint* _points_array;
#pragma endregion
};