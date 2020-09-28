#include "Nikomed.h"
#include <iostream>
#include <cmath>

Nikomed::Nikomed(float a, float l)
{
	this->a = a;
	this->l = l;
}

float Nikomed::get_a()
{
	return this->a;
}

void Nikomed::set_a(float a)
{
	this->a = a;
}

float Nikomed::get_l()
{
	return this->l;
}

void Nikomed::set_l(float l)
{	
	this->l = l;
}

int Nikomed::get_descartes_y(float x, float* res)
{
    float acos_arg = (x - a) / l;
    float angle;

    if (acos_arg > 1 || acos_arg < -1)
    {       
        return -1;
    }
    else
    {
        angle = acos(acos_arg);
        float y = a * tan(angle) + l * sin(angle);
        *res = y;
        return 0;
    }
}

int Nikomed::get_polar_r(float angle, float* res)
{
    if (cos(angle) == 0)
    {
        return -1;
    }
    else
    {
        *res = a / cos(angle);
        return 0;
    }
}

