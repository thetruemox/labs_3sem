#include "Cell.h"

Cell::Cell()
{
	this->number = -1;
	condition = 0;
}

void Cell::set_number(int num)
{
	this->number = num;
}

void Cell::set_condition(int cond)
{
	this->condition = cond;
}

int Cell::get_number() const
{
	return this->number;
}

int Cell::get_condition() const
{
	return this->condition;
}

