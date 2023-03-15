// https://practice.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/1
// Approach: Traverse RTL. if upper_bound of arr[i] is already in set. Add *itr to ans else -1
// TC: O(nlogn)
// SC: O(n)

// Solution using BST -> construct BST with given arr.
// Inorder traversal. Find inorder successor for every node

vector<int> findLeastGreater(vector<int> &arr, int n)
{
    set<int> s;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        auto itr = s.upper_bound(arr[i]);
        if (itr == s.end())
            ans.push_back(-1);
        else
            ans.push_back(*itr);
        s.insert(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}