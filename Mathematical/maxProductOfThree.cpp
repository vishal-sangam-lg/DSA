// https://leetcode.com/problems/maximum-product-of-three-numbers/
// Approach: Find smallest, second smallest, largest, secondLargest, thirdLargest in array
// Ans can either be min1*min2*max1 or max1*max2*max3
// TC: O(n)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

int maximumProduct(vector<int> &nums)
{
    int min1 = INT_MAX; // smallest
    int min2 = INT_MAX; // secondSmallest
    int max1 = INT_MIN; // largest
    int max2 = INT_MIN; // secondLargest
    int max3 = INT_MIN; // thirdLargest
    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= min1)
        {
            min2 = min1;
            min1 = nums[i];
        }
        else if (nums[i] <= min2)
        {
            min2 = nums[i];
        }

        if (nums[i] >= max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        }
        else if (nums[i] >= max2)
        {
            max3 = max2;
            max2 = nums[i];
        }
        else if (nums[i] >= max3)
        {
            max3 = nums[i];
        }
    }
    ans = max(ans, min1 * min2 * max1);
    ans = max(ans, max1 * max2 * max3);
    return ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    cout << maximumProduct(nums) << endl;
    return 0;
}