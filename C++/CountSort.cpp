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


vec CountSort(vec &arr)
{
    ll high = arr[0], i;
    for (i = 0; i < arr.size(); i++)
        high = max(high, arr[i]);
    vec freq(high + 1, 0);
    for (i = 0; i < arr.size(); i++)
        freq[arr[i]]++;
    for (i = 1; i <= high; i++)
        freq[i] += freq[i - 1];
    vec sorted(arr.size());
    for (i = high - 1; i >= 0; i--)
        sorted[--freq[arr[i]]] = arr[i];
    return sorted;
}

int main()
{
    system("cls");
    int size, el;
    cout << "Enter size of the array: ";
    cin >> size;
    if (size <= 0)
    {
        cout << "Size of list can not be negative" << endl;
        return 1;
    } 
    vec arr;
    for (int i = 0; i < size; i++)
        cin >> el, arr.push_back(el);
    cout << "ARRAY BEFORE SORTING:" << endl;
    PrintVec(arr);
    arr = CountSort(arr);
    cout << "ARRAY AFTER SORTING:" << endl;
    PrintVec(arr);
    return 0;
}