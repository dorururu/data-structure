#include <iostream>
#define MAX 100
using namespace std;

int top = -1;
int stack[MAX+1];

void push(int num) {
	if(top == MAX) {
		cout << "Stack is full" << '\n';
		return;
	}

	stack[++top] = num;
}

int pop() {
	if(top == -1) {
		cout << "Stack is empty" << '\n';
		return -1;
	}

	top--;

	return stack[top];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	int command, value;
	while(T--) {

		cin >> command; //1 : push, 2 : pop,  3 : print top

		if(command == 1) {
			cin >> value;
			push(value);
		} else if(command == 2) {
			pop();
		} else if(command == 3) {
			cout << stack[top] << '\n';
		}

	}
	
	
	return 0;
}