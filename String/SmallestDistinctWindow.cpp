// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1

// Approach: Sliding window
// 1.firstly expand the window until all the distinct characters of string
//   are not present in the window , once all the distinct characters are there simply
//   contract the window.
// 2.then in next iteration everytime we expand the window size by 1 and check
//   if contraction is possible

// TC: O(n)
// SC: O(n)

int findSubString(string str)
{
    int n = str.size();
    unordered_map<char, int> mp;

    for (int i = 0; i < n; i++)
        mp[str[i]] = 0;

    int i = 0, j = 0, minLen = INT_MAX, count = 0;
    // string res;

    while (j < n)
    {
        // Inc count if character appears for the first time in window
        if (mp[str[j]] == 0)
            count++;
        mp[str[j]]++;

        // count == mp.size() when the window has all the distinct characters
        if (count == mp.size())
        {
            // Trying to contract the window
            while (i < n && mp[str[i]] > 1)
            {
                mp[str[i]]--;
                i++;
            }
            // Update minLen if necessary
            if (j - i + 1 < minLen)
            {
                minLen = j - i + 1;
                // res = str.substr(i, j-i+1);
            }
        }
        j++;
    }
    return minLen;
}