#pragma once

#pragma region ENUMs
/// Holds the point available axes
enum Axis 
{
	/// The x axis
	X_AXIS = 1, 
	/// The y axis
	Y_AXIS = 2, 
	/// The z axis
	Z_AXIS = 3
};

/// Holds the color's components of a point
enum Color 
{
	/// The red component of a point
	RED_COMPONENT = 1, 
	/// The green component of a point
	GREEN_COMPONENT = 2, 
	/// The blue component of a point
	BLUE_COMPONENT = 3
};
#pragma endregion

class CPoint
{
public:

#pragma region CONSTRUCTORs
	/// The basic constructor - creates a new instance of CPoint class
	CPoint();

	/// A constructor with given coordinates - creates a new instance of CPoint class with the given coordinates
	/// Parameters:
	///		x_coordinate - The x coordinate of the point
	///		y_coordinate - The y coordinate of the point
	///		z_coordinate - The z coordinate of the point
	CPoint(double x_coordinate, double y_coordinate, double z_coordinate);

	/// A constructor with given coordinates and color - creates a new instance of CPoint class with the given coordinates and color
	/// Parameters:
	///		x_coordinate - The x coordinate of the point
	///		y_coordinate - The y coordinate of the point
	///		z_coordinate - The z coordinate of the point
	///		red_component - The red component of the color
	///		green_component - The green component of the color
	///		blue_component - The blue component of the color
	CPoint(double x_coordinate, double y_coordinate, double z_coordinate, double red_component, double green_component, double blue_component);
#pragma endregion

#pragma region Move point functions
	/// Move point in a given axis
	/// Parameters:
	///		axis - The axis in which the point will be moved
	///		move_value - The value in which the point will be moved
	void MovePoint(Axis axis, double move_value);

	/// Move point in all axes
	/// Parameters:
	///		x_move - The value in which the point will be moved in the x axis
	/// 	y_move - The value in which the point will be moved in the y axis
	/// 	z_move - The value in which the point will be moved in the z axis
	void MovePoint(double x_move, double y_move, double z_move);

	/// Move point by the coordinate of another point
	/// Parameters:
	/// 	point_move - The point with the coordinate in which the current point will be moved
	void MovePoint(CPoint point_move);
#pragma endregion

#pragma region Set point location functions
	/// Set point coordinate in a given axis
	/// Parameters:
	/// 	axis - The axis in which the point will be moved
	/// 	coordinate_value - The new coordinate value of the point in the given axis
	void SetPointCoordinate(Axis axis, double coordinate_value);

	/// Set point coordinate in all axes
	/// Parameters:
	/// 	x_coordinate - The new coordinate value of the point in the x axis
	/// 	y_coordinate - The new coordinate value of the point in the y axis
	/// 	z_coordinate - The new coordinate value of the point in the z axis
	void SetPointCoordinates(double x_coordinate, double y_coordinate, double z_coordinate);
#pragma endregion

#pragma region Scale point functions
	/// Scale point in a given axis
	/// Parameters:
	/// 	axis - The axis in which the point will be scaled
	/// 	scale_ratio - The ratio in which the point will be scaled
	void ScalePoint(Axis axis, double scale_ratio);

	/// Scale point in all axes
	/// Parameters:
	/// 	x_ratio - The ratio in which the point will be scaled in the x axis
	/// 	y_ratio - The ratio in which the point will be scaled in the y axis
	/// 	z_ratio - The ratio in which the point will be scaled in the z axis
	void ScalePoint(double x_ratio, double y_ratio, double z_ratio);
#pragma endregion

#pragma region Rotate point functions
	/// Rotate point around a given axis
	/// Parameters:
	/// 	axis - The axis which the point will be rotated around
	/// 	rotate_value - The angle (in degrees) in which the point will be rotated
	void RotatePoint(Axis axis, double rotate_value);
#pragma endregion

#pragma region Set point color functions
	/// Set point's color in a given color component
	/// Parameters:
	/// 	color_component - The color component in which the point's color will be changed
	/// 	color_value - The new color's component value
	void SetPointColor(Color color_component, double color_value);

