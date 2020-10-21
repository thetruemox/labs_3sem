#include <iostream>
#include "Loto_card.h"
#include <vector>
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
        
        if (keg == 0) break;
        

        lotto.put_keg(keg);
        std::cout << std::endl << std::endl;

        lotto.check_for_busy_lines();
        lotto.card_output();
    }

    std::vector<int>* array = lotto.get_remained_numbers();
    
    cout << endl;

    for (auto const& element : *array)
        std::cout << element << ' ';
  
    return 0;
}


    
