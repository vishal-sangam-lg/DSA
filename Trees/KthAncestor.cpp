// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
// Approach I - Store the path while traversing. If you find k. Store path[path.size() - k] as ans
// TC: O(n)
// SC: O(height of tree)

int ans = -1;

void solve(Node *root, int &k, int node, vector<int> path)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == node)
    {
        if (path.size() < k)
            ans = -1;
        else
            ans = path[path.size() - k];
    }

    path.push_back(root->data);
    solve(root->left, k, node, path);
    solve(root->right, k, node, path);
    path.pop_back();
}

int kthAncestor(Node *root, int k, int node)
{
    vector<int> path;
    solve(root, k, node, path);
    return ans;
}

// Approach - II (optimal)
// If root == node, return root. if either left or right is not null, k-- and check for ans

Node *solve(Node *root, int &k, int node)
{
    if (root == NULL)
        return NULL;

    if (root->data == node)
    {
        return root;
    }

    Node *left = solve(root->left, k, node);
    Node *right = solve(root->right, k, node);

    if (left != NULL && right == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }
    else if (left == NULL && right != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }
    else
    {
        return NULL;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}