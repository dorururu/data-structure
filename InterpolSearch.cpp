#include <iostream>
#include <queue>
using namespace std;

int interpolSearch(int arr[], int left, int right, int target) {
	if(arr[left] > target || arr[right] < target) return -1;

	int mid = ((double)(target-arr[left]) / (arr[right] - arr[left]) * (right-left)) + left;

	if(arr[mid] == target)
		return mid;
	else if(arr[mid] > target)
		return interpolSearch(arr, left, mid-1, target);
	else
		return interpolSearch(arr, mid+1, right, target);

}

int main() {
	int arr[] = { 0,2,3,5,6,10,11,19,30 };
	int len = sizeof(arr)/sizeof(int);

	int result = interpolSearch(arr, 0, len-1, 19);
	
	if(result == -1) {
		cout << "Not found" << '\n';
	} else {
		cout << "target index : " << result << '\n';
	}
	

	return 0;
}