// https://practice.geeksforgeeks.org/problems/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/1
// Approach: Vote variable is ++ for 0 and -- for 1. When vote == 0. its balanced

int maxSubStr(string str)
{
    // Moore's voting algorithm
    int vote = 0, ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
        {
            vote++;
        }
        else
        {
            vote--;
        }
        if (vote == 0)
        {
            ans++;
        }
    }
    if (vote == 0)
    {
        return ans;
    }
    return -1;
}