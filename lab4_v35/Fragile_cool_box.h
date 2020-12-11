#pragma once
#include "Cool_box.h"
#include "Fragile_box.h"

class Fragile_cool_box : public Cool_box, public Fragile_box
{
public:
	//Fragile_cool_box();
	Fragile_cool_box(int l, int w, int h, float temperature, float max_pressure);
};


