// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// Approach: Merge every column to first column, one by one. return first column
// TC: O(n * m)
// SC: O(n)

Node *merge(Node *root1, Node *root2)
{
    if (root2 == NULL)
        return root1;
    if (root1 == NULL)
        return root2;

    Node *mergedRoot = new Node(0);
    Node *ptr = mergedRoot;

    while (root1 != NULL && root2 != NULL)
    {
        if (root1->data <= root2->data)
        {
            ptr->bottom = root1;
            root1 = root1->bottom;
        }
        else
        {
            ptr->bottom = root2;
            root2 = root2->bottom;
        }
        ptr = ptr->bottom;
    }
    if (root1 != NULL)
        ptr->bottom = root1;
    if (root2 != NULL)
        ptr->bottom = root2;

    return mergedRoot->bottom;
}

Node *flatten(Node *root)
{
    Node *r1 = root;
    Node *r2 = root->next;
    while (r2 != NULL)
    {
        r1 = merge(r1, r2);
        r2 = r2->next;
    }
    return r1;
}