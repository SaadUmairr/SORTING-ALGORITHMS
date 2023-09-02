#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define vec vector<ll>
#define ll long long int
using namespace std;

void PrintVec(const vec& arr) {
    for (const int& value : arr) {
        cout << value << '\t';
    }
    cout << endl;
}

void ActualWorker(vec &arr, int left, int middle, int right) // This function does the actual work of Merging and sorting the arrays
{
    int LeftHalf = middle - left + 1, RightHalf = right - middle;
    vec LeftArr(LeftHalf), RightArr(RightHalf);
    for (int i = 0; i < LeftHalf; i++)
        LeftArr[i] = arr[left + i];
    for (int i = 0; i < RightHalf; i++)
        RightArr[i] = arr[middle + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < LeftHalf && j < RightHalf)
    {
        if (LeftArr[i] <= RightArr[j])
        {
            arr[k] = LeftArr[i];
            i++;
        }
        else
        {
            arr[k] = RightArr[j];
            j++;
        }
        k++;
    }
    while (i < LeftHalf)
    {
        arr[k] = LeftArr[i];
        i++, k++;
    }
    while (j < RightHalf)
    {
        arr[k] = RightArr[j];
        j++, k++;
    }
}

void MergeSort(vec& arr, int left, int right)
{
    // This function partitions the array
    if (left >= right)
        return;
    int middle = left + (right - left) / 2;
    MergeSort(arr, left, middle);
    MergeSort(arr, middle + 1, right);
    ActualWorker(arr, left, middle, right);
}

int main()
{
    system("cls");
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int size, el;
    cout << "Enter size of the array: ";
    cin >> size;
    vec arr;
    for (int i = 0; i < size; i++)
        cin >> el, arr.push_back(el);
    cout << "ARRAY BEFORE SORTING:" << endl;
    PrintVec(arr);
    MergeSort(arr, 0, size - 1);
    cout << "ARRAY AFTER SORTING:" << endl;
    PrintVec(arr);
    return 0;
}