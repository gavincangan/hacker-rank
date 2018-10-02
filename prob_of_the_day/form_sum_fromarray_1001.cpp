/*
Given an array of N integers and another integer P, find 4 integers in the array that sum up exactly to P. 
If four such integers don't exist return false.
*/

#include <bits/stdc++.h>
#include <numeric>
#include <assert.h>

std::vector<int>::iterator arrayBinarySearch_ltP( std::vector<int>::iterator start_iter, std::vector<int>::iterator end_iter, const int& p )
{
    auto mid = start_iter + std::distance( start_iter, end_iter )/2;
    // std::cout<<"Mid: "<<*mid<<"\t"<<*start_iter<<' '<<*end_iter<<std::endl;
    if(*mid > p)
    {
        if( *(mid-1) < p )
        {
            // std::cout<<"Found p: "<< *mid<<' '<< *(mid-1) <<std::endl;
            return (mid-1);
        }
        else
        {
            return arrayBinarySearch_ltP( start_iter, mid, p );
        }
    }
    else if( *mid < p )
    {
        return arrayBinarySearch_ltP( mid, end_iter, p );
    }
    else if( *mid == p )
    {
        return (mid-1);
    }
    return start_iter;
}

// std::vector<int> sumSubArray( std::vector<int> arr, const int& p )
// {
//     std::sort(arr.begin(), arr.end());

//     for(auto i: arr )
//     {
//         std::cout<<i<<" ";
//     }
//     std::cout<<'\t'<<p<<std::endl;

//     std::vector<int>::iterator start_iter; // = arr.begin();

//     auto end_iter = arrayBinarySearch_ltP( arr.begin(), arr.end(), p );

//     bool found = false;
//     std::vector<int> resvect;
//     int curr_sum = 0;
//     size_t arr_length = 0;

//     while(!found)
//     {
//         if( end_iter == arr.begin() )
//             break;

//         curr_sum = *end_iter;
//         start_iter = arr.begin();
//         arr_length = 1;
//         resvect.clear();
//         resvect.push_back(*end_iter);

//         std::cout<<"S: "<< *start_iter <<" E: "<< *end_iter <<std::endl;

//         while( start_iter < end_iter && arr_length < 4 )
//         {
//             if(*start_iter <= p - curr_sum)
//             {
//                 curr_sum += *start_iter;
//                 arr_length++;
//                 resvect.push_back(*start_iter);
//             }

//             std::cout<<"\tS: "<< *start_iter <<" E: "<< *end_iter<< " -- " << curr_sum <<" | "<< arr_length <<std::endl;

//             if( curr_sum == p && arr_length == 4 )
//             {
//                 found = true;
//                 break;
//             }

//             start_iter++;
//         }

//         if(found)
//         {
//             break;
//         }
//         else
//         {
//             end_iter--;
//         }
//     }

//     return resvect;
// }

std::vector<int> recSubArray( std::vector<int>::iterator start, std::vector<int>::iterator end, const int& p, size_t index=0 )
{
    static std::vector<int> sumArray(4, 0);

    
}


std::vector<int> sumSubArray( std::vector<int> arr, const int& p )
{
    std::sort(arr.begin(), arr.end());

    for(auto i: arr )
    {
        std::cout<<i<<" ";
    }
    std::cout<<'\t'<<p<<std::endl;

    std::vector<int>::iterator start_iter; // = arr.begin();

    auto end_iter = arrayBinarySearch_ltP( arr.begin(), arr.end(), p );



}

int main()
{
    std::vector<int> arr = { 15, 19, 29, 55, 47, 12, 37, 11, 13, 9, 31, 17, 18, 16, 10, 5, 33 };

    int p = 47;

    auto output_subarray = sumSubArray( arr, p );

    if( output_subarray.size() == 4 )
    {
        for( auto i: output_subarray)
        {
            std::cout<<i<<" >> ";
        }
        std::cout<<std::endl;

        assert( std::accumulate( output_subarray.begin(), output_subarray.end(), 0 ) == p );
    }
    else
    {
        std::cout<<"Not found!"<<" "<< output_subarray.size() <<std::endl;
    }

    return 0;
}

