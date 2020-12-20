#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include "Coder_enigma.h"



int main()
{
	Coder_enigma coder;
	string file_name = "test.txt";
	int choice;

	while (true)
	{
		cout << "1. Encode text in file\n2. Decode text in file\n3. Out_de_str\n4. Out_en_num\n5. Exit" << endl;
		cout << "Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			try
			{
				coder.f_read_decoded(file_name);
				coder.en_code();
				coder.f_out_en_num(file_name);
			}
			catch (const char* err)
			{
				cerr << err;
			}
			
			break;
		case 2:
			try
			{
				coder.f_read_encoded(file_name);
				coder.de_code();
				coder.f_out_de_str(file_name);
			}
			catch (const char* err)
			{
				cerr << err;
			}
			
			break;
		case 3:
			coder.out_de_str(cout);
			cout << endl;
			break;
		case 4:
			coder.out_en_num(cout);
			cout << endl;
			break;
		case 5:
			return 0;
		default:
			return 0;
		}
	}
	

	return 0;
}







