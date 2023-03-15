// https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1
// Approach: Inorder traversal and store in vector. Build node with vector taking mid.
// call(left, start, mid-1) call(right, mid+1, end)
// TC: O(n)
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

Node *build(vector<int> &inorder, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(inorder[mid]);
    root->left = build(inorder, start, mid - 1);
    root->right = build(inorder, mid + 1, end);
    return root;
}

Node *buildBalancedTree(Node *root)
{
    vector<int> inorder;
    inorderTraversal(root, inorder);
    return build(inorder, 0, inorder.size() - 1);
}