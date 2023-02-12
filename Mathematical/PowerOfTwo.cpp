// https://leetcode.com/problems/power-of-two/
// Approach: n has only 1 set bit. n-1 will have all bits set
// Ex. 4(100) 3(11)
// TC: O(1)
// SC: O(1)

#include <iostream>
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    }
    int ans = n & (n - 1);
    return ans == 0;
}

int main()
{
    cout << isPowerOfTwo(16) << " " << isPowerOfTwo(5) << endl;
}