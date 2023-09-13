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

void MergeSort(vec &arr, int left, int right)
{
    // This function partitions the array
    if (left >= right)
        return;
    int middle = left + (right - left) / 2;
    MergeSort(arr, left, middle);
    MergeSort(arr, middle + 1, right);
    ActualWorker(arr, left, middle, right);
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
        MergeSort(arr, 0 , size-1);
        cout << "SORTED LIST:" << endl;
        PrintVec(arr);
    }
    catch (runtime_error e)
    {
        cout << "Error : " << e.what() << endl;
    }
    return 0;
}