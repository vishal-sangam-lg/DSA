// https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
// Approach: For i = 0->n, while 0 < arr[i] <= n, swap arr[i], arr[correctIndex]
// TC: O(n)
// SC: O(1)

// Suboptimal approaches:
// 1. If there are only +ve numbers - You can mark its position as -ve and check back
// 2. Use map to store, traverse map and return

int missingNumber(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int CI = arr[i] - 1; // Correct position stored in correct index
        while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[CI])
        {
            swap(arr[i], arr[CI]);
            CI = arr[i] - 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }
    return n + 1;
}