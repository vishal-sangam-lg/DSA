// https://leetcode.com/problems/compare-version-numbers/
// Approach: Build number till a dot for both version. Compare and return ans. If they are equal, continue loop
// TC: O(n+m)
// SC: O(1)

int compareVersion(string version1, string version2)
{
    int i = 0, j = 0, n1 = version1.size(), n2 = version2.size();
    while (i < n1 || j < n2)
    {
        int num1 = 0, num2 = 0;
        // Construct first number until a dot
        while (i < n1 && version1[i] != '.')
        {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }
        // Construct second number until a dot
        while (j < n2 && version2[j] != '.')
        {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }
        // compare num1 and num2. return result
        if (num1 > num2)
        {
            return 1;
        }
        if (num1 < num2)
        {
            return -1;
        }
        i++;
        j++;
    }
    return 0;
}