#include<iostream>

int fourthBit(int num) {
    return ( (((uint32_t)num) >> 3) & (uint32_t)0x00000001 );
}

int main()
{
    int a = 32;
    std::cout<<fourthBit(a)<<"\n\n"<<std::endl;
}