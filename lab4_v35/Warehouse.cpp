#include "Warehouse.h"
#include <iostream>

#define BASE_SIZE 10
Warehouse::Warehouse()
{
	map = new Warehouse_map(BASE_SIZE, BASE_SIZE, BASE_SIZE);
	this->cursor.x_length = 0;
	this->cursor.y_width = 0;
	this->temperature = 36.6f;
	this->length = BASE_SIZE;
	this->width = BASE_SIZE;
	this->height = BASE_SIZE;
}


Warehouse::Warehouse(int l, int w, int h, float temperature)
{
	if (l <= 0 || w <= 0 || h <= 0)
	{
		throw "Warehouse: Incorrect values specified";
	}
	else
	{
		this->length = l;
		this->width = w;
		this->height = h;
		this->temperature = temperature;

		map = new Warehouse_map(l, w, h);

		this->cursor.x_length = 0;
		this->cursor.y_width = 0;
	}
}

Warehouse::~Warehouse()
{
	for (unsigned int i = 0; i < this->racks.size(); i++)
	{
		delete this->racks[i];
	}

	delete map;
	//деструктор
}

void Warehouse::out_all_boxes(std::ostream& out) const
{
	for (unsigned int i = 0; i < this->racks.size(); i++)
	{
		out << "Rack number: " << i << std::endl;

		for (unsigned int j = 0; j < this->racks[i]->size(); j++)
		{
			
			out << "Box ID: " << this->racks[i]->box_rack[j]->ID << std::endl;
		}

		out << std::endl;
	}
}

bool Warehouse::put_box_auto(Box *box)
{
	Cool_box* cb_ptr = dynamic_cast<Cool_box*>(box);
	if (cb_ptr != nullptr && cb_ptr->get_temperature() > this->temperature) return false;
	
	//Попытка поместить коробку на стеллаж 
	for (unsigned int i = 0; i < racks.size(); i++)
	{
		if (racks[i]->put_box_auto(box))
		{
			box->ID = this->generate_ID();
			return true;
		}
	}
	
	//Поиск места и создание нового стеллажа
	unsigned int x = box->length;
	unsigned int y = box->width;
	unsigned int z = box->height;

	for (unsigned int i = 0; i < this->length; i++)
	{
		for (unsigned int j = 0; j < this->width; j++)
		{
			cursor.x_length = i;
			cursor.y_width = j;

			if (map->is_it_empty_here(cursor, x, y, z))
			{
				put_container_push_back(x, y, z, box, cursor);
				return true;
			}
			if (map->is_it_empty_here(cursor, y, x, z))
			{
				put_container_push_back(y, x, z, box, cursor);
				return true;
			}

			if (dynamic_cast<Fragile_box*>(box) != nullptr) continue;
			
			if (map->is_it_empty_here(cursor, y, z, x))
			{
				put_container_push_back(y, z, x, box, cursor);
				return true;
			}
			if (map->is_it_empty_here(cursor, z, y, x))
			{
				put_container_push_back(z, y, x, box, cursor);
				return true;
			}

			if (map->is_it_empty_here(cursor, x, z, y))
			{
				put_container_push_back(x, z, y, box, cursor);
				return true;
			}
			if (map->is_it_empty_here(cursor, z, x, y))
			{
				put_container_push_back(z, x, y, box, cursor);
				return true;
			}
		}
	}

	return false;
}

