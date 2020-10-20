#include "Loto_card.h"
#include <cstdlib> 
#include <ctime>
#include <cmath>

Loto_card::Loto_card()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			cells[i][j] = new Cell;
		}	
	}
}


Loto_card::~Loto_card()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			delete cells[i][j];
		}
	}
}


void Loto_card::generate_numbers()
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

int Loto_card::generate_r_num(int h_i, int w_j, int* uq_nums_arr, int &it_nums)
{
	int rand_num;
	int power = pow(10, 1 + this->height / 10); //диапазон чисел для одной ячейки лото

	do
	{
		rand_num = rand() % power + power * w_j;

	} while (!check_nums(rand_num, uq_nums_arr, it_nums));

	uq_nums_arr[it_nums] = rand_num;
	it_nums++;

	return rand_num;
}


bool Loto_card::check_nums(int num, int* arr, int size)
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


