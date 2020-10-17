#include "Cell.h"

Cell::Cell()
{
	this->number = 0;
	condition = 0;
}

Cell::Cell(int number)
{
	this->number = number;
	condition = 1;
}

