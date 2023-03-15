// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
// Approach: Level order traversal. Level is even -> print as it is. odd -> print reverse
// TC: O(n)
// SC: O(n)

vector<int> zigZagTraversal(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    int level = 0;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        while (size > 0)
        {
            Node *curr = q.front();
            q.pop();
            temp.push_back(curr->data);
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            size--;
        }
        if (level % 2 == 0)
        {
            for (auto it : temp)
                ans.push_back(it);
        }
        else
        {
            reverse(temp.begin(), temp.end());
            for (auto it : temp)
                ans.push_back(it);
        }
        level++;
    }
    return ans;
}