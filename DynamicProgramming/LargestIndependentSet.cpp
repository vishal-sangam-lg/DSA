// https://practice.geeksforgeeks.org/problems/largest-independent-set-problem/1
// Approach:
// Include Exclude pattern with pair<int,int> {include, exclude}
// include current node -> ans.first = 1 + left.second + right.second
// exclude current node -> ans.second = max(left) + max(right)

// pair<int,int> stores {include_case_ans, exclude_case_ans}
pair<int, int> solve(Node *root)
{
    if (root == NULL)
        return make_pair(0, 0);

    // get values from both left subtree and right subtree
    pair<int, int> l = solve(root->left);
    pair<int, int> r = solve(root->right);

    // For storing answer of current node
    pair<int, int> ans;

    // If we include the present node -> We can't include its left and right
    ans.first = 1 + l.second + r.second;

    // if we don't include the present node
    // We can take max(include or exclude) in both left and right
    ans.second = max(l.first, l.second) + max(r.first, r.second);
    return ans;
}

// map<Node, <include_case_ans, exclude_case_ans>>
pair<int, int> solveMem(Node *root, map<Node *, pair<int, int>> &dp)
{
    if (root == NULL)
        return dp[root] = make_pair(0, 0);
    if (dp.find(root) != dp.end())
    {
        return dp[root];
    }

    // get values from both left subtree and right subtree
    pair<int, int> l = solveMem(root->left, dp);
    pair<int, int> r = solveMem(root->right, dp);

    // For storing answer of current node
    pair<int, int> ans;

    // If we include the present node -> We can't include its left and right
    ans.first = 1 + l.second + r.second;

    // if we don't include the present node
    // We can take max(include or exclude) in both left and right
    ans.second = max(l.first, l.second) + max(r.first, r.second);
    return dp[root] = ans;
}

int LISS(Node *root)
{
    // Recursive solution
    // pair<int,int> ans = solve(root);
    // return max(ans.first,ans.second);

    // DP Memoisation solution
    map<Node *, pair<int, int>> dp;
    pair<int, int> ans = solveMem(root, dp);
    return max(ans.first, ans.second);
}