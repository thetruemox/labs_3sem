#pragma once
#include "Box.h"

class Fragile_box : public Box
{
public:

	Fragile_box(int l, int w, int h, int max_pressure);
	
	float get_pressure() const;
	void set_pressure(float pressure);

protected:
	Fragile_box();

	float max_pressure;
	float pressure;
};

