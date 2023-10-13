#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <limits>

#define vec vector<int>
using namespace std;

void PrintVec(vector<int> arr) {
    for (auto &i : arr)
        cout << i << '\t';
    cout << endl;
}

int inputNumber() {
    int num;
    cin >> num;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("INPUT MUST BE A NUMBER");
    }
    return num;
}

void CubeSort(vec &arr) {
    int size = arr.size();
    int n = size;
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        n--;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    system("cls");
    int size, el;
    try {
        cout << "Enter size of the array: ";
        size = inputNumber();
        if (size <= 0)
            throw runtime_error("Size of list cannot be negative or zero");
        vec arr;
        for (int i = 0; i < size; i++)
            el = inputNumber(), arr.push_back(el);
        cout << "INPUT LIST:" << endl;
        PrintVec(arr);
        CubeSort(arr);
        cout << "SORTED LIST:" << endl;
        PrintVec(arr);
    } catch (runtime_error e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
