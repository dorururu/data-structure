#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

struct Stack {
	Node *head;
};

void stackInit(Stack *pstack) {
	pstack->head = NULL;
}

bool isEmpty(Stack *pstack) {
	if(pstack->head == NULL) return true;
	else return false;
}

void push(Stack *pstack, int data) {
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

int pop(Stack *pstack) {
	int rdata;
	Node *rnode;

	if(isEmpty(pstack)) {
		cout << "Error : Stack is Empty" << '\n';
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);
	return rdata;
}

int peek(Stack *pstack) {
	if(isEmpty(pstack)) {
		cout << "Error : Stack is Empty" << '\n';
		exit(-1);
	}

	return pstack->head->data;
}

int main() {

	Stack st;
	stackInit(&st);
	
	push(&st, 1);
	push(&st, 2);
	push(&st, 3);
	push(&st, 10);
	push(&st, 8);
	push(&st, 7);

	cout << peek(&st) << '\n';

	while(!isEmpty(&st))
		cout << pop(&st) << '\n';

	return 0;
}