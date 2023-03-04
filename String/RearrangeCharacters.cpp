// https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1
// Approach: Get the maxFreqChar. If its frequency > half of string length. return -1
// Else start placing in odd position then even position starting from maxFreqChar
// TC: O(n)
// SC: O(1) excluding freq array of size 26

string rearrangeString(string str)
{
    int freq[26] = {0};
    int maxFreq = INT_MIN;
    char maxFreqChar;
    int maxFreqIdx = 0;
    // Getting the maximum frequent character and its count, index
    for (int i = 0; i < str.length(); i++)
    {
        freq[str[i] - 'a']++;
        if (freq[str[i] - 'a'] > maxFreq)
        {
            maxFreq = freq[str[i] - 'a'];
            maxFreqChar = str[i];
            maxFreqIdx = str[i] - 'a';
        }
    }

    // Impossible if maxFreq > half of size of string
    if (maxFreq > (str.length() + 1) / 2)
        return "-1";

    // Placing characters in odd positions, then even positions
    // Starting from positioning the maxFreqChar
    int i = 0;
    while (freq[maxFreqIdx]--)
    {
        str[i] = maxFreqChar;
        i += 2;
    }
    // Placing the remaining characters
    for (int j = 0; j < 26; j++)
    {
        if (freq[j] > 0)
        {
            while (freq[j]--)
            {
                if (i >= str.length())
                {
                    i = 1;
                }
                str[i] = char(97 + j);
                i += 2;
            }
        }
    }
    return str;
}