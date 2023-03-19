// https://practice.geeksforgeeks.org/problems/smallest-subset-with-greater-sum/1
// Approach: Sort in descending order.
// count until condition not met by adding large numbers and subtracting them from target
// TC: O(nlogn)
// SC: O(1)

int minSubset(vector<int> &Arr, int N)
{
    sort(Arr.begin(), Arr.end(), greater<int>());

    long long sum = 0;
    for (int i = 0; i < N; i++)
        sum += Arr[i];

    long long maxSum = 0;
    int i = 0;
    while (sum >= maxSum && i < N)
    {
        sum -= Arr[i];
        maxSum += Arr[i];
        i++;
    }
    return i;
}