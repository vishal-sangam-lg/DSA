// https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1
// Approach: Maps | hashing
// TC: O(n)
// SC: O(1)

bool areIsomorphic(string s1, string s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }
    int hash1[26] = {0};
    int hash2[26] = {0};
    for (int i = 0; i < s1.size(); i++)
    {
        hash1[s1[i] - 'a']++;
        hash2[s2[i] - 'a']++;
    }
    for (int i = 0; i < s1.size(); i++)
    {
        if (hash1[s1[i] - 'a'] != hash2[s2[i] - 'a'])
        {
            return false;
        }
    }
    return true;
}