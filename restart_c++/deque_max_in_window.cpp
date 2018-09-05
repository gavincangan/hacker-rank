// #include <iostream>
// #include <sstream>
// #include <vector>
// #include <deque>

// int main()
// {
//     uint32_t num_tests;
//     std::cin >> num_tests;

//     std::string line_input;

//     for(int test_ix=0; test_ix<num_tests; test_ix++)
//     {
//         std::getline(std::cin, line_input);
//         if( ! line_input.empty() )
//         {
//             std::istringstream line_stream( line_input  );

//         }
//     }
    
// }

#include <iostream>
#include <deque>   
#include <vector>
#include <algorithm>    // std::min_element, std::max_element

void printKMax(int arr[], int n, int k){
    //Write your code here.
    std::deque<int> arr_deque;
    std::deque<int> compare_deque;
    
    int i=0;
    for( ;i<k; i++)
        arr_deque.push_back( arr[i] );
    
    for(;i<n+1;i++)
    {
        std::cout << *std::max_element( arr_deque.end()-k, arr_deque.end() )<<' ';
        //std::cout<<"\npopF:"<<arr_deque.front()<<'\t'<<k<<'\n'; 
        //arr_deque.pop_front();
        arr_deque.push_back( arr[i] );
    }
    std::cout<<std::endl;
}

int main(){
  
    int t;
    std::cin >> t;
    while(t>0) {
        int n,k;
        std::cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
              std::cin >> arr[i];
        printKMax(arr, n, k);
        t--;
      }
      return 0;
}