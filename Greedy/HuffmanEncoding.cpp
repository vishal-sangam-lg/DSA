// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1
// Approach: Add all nodes to minheap with cmp.
// Take Smallest 2 nodes, thats left and right child. construct parent. add parent back to pq
// Construct tree. preorder traversal. left+"0" right+"1"

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class cmp
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
    void preorder(Node *root, string temp, vector<string> &ans)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(temp);
            return;
        }

        preorder(root->left, temp + "0", ans);
        preorder(root->right, temp + "1", ans);
    }
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        priority_queue<Node *, vector<Node *>, cmp> pq;
        for (int i = 0; i < N; i++)
        {
            Node *temp = new Node(f[i]);
            pq.push(temp);
        }

        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();

            Node *right = pq.top();
            pq.pop();

            Node *newNode = new Node(left->data + right->data);
            newNode->left = left;
            newNode->right = right;
            pq.push(newNode);
        }

        Node *root = pq.top();
        vector<string> ans;
        preorder(root, "", ans);
        return ans;
    }
};