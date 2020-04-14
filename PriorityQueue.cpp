#include <iostream>
#define MAX 100
using namespace std;


typedef int PriorityComp (int d1, int d2);

struct Heap {
	PriorityComp *comp;
	int numOfData;
	int heapArr[MAX];
};

void heapInit(Heap *ph, PriorityComp pc) {
	ph->numOfData = 0;
	ph->comp = pc;
}

int isEmpty(Heap *ph) {
	if(ph->numOfData == 0)
		return true;
	else
		return false;
}

int getParent(int idx) {
	return idx/2;
}

int getLeftChild(int idx) {
	return idx*2;
}

int getRightChild(int idx) {
	return idx*2+1;
}

int getHighPriorityChild(Heap *ph, int idx) {
	int leftChild = getLeftChild(idx);
	int rightChild = getRightChild(idx);

	if(leftChild > ph->numOfData) {
		return 0;
	} else if(leftChild == ph->numOfData) {
		return leftChild;
	} else {
		if(ph->comp(ph->heapArr[leftChild], ph->heapArr[rightChild]) < 0)
			return rightChild;
		else
			return leftChild; 
	}
}

void insert(Heap *ph, int data) {
	int idx = ph->numOfData + 1;

	int parentIdx;
	while(idx != 1) {
		parentIdx = getParent(idx);
		if(ph->comp(data, ph->heapArr[parentIdx]) > 0) {
			ph->heapArr[idx] = ph->heapArr[parentIdx];
			idx = parentIdx;
		}
		else break;
	}

	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

int pop(Heap *ph) {
	int rdata = ph->heapArr[1];
	int lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while(childIdx = getHighPriorityChild(ph, parentIdx)) {
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0) break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return rdata;
}

int pcmp(int num1, int num2) {
	return num1 - num2;
}


int main() {

	Heap heap;
	heapInit(&heap, pcmp);

	insert(&heap, 1);
	insert(&heap, 2);
	insert(&heap, 3);

	cout << pop(&heap) << '\n';

	insert(&heap, 1);
	insert(&heap, 2);
	insert(&heap, 3);

	cout << pop(&heap) << '\n';

	while(!isEmpty(&heap))
		cout << pop(&heap) << '\n';


	return 0;
}