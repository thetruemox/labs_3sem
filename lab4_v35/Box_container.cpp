#include "Box_container.h"

Box_container::Box_container(Cursor cursor, int length, int width)
{
	this->placed_cursor = cursor;
	this->length = length;
	this->width = width;
	this->temp_height = 0;
}

void Box_container::put_box_in_stack(Box& box)
{
	//ѕроверка на давление и поверхность расположени€
	this->box_stacks.push_back(box);
}
