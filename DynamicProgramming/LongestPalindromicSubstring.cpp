// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1
// Approach:
// Traverse LTR for all i - 0 -> n
// maxLenEvenPalindrome = expandFromCenter(i, i+1)
// maxLenOddPalindrome = expandFromCenter(i, i)
// return max

// Iterative solution
int expandFromCenter(string s, int i, int j)
{
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        i--;
        j++;
    }
    return j - i - 1;
}
string longestPalindrome(string S)
{
    int start = 0, maxLen = 0;
    string res = "";
    for (int i = 0; i < S.length(); i++)
    {
        int maxLenEvenPalindrome = expandFromCenter(S, i, i + 1);
        int maxLenOddPalindrome = expandFromCenter(S, i, i);
        int currMaxLen = max(maxLenEvenPalindrome, maxLenOddPalindrome);

        if (maxLen < currMaxLen)
        {
            maxLen = currMaxLen;
            start = i - (maxLen - 1) / 2;
            res = S.substr(start, maxLen);
        }
    }
    return res;
}