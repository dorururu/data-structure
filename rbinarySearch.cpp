#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) {
    if(left > right) return -1;

    int mid = (left+right) / 2;

    if(arr[mid] == key) {
        return mid;
    } else if(arr[mid] < key) {
        return binarySearch(arr, mid+1, right, key);
    } else {
        return binarySearch(arr, left, mid-1, key);
    }

}

int main() {
    
    int arr[] = { -3,-2,0,2,3,5,6,10,11,30 };
    int key;
    cin >> key;

    int result = binarySearch(arr, 0, 9, key);

    if(result == -1) cout << "Not Found" << '\n';
    else cout << "key index : " << result << '\n';
    
    return 0;
}