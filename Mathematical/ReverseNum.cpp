// https://leetcode.com/problems/reverse-integer/
// TC: O(n)
// SC: O(1)

#include <iostream>
using namespace std;

int reverse(int x)
{
    int ans = 0;
    while (x != 0)
    {
        if (ans < (INT_MIN / 10) || ans > (INT_MAX / 10))
        {
            return 0;
        }
        ans = (ans * 10) + (x % 10);
        x /= 10;
    }
    return ans;
}

int main()
{
    cout << reverse(125) << endl;
}
