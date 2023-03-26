// https://practice.geeksforgeeks.org/problems/word-break-part-23249/1
// Approach: Store dict in map. For all substr(0 -> n) of s. If word present in map, solve(curr + word + " ")

unordered_map<string, int> freq;
void solve(string curr, string s, int n, vector<string> &ans)
{
    if (s.length() == 0)
    {
        curr.pop_back(); // Remove the extra space at end
        ans.push_back(curr);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string word = s.substr(0, i + 1);
        if (freq[word])
        {
            solve(curr + word + " ", s.substr(i + 1), n, ans);
        }
    }
}
vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    for (string word : dict)
        freq[word]++;

    vector<string> ans;
    solve("", s, n, ans);
    return ans;
}