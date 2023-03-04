// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
// Approach: Reverse given nos. while first != NULL or second != NULL or carry. add to sum.
// create new node and append to ans
// TC: O(n+m)
// SC: O(max(n,m)) for result

struct Node *reverse(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}
struct Node *add(struct Node *first, struct Node *second)
{
    first = reverse(first);
    second = reverse(second);

    int carry = 0;
    struct Node *sum = new struct Node(0);
    struct Node *ptr = sum;

    while (first != NULL || second != NULL || carry != 0)
    {
        int sum = 0;
        // Adding digit from first linked list
        if (first != NULL)
        {
            sum += first->data;
            first = first->next;
        }

        // Adding digit from second linked list
        if (second != NULL)
        {
            sum += second->data;
            second = second->next;
        }

        // Adding carry to sum and updating new carry
        sum += carry;
        carry = sum / 10;

        // Creating a new node and inserting it to sum LL
        struct Node *temp = new struct Node(sum % 10);
        ptr->next = temp;
        ptr = ptr->next;
    }

    // Reverse the LL after dummy 0 value and return
    return reverse(sum->next);
}
// Function to add two numbers represented by linked list.
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    return add(first, second);
}
