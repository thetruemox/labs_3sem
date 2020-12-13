#pragma once
#include "Box.h"

class Cool_box : virtual public Box
{
public:
	Cool_box();
	Cool_box(const Cool_box& box);
	Cool_box(int l, int w, int h, float mass, float temperature);

	float get_temperature() const;
	void set_temperature(float t);

private:
	float temperature;
};

