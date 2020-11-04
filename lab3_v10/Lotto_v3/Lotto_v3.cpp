#include <iostream>
#include "Lotto_card.h"
#include <vector>
using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    Lotto_card lotto(3);

    int choice;

    do
    {
        cout << "1. put_keg\n2. check_for_busy_lines\n3. lotto_out\n4. end my life" << endl;

        cin >> choice;

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

    _CrtDumpMemoryLeaks();
    return 0;
}
