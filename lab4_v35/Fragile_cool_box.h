#pragma once
#include "Box.h"
class Fragile_cool_box : public Box
{
public:

	Fragile_cool_box(int l, int w, int h, float temperature, float max_pressure);

	float get_max_pressure() const;
	float get_temperature() const;

	void set_max_pressure(float max_pressure);
	void set_temperature(float temperature);

private:
	Fragile_cool_box();
	Fragile_cool_box(float temperature);

	float max_pressure;
	float temperature;
};


