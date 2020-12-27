#pragma once
#include "Box.h"

/**
 * @brief A type of load-sensitive boxes in warehouse that should not be laid on its side
 */
class Fragile_box : virtual public Box
{
public:
	/// <summary>
	/// Base constructor
	/// </summary>
	Fragile_box();
	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="box">Copy box</param>
	Fragile_box(const Fragile_box& box);
	/// <summary>
	/// Constructor that initializes all box parameters
	/// </summary>
	/// <param name="l">Box length</param>
	/// <param name="w">Box width</param>
	/// <param name="h">Box height</param>
	/// <param name="mass">Box mass</param>
	/// <param name="max_pressure">Box max_pressure</param>
	Fragile_box(int l, int w, int h, float mass, float max_pressure);

	/// <summary>
	/// Set the pressure of other boxes is higher for this
	/// </summary>
	/// <param name="mass">Mass</param>
	void set_pressure(float mass);
	/// <summary>
	/// Set the maximum allowable pressure on this box
	/// </summary>
	/// <param name="max">Max pressure</param>
	void set_max_pressure(float max);
	/// <summary>
	/// Returns the pressure of other boxes is higher for this
	/// </summary>
	/// <returns>Pressure on this box</returns>
	float get_pressure() const;
	/// <summary>
	/// Returns the maximum allowable pressure on this box
	/// </summary>
	/// <returns>Maximum allowable pressure on this box</returns>
	float get_max_pressure() const;

private:
	float max_pressure;
	float pressure;
};

