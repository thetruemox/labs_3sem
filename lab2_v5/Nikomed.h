#pragma once

class Nikomed
{
public:
	Nikomed(float a, float l);
	//a - offset, 2l - length between two points of nikomed

	float get_a();
	void set_a(float a);
	float get_l();
	void set_l(float l);

	int get_descartes_y(float x, float* res);
	int get_polar_r(float angle, float* res);
	int get_curve_r(float* arr_res);
	int get_circle_area(float* res);
	int get_inflection_x(float* arr_res);

private:
	float a, l;

};

