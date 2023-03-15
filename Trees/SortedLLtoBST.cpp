// https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1
// Approach: Find middle of LL. Create tree node with middle LLnode,
// Join its left to call(left), join its right to call(right)

TNode *sortedListToBST(LNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return new TNode(head->data);
    }

    // Find the middle
    LNode *fast = head, *slow = head, *prev = NULL;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    // Disconnect LL at middle
    prev->next = NULL;

    // Create node with middle node, call(left), call(right)
    TNode *root = new TNode(slow->data);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
}