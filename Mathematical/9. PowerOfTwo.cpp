// https://leetcode.com/problems/power-of-two/
// Approach: n has only 1 set bit. n-1 will have all bits set except that one
// Ex. 4(100) 3(11)
// TC: O(1)
// SC: O(1)

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;
    return (n & (n - 1)) == 0;
}