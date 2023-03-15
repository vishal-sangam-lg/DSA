// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
// Approach: Print curr. if left exist, add to queue and move right
// Process till queue is empty
// TC: O(n)
// SC: O(n)

vector<int> diagonal(Node *root)
{
    queue<Node *> q;
    vector<int> ans;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        while (curr != NULL)
        {
            ans.push_back(curr->data);
            if (curr->left)
            {
                q.push(curr->left);
            }
            curr = curr->right;
        }
    }
    return ans;
}