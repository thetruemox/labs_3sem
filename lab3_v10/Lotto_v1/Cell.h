#pragma once

class Cell
{
public:
	Cell();
	void set_number(int num);
	void set_condition(int cond);
	int get_number();
	int get_condition();
private:
	int number;
	int condition; //0 - ������, 1 - �������� � ������, 2 - ������ � ������
};