	/// Set point's color in all color components
	/// Parameters:
	/// 	red_component - The new red component of the point's color
	/// 	green_component - The new green component of the point's color
	/// 	blue_component - The new blue component of the point's color
	void SetPointColor(double red_component, double green_component, double blue_component);
#pragma endregion

#pragma region Get functions
	/// Creates a point with the same coordinate and color as the current point
	/// Returns:
	///		A new instance of CPoint class
	CPoint ClonePoint();

	/// Get the coordinate of the point in a given axis
	/// Parameters:
	/// 	axis - The axis in which the point's coordinate will be returned
	/// Returns:
	///		The coordinate of the point in the given axis
	double GetCoordinate(Axis axis);

	/// Get point's color in a given color component
	/// Parameters:
	/// 	color_component - The color component in which the point's color will be returned
	/// Returns:
	///		The color's value of the point in the given color component
	double GetColor(Color color_component);
#pragma endregion

#pragma region Draw function
	void DrawPoint();
#pragma endregion

private:
#pragma region Private variables
	/// The coordinate of the point in the x axis
	double _x_coordinate;

	/// The coordinate of the point in the y axis
	double _y_coordinate;

	/// The coordinate of the point in the z axis
	double _z_coordinate;

	/// The red component of the point's color
	double _red_component;

	/// The green component of the point's color
	double _green_component;

	/// The blue component of the point's color
	double _blue_component;
#pragma endregion

#pragma region Move point functions
	/// Move point in the x axis
	/// 	x_move - The value in which the point will be moved in the x axis
	void MovePointX(double x_move);

	/// Move point in the y axis
	/// 	y_move - The value in which the point will be moved in the y axis
	void MovePointY(double y_move);

	/// Move point in the z axis
	/// 	z_move - The value in which the point will be moved in the z axis
	void MovePointZ(double z_move);
#pragma endregion

#pragma region Set point location functions
	/// Set point coordinate in the x axis
	/// 	x_coordinate - The new coordinate value of the point in the x axis
	void SetPointX(double x_coordinate);

	/// Set point coordinate in the y axis
	/// 	y_coordinate - The new coordinate value of the point in the y axis
	void SetPointY(double y_coordinate);

	/// Set point coordinate in the z axis
	/// 	z_coordinate - The new coordinate value of the point in the z axis
	void SetPointZ(double z_coordinate);
#pragma endregion

#pragma region Rotate point functions
	/// Rotate point around the x axis
	/// 	x_rotate - The angle (in degrees) in which the point will be rotated
	void RotatePointX(double x_rotate);

	/// Rotate point around the y axis
	/// 	y_rotate - The angle (in degrees) in which the point will be rotated
	void RotatePointY(double y_rotate);

	/// Rotate point around the z axis
	/// 	z_rotate - The angle (in degrees) in which the point will be rotated
	void RotatePointZ(double z_rotate);
#pragma endregion

#pragma region Set point color functions
	/// Set point's color in the red color part
	/// 	red_component - The new red part color of the point
	void SetPointRed(double red_component);

	/// Set point's color in the green color part
	/// 	green_component - The new green part color of the point
	void SetPointGreen(double green_component);

	/// Set point's color in the blue color part
	/// 	blue_component - The new blue part color of the point
	void SetPointBlue(double blue_component);
#pragma endregion

#pragma region Get functions
	/// Returns the coordinate of the point in the x axis
	double GetX();

	/// Returns the coordinate of the point in the y axis
	double GetY();

	/// Returns the coordinate of the point in the z axis
	double GetZ();

	/// Returns the red component of the point's color
	double GetRed();

	/// Returns the green component of the point's color
	double GetGreen();

	/// Returns the blue component of the point's color
	double GetBlue();
#pragma endregion
};