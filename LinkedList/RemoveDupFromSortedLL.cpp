// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
// Approach: Traverse LTR with ptr. if ptr and ptr -> next has same data. its duplicate. change links
// TC: O(n)
// SC: O(1)

Node *removeDuplicates(Node *head)
{
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->data == ptr->next->data)
        {
            ptr->next = ptr->next->next;
            continue;
        }
        ptr = ptr->next;
    }
    return head;
}