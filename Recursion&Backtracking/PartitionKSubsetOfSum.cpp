// https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1
// Approach: Same as Partition with equal sum. target = sum/k.
// for loop recursion to get k partitions of sum/k

bool solve(int a[], int sum, int partition, int k, bool vis[], int index, int n)
{
    if (k == 0)
        return true;
    if (sum > partition)
        return false;
    if (sum == partition)
    {
        return solve(a, 0, partition, k - 1, vis, 0, n);
    }

    for (int i = index; i < n; i++)
    {
        if (vis[i])
            continue;

        vis[i] = true;
        if (solve(a, sum + a[i], partition, k, vis, i + 1, n))
            return true;

        vis[i] = false;
    }

    return false;
}

bool isKPartitionPossible(int a[], int n, int k)
{
    // Your code here
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    if (sum % k != 0)
        return false;

    bool vis[n] = {false}; // to find unique subsets !!!

    return solve(a, 0, sum / k, k, vis, 0, n);
}