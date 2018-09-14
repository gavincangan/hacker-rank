/*
Reverse a forward linked list in place
*/

#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> input_list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::forward_list<int>::iterator liter1, liter2;

    liter1 = input_list.begin();
    liter1 = std::next(liter1);

    liter2 = input_list.begin();
    liter2 = std::next(liter1);

    while(1)
    {

    }
}