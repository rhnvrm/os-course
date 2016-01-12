#include <bits/stdc++.h>

struct node{
	int data;
	node* next;
}*Stack;


void pop(){
	
	if((Stack == NULL))
		printf("%s\n", "Stack Underflow\n");
	else{
		printf("%d\n", Stack->data);
		Stack = Stack->next;
	}
}

void push(int x){

	node* np;

	np = (node*)malloc(sizeof(node));

	np->data = x;
	np->next = Stack;

	Stack = np;

}

int main(){
	
	push(1);
	push(2);
	push(3);
	pop();
	pop();
	pop();
	pop();


	return 0;
}

