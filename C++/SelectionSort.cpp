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

void SelectionSort(vec &arr)
{
    int size = arr.size(), i, j, min;

    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;
        if (min != i)
            swap(arr[i], arr[min]);
    }
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
    SelectionSort(arr);
    cout << "SORTED LIST:" << endl;
    PrintVec(arr);

    return 0;
}