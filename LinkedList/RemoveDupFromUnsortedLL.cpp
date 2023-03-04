// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
// Approach: Use set to check if node exist. If it exist, change links
// TC: O(n)
// SC: O(n)

Node *removeDuplicates(Node *head)
{
    unordered_set<int> s;
    Node *ptr = head;
    Node *prev = NULL;
    while (ptr != NULL)
    {
        if (s.find(ptr->data) == s.end())
        {
            s.insert(ptr->data);
            prev = ptr;
        }
        else
        {
            prev->next = ptr->next;
            delete (ptr);
        }
        ptr = prev->next;
    }
    return head;
}