#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define vec vector<ll>
#define ll long long int
using namespace std;

void PrintVec(vec arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << '\t';
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
    QuickSort(arr, low, j-1);
    QuickSort(arr, j + 1, high);
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
    QuickSort(arr, 0, size - 1);
    cout << "ARRAY AFTER SORTING:" << endl;
    PrintVec(arr);
    return 0;
}