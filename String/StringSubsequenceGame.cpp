// https://practice.geeksforgeeks.org/problems/string-subsequence-game5515/1
// Approach: Get all the subsequence. Add a subsequence to res if it meets the game conditions

bool isVowel(char a)
{
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve(string s, int i, string curr, set<string> &res)
{
    if (i == s.length())
    {
        if (curr.length() >= 2 && isVowel(curr[0]) && !isVowel(curr[curr.length() - 1]))
        {
            res.insert(curr);
        }
        return;
    }
    solve(s, i + 1, curr + s[i], res);
    solve(s, i + 1, curr, res);
}
set<string> allPossibleSubsequences(string S)
{
    set<string> res;
    solve(S, 0, "", res);
    return res;
}