// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Approach: store character in set. Two pointer to note start and end.
// If you find current character in set. i++ else j++
// TC: O(n)
// SC: O(n)

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> set;
    int i = 0, j = 0, n = s.size(), ans = 0;
    while (i < n && j < n)
    {
        if (set.find(s[j]) == set.end()) // If the character not in the set
        {
            set.insert(s[j++]);    // Insert the character in set and update the j counter
            ans = max(ans, j - i); // Check if the new distance is longer than the current answer
        }
        else
        {
            set.erase(s[i++]);
            /*If character already exist in the set, ie. it is a repeated character,
            we update the left side counter i, and continue with the checking for substring. */
        }
    }
    return ans;
}