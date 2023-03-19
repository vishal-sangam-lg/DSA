// https://practice.geeksforgeeks.org/problems/min-sum-formed-by-digits3551/1
// Approach: Sort. Min sum is sum of number formed by odd position ans even position

long long int minSum(int arr[], int n)
{
    sort(arr, arr + n);
    long long num1 = 0, num2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            num1 = num1 * 10 + arr[i];
        else
            num2 = num2 * 10 + arr[i];
    }
    return num1 + num2;
}