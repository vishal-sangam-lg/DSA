// https://practice.geeksforgeeks.org/problems/circular-linked-list/1
// Approach: Store head and temp and move head.
// If head reaches null, false. If head reaches temp, true
// TC: O(n)
// SC: O(1)

bool isCircular(struct Node *head)
{
    if (!head)
        return true;

    struct Node *temp = head;

    while (head && head->next != temp)
        head = head->next;

    if (!head || !(head->next))
        return false;

    return true;
}