#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int x=0){
		data = x;
		next = NULL;
	}
};
	void printList(Node* node){
    	while (node != NULL) {
        	printf("%d ", node->data);
        	node = node->next;
    	}
    	printf("\n");
	}

struct LinkedList{
	Node* head;
	LinkedList(){
		head = NULL;
	}
	void push(int info){
		Node* temp = new Node(info);
		temp->next = head;
		head = temp;
	}
	void print(){
		if(head==NULL) {
			cout<<"Linked List is empty\n";
			return;
		}
		Node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}

	// Q.1 Reverse a Linked List
	// Iterative Approach - Takes three pointers prev,curr,next
	void reverseIter(){
		Node *prev,*curr,*next;
		prev=NULL; curr=next=head;
		if(head == NULL || head->next == NULL)
			return;
		while(curr!=NULL){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
	// Recursive Approach - rest Linked List reversed using recursion
	Node* reverseRec(Node* head){
		if(head == NULL || head->next == NULL)
			return head;
		Node* rest = reverseRec(head->next);
		head->next->next = head;
		head->next = NULL;
		return rest;		
	}
};

// Q.2 Reverse a Linked List in groups of given size
	 Node *reverse (Node *head, int k){ 
		 if(head == NULL || head->next == NULL)
		 	return head;
		Node *curr,*prev,*next;
		curr = next = head;
		prev = NULL; int count=0;
		while(curr!=NULL && count<k){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next; count++;
		}
		if(curr!= NULL){
			head->next = reverse(curr,k);
		}
		return prev;
    }

// Q.3 Detect loop in a Linked List
	 bool detectLoop(Node* head){
        Node *slow,*fast;
		slow=fast=head;
		if(head == NULL || head->next == NULL)
			return false;
		while(slow!=NULL && fast!=NULL && fast->next!=NULL){
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast){
				return true;
			}
		}
		return false;
    }

// Q.4 Delete Loop in a linked List
	void removeLoop(Node* head){
        Node *slow,*fast;
		slow=fast=head;
		if(head == NULL || head->next == NULL)
			return ;
		while(slow!=NULL && fast!=NULL && fast->next!=NULL){
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast){
				break;
			}
		}
		if(slow == fast){

			fast = head;
				if(slow == fast){ // Loop point is our head
					while(slow->next!=fast) {
						slow=slow->next;
					}
				}
				else{
					while(fast->next != slow->next){
						slow=slow->next;
						fast=fast->next;
					}
				}
				slow->next = NULL;
		}
		return;
    }

// Q.5 Starting point of Loop
Node* loopPoint(Node* head){
	Node* slow,*fast;
	slow=fast=head;
	if(head == NULL && head->next == NULL)
		return NULL;
	while(slow && fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			break;
	}
	if(slow == fast){
		fast = head;
		if(slow == fast)
			return head;
		while(slow!=fast){
			slow=slow->next;
			fast=fast->next;
		}
		return slow;
		
	}else{
		return NULL;
	}
}

// Q.6 Remove duplicates in sorted LL
	Node *removeDuplicates(Node *head){

		Node* temp; temp=head;
		if(temp==NULL){
			return NULL;
		}
		while(temp->next!=NULL){
			if(temp->data == temp->next->data){
				Node* p = temp->next;
				temp->next = temp->next->next;
				delete p;
			}else{
				temp=temp->next;
			}
		}
		return head;
	}

// Q.7 Remove duplicates in unsorted LL
	Node * removeDuplicatesUn( Node *head) {
		unordered_map<int,bool> mp;
		Node* temp = head,*prev = NULL; 
		if(temp == NULL)
			return NULL;
		while(temp!=NULL){
			if(mp[temp->data]){
				prev->next = temp->next;
				delete temp;
			}else{
				mp[temp->data] = true;
				prev = temp;
			}
			temp = prev->next;
		}
		return head;
    }
// Q.8 Move last element to first in LL
	void moveToFront(Node **head){
		Node* temp = *head,*prev=NULL;
		if(temp == NULL && temp->next == NULL)
			return;
		while(temp->next!=NULL){
			prev = temp;
			temp = temp->next;
		}
		temp->next = *head;
		*head = temp;
		prev->next = NULL;
	}

