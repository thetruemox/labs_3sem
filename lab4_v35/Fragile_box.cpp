#include "Fragile_box.h"


Fragile_box::Fragile_box() : Box()
{
	this->max_pressure = 100.0f;
	this->pressure = 0;
}

Fragile_box::Fragile_box(const Fragile_box& box) : Box(box)
{
	this->pressure = box.pressure;
	this->max_pressure = box.max_pressure;
}

Fragile_box::Fragile_box(int l, int w, int h, float mass, float max_pressure) : Box(l, w, h, mass)
{
	if (max_pressure < 0)
	{
		throw "Fragile_box: Incorrect values specified";
	}
	else
	{
		this->max_pressure = max_pressure;
		this->pressure = 0;
	}
}

void Fragile_box::set_pressure(float mass)
{
	if (mass >= 0) this->pressure = mass;
}

void Fragile_box::set_max_pressure(float max)
{
	if (max >= 0) this->max_pressure = max;
}

float Fragile_box::get_pressure() const
{
	return this->pressure;
}

float Fragile_box::get_max_pressure() const
{
	return this->max_pressure;
}

    
