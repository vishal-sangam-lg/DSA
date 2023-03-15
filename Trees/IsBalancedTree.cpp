// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
// Naive solution: Traverse all nodes. Calculate left and right height. Get diff and return ans
// Why its naive? -> you are calculating left and right height again and again

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    bool diff = abs(leftHeight - rightHeight) <= 1;

    return (left && right && diff);
}

// Optimal Solution
// Approach: Use pair<int, bool> to store curr height and if its balanced
// if leftbalanced && rightbalanced && diff -> return make_pair(max(leftHeight, rightHeight) + 1, true)
// TC: O(n)
// SC: O(n)

pair<int, bool> solve(Node *root)
{
    if (root == NULL)
        return make_pair(0, true);

    pair<int, bool> leftAns = solve(root->left);
    pair<int, bool> rightAns = solve(root->right);

    int leftHeight = leftAns.first;
    int rightHeight = rightAns.first;

    bool diff = abs(leftHeight - rightHeight) <= 1;

    bool leftbalanced = leftAns.second;
    bool rightbalanced = rightAns.second;

    if (leftbalanced && rightbalanced && diff)
    {
        return make_pair(max(leftHeight, rightHeight) + 1, true);
    }
    else
    {
        return make_pair(max(leftHeight, rightHeight) + 1, false);
    }
}

bool isBalanced(Node *root)
{
    pair<int, bool> ans = solve(root);
    return ans.second;
}