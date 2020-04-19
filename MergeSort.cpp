#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
	int tmp[9];
	

	int l = left;
	int r = mid+1;

	int index = left;
	while(l <= mid && r <= right) {
		if(arr[l] <= arr[r]) {
			tmp[index++] = arr[l++];
		} else {
			tmp[index++] = arr[r++];
		}
	}

	while(l<=mid) tmp[index++] = arr[l++];
	while(r<=right) tmp[index++] = arr[r++];

	for(int i=left; i<=right; i++) arr[i] = tmp[i]; 

}

void mergeSort(int arr[], int left, int right) {
	if(left >= right) return;

	int mid = (left + right) / 2;

	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);

	merge(arr, left, mid, right);
}

int main() {

	int arr[] = { 40,15,34,29,3,10,9,17,37 };
    mergeSort(arr, 0, 8);

	for(int i=0; i<9; i++) cout << arr[i] << ' ';

	return 0;
}