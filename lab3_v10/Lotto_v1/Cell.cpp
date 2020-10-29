#include "Cell.h"

Cell::Cell()
{
	this->number = -1;
	condition = EMPTY;
}

void Cell::set_number(int num)
{
	this->number = num;
}

void Cell::set_condition(Condition cond)
{
	condition = cond;
}

int Cell::get_number() const
{
	return this->number;
}

Condition Cell::get_condition() const
{
	return this->condition;
}

