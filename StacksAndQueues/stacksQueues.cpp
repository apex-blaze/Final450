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


int main(){
	
    return 0;
}