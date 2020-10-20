#include <iostream>
#include "Loto_card.h"
using namespace std;



int main()
{
    Loto_card loto;
    loto.generate_numbers();

    for (int i = 0; i < 3; i++)
    {
        for (int j  = 0; j < 9; j++)
        {
            if (loto.cells[i][j]->get_condition() == 1)
            {
                cout << loto.cells[i][j]->get_number() << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    
  
    return 0;
}


    
