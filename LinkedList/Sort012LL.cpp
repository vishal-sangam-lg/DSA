// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
// Approach: Count frequency of 0 1 2 in first traversal. Fill LL in second traversal
// TC: O(n)
// SC: O(1)

Node *segregate(Node *head)
{
    int zero = 0, one = 0, two = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
            zero++;
        else if (curr->data == 1)
            one++;
        else
            two++;
        curr = curr->next;
    }
    curr = head;
    while (curr != NULL)
    {
        if (zero > 0)
        {
            curr->data = 0;
            zero--;
        }
        else if (one > 0)
        {
            curr->data = 1;
            one--;
        }
        else
        {
            curr->data = 2;
        }
        curr = curr->next;
    }
    return head;
}