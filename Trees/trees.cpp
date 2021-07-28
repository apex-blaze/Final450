#include<bits/stdc++.h>

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

/**** Helper Functions ****/

int height(Node*);

void currentLevel(Node* root,int lvl){

    if(root==NULL)
        return;
    if(lvl==1){
        cout<<root->data<<" ";
        return;
    }
    currentLevel(root->left,lvl-1);
    currentLevel(root->right,lvl-1);
}

// Q.1 Level Order Traversal 

// Method 1 - Using Recursion O(n^2)

void lvlOrder(Node* root){
    int ht = height(root);
    for(int i=1;i<=ht;i++){
        currentLevel(root,i);
    }
}

// Method 2 - Using Queue O(n)
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

// Q.2 Reverse Level Order
    vector<int> reverseLevelOrder(Node *root){
        vector<int>v;
        if(root==NULL)
            return v;
        queue<Node*>q;
        q.push(root); q.push(NULL);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(node){
                v.push_back(node->data);
                if(node->right){
                    q.push(node->right);
                }
                if(node->left){
                    q.push(node->left);
                }
            }else if(!q.empty()){
                q.push(NULL);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }

// Q.3 Height of tree
    int height(Node* root){
    if(root==NULL)
        return 0;
    
    int leftH = height(root->left);
    int rightH = height(root->right);

    return 1+max(leftH,rightH);
}

// Q.4 Diameter of Tree
    int diameter(Node* root) {
        if(root==NULL)
            return 0;
        
        int left = diameter(root->left);
        int right = diameter(root->right);
        int lh = height(root->left);
        int rh = height(root->right);
        int thro = lh+1+rh;
        return max(thro,max(left,right));
    }

// Q.5 Mirror of tree
    Node* mirrorTree(Node* root){
        if(root==NULL)
            return root;
        
        Node* left=mirrorTree(root->left);
        Node* right=mirrorTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }

// Q.6 Inorder Traversal

// Method 1 - Using Recursion
    void inOrder(Node* root){
        if(root==NULL)
            return;
        
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
//Method 2 - Iterative Approach
    void inorder(Node* root){
        stack<Node*> s;
        Node* temp = root;
        
        while(!s.empty() || temp){

            if(temp){
                s.push(temp);
                temp = temp->left;
            }else{
                temp = s.top();
                s.pop();
                cout<<temp->data<<" ";
                temp = temp->right;
            }
        }
    }

// Q.7 Preorder Traversal 
    // Method 1 - Using Recursion
    void preOrder(Node* root){
        if(root==NULL)
            return;
        
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    // Method 2 - Iterative Approach
    void preorder(Node* root){
        if(root == NULL)
            return;
        
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){

            Node* temp = s.top(); 
            s.pop();
            cout<<temp->data<<" ";

            if(temp->right)
                s.push(temp->right);

            if(temp->left)
                s.push(temp->left);
        }
    }

// Q.8 Post Order Traversal 
    //Method 1 - Using Recursion
    void postOrder(Node *root){
        if(root == NULL)
            return;
        
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }

    // Method 2 - Iterative Approach
    void postorder(Node *root){
        if(root == NULL)
            return;
        
        stack<Node*> s;
        s.push(root);
        stack<int> out;

        while(!s.empty()){
            Node* temp = s.top();
            s.pop();
            out.push(temp->data);

            if(temp->left)
                s.push(temp->left);
            if(temp->right)
                s.push(temp->right);
        }
        while(!out.empty()){
            cout<<out.top()<<" ";
            out.pop();
        }

    }

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // lvlOrder(root);
    // inorder(root);
    // preorder(root);
    // postorder(root);

    // Node* tree = new Node(5);
    // tree->left = new Node(3);
    // tree->right = new Node(6);
    // tree->left->left = new Node(2);
    // tree->left->right = new Node(4);
    // printf("Inorder of original tree: ");
    // inorder(tree);
 
    // // Function call
    // mirrorTree(tree);
 
    // printf("\nInorder of Miror tree: ");
    // inorder(tree);

    return 0;
}