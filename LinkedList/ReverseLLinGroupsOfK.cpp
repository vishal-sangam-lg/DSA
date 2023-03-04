// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
// Approach: Reverse till k nodes iteratively. If next != null then head->next = reverse(next, k)
// TC: O(n)
// SC: O(1)

struct node *reverse(struct node *head, int k)
{
    int count = 0;
    struct node *prev = NULL, *curr = head, *next;
    while (curr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next)
        head->next = reverse(next, k);

    return prev;
}