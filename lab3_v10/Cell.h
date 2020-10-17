#pragma once

class Cell
{
public:
	Cell();
	Cell(int number);
private:
	int number;
	int condition; //0 - пустая, 1 - свободно с числом, 2 - занято с числом
};


