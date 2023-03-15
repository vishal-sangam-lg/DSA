// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1
// Approach: old value = node->data. Transform node->data = solve(left)+solve(right). Return oldValue + node->data
// TC: O(n)
// SC: O(height of tree)

int solve(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int oldValue = node->data;
    node->data = solve(node->left) + solve(node->right);
    return oldValue + node->data;
}
void toSumTree(Node *node)
{
    solve(node);
}