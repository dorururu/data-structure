#include <iostream>
using namespace std;

void selectionSort(int num[], int n) {
	int minIdx;
	int tmp;
	for(int i=0; i<n-1; i++) {
		minIdx = i;
		for(int j=i+1; j<n; j++) {
			if(num[minIdx] > num[j]) {
				minIdx = j;
			}
		}
		tmp = num[i];
		num[i] = num[minIdx];
		num[minIdx] = tmp;
	}
}

int main() {

	int n = 10;
	int num[] = { 13,25,9,12,34,52,49,17,5,8 };
   
	selectionSort(num, n);
	for(int i=0; i<n; i++) cout << num[i] << ' ';

	return 0;
}