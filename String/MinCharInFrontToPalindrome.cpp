// https://practice.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1
// Approach: Greedy
// Finding the maxLen of palindrome from 0 to trim
// Whatever will be left after trim must be added in the front
// ans = str.length() - trim;
// TC: O(n^2) -> average takes O(n)
// SC: O(1)
int minChar(string str)
{
    int i = 0, j = str.length(), trim = str.length();

    // Finding the maxLen of palindrome from 0 to trim
    // Whatever will be left after trim must be added in the front
    // ans = str.length() - trim;
    while (i < j)
    {
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            i = 0;
            j = --trim;
        }
    }
    return str.length() - trim - 1;
}
