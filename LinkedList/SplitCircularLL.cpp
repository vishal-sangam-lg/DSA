// https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1
// Appraoch: Slow fast pointer, connect back the halves according to odd or even length LL
// TC: O(n)
// SC: O(1)

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow = head, *fast = head;
    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *temp = slow->next;
    slow->next = head;
    // Odd length LL
    if (fast->next == head)
    {
        fast->next = temp;
    } // Even length LL
    else
    {
        fast->next->next = temp;
    }

    *head1_ref = head;
    *head2_ref = temp;
}