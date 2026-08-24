#include<iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int swapped;

    for (int round = 0; round < size; round++) {
        swapped = 0;
        for (int i = 0; i < size - 1 - round; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}
