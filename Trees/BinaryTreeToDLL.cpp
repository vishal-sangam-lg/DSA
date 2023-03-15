// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
// Approach:
// Inorder Traversal. Maintain head and prev
// Instead of printing. process DLL, join links
// TC: O(n)
// SC: O(height of tree)

void solve(Node *root, Node *&head, Node *&prev)
{
    if (root == NULL)
    {
        return;
    }

    solve(root->left, head, prev);

    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    solve(root->right, head, prev);
}
// Function to convert binary tree to doubly linked list and return it.
Node *bToDLL(Node *root)
{
    Node *head = NULL;
    Node *prev = NULL;
    solve(root, head, prev);
    return head;
}