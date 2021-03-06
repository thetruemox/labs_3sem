#include "Box.h"

#define BASE_SIZE 1
Box::Box()
{
    this->length = BASE_SIZE;
    this->width = BASE_SIZE;
    this->height = BASE_SIZE;
    this->mass = BASE_SIZE;
    this->ID = 0;
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
        this->ID = 0;
    }
}

Box::Box(const Box& box)
{
    this->length = box.length;
    this->width = box.width;
    this->height = box.height;
    this->mass = box.mass;
    this->ID = box.ID;
}

Box* Box::copy(Box* obj)
{
    Box* copy_obj = new Box;

    copy_obj->set_all(obj->get_length(), obj->get_width(), obj->get_height());
    copy_obj->ID = obj->ID;
    copy_obj->mass = obj->mass;

    return copy_obj;
}

unsigned int Box::get_ID()
{
    return this->ID;
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
