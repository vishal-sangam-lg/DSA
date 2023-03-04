// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
// Approach: Take two LL - odd and even. Append odd and even nodes to them respectively
// Join even-odd and return

Node *divide(int N, Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *even = new Node(-1);
    Node *odd = new Node(-1);
    Node *evenptr = even;
    Node *oddptr = odd;

    Node *temp = head;

    while (temp != NULL)
    {
        if ((temp->data) % 2 == 0)
        {
            evenptr->next = temp;
            evenptr = evenptr->next;
        }
        else
        {
            oddptr->next = temp;
            oddptr = oddptr->next;
        }
        temp = temp->next;
    }
    if (even->next != NULL)
    {
        evenptr->next = odd->next;
        oddptr->next = NULL;
        return even->next;
    }
    return odd->next;
}