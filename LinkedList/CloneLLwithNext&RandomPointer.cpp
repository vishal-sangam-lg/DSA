// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
// Approach:
// 1st itr -> store original and corresponding new node in map. Create a clone with next connected
// 2nd itr -> Connect arb pointers using maps
// TC: O(n)
// SC: O(n)
// Optimal solution: TC: O(n) SC: O(1)

Node *copyList(Node *head)
{
    Node *cloneHead = NULL, *cloneTail = NULL, *ptr = head;
    unordered_map<Node *, Node *> mp;
    while (ptr)
    {
        Node *newNode = new Node(ptr->data);
        mp.insert({ptr, newNode});
        if (cloneHead == NULL)
        {
            cloneHead = newNode;
            cloneTail = newNode;
        }
        else
        {
            cloneTail->next = newNode;
            cloneTail = newNode;
        }
        ptr = ptr->next;
    }
    ptr = head;
    Node *clonePtr = cloneHead;
    while (ptr && clonePtr)
    {
        clonePtr->arb = mp[ptr->arb];
        ptr = ptr->next;
        clonePtr = clonePtr->next;
    }
    return cloneHead;
}