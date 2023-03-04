// https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1
// Approach: Construct num1, num2 from l1, l2. multiply num1*num2 % m
// TC: O(n)
// SC: O(1)

long long multiplyTwoLists(Node *l1, Node *l2)
{
    long long m = 1000000007;
    long long num1 = 0;
    long long num2 = 0;
    while (l1 != NULL)
    {
        num1 = (num1 * 10 + l1->data) % m;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        num2 = (num2 * 10 + l2->data) % m;
        l2 = l2->next;
    }
    return (num1 * num2) % m;
}