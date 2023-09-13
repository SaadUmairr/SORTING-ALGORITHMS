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

void CountSort(vec &arr)
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
    arr = sorted;
}
int inputNumber()
{
    int num;
    cin >> num;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("INPUT MUST BE A NUMBER");
    }
    return num;
}

int main()
{
    system("cls");
    int size, el;
    try
    {
        cout << "Enter size of the array: ";
        size = inputNumber();
        if (size <= 0)
            throw runtime_error("Size of list can not be negative or zero");
        vec arr;
        for (int i = 0; i < size; i++)
            el = inputNumber(), arr.push_back(el);
        cout << "INPUT LIST:" << endl;
        PrintVec(arr);
        CountSort(arr);
        cout << "SORTED LIST:" << endl;
        PrintVec(arr);
    }
    catch (runtime_error e)
    {
        cout << "Error : " << e.what() << endl;
    }
    return 0;
}