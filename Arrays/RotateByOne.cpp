// https://www.geeksforgeeks.org/c-program-cyclically-rotate-array-one/
// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
// Approach: Traverse RTL copy i-1 to i. Copy last element to [0]

#include <iostream>
using namespace std;

void rotate(int arr[], int n)
{
    int lastElement = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = lastElement;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    rotate(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}