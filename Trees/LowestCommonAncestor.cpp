// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
// Approach: If you find n1 or n2, return root. else return null.
// If leftAns and rightAns are both not null. root is the ans. return ans.
// Else return whatever is not null
// TC: O(n)
// SC: O(height of tree)

Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else
    {
        return NULL;
    }
}