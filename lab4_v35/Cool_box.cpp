#include "Cool_box.h"


Cool_box::Cool_box() : Box()
{
    this->temperature = 36.6f;
}

Cool_box::Cool_box(int l, int w, int h, float mass, float temperature) : Box(l, w, h, mass)
{
    this->temperature = temperature;
}

