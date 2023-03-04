// https://leetcode.com/problems/add-two-numbers-ii/
// Approach:
// Step1: Add leading zeros to smaller list
// Step2: Recursive call to 2 digits of l1,l2 till the end
// Step3: When recursion returns, calculate sum, carry and update node

ListNode *addTwoDigits(ListNode *l1, ListNode *l2, int &carry)
{
    if (l1 == NULL && l2 == NULL)
        return NULL;

    ListNode *newNode = new ListNode(-1);
    newNode->next = addTwoDigits(l1->next, l2->next, carry);

    newNode->val = (l1->val + l2->val + carry) % 10;
    carry = (l1->val + l2->val + carry) / 10;

    return newNode;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ptr1 = l1, *ptr2 = l2;
    // Adding zeros to the start of the smaller list:
    while (ptr1 || ptr2)
    {
        // Adding zeros when l1 is smaller than l2
        if (ptr1 == NULL)
        {
            ListNode *newNode = new ListNode(0);
            newNode->next = l1;
            l1 = newNode;
            ptr2 = ptr2->next;
        }
        // Adding zeros when l2 is smaller than l1
        else if (ptr2 == NULL)
        {
            ListNode *newNode = new ListNode(0);
            newNode->next = l2;
            l2 = newNode;
            ptr1 = ptr1->next;
        }
        // Just move the pointers until one of the LL hits null
        else
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    // Addition
    int carry = 0;
    ListNode *ans = new ListNode(-1);
    ans->next = addTwoDigits(l1, l2, carry);
    // Adding carry to first digit if its still remaining
    if (carry != 0)
    {
        ListNode *newNode = new ListNode(carry);
        newNode->next = ans->next;
        ans->next = newNode;
    }

    return ans->next;
}