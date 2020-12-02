#include "Box_container.h"

Box_container::Box_container(Cursor cursor, int length, int width)
{
	this->placed_cursor = cursor;
	this->length = length;
	this->width = width;
	this->temp_height = 0;
}
