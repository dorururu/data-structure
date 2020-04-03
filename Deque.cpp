#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node *prev;
};

struct Deque {
	Node *head;
	Node *tail;
};

void dequeInit(Deque *deq) {
	deq->head = NULL;
	deq->tail = NULL;
}

bool isEmpty(Deque *deq) {
	if(deq->head == NULL)
		return true;
	else
		return false;
}

void addFirst(Deque *deq, int data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = deq->head;

	if(isEmpty(deq))
		deq->tail = newNode;
	else
		deq->head->prev = newNode;

	newNode->prev = NULL;
	deq->head = newNode;
}

void addLast(Deque *deq, int data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = deq->tail;

	if(isEmpty(deq))
		deq->head = newNode;
	else
		deq->tail->next = newNode;

	newNode->next = NULL;
	deq->tail = newNode;
}

bool removeFirst(Deque *deq, int *data) {
	if(isEmpty(deq)) {
		cout << "Deque is Empty" << '\n';
		return false;
	}

	Node *rnode = deq->head;
	*data = deq->head->data;

	deq->head = deq->head->next;
	free(rnode);

	if(deq->head == NULL)
		deq->tail = NULL;
	else
		deq->head->prev = NULL;

	return true;
}

bool removeLast(Deque *deq, int *data) {
	if(isEmpty(deq)) {
		cout << "Deque is Empty" << '\n';
		return false;
	}

	Node *rnode = deq->tail;
	*data = deq->tail->data;

	deq->tail = deq->tail->prev;
	free(rnode);

	if(deq->tail == NULL)
		deq->head = NULL;
	else
		deq->tail->next = NULL;

	return true;
}

bool getFirst(Deque *deq, int *data) {
	if(isEmpty(deq)) {
		cout << "Deque is Empty" << '\n';
		return false;
	}

	*data = deq->head->data;
	return true;
}

bool getLast(Deque *deq, int *data) {
	if(isEmpty(deq)) {
		cout << "Deque is Empty" << '\n';
		return false;
	}

	*data = deq->tail->data;
	return true;
}

int main() {

	int data;
	Deque deq;
	dequeInit(&deq);

	addFirst(&deq, 3);
	addFirst(&deq, 2);
	addFirst(&deq, 1);

	addLast(&deq, 4);
	addLast(&deq, 5);
	addLast(&deq, 6);

	while(!isEmpty(&deq)) {
		removeFirst(&deq, &data);
		cout << data << ' ';
	}
	cout << '\n';

	addFirst(&deq, 3);
	addFirst(&deq, 2);
	addFirst(&deq, 1);

	addLast(&deq, 4);
	addLast(&deq, 5);
	addLast(&deq, 6);

	while(!isEmpty(&deq)) {
		removeLast(&deq, &data);
		cout << data << ' ';
	}
	cout << '\n';

	return 0;
}