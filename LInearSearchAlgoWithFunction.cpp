#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
}

int main() {
    int arr[] = {-3, 5, -6, -4, -6, 12, 34, 54, 55, 66, 77, 3, 4, 5, 6, -1};
    int target = 4;
    int size = 0;

    while (arr[size] != -1) {
        size++;
    }
    cout << "Target is found in " << linearSearch(arr, size, target) << "th Index." << endl;
}
