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

// Q.8 max Subarray sum (Kadane algo)
int maxSubarraySum(int arr[], int n){
     long long maxi = INT_MIN; long long sum=0;
     for(int i=0;i<n;i++){
         sum+=arr[i];
         maxi = max(maxi,sum);
         if(sum < 0){
             sum=0;
         }
     }   
    return maxi;
} 


// Q.9 Minimize the difference between heights
int getMinDiff(int arr[], int n, int k) {
    if(n==1) return 0;
    sort(arr,arr+n);
    int ans = arr[n-1]-arr[0];

    // for i=0 as partition ans will be same as initial ans
      for(int i=1;i<n;i++){
          if(arr[i]>=k){
              int maxi = max(arr[n-1]-k,arr[i-1]+k);
              int mini = min(arr[0]+k,arr[i]-k);
              ans = min(ans,maxi-mini);
          }
      } 
      return ans; 
}

// Q. 11 Find duplicate in array of N+1 Integers
int findDuplicate(vector<int>& nums) {
    int fast = nums[nums[0]],slow=nums[0];
    while(fast!=slow){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }    
    fast=0;
    while(fast != slow){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

// Q.12 Merge two sorted arrays in O(1) space and O(nlogn) time
void merge(int arr1[], int arr2[], int n, int m) {
    
    int i=0,j=0,k=n-1;
    while(i<=k && j<m){
        if(arr1[i]<arr2[j]){
            i++;
        }else{
            swap(arr2[j++],arr1[k--]);
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}


// Q. 13 Kadane's Algo already done at Q.8

// Q. 14  Merge intervals (overlapping or disjoint)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty()) return intervals;
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end(),[](vector<int> v1,vector<int> v2){
        return v1[0] < v2[0];
    });
    ans.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        if(ans.back()[1] < intervals[i][0]){
            ans.push_back(intervals[i]);
        }else{
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
        }
    }
    return ans;
}

// Q.15 Next Permutation
 void nextPermutation(vector<int>& nums) {
        int k=-1,l;
        int n = nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                k=i; break;
            }
        }
        if(k==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i] > nums[k]){
                l=i;
                break;
            }
        }
        swap(nums[k],nums[l]);
        reverse(nums.begin()+k+1,nums.end());
}

// Q.16 Count Inversions
// long long int inversionCount(long long arr[], long long N){
//         long long b[N]; long long ans=0;
//         for(long long i=0;i<N-1;i++){
//             b[i]=arr[i];
//         }
//         sort(b,b+N);
//         long long j=0,i=0;
//         while(i<N){
//             if(j>=N){
//                 i++;
//                 j=i;
//                 continue;
//             }
//             if( arr[j] == b[i]){
//                 ans+= abs(j-i);
//                 i++; j=i;
//             }else{
//                 j++;
//             }
//         }

// }


// Q.17 Best time to buy and sell stock
    int maxProfit(vector<int>& prices) {
        int maxProfit=0,minTill=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minTill=min(minTill,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minTill);
        }
        return maxProfit;
    }

//Q.18 Find count of all pairs in array whose sum is k
    int getPairsCount(int arr[], int n, int k) {
        map<int,int>mp; int count=0;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            count+=mp[k-arr[i]];
            if(arr[i] == k-arr[i])
                count--;
        }
        return count/2;
    }

// Q.19 Find common elements in 3 sorted arrays
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
        vector<int> ans;
        int i,j,k; i=j=k=0; int p1,p2,p3; p1=p2=p3=INT_MIN;
        while(i<n1 && j<n2 && k<n3){
            while(A[i]==p1 && i<n1){
                i++;
            }
            while(B[j]==p2 && j<n2){
                j++;
            }
            while(C[k]==p3 && k<n3){
                k++;
            }
            if(A[i]==B[j] && B[j] == C[k]){
                ans.push_back(A[i]);
                p1=A[i];
                p2=B[j];
                p3=C[k];
                i++;j++;k++;
            }
            else if(A[i]<B[j]){ // A is smallest
                p1=A[i];
                i++;
            }else if(B[j]<C[k]){ // B is smallest
                p2=B[j];
                j++;
            }else{  // C is smallest
                p3=C[k];
                k++;
            }
        }
        return ans;
    }

// Q.22 Factorial of a large number
    vector<int> factorial(int N){
        
        vector<int>v;
        v.push_back(1);
        if(N==0 || N==1){
            return v;
        }
        int carry = 0;
        for(int i=2;i<=N;i++){
            for(int j=0;j<v.size();j++){
                int prod = i*v[j] + carry;
                v[j]=prod%10;
                carry = prod/10;
            }
            while(carry){
                v.push_back(carry%10);
                carry=carry/10;
            }
        }
        reverse(v.begin(),v.end());
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
