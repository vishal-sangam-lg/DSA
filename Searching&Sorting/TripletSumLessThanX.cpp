// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
// Approach: For all i,
// try finding a i+j+k to given sum. count += k-j
// Again try for next j
// TC: O(n^2)
// SC: O(1)

long long countTriplets(long long arr[], int n, long long sum)
{
    sort(arr, arr + n);
    int count = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int total = arr[i] + arr[j] + arr[k];
            if (total < sum)
            {
                // Count all the numbers in between low and high
                // As they also become valid with current ith and jth element
                count += k - j;
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return count;
}