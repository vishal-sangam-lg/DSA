// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
// Approach: Return 1 + max(height(left), height(right))
// TC: O(n)
// SC: O(n)

int height(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);
    return 1 + max(left, right);
}