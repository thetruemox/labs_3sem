#pragma once
#include "Warehouse.h"

class Terminal
{
public:
	Terminal();
	~Terminal();

private:
	std::vector<Warehouse*> warehouses;
};

