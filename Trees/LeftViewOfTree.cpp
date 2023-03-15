// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// Approach: Level order traversal using queue. print when i = 0 in curr level
// TC: O(n)
// SC: O(n)

vector<int> leftView(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    if (root == NULL)
        return ans;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
                ans.push_back(curr->data);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return ans;
}