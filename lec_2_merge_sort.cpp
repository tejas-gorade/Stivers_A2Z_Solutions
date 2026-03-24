#include<iostream>
#include<vector>
using namespace std;

// 5] Merge sort
// time complexity - // avg - O(nlogn)      // best - O(nlog(n))

void merge(vector <int> &arr,int low,int mid,int high){
    vector <int> temp;
    int left = low;
    int right = mid+1;
    
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}

void mergesort(vector <int> &arr ,int low,int high){
    if(low==high)
        return;
    int mid = (high+low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);

    merge(arr,low,mid,high);
}

void ms(){
    int n;
    cout<<"Enter the size of array- "<<endl;
    cin>>n;

    vector <int> v(n);
    cout<<"Enter the elements of array:- "<<endl;
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"] = ";
        cin>>v[i];

    }
    mergesort(v,0,n-1);

    cout << "\nThe sorted array is: " << endl;
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){

    ms();
    
    return 0;
}