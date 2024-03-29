#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

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

// Q.3 Maximum of all subarrays of size k
vector<int> maxOfK(int arr[],int n,int k){

    vector<int>ans;
    priority_queue<int>hp,drop;

    for(int i=0;i<k;i++){
        hp.push(arr[i]);
    }
    ans.push_back(hp.top());
    for(int i=k;i<n;i++){
        if(arr[i-k] == hp.top()){
            hp.pop();
        }else{
            drop.push(arr[i-k]);
        }
        while(!drop.empty() && drop.top() == hp.top()){
            hp.pop();
            drop.pop();
        }
        hp.push(arr[i]);
        ans.push_back(hp.top());
    }
    return ans;
}

// Q.4 k largest element in array
vector<int> kLargest(int arr[],int n,int k){
    priority_queue<int,vector<int> ,greater<int>> minH;
    vector<int> v;
    for(int i=0;i<n;i++){
            minH.push(arr[i]);
            if(minH.size()>k)
                minH.pop();    
    }
    while(minH.size()){
        v.push_back(minH.top());
        minH.pop();
    }
    reverse(v.begin(),v.end());
    return v;
}

// Q.8 kth Largest Subarray sum
int kthLargestSum(int arr[],int n,int k){
    int pre[n]; pre[0] = arr[0];
    for(int i=1;i<n;i++){
        pre[i] = arr[i]+pre[i-1];
    }
    priority_queue<int,vector<int>,greater<int>> minH;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int x = pre[j] - pre[i] + arr[i];
            minH.push(x);
            if(minH.size()>k){
                minH.pop();
            }
        }
    }
    return minH.top();
}

// Q.14 Minimum cost of ropes
long long minCost(long long arr[], long long n) {
    long long cost=0;
    priority_queue<long long,vector<long long>,greater<long long>> minH;
    for(long long i=0;i<n;i++){
        minH.push(arr[i]);
    }
    while(minH.size()>1){
        long long first = minH.top();
        minH.pop();
        long long second = minH.top();
        minH.pop();
        long long sum = first+second;
        cost+=sum;
        minH.push(sum);
    }
    return cost;
}

int main(){

    // int arr[] = {3,5,7,1,0,6,2}; // n=7
    // heapsort(arr,7);
    // for(auto i:arr){
    //     cout<<i<<" ";
    // }
    // int arr[] = { 12, 1, 78, 90, 57, 89, 56 }; // n=7 k=3
    // vector<int> v = maxOfK(arr,7,3);
    // for(auto x:v) cout<<x<<endl;

    // int a[] = { 10, -10, 20, -40 };
    // cout << kthLargestSum(a, 4, 6);

    return 0;
}