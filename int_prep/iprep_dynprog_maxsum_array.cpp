/*
Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset.

For example, given an array arr=[-2, 1, 3, 4, 5] we have the following possible subsets:

Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8

//https://www.hackerrank.com/challenges/max-array-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming

*/

#include <bits/stdc++.h>
#include <algorithm> 
#include <limits>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr)
{
    uint16_t arr_len = arr.size();
    vector<int> max_val(arr_len, std::numeric_limits<int>::min());
    int temp_max = 0, zero_max = 0;

    max_val[0] = std::max( arr[0], 0);
    max_val[1] = std::max( arr[1], 0);

    //maxval[2]
    zero_max = std::max( arr[2], 0);
    temp_max = std::max( temp_max, max_val[0] + zero_max );
    max_val[2] = temp_max;

    for(int ix = 3; ix<arr_len; ix++)
    {
        zero_max = max( arr[ix], 0 );
        temp_max = max( zero_max, max_val[ix-2] + zero_max );
        max_val[ix] = max( temp_max, max_val[ix-3] + zero_max );
    }

    temp_max = *max_element( max_val.begin(), max_val.end() );

    return temp_max;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    cout << res << "\n";
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
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
