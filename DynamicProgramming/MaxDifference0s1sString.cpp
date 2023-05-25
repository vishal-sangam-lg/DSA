// https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1

// Kadane's Algorithm
// TC: O(n)
// SC: O(1)

int maxSubstring(string S)
{
    int sweep = 0, ans = -1;
    for (char c : S)
    {
        if (c == '0')
            sweep++;
        else
            sweep--;
        ans = max(ans, sweep);
        if (sweep < 0)
            sweep = 0;
    }
    return ans;
}
