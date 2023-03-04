// https://practice.geeksforgeeks.org/problems/44bb5287b98797782162ffe3d2201621f6343a4b/1

// Intuition: https://www.youtube.com/watch?v=QfbOhn0WZ88

// Approach: slow - fast pointer to get colliding point.
// Reset slow and move slow and fast one step at a time.
// Point they meet is the first node of loop
// TC: O(n)
// SC: O(1)

int findFirstNode(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    // Return -1 if loop doesn't exist
    if (slow != fast || slow == NULL || fast == NULL)
        return -1;

    // Reset slow and find first Node in loop
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast->data;
}