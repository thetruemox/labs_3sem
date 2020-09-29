#include "Reading.h"
#include <iostream>

float read_poz()
{
	float temp;
	std::cin >> temp;

	while (!std::cin.good() || temp <= 0)
	{
		std::cout << std::endl << "Invalid input, try again" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> temp;
	}

	return temp;
}

float read_r()
{
	float temp;
	std::cin >> temp;

	while (!std::cin.good())
	{
		std::cout << std::endl << "Invalid input, try again" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> temp;
	}

	return temp;
}