#pragma once
#include "Box.h"
class Fragile_cold_box : public Box
{
public:
	Fragile_cold_box();
	Fragile_cold_box(float temperature);
	Fragile_cold_box(int l, int w, int h, float temperature);

	float get_pressure() const;
	float get_temperature() const;

	void set_pressure(float pressure);
	void set_temperature(float temperature);

private:

	float pressure;
	float temperature;
};


