#pragma once
#include <string>
#include <vector>
#include "..\lab4_v35\Warehouse.h"
#include <ctime>
#include <cstdlib>


#define MAX_BOX_SIZE 5
#define MAX_BOX_MASS 5
#define MAX_PRESSURE 10
#define MIN_TEMPERATURE -10
#define MAX_TEMPERATURE 10

class Provider
{
public:
	Provider() { this->warehouse = nullptr; }
	Provider(Warehouse* warehouse) { this->warehouse = warehouse; }

	void add_box();
	void delete_box();

	int rand_num(int min, int max);

	int get_size() { return this->id_arr.size(); }
private:
	Warehouse* warehouse;
	std::vector<int> id_arr;
	//std::string name;
};

