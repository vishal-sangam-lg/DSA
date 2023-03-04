// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1s
// Approach: slow fast (rabbit-tortoise) algo
// Check if loop is present
// Get the size of loop
// Reset fast and slow
// Move fast size-1 nodes ahead of slow
// Move both fast and slow
// When fast -> next == slow. It means fast is the last node
// Mark fast -> next = null
// TC: O(n)
// SC: O(1)

void removeLoop(Node *head)
{
    Node *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            break;
        }
    }
    // Return if loop is not present
    if (slow != fast || slow == NULL || fast == NULL)
        return;

    int sizeOfLoop = 1;
    fast = fast->next;

    // Calculating size of loop
    while (fast != slow)
    {
        fast = fast->next;
        sizeOfLoop++;
    }

    fast = head;
    slow = head;
    // move fast sizeOfLoop-1 ahead of slow
    for (int i = 0; i < sizeOfLoop - 1; i++)
        fast = fast->next;

    // when fast next points at slow. fast is at end of LL
    while (fast->next != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = NULL;
}

// Refer FirstNodeOfLoop.cpp, you can think of another approach.