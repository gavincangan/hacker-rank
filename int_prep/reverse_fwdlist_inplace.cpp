/*
Reverse a forward linked list in place
*/

#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> input_list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::forward_list<int>::iterator liter1, liter2;

    std::cout<<"Input list: ";
    for(int i:input_list)
        std::cout<<i<<" ";
    std::cout<<std::endl;

    liter1 = input_list.begin();

    liter2 = liter1;
    liter2++;

    while(1)
    {

        input_list.push_front( *liter2 );
        liter2 = input_list.erase_after( liter1 );

        // for(int i:input_list)
        //     std::cout<<i<<" ";
        // std::cout<<std::endl;

        if(liter2 == input_list.end())
        {
            // std::cout<<"\nEnd of procedure\n";
            break;
        }
        else
        {
            // std::cout<<"\nContinue iteration\n";
        }

        // std::cout<<'\n';
    }

    std::cout<<"Input list after reversing: ";
    for(int i:input_list)
        std::cout<<i<<" ";
    std::cout<<std::endl;
}