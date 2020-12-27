#pragma once
#include "Box.h"

/**
 * @brief Type of temperature sensitive boxes in warehouse
 */
class Cool_box : virtual public Box
{
public:
	Cool_box();
	Cool_box(const Cool_box& box);
	Cool_box(int l, int w, int h, float mass, float temperature);

	///Return maximum available storage temperature
	float get_temperature() const;

	///Set maximum available storage temperature
	void set_temperature(float t);

private:
	float temperature;
};

