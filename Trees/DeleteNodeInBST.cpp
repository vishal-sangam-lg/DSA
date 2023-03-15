// https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1
// Approach: Search BST. Find key. copy inorderSuccessor to key node. delete(root->right, successor)

int findSuccessor(Node *root)
{
    while (root->left != nullptr)
        root = root->left;

    return root->data;
}
Node *deleteNode(Node *root, int x)
{
    if (!root)
        return nullptr;

    if (root->data > x)
        root->left = deleteNode(root->left, x);
    else if (root->data < x)
        root->right = deleteNode(root->right, x);

    else
    {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        else
        {
            root->data = findSuccessor(root->right);
            root->right = deleteNode(root->right, root->data);
        }
    }
    return root;
}