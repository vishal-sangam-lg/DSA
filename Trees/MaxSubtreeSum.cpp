// https://practice.geeksforgeeks.org/problems/largest-subtree-sum-in-a-tree/1
// Approach: Calculate leftSubtreeSum, rightSubtreeSum.
// int includeCurrNode = leftSubtreeSum + rightSubtreeSum + root->data;
// int excludeCurrNode = max(leftSubtreeSum, rightSubtreeSum);
// ans = max({ans, includeCurrNode, excludeCurrNode});
// TC: O(n)
// SC: O(n)

int solve(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    int leftSubtreeSum = solve(root->left, ans);
    int rightSubtreeSum = solve(root->right, ans);

    int includeCurrNode = leftSubtreeSum + rightSubtreeSum + root->data;
    int excludeCurrNode = max(leftSubtreeSum, rightSubtreeSum);

    ans = max({ans, includeCurrNode, excludeCurrNode});

    return includeCurrNode;
}
// Function to find largest subtree sum.
int findLargestSubtreeSum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    int ans = INT_MIN;
    int garbage = solve(root, ans);
    return ans;
}