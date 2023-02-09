// https://leetcode.com/problems/add-binary/
// Approach: Traverse RTL. Add binary. check for all possible conditions
// case 1 - 0 0 0(carry) -> 0(res) 0(carry)
// case 2 - 0 1 0(carry) -> 1(res) 0(carry)
// case 3 - 1 1 0(carry) -> 0(res) 1(carry)
// case 4 - 1 1 1(carry) -> 1(res) 1(carry)
// TC: O(n)
// SC: O(n) -> res

#include <iostream>
using namespace std;

string addBinary(string a, string b)
{
    string res = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += a[i--] - '0';
        }
        if (j >= 0)
        {
            sum += b[j--] - '0';
        }
        if (sum == 0 || sum == 1)
        {
            res += to_string(sum);
            carry = 0;
        }
        else if (sum == 2)
        {
            res += "0";
            carry = 1;
        }
        else
        { // sum == 3
            res += "1";
            carry = 1;
        }
    }
    if (carry)
        res += "1";
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    cout << addBinary("11", "1") << endl;
}