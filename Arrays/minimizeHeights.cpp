// Minimize the heights - I  https://practice.geeksforgeeks.org/problems/minimize-the-heights-i/1
// Minimize the heights - II https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
// Approach: Sort the array, Initial answer = last element - first element
// inside loop check if there can be any other number which can be max or min
// To get newMax compare last element - k with all elements in array + k
// To get newMin compare first element + k with all elements in array - k
// Check the answer for their case, update if (newMax - newMin < ans)
// TC: O(nlogn)
// SC: O(1)
// Dry Run:
// 1 10 15 -> currLargest = 9; currSmallest = 7; ans = 14
// Loop Begin
// i = 1; currLargest = 9; currSmallest = 4; ans = 5;
// i = 2; currLargest = 16; currSmallest = 4; ans = 5;
// Loop End

#include <iostream>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    int currSmallest = arr[0] + k;
    int currLargest = arr[n - 1] - k;
    for (int i = 1; i < n; i++)
    {
        // check if arr[i] - k < 0 and skip the loop if it is negative for MinimizeHeights II
        // if(arr[i] - k < 0) continue;
        currLargest = max(arr[n - 1] - k, arr[i - 1] + k);
        currSmallest = min(arr[0] + k, arr[i] - k);
        ans = min(ans, currLargest - currSmallest);
    }
    return ans;
}

int main()
{
    int arr1[] = {1, 15, 10};
    int arr2[] = {1, 5, 8, 10};
    cout << getMinDiff(arr1, 3, 6) << endl;
    cout << getMinDiff(arr2, 4, 2) << endl;
    return 0;
}