bool Warehouse::put_box_manual(Box* box, Cursor cursor)
{
	Cool_box* cb_ptr = dynamic_cast<Cool_box*>(box);
	if (cb_ptr != nullptr && cb_ptr->get_temperature() > this->temperature) return false;

	int index = this->who_is_there(cursor);

	if (index != -1)
	{
		if (this->racks[index]->put_box_auto(box))
		{
			box->ID = this->generate_ID();
			return true;
		}
		else return false;
	}

	unsigned int x = box->length;
	unsigned int y = box->width;
	unsigned int z = box->height;

	if (map->is_it_empty_here(cursor, x, y, z))
	{
		put_container_push_back(x, y, z, box, cursor);
		return true;
	}
	if (map->is_it_empty_here(cursor, y, x, z))
	{
		put_container_push_back(y, x, z, box, cursor);
		return true;
	}

	if (dynamic_cast<Fragile_box*>(box) != nullptr) return false;

	if (map->is_it_empty_here(cursor, y, z, x))
	{
		put_container_push_back(y, z, x, box, cursor);
		return true;
	}
	if (map->is_it_empty_here(cursor, z, y, x))
	{
		put_container_push_back(z, y, x, box, cursor);
		return true;
	}

	if (map->is_it_empty_here(cursor, x, z, y))
	{
		put_container_push_back(x, z, y, box, cursor);
		return true;
	}
	if (map->is_it_empty_here(cursor, z, x, y))
	{
		put_container_push_back(z, x, y, box, cursor);
		return true;
	}

	return false;
}

bool Warehouse::delete_box(int ID)
{
	for (unsigned int i = 0; i < this->racks.size(); i++)
	{
		for (unsigned int j = 0; j < this->racks[i]->size(); j++)
		{
			if (this->racks[i]->box_rack[j]->ID == ID)
			{
				this->racks[i]->delete_box(j); //вызов функции удаления

				if (this->racks[i]->size() == 0)
				{
					this->map->clear_place(this->racks[i]->placed_cursor, this->racks[i]->base_length, this->racks[i]->base_width);
					delete this->racks[i];
					this->racks.erase(this->racks.begin() + i);
				}

				return true;
			}
		}
	}
	return false;
}

bool Warehouse::move_box(int ID, Cursor cursor)
{
	Box* b_ptr;

	for (unsigned int i = 0; i < this->racks.size(); i++)
	{
		for (unsigned int j = 0; j < this->racks[i]->size(); j++)
		{
			if (this->racks[i]->box_rack[j]->ID == ID)
			{
				if (this->who_is_there(cursor) == i) return false; //Перемещение коробки на то же место где она была

				b_ptr = this->racks[i]->box_rack[j];

				if (this->put_box_manual(b_ptr, cursor))
				{
					this->racks[i]->box_rack[j] = nullptr;
					b_ptr->ID = ID;

					this->racks[i]->box_rack.erase(this->racks[i]->box_rack.begin() + j);
					if (this->racks[i]->box_rack.size() == 0)
					{
						this->map->clear_place(this->racks[i]->placed_cursor, this->racks[i]->base_length, this->racks[i]->base_width);

						delete this->racks[i];
						this->racks.erase(this->racks.begin() + i);
					}

					return true;
				}
				else
				{
					return false;
				}
				
			}
		}
	}


	return false;
}

int Warehouse::get_size() const
{
	int size = 0;

	for (unsigned int i = 0; i < this->racks.size(); i++)
	{
		size += this->racks[i]->size();
	}

	return size;
}

unsigned int Warehouse::generate_ID()
{
	return this->it_ID++;
}

int Warehouse::who_is_there(Cursor cursor)
{
	for (unsigned int i = 0; i < this->racks.size(); i++)
	{
		if ((cursor.x_length >= this->racks[i]->placed_cursor.x_length && cursor.x_length < this->racks[i]->placed_cursor.x_length + this->racks[i]->base_length) && (cursor.y_width >= this->racks[i]->placed_cursor.y_width && cursor.y_width < this->racks[i]->placed_cursor.y_width + this->racks[i]->base_width))
		{
			return i;
		}
	}
	return -1;
}

void Warehouse::put_container_push_back(unsigned int x, unsigned int y, unsigned int z, Box* box, Cursor cursor)
{
	box->set_all(x, y, z);
	this->racks.push_back(new Box_container(cursor, box, this->height));
	box->ID = this->generate_ID();
}

void Warehouse::map_out()
{
	this->map->map_out();
}
