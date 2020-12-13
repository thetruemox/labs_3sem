#include "Box.h"

#define BASE_SIZE 1
Box::Box()
{
    this->length = BASE_SIZE;
    this->width = BASE_SIZE;
    this->height = BASE_SIZE;
    this->mass = BASE_SIZE;
}

Box::Box(int length, int width, int height, float mass)
{
    if ((!set_all(length, width, height)) || mass <= 0)
    {
        throw "Box: Incorrect values specified";
    }
    else 
    {
        this->mass = mass;
    }
}

Box::Box(const Box& box)
{
    this->length = box.length;
    this->width = box.width;
    this->height = box.height;
    this->mass = box.mass;
}

bool Box::set_all(int length, int width, int height)
{
    if (length <= 0 || width <= 0 || height <= 0)
    {
        return false;
    }
    else
    {
        this->length = length;
        this->width = width;
        this->height = height;
        return true;
    }
}
