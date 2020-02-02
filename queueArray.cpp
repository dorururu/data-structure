#include <iostream>
#define MAX 100
using namespace std;

int front = 0;
int rear = 0;
int queue[MAX];

bool isEmpty() {
   if(front == rear) {
      cout << "Queue is empty" << '\n';
      return true;
   }

   return false;
}

bool isFull() {
   if((rear+1) % MAX == front) {
      cout << "Queue is full" << '\n';
      return true;
   }

   return false;
}

void push(int num) {
   if(isFull()) {
      return;
   }

   queue[rear++] = num;
   if(rear == MAX) rear = 0;
}

int pop() {
   if(isEmpty()) {
      return -1;
   }

   int rt = queue[front++];
   if(front == MAX) front = 0;

   return rt;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);


   int T;
	cin >> T;

	int command, value;
	while(T--) {

		cin >> command; //1 : push, 2 : pop,  3 : print front

		if(command == 1) {
			cin >> value;
         push(value);
		} else if(command == 2) {
         pop();
		} else if(command == 3) {
         if(!isEmpty()) cout << queue[front] << '\n';
		}

	}


   return 0;
}