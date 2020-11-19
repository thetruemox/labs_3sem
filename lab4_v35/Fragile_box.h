#pragma once
#include "Box.h"

class Fragile_box : public Box
{
public:
	Fragile_box();
	Fragile_box(int l, int w, int h);
	
	float get_pressure() const;
	void set_pressure(float pressure);

protected:
	float pressure;
};

