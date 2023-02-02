// https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
// Striver explanation -> https://www.youtube.com/watch?v=oaVa-9wmpns
// Approach: Dutch national flag algorithm
// all the numbers [0 to low-1] are 0s and all the numbers [high+1 to n] are 2s
// 1s are in range [low to mid-1](mid-1 is high) because at end, mid will have crossed high
// TC: O(n)
// SC: O(1)
// Dry Run:
// 0(low, mid) 1 1 0 1 2 1 2 0 0 0 1(high)
// 0 1(low, mid) 1 0 1 2 1 2 0 0 0 1(high)
// 0 1(low) 1(mid) 0 1 2 1 2 0 0 0 1(high)
// 0 1(low) 1 0(mid) 1 2 1 2 0 0 0 1(high)
// 0 0 1(low) 1 1(mid) 2 1 2 0 0 0 1(high)
// 0 0 1(low) 1 1 2(mid) 1 2 0 0 0 1(high)
// 0 0 1(low) 1 1 1(mid) 1 2 0 0 0(high) 2
// 0 0 1(low) 1 1 1 1(mid) 2 0 0 0(high) 2
// 0 0 1(low) 1 1 1 1 2(mid) 0 0 0(high) 2
// 0 0 1(low) 1 1 1 1 0(mid) 0 0(high) 2 2
// 0 0 0 1(low) 1 1 1 1 0(mid) 0(high) 2 2
// 0 0 0 0 1(low) 1 1 1 1 0(mid, high) 2 2
// 0 0 0 0 0 1(low) 1 1 1 1(high) 2(mid) 2
// INFERENCE: We try to make the low point at 1st occurence of 1
// and high point at last occurence of 1
#include <iostream>
using namespace std;

void sort012(int a[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a[mid], a[low]);
            low++;
            mid++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a[mid], a[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {2, 1, 0, 1, 0, 1, 0, 2};
    sort012(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}