﻿#include <iostream>
#include "Nikomed.h"
#include "Reading.h"
using std::cout;
using std::endl;

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main()
{
	cout << "Type l and a (l > 0, a = R)" << endl;

	Nikomed nikomed(read_r(), read_poz());

	int com_num = 0;
	int t_s;
	float* arr_res;
	float* arr_x;
	float res, x, angle;
	
	while (com_num != 8)
	{
		cout << "1. get_descartes_y()" << endl;
		cout << "2. get_polar_r()" << endl;
		cout << "3. get_curve_r()" << endl;
		cout << "4. get_circle_area()" << endl;
		cout << "5. get_inflection_p()" << endl;
		cout << "6. set_a()" << endl;
		cout << "7. set_l()" << endl;
		cout << "8. Exit" << endl;
		cout << "Command number: ";

		com_num = read_poz();
		
		switch (com_num)
		{
		case 1:
			cout << "Type x: ";
			x = read_r();
			if (nikomed.get_descartes_y(x, res) == 0)
			{
				cout << "y = " << res << endl;
			}
			else cout << "There is no such y for that x!" << endl;
			
			cout << endl;
			break;
		case 2:
			cout << "Type angle: ";
			angle = read_r();
			if (nikomed.get_polar_r(angle, res) == 0)
			{
				cout << "length = " << res << endl;
			}
			else cout << endl << "There is no such length for that angle!" << endl;

			cout << endl;
			break;
		case 3:
			arr_res = new float[3];
				
			cout << "Radiuses of curvature: " << endl;
			for (int i = 0; i < nikomed.get_curve_r(arr_res, 3); i++)
			{
				cout << "R" << i << ": " << arr_res[i] << " ";
			}
			cout << endl << endl;

			delete[] arr_res;
			break;
		case 4:
			if (nikomed.get_circle_area(res) == 0)
			{
				cout << "Circle area = " << res << endl;
			}
			else cout << "There is no circle area!" << endl;

			cout << endl;
			break;
		case 5:
			arr_x = new float[3];
			float temp;

			cout << "Inflection points: " << endl;
			for (int i = 0; i < nikomed.get_inflection_x(arr_x, 3); i++)
			{
				nikomed.get_descartes_y(arr_x[i], temp);
				cout << "x: " << arr_x[i] << " y: " << temp << endl;
			}

			delete[] arr_x;
			cout << endl;
			break;

		case 6:
			cout << "Type a: ";
			nikomed.set_a(read_r());

			cout << endl;
			break;
		case 7:
			cout << "Type l: ";
			nikomed.set_l(read_poz());
		
			
			cout << endl;
			break;
		case 8:
			_CrtDumpMemoryLeaks();
			return 0;
			break;
		default:
			cout << "There is no such command!" << endl << endl;
			break;
		}
	}
    return 0;
}

