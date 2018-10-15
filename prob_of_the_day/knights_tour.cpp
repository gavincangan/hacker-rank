#include <iostream>
#include <vector>
#include <array>

template<typename std::size_t _sizex, std::size_t _sizey>
class Board
{
    public:
    const size_t sizex, sizey;
    std::array< std::array<uint32_t, _sizex>, _sizey > board;
    // const std::vector< std::pair<int, int> > kmoves = { {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2} };
    
    const std::vector< std::pair<int, int> > kmoves = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };
    // template<typename std::size_t _sizex, std::size_t _sizey>
    Board< _sizex, _sizey >(): sizex(_sizex), sizey(_sizey), board({}) {}

    void print_board()
    {
        for(auto row : board)
        {
            for( auto num : row )
            {
                std::cout<<num<<"\t";
            }
            std::cout<<std::endl;
        }
    }

    bool is_valid_pos( const int x, const int y)
    {
        if( y >= 0 && y < int(sizey) )
        {
            if( x >= 0 && x < int(sizex) )
            {
                return true;
            }
        }
        return false;
    }

    bool is_passable( const int x, const int y)
    {
        if( is_valid_pos( x, y ) )
        {
            return ( board[y][x] == 0 );
        }
        return false;
    }

};

template<typename std::size_t _sizex, std::size_t _sizey>
bool nextKnightStep( Board<_sizex, _sizey>& board, int cx, int cy, uint32_t step_count = 1 )
{
    static size_t max_count = 0;

    if(step_count > max_count)
    {
        max_count = step_count;
    }

    board.board[cy][cx] = step_count;

    std::cout<<"\nS: "<<step_count<<" X:"<<cx<<" Y:"<<cy<<"\t"<< max_count <<std::endl;
    board.print_board();

    if(step_count >= board.sizex * board.sizey)
    {
        return true;
    }

    bool is_okay = false;
    for( auto move : board.kmoves )
    {
        is_okay = false;
        if( board.is_passable( cx+move.first, cy+move.second ) )
        {
            is_okay = nextKnightStep( board, cx+move.first, cy+move.second, step_count + 1 );
            if(is_okay)
            {
                return true;
            }
        }
    }
    if(!is_okay)
    {
        board.board[cy][cx] = 0;
    }

    return is_okay;

}

int main()
{
    Board<8, 8> board;

    nextKnightStep<8, 8>( board, 0, 0, 1 );

    board.print_board();

    return 0;
}