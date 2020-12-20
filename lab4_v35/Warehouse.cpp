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
	for (int i = 0; i < this->racks.size(); i++)
	{
		delete this->racks[i];
	}

	delete map;
	//����������
}

bool Warehouse::put_box(Box *box)
{
	Cool_box* cb_ptr = dynamic_cast<Cool_box*>(box);
	if (cb_ptr != nullptr && cb_ptr->get_temperature() > this->temperature) return false;
	
	//������� ��������� ������� �� ������� 
	for (int i = 0; i < racks.size(); i++)
	{
		if (racks[i]->put_box(box))
		{
			box->ID = this->get_size();
			return true;
		}
	}

	//����� ����� � �������� ������ ��������
	unsigned int x = box->length;
	unsigned int y = box->width;
	unsigned int z = box->height;

	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			cursor.x_length = i;
			cursor.y_width = j;

			if (map->is_it_empty_here(cursor, x, y, z))
			{
				box->set_all(x, y, z);
				box->ID = this->get_size();
				this->racks.push_back(new Box_container(cursor, box, this->height));
				return true;
			}
			if (map->is_it_empty_here(cursor, y, x, z))
			{
				box->set_all(y, x, z);
				box->ID = this->get_size();
				this->racks.push_back(new Box_container(cursor, box, this->height));
				return true;
			}

			if (dynamic_cast<Fragile_box*>(box) != nullptr) continue;
			
			if (map->is_it_empty_here(cursor, y, z, x))
			{
				box->set_all(y, z, x);
				box->ID = this->get_size();
				this->racks.push_back(new Box_container(cursor, box, this->height));
				return true;
			}
			if (map->is_it_empty_here(cursor, z, y, x))
			{
				box->set_all(z, y, x);
				box->ID = this->get_size();
				this->racks.push_back(new Box_container(cursor, box, this->height));
				return true;
			}

			if (map->is_it_empty_here(cursor, x, z, y))
			{
				box->set_all(x, z, y);
				box->ID = this->get_size();
				this->racks.push_back(new Box_container(cursor, box, this->height));
				return true;
			}
			if (map->is_it_empty_here(cursor, z, x, y))
			{
				box->set_all(z, x, y);
				box->ID = this->get_size();
				this->racks.push_back(new Box_container(cursor, box, this->height));
				return true;
			}
		}
	}

	return false;
}

int Warehouse::get_size()
{
	int size = 0;

	for (int i = 0; i < this->racks.size(); i++)
	{
		size += this->racks[i]->size();
	}

	return size;
}

void Warehouse::map_out()
{
	this->map->map_out();
}
