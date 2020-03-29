#include <iostream>
#define MAX 100
using namespace std;

struct Queue {
	int front;
	int rear;
	int qArr[MAX];
};

void queueInit(Queue *q) {
	q->front = 0;
	q->rear = 0;
}

bool isEmpty(Queue *q) {
	if(q->front == q->rear)
		return true;
	else
		return false;
}

int getNextPos(int pos) {
	if(pos == MAX-1)
		return 0;
	else
		return pos+1;
}

bool push(Queue *q, int data) {
	if(getNextPos(q->rear) == q->front) {
		cout << "Queue is Full" << '\n';
		return false;
	}

	q->rear = getNextPos(q->rear);
	q->qArr[q->rear] = data;
	return true;
}

bool pop(Queue *q, int *data) {
	if(isEmpty(q)) {
		cout << "Queue is Empty" << '\n';
		return false;
	}

	q->front = getNextPos(q->front);
	*data = q->qArr[q->front];
	return true;
}

bool peek(Queue *q, int *data) {
	if(isEmpty(q)) {
		cout << "Queue is Empty" << '\n';
		return false;
	}

	*data = q->qArr[getNextPos(q->front)];
	return true;
}

int main() {

	int data;
	Queue q;
	queueInit(&q);

	push(&q, 1);
	push(&q, 2);
	push(&q, 3);
	push(&q, 4);
	push(&q, 5);

	while(!isEmpty(&q)) {
		pop(&q, &data);
		cout << data << '\n';
	}

	return 0;
}