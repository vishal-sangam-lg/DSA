// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
// Approach: Two pointer - one to traverse. other to store ans which is n steps behind ptr
// TC: O(n)
// SC: O(1)

int getNthFromLast(Node *head, int n)
{
    Node *curr = head;
    Node *save = head;
    while (curr)
    {
        if (n)
        {
            curr = curr->next;
            n--;
        }
        else
        {
            save = save->next;
            curr = curr->next;
        }
    }
    if (n)
        return -1;
    return save->data;
}