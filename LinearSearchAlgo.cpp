#include<iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 1;
    int found = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            found = 1;
            break;

        }
    }
    if (found == 1) {
        cout << "Target is Found" << endl;
    } else {
        cout << "Target is not Found" << endl;
    }
}
