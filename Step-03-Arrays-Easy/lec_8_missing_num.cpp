#include<bits/stdc++.h>  
#include<iostream>
using namespace std;

// Given ---> an array of range [0,n] and size n
// to find ---> a missing number in the array (as [0,n] - takes n+1 size)
// LOGIC ---> (missing = sum of "whole array ") -  (sum of array "without missing number")
//          Time compx  -  O(n)      space compx - O(1)

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

int missing_num(vector <int> &vec){
    int curr_sum =0 , n= vec.size();
    int expected_sum = ( n *(n+1) ) / 2 ;
    for(int i=0;i<n;i++){
        curr_sum+=vec[i];
    }
    return expected_sum - curr_sum;         // the missing value will be this
}

int main() {
    
    vector <int> vec;
    int minimum;
    inputarray(vec);
    
    minimum = missing_num(vec);
    cout<<"The Missing number is:  "<<minimum<<endl;

    return 0;       
}


//---------------------------------USE XOR INSTEAD--------------------------------------- //
/*                  // Time compx  -  O(n)      space compx - O(1)   
 int missing_num(vector <int> &vec){
        int xorr1  = 0 , xorr2 = 0, n= vec.size();
        for(int i=0;i<n;i++){
            xorr1 = xorr ^ vec[i];
            xorr2 = xorr ^ vec[i];
        }
        xorr1 = xorr1 ^ n;
        return xorr1 ^ xorr2 ;         // the missing value will be this
    }
*/


//-----------------------------------brute force-----------------------------------
//                    // Time compx  -  O(nlog(n))      space compx - O(1)
/* 
int missing_num(vector <int> &vec){
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        if(vec[i] != i){
            return vec[i-1];
        }
    }
    return -1;  
}
*/