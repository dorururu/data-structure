#include <iostream>
using namespace std;

void swap(int arr[], int idx1, int idx2) {
	int tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}

int partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left+1;
	int high = right;

	while(low <= high) {
		while(arr[low] <= pivot && low <= right) low++;
		while(arr[high] >= pivot && high >= (left+1)) high--;

		if(low <= high) swap(arr, low, high);
	}

	swap(arr, left, high);
	return high;
}

void quickSort(int arr[], int left, int right) {
	if(left > right) return;

	int pivot = partition(arr, left, right);
	quickSort(arr, left, pivot-1);
	quickSort(arr, pivot+1, right);
}

int main() {

	int arr[] = { 10,15,34,29,3,40,9,17,37 };

	quickSort(arr, 0, 8);

	for(int i=0; i<9; i++) cout << arr[i] << ' ';

	return 0;
}