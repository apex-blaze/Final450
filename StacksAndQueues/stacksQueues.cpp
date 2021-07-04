#include<iostream>
#include<climits>
#include<stack>
#include<queue>
using namespace std;

// Q.1 Implement Stack from Scratch
class Stack{
	int top,capacity;
	int *arr;
	public:
	Stack(int n=10){
		arr = new int[n];
		top = -1;
		capacity = n;
	}
	void push(int x){
		if(top == capacity-1){
			return;
		}
		arr[++top] = x;
	}

	int pop(){
		if(top == -1){
			return INT_MIN;
		}
		return arr[top--];
	}
	int peek(){
		if(top == -1){
			return INT_MIN;
		}
		return arr[top];
	}
	void clear(){
		top = -1;
	}
	bool isEmpty(){
		return top == -1;
	}
};


int main(){
	
    return 0;
}