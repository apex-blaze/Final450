#include<iostream>

using namespace std;

//Basic Tree Structure
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


int main(){

    return 0;
}