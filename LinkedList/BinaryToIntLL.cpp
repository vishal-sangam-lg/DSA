// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// Approach: Process every node LTR
// TC: O(n)
// SC: O(1)

int getDecimalValue(ListNode *head, int res = 0)
{
    return head ? getDecimalValue(head->next, res * 2 + head->val) : res;
}

int getDecimalValue(ListNode *head)
{
    int res = 0;
    while (head != NULL)
    {
        res = res * 2 + head->val;
        head = head->next;
    }
    return res;
}
