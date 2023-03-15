// https://practice.geeksforgeeks.org/problems/construct-tree-1/1
// Love Babbar - https://www.youtube.com/watch?v=ffE1xj51EBQ
// Approach:
// Traverse inorder and map value to index
// Traverse preorder from RTL
// first element of preorder is root
// Find index of that element in map
// Call left child for inStart,position-1 and right child for position+1,inEnd

// Solution I - Values of nodes are distinct

void createMappingOfInorderIndex(unordered_map<int, int> &nodeToIndex, int in[], int n)
{
    if (n == 0)
        return;
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node *solve(int in[], int pre[], int &preIdx, int inStart, int inEnd, int n, unordered_map<int, int> &nodeToIndex)
{
    if (preIdx >= n || inStart > inEnd)
    {
        return NULL;
    }

    int element = pre[preIdx++];
    Node *root = new Node(element);
    // Find the position of curr in inorder
    int position = nodeToIndex[element];

    // Recursive call to left and right of position in inorder
    root->left = solve(in, pre, preIdx, inStart, position - 1, n, nodeToIndex);
    root->right = solve(in, pre, preIdx, position + 1, inEnd, n, nodeToIndex);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    unordered_map<int, int> nodeToIndex;
    int preIdx = 0;
    createMappingOfInorderIndex(nodeToIndex, in, n);
    return solve(in, pre, preIdx, 0, n - 1, n, nodeToIndex);
}

// Solution II - If values of nodes are not distinct. Don't use maps. Use linear/binary search

int position(vector<int> in, int element, int inStart, int inEnd)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node *solve(vector<int> in, vector<int> pre, int &preIdx, int inStart, int inEnd)
{
    if (preIdx == pre.size() || inStart > inEnd)
    {
        return NULL;
    }
    int element = pre[preIdx++];
    Node *root = new Node(element);

    int pos = position(in, element, inStart, inEnd);

    root->left = solve(in, pre, preIdx, inStart, pos - 1);
    root->right = solve(in, pre, preIdx, pos + 1, inEnd);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    int preIdx = 0;
    vector<int> inorder(in, in + n);
    vector<int> preorder(pre, pre + n);
    Node *ans = solve(inorder, preorder, preIdx, 0, n);
    return ans;
}