#include <iostream>
#include <limits>
#include <cstddef>
#include <vector>
#include<array>

int main()
{
    uint32_t num_arrays, num_queries;
    uint32_t temp = 0;
    std::cin >> num_arrays >>num_queries;

    std::vector< std::vector<uint32_t> > array_vec;
    std::vector< std::array<uint32_t, 2> > query_vec;

    // std::cout<<"\nA "<< num_arrays <<"\nQ " << num_queries<< std::endl;

    for(uint32_t i=0; i<num_arrays; i++)
    {
        bool is_first_entry = true;
        uint32_t count_num = 0;
        uint32_t tlen = std::numeric_limits<uint16_t>::max();
        std::vector<uint32_t> tvec;

        while( std::cin >> temp ) 
        {
            if( is_first_entry )
            {
                is_first_entry = false;
                tlen = temp;
                // std::cout<<"Length: "<<tlen << std::endl;
            }
            else
            {
                // std::cout << temp <<" # ";
                tvec.push_back( temp );
                // std::cout<< "Pushed :"<< temp << std::endl;;
                count_num++;
            }
            if( count_num >= tlen )
                break;
        }

        array_vec.push_back(tvec);

        // std::cout<<"\n array_num# "<<i<<std::endl;
    }

    uint32_t iix, jix;
    uint16_t len_outer_vector = array_vec.size();

    for(uint32_t i=0; i<num_queries; i++)
    {
        // query_vec[i][0] = iix;
        // query_vec[i][1] = jix;
        std::array<uint32_t, 2> tarr;

        std::cin>> tarr[0] >> tarr[1];

        query_vec.push_back(tarr);
    }
    
    std::vector<uint32_t> tvec;
    for(uint32_t i=0; i<num_queries; i++)
    {
        iix = query_vec.at(i)[0]; // % len_outer_vector;        
        tvec = array_vec[iix];

        jix = query_vec.at(i)[1]; // % tvec.size();

        std::cout<< tvec[jix]<<"\n";
    }

    std::cout<<std::endl;

    return(0);
}