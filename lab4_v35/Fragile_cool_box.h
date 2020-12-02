#pragma once
#include "Box.h"
class Fragile_cool_box : public Box
{
public:
	Fragile_cool_box();
	Fragile_cool_box(float temperature);
	Fragile_cool_box(int l, int w, int h, float temperature);

	float get_pressure() const;
	float get_temperature() const;

	void set_pressure(float pressure);
	void set_temperature(float temperature);

private:

	float pressure;
	float temperature;
};


