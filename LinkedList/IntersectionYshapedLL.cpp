// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
// Intuition:
//       <----a---->
//  head1----------- <----x---->
//                  |-----------
//      head2-------
//           <--b-->
// First traverse a+x and b+x.
// Then switch the pointers.
// traverse b+x and a+x

// a+x+b+x = b+x+a+x

// TC: O(n)
// SC: O(1)

int intersectPoint(Node *head1, Node *head2)
{
    Node *p1 = head1, *p2 = head2;
    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;

        if (p1 == NULL && p2 == NULL)
            return -1;

        if (p1 == NULL)
            p1 = head2;

        if (p2 == NULL)
            p2 = head1;
    }
    return p1->data;
}