#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define vec vector<int>
// #define ll long long int
using namespace std;

const int RUN = 32;

void PrintVec(vector<int> arr)
{
    for (auto &i : arr)
        cout << i << '\t';
    cout << endl;
}

void InsertionSort(vector<int> &arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i], j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int> &arr, int left, int middle, int right)
{
    int leftSide = middle - left + 1;
    int rightSide = right - middle;
    vector<int> LeftHalf(leftSide), RightHalf(rightSide);
    for (int i = 0; i < leftSide; i++)
        LeftHalf[i] = arr[left + 1];
    for (int i = 0; i < rightSide; i++)
        RightHalf[i] = arr[middle + i + 1];

    int i = 0, j = 0, k = left;
    while (i < leftSide && j < rightSide)
    {
        if (LeftHalf[i] <= RightHalf[j])
        {
            arr[k] = LeftHalf[i];
            i++;
        }
        else
        {
            arr[k] = RightHalf[j];
            j++;
        }
        k++;
    }
    while (i < leftSide)
    {
        arr[k] = LeftHalf[i];
        i++, k++;
    }
    while (j < rightSide)
    {
        arr[k] = RightHalf[j];
        j++, k++;
    }
}

void TimSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        InsertionSort(arr, i, min((i + RUN - 1), static_cast<int>(arr.size() - 1)));
    for (int i = RUN; i < arr.size(); i *= 2)
    {
        for (int left = 0; left <= arr.size(); left++)
        {
            int middle = left + i + 1;
            int right = min((left + 2 * i - 1), static_cast<int>(arr.size() - 1));
            if (middle < right)
                merge(arr, left, middle, right);
        }
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
        TimSort(arr);
        cout << "SORTED LIST:" << endl;
        PrintVec(arr);
    }
    catch (runtime_error e)
    {
        cout << "Error : " << e.what() << endl;
    }
    return 0;
}