// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
// Approach: Level order traversal using queue checking condition
// If you find null in queue, break
// You shouldn't find anything left in queue other than null

bool isHeap(struct Node *root)
{
    // code here
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *x = q.front();
        if (x == NULL)
        {
            break;
        }
        q.pop();
        if (x->left)
        {
            if (x->left->data > x->data)
                return false;
            else
                q.push(x->left);
        }
        else
        {
            q.push(NULL);
        }
        if (x->right)
        {
            if (x->right->data > x->data)
                return false;
            else
                q.push(x->right);
        }
        else
        {
            q.push(NULL);
        }
    }
    while (!q.empty())
    {
        if (q.front() != NULL)
            return false;
        q.pop();
    }
    return true;
}