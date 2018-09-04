#include <iostream>
#include <vector>


int main()
{
    // std::vector<int, 8> sa;
    // sa.fill(3);

    // sa[3] = 5;

    // std::cout<< sa[3]<<std::endl;
    int arr_len;
    int temp = 0;
    std::cin >> arr_len;

    std::vector<int> arr_vec;

    for(int i=0; i<arr_len; i++)
    {
        std::cin >> temp;
        arr_vec.push_back( temp );
    }

    // for(int i=arr_vec.size()-1; i>=0; i--)
    // {
    //     std::cout<< arr_vec.at(i)<< " ";
    // }
    // std::cout<<std::endl;

    for (std::vector<int>::iterator it = arr_vec.begin() + 3; it!= arr_vec.end(); ++it){

        std::cout<<*it<<"->";
    }

    return(0);
}