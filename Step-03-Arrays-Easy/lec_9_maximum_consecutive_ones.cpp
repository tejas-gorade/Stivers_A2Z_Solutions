#include<bits/stdc++.h>  
#include<iostream>
using namespace std;

// Given - an array 
// to find : maximum number of consecutive ones 

//      Time compx  -  O(n)      space compx - O(1)

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

int max_consecutive_ones(vector <int> vec){
    int count_ones = 0, max_ones = 0;
    for(int i=0;i<vec.size();i++){
        if(vec[i] == 1){
            count_ones++;
            max_ones= max(max_ones , count_ones);
        }
        else
            count_ones = 0;
    }
    return max_ones;
}

int main() {
    
    vector <int> vec;
    int max_count;
    inputarray(vec);
    
    max_count = max_consecutive_ones(vec);
    cout<<"Maximum consecutive ones count is: "<<max_count<<endl;

    return 0;       
}
