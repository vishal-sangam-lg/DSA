// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
// Approach: Reverse the LL and compare with original LL
// TC: O(n)
// SC: O(n)

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *rev = reverse(slow->next);
    while (rev != NULL)
    {
        if (rev->data != head->data)
        {
            return false;
        }
        rev = rev->next;
        head = head->next;
    }
    return true;
}

// Optimal Solution
// TC: O(n)
// SC: O(1)
// Approach: Construct the number from left and right in one iteration
bool isPalindrome(Node *head)
{
    if (head == NULL)
        return false;
    int rsum = 0, lsum = 0, i = 1;
    Node *it = head;

    while (it != NULL)
    {
        rsum = it->data + (rsum * 10);
        lsum = lsum + (it->data * i);
        i *= 10;
        it = it->next;
    }
    if (rsum == lsum)
        return true;
    else
        return false;
}