// https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1
// Approach: Partition at every step and if it isPalindrome, recursive call for rest of string. Push to ans when str ends

bool isPalindrome(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

void solve(string &S, vector<vector<string>> &res, int i, vector<string> &curr)
{
    if (i >= S.length())
    {
        res.push_back(curr);
        return;
    }

    string str = "";
    for (int j = i; j < S.length(); j++)
    {
        str += S[j];
        if (isPalindrome(str))
        {
            curr.push_back(str);
            solve(S, res, j + 1, curr);
            curr.pop_back();
        }
    }
}

vector<vector<string>> allPalindromicPerms(string S)
{
    vector<vector<string>> res; // All palindromic partitions
    vector<string> curr;        // Current partition
    solve(S, res, 0, curr);
    return res;
}