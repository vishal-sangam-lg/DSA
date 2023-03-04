// https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1
// Approach: only two cases can exist
// case 1 - starting from 0 -> 010101
// case 2 - starting from 1 -> 101010
// Count number of flips for both case. Return min

int minFlips(string S)
{
    // flip1 for string starting from 0 -> 010101
    // flip2 for string starting from 1 -> 101010
    int flip1 = 0, flip2 = 0;

    for (int i = 0; i < S.length(); i++)
    {
        if ((i % 2 == 0 && S[i] == '1') || (i % 2 != 0 && S[i] == '0'))
            flip1++;
        if ((i % 2 == 0 && S[i] == '0') || (i % 2 != 0 && S[i] == '1'))
            flip2++;
    }

    return min(flip1, flip2);
}