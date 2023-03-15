// https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
// Approach:
// Ans should be in preorder(NLR) Traverse RLN(reverse of preorder). Construct LL from RTL,
// maintain prev to store rightmost node recently added

Node *prev = NULL;
void flatten(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    flatten(root->right);
    flatten(root->left);

    root->left = NULL;
    root->right = prev;
    prev = root;
}