// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
// Approach: Binary search in range [max_element(arr), accumulate(arr)]
// Choose mid and check if it is a valid allocation, update ans
// TC: O(log(sumOfArr - maxOfArr))
// SC: O(1)

long long int accumulate(int arr[], int n)
{
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
long long minTime(int arr[], int n, int k)
{
    long long int low = *max_element(arr, arr + n);
    long long int high = accumulate(arr, n);

    while (low <= high)
    {
        long long int mid = low + (high - low) / 2;
        long long int paintercount = 0;
        long long int paintersum = 0;
        for (int i = 0; i < n; i++)
        {
            paintersum += arr[i];
            if (paintersum > mid)
            {
                paintercount++;
                paintersum = arr[i];
            }
        }
        if (paintersum > 0)
            paintercount++;

        if (paintercount > k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}