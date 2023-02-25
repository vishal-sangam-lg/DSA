// https://leetcode.com/problems/count-and-say/
// https://practice.geeksforgeeks.org/problems/decode-the-pattern1138/1
// Approach: Try to generate pattern
// 1 11 21 1211… construct this pattern starting from 1. n^2 loop.
// TC: O(n^2)
// SC: O(|pattern|)

string countAndSay(int n)
{
    if (n == 0)
    {
        return "";
    }
    string pattern = "1";
    for (int i = 0; i < n - 1; i++)
    {
        string temp = "";
        int countConsecutive = 1;
        for (int index = 0; index < pattern.size(); index++)
        {
            if (pattern[index] == pattern[index + 1])
            {
                countConsecutive++;
            }
            else
            {
                temp += to_string(countConsecutive) + pattern[index];
                countConsecutive = 1;
            }
        }
        pattern = temp;
    }
    return pattern;
}