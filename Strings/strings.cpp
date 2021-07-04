#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<unordered_map>


using namespace std;

// Q.1 Reverse a string
void reverse(vector<char>& v){
    int n = v.size(); 
    for(int i=0;i<n/2;i++){
        swap(v[i],v[n-1-i]);
    }
}

// Q.2 Check if string is Palindrome or not
int isPalindrome(char S[]){
    int n = strlen(S);
    for(int i=0;i<n;i++){
        if(S[i] != S[n-i-1]) 
            return false;
    }
    return true;
}

// Q.3 Print Duplicate chars in string along with their frequency
void printDups(string s){
     unordered_map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }

    for(auto i:mp){
        if(i.second > 1){
            cout<<i.first<<" -> "<<i.second<<endl;
        }
    }
}

// Q.4 Check if a string is rotation of another
bool areRotations(string a,string b){
    if(a.size() != b.size())
      return false;
    string temp = a+a;
    if(temp.find(b) == -1){
        return false;
    }
    return true;
}

// Q.5 Check if a string is valid shuffle of two strings


// Q.6 Count and Say Problem
string countAndSay(int n) {
    if(n == 1){
        return "1";
    }
    string s = countAndSay(n-1);
    int size = s.length(),cnt=1;
    string ans;
    for(int i=1;i<size;i++){
        if(s[i] == s[i-1]){
            cnt++;
        }else{
            ans = ans + to_string(cnt) + s[i-1];
            cnt = 1;
        }
    }
    ans = ans + to_string(cnt) + s[size-1];
    return ans;    
}

// Q.7 Longest Palindromic Substring


int main(){

    return 0;
}


