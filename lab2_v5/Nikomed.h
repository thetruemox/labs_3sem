#pragma once


	class Nikomed
	{
	public:
		Nikomed();
		Nikomed(float a, float l);
		//a - offset, 2l - length between two points of nikomed

		const float get_a();
		const float get_l();

		void set_a(float a);
		void set_l(float l);

		const int get_descartes_y(float x, float& res);
		const int get_polar_r(float angle, float& res);
		const int get_curve_r(float* arr_res);
		const int get_circle_area(float& res);
		const int get_inflection_x(float* arr_res);

	private:
		float a, l;

	};
