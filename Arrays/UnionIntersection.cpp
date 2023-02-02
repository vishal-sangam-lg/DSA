// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
// https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/

#include <iostream>
#include <unordered_set>
using namespace std;

int doUnion(int a[], int n, int b[], int m)
{
    unordered_set<int> res;
    for (int i = 0; i < n; i++)
    {
        res.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        res.insert(b[i]);
    }
    return res.size();
}

int main()
{
    int arr1[] = {2, 3, 1, 5, 9};
    int arr2[] = {3, 1, 10, 12, 15};
    cout << doUnion(arr1, 5, arr2, 5) << endl;
    return 0;
}