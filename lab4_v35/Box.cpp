#include "Box.h"

Box::Box()
{
    this->length = 1;
    this->width = 1;
    this->height = 1;
    this->mass = 1;
}

Box::Box(int length, int width, int height, float mass)
{
    set_all(length, width, height);
    this->mass = mass;
}

void Box::set_all(int length, int width, int height)
{
    this->length = length;
    this->width = width;
    this->height = height;
}
