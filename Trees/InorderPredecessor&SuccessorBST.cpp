// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
// Inorder predecessor -> highest element in left subtree
// Inorder successor -> lowest element in right subtree
// Approach: Find key.
// Predecessor -> search for highest element in left subtree
// Successor -> search lowest element in right subtree

// Basic Approach:
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    if (root == NULL)
    {
        return;
    }
    findPreSuc(root->left, pre, suc, key);
    if (root->key < key)
    {
        pre = root;
    }
    else if (suc == NULL && root->key > key)
    {
        suc = root;
    }
    findPreSuc(root->right, pre, suc, key);
    return;
}

// Optimal
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
        return;
    // Find key
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->key == key)
        {
            break;
        }
        if (curr->key > key)
        {
            suc = curr;
            curr = curr->left;
        }
        else
        {
            pre = curr;
            curr = curr->right;
        }
    }

    // Find the larget element in left Subtree -> predecessor
    if (curr != NULL)
    {
        Node *leftTree = curr->left;
        while (leftTree != NULL)
        {
            pre = leftTree;
            leftTree = leftTree->right;
        }
    }

    // Find the smallest element in right Subtree -> successor
    if (curr != NULL)
    {
        Node *rightTree = curr->right;
        while (rightTree != NULL)
        {
            suc = rightTree;
            rightTree = rightTree->left;
        }
    }
}