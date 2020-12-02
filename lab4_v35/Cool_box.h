#pragma once
#include "Box.h"

class Cool_box : public Box
{
public:
	Cool_box();
	Cool_box(float temperature);
	Cool_box(int l, int w, int h, float temperature);

	float get_temperature() const;
	void set_temperature(float temperature);

private:
	float temperature;
};

