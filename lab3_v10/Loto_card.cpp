#include "Loto_card.h"
#include <cstdlib> 
#include <ctime>
#include <cmath>
#include <iostream>

Lotto_card::Lotto_card()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			cells[i][j] = new Cell;
		}	
	}
}


Lotto_card::~Lotto_card()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			delete cells[i][j];
		}
	}
}


void Lotto_card::generate_numbers()
{
	srand(time(NULL));

	int w_nums = 5; //необходимое количество чисел для генерации на одну строку	
	int unique_nums = this->height * w_nums; //количество уникальных чисел
	int* uq_nums_arr = new int[unique_nums]; //массив уникальных чисел
	int it_nums = 0; //итератор для массива уникальных чисел

	for (int h_i = 0; h_i < this->height; h_i++)
	{
		w_nums = 5; 					
		for (int w_j = 0; w_j < this->width; w_j++)
		{
			if (w_nums < this->width - w_j)
			{
				if (rand() % 10 >= 5)
				{				
					cells[h_i][w_j]->set_number(generate_r_num(h_i, w_j, uq_nums_arr, it_nums));
					cells[h_i][w_j]->set_condition(1);

					--w_nums;
				}
			}
			else
			{
				cells[h_i][w_j]->set_number(generate_r_num(h_i, w_j, uq_nums_arr, it_nums));
				cells[h_i][w_j]->set_condition(1);

				--w_nums;
			}

			if (w_nums <= 0) break;
		}
	}

	delete[] uq_nums_arr;  
}

void Lotto_card::card_output() //дополнить вывод если поставлен бочонок 
{
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

int Lotto_card::generate_r_num(int h_i, int w_j, int* uq_nums_arr, int &it_nums)
{
	int rand_num;
	int power = 10; 

	while (height >= power) power *= 10; //диапазон чисел для одной ячейки лото
	
	do
	{
		rand_num = rand() % power + power * w_j;

	} while (!check_nums(rand_num, uq_nums_arr, it_nums));

	uq_nums_arr[it_nums] = rand_num;
	it_nums++;

	return rand_num;
}


bool Lotto_card::check_nums(int num, int* arr, int size)
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


