#include "Fragile_cool_box.h"

#define BASE_SIZE 1
Fragile_cool_box::Fragile_cool_box() : Box()
{
	this->set_temperature(BASE_SIZE);
	this->set_max_pressure(BASE_SIZE);
	this->set_pressure(0);
}

Fragile_cool_box::Fragile_cool_box(const Fragile_cool_box& box) : Box(box)
{
	this->set_temperature(box.get_temperature());
	this->set_max_pressure(box.get_max_pressure());
	this->set_pressure(box.get_pressure());
}

Fragile_cool_box::Fragile_cool_box(int l, int w, int h, float mass, float temperature, float max_pressure) : Box(l, w, h, mass)
{
	if (max_pressure < 0)
	{
		throw "Fragile_cool_box: Incorrect values specified";
	}
	else
	{
		this->set_temperature(temperature);
		this->set_max_pressure(max_pressure);
		this->set_pressure(0);
	}
	
}
