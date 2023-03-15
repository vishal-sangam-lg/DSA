// https://practice.geeksforgeeks.org/problems/sum-tree/1
// Approach:
// If root == NULL make_pair(0, true)
// If root->left == NULL && root->right == NULL make_pair(root->data, true)
// recursion for left and right.
// if root->data = left + right. make_pair(2*root->data, true)
// else make_pair(0, false)
// TC: O(n)
// SC: O(height of tree)

pair<int, bool> solve(Node *root)
{
    if (root == NULL)
    {
        return make_pair(0, true);
    }
    if (root->left == NULL && root->right == NULL)
    {
        return make_pair(root->data, true);
    }
    pair<int, bool> left = solve(root->left);
    pair<int, bool> right = solve(root->right);

    if (left.second && right.second && (root->data == left.first + right.first))
    {
        return make_pair(2 * root->data, true);
    }
    else
    {
        return make_pair(0, false);
    }
}
bool isSumTree(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    pair<int, bool> ans = solve(root);
    return ans.second;
}