// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1
// base case -> if n==1 || n == 2 return n;
// Recursive relation -> solve(n-1) + (n-1)*solve(n-2)

// constants
int m = 1e9 + 7;

int solve(int n)
{
    // Base cases
    // If there is only 1 person, only one way -> They have to stay single
    // If there are 2 person, 2 ways -> both single, or 1 pair
    if (n == 1 || n == 2)
    {
        return n;
    }

    // solve(n-1) -> taking current person to remain single
    // (n-1)*solve(n-2) -> all possibilities of pairing current person with rest n-1
    // and corresponding solve(n-2) possibilities
    return solve(n - 1) + (n - 1) * solve(n - 2);
}

int solveMem(int n, vector<int> &dp)
{
    if (n == 1 || n == 2)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = solve(n - 1) + (n - 1) * solve(n - 2);
}

int solveTab(int N)
{
    vector<long long int> dp(N + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int n = 3; n <= N; n++)
    {
        dp[n] = (dp[n - 1] % m + ((n - 1) * dp[n - 2]) % m) % m;
    }

    return dp[N];
}

int solveSO(int N)
{
    long long int a = 1;
    long long int b = 2;
    long long int c;

    for (int n = 3; n <= N; n++)
    {
        c = (b % m + ((n - 1) * a) % m) % m;
        a = b;
        b = c;
    }

    return c;
}

int countFriendsPairings(int n)
{
    // return solve(n);
    // vector<int> dp(n+1, -1);
    // return solveMem(n, dp);
    // return solveTab(n);
    return solveSO(n);
}