// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
// Approach: Dutch national flag

#include <iostream>
using namespace std;

void segregateElements(int arr[], int n)
{
    int temp[n];
    int count = 0;
    // Copying all positive numbers
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            temp[count++] = arr[i];
        }
    }
    // Copying all negative numbers
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            temp[count++] = arr[i];
        }
    }
    // Copying answer to arr
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int arr[] = {2, 4, -1, 5, -3};
    segregateElements(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}