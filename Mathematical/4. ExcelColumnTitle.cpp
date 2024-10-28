// https://leetcode.com/problems/excel-sheet-column-title/
// Approach: always n-- to adjust with index of string all
// Get remainder with % 26, update ans. Update column with /26
// TC: O(log26n)
// SC: O(1)

string convertToTitle(int columnNumber)
{
    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", ans = "";
    int n = columnNumber;
    while (n > 0)
    {
        n--; // Adjust with alphabets array index
        int remainder = n % 26;
        ans += alphabets[remainder];
        n /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}