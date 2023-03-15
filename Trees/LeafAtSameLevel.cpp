// https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1
// Approach: Keep a global level and currLevel.
// Increment currLevel for every left and right child
// If its left node and currLevel is not equal to global level. Mark flag as false
// TC: O(n)
// SC: O(height of tree)

int level = -1;
void solve(Node *root, int currLevel, bool &flag)
{
    if (root == NULL || flag == false)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (level != -1 && currLevel != level)
            flag = false;
        else
            level = currLevel;
    }
    solve(root->left, currLevel + 1, flag);
    solve(root->right, currLevel + 1, flag);
}
bool check(Node *root)
{
    bool flag = true;
    solve(root, 0, flag);
    return flag;
}