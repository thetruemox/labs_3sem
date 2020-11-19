#pragma once
#include "Box.h"

class Cold_box : public Box
{
public:
	Cold_box();
	Cold_box(float temperature);
	Cold_box(int l, int w, int h, float temperature);

	float get_temperature() const;
	void set_temperature(float temperature);

private:
	float temperature;
};

