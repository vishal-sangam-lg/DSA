// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
// Approach: global maxLevel. sum += root->data. left and right recursion
// if current level is >= maxLevel, update ans accordingly
// TC: O(n)
// SC: O(height of tree)

int maxLevel = INT_MIN;
void solve(Node *root, int &ans, int level, int sum)
{
    if (root == NULL)
    {
        return;
    }
    sum += root->data;
    if (level >= maxLevel)
    {
        ans = sum;
        maxLevel = level;
    }
    else if (level == maxLevel)
    {
        ans = max(ans, sum);
    }

    solve(root->left, ans, level + 1, sum);
    solve(root->right, ans, level + 1, sum);
}
int sumOfLongRootToLeafPath(Node *root)
{
    int ans = 0;
    solve(root, ans, 1, 0);
    return ans;
}