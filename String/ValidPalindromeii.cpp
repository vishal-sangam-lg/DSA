// https://leetcode.com/problems/valid-palindrome-ii/
// Approach:
// Check from left and right at the same time until the first different pair.
// Now we have something like a****b, where a and b are different.
// We need to delete either a or b to make it a palindrome.
// TC: O(n)
// SC: O(1)

bool validPalindrome(string s)
{
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        if (s[i] != s[j])
        {
            int i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;
            while (i1 < j1 && s[i1] == s[j1])
            {
                i1++;
                j1--;
            };
            while (i2 < j2 && s[i2] == s[j2])
            {
                i2++;
                j2--;
            };
            return i1 >= j1 || i2 >= j2;
        }
    return true;
}