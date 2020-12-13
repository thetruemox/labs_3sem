#pragma once
#include "Box.h"

class Fragile_box : virtual public Box
{
public:
	Fragile_box();
	Fragile_box(const Fragile_box& box);
	Fragile_box(int l, int w, int h, float mass, float max_pressure);

	void set_pressure(float mass);
	void set_max_pressure(float max);

	float get_pressure() const;
	float get_max_pressure() const;

private:
	float max_pressure;
	float pressure;
};

