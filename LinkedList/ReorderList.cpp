// https://leetcode.com/problems/reorder-list/
// Approach: Cut at middle of LL, Reverse second half of LL, Merge First and second half

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Odd length LL
    if (fast->next == NULL)
        return slow;
    // Even length LL
    else
        return slow->next;
}
ListNode *reverse(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = head->next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
void reorderList(ListNode *head)
{
    if (!head || !head->next)
        return;

    // cut from the middle and reverse the second half: O(n)
    ListNode *middle = middleNode(head);

    ListNode *head2 = middle->next;
    middle->next = NULL;

    head2 = reverse(head2);

    ListNode *ptr1 = head;
    ListNode *ptr2 = head2;
    ListNode *temp1, *temp2;
    // Merging
    while (ptr1 && ptr2)
    {
        temp1 = ptr1->next;
        temp2 = ptr2->next;
        ptr1->next = ptr2;
        ptr2->next = temp1;
        ptr1 = temp1;
        ptr2 = temp2;
    }
}