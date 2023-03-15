// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
// Approach: Get include and exclude sum. store max(include, exclude) in map<Node*, int>dp
// Include -> call for left->left and left->right, right->left and right->right
// Exclude -> call for left + right

unordered_map<Node *, int> dp;
int getMaxSum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (dp[root])
    {
        return dp[root];
    }

    int include = root->data;
    if (root->left != NULL)
    {
        include += getMaxSum(root->left->left);
        include += getMaxSum(root->left->right);
    }
    if (root->right != NULL)
    {
        include += getMaxSum(root->right->left);
        include += getMaxSum(root->right->right);
    }

    int exclude = getMaxSum(root->right) + getMaxSum(root->left);

    return dp[root] = max(include, exclude);
}