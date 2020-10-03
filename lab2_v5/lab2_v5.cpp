#include <iostream>
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

	int com_num;
	int t_s;
	float* arr_res;
	float* arr_x;
	float res, x, angle;

	while (1)
	{
		cout << "1. get_descartes_y()" << endl;
		cout << "2. get_polar_r()" << endl;
		cout << "3. get_curve_r()" << endl;
		cout << "4. get_circle_area()" << endl;
		cout << "5. get_inflection_p()" << endl;
		cout << "6. Exit" << endl;
		cout << "Command number: ";

		com_num = read_poz();
		
		switch (com_num)
		{
		case 1:
			cout << "Type x: ";
			x = read_r();
			if (nikomed.get_descartes_y(x, &res) == 0)
			{
				cout << "y = " << res << endl;
			}
			else cout << "There is no such y for that x!" << endl;
			
			cout << endl;
			break;
		case 2:
			cout << "Type angle: ";
			angle = read_r();
			if (nikomed.get_polar_r(angle, &res) == 0)
			{
				cout << "length = " << res << endl;
			}
			else cout << endl << "There is no such length for that angle!" << endl;

			cout << endl;
			break;
		case 3:
			arr_res = new float[3];
			
			if (nikomed.get_curve_r(arr_res) == 0)
			{
				cout << "Radiuses of curvature: " << endl;
				for (int i = 0; i < 3; i++)
				{
					cout << "R" << i << ": " << arr_res[i] << " ";
				}
				cout << endl;
			}
			else 
			{
				cout << "Radiuses of curvature: " << endl;
				for (int i = 0; i < 2; i++)
				{
					cout << "R" << i << ": " << arr_res[i] << " ";
				}
				cout << endl;
			}

			cout << endl;
			delete[] arr_res;
			break;
		case 4:
			if (nikomed.get_circle_area(&res) == 0)
			{
				cout << "Circle area = " << res << endl;
			}
			else cout << "There is no circle area!" << endl;

			cout << endl;
			break;
		case 5:
			arr_x = new float[3];

			t_s = nikomed.get_inflection_x(arr_x);
			float temp;

			cout << "Inflection points: " << endl;
			for (int i = 0; i < t_s; i++)
			{
				nikomed.get_descartes_y(arr_x[i], &temp);
				cout << "x: " << arr_x[i] << " y: " << temp << endl;
			}

			delete[] arr_x;
			cout << endl;
			break;
		case 6:

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

