#pragma once

#include "CPoint.h"
#include "CPolygon.h"

class CModel
{
public:
#pragma region CONSTRUCTORs & DESTRUCTOR
	/// The basic constructor - creates a new instance of CModel class with 2 polygons, all with default constructor
	CModel();

	/// A constructor with given number of polygons - creates a new instance of CModel class with given number of polygons
	/// Parameters:
	///		num_of_polygons - The number of polygons
	CModel(int num_of_polygons);

	/// Copy constuctor - create a new copy of the given model
	/// Parameters:
	///		model - The model to be copied
	CModel(const CModel& model);

	/// The destructor of the class - required to free memory allocation
	~CModel();
#pragma endregion
	
#pragma region Setting model properties
	/// Change the number of polygons in the model. All polygons created using the default constructor
	/// Parameters:
	///		num_of_polygons - The number of polygons		
	void SetNumberOfPolygons(int num_of_polygons);

	/// Set model's color in a given color component
	/// Parameters:
	/// 	color_component - The color component in which the model's color will be changed
	/// 	color_value - The new color's component value
	void SetModelColor(Color color_component, double color_value);

	/// Set model's color in all color components
	/// Parameters:
	/// 	red_component - The new red component of the model's color
	/// 	green_component - The new green component of the model's color
	/// 	blue_component - The new blue component of the model's color
	void SetModelColor(double red_component, double green_component, double blue_component);
#pragma endregion

#pragma region Setting one polygon properties
	/// Change one polygon in the model to a given polygon
	/// Parameters:
	/// 	polygon_index - The index of the polygon in the model to be changed
	/// 	polygon - The new polygon in the model
	void SetOnePolygon(int polygon_index, CPolygon polygon);

	/// Change one polygon's color in a given color component
	/// Parameters:
	/// 	polygon_index - The index of the polygon in the model to be changed
	/// 	color_component - The color component in which the polygon's color will be changed
	/// 	color_value - The new color's component value
	void SetOnePolygonColor(int polygon_index, Color color_component, double color_value);

	/// Change one polygon's color in all color components
	/// Parameters:
	/// 	polygon_index - The index of the polygon in the model to be changed
	/// 	red_component - The new red component of the polygon's color
	/// 	green_component - The new green component of the polygon's color
	/// 	blue_component - The new blue component of the polygon's color
	void SetOnePolygonColor(int polygon_index, double red_component, double green_component, double blue_component);
#pragma endregion

#pragma region Move model functions
	/// Move model in a given axis
	/// Parameters:
	///		axis - The axis in which the model will be moved
	///		move_value - The value in which the model will be moved
	void MoveModel(Axis axis, double move_value);

	/// Move model in all axes
	/// Parameters:
	///		x_move - The value in which the model will be moved in the x axis
	/// 	y_move - The value in which the model will be moved in the y axis
	/// 	z_move - The value in which the model will be moved in the z axis
	void MoveModel(double x_move, double y_move,double z_move);

	/// Move model by the coordinate of another point
	/// Parameters:
	/// 	point_move - The point with the coordinate in which the model will be moved
	void MoveModel(CPoint point_move);

	/// Change model's center in a given axis
	/// Parameters:
	///		axis - The axis in which the model will be moved
	///		coordinate_value - The new coordinate value of the model's center in the given axis
	void MoveModelCenter(Axis axis, double coordinate_value);

	/// Change model's center in all axes
	/// Parameters:
	/// 	x_coordinate - The new coordinate value of the model's center in the x axis
	/// 	y_coordinate - The new coordinate value of the model's center in the y axis
	/// 	z_coordinate - The new coordinate value of the model's center in the z axis
	void MoveModelCenter(double x_coordinate, double y_coordinate,double z_coordinate);

	/// Change model's center by the coordinate of another point
	/// Parameters:
	/// 	point_coordinate - The point with the coordinate to which the model's center will be changed to
	void MoveModelCenter(CPoint point_coordinate);
#pragma endregion

#pragma region Scale model functions
	/// Scale model in a given axis, relativly to (0,0,0)
	/// Parameters:
	/// 	axis - The axis in which the model will be scaled
	/// 	scale_ratio - The ratio in which the model will be scaled
	void ScaleModel(Axis axis, double scale_ratio);

	/// Scale model in all axes, relativly to (0,0,0)
	/// Parameters:
	/// 	x_ratio - The ratio in which the model will be scaled in the x axis
	/// 	y_ratio - The ratio in which the model will be scaled in the y axis
	/// 	z_ratio - The ratio in which the model will be scaled in the z axis
	void ScaleModel(double x_ratio, double y_ratio, double z_ratio);

	/// Scale model in a given axis, relativly to the model center
	/// Parameters:
	/// 	axis - The axis in which the model will be scaled
	/// 	scale_ratio - The ratio in which the model will be scaled
	void ScaleSelfModel(Axis axis, double scale_ratio);

	/// Scale model in all axes, relativly to the polygon center
	/// Parameters:
	/// 	x_ratio - The ratio in which the model will be scaled in the x axis
	/// 	y_ratio - The ratio in which the model will be scaled in the y axis
	/// 	z_ratio - The ratio in which the model will be scaled in the z axis
	void ScaleSelfModel(double x_ratio, double y_ratio, double z_ratio);
#pragma endregion

#pragma region Rotate model functions
	/// Rotate model around a given axis, relativly to (0,0,0)
	/// Parameters:
	/// 	axis - The axis which the model will be rotated around
	/// 	rotate_value - The angle (in degrees) in which the model will be rotated
	void RotateModel(Axis axis, double rotate_value);

	/// Rotate model around a given axis, relativly to the model center
	/// Parameters:
	/// 	axis - The axis which the model will be rotated around
	/// 	rotate_value - The angle (in degrees) in which the model will be rotated
	void RotateSelfModel(Axis axis, double rotate_value);
#pragma endregion

#pragma region Draw model function
	/// Draws the model, using the graphic library
	void DrawModel();
#pragma endregion
	
#pragma region Get functions
	/// Get one polygon from the model
	/// Parameters:
	/// 	polygon_index - The index of the polygon in the model to be returned
	/// Returns:
	///		The polygon in the given index
	CPolygon GetPolygon(int polygon_index);

	/// Returns the center of the model
	CPoint GetModelCenter();

	/// Returns the number of polygons in the model
	int GetNumberOfPolygons();
#pragma endregion

protected:
#pragma region Private variables
	/// Number of polygons in the model
	int _num_of_polygons;

	/// Array of the polygons in the model
	CPolygon* _polygons_array;
#pragma endregion
};
