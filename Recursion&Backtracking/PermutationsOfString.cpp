// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
// Approach: for loop recursion - for every index,
// swap s[i] with all chars on its right with a for loop
// To get unique permutations - Don't swap same characters.

void solve(int index, string &s, vector<string> &ans)
{
    if (index == s.length())
    {
        ans.push_back(s);
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        // Condition to get unique permutations
        // Don't swap same characters. !Catch!
        if (i > index && s[i] == s[i - 1])
            continue;
        swap(s[i], s[index]);
        solve(index + 1, s, ans);
        swap(s[i], s[index]);
    }
}
vector<string> find_permutation(string s)
{
    vector<string> ans;
    sort(s.begin(), s.end());
    solve(0, s, ans);
    sort(ans.begin(), ans.end());
    return ans;
}