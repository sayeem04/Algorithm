#include<iostream>
using namespace std;

int main() {
    int arr[] = {5, 8, 6, 1, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x;
    for (int i = 0; i < size; i++) {
        x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
