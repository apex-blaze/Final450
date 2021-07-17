#include<iostream>
#include<queue>

using namespace std;

// Q.1 Implement Min/Max Heap using array and recusrion

// O(logn)
void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }

    if(i!=largest){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }

}

//  O(n) - Because, 90% of nodes reside in lower 3 levels of BT
//          & For Lower Levels Heapify almost takes less than 3 
//          calls which is almost constant
void buildHeap(int arr[],int n){
    
    int nonLeafIdx = n/2 -1;
    for(int i=nonLeafIdx;i>=0;i--){
        heapify(arr,n,i);
    }
}

// Q.2 Perform Heapsort O(nlogn)
void heapsort(int arr[],int n){

    buildHeap(arr,n);

    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main(){

    // int arr[] = {3,5,7,1,0,6,2}; // n=7
    // heapsort(arr,7);
    // for(auto i:arr){
    //     cout<<i<<" ";
    // }

    return 0;
}