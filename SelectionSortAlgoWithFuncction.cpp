#include<iostream>
using namespace std;
// Selection Sort Algorithm :

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {-5, -4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
}
