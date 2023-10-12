#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
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

void BucketSort(vec &arr)
{
    int size = arr.size();
    if (size <= 0)
        return;
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());

    int range = max_val - min_val + 1;
    vector<vector<int>> buckets(range);

    for (int i = 0; i < size; i++)
    {
        int index = arr[i] - min_val;
        buckets[index].push_back(arr[i]);
    }

    for (int i = 0; i < range; i++)
        sort(buckets[i].begin(), buckets[i].end());

    int index = 0;
    for (int i = 0; i < range; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[index++] = buckets[i][j];
        }
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
        BucketSort(arr);
        cout << "SORTED LIST:" << endl;
        PrintVec(arr);
    }
    catch (runtime_error e)
    {
        cout << "Error : " << e.what() << endl;
    }
    return 0;
}
