// https://practice.geeksforgeeks.org/problems/median-of-bst/1
// Approach: Inorder traversal, store in vector. According to size of vector is odd or even, return ans
// TC: O(n)
// SC: O(n)

void inorderTraversal(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left, v);
    v.push_back(root->data);
    inorderTraversal(root->right, v);
}

float findMedian(struct Node *root)
{
    vector<int> inorder;
    inorderTraversal(root, inorder);
    int n = inorder.size();
    double mid = inorder[n / 2];
    if (n % 2 == 0)
    {
        return float(float(inorder[n / 2] + inorder[(n / 2) - 1]) / 2);
    }
    else
    {
        return float(inorder[n / 2]);
    }
}