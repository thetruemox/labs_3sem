#include "Terminal.h"

Terminal::~Terminal()
{
	for (int i = 0; i < this->warehouses.size(); i++)
	{
		delete this->warehouses[i];
	}
}
