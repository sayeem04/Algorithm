#include<iostream>
using namespace std;
//Binary Searhing Algorithm.

int binarySearch(int arr[], int size, int target) {
    int start = 0;
    int end = size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] > target) {
            end = mid - 1;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            return mid;
        }
    }
}


int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 70;
    int ans = binarySearch(arr, size, target);
    cout << ans << endl; // 6th element is the target.
}
