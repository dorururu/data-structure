#include <iostream>
using namespace std;

void insertionSort(int num[], int n) {
	int pivot;
	int i, j;
	for(i=1; i<n; i++) {
		pivot = num[i];
		for(j=i-1; j>=0; j--) {
			if(pivot < num[j]) num[j+1] = num[j];
			else break;
		}
		num[j+1] = pivot;
	}
}

int main() {

	int n = 10;
	int num[] = { 13,25,9,12,34,52,49,17,5,8 };
   
	insertionSort(num, n);
	for(int i=0; i<n; i++) cout << num[i] << ' ';

	return 0;
}