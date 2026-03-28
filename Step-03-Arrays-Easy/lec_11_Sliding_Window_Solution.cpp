#include<bits/stdc++.h>  
#include<iostream>
using namespace std;

// given  ----> array of size n and integer k
// to find ---> length of longest subarray with sum k 

// if array has BOTH Positive and Negative Numbers ---> MOST OPTIMAL 
// if array has ONLY Positive Numbers --------> BETTER ONLY ---> OPTIMAL IS SLIDING WINDOW

//----------------------------------Used Sliding Window-------------------------------------// 
//               Time compx  -  O(n)      space compx - O(1)


void inputarray(vector <int> &vec){
    int n,value;
    cout<<"Enter the ""size"" of array : "<<endl;
    cin>>n;

    cout<<"Enter the array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>value;
        vec.push_back(value);
    }
}

int longest_subarray_sum_k_using_Sliding_Window(vector <int> &vec , int k){

    int n = vec.size() , max_len = 0 ;    
    long long  current_sum = 0;
    int left = 0 , right = 0;
    while(right < n){
        current_sum += vec[right];

        while(current_sum > k && left <= right){
            current_sum -= vec[left];   
            left++; 
        }

        if(current_sum == k)
            max_len = max(max_len , right - left + 1);

        right++;
    } 
    return max_len;
}


int main() {
    
    vector <int> vec;
    int length;
    long long k;

    inputarray(vec);
    cout<<"Enter the value of k :";
    cin>>k;

    length = longest_subarray_sum_k_using_Sliding_Window(vec , k);
    cout<<"Length of longest subarray with sum "<<k<< " is : "<<length<<endl;

    return 0;       
}

//------------------------------------------//------------------------------------------------//

/*

Approach 1 - BRUTE FORCE --> O(n^2)

Approach 2 - USING Hash MAP ---> tc = O( nlog(n) ) --> map               
//                                    O( n * 1 ) --> unordered_map
//                               sc = O( n )---> using n - indexed sized hashmap

*/
