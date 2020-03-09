#include <iostream>
using namespace std;
 
 
int main() {
 
    //a sorted array
    int arr[] = { -2,-2,0,2,3,5,6,10,11,30 };
 
    int left = 0;
    int right = 9;
 
    int key;
    cin >> key;
 
    while (left <= right) {
        int mid = (left + right) / 2;
 
        if (arr[mid] == key) {
            cout << "key index : " << mid << '\n';
            return 0;
        }
        else if (arr[mid] < key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    cout << "Not found" << "\n";
    
 
    return 0;
}
