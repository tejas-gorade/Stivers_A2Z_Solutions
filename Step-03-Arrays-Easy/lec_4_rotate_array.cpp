#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// given --->  an array |  k - rotate right or left by k places

// OPTIMAL - USE REVERSE FUNCTION
// Time compx  -  O(n)      space compx - O(1)

void printarr(vector <int> &vec){
    cout<<" { ";
    for(int i=0;i<vec.size();i++){
        cout<< vec[i]<<" ";
    }
    cout<<" }"<<endl;
}

void rotate_array_left(vector <int> &vec ,int k){
    int n = vec.size();
    k = k % n;                       //  if k=6, n=5  its rotaing same as k=1 and n=5
    reverse(vec.begin() , ( vec.begin() + k ) );        // reverse ele befor k
    reverse( ( vec.begin() + k ) , vec.end() );         // reverse ele after k 
    reverse(vec.begin() ,  vec.end() );                 // reverse whole array 
}

void rotate_array_right(vector <int> &vec ,int k){
    int n = vec.size();
    k = k % n;                          //  if k=6, n=5  its rotaing same as k=1 and n=5
    reverse(vec.begin() ,  vec.end() );               // reverse whole array
    reverse(vec.begin() , ( vec.begin() + k ) );    // reverse ele befor k
    reverse( ( vec.begin() + k ) , vec.end() );       // reverse ele after k
    // same as 1] rev ---> begin -> end-k 
            // 2] rev ---> end-k -> end 
            // 2] rev ---> begin -> end
}   

int main(){
    vector <int> vec;
    int k,a,n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    cout<<"Enter the array: "<<endl;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        vec.push_back(val);
    }                         

    cout<<"Enter value of k ( k = no. of steps to roate array by: )"<<endl;
    cin>>k;

    cout<<"1. rotate left"<<endl;
    cout<<"2. rotate right"<<endl;
    cin>>a;

    cout<<"array before rotating : "<<endl;
    printarr(vec);
    cout<<endl;

    if(a == 1)
        rotate_array_left(vec , k);
    else if(a==2)    
        rotate_array_right(vec , k);

    cout<<"array after rotating : "<<endl;
    printarr(vec);

    return 0;
}


/*
Approach 1 - Brute Force   
// Time compx  -  O(n)      space compx - O(n)
            use a different array of same size as input array
            put all the ele of input array to new array 
            with k places left or right // a[i] = inputarr[i+k] type
*/

//------------------------------------////----------------------------------------//
/*

Approach 2 - Better
// Time compx  -  O(n)      space compx - O(k)
            do not take whole new array as same size of input array
            just push_back the elements of input array 
            first k elements - for left roatate
            last k elements - for right roatate


    ------------------------BETTER  - RIGHT-------------------------
    
    vector <int> arr;
    for(int i = n-k ; i < n ; i++){          // push last k ele in arr
        arr.push_back(vec[i]);
    }

    for(int i=n-1 ; i>=0 ; i--){      
        if(i >= k)
            vec[i] = vec[i - k];             // last k ele wil become first k ele
        else
            vec[i] = arr[i];
    }
  
    -----------------------------BETTER - LEFT-------------------------------
   
    vector <int> arr;
    for(int i=0 ; i < k ; i++){               // push first k ele in arr
        arr.push_back(vec[i]);
    }

    for(int i=0;i<n;i++){      
        if(i < n - k)                       
            vec[i] = vec[i+k];
        else{
            for(int j=0;j<k;j++){   
                vec[i] = arr[j];            // first k ele wil become last k ele
                i++;              
            }
        }
    } 

    */



