#include "Cursor.h"

Cursor::Cursor()
{
	x_length = 0;
	y_width = 0;
}

Cursor::Cursor(unsigned int x, unsigned int y)
{
	x_length = x;
	y_width = y;
}

Cursor& Cursor::operator=(const Cursor& obj)
{
	if (this == &obj) return *this;

	this->x_length = obj.x_length;
	this->y_width = obj.y_width;

	return *this;
}
