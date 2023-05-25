// https://practice.geeksforgeeks.org/problems/max-length-chain/1

// Greedy solution
// Approach:
// Sort the pairs according to second number.
// construct the chain maintain prev and count
// TC: O(nlogn)
// SC: O(1)

// DP is sub-optimal solution

static bool compare(struct val a, struct val b)
{
    return a.second < b.second;
}
int maxChainLen(struct val p[], int n)
{
    sort(p, p + n, compare);

    int count = 0, prev = -1;
    for (int i = 0; i < n; i++)
    {
        if (p[i].first > prev)
        {
            count++;
            prev = p[i].second;
        }
    }

    return count;
}