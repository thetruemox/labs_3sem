#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include "Number.hpp"


class Coder_enigma
{
public:
	~Coder_enigma();

	void enter_text_line(string str);
	void enter_num_arr(vector<Lab3::Number*> en_num);

	void f_read_decoded(string file_name);
	void f_read_encoded(string file_name);

	bool en_code();
	bool de_code();
	
	void out_de_str();
	void out_en_num();

private:
	string de_str;
	vector<Lab3::Number*> en_num;
	
};

int main()
{
	Coder_enigma coder;
	
	int choice;

	/*
	while (true)
	{
		cout << "1. enter_text_line \n2. enter_num_arr";
	}
	*/

	return 0;
}

Coder_enigma::~Coder_enigma()
{
	for (int i = 0; i < en_num.size(); i++)
	{
		delete en_num[i];
	}
}

bool Coder_enigma::en_code()
{
	if (de_str.size() == 0) return false;

	en_num.clear();

	for (int i = 0; i < de_str.size(); i++)
	{
		en_num.push_back(new Lab3::Number((int)de_str[i]));
	}

	return true;
}

void Coder_enigma::enter_text_line(string str)
{
	this->de_str = str;
}

void Coder_enigma::enter_num_arr(vector<Lab3::Number*> en_num)
{
	this->en_num = en_num;
}

void Coder_enigma::f_read_decoded(string file_name)
{
	ifstream fin(file_name);
	if (!fin.is_open())
	{
		cout << "there is no such file!";
		return;
	}
	string buff;
	this->de_str = "";

	do
	{
		buff = "\0";
		fin >> buff;
		this->de_str += buff;
		this->de_str += " ";
	} while (buff != "\0");

	fin.close();
}

void Coder_enigma::f_read_encoded(string file_name)
{
	ifstream fin(file_name);
	if (!fin.is_open())
	{
		cout << "there is no such file!";
		return;
	}

	string buff;
	char temp[3];

	fin >> buff;
	
	if (buff.size() % 2 != 0)
	{
		cout << "Invalid input";
		return;
	}

	for (int i = 0; i < buff.size(); i+=2)
	{
		temp[0] = buff[i];
		temp[1] = buff[i + 1];
		temp[2] = '\0';
		this->en_num.push_back(new Lab3::Number(temp));
	}
	
	fin.close();
}

void Coder_enigma::out_de_str()
{
	if (de_str.size() != 0)
	{
		cout << de_str;
	}
}

void Coder_enigma::out_en_num()
{
	for (int i = 0; i < en_num.size(); i++)
	{
		cout << *en_num[i];
	}
}

bool Coder_enigma::de_code()
{
	if (en_num.size() == 0) return false;
	
	de_str = "";

	Lab3::Number* num_16;

	char* num_ptr;
	int num_10 = 0;
	int t_num;
	int power;

	for (int i = 0; i < en_num.size(); i++)
	{
		num_16 = en_num.at(i);
		num_ptr = num_16->getArray();
		num_10 = 0;
		power = num_16->getLength() - 1;

		for (int j = 1; j <= num_16->getLength(); j++)
		{
			switch (num_ptr[j])
			{
			case 'a':
				t_num = 10;
				break;
			case 'b':
				t_num = 11;
				break;
			case 'c':
				t_num = 12;
				break;
			case 'd':
				t_num = 13;
				break;
			case 'e':
				t_num = 14;
				break;
			case 'f':
				t_num = 15;
				break;
			default:
				t_num = (int)num_ptr[j] - 48;
				break;
			}
			num_10 += pow(16, power) * t_num;
			power--;
		}

		de_str += (char)num_10;
	}

	return true;
}






