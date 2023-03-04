// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
// Approach: recursive call till last node.
// When you find last node. add 1 and return
// while return, check if node has 10, if yes move the carry
// TC: O(n)
// SC: O(1)
// Suboptimal solution - Reverse the LL, then try to add the number

Node *addOne(Node *head)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
    {
        head->data += 1;
        return head;
    }
    Node *temp = addOne(head->next);
    if (temp->data == 10)
    {
        head->data += 1;
        temp->data = 0;
    }
    return head;
}