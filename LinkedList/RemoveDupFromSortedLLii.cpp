// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// https://practice.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1
// Same answer for both

// Approach: Create dummy node. connect it to head. Remove nodes that are duplicate while traversing
// TC: O(n)
// SC: O(1)

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *ans = new ListNode(0);
    ans->next = head;
    ListNode *cur = ans;
    int duplicate;
    while (cur->next && cur->next->next)
    {
        if (cur->next->val == cur->next->next->val)
        {
            duplicate = cur->next->val;
            while (cur->next && cur->next->val == duplicate)
            {
                cur->next = cur->next->next;
            }
        }
        else
        {
            cur = cur->next;
        }
    }
    return ans->next;
}