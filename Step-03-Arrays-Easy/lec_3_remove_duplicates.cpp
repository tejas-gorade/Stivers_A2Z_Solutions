#include<iostream>
#include<vector>

using namespace std;

// Array is sorted  - Ascending order
// Task - Remove Duplicates and return the size of array after removing duplicates

// Time Complexity: O(n) - Single pass through the array
// Space Complexity: O(1) - Modifying the array in-place

void printarr(vector <int> &v){
    cout<<"{ ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"}"<<endl;
}

int remove_duplicates(vector <int> &v){
    int j=0;
    for(int i=1;i<v.size();i++){
        if(v[i] != v[j]){
            j++;
            v[j] = v[i];
        }
    }
    return j+1;         // j+1 will be size of vec after removing duplicates

}

int main(){

    vector <int> vec;
    cout<<"Enter the elements of array: "<<endl;
    cout<<"Write done after Entering "<<endl;
    int value;                          
    while(cin>>value){                  // used when size of array is not given   
        vec.push_back(value);
    }
    cout<<"Before Removing Duplicates: "<<endl;
    printarr(vec);

    int length = remove_duplicates(vec);        

    cout<<"After Removing Duplicates: "<<endl;
    cout<<"size of array: "<<length<<" , ";
    cout<<" { ";
    for(int i=0;i<length;i++){
        cout<<vec[i]<<" ";
    }
    cout<<" }";
    return 0;
}