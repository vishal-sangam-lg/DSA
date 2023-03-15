// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
// Approach: return solve(root->left, lowerbound, root->data - 1) || solve(root->right, root->data + 1, upperbound).
// When node = upperbound = lowerbound, its a dead end

bool solve(Node *root, int lowerbound, int upperbound)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == lowerbound && root->data == upperbound)
    {
        return true;
    }

    return solve(root->left, lowerbound, root->data - 1) || solve(root->right, root->data + 1, upperbound);
}

bool isDeadEnd(Node *root)
{
    int lowerbound = 1, upperbound = INT_MAX;
    return solve(root, lowerbound, upperbound);
}