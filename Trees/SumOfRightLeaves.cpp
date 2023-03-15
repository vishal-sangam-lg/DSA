// https://practice.geeksforgeeks.org/problems/sum-of-right-leaf-nodes/1

int rightLeafSum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = 0;
    if (root->right != NULL && root->right->left == NULL &&
        root->right->right == NULL)
    {
        sum += root->right->data;
    }
    return sum += rightLeafSum(root->left) + rightLeafSum(root->right);
}