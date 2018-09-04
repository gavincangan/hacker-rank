// https://www.hackerrank.com/challenges/cpp-maps/problem

#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>

int main()
{
    uint32_t num_queries = 0;

    std::map < std::string, uint32_t> stud_score;
    std::vector < uint32_t > res_vector;
    std::cin >> num_queries;

    std::string line_input;
    std::string tname;
    uint32_t tquery=0;
    uint32_t tscore=0;

    std::cin.sync();
    for(uint32_t i=0; i<num_queries; )
    {
        std::getline(std::cin, line_input); //>> tquery >> tval;
        if( ! line_input.empty() )
        {
            std::istringstream line_stream( line_input  );
            line_stream >> tquery >> tname;
            auto val_pos = stud_score.find(tname);
            //std::cout <<"\n"<<i<<"\t"<<tquery<<"\t"<<tname<<"\n";

            if(tquery > 0 && tquery < 4) i++;
            
            if(tquery == 1)
            {
                line_stream >> tscore;
                
                if( val_pos != stud_score.end() )
                {
                    stud_score[tname] += tscore;
                }
                else
                {
                    stud_score.insert( make_pair(tname, tscore) );
                }

            }
            else if(tquery == 2)
            {
                if( val_pos != stud_score.end() )
                {
                    stud_score.erase(val_pos);
                }
            }
            else if(tquery == 3)
            {
                //std::cout<<"\nQ3 :: "<<tname<<"\n";
                if( val_pos != stud_score.end() )
                {
                    //std::cout<<"\n"<<tname<<"\'s scores found!\n";
                    res_vector.push_back( stud_score[tname] );
                }
                else
                {
                    //std::cout<<"\n"<<tname<<"\'s scores NOT found!\n";
                    res_vector.push_back( 0 );
                }
            }
        }
        else
        {
            //std::cout<<"\nLine is empty!\t"<<line_input<<std::endl;
        }
    }
    //std::cout<<std::endl;
    for( auto s: res_vector)
    {
        std::cout << s << std::endl;
    }

    return 0;
}