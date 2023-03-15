// https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1
// Approach: Return the leftmost node for min. Return rightmost node for max
// TC: O(height of tree)
// SC: O(1)

int minValue(Node *root)
{
    if (!root)
        return -1;
    while (root->left)
    {
        root = root->left;
    }
    return root->data;
}