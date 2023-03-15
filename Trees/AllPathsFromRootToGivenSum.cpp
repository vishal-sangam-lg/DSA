// https://practice.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1
// Approach: Preorder traversal, Maintain currSum, if it matches target, add currPath

void solve(Node *root, vector<int> currPath, int currSum, int target, vector<vector<int>> &ans)
{
    if (root == NULL)
    {
        return;
    }
    currSum += root->key;
    currPath.push_back(root->key);
    if (currSum == target)
    {
        ans.push_back(currPath);
        return;
    }

    solve(root->left, currPath, currSum, target, ans);
    solve(root->right, currPath, currSum, target, ans);
}
vector<vector<int>> printPaths(Node *root, int sum)
{
    vector<vector<int>> ans;
    vector<int> currPath;
    solve(root, currPath, 0, sum, ans);
    return ans;
}