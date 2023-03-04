// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
// Approach I - Merging lists one by one using merge()

// Iterative
class Solution
{
public:
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
                ptr->next = root1;
                root1 = root1->next;
            }
            else
            {
                ptr->next = root2;
                root2 = root2->next;
            }
            ptr = ptr->next;
        }
        if (root1 != NULL)
            ptr->next = root1;
        if (root2 != NULL)
            ptr->next = root2;

        return mergedRoot->next;
    }
    Node *mergeKLists(Node *arr[], int K)
    {
        Node *head = arr[0];
        for (int i = 1; i < K; i++)
        {
            Node *currHead = arr[i];
            head = merge(head, currHead);
        }
        return head;
    }
};

// Recursive
class Solution
{
public:
    Node *merge(Node *first, Node *second)
    {
        if (first == NULL)
        {
            return second;
        }
        else if (second == NULL)
        {
            return first;
        }

        if (first->data < second->data)
        {
            first->next = merge(first->next, second);
            return first;
        }
        else
        {
            second->next = merge(first, second->next);
            return second;
        }
    }

    Node *mergeKLists(Node *arr[], int K)
    {
        Node *ans = NULL;
        for (int i = 0; i < K; i++)
        {
            ans = merge(ans, arr[i]);
        }
        return ans;
    }
};

// Approach - II : MinHeap of size k
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    Node *mergeKLists(Node *arr[], int K)
    {
        priority_queue<Node *, vector<Node *>, compare> pq;

        Node *ans = new Node(-1);
        Node *tail = ans;

        for (int i = 0; i < K; i++)
        {
            pq.push(arr[i]);
        }

        while (pq.size() > 0)
        {
            Node *top = pq.top();
            pq.pop();
            tail->next = top;
            tail = top;
            if (top->next != NULL)
            {
                pq.push(top->next);
            }
        }
        return ans->next;
    }
};