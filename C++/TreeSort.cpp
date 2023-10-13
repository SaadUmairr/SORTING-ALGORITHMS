#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#define vec vector<ll>
#define ll long long int
using namespace std;

struct TreeNode
{
    ll data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(ll val) : data(val), left(nullptr), right(nullptr) {}
};

void Insert(TreeNode *&root, ll value)
{
    if (root == nullptr)
    {
        root = new TreeNode(value);
    }
    else
    {
        if (value < root->data)
        {
            Insert(root->left, value);
        }
        else
        {
            Insert(root->right, value);
        }
    }
}

void InOrderTraversal(TreeNode *root, vec &sorted)
{
    if (root == nullptr)
    {
        return;
    }
    InOrderTraversal(root->left, sorted);
    sorted.push_back(root->data);
    InOrderTraversal(root->right, sorted);
}

void TreeSort(vec &arr)
{
    TreeNode *root = nullptr;

    // Insert elements into the binary search tree
    for (ll val : arr)
    {
        Insert(root, val);
    }

    arr.clear();                 // Clear the original array
    InOrderTraversal(root, arr); // Perform in-order traversal to get the sorted order
}

void PrintVec(const vec &arr)
{
    for (const ll &value : arr)
    {
        cout << value << '\t';
    }
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

int main()
{
    system("cls");
    int size, el;
    try
    {
        cout << "Enter size of the array: ";
        size = inputNumber();
        if (size <= 0)
            throw runtime_error("Size of list cannot be negative or zero");
        vec arr;
        for (int i = 0; i < size; i++)
        {
            el = inputNumber();
            arr.push_back(el);
        }
        cout << "INPUT LIST:" << endl;
        PrintVec(arr);
        TreeSort(arr); // Perform tree sort
        cout << "SORTED LIST:" << endl;
        PrintVec(arr);
    }
    catch (runtime_error e)
    {
        cout << "Error : " << e.what() << endl;
    }
    return 0;
}
