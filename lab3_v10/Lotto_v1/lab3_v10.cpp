#include <iostream>
#include "Loto_card.h"
#include <vector>
using namespace std;



int main()
{
    Lotto_card lotto;
    lotto.card_output();

    int temp = 0;

    while (temp != -1)
    {
        lotto.card_output();
        
        cin >> temp;
        lotto.put_keg(temp);
    }
    
    lotto.check_for_busy_lines();
    lotto.card_output();


    return 0;
}


    
