// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
// Approach: Find LCA, find distance from n1 to LCA and n2 to LCA. Return d1+d2 |
// Optimal solution -> find d1, d2 along with LCA

int ans = 0;
int solve(Node *root, int a, int b)
{
    // If root is null or ans is already found return 0
    if (root == NULL || ans > 0)
        return 0;

    int leftAns = solve(root->left, a, b);
    int rightAns = solve(root->right, a, b);

    // If you find a or b. Return whichever was already found or 1(found a or b for first time)
    if ((root->data == a || root->data == b))
    {
        if (leftAns != 0)
            ans = leftAns;
        else if (rightAns != 0)
            ans = rightAns;
        else
            return 1;
    }

    // Add current node(1) and forward left and right.
    // If both are not 0, its the lca.
    if (leftAns != 0 && rightAns != 0)
        ans = leftAns + rightAns;
    else if (leftAns != 0)
        return leftAns + 1;
    else if (rightAns != 0)
        return rightAns + 1;
    return 0;
}
int findDist(Node *root, int a, int b)
{
    if (a == b)
        return 0;
    solve(root, a, b);
    return ans;
}