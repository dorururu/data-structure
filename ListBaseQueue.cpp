#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

struct Queue {
	Node *front;
	Node *rear;
};

void queueInit(Queue *q) {
	q->front = NULL;
	q->rear = NULL;
}

bool isEmpty(Queue *q) {
	if(q->front == NULL)
		return true;
	else
		return false;
}

void push(Queue *q, int data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if(isEmpty(q)) {
		q->front = newNode;
		q->rear = newNode;
	} else {
		q->rear->next = newNode;
		q->rear = newNode;
	}
}

bool pop(Queue *q, int *data) {
	if(isEmpty(q)) {
		cout << "Queue is Empty" << '\n';
		return false;
	}
	
	Node *rNode;
	int rdata;

	rdata = q->front->data;
	rNode = q->front;
	q->front = q->front->next;

	free(rNode);
	*data = rdata;
	return true;
}

bool peek(Queue *q, int *data) {
	if(isEmpty(q)) {
		cout << "Queue is Empty" << '\n';
		return false;
	}

	*data = q->front->data;
	return true;
}

int main() {

	Queue q;
	queueInit(&q);

	push(&q, 1);
	push(&q, 2);
	push(&q, 3);
	push(&q, 4);
	push(&q, 5);
	
	int data;
	while(!isEmpty(&q)) {
		pop(&q, &data);
		cout << data << '\n';
	}


	return 0;
}