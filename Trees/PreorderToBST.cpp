// https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1
// Striver: https://www.youtube.com/watch?v=UmJT3j26t1I

// Alternate approach: sort preorder to get inorder. Construct bst with preorder and inorder
// TC: O(nlogn)
// SC: O(n)

// Better approach:
// While adding left child, upper bound will be current node.
// While adding right child, upper bound will be parent node.
// Traverse Preorder, maintain upperbound. Construct BST
// TC: O(n)
// SC: O(n)

Node *build(int pre[], int &i, int n, int upperBound)
{
    if (i == n || pre[i] > upperBound)
    {
        return NULL;
    }

    Node *root = newNode(pre[i]);
    i++;

    root->left = build(pre, i, n, root->data);
    root->right = build(pre, i, n, upperBound);
    return root;
}
Node *post_order(int pre[], int size)
{
    int i = 0;
    return build(pre, i, size, INT_MAX);
}