// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1
// Approach: Inorder traveral. count++ when you node matches condition
// TC: O(n)
// SC: O(height of tree)

void inorder(Node *root, int l, int h, int &count)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, l, h, count);
    if (root->data >= l && root->data <= h)
    {
        count++;
    }
    inorder(root->right, l, h, count);
}

int getCount(Node *root, int l, int h)
{
    int count = 0;
    inorder(root, l, h, count);
    return count;
}