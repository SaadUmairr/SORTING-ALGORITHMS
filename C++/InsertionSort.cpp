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

void InsertionSort(vec &arr)
{
    int size = arr.size();
    for (int i = 1; i < size; i++)
    {
        int min = i;
        while (arr[min - 1] > arr[min] && min > 0)
        {
            swap(arr[min - 1], arr[min]);
            min--;
        }
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
    InsertionSort(arr);
    cout << "SORTED LIST:" << endl;
    PrintVec(arr);
    return 0;
}