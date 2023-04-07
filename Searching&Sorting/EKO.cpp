// https://www.spoj.com/problems/EKO/
// https://practice.geeksforgeeks.org/problems/cut-woods/0
// Approach: Binary search in range [0, max_element(arr)]
// Check if you are getting enough wood by cutting in the mid
// TC: O(log(maxOfArr))
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

int maxHeight(vector<int> &A, int M)
{
    long long low = 0, high = *max_element(A.begin(), A.end());

    while (low < high)
    {
        long long mid = high - (high - low) / 2;
        long long wood = 0;
        for (int i = 0; i < A.size(); i++)
            wood += max(A[i] - mid, (long long)0);
        if (wood < M)
            high = mid - 1;
        else
            low = mid;
    }
    return high;
}

int main()
{
    int n, m; // n = number of trees, m = wood required
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxHeight(arr, m) << endl;
    return 0;
}