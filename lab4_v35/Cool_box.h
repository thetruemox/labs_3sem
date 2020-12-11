#pragma once
#include "Box.h"

class Cool_box : virtual public Box
{
public:
	Cool_box();
	Cool_box(int l, int w, int h, float temperature);

	float temperature;
};

