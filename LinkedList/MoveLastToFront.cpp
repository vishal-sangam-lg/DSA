// https://practice.geeksforgeeks.org/problems/move-last-element-to-front-of-a-linked-list/1
// Approach: Traverse & Find secondLast. store last. point secondLast to null. last to head
// TC: O(n)
// SC: O(1)

ListNode *moveToFront(ListNode *head)
{
    if (head->next == NULL)
        return head;

    ListNode *secondLast = head;

    while (secondLast->next->next != NULL)
    {
        secondLast = secondLast->next;
    }

    ListNode *last = secondLast->next;
    secondLast->next = NULL;
    last->next = head;

    return last;
}