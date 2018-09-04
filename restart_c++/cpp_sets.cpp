//https://www.hackerrank.com/challenges/cpp-sets/problem

#include <iostream>
#include <set>
#include <vector>

int main()
{
    uint32_t num_queries = 0;

    uint32_t tquery, tval = 0;
    std::set <uint32_t> myset;

    std::vector < std::string > res_vector;

    std::string yes_str = "Yes";
    std::string no_str = "No";

    std::cin >> num_queries;
    // std::cout<< "Number of queries: " << num_queries << std::endl;

    for(uint32_t i=0; i<num_queries; i++)
    {
        std::cin >> tquery >> tval;
        if(tquery == 3)
        {
            auto val_pos = myset.find(tval);
            if( val_pos != myset.end() )
            {
                res_vector.push_back(yes_str);

            }
            else
            {
                res_vector.push_back(no_str);
            }
        }
        else if(tquery == 1)
        {
            myset.insert(tval);
        }
        else if(tquery == 2)
        {
            myset.erase(tval);
        }
    }

    for( auto s: res_vector)
    {
        std::cout << s << std::endl;
    }

    return 0;
}


