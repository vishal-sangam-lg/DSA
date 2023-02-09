// https://leetcode.com/problems/excel-sheet-column-title/
// Approach: always n-- to adjust with index of string all
// Think in terms of 26 powers
// TC: O(log26n)
// SC: O(1)

#include <iostream>
using namespace std;

string convertToTitle(int columnNumber)
{
    string all = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = columnNumber;
    string ans = "";
    while (n > 0)
    {
        n--; // To adjust with array index
        int remainder = n % 26;
        ans.push_back(all[remainder]);
        n /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout << convertToTitle(701) << endl;
}