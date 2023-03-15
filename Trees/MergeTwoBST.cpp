// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1
// Approach: Iterative inorder traversal using 2 stack,
// while (root1 || root2 || s1.size() || s2.size())
// Go left, Process -> add whichever is smaller to ans, Go right

vector<int> merge(Node *root1, Node *root2)
{
    vector<int> ans;
    stack<Node *> s1, s2;
    while (root1 || root2 || s1.size() || s2.size())
    {
        while (root1)
        {
            s1.push(root1);
            root1 = root1->left;
        }
        while (root2)
        {
            s2.push(root2);
            root2 = root2->left;
        }

        if (s2.empty() || (!s1.empty() && s1.top()->data < s2.top()->data))
        {
            root1 = s1.top();
            ans.push_back(root1->data);
            s1.pop();
            root1 = root1->right;
        }
        else
        {
            root2 = s2.top();
            ans.push_back(root2->data);
            s2.pop();
            root2 = root2->right;
        }
    }
    return ans;
}