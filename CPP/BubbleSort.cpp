#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define vec vector<ll>
#define ll long long int
using namespace std;

void Swap(ll &a, ll &b)
{
    a = a+b;
    b = a-b;
    a = a-b;
}
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
                Swap(arr[j], arr[j+1]);
                change = true;
            }
        }
        if(!change)
            break;
    }
}
void PrintVec(vec arr)
{
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<'\t';
    cout<<endl;
}

int main()
{
    system("cls");
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
//#endif

    int size, el;
    cout<<"Enter size of the array: ";
    cin>>size;
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