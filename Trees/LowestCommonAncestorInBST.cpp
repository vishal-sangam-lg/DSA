// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
// Approach:
// If root is less than both n1 & n2, LCA lies on right subtree
// If root is greater than both n1 & n2, LCA lies on left subtree
// Else n1 & n2 are in different subtree. Hence thats LCA
// TC: (height of BST)
// SC: (height of BST)

Node *LCA(Node *root, int n1, int n2)
{
    while (root != NULL)
    {
        // If root is less than both n1 & n2, LCA lies on right subtree
        if (root->data < n1 && root->data < n2)
        {
            root = root->right;
        }
        // If root is greater than both n1 & n2, LCA lies on left subtree
        else if (root->data > n1 && root->data > n2)
        {
            root = root->left;
        }
        // Else n1 & n2 are in different subtree. Hence thats LCA
        else
        {
            break;
        }
    }
    return root;
}