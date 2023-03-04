// https://leetcode.com/problems/middle-of-the-linked-list/
// Approach: Slow fast pointer. return ans according to odd or even length
// TC: O(n)
// SC: O(1)

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