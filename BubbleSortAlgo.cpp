#include <iostream>
using namespace std;

int main() {
    int arr[5];

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Take Inputs : " << endl;
    for (int x = 0; x < n; x++) {
        cin >> arr[x];
    }
    cout << "Taken Inputs : " << endl;

    for (int i = 0; i < sizeof(arr) / 4; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j + 1] < arr[j]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Sorting Outputs : " << endl;
    for (int i = 0; i < sizeof(arr) / 4; ++i) {
        cout << arr[i] << " ";
    }
}
