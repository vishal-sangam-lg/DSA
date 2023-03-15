// https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1
// Approach: Traverse inorder of BT, store in vector. Sort it.
// Traverse BT inorder again and replace data according to sorted vector
// TC: O(nlogn)
// SC: O(n)

void inorderTraversal(Node *root, vector<int> &inorder)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}
void buildBST(Node *root, vector<int> &inorder, int &i)
{
    if (root == NULL)
    {
        return;
    }

    buildBST(root->left, inorder, i);
    root->data = inorder[i++];
    buildBST(root->right, inorder, i);
}
Node *binaryTreeToBST(Node *root)
{
    int i = 0;
    vector<int> inorder;
    inorderTraversal(root, inorder);
    sort(inorder.begin(), inorder.end());
    buildBST(root, inorder, i);
    return root;
}