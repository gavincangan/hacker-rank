/*
Reverse the order of words in a string in-place
*/

#include <iostream>
#include <vector>

void reverse_string( std::string::iterator startpos_fwd, std::string::iterator endpos_fwd)
{
    std::string::iterator currpos_fwd = startpos_fwd;
    std::string::reverse_iterator currpos_rev = std::make_reverse_iterator(endpos_fwd);

    char temp;

    // std::cout<<"$"<<*(currpos_fwd+1)<<"\t"<<*(currpos_rev+1)<<"#\n";

    while( abs(std::distance(currpos_fwd, startpos_fwd)) < std::distance(currpos_fwd,  endpos_fwd) )
    {
        temp = *currpos_fwd;
        *currpos_fwd = *currpos_rev;
        *currpos_rev = temp;

        currpos_fwd++;
        currpos_rev++;
    }
}

int main()
{

    std::string input_str; // = "the quick brown dog jumps over the lazy fox";
    std::cout<<"Enter input string: ";
    std::getline(std::cin, input_str);
    std::cout<<input_str<<' '<<input_str.length()<<std::endl;

    reverse_string(input_str.begin(), input_str.end());

    std::string::iterator startword_fwd=input_str.begin(), endword_fwd=input_str.begin();

    // std::cout<<"Reversed string: "<<input_str<<std::endl;

    while( 1 )
    {
        while( *endword_fwd != ' ' && endword_fwd != input_str.end() )
        {
            endword_fwd++;
        }
        reverse_string(startword_fwd, endword_fwd);
        // std::cout<<"## "<<input_str<<std::endl;

        if( endword_fwd != input_str.end() )
        {
            startword_fwd = endword_fwd+1;
            endword_fwd++;
        }
        else
        {
            break;
        }
    }

    std::cout<<"Word order reversed string: "<<input_str<<std::endl;

    return 0;
}


    // bool transform_done = false;
    // // uint16_t count = 0;
    
    // std::string::iterator spacebefore_pos_fwd = input_str.begin(), spaceafter_pos_fwd=input_str.begin();
    // std::string::reverse_iterator spacebefore_pos_rev = input_str.rend(), spaceafter_pos_rev=input_str.rend();


    // while(!transform_done)
    // {
    //     while( *spaceafter_pos_fwd != ' ' && spaceafter_pos_fwd != input_str.end() )
    //     {
    //         spaceafter_pos_fwd++; spaceafter_pos_rev--;
    //         std::cout<<"p "<<*spaceafter_pos_fwd<<" "<<*spacebefore_pos_fwd<<std::endl;
    //     }

    //     cur_pos_fwd = spacebefore_pos_fwd;
    //     cur_pos_rev = spaceafter_pos_rev;

    //     while( abs(std::distance(cur_pos_fwd, spacebefore_pos_fwd)) <= std::distance(cur_pos_fwd, spaceafter_pos_fwd))
    //     {
    //         std::cout<<"p "<<*cur_pos_fwd<<" "<<*cur_pos_rev<<std::endl;
    //         temp = *cur_pos_fwd;
    //         *cur_pos_fwd = *cur_pos_rev;
    //         *cur_pos_rev = temp;
    //     }

    //     if( spaceafter_pos_fwd==input_str.end() )
    //     {
    //         transform_done = true;
    //     }
    //     else
    //     {
    //         spacebefore_pos_fwd = spaceafter_pos_fwd;
    //         spaceafter_pos_fwd = spaceafter_pos_fwd + 1;
    //         spaceafter_pos_rev = spaceafter_pos_rev - 1;
    //     }

    //     std::cout<<input_str<<std::endl;
    // }