#include <iostream>
using namespace std;
#include <memory>
#include <list>
#include <vector>

#include "Terminal.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>



int main()
{ 
    Terminal terminal;
	int num = 0;

	while (num != 8)
	{
		cout << "1. add_warehouse()" << endl;
		cout << "2. put_box()" << endl;
		cout << "3. delete_box()" << endl;
		cout << "4. move_box()" << endl;
		cout << "5. out_boxes()" << endl;
		cout << "6. out_warehouses()" << endl;
		cout << "7. map_out()" << endl;
		cout << "8. Exit" << endl;
		cout << "Command number: ";

		
		std::cin >> num;

		while (!std::cin.good())
		{
			std::cout << std::endl << "Invalid input, try again" << std::endl;
			std::cin >> num;
		}

		switch (num)
		{
		case 1:
			std::cout << std::endl;
			terminal.add_warehouse();
			std::cout << std::endl;
			break;
		case 2:
			std::cout << std::endl;
			terminal.put_box();
			std::cout << std::endl;
			break;
		case 3:
			std::cout << std::endl;
			terminal.delete_box();
			std::cout << std::endl;
			break;
		case 4:
			std::cout << std::endl;
			terminal.move_box();
			std::cout << std::endl;
			break;
		case 5:
			std::cout << std::endl;
			terminal.out_boxes();
			std::cout << std::endl;
			break;
		case 6:
			std::cout << std::endl;
			terminal.out_warehouses();
			std::cout << std::endl;
			break;
		case 7:
			std::cout << std::endl;
			terminal.map_out();
			std::cout << std::endl;
			break;
		case 8:
			return 0;
		default:
			cout << "There is no such command!" << endl << endl;
			break;
		}
	}

    _CrtDumpMemoryLeaks();
    return 0;
}

