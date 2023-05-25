// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1
// Approach: create adjacency list of all neighbouring nodes in keypad
// dfs with dp[N][index], where N is steps left, index is current key

long long int dfs(int index, int N, unordered_map<int, vector<int>> &adj, vector<vector<long long int>> &dp)
{
    if (N == 1)
        return 1;
    if (dp[N][index] != -1)
        return dp[N][index];
    long long int ans = 0;
    for (auto it : adj[index])
    {
        ans += dfs(it, N - 1, adj, dp);
    }
    return dp[N][index] = ans;
}
long long getCount(int N)
{
    unordered_map<int, vector<int>> adj;
    adj[0] = {0, 8};
    adj[1] = {2, 4, 1};
    adj[2] = {1, 3, 5, 2};
    adj[3] = {2, 6, 3};
    adj[4] = {1, 5, 7, 4};
    adj[5] = {2, 4, 6, 8, 5};
    adj[6] = {3, 5, 9, 6};
    adj[7] = {4, 8, 7};
    adj[8] = {5, 7, 9, 0, 8};
    adj[9] = {6, 8, 9};
    long long int ans = 0;
    vector<vector<long long int>> dp(N + 1, vector<long long int>(10, -1));
    for (int i = 0; i <= 9; i++)
    {
        ans += dfs(i, N, adj, dp);
    }
    return ans;
}