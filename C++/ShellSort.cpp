#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define vec vector<int>
using namespace std;

void PrintVec(vector<int> arr)
{
    for (auto &i : arr)
        cout << i << '\t';
    cout << endl;
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

void ShellSort(vec &arr)
{
    int size = arr.size();
    for (int gap = size / 2; gap >= 1; gap /= 2)
        for (int j = gap; j < size; j++)
            for (int i = j - gap; i >= 0; i -= gap)
            {
                if (arr[i + gap] > arr[i])
                    break;
                else
                    swap(arr[i + gap], arr[i]);
            }
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
        ShellSort(arr);
        cout << "SORTED LIST:" << endl;
        PrintVec(arr);
    }
    catch (runtime_error e)
    {
        cout << "Error : " << e.what() << endl;
    }
    return 0;
}