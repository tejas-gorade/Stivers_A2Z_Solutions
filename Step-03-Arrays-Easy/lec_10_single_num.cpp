#include<bits/stdc++.h>  
#include<iostream>
using namespace std;

// Given : an Array with every num occuring twice except 1 number
// output : the single time occuring number 

// Approach - MOST OPTIMAL - USING "Bitwise XOR"
//            Time compx  -  O(n)      space compx - O(1)

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

int single(vector <int> vec){
    int xorr = 0;
    for(int i=0;i<vec.size();i++){
        xorr = xorr ^ vec[i];
    }
    return xorr;
}

int main() {
    
    vector <int> vec;
    int single_num;
    inputarray(vec);
    
    single_num = single(vec);
    cout<<"Singlr number is: "<<single_num<<endl;

    return 0;       
}

/*

// -----------------------------Brute Force-----------------------------------//
//           Time compx  -  O(n^2)      space compx - O(1)

 for(i =0 --> n) 
  for(j=0---->n) 
  if(i!=j)  ----> if(a[i] != a[j]) ---<return a[i];


// --------------------------------BETTER-----------------------------------//
//          Time compx  -  O(n + max_element)      space compx - O(max_element)

 Approach ---> using HASHMAPS

 int max = max_element(a.begin(),a.end());
 HASH[max+1];
 for(i =0 --> n) {
    HASH[a[i]]++;
 }
 for(i =0 --> n) {
   if( HASH[a[i]] == 1 ) -----> return a[i];
 }


// -----------------------------BEST-ALTERNATIVE-----------------------------------//
//          Time compx  -  O(n)      space compx - O(n/2 +1) ==> O(n)   

Approach ---> using unordered_map

 unordered_map < int , int > M_freq;
 for(i =0 --> n) {
    M_freq[a[i]]++;
 }
 for(auto it : M_freq) {
   if( it.second == 1 ) -----> return it.first;
 }

*/