#include<iostream>
#include<vector>
using namespace std;

void printarr(vector <int> &vec){
    cout<<" { ";
    for(int i=0;i<vec.size();i++){
        cout<< vec[i]<<" ";
    }
    cout<<" }"<<endl;
}


// USING 2-POINTER ----> j=0;i=1
// Time compx  -  O(n)      space compx - O(1)

void move_zero_to_end(vector <int> &v){                // USING 2-POINTER ----> j=0;i=1
    int j = 0;                                         //default in for loop -> i++
    for(int i=1;i<v.size();i++){            // j != 0 , i = 0   ->j++ ,         i++
        if(v[j] != 0)                       // j != 0 , i != 0  ->j++ ,         i++    
            j++;                            // j = 0 , i = 0    ->              i++
        if(v[j] == 0 && v[i] != 0){         // j = 0 , i != 0   ->swap() , j++, i++
            swap(v[j],v[i]);
            j++;
        }
    }
}

int main() {
    
    vector <int> vec;

    cout<<"Enter the array: "<<endl;
    int value;
    while(cin>>value){
        vec.push_back(value);
    }
    cout<<"array initially: "<<endl;
    printarr(vec);

    move_zero_to_end(vec);
    
    cout<<"array after moving zeroes to end: "<<endl;
    printarr(vec);

    return 0;
}

/*
// Time compx  -  O(n)      space compx - O(n)
------------------------- BRUTE FORCE ---------------------------
        STORE ALL NON ZERO ELEMENTS IN AN ARRAY
        COUNT ZEROES
        AND PUSH THE ZEROES AFTER THE NON ZERO ELEMENTS
*/


/* 
// Time compx  -  O(2*n)      space compx - O(1)
-------------------------- BETTER --------------------------------

void move_zero_to_end(vector <int> &vec){
    int count_zero = 0 ;
    for(int i=0;i<vec.size();i++){
        if(vec[i] == 0)
            count_zero++;
        else{
            vec[i - count_zero] = vec[i];
        }
    }
    for(int i=( vec.size()-count_zero );i<vec.size();i++){
        vec[i] = 0;
    } 
}
*/