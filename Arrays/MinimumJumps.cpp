// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
// Approach: Sliding Window
// In the window i to maxReach -> update nextMaxReach
// when i == maxReach (end of window) -> update maxReach with nextMaxReach, jump and check answer
// TC: O(n)
// SC: O(1)

#include <iostream>
using namespace std;

int minJumps(int arr[], int n)
{
    // If array length <= 1 -> No need to jump
    if (n <= 1)
        return 0;
    // If arr[0] = 0 -> We can't proceed further
    if (arr[0] == 0)
        return -1;

    int maxReach = 0, nextMaxReach = 0, jumps = 0;
    for (int i = 0; i < n; i++)
    {
        nextMaxReach = max(nextMaxReach, arr[i] + i);
        if (i == maxReach)
        {
            maxReach = nextMaxReach;
            jumps++;
            if (maxReach >= n - 1)
            {
                return jumps;
            }
            nextMaxReach = arr[i]; // Not necessary
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 1, 4, 5};
    cout << minJumps(arr, 5) << endl;
    return 0;
}