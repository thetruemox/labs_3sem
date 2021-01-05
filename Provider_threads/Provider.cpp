#include "Provider.h"

void Provider::add_box()
{
	if (this->warehouse == nullptr) return;

	srand(time(0));

	Box* box;
	int ID;

	switch (rand_num(1, 4))
	{
	case 1:
		box = new Box(rand_num(1, MAX_BOX_SIZE), rand_num(1, MAX_BOX_SIZE), rand_num(1, MAX_BOX_SIZE), rand_num(1, MAX_BOX_MASS));
		ID = this->warehouse->put_box_auto(box);
		if (ID != -1) this->id_arr.push_back(ID);
		delete box;
		break;
	case 2:
		box = new Cool_box(rand_num(1, MAX_BOX_SIZE), rand_num(1, MAX_BOX_SIZE), rand_num(1, MAX_BOX_SIZE), rand_num(1, MAX_BOX_MASS), rand_num(MIN_TEMPERATURE, MAX_TEMPERATURE));
		ID = this->warehouse->put_box_auto(box);
		if (ID != -1) this->id_arr.push_back(ID);
		delete box;
		break;
	case 3:
		box = new Fragile_box(rand_num(1, MAX_BOX_SIZE), rand_num(1, MAX_BOX_SIZE), rand_num(1, MAX_BOX_SIZE), rand_num(1, MAX_BOX_MASS), rand_num(1, MAX_PRESSURE));
		ID = this->warehouse->put_box_auto(box);
		if (ID != -1) this->id_arr.push_back(ID);
		delete box;
		break;
	case 4:
		box = new Fragile_cool_box(rand_num(1, MAX_BOX_SIZE), rand_num(1, MAX_BOX_SIZE), rand_num(1, MAX_BOX_SIZE), rand_num(1, MAX_BOX_MASS), rand_num(MIN_TEMPERATURE, MAX_TEMPERATURE), rand_num(1, MAX_PRESSURE));
		ID = this->warehouse->put_box_auto(box);
		if (ID != -1) this->id_arr.push_back(ID);
		delete box;
		break;
	default:
		break;
	}
}

void Provider::delete_box()
{
	if (this->id_arr.size() == 0) return;
	
	srand(time(0));

	int index = this->rand_num(0, this->id_arr.size() - 1);
	if (this->warehouse->delete_box(this->id_arr[index]))
	{
		this->id_arr.erase(this->id_arr.begin() + index);
	}
}


int Provider::rand_num(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
