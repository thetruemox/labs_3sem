#include <iostream>
#include "Loto_card.h"
using namespace std;



int main()
{
    Lotto_card lotto;
    lotto.generate_numbers();

    lotto.card_output();

    int keg;
    while (true)
    {
        std::cout << "keg num: ";
        std::cin >> keg;
   
        lotto.put_keg(keg);
        std::cout << std::endl << std::endl;

        lotto.card_output();
    }

    
  
    return 0;
}


    
