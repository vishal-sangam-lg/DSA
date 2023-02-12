// https://leetcode.com/problems/the-kth-factor-of-n
// Approach: Find all the factors. Return the factor when count == k
// TC: O(n)
// SC: O(1)

#include <iostream>
using namespace std;

int kthFactor(int n, int k)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
        if (count == k)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    cout << kthFactor(12, 5) << endl;
}