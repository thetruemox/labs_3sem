#pragma once
#include "Box.h"

/**
 * @brief Type of temperature sensitive boxes in warehouse
 */
class Cool_box : virtual public Box
{
public:
	/// <summary>
	/// Base constructor
	/// </summary>
	Cool_box();
	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="box">Copy box</param>
	Cool_box(const Cool_box& box);
	/// <summary>
	/// Constructor that initializes all box parameters
	/// </summary>
	/// <param name="l">Box length</param>
	/// <param name="w">Box width</param>
	/// <param name="h">Box height</param>
	/// <param name="mass">Box mass</param>
	/// <param name="temperature">Box temperature</param>
	Cool_box(int l, int w, int h, float mass, float temperature);

	Box* copy(Box* obj) override;

	/// <summary>
	/// Return maximum available storage temperature
	/// </summary>
	/// <returns>Maximum available storage temperature</returns>
	float get_temperature() const;
	/// <summary>
	/// Set maximum available storage temperature
	/// </summary>
	/// <param name="t">Temperature</param>
	void set_temperature(float t);

private:
	float temperature;
};

