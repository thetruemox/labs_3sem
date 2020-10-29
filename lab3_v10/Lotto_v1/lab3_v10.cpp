#include <iostream>
#include "Loto_card.h"
#include <vector>
using namespace std;



int main()
{
    Lotto_card lotto;
    lotto.card_output();

    std::vector<int>* array = new std::vector<int>;

    lotto.get_remained_numbers(array);

    for (int i = 0; i < array->size(); i++)
    {
        cout << array->at(i) << " ";
    }

    return 0;
}


    
