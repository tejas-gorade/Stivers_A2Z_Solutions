#include<iostream>
using namespace std;

// 1] selection sort ---> time compx - // avg - O(n^2)     // best - O(n^2)
                                    
// 2] bubble sort -------> time copx - // avg - O(n^2)     // best - O(n)
                                    
// 2] insertion sort ----> time copx - // avg - O(n^2)     // best - O(n)
                                    
// 2] quick sort -------> time copx - // avg - O(nlog(n))  // best - O(nlog(n))
                                    


void printarr(int a[],int n){
    cout<<"Sorted array:-"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout << endl << "-----------------------" << endl;
}

void selection(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;                  // put min as index i 
        for(int j=i;j<n;j++){
            if(a[j]<a[min])
                min = j;
        }
        if(min != i)
            swap(a[i],a[min]);
    }
}

void bubble(int a[],int n){
    for(int i=0;i<n-1;i++){
        int is_swap=0;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                is_swap=1;
            }
        }
        if(!is_swap)
                break;
    }
}

void insertion(int a[],int n){
    for(int i=1;i<n;i++){
        int key = a[i];
        int j=i-1;
        while(j>=0 && key < a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int partition(int a[],int low,int high){
    int pivot = a[low];
    int p=low+1;
    int q=high;
    while(p<=q){

        while(a[p]<=pivot && p<=high){
            p++;
        }
        while(a[q]>pivot && q>=low+1){
            q--;    
        }
        if(p<q)
            swap(a[p],a[q]);                
    }
    swap(a[low],a[q]);      // pivot <--> a[q] as (pivot=a[low])
    return q;               // now q is index containing a[low] value
}                           // as only values swapped

void quick(int a[],int low,int high){
    
    if(low<high){
        int pivot_index = partition(a,low,high);
        quick(a,low,pivot_index-1);
        quick(a,pivot_index+1,high);
    }
}

void sort(){

    bool flag = false;
    while(!flag){

        int ch;
        cout<<"Enter 1/2/3/4/5:"<<endl;
        cout<<"1.Selection sort"<<endl;
        cout<<"2.Bubble sort"<<endl;
        cout<<"3.Insertion sort"<<endl;
        cout<<"4.Quick sort"<<endl;
        cout<<"5.End."<<endl;
        cin>>ch;

        int size;
        cout<<"Enter the size of array: "<<endl;
        cin>>size;

        int arr[size];

        cout<<"Enter the elements of array: "<<endl;
        for(int i=0;i<size;i++){
            cout<<"a["<<i<<"] = ";
            cin>>arr[i];
        }

        switch (ch)
        {
        case 1 :
            selection(arr,size);
            printarr(arr,size);
            break;

        case 2:
            bubble(arr,size);
            printarr(arr,size);
            break;

        case 3:
            insertion(arr,size);
            printarr(arr,size);
            break;

        case 4:
            quick(arr,0,size-1);
            printarr(arr,size);
            break;
        
        case 5:
            flag=true;      // END
            break;

        default:
            cout<<"Invalid input"<<endl;
            flag=true;  // use flag in while loop instead of recurssion
            break;      // as recurssion will use stacking for every call
        }       
    }
}

int main(){
    
    sort();
    return 0;
}
