// https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1

// Formula:
// nth catalan number is T(n)  = (2n)! / (n+1)!*n!

cpp_int factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

cpp_int findCatalan(int n)
{
    return factorial(2 * n) / (factorial(n + 1) * factorial(n));
}

// Using DP - store all factorial till 2n. Return ans
cpp_int findCatalan(int n)
{
    cpp_int ans, num, den;
    cpp_int dp[2 * n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= 2 * n; i++)
    {
        dp[i] = i * dp[i - 1];
    }
    num = dp[2 * n];
    den = dp[n + 1] * dp[n];
    return num / den;
}