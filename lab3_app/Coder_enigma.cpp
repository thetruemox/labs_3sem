#include "Coder_enigma.h"


Coder_enigma::~Coder_enigma()
{
	clear_en_num();
}

bool Coder_enigma::en_code()
{
	if (de_str.size() == 0) return false;

	this->clear_en_num();

	for (int i = 0; i < de_str.size(); i++)
	{
		en_num.push_back(new Lab3::Number((int)de_str[i]));
	}

	return true;
}

void Coder_enigma::enter_text_line(std::string str)
{
	this->de_str = str;
}

void Coder_enigma::enter_num_arr(std::string num)
{
	if (num.size() % 2 != 0) throw "enter_num_arr: Invalid input!";

	this->clear_en_num();

	char temp[3];

	for (int i = 0; i < num.size(); i += 2)
	{
		temp[0] = num[i];
		temp[1] = num[i + 1];
		temp[2] = '\0';
		this->en_num.push_back(new Lab3::Number(temp));
	}
}

void Coder_enigma::f_read_decoded(std::string file_name)
{
	std::ifstream fin(file_name);
	if (!fin.is_open()) throw "f_read_decoded: There is no such file!";

	std::string buff;
	this->de_str = "";

	do
	{
		buff = "\0";
		fin >> buff;

		if (buff == "\0") break;

		this->de_str += buff;
		this->de_str += " ";
	} while (buff != "\0");

	fin.close();
}

void Coder_enigma::f_read_encoded(std::string file_name)
{
	std::ifstream fin(file_name);
	if (!fin.is_open()) throw "f_read_encoded: There is no such file!";

	std::string buff;
	char temp[3];

	fin >> buff;

	if (buff.size() % 2 != 0) throw "f_read_encoded: Invalid input!";

	this->clear_en_num();

	for (int i = 0; i < buff.size(); i += 2)
	{
		temp[0] = buff[i];
		temp[1] = buff[i + 1];
		temp[2] = '\0';
		this->en_num.push_back(new Lab3::Number(temp));
	}

	fin.close();
}

void Coder_enigma::out_de_str(std::ostream& out)
{
	if (de_str.size() != 0)
	{
		out << de_str;
	}
}

void Coder_enigma::out_en_num(std::ostream& out)
{
	for (int i = 0; i < en_num.size(); i++)
	{
		out << *en_num[i];
	}
}

void Coder_enigma::f_out_de_str(std::string file_name)
{
	std::ofstream fout(file_name, std::ofstream::out | std::ofstream::trunc);
	if (!fout.is_open()) throw "f_out_de_str: There is no such file!";

	out_de_str(fout);

	fout.close();
}

void Coder_enigma::f_out_en_num(std::string file_name)
{
	std::ofstream fout(file_name, std::ofstream::out | std::ofstream::trunc);
	if (!fout.is_open()) throw "f_out_de_str: There is no such file!";

	out_en_num(fout);

	fout.close();
}

void Coder_enigma::clear_en_num()
{
	for (int i = 0; i < en_num.size(); i++)
	{
		delete en_num[i];
	}
	this->en_num.resize(0);
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