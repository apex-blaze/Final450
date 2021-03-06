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





// 4. Sort an array of 0s,1s and 2s

// Done using Dutch Flag Algo - O(n)
void sort012s(int arr[],int size){
    //mid to hi is the region we are about to shrink
    int lo=0,mid=0,hi=size-1;
    while(mid<=hi){
        if(arr[mid] == 0){
            swap(arr[lo],arr[mid]);
            lo++; mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else if(arr[mid] == 2){
            swap(arr[hi],arr[mid]);
            hi--;
        }
    }
}

// 5. Move all negative elements to one side of the array

// A. Partition Algo - O(n)
void shiftNegatives_A(int arr[],int size){
    int j = -1,pivot=0;
    for(int i=0;i<size;++i){
        if(arr[i]<pivot){
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

// 6. Union and Intersection of two sorted arrays
vector <int> unionOfArrays(int a[],int b[],int m,int n){
    vector<int> v;
    int i=0,j=0;
    while(i<m && j<n){
        if(a[i] < b[j]){
            if(a[i]!=a[i+1]){
                v.push_back(a[i]);
            }
            i++;
        }
        else if(b[j] < a[i]){
            if(b[j]!=b[j+1]){
                v.push_back(b[j]);
            }
            j++;
        }
        else{
           if(a[i]!=a[i+1] && b[j]!=b[j+1]){
               v.push_back(a[i]);
               i++; j++;
           }
           else{
               if(b[j] == b[j+1]) j++;
               if(a[i] == a[i+1]) i++;
           }
        }
    }
    while(i<m){
        if(a[i]!=a[i+1]){
            v.push_back(a[i]);
        }
        i++;
    }
    while(j<n){
        if(b[j]!=b[j+1] ){
            v.push_back(b[j]);
        }
        j++;
    }
    return v;
}

vector <int> intersectionOfArrays(int a[],int b[],int m ,int n){
    vector <int> v;
    int i=0,j=0;
    while(i<m && j<n){
        if(a[i] < b[j]) i++;
        else if(b[j] < a[i]) j++;
        else{
            if(a[i]!=a[i+1] && b[j]!=b[j+1]){
                v.push_back(a[i]);
                i++; j++;
            }
            else{
                if(b[j] == b[j+1]) j++;
                if(a[i] == a[i+1]) i++;
            }

        }
    }
    return v;
}

int main(){
    int a[] = {2,2,5,5, 5, 6};
    int m = sizeof(a)/sizeof(a[0]);
    int b[] = {4,4, 6,6,6, 8, 10}; 
    int n = sizeof(b)/sizeof(b[0]);
    // reverseArrayItr(a,4);
    // reverseArrayRecursive(a,4);
    // cout<<minItr(a,4)<<endl;
    // shiftNegatives_A(a,size);
    // sort012s(a,size);
    // printArray(a,size);
    

}