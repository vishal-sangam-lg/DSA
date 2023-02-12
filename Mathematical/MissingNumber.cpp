// https://leetcode.com/problems/missing-number/
// TC: O(n)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

// Approach - I (Optimal)
int missingNumber(vector<int> &nums)
{
    // a XOR a = 0
    // Since we have numbers and same indexes
    // In the end, we will have the missingNumber
    // when we xor all numbers and indexes
    int ans = 0, i;
    for (i = 0; i < nums.size(); i++)
    {
        ans = ans ^ nums[i] ^ i;
    }
    ans = ans ^ i; // For last element
    return ans;
}

// Approach - II
// int missingNumber(vector<int> &nums)
// {
//     int sum = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         sum += nums[i];
//     }
//     int n = nums.size();
//     int sumTillN = (n * (n + 1)) / 2;
//     return sumTillN - sum;
// }

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(3);
    cout << missingNumber(v) << endl;
}