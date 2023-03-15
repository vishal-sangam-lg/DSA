// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
// Approach: Level order traversal using queue. print when i = q.size()-1 in curr level
// TC: O(n)
// SC: O(n)

vector<int> rightView(Node *root)
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
            if (i == size - 1)
                ans.push_back(curr->data);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return ans;
}