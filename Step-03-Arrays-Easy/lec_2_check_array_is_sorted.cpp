#include<iostream>
#include<vector>
using namespace std;

// Time compx  -  O(n)      space compx - O(1)
bool is_sorted(vector <int> &v){
    for(int i=1;i < v.size();i++){      
        if(v[i-1] > v[i])               // Ascending order
        return false;                   // Descending ---> v[i-1] < v[i]
    }
    return true;
} 

int main(){

    vector <int> vec;
    cout<<"Enter the elements of array: "<<endl;
    cout<<"Write done after Entering "<<endl;
    int value;                          
    while(cin>>value){                  // used when size of array is not given   
        vec.push_back(value);
    }

    if(is_sorted(vec))
        cout<<"Array is Sorted !"<<endl;
    else
        cout<<"Array is not Sorted !"<<endl;


    return 0;
}