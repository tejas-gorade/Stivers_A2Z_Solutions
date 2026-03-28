#include<bits/stdc++.h>     
#include<iostream>
using namespace std;

// union and intersecton - in Ascending Order

// GIVEN : 2 "sorted" arrays 

// USING TWO - POINTER

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

void printarr(vector <int> &v){
    cout<<"{ ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"}"<<endl;
}


// Time compx  -  O(n + m)      space compx - O(n + m)
void union_array(vector <int> &vec1, vector <int> &vec2){
    int i=0,j=0;            // i and j can be changed but dont get destroyed till function ends
    vector <int> union_vec; 
    while(i < vec1.size() and j < vec2.size()){      // either vec1 or vec2 is traced
        int curr;           
        if(vec1[i] <= vec2[j]){
            curr = vec1[i];
            i++;
        }
        else{
            curr = vec2[j];
            j++;
        }

        if(union_vec.empty() || union_vec.back() != curr )
            union_vec.push_back(curr);
    }
    
    while(i < vec1.size()){                         // if vec1 is still remaining- vec1>vec2
        if(union_vec.empty() || union_vec.back() != vec1[i] )
            union_vec.push_back(vec1[i]);
        i++;
    }
    while(j < vec2.size()){                         // if vec2 is still remaining- vec2>vec1
        if(union_vec.empty() || union_vec.back() != vec2[j] )
            union_vec.push_back(vec2[j]);
        j++;
    }

    cout<<"Array 1: ";
    printarr(vec1);
    cout<<"Array 2: ";
    printarr(vec2);
    cout<<endl;

    cout<<"Union of both arrays is: ";
    printarr(union_vec);
    cout<<endl;
}

// Time compx  -  O(n +m)      space compx - O(min(n + m))
void intersection(vector <int> &vec1, vector <int> &vec2){
    int i=0,j=0;        // i and j can be changed but dont get destroyed till function ends
    vector <int> intersection_vec;

    while(i < vec1.size() && j < vec2.size()){
        int common;
        if(vec1[i] == vec2[j]){
            if(intersection_vec.empty() || intersection_vec.back() != vec1[i])
                intersection_vec.push_back(vec1[i]);                
            i++;
            j++;
        }
        else if(vec1[i] < vec2[j])
            i++;
        else
            j++;
    }
    cout<<"Array 1: ";
    printarr(vec1);
    cout<<"Array 2: ";
    printarr(vec2);
    cout<<endl;

    cout<<"Intersection of both arrays is: ";
    printarr(intersection_vec);
    cout<<endl;
}


int main() {
    
    vector <int> vec1 , vec2;
    int a;

    cout<<"Enter 1/2:"<<endl<<"1] union of arrays \t 2] intersection of arrays "<<endl;
    cin>>a;
    cout<<"Enter array 1:"<<endl;
    inputarray(vec1);
    cout<<"Enter array 2:"<<endl;
    inputarray(vec2);
    cout<<endl;
    
    if(a==1)
        union_array(vec1,vec2);
    else    
        intersection(vec1,vec2);
    
    return 0;
}