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

// Q.1 Level Order Traversal O(n)

void levelOrder(Node* root){
    if(root == NULL) 
     return;
    queue<Node*> q;
    q.push(root); q.push(NULL);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
            cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);
            
            if(node->right)
                q.push(node->right);
            
        }else if(!q.empty()){
            q.push(NULL);
        }
    }
    cout<<"\n";
}

int main(){

    return 0;
}