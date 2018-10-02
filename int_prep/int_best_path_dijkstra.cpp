
#define RIGHT 1
#define DOWN 2

typedef pair<int, int> iPair;

// Complete the pacmanScore function below.
int pacmanScore(vector< vector<int> > mat) {
      int32_t curr_r = 0;
      int32_t curr_c = 0;

      int32_t rows = mat.size();
      int32_t cols = mat[0].size();
        
        int64_t max_score = 0;
        int max_next_score = numeric_limits<int>::min();

        uint8_t dir = 0; //1-> Right 2-> Down
        bool one_dir = false;
        while( curr_c < cols -1 || curr_r < rows - 1 )
        {
              if( curr_c +1 <  cols )
              {
                      max_next_score = mat[curr_r][curr_c+1];
                      dir = RIGHT;
                }
                if( curr_r + 1 < rows)
                {
                        if( mat[curr_r + 1][curr_c] > max_next_score )
                        {
                                max_next_score = mat[curr_r+1][curr_c];
                                dir = DOWN;
                        }
                }
                
                if(dir == DOWN)
                {
                        ++curr_r;
                        max_score += max_next_score;
                }
                else if(dir == RIGHT){
                        ++curr_c;
                        max_score += max_next_score;    
                }
                else
                {
                       break;        
                }
        
                dir = 0;
                max_next_score = 0;
        }
        return max_score;
}

// int pacmanScore_1(vector< vector<int> > mat) {
//         priority_queue< iPair, vector<iPair>, less<iPair> > open;
        
        
//         int curr_reward = 0
//         int curr_cell = 0;
        
//         uint32_t rows = mat.size();
//         uint32_t cols = mat[0].size();

//         vector<int> reward(rows*cols, 0);
        
//         open.push( make_pair(0, rows*cols) );
        
//         while(!pq.empty())
//         {
//               curr_cell = pq.top().second();
//               curr_reward = pq.top().first();
//               pq.pop();
//               if( (curr_cell -1)/cols == curr_cell/cols  && curr_cell >= 0  )
//               {
//                       open.push( make_pair( curr_reward+mat[(curr_cell-1)%cols, (curr_cell-1)/cols], curr_cell -1 ) );
//                       reward[curr_cell - 1] = curr_reward+mat[(curr_cell-1)%cols, (curr_cell-1)/cols]
//               } 
//               if( (curr_cell - cols >= 0)
//               {
//                       open.push(make_pair( curr_reward+mat[(curr_cell-cols)%cols, (curr_cell-cols)/cols], curr_cell - cols));
//                       reward[curr_cell - cols] = curr_reward+mat[(curr_cell-cols)%cols, (curr_cell-cols)/cols];
//               }
//         }
// }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string mat_rows_temp;
    getline(cin, mat_rows_temp);

    int mat_rows = stoi(ltrim(rtrim(mat_rows_temp)));

    string mat_columns_temp;
    getline(cin, mat_columns_temp);

    int mat_columns = stoi(ltrim(rtrim(mat_columns_temp)));

    vector<vector<int>> mat(mat_rows);

    for (int i = 0; i < mat_rows; i++) {
        mat[i].resize(mat_columns);

        string mat_row_temp_temp;
        getline(cin, mat_row_temp_temp);

        vector<string> mat_row_temp = split(rtrim(mat_row_temp_temp));

        for (int j = 0; j < mat_columns; j++) {
            int mat_row_item = stoi(mat_row_temp[j]);

            mat[i][j] = mat_row_item;
        }
    }

    int res = pacmanScore(mat);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}