// Q.9 Add '1' to the number represented by LL
	Node* addOne(Node *head){
        Node* temp=head,*prev;
		if(head==NULL)
			return NULL;
		if(head->next==NULL){
			head->data++;
			return head;
		}
		Node* non9=NULL;
		while(temp->next!=NULL){
			if(temp->data!=9){
				non9 = temp;
			}
			temp=temp->next;
		}
		if(non9){
			if(temp->data != 9){ // means last node is non9
				temp->data++;
			}else{
				non9->data++;
				temp = non9->next;
				while(temp){
					temp->data = 0;
					temp = temp->next;
				}
			}
			return head;
		}else{
			temp = head;
			while(temp){
				temp->data = 0;
				temp=temp->next;
			}
			Node* neu = new Node(1);
			neu->next = head;
			return neu;
		}
		
    }

// Q.10 Add two no.s represented by two LLs
	struct Node* addTwoLists(struct Node* first, struct Node* second){
		Node* ans = NULL;
		stack<Node*>s1,s2,s3;
		while(first!=NULL){
			s1.push(first);
			first=first->next;
		}
		while(second!=NULL){
			s2.push(second);
			second=second->next;
		}
		int carry = 0;
		while(!s1.empty() && !s2.empty()){
			int sum = s1.top()->data + s2.top()->data + carry;
			s1.pop(); s2.pop();
			Node* newNode = new Node(sum%10);
			s3.push(newNode);
			carry = sum>9?1:0;
		}
		while(!s1.empty()){
			int sum = s1.top()->data + carry;
			s1.pop();
			Node* newNode = new Node(sum%10);
			s3.push(newNode);
			carry = sum>9?1:0;
		}
		while(!s2.empty()){
			int sum = s2.top()->data + carry;
			s2.pop();
			Node* newNode = new Node(sum%10);
			s3.push(newNode);
			carry = sum>9?1:0;
		}
		if(carry){
			Node* newNode = new Node(carry);
			s3.push(newNode);
		}
		if(!s3.empty()){  // s3 will be empty only when both given LLs are empty
			ans = s3.top();
		}
		while(!s3.empty()){
			Node* temp = s3.top();
			s3.pop();
			if(s3.size() == 0){
				temp->next = NULL;
			}else{
				temp->next = s3.top();
			}
		}
		return ans;

    }

// Q.11 Intersection of two sorted LLs
	Node* findIntersection(Node* head1, Node* head2){
    	Node *a,*b,*ans= NULL,*temp=NULL; 
		
		a = head1; b = head2;
		if(head1 == NULL || head2 == NULL)
			return NULL;
		while(a!=NULL && b!=NULL){
			if(a->data == b->data){
				if(ans==NULL && temp == NULL){
					ans = new Node(a->data);
					temp = ans;
				}else{
					temp->next = new Node(a->data);
					temp= temp->next;
				}
				a = a->next; b= b->next;
			}else if(a->data < b->data){
				a = a->next;
			}else{
				b = b->next;
			}
		}
		return ans;
	}

// Q.12 Intersection point of two LL
	int intersectPoint(Node* head1, Node* head2){
		Node* temp1= head1, *temp2= head2; int n=0,m=0;

		if(head1 == NULL || head2 == NULL){
			return -1;
		}
		while(temp1){
			temp1=temp1->next; n++;
		}
		while(temp2){
			temp2 = temp2->next; m++;
		}
		int diff = abs(n-m);
		temp1 = head1; temp2=head2;
		if(n>m){
			while(diff--){
				temp1=temp1->next;
			}
		}else{
			while(diff--){
				temp2=temp2->next;
			}
		}
		while(temp1 && temp2 && temp1 != temp2){
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if(temp1==temp2) 
			return temp1->data;
		else
			return -1;
	}

// Q.15 Middle element of LL
	 Node* middleNode(Node* head) {
        Node* slow=head,*fast = head;
        if(head==NULL || head->next==NULL){
            return head;
        }
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

int main(){
	//   Node* head = new Node(1);
    // head->next = new Node(9);
    // head->next->next = new Node(9);
    // head->next->next->next = new Node(9);
 
    // printf("List is ");
    // printList(head);
 
    // head = addOne(head);
 
    // printf("\nResultant list is ");
    // printList(head);

    return 0;
}