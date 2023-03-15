// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
// Approach: Inorder traversal. Instead of printing, k-- and if k==0, ans = root->data
// TC: O(n)
// SC: O(height of tree)

void inorder(Node *root, int &k, int &ans)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, k, ans);

    k--;
    if (k == 0)
    {
        ans = root->data;
    }

    inorder(root->right, k, ans);
}

int KthSmallestElement(Node *root, int K)
{
    int ans = -1;
    inorder(root, K, ans);
    return ans;
}