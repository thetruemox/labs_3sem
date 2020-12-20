#pragma once
#include "Number.hpp"
#include <string>
#include <vector>
#include <fstream>

class Coder_enigma
{
public:
	~Coder_enigma();

	void enter_text_line(std::string str);
	void enter_num_arr(std::string num);

	void f_read_decoded(std::string file_name);
	void f_read_encoded(std::string file_name);

	bool en_code();
	bool de_code();

	void out_de_str(std::ostream& out);
	void out_en_num(std::ostream& out);

	void f_out_de_str(std::string file_name);
	void f_out_en_num(std::string file_name);

private:
	void clear_en_num();

	std::string de_str;
	std::vector<Lab3::Number*> en_num;

};

