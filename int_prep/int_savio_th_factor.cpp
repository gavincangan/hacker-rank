/*
Find the pth factor of n
Eg: 3 rd factor of 20 would be 4
20 --> 1, 2, 4, 5, 10, 20
3rd (1 indexing) ==> 4
*/
#include<iostream>

int main()
{
    uint64_t input_num = 0, factor_ix = 0, num_factors=0, ix = 1;
    bool factor_found = false;
    std::cin>>input_num>>factor_ix;
    // std::cout<<"\nInput number: "<<input_num<<"\nFactor index: "<<factor_ix<<std::endl;
    for(; ix < input_num; ix++)
    {
        // std::cout<<"\n"<<ix;
        if(input_num % ix == 0)
        {
            // std::cout<<"\t"<<ix;
            num_factors++;
        }
        if(num_factors == factor_ix)
        {
            factor_found = true;
            break;
        }
    }
    // std::cout<<std::endl;
    if(factor_found)
    {
        std::cout<<ix<<std::endl;
    }
    else
    {
        std::cout<<0<<std::endl;
    }
    
}