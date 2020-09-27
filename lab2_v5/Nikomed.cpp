#include "Nikomed.h"
#include <iostream>

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

