// https://practice.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1
// Approach:
// Recursive relation: solve(n-x) == 0 || solve(n-y) == 0 || solve(n-1) == 0

int solve(int n, int x, int y)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int option1 = 1, option2 = 1, option3 = 1;
    if (n - x >= 0)
    {
        option1 = solve(n - x, x, y);
    }
    if (n - y >= 0)
    {
        option2 = solve(n - y, x, y);
    }
    if (n - 1 >= 0)
    {
        option3 = solve(n - 1, x, y);
    }

    if (option1 == 0 || option2 == 0 || option3 == 0)
    {
        return 1;
    }
    return 0;
}

int solveMem(int n, int x, int y, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int option1 = 1, option2 = 1, option3 = 1;
    if (n - x >= 0)
    {
        option1 = solveMem(n - x, x, y, dp);
    }
    if (n - y >= 0)
    {
        option2 = solveMem(n - y, x, y, dp);
    }
    if (n - 1 >= 0)
    {
        option3 = solveMem(n - 1, x, y, dp);
    }

    if (option1 == 0 || option2 == 0 || option3 == 0)
    {
        return dp[n] = 1;
    }
    return dp[n] = 0;
}

int solveTab(int N, int x, int y)
{
    vector<int> dp(N + 1, 0);
    dp[1] = 1;

    for (int n = 2; n <= N; n++)
    {
        int option1 = 1, option2 = 1, option3 = 1;
        if (n - x >= 0)
        {
            option1 = dp[n - x];
        }
        if (n - y >= 0)
        {
            option2 = dp[n - y];
        }
        if (n - 1 >= 0)
        {
            option3 = dp[n - 1];
        }

        if (option1 == 0 || option2 == 0 || option3 == 0)
        {
            dp[n] = 1;
        }
        else
        {
            dp[n] = 0;
        }
    }

    return dp[N];
}

int findWinner(int N, int X, int Y)
{
    // return solve(N, X, Y);

    // vector<int> dp(N+1, -1);
    // return solveMem(N, X, Y, dp);

    return solveTab(N, X, Y);
}