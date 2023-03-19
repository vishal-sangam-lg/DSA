// https://practice.geeksforgeeks.org/problems/swap-and-maximize5859/1
// Approach: Sort. sum += abs(arr[i] - arr[j--]).
// Initially i = 0, j = n-1

long long int maxSum(int arr[], int n)
{
    sort(arr, arr + n);
    long long int sum = 0;
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        sum += abs(arr[i] - arr[j--]);
    }
    return sum;
}