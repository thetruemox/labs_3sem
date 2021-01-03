#pragma once
#include "Cool_box.h"
#include "Fragile_box.h"

/**
 * @brief Combination of Fragile and Cool box
 */
class Fragile_cool_box : public Cool_box, public Fragile_box
{
public:
	/// <summary>
	/// Base constructor
	/// </summary>
	Fragile_cool_box();
	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="box">Copy box</param>
	Fragile_cool_box(const Fragile_cool_box& box);

	Box* copy(Box* obj) override;

	/// <summary>
	/// Constructor that initializes all box parameters
	/// </summary>
	/// <param name="l">Box length</param>
	/// <param name="w">Box width</param>
	/// <param name="h">Box height</param>
	/// <param name="mass">Box mass</param>
	/// <param name="temperature">Box temperature</param>
	/// <param name="max_pressure">Box max_pressure</param>
	Fragile_cool_box(int l, int w, int h, float mass, float temperature, float max_pressure);

};


