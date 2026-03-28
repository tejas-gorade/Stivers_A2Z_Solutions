#include<bits/stdc++.h>  
#include<iostream>
using namespace std;
/*
Given   ---> array of size n and integer k
To Find ---> length of lomgest subarray with sum = k 
//                  
USING Hash MAP ---> tc = O( nlog(n) ) --> map               
//                       O( n * 1 ) --> unordered_map
//                  sc = O( n )---> using n - indexed sized hashmap

==> if array has BOTH Positive and Negative Numbers ---> "MOST OPTIMAL" 
==> if array has ONLY Positive Numbers -----> "BETTER ONLY" =>( OPTIMAL IS SLIDING WINDOW )
*/
//------------------------------------------//------------------------------------------------//

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

int longest_subarray_sum_k(vector <int> &vec , int k){

    int n = vec.size() , max_len = 0 ; 
    long long  prefix_sum = 0;
    unordered_map <long long , int> MAP;     // <prefix_sum , index>

    for(int i=0;i<n;i++){                   // (for each index in vector vec) 
        prefix_sum += vec[i];               // as prefix_sum = sum of all ele form 0 --> index i
        if(prefix_sum == k)                 
            max_len = i+1;      

// subarray in which prefix_sum --> [till current i] from any index [before current i] = k
// for curr ps = x; have i ever seen x-k brore current i; so that x-(x-k) will be = k
        long long remaining_sum = prefix_sum - k ; 

        if( MAP.find(remaining_sum) != MAP.end() ){    
            int len = i - MAP[remaining_sum];      // if rem_sum is found in the map
            max_len = max(max_len , len);             
        }
        if(MAP.find(remaining_sum) == MAP.end()) 
            MAP[prefix_sum] = i;                   // add req_sum to map                                              
                                                           
    }
    return max_len;
}


int main() {
    
    vector <int> vec;
    int length ,k;

    inputarray(vec);
    cout<<"Enter the value of k :";
    cin>>k;

    length = longest_subarray_sum_k(vec , k);
    cout<<"Length of longest subarray with sum "<<k<< " is : "<<length<<endl;

    return 0;       
}

//------------------------------------------//------------------------------------------------//

/*
Approach 1 - BRUTE FORCE --> O(n^2)

int longest_subarray_sum_k(vector <int> &vec , int k){
    int n = vec.size() , ml = 0 ;    
    for(int i=0;i<n;i++){
        int sum=0 , cl = 0;
        for(int j=i;j<n;j++){
            if(sum == k)
                ml = max(ml,cl);
            else if(sum > k){
                cl = 0;
                break;
            }
        }
    }
    return ml;
}
*/
