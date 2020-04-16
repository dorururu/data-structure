#include <iostream>
using namespace std;

void bubbleSort(int num[], int n) {

	int tmp;
	for(int i=0; i<n-1; i++) {
		bool swapFlag = false;
		for(int j=0; j<n-i-1; j++) {
			if(num[j] > num[j+1]) {
				tmp = num[j];
				num[j] = num[j+1];
				num[j+1] = tmp;

				swapFlag = true;
			}
		}
		if(!swapFlag) break;
	}

}

int main() {

	int n = 10;
	int num[] = { 13,25,9,12,34,52,49,17,5,8 };
    bubbleSort(num, n);

	for(int i=0; i<n; i++) cout << num[i] << ' ';

	return 0;
}