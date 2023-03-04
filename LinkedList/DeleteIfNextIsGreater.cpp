// https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1
// Approach: Traverse the LL.
// If curr < its next. curr data = curr next data. point curr to its next next. delete curr next

Node *compute(Node *head)
{
    Node *curr = head;

    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data < curr->next->data)
        {
            curr->data = curr->next->data;
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            curr = head;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}