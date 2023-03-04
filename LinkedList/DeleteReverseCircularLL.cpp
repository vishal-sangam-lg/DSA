// https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1
// TC: O(n)
// SC: O(1)

void deleteNode(struct Node **head, int key)
{
    Node *ptr = *head;

    while (ptr->next->data != key)
        ptr = ptr->next;

    Node *del = ptr->next;
    ptr->next = ptr->next->next;
    delete del;
}

/* Function to reverse the linked list */
void reverse(struct Node **head_ref)
{
    Node *curr = *head_ref;
    Node *prev = NULL;
    Node *next;
    while (curr->next != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    *head_ref = prev;
}