// https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1
// Approach: Two pointer. Append to ans LL if you find it equal or else, move pointers
// TC: O(n+m)
// SC: O(1) result not included

Node *findIntersection(Node *head1, Node *head2)
{
    Node *p1 = head1;
    Node *p2 = head2;
    Node *ans = new Node(0);
    Node *ptr = ans;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data == p2->data)
        {
            ptr->next = new Node(p1->data);
            ptr = ptr->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->data < p2->data)
        {
            p1 = p1->next;
        }
        else
        {
            p2 = p2->next;
        }
    }

    // Return the ans after dummy 0 node
    return ans->next;
}