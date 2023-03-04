// https://leetcode.com/problems/partition-list/
// Approach: Create lessThanX and greaterThanX list by traversing the given list. Join them
// TC: O(n)
// SC: O(n)

ListNode *partition(ListNode *head, int x)
{
    ListNode *lessThanX = new ListNode(0);
    ListNode *greaterThanX = new ListNode(0);

    ListNode *p1 = lessThanX, *p2 = greaterThanX;

    while (head)
    {
        if (head->val < x)
        {
            p1->next = head;
            p1 = p1->next;
        }
        else
        {
            p2->next = head;
            p2 = p2->next;
        }
        head = head->next;
    }

    p2->next = NULL;
    p1->next = greaterThanX->next;

    return lessThanX->next;
}

// GFG variant - https://practice.geeksforgeeks.org/problems/partition-a-linked-list-around-a-given-value/1

struct Node *partition(struct Node *head, int x)
{
    struct Node *lessThanX = new Node(0);
    struct Node *equalToX = new Node(0);
    struct Node *greaterThanX = new Node(0);

    struct Node *p1 = lessThanX, *p2 = equalToX, *p3 = greaterThanX;

    while (head)
    {
        if (head->data < x)
        {
            p1->next = head;
            p1 = p1->next;
        }
        else if (head->data == x)
        {
            p2->next = head;
            p2 = p2->next;
        }
        else
        {
            p3->next = head;
            p3 = p3->next;
        }
        head = head->next;
    }

    p3->next = NULL;
    p2->next = greaterThanX->next;
    p1->next = equalToX->next;

    return lessThanX->next;
}