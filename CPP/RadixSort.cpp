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
        cout << value << '\t';
    cout << endl;
}
int getMax(vec &arr)
{
    ll MAX=INT64_MIN;
    for(const ll &i: arr)
        MAX = max(MAX, i);
    return MAX;
}
void CountSort(vec &arr, int exp)
{
    vec output(arr.size(),0);
    vec count(10,0);
    for(int i=0;i<arr.size();i++)
        count[(arr[i]/exp)%10]++;
    for(int i=1;i<10;i++)
        count[i]+=count[i-1];
    for(int i=arr.size()-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    arr = output;
}

void RadixSort(vec &arr)
{
    ll MAX = getMax(arr);
    for (int i = 1; MAX / i >= 1; i *= 10)
    {
        CountSort(arr, i);
    }
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
    RadixSort(arr);
    cout<<"ARRAY AFTER SORTING:"<<endl;
    PrintVec(arr);
    return 0;
}