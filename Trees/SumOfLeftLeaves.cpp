// https://leetcode.com/problems/sum-of-left-leaves/
// https://practice.geeksforgeeks.org/problems/sum-of-left-leaf-nodes/1

int sumOfLeftLeaves(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = 0;
    if (root->left != NULL && root->left->left == NULL &&
        root->left->right == NULL)
    {
        sum += root->left->val;
    }
    sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    return sum;
}