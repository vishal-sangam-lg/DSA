// https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1
// Approach: count opening brackets. ++ if [ eles --
// If count < 0. swap += abs(count)
// TC: O(n)
// SC: O(1)

int minimumNumberOfSwaps(string S)
{
    int open = 0, swaps = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '[')
            open++;
        else
        {
            open--;
            if (open < 0)
            {
                swaps += abs(open);
            }
        }
    }
    return swaps;
}