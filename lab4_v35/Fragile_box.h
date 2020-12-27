#pragma once
#include "Box.h"

/**
 * @brief A type of load-sensitive boxes in warehouse that should not be laid on its side
 */
class Fragile_box : virtual public Box
{
public:
	Fragile_box();
	Fragile_box(const Fragile_box& box);
	Fragile_box(int l, int w, int h, float mass, float max_pressure);

	///Set the pressure of other boxes is higher for this
	void set_pressure(float mass);
	///Set the maximum allowable pressure on this box
	void set_max_pressure(float max);
	///Get the pressure of other boxes is higher for this
	float get_pressure() const;
	///Get the maximum allowable pressure on this box
	float get_max_pressure() const;

private:
	float max_pressure;
	float pressure;
};

