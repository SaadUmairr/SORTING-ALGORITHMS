#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define vec vector<ll>
#define ll long long int
using namespace std;

void PrintVec(const vec &arr)
{
    for (const int &value : arr)
    {
        cout << value << '\t';
    }
    cout << endl;
}

int Partition(vec &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1, j = high;
    while (i <= j)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void QuickSort(vec &arr, int low, int high)
{
    if (low > high)
        return;
    int j = Partition(arr, low, high);
    QuickSort(arr, low, j - 1);
    QuickSort(arr, j + 1, high);
}

int main()
{
    system("cls");
    int size, el;
    cout << "Enter size of the array: ";
    cin >> size;
    if (size <= 0)
    {
        cout << "Size of list can not be negative or zero" << endl;
        return 1;
    }
    vec arr;
    for (int i = 0; i < size; i++)
        cin >> el, arr.push_back(el);
    cout << "INPUT LIST:" << endl;
    PrintVec(arr);
    QuickSort(arr, 0, size - 1);
    cout << "SORTED LIST:" << endl;
    PrintVec(arr);
    return 0;
}