#include "Lotto_card.h"
#include <cstdlib> 
#include <ctime>
#include <cmath>
#include <iostream>
#include <vector>

Lotto_card::Lotto_card()
{
	height = HEIGHT;
	generate_numbers();
}

Lotto_card::Lotto_card(const Lotto_card& obj)
{
	this->height = obj.height;

	for (int i = 0; i < height; i++)
	{
		for (int  j = 0; j < width; j++)
		{
			this->cells[i][j].set_condition(obj.cells[i][j].get_condition());
			this->cells[i][j].set_number(obj.cells[i][j].get_number());
		}
	}
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
					cells[h_i][w_j].set_number(generate_rand_num(h_i, w_j, uq_nums_arr, it_nums));
					cells[h_i][w_j].set_condition(FREE_NUMBER);

					--w_nums;
				}
			}
			else
			{
				cells[h_i][w_j].set_number(generate_rand_num(h_i, w_j, uq_nums_arr, it_nums));
				cells[h_i][w_j].set_condition(FREE_NUMBER);

				--w_nums;
			}

			if (w_nums <= 0) break;
		}
	}

	delete[] uq_nums_arr;
}

unsigned int Lotto_card::get_width() const
{
	return this->width;
}

unsigned int Lotto_card::get_height() const
{
	return this->height;
}

void Lotto_card::card_output(std::ostream& out) const
{
	if (this->height == 0)
	{
		out << "This card is empty!" << std::endl;
		return;
	}


	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (this->cells[i][j].get_condition() == FREE_NUMBER)
			{
				if (j == 0)
				{
					out << "[ " << this->cells[i][j].get_number() << "] ";
				}
				else out << "[" << this->cells[i][j].get_number() << "] ";

			}
			else if (this->cells[i][j].get_condition() == BUSY_NUMBER)
			{
				if (j == 0)
				{
					out << "< " << this->cells[i][j].get_number() << "> ";
				}
				else out << "<" << this->cells[i][j].get_number() << "> ";

			}
			else out << "[  ] ";
		}
		out << std::endl;
	}
	return;
}

void Lotto_card::put_keg(int keg)
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if ((cells[i][j].get_condition() == FREE_NUMBER) && (cells[i][j].get_number() == keg))
			{
				cells[i][j].set_condition(BUSY_NUMBER);
				return;
			}
			else if ((cells[i][j].get_condition() == BUSY_NUMBER) && (cells[i][j].get_number() == keg))
			{
				return;
			}
		}
	}
	return;
}

unsigned int Lotto_card::how_many_busy() const
{
	int many = 0;

	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (cells[i][j].get_condition() == BUSY_NUMBER)
			{
				many++;
			}
		}
	}

	return many;
}

Condition Lotto_card::is_cell_busy(int i, int j) const
{
	return cells[i][j].get_condition();
}

void Lotto_card::check_for_busy_lines()
{
	bool busy;

	for (int i = 0; i < this->height; i++)
	{
		busy = true;
		for (int j = 0; j < this->width; j++)
		{
			if (cells[i][j].get_condition() == FREE_NUMBER)
			{
				busy = false;
				break;
			}
		}

		if (busy) delete_busy_line(i);
	}
}

void Lotto_card::get_remained_numbers(std::vector<int>* array) const
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (cells[i][j].get_condition() == FREE_NUMBER)
			{
				array->push_back(cells[i][j].get_number());
			}
		}
	}
}

Lotto_card& Lotto_card::operator--(int)
{
	Lotto_card temp_lotto(*this);
	this->check_for_busy_lines();
	return temp_lotto;
}

Condition Lotto_card::operator()(int i, int j) const 
{
	return this->is_cell_busy(i, j);
}

void Lotto_card::operator()(int keg)
{
	this->put_keg(keg);
}

std::ostream& operator<< (std::ostream& out, const Lotto_card& lotto)
{
	lotto.card_output(out);
	return out;
}

std::istream& operator>> (std::istream& in, Lotto_card& lotto)
{
	int keg_num;
	in >> keg_num;

	if (in.good())
	{
		lotto.put_keg(keg_num);
	}
	else 
	{
		in.clear();
		in.ignore(in.rdbuf()->in_avail());
	}
		
	
	return in;
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
			cells[height_i][j].set_condition(cells[this->height - 1][j].get_condition());
			cells[height_i][j].set_number(cells[this->height - 1][j].get_number());
		}
		this->height--;
		return;
	}

	return;
}

unsigned int Lotto_card::generate_rand_num(int h_i, int w_j, int* uq_nums_arr, int& it_nums)
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

bool Lotto_card::check_unique_nums(int num, const int* arr, int size) const
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

