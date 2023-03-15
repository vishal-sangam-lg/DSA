// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// Approach: Return max((height(left)+height(right)+1), diameter(left), diameter(right))
// TC: O(n)
// SC: O(height of tree)

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int a = height(root->left) + height(root->right) + 1;
    int b = diameter(root->left);
    int c = diameter(root->right);
    return (max(a, max(b, c)));
}