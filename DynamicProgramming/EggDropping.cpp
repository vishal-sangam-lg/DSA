// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
// Approach: for k = 1 -> floors, 1 + max(solve(eggs-1, k-1), solve(eggs, floors-k))
// i.e break and not break cases
// Update ans with min attempts

int solve(int eggs, int floors)
{
    if (floors == 0 || floors == 1)
    {
        return floors;
    }
    if (eggs == 1)
    {
        return floors;
    }

    int ans = INT_MAX;
    for (int k = 1; k <= floors; k++)
    {
        // curr = 1 attempt + max(break, notbreak) to get the worst case
        int curr = 1 + max(solve(eggs - 1, k - 1), solve(eggs, floors - k));
        // Store the minimum attempts
        ans = min(ans, curr);
    }

    return ans;
}

int solveMem(int eggs, int floors, vector<vector<int>> &dp)
{
    if (floors == 0 || floors == 1)
    {
        return floors;
    }
    if (eggs == 1)
    {
        return floors;
    }
    if (dp[eggs][floors] != -1)
    {
        return dp[eggs][floors];
    }

    int ans = INT_MAX;
    for (int k = 1; k <= floors; k++)
    {
        // curr = 1 attempt + max(break, notbreak) to get the worst case
        int curr = 1 + max(solveMem(eggs - 1, k - 1, dp), solveMem(eggs, floors - k, dp));
        // Store the minimum attempts
        ans = min(ans, curr);
    }

    return dp[eggs][floors] = ans;
}

int solveTab(int Eggs, int Floors)
{
    vector<vector<int>> dp(Eggs + 1, vector<int>(Floors + 1, 0));
    for (int i = 0; i <= Eggs; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int i = 0; i <= Floors; i++)
    {
        dp[1][i] = i;
    }

    for (int eggs = 2; eggs <= Eggs; eggs++)
    {
        for (int floors = 2; floors <= Floors; floors++)
        {
            int ans = INT_MAX;
            for (int k = 1; k <= floors; k++)
            {
                int curr = 1 + max(dp[eggs - 1][k - 1], dp[eggs][floors - k]);
                ans = min(ans, curr);
            }
            dp[eggs][floors] = ans;
        }
    }

    return dp[Eggs][Floors];
}

int eggDrop(int n, int k)
{
    // return solve(n, k);
    // vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    // return solveMem(n, k, dp);
    return solveTab(n, k);
}