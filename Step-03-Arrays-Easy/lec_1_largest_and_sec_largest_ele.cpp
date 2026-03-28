#include<iostream>
#include<vector>

using namespace std;

// Time compx  -  O(n)      space compx - O(1)
int largest(vector <int> &v){                      
    int max = 0;                  
    for(int i=0;i<v.size();i++){
        if(v[max] < v[i])
            max = i;
    }
    return v[max];
}

// Time compx  -  O(n)      space compx - O(1)
int second_largest(vector <int> &v){               
    int max = 0 ;
    int sec_large = -1;            
    for(int i=0;i < v.size();i++){
        if(v[max] < v[i]){
            sec_large = max;
            max = i ;   
        }
        else if( v[i] < v[max] && v[i] > v[sec_large] )
            sec_large = i ;
    }
    return (sec_large==-1)?-1:v[sec_large];
}

int main(){

    vector <int> vec;
    cout<<"Enter the elements of array: "<<endl;
    cout<<"Write done after Entering "<<endl;
    int value;                          
    while(cin>>value){                  // used when size of array is not given   
        vec.push_back(value);
    }

    cout<<"Largest Element in Array: "<<largest(vec)<<endl;
    cout<<"Second Largest Element in Array: "<<second_largest(vec)<<endl;

    return 0;
}