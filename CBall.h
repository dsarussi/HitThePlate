#pragma once
#include "CModel.h"

/// Create colorful ball, with radius in (x,y,z)=1 and centered at (0,0,0)
class CBall : public CModel
{
public:
#pragma region CONSTRUCTORs
	/// The basic constructor - creates a new instance of CBall class with 10 values for fi and 30 values for theta
	CBall(void);

	/// A constructor with given number of fi values and theta values - creates a new instance of CBall class with the given number of values for fi and theta
	/// Parameters:
	///		num_of_fi_values - The number of values for fi
	///		num_of_theta_values - The number of values for theta
	CBall(int num_of_fi_values, int num_of_theta_values);
#pragma endregion

#pragma region Set ball properties
	/// Change the number of fi and theta values in the ball. The new ball is varying between white and black with radius in (x,y) = 1 and and with center at (0,0,0)
	/// Parameters:
	///		num_of_fi_values - The number of values for fi
	///		num_of_theta_values - The number of values for theta
	void SetBallNumOfElements(int num_of_fi_values, int num_of_theta_values);

	/// Change the colors of the ball to vary between the given colors
	/// Parameters:
	///		red_component_min - The minimal value of the colors' red component
	///		red_component_max - The maximal value of the colors' red component
	///		green_component_min - The minimal value of the colors' green component
	///		green_component_max - The maximal value of the colors' green component
	///		blue_component_min - The minimal value of the colors' blue component
	///		blue_component_max - The maximal value of the colors' blue component
	void SetBallColors(double red_component_min, double red_component_max, double green_component_min, double green_component_max, double blue_component_min, double blue_component_max);
#pragma endregion

private:
	/// Returns number between 0 to 1, with cyclic in theta_index and linearty in fi_index
	/// Parameters:
	///		fi_index - The index of fi value, between 0 to _num_of_fi_values-1
	///		theta_index - The index of theta value, between 0 to _num_of_theta_values-1
	///		fi_weight - The weight of fi in the new color value
	///		theta_weight - The weight of theta in the new color value
	double GetNewColorComponent(int fi_index, int theta_index, int fi_weight, int theta_weight);
#pragma region Private variables
	/// Number of fi values in the ball
	int _num_of_fi_values;

	/// Number of theta values in the ball
	int _num_of_theta_values;
#pragma endregion
};
