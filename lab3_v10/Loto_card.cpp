#include "Loto_card.h"
#include <cstdlib> 
#include <ctime>
#include <cmath>
#include <iostream>
#include <vector>

Lotto_card::Lotto_card()
{
	height = HEIGHT;

	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			cells[i][j] = new Cell;
		}	
	}

	generate_numbers();
}


Lotto_card::~Lotto_card()
{
	//for (int i = 0; i < this->height; i++) delete[] cells[i];
	//delete[] cells;
}


void Lotto_card::generate_numbers()
{
	srand(time(NULL));

	int w_nums = 5; //����������� ���������� ����� ��� ��������� �� ���� ������	
	int unique_nums = this->height * w_nums; //���������� ���������� �����
	int* uq_nums_arr = new int[unique_nums]; //������ ���������� �����
	int it_nums = 0; //�������� ��� ������� ���������� �����

	for (int h_i = 0; h_i < this->height; h_i++)
	{
		w_nums = 5; 					
		for (int w_j = 0; w_j < this->width; w_j++)
		{
			if (w_nums < this->width - w_j)
			{
				if (rand() % 10 >= 5)
				{				
					cells[h_i][w_j]->set_number(generate_rand_num(h_i, w_j, uq_nums_arr, it_nums));
					cells[h_i][w_j]->set_condition(1);

					--w_nums;
				}
			}
			else
			{
				cells[h_i][w_j]->set_number(generate_rand_num(h_i, w_j, uq_nums_arr, it_nums));
				cells[h_i][w_j]->set_condition(1);

				--w_nums;
			}

			if (w_nums <= 0) break;
		}
	}

	delete[] uq_nums_arr;  
}

void Lotto_card::card_output() 
{
	if (this->height == 0)
	{
		std::cout << "This card is empty!" << std::endl;
		return;
	}

	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (cells[i][j]->get_condition() == 1)
			{
				if (j == 0)
				{
					std::cout << "[ " << cells[i][j]->get_number() << "] ";
				} else std::cout << "[" << cells[i][j]->get_number() << "] ";
				
			}
			else if (cells[i][j]->get_condition() == 2)
			{
				if (j == 0)
				{
					std::cout << "< " << cells[i][j]->get_number() << "> ";
				}
				else std::cout << "<" << cells[i][j]->get_number() << "> ";

			} else std::cout << "[  ] ";
		}
		std::cout << std::endl;
	}
}

void Lotto_card::put_keg(int keg)
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if ((cells[i][j]->get_condition() == 1) && (cells[i][j]->get_number() == keg))
			{
				cells[i][j]->set_condition(2);
				return;
			}
			else if ((cells[i][j]->get_condition() == 2) && (cells[i][j]->get_number() == keg))
			{
				//throw "This number already busy!";
				return;
			}
		}
	}
	//throw "There is no such number!";
	return;
}

bool Lotto_card::is_cell_busy(int i, int j)
{
	if (cells[i][j]->get_condition() == 2)
	{
		return true;
	} else return false;
}

void Lotto_card::check_for_busy_lines()
{
	bool busy;

	for (int i = 0; i < this->height; i++)
	{
		busy = true;
		for (int j = 0; j < this->width; j++)
		{
			if (cells[i][j]->get_condition() == 1)
			{
				busy = false;
				break;
			}
		}

		if (busy) delete_busy_line(i);
	}
}

std::vector<int>* Lotto_card::get_remained_numbers()
{
	std::vector<int>* array = new std::vector<int>;
	array->resize(this->height * 5);
	int it = 0;

	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (cells[i][j]->get_condition() == 1)
			{
				array->at(it) = cells[i][j]->get_number();
				it++;
			}
		}
	}

	array->resize(it);
	return array;
}

void Lotto_card::delete_busy_line(int height_i)
{
	if (height_i == this->height)
	{
		this->height--;
		return;
	}
	else
	{
		for (int j = 0; j < this->width; j++)
		{
			cells[height_i][j]->set_condition(cells[this->height - 1][j]->get_condition());
			cells[height_i][j]->set_number(cells[this->height - 1][j]->get_number());
		}
		this->height--;
		return;
	}

	return;
}

int Lotto_card::generate_rand_num(int h_i, int w_j, int* uq_nums_arr, int &it_nums)
{
	int rand_num;
	int power = 10; 

	while (height >= power) power *= 10; //�������� ����� ��� ����� ������ ����
	
	do
	{
		rand_num = rand() % power + power * w_j;

	} while (!check_unique_nums(rand_num, uq_nums_arr, it_nums));

	uq_nums_arr[it_nums] = rand_num;
	it_nums++;

	return rand_num;
}

bool Lotto_card::check_unique_nums(int num, int* arr, int size)
{
	if (size == 0) return true;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
		{
			return false;
		}
	}

	return true;
}


