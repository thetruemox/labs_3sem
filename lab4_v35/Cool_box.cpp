#include "Cool_box.h"

#define BASE_SIZE 1
Cool_box::Cool_box() : Box()
{
    this->temperature = BASE_SIZE;
}

Cool_box::Cool_box(const Cool_box& box) : Box(box)
{
    this->temperature = box.temperature;
}

Cool_box::Cool_box(int l, int w, int h, float mass, float temperature) : Box(l, w, h, mass)
{
    this->temperature = temperature;
}

Box* Cool_box::copy(Box* obj)
{
    Cool_box* ptr = dynamic_cast<Cool_box*>(obj);
    if (ptr == nullptr) return nullptr;

    Cool_box* copy_obj = new Cool_box;

    copy_obj->set_all(obj->get_length(), obj->get_width(), obj->get_height());
    copy_obj->set_ID(obj->get_ID());
    copy_obj->set_mass(obj->get_mass());
    copy_obj->set_temperature(ptr->get_temperature());

    return copy_obj;
}

float Cool_box::get_temperature() const
{
    return this->temperature;
}

void Cool_box::set_temperature(float t)
{
    this->temperature = t;
}

