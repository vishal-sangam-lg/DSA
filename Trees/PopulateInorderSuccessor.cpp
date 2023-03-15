// https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1
// Approach: Inorder traversal, with prev. If prev != NULL. point prev -> next = root.
// update prev to root before moving right
// TC: O(n)
// SC: O(n)

Node *prev = NULL;
void populateNext(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    populateNext(root->left);

    if (prev != NULL)
    {
        prev->next = root;
    }
    prev = root;

    populateNext(root->right);
}