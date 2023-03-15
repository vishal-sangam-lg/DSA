// https://practice.geeksforgeeks.org/problems/mirror-tree/1
// Approach: Traverse the tree -> swap(curr->left, curr->right) | Both recursive or iterative(queue) works
// TC: O(n)
// SC: O(n)

void mirror(Node *node)
{
    // Recursive Solution
    // if(node == NULL) return;

    // swap(node -> left, node -> right);
    // mirror(node -> left);
    // mirror(node -> right);

    // Iterative Solution
    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        swap(curr->left, curr->right);
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}