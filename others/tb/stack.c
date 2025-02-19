#include<stdio.h>

int size,stack[20],top;

int peek();
int isFull();
int isEmpty();
void push(int);
int pop(int);

void main(){
	int c,op;
	printf("Enter size of stack");
	scanf("%d",&size);
	printf("Enter choice 1.peek 2.full or not 3.empty or not 4.push 5.pop");
	scanf("%d",&c);
	switch(c){
		case 1: peek();
			break;
		case 2: isFull();
		    break;
		case 3: isEmpty();
		    break;
		case 4: push();
		    break;
		case 5: pop();
		    break;
		default: printf("Invalid input");
		}
	}
	
}

int peek() {
 return stack[top];
}

int isFull() {
 if(top == MAXSIZE)
 return 1;
 else
 return 0;
}

int isEmpty() {
 if(top == -1)
 return 1;
 else
 return 0;
}

void push(int data) {
 if(!isFull()) {
 top = top + 1; 
 stack[top] = data;
 } else {
 printf("Could not insert data, Stack is full.\n");
 }
}

int pop(int data) {
 if(!isEmpty()) {
 data = stack[top];
 top = top - 1; 
 return data;
 } else {
 printf("Could not retrieve data, Stack is empty.\n");
 }
}
