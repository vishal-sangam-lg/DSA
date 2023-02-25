// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
// Approach: Add 1 to res
// Multiply 2 * 3 * 4 ...
// For every 2 or 3 or 4 ... -> Multiply every digit of res
// Update carry
// TC: O(n^2)

#include <iostream>
#include <vector>
using namespace std;

vector<int> factorial(int N)
{
    vector<int> res;
    res.push_back(1);
    // Multiply 1 * 2 * 3 * 4 to res
    for (int i = 2; i <= N; i++)
    {
        int carry = 0;
        // Multiply 2(example) to all digits of res and so on
        for (int j = res.size() - 1; j >= 0; j--)
        {
            int currDigit = res[j] * i + carry;
            res[j] = currDigit % 10;
            carry = currDigit / 10;
        }
        // Add carry to starting of vector
        while (carry > 0)
        {
            res.insert(res.begin(), carry % 10);
            carry /= 10;
        }
    }
    return res;
}