#include <iostream>
#include <queue>
#define BUCKET_NUM 10
using namespace std;

void radixSort(int arr[], int num, int maxlen) {
	queue<int> buckets[BUCKET_NUM];
	int pos;
	int divfac = 1;
	int radix;

	for(pos=0; pos<maxlen; pos++) {

		for(int i=0; i<num; i++) {
			radix = (arr[i] / divfac) % 10;
			buckets[radix].push(arr[i]);
		}

		for(int i=0, j=0; i<BUCKET_NUM; i++) {
			while(!buckets[i].empty()) {
				arr[j++] = buckets[i].front();
				buckets[i].pop();
			}
		}

		divfac *= 10;
	}
}


int main() {
	int arr[] = { 13,212,14,7141,10987,6,15 };
	int len = sizeof(arr)/sizeof(int);

	radixSort(arr, len, 5);
	
	for(int i=0; i<len; i++) cout << arr[i] << ' ';

	return 0;
}