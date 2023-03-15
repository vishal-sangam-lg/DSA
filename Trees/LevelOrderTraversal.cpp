// https://practice.geeksforgeeks.org/problems/level-order-traversal/1
// Approach: Add curr element to queue, call for left and right. In every iteration, process the queue.front()
// TC: O(n)
// SC: O(n)

vector<int> levelOrder(Node *node)
{
    vector<int> lvl;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        lvl.push_back(curr->data);
        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
    }
    return lvl;
}