// https://leetcode.com/problems/longest-common-prefix/
// Approach: Sort strs. compare first and last string in sorted strs.
// If characters are equal add to ans.
// TC: O(nlogn)
// SC: O(1)

string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    string firstString = strs[0];
    string lastString = strs[strs.size() - 1];

    string ans = "";

    for (int i = 0; i < firstString.size(); i++)
    {
        if (firstString[i] == lastString[i])
            ans += firstString[i];
        else
            break;
    }

    return ans;
}