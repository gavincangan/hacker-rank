#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    uint32_t len_vec = 0;
    std::vector<uint32_t> my_vec;
    std::cin>>len_vec;
    uint32_t temp = 0;
    for(uint32_t i=0; i<len_vec; i++)
    {
        std::cin>> temp;
        my_vec.push_back(temp);
    }
    sort(my_vec.begin(), my_vec.end());
    for(auto tval : my_vec)
    {
        std::cout<<tval<<" ";
    }
    return 0;
}