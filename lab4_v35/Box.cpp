#include "Box.h"

Box::Box()
{
    this->length = 1;
    this->width = 1;
    this->height = 1;
    this->type = DEFAULT;
}

Box::Box(int l, int w, int h)
{
    if (l > 0)
    {
        this->length = l;
    }
    else this->length = 1;

    if (w > 0)
    {
        this->width = w;
    }
    else this->width = 1;

    if (h > 0)
    {
        this->height = h;
    }
    else this->height = 1;

    this->type = DEFAULT;
}

int Box::get_box_number() const
{
    return this->box_number;
}

float Box::get_price() const
{
    return this->price;
}

float Box::get_mass() const
{
    return this->mass;
}

void Box::get_customer_name(std::string& name) const
{
    name = this->customer_name;
}

int Box::get_length() const
{
    return this->length;
}

int Box::get_width() const
{
    return this->width;
}

int Box::get_height() const
{
    return this->height;
}

Type Box::get_type() const
{
    return this->type;
}

void Box::set_box_number(int num)
{
    this->box_number = num;
}

void Box::set_price(float price)
{
    if (price >= 0)
    {
        this->price = price;
    }
}

void Box::set_mass(float mass)
{
    if (mass > 0)
    {
        this->mass = mass;
    }   
}

void Box::set_customer_name(std::string name)
{
    if (!name.empty())
    {
        this->customer_name = name;
    }
}
