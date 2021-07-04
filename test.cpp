#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<unordered_map>
#include<climits>

using namespace std;

bool isPalindrome(char S[]){
    int n = strlen(S);
    for(int i=0;i<n;i++){
        if(S[i] != S[n-i-1]) 
            return false;
    }
    return true;
}

bool isPalindrom(string s){
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
        return true;
    }
}

string longestPalin(string S) {
    int n = S.size(); string ans;
    int max = INT_MIN;
    cout<<max<<endl;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string curr;
            curr = S.substr(i,abs(j-i+1));
            if(isPalindrom(curr)){
                // cout<<(curr.size()>max)<<endl;
                
                if(curr.size() > max){
                    ans = curr;
                    max = curr.size();
                    // cout<<max<<endl;
                }
            }
        }
    }
    return ans;
}  

int main(){
    cout<<longestPalin("aaaabbaa")<<endl;
    return 0;
} 
