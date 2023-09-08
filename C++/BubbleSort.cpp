#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define vec vector<ll>
#define ll long long int
using namespace std;

void BubbleSort(vec &arr)
{
    bool change;
    int size = arr.size();
    for(int i=0;i<size;++i)
    {
        change = false;
        for(int j=0;j<size-i-1;++j)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                change = true;
            }
        }
        if(!change)
            break;
    }
}
void PrintVec(const vec& arr) {
    for (const int& value : arr) {
        cout << value << '\t';
    }
    cout << endl;
}


int main()
{
    system("cls");
    int size, el;
    cout<<"Enter size of the array: ";
    cin>>size;
    if (size <= 0)
    {
        cout << "Size of list can not be negative" << endl;
        return 1;
    } 
    vec arr;
    for(int i=0;i<size;i++)
        cin>>el, arr.push_back(el);
    cout<<"ARRAY BEFORE SORTING:"<<endl;
    PrintVec(arr);
    BubbleSort(arr);
    cout<<"ARRAY AFTER SORTING:"<<endl;
    PrintVec(arr);
    return 0;
}