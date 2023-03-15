// Count number of paths with target sum
// https://leetcode.com/problems/path-sum-iii/
// Approach: Preorder traversal, Maintain currSum, if it matches target, count++

int sumUp(TreeNode *root, long long currSum, int &sum)
{
    if (!root)
        return 0;
    currSum += root->val;
    return (currSum == sum) + sumUp(root->left, currSum, sum) + sumUp(root->right, currSum, sum);
}
int pathSum(TreeNode *root, int sum)
{
    if (!root)
        return 0;
    return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}