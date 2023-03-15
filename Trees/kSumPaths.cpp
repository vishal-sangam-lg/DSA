// https://practice.geeksforgeeks.org/problems/k-sum-paths/1
// Approach: Recursive call for left and right starting from every node. If k == sum. ans++
// TC: O(n^2)
// Optimal solution: O(n)

int ans = 0;
void solve(Node *root, int k, int sum)
{
    if (root == NULL)
        return;

    sum += root->data;
    if (sum == k)
        ans++;

    solve(root->left, k, sum);
    solve(root->right, k, sum);
}
int sumK(Node *root, int k)
{
    if (root == NULL)
        return 0;
    solve(root, k, 0);
    sumK(root->left, k);
    sumK(root->right, k);
    return ans;
}