#include "Terminal.h"

Terminal::~Terminal()
{
	for (int i = 0; i < this->warehouses.size(); i++)
	{
		delete this->warehouses[i];
	}
}

void Terminal::out_warehouses()
{
	for (int i = 0; i < this->warehouses.size(); i++)
	{
		std::cout << "Warehouse " << i << " " << std::endl; 
		std::cout << "l = " << this->warehouses[i]->get_length() << ", w = " << this->warehouses[i]->get_width() << ", h = " << this->warehouses[i]->get_height() << std::endl;
		std::cout << "Temperature =  " << this->warehouses[i]->get_temperature() << std::endl;
		std::cout << "Has " << this->wh_size(i) << " box(-es)" << std::endl;

		std::cout << std::endl;
	}
}

void Terminal::map_out()
{
	std::cout << "In which warehouse? ";
	int index = get_int_pos_wzero();
	if (index >= this->warehouses.size()) return;

	this->warehouses[index]->map_out();
}

void Terminal::out_boxes()
{
	std::cout << "In which warehouse? ";
	int index = get_int_pos_wzero();
	if (index >= this->warehouses.size()) return;

	this->warehouses[index]->out_all_boxes(std::cout);
}

void Terminal::add_warehouse()
{
	std::cout << "Length: ";
	int length = get_int_pos();

	std::cout << "Width: ";
	int width = get_int_pos();

	std::cout << "Height: ";
	int height = get_int_pos();

	std::cout << "Temperature: ";
	float temperature = get_float_any();

	warehouses.push_back(new Warehouse(length, width, height, temperature));
}

void Terminal::put_box()
{
	std::cout << "In which warehouse? ";
	int index = get_int_pos_wzero();
	if (index >= this->warehouses.size()) return;

	std::cout << "Length: ";
	int length = get_int_pos();

	std::cout << "Width: ";
	int width = get_int_pos();

	std::cout << "Height: ";
	int height = get_int_pos();

	std::cout << "Mass: ";
	float mass = get_float_pos();

	int choice;
	Box* box = nullptr;
	float temperature, max_pressure;

	std::cout << "1. Box\n2. Cool_box\n3. Fragile_box\n4. Fragile_cool_box";
	std::cout << std::endl << "Choice: ";
	choice = get_int_pos();

	switch (choice)
	{
	case 1:
		box = new Box(length, width, height, mass);
		break;
	case 2:
		std::cout << "Temperature: ";
		temperature = get_float_any();
		box = new Cool_box(length, width, height, mass, temperature);
		break;
	case 3:
		std::cout << "Max_pressure: ";
		max_pressure = get_float_pos();
		box = new Fragile_box(length, width, height, mass, max_pressure);
		break;
	case 4:
		std::cout << "Temperature: ";
		temperature = get_float_any();
		std::cout << "Max_pressure: ";
		max_pressure = get_float_pos();
		box = new Fragile_cool_box(length, width, height, mass, temperature, max_pressure);
		break;
	default:
		return;
		break;
	}

	std::cout << "1. Auto\n2. Manual";
	std::cout << std::endl << "Choice: ";
	choice = get_int_pos();

	if (choice == 1)
	{
		if(!this->warehouses[index]->put_box_auto(box)) delete box;
	}
	else if (choice == 2)
	{
		std::cout << "X: ";
		int x = get_int_pos_wzero();

		std::cout << "Y: ";
		int y = get_int_pos_wzero();

		Cursor cursor(x, y);
		if(!this->warehouses[index]->put_box_manual(box, cursor)) delete box;
	}
	else return;
}

void Terminal::delete_box()
{
	std::cout << "In which warehouse? ";
	int index = get_int_any();
	if (index >= this->warehouses.size() || index < 0) return;
	
	std::cout << "ID: ";
	int ID = get_int_any();
	this->warehouses[index]->delete_box(ID);
}

void Terminal::move_box()
{
	std::cout << "In which warehouse? ";
	int index = get_int_any();
	if (index >= this->warehouses.size() || index < 0) return;


	std::cout << "ID: ";
	int ID = get_int_any();

	std::cout << "X: ";
	int x = get_int_pos_wzero();

	std::cout << "Y: ";
	int y = get_int_pos_wzero();

	Cursor cursor(x, y);
	this->warehouses[index]->move_box(ID, cursor);
}

int Terminal::wh_size(int index)
{
	return this->warehouses[index]->get_size();
}

int Terminal::get_int_pos()
{
	int num;
	std::cin >> num;

	while (!std::cin.good() || num <= 0)
	{
		std::cout << std::endl << "Invalid input, try again" << std::endl;
		std::cin >> num;
	}

	return num;
}

int Terminal::get_int_pos_wzero()
{
	int num;
	std::cin >> num;

	while (!std::cin.good() || num < 0)
	{
		std::cout << std::endl << "Invalid input, try again" << std::endl;
		std::cin >> num;
	}

	return num;
}

int Terminal::get_int_any()
{
	int num;
	std::cin >> num;

	while (!std::cin.good())
	{
		std::cout << std::endl << "Invalid input, try again" << std::endl;
		std::cin >> num;
	}

	return num;
}

float Terminal::get_float_any()
{
	float num;
	std::cin >> num;

	while (!std::cin.good())
	{
		std::cout << std::endl << "Invalid input, try again" << std::endl;
		std::cin >> num;
	}

	return num;
}

float Terminal::get_float_pos()
{
	float num;
	std::cin >> num;

	while (!std::cin.good() && num >= 0)
	{
		std::cout << std::endl << "Invalid input, try again" << std::endl;
		std::cin >> num;
	}

	return num;
}


