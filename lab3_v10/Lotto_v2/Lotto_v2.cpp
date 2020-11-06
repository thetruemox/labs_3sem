#include <iostream>
#include "Lotto_card.h"
#include <vector>
using namespace std;



int main()
{
    Lotto_card lotto;
    int choice;

    do
    {
        cout << "1. put_keg\n2. check_for_busy_lines\n3. lotto_out\n4. end my life" << endl;

        cin >> choice;
        if (!cin.good())
        {
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }          

        switch (choice)
        {
        case 1:
            cin >> lotto;
            break;
        case 2:
            lotto--;
            break;
        case 3:
            cout << lotto;
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "i dont know such command" << endl;
            break;
        }

    } while (true);
    

    return 0;
}


