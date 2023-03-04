// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
// Approach: slow pointer, fast pointer. If they meet, loop present.
// TC: O(n)
// SC: O(1)

bool detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}