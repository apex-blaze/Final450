#include<iostream>
#include<climits>

using namespace std;

// Q.2  0-1 Knapsack
// Bottom Up Approach
   int knapSack(int W, int wt[], int val[], int n) 
    { 
       int t[n+1][W+1];
       for(int i=0;i<n+1;i++){
           for(int j=0;j<W+1;j++){
               if(i==0 || j==0){
                   t[i][j] = 0;
               }
               else if(wt[i-1] <= j){
                   t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j] );
               }else{
                   t[i][j] = t[i-1][j];
               }
           }
       }
       return t[n][W];
    }

// Q.8 Equal Partition Sum

bool subsetSum(int arr[],int n,int sum){
	bool t[n+1][sum+1];
	for(int j=0;j<sum+1;j++){
		t[0][j] = false;
	}
	for(int i=0;i<n+1;i++){
		t[i][0] = true;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[i-1] <= j){
				t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
			}else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][sum];
}

/*
	let s1,s2 be two partitions 
	=> s1=s2 ---eq1
	=> s1+s2 = sum --eq2
	=> s1 = sum/2							
	s1 should be integer value only otherwise return false
	Now find subsetSum(sum/2)!!
*/

  int equalPartition(int N, int arr[])
    {
		long long sum=0;
		for(int i=0;i<N;i++){
			sum+=arr[i];
		}
		
		if(sum%2) 
			return 0;
		else
		    return subsetSum(arr,N,sum/2);
		
    }

int main(){

    return 0;
}