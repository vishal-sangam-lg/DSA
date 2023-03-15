// https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
// Approach: Inorder traversal, update ans when required
// TC: O(height of tree)
// SC: O(1)

int findCeil(Node *root, int x)
{
    int res = -1;
    while (root != NULL)
    {
        if (root->data == x)
        {
            return root->data;
        }
        else if (root->data > x)
        {
            res = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return res;
}