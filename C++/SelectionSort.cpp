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
        SelectionSort(arr);
        cout << "SORTED LIST:" << endl;
        PrintVec(arr);
    }
    catch (runtime_error e)
    {
        cout << "Error : " << e.what() << endl;
    }
    return 0;
}