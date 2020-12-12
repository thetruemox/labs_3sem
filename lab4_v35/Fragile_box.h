#pragma once
#include "Box.h"

class Fragile_box : virtual public Box
{
public:
	Fragile_box();
	Fragile_box(int l, int w, int h, float mass, int max_pressure);

	float max_pressure;
	float pressure;
};

