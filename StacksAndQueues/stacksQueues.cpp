#include<iostream>
#include<climits>
#include<stack>
#include<queue>
using namespace std;

// Q.1 Implement Stack from Scratch
class Stack{
	int top,capacity,size;
	int *arr;
	public:
	Stack(int n=10){
		arr = new int[n];
		top = -1;
		capacity = n;
		size = 0;
	}
	void push(int x){
		if(top == capacity-1){
			return;
		}
		arr[++top] = x;
		size++;
	}

	int pop(){
		if(top == -1){
			return INT_MIN;
		}
		return arr[top--];
		size--;
	}
	int peek(){
		if(top == -1){
			return INT_MIN;
		}
		return arr[top];
	}
	void clear(){
		top = -1;
		size = 0;
	}
	bool isEmpty(){
		return top == -1;
	}
};

// Q.2 Implement Queue from Scratch

class Queue{
	int Front,Rear,capacity,size;
	int* arr;
	public:
	Queue(int n=10){
		arr = new int[n];
		Front = -1;
		Rear = -1;
		capacity = n;
		size = 0;
	}

	bool isFull(){
		return size == capacity;
	}

	bool isEmpty(){
		return size == 0;
	}

	void enqueue(int x){
		if(isFull()){
			return;
		}
		if(isEmpty()){
			Front++;
		}
		Rear = (Rear + 1)%capacity;
		arr[Rear] = x;
		size++;
	}

	int dequeue(){
		if(isEmpty()){
			return INT_MIN;
		}
		int ans;
		if(Front == Rear){
		    ans = arr[Front];
			Front = Rear = -1;
			return ans;
		}
		ans = arr[Front];
		Front = (Front + 1)%capacity;
		size--;
		return ans;
	}

	int front(){
		if(isEmpty()){
			return INT_MIN;
		}
		return arr[Front];
	}
	int rear(){
		if(isEmpty()){
			return INT_MIN;
		}
		return arr[Rear];
	}
	void clear(){
		Rear = Front = -1;
		size = 0;
	}
};

// Q.3 Implement 2 Stacks in an array

class TwoStack{
	int top1,top2,capacity;
	int *arr;
	public:
	TwoStack(int n=10){
		top1 = -1; top2 = n;
		arr = new int[n];
		capacity = n;
	}
	void push1(int x){
		if(top1 >= top2-1){
			return;
		}
		arr[++top1] = x;
	}
	void push2(int x){
		if(top2 <= top1+1){
			return;
		}
		arr[--top2] = x;
	}
	int pop1(){
		if(top1 == -1)
			return INT_MIN;
		return arr[top1--];
	}
	int pop2(){
		if(top2 == capacity)
			return INT_MIN;
		return arr[top2++];
	}
	
};

// Q.4 Implement Middle Element Stack 
class MidStack{
	class DLL{
		public:
		int data;
		DLL *prev,*next;
		DLL(int y){
			data = y;
			prev = NULL;
			next = NULL;
		}
	};
	int size;
	DLL *top,*mid;
	public:
	MidStack(){
		size = 0;
		top = NULL;
		mid = NULL;
	}

	void push(int x){
		DLL *newNode = new DLL(x);
		newNode->next = top;
		top = newNode;
		size++;
		if(size == 1){
			mid = top;
			return;
		}
		if(size%2 == 0){
			mid = mid->prev;
		}
	}

	int pop(){
		if(top == NULL){
			return INT_MIN;
		}
		int ans;
		if(top->next == NULL){
			ans = top->data;
			delete top;
			top == NULL; mid == NULL;
			size--;
			return ans;
		}
		DLL *temp = top;
		ans = temp->data;
		size--;
		if(size%2){
			mid = mid->next;
		}
		top = top->next;
		delete temp;
		return ans;
	}
	int middle(){
		if(mid==NULL){
			return INT_MIN;
		}
		return mid->data;
	}

	int delMiddle(){
		if(mid==NULL)
			return INT_MIN;
		int deleted = mid->data;
		size--;
		if(mid->next == NULL && mid->prev == NULL){
			mid == NULL;
			return deleted;
		}
		if(size%2 == 0){
			mid = mid->prev;
		}else{
			mid = mid->next;
		}
		return deleted;
	}

};

// Q.5 Implement K stacks in an array
class NStacks{
	int *topOfStack;
	int *arr;
	int *next; int free;
	int capacity,stacks;
	public:
	NStacks(int n=10,int k=3){
		capacity = n; stacks = k;
		topOfStack = new int[k];
		fill_n(topOfStack,k,-1);
		arr = new int[n];
		for(int i=0;i<n-1;i++){
			next[i] = i+1;
		}
		next[n-1] = -1;
		free = 0;
	}
	void push(int k,int x){
		if(k<0 || k>=stacks)
			 return;
		if(free < 0) // Stack Overflow
			return;
		int currIndex = free;
		free = next[currIndex];
		arr[currIndex] = x;
		next[currIndex] = topOfStack[k];
		topOfStack[k] = currIndex;
	}

	int pop(int k){
		if(k<0 || k>=stacks)
			return INT_MIN;
		if(topOfStack[k] == -1) // Stack underflow
			return INT_MIN;

		int currIndex = topOfStack[k];
		int ans = arr[currIndex];
		topOfStack[k] = next[currIndex];
		next[currIndex] = free;
		free = currIndex;
	}
};

int main(){
	
    return 0;
}