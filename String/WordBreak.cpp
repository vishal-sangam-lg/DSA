// https://practice.geeksforgeeks.org/problems/word-break1352/1
// Approach: Add dict to set. recursive call to match substr (0-i) && (i-end)

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