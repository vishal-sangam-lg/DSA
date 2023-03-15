// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
// Approach: Traverse Right root left. instead of printing root, k-- if k == 0, ans = root->data
// TC: O(n)
// SC: O(height of tree)

int ans = -1;
int kthLargest(Node *root, int &K)
{
    if (root == NULL)
    {
        return 0;
    }

    kthLargest(root->right, K);

    K--;
    if (K == 0)
    {
        ans = root->data;
    }

    kthLargest(root->left, K);
    return ans;
}