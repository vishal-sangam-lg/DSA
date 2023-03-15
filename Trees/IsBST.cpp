// https://practice.geeksforgeeks.org/problems/check-for-bst/1
// Approach: solve(root, lowerbound, upperbound).
// Check if root > lowerbound && root < upperbound.
// Update lowerbound and upperbound. return solve(left) && solve(right)
// TC: O(n)
// SC: O(n)

bool solve(Node *root, int lowerBound, int upperBound)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > lowerBound && root->data < upperBound)
    {
        bool left = solve(root->left, lowerBound, root->data);
        bool right = solve(root->right, root->data, upperBound);
        return left && right;
    }
    return false;
}

bool isBST(Node *root)
{
    return solve(root, INT_MIN, INT_MAX);
}