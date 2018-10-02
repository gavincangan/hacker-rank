/*
You will be given a list of integers, arr, and a single integer . You must create an array of length from elements of such that its unfairness is minimized. Call that array . Unfairness of an array is calculated as

Where:
- max denotes the largest integer in arr
- min denotes the smallest integer in arr

Testing for all pairs, the solution provides the minimum unfairness.

Note: Integers in may not be unique. 
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    sort( arr.begin(), arr.end() );

    if(k > arr.size() - 1)
    {
        return 0;
    }

    auto iter_begin = arr.begin();
    auto iter_end = iter_begin + k-1;

    int min_diff = numeric_limits<int>::max();
    int temp_diff = 0;
    while( iter_end != arr.end() )
    {
        temp_diff = *iter_end - *iter_begin;
        // cout<<"\t"<<temp_diff<<" "<<*iter_end<<" "<<*iter_begin<<endl;
        if( temp_diff < min_diff )
        {
            min_diff = temp_diff;
        }
        iter_begin++;
        iter_end++;
    }
    return min_diff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}