#include<bits/stdc++.h>     
#include<iostream>
using namespace std;

// to find the minimum index where target is found 
// arr = {1,2,3,3,4,5,3,4,5,8}   --> key = 3 --> output = 2
//                               --> key = 5 --> output = 5

// Time compx  -  O(n)      space compx - O(1)
int linear_search(vector <int> &v , int key){
    for(int i=0;i<v.size();i++){
        if(v[i] == key)
            return i;
    }
    return -1;          // is key not found in array
}

int main() {
    
    vector <int> vec;
    int target, n , value;

    cout<<"Enter the size of array: "<<endl;
    cin>>n;

    cout<<"Enter the array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>value;
        vec.push_back(value);
    }
   
    cout<<"Enter target element: "<<endl;
    cin>>target;

    int index = linear_search(vec , target);
    cout<<"The minimum index = "<<index<<endl;
    return 0;
}


//----------------------------------------OR----------------------------------------------- 
/*
// Time compx  -  O(n)      space compx - O(1)
#include <algorithm>                // Required for find

auto it = find(vec.begin(), vec.end(), target);

if (it != vec.end()) {
    int index = distance(vec.begin(), it);    // as iterator is not an int -->distance is used
    cout << "Found at index: " << index;      // to get the integer distance where found target
} else {
    cout << "Not found";
}

*/