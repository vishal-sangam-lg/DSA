// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
// Approach:
// Iterative: prev, head, next
// Recursive: head recursion. head -> next -> next = head. head -> next = null
// TC: O(n)
// SC: O(1)

// Recursive example
// 1 -> 2 -> 3 -> 4
// recursive stack
// head = 4
// head = 3
// head = 2
// head = 1
// At every step. We need to make head's next point to curr head

struct Node *reverse(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverse(head->next);
    head->next->next = head; // important
    head->next = NULL;

    return newHead;
}
// Function to reverse a linked list.
struct Node *reverseList(struct Node *head)
{
    // // Iterative solution
    // if(head == NULL || head -> next == NULL) return head;

    // struct Node* prev = NULL;
    // struct Node* curr = head;
    // struct Node* next = head->next;

    // while(curr != NULL) {
    //     next = curr -> next;
    //     curr -> next = prev;
    //     prev = curr;
    //     curr = next;
    // }

    // return prev;
    return reverse(head);
}