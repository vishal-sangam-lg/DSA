// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
// Approach: prev, curr, next pointers. Along with curr -> next = prev, point curr -> prev = next
// TC: O(n)
// SC: O(1)

// Iterative
Node *reverseDLL(Node *head)
{
    Node *curr = head, *prev = NULL, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Recursive
Node *reverseDLL(Node *head)
{
    if (not head)
    {
        return head;
    }
    if (not head->next)
    {
        head->prev = NULL;
        return head;
    }

    Node *newHead = reverseDLL(head->next);

    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;

    return newHead;
}