/*
Given a string, find the largest palindrome on the given string
*/

#include <bits/stdc++.h>

size_t check_palindrome( std::string& le_string, std::string::iterator siter, bool is_odd )
{
    std::string::iterator siter_rev;
    size_t plen = 0;
    if(is_odd)
    {
        siter_rev = siter - 2;
        plen = 1;
    }
    else
    {
        siter_rev = siter - 1;
        plen = 0;
    }
    while( siter != le_string.end() && siter_rev != le_string.begin() )
    {
        if( *siter == *siter_rev )
        {
            // std::cout<< *siter <<" -- " << *(siter_rev) << std::endl;
            plen += 2;
            siter++; siter_rev--;
        }
        else
        {
            break;
        }
    }
    return plen;
}

int main()
{
    std::deque<char>  le_stack;
    std::string le_string = "liguhelgipoiuytrertyuioualwieungbfghjkjhgfdovolthalmvweotnawot";

    size_t maxp_start = 0, maxp_len=0;

    size_t index = 0, plen = 0;
    for( auto siter = le_string.begin(); siter != le_string.end(); )
    {
        plen = 0;
        if( *siter == *(siter+1) )
        {
            siter++; index++;
            plen = check_palindrome( le_string, siter, false );
        }
        else if( index > 0 )
        {
            if( *(siter-1) == *(siter+1) )
            {
                plen = check_palindrome( le_string, siter + 1, true );
            }
        }
        if( plen > maxp_len )
        {
            maxp_len = plen;
            maxp_start = index - plen/2;
        }

        // if(plen == 0)
        // {
        //     ;
        // }
        // else
        // {
            // auto pstart = index - plen/2;
            // std::cout<<"Palindrome "<< le_string.substr(pstart, plen) << " at " << pstart <<" length: "<<plen<<std::endl;
        // }

        index++; siter++;
    }
    std::cout<< le_string.substr(maxp_start, maxp_len) << std::endl;
}