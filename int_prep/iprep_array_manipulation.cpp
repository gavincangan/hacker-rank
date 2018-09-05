//https://www.hackerrank.com/challenges/crush/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {


    return 0;
}

int main()
{
    // ofstream std::fout(getenv("OUTPUT_PATH"));

    std::string nm_temp;
    getline(std::cin, nm_temp);

    std::vector<string> nm = split_string(nm_temp);

    uint32_t n = stoi(nm[0]);

    uint32_t m = stoi(nm[1]);

    std::vector<vector<int>> queries(m);
    for (uint32_t i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            std::cin >> queries[i][j];
        }

        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    std::cout << result << "\n";

    // std::fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    std::string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    std::vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
