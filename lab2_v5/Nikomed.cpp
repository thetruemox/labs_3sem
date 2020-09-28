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
        *res = a / cos(angle) + l;
        return 0;
    }
}

int Nikomed::get_curve_r(float* arr_res)
{
    arr_res[0] = pow((l + a), 2) / l;
    arr_res[1] = pow((l - a), 2) / l;
    arr_res[2] = ( l * sqrt(pow(l, 2) - pow(a, 2)) ) / (2 * a);

    return 0;
}

int Nikomed::get_circle_area(float* res)
{
    float sqrt_arg = pow(l, 2) - pow(a, 2);
    if (sqrt_arg < 0) return -1;
    
    float ln_arg = (l + sqrt(sqrt_arg)) / a;
    if (ln_arg <= 0) return -1;
    
    float acos_arg = a / l;
    if (acos_arg > 1 || acos_arg < -1) return -1;
    
    *res = a * sqrt(sqrt_arg) - 2 * a * l * log(ln_arg) + pow(l, 2) * acos(acos_arg);

    return 0;
}

