#include<iostream>
using namespace std ;

int main() {
    int arr[] = {4, 6, 7, 8, 9, 45, 56, 67, 78, 100, 110, 123};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 67;
    int found = 0;
    int start = 0;
    int end = size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] > target) {
            end = mid - 1;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        cout << "Target is found. And this is : " << target << endl;
    } else {
        cout << "Target id not found.";
    }
}
