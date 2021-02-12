#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// 1.  Reverse the Array

// **** Iterative approach ****
void reverseArrayItr(int arr[],int size){
    for(int i=0;i<(size/2);++i){
        int temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}

// **** Recursive approach ****
void reverseArrayRec(int arr[],int size){
   void reverseArrayRecUtil(int*,int,int);
   reverseArrayRecUtil(arr,0,size-1);
}

void reverseArrayRecUtil(int arr[],int start,int end){
    if(start >= end)
    return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverseArrayRecUtil(arr,start+1,end-1);
}

// 2. Maximum and Minimum Element in Array

// **** Iterative Approach **** -O(n)
int maxItr(int arr[],int size){
    int ans=INT_MIN;
    for(int i=0;i<size;++i){
        if(arr[i]>ans){
            ans = arr[i];
        }
    }
    return ans;
}

// **** Recursive Approach ****
int maxRec(int arr[],int size){
      if(size == 1){
        return arr[0];
    }
    else{
        return max(arr[size-1],maxRec(arr,size-1));
    }
}
// NOTE : Similarly, it could be implemented for Min


// 3. Kth Max and Min element in an array

/* O(nlogn) approach is to sort the array using STL sort().
   And then returning arr[n-k]
   But we will use O(n) Approach! */




// 5. Move all negative elements to one side of the array

// A. Partition Algo - O(n)
void shiftNegatives_A(int arr[],int size){
    int j = -1,pivot=0;
    for(int i=0;i<size;++i){
        if(arr[i]<=pivot){
            j++;
            swap(arr[i],arr[j]);
        }
    }
}

// B. TWo-pointer Approach - O(n)
void shiftNegatives_B(int arr[],int size){
    int left = 0, right =  size-1;
    while(left < right){
        if(arr[left]<0 && arr[right]<0){
            left++;
        }
        else if(arr[left]>0 && arr[right]>0){
            right--;
        }
        else if(arr[left]>0 && arr[right]<0){
            swap(arr[left],arr[right]);
            left++; right--;
        }
        else{
            left++; right--;
        }
    }
}

int main(){
    int a[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int size = sizeof(a)/sizeof(a[0]);
    // reverseArrayItr(a,4);
    // reverseArrayRecursive(a,4);
    // cout<<minItr(a,4)<<endl;
    // shiftNegatives_A(a,size);
    printArray(a,size);
    

}