// https://leetcode.com/problems/ugly-number-ii/
// https://practice.geeksforgeeks.org/problems/ugly-number-ii/1
// Approach: i,j,k to point at 2,3,5 multiple recently added
// Try to fill in ascending order
// res[i]*2,res[j]*3,res[k]*5 -> Add the min of 3 cases
// TC: O(n)
// SC: O(n)

int nthUglyNumber(int n)
{
    int i = 0, j = 0, k = 0;
    vector<int> res(1, 1);
    while (res.size() < n)
    {
        // It has to be a multiple of 2 or 3 or 5. So try to fill in ascending order
        res.push_back(min({res[i] * 2, res[j] * 3, res[k] * 5}));
        if (res.back() == res[i] * 2)
            i++;
        if (res.back() == res[j] * 3)
            j++;
        if (res.back() == res[k] * 5)
            k++;
    }
    return res.back();
}