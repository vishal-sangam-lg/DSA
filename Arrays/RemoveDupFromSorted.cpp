// https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1
// Approach: 2 pointer. i - last unique element, j - looping
// TC: O(n)
// SC: O(1)

int remove_duplicate(int a[], int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (a[i] != a[j])
        {
            i++;
            a[i] = a[j];
        }
    }
    return i + 1;
}

#include <iostream>
using namespace std;

// Striver
int removeDuplicates(int arr[], int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}
int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = removeDuplicates(arr, n);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}