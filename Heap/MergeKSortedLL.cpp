// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
// Approach: priority_queue<Node *, vector<Node *>, compare> pq. Store pq.top into new list

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
    // Function to merge K sorted linked list.
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