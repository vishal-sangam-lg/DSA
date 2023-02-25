// https://leetcode.com/problems/longest-palindromic-substring/
// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1
// Approach: For all values of i
// expand from center and check
// for bab when i, i is on a. you will get bab
// for baab when i, j is on a, a. you will get baab
// TC: O(n^2)
// SC: O(1)

int expandFromCenter(string s, int i, int j)
{
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        i--;
        j++;
    }
    return j - i - 1;
}
string longestPalindrome(string s)
{
    // Used to store starting and ending index of longest palindromic substring
    int start = 0, maxLen = 0;
    string res = "";

    // Expanding from center for all i,i(odd) & i,i+1(even)
    for (int i = 0; i < s.length(); i++)
    {
        int maxLenEvenPalindrome = expandFromCenter(s, i, i + 1);
        int maxLenOddPalindrome = expandFromCenter(s, i, i);
        int currMaxLen = max(maxLenEvenPalindrome, maxLenOddPalindrome);
        if (maxLen < currMaxLen)
        {
            // Since we are expanding from center
            // Start will be maxLen/2 towards left of i
            start = i - (currMaxLen - 1) / 2;
            maxLen = currMaxLen;
            res = s.substr(start, maxLen);
        }
    }
    return res;
}