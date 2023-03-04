// https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1
// Approach:
// Initilising tail of LL
// connect tail to head
// Traverse to new tail after rotation
// Disconnect tail and return new head
// TC: O(n)
// SC: (1)

Node *rotate(Node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Initilising tail of LL
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    // connect tail to head
    tail->next = head;

    // Traverse to new tail after rotation
    while (k--)
    {
        tail = tail->next;
    }

    // Disconnect tail and return new head
    head = tail->next;
    tail->next = NULL;
    return head;
}