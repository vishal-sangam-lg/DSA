// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1

// Dry Run
// k = 3 -> RGB
// n = 2   same = RR GG BB     different = RG RB GR GB BR BG
// n = 3
// same = previous different coz we take it and paint with same as last color
// different = previous total * (k-1) coz we can paint with any color other than last color
// n = 2      same = 3      different = 6       total = 9
// n = 3      same = 6      different = 18      total = 24
// n = 4      same = 18     different = 48      total = 66
// n = 5      same = 48     different = 132     total = 180

// Observation:
// current answer = same + different
// current same = prev different which in turn = its prev total * k-1
// current different = prev total * k-1

// Recursive relation
// f(n) = same + different
// f(n) = different of f(n-1) + total of f(n-1) * (k-1)
// f(n) = total of f(n-2) * (k-1) + total of f(n-1) * (k-1)
// f(n) = k-1 * (f(n-1) + f(n-2));

long long solve(int n, int k)
{
    // Base cases:
    // n = 0 -> Not possible
    // n = 1 -> You have one post and k colors => k possibilities
    // n = 2 -> You have 2 post and k colors
    // => using same colors -> k possibilities
    // => using different colors -> k * (k-1) possibilities
    // Example: n = 2 and k = 3 -> RGB are colors
    // same = RR GG BB = 3 = k
    // different = RG RB GR GB BR BG = 6 = k * k-1
    // Hence for n == 2 -> k + (k * (k-1)) = k*k
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k * k;
    }

    return (k - 1) * (solve(n - 1, k) + solve(n - 2, k));
}

long long solveMem(int n, int k, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k * k;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = (k - 1) * (solve(n - 1, k) + solve(n - 2, k));
}

// constant
long long m = 1e9 + 7;
long long solveTab(int N, int k)
{
    vector<int> dp(N + 1, 0);
    dp[1] = k;
    dp[2] = k * k;

    for (int n = 3; n <= N; n++)
    {
        dp[n] = ((k - 1) * (dp[n - 1] % m + dp[n - 2] % m)) % m;
    }

    return dp[N];
}

long long solveSO(int N, int k)
{
    int prevprev = k;
    int prev = k * k;
    int curr;

    for (int n = 3; n <= N; n++)
    {
        curr = ((k - 1) * (prev % m + prevprev % m)) % m;
        prevprev = prev;
        prev = curr;
    }

    return prev;
}

long long countWays(int n, int k)
{
    if (n == 1)
    {
        return k;
    }
    // vector<int> dp(n+1, -1);
    // return solve(n, k);
    // return solveMem(n, k, dp);
    // return solveTab(n, k);
    return solveSO(n, k);
}