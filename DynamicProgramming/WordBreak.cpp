// https://practice.geeksforgeeks.org/problems/word-break1352/1

// Recursive solution

int solve(string s, set<string> dict)
{
    if (s.size() == 0)
        return 1;

    for (int i = 1; i <= s.size(); i++)
    {
        bool condition1 = false, condition2 = false;
        // 1st condition - checking if any substr(0-i) matches with dict
        condition1 = dict.find(s.substr(0, i)) != dict.end();
        // 2nd condition - recursive call for substr(i-end)
        if (condition1)
            condition2 = solve(s.substr(i), dict);

        if (condition1 && condition2)
        {
            return 1;
        }
    }
    return 0;
}

int wordBreak(string A, vector<string> &B)
{
    set<string> dict;
    for (int i = 0; i < B.size(); i++)
    {
        dict.insert(B[i]);
    }
    return solve(A, dict);
}

// DP solution
// Approach:
// For loop recursion pattern
// traverse dictionary:
//   if(isMatch(substring s till i and dict[j]))
//     if(solve(substring after j))

bool isMatch(string s1, string s2, int i)
{
    return s1.substr(i, s2.size()) == s2;
}

int solve(int i, int n, string s, vector<string> &dict)
{
    if (i == n)
    {
        return 1;
    }

    for (int j = 0; j < dict.size(); j++)
    {
        if (isMatch(s, dict[j], i))
        {
            if (solve(i + dict[j].size(), n, s, dict))
            {
                return 1;
            }
        }
    }

    return 0;
}

int solveMem(int i, int n, string s, vector<string> &dict, vector<int> &dp)
{
    if (i == n)
    {
        return 1;
    }
    if (dp[i] != -1)
    {
        dp[i];
    }

    for (int j = 0; j < dict.size(); j++)
    {
        if (isMatch(s, dict[j], i))
        {
            if (solveMem(i + dict[j].size(), n, s, dict, dp))
            {
                return dp[i] = 1;
            }
        }
    }

    return dp[i] = 0;
}

int solveTab(string s, vector<string> &dict)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < dict.size(); j++)
        {
            if (isMatch(s, dict[j], i))
            {
                if (dp[i + dict[j].size()])
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        if (dp[i] == 1)
        {
            continue;
        }
        dp[i] = 0;
    }

    return dp[0];
}

int wordBreak(string A, vector<string> &B)
{
    // return solve(0, A.size(), A, B);
    // vector<int> dp(A.size()+1, -1);
    // return solveMem(0, A.size(), A, B, dp);
    return solveTab(A, B);
}