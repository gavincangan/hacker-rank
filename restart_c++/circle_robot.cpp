#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

#define N 0
#define E 1
#define S 2
#define W 3

using namespace std;
int manhattan_dist(int ax, int ay, int bx, int by)
{
    return( abs(ax-bx) + abs(ay-by) );
}
// Complete the doesCircleExist function below.
vector<string> doesCircleExist(vector<string> commands)
{
    vector<string> res_vect;
    
    int tmode = 0;
    int cx = 0, cy = 0;
    int ox = 0, oy = 0;
    int dist[2] = {0};
    bool is_circle = false;

    for(string tcmd_str: commands)
    {
        tmode = 0; cx = 0; cy = 0; is_circle = false;
        for(int iter = 0; iter<4; iter++)
        {
            for(char tcmd: tcmd_str)
            {
                if(tcmd == 'G')
                {
                    // ox = cx; oy = cy;
                    if(tmode==N) cy += 1; //UP
                    else if(tmode==E) cx+= 1; //RIGHT
                    else if(tmode==S) cy-=1; //DOWN
                    else if(tmode==W) cx-=1; //LEFT
                }
                else if(tcmd == 'R')
                    tmode = (tmode + 1)%4;
                else if(tcmd == 'L')
                    tmode = (4 + tmode -1 ) %4;

            }
            // cout<<"\nIter:"<<iter<<" POS: "<<cx<<", "<<cy<<"Mode:"<<tmode<<endl;
            if(cx == 0 && cy == 0)
            {
                is_circle = true;
                break;
            }
        }
        res_vect.push_back( (is_circle?"YES":"NO") );
    }
   
    
    return res_vect;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int commands_count;
    cin >> commands_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> commands(commands_count);

    for (int i = 0; i < commands_count; i++) {
        string commands_item;
        getline(cin, commands_item);

        commands[i] = commands_item;
    }

    vector<string> res = doesCircleExist(commands);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];

        if (i != res.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    // fout.close();

    return 0;
}