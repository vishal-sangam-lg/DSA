// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

// DP solution
// TC: O(n^2)
// SC: O(n)

// Step 1: Create a strictly increasing array
// Copy arr to set to get rid of duplicates
// because duplicates can't be strictly increasing
// Copy set to vector, sort it to get a strictly increasing array

// Step 2: Find length of longest common subsequence
// in actual arr and strictly increasing array

// Function to find length of longest common subsequence.
int lcs(vector<int> &a, vector<int> &b, int N, int M)
{
    if (N < M)
    {
        swap(N, M);
        swap(a, b);
    }

    vector<int> prev(M + 1, 0);
    vector<int> curr(M + 1, 0);
    vector<int> ans(M + 1, 0);

    for (int n = 1; n <= N; n++)
    {
        for (int m = 1; m <= M; m++)
        {
            if (a[n - 1] == b[m - 1])
            {
                ans[m] = 1 + prev[m - 1];
            }
            else
            {
                ans[m] = max(prev[m], curr[m - 1]);
            }
            prev = curr;
            curr = ans;
        }
    }

    return ans[M];
}

int longestSubsequence(int n, int arr[])
{
    // Step 1: Creating strictly increasing vector
    unordered_set<int> s(arr, arr + n);
    vector<int> strictlyIncreasing(s.begin(), s.end());
    sort(strictlyIncreasing.begin(), strictlyIncreasing.end());

    // Step 2: Find lcs(arr, strictlyIncreasing)
    vector<int> a(arr, arr + n);
    return lcs(a, strictlyIncreasing, a.size(), strictlyIncreasing.size());
}

// Optimal solution - Binary search
// TC: O(nlogn)
// SC: O(n)

// lower_bound(begin, end, val) in c++
// return an iterator pointing to the first element in the range which has a value not less than val.

// Approach: Get the lower_bound of current element in res
// Current element could be placed in place of lower_bound in res

// Dry run:
// [1 7 8 4 5 6 -1 9]
// res
// [1 7 8]
// [1 4 8]
// [1 4 5]
// [1 4 5 6]
// [-1 4 5 6]
// [-1 4 5 6 9]
// length = 5

int longestSubsequence(int n, int a[])
{
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int index = lower_bound(res.begin(), res.end(), a[i]) - res.begin();
        // What you found is the largest element seen till now
        if (index == res.size())
        {
            res.push_back(a[i]);
        }
        // What you found can fit in between
        else
        {
            res[index] = a[i];
        }
    }
    return res.size();
}