// https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1
// Approach: serialize tree -> to_string(root->data)+"$"+solve(root->left)+"$"+solve(root->right)
// Add to map. If already exist, add to ans

vector<Node *> ans;
unordered_map<string, int> m;
string solve(Node *root)
{
    if (root == NULL)
        return "";

    string curr = to_string(root->data) + "$" + solve(root->left) + "$" + solve(root->right);

    if (m[curr] == 1)
    {
        ans.push_back(root);
    }
    m[curr]++;

    return curr;
}
vector<Node *> printAllDups(Node *root)
{
    ans.clear();
    m.clear();
    solve(root);
    return ans;
}