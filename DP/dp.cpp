#include<iostream>
#include<climits>
#include<vector>

using namespace std;
// Q.1 Coin Change Problem
long long coinChange(int arr[],int n,int sum){
	long long t[n+1][sum+1];

	for(int j=0;j<sum+1;j++)	
		t[0][j] = 0;
	for(int i=0;i<n;i++)
		t[i][0] = 1;
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[i-1] <= j){
				t[i][j] = t[i-1][j] + t[i][j-arr[i-1]];
			}else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][sum];
}

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

// Q.14 Longest Common Subsequence (LCS)
	vector<vector<int>> t = vector<vector<int>>(1001,vector<int>(1001,-1)) ;
    
    int lcs(int x, int y, string &s1, string &s2){
        if(x==0 || y==0)
            return 0;
            
        if(t[x][y]!=-1)
            return t[x][y];
        
        if(s1[x-1] == s2[y-1]){
            return t[x][y] = 1 + lcs(x-1,y-1,s1,s2);
        } else{
            return t[x][y] = max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2));
        }
    }

int main(){

    return 0;
}