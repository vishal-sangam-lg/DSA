// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
// Approach:
// Traverse inorder and map value to index
// Traverse postorder from RTL
// last element of postorder is root
// Find index of that element in map
// Call left child for inStart,position-1 and right child for position+1,inEnd

// IMPORTANT NOTE: If values of nodes are not distinct. Map will not work. Use binary search instead

void createMappingOfInorderIndex(unordered_map<int, int> &nodeToIndex, int *in, int n)
{
    if (n == 0)
        return;
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node *solve(int in[], int post[], int &postIdx, int inStart, int inEnd, unordered_map<int, int> &nodeToIndex)
{
    if (postIdx < 0 || inStart > inEnd)
    {
        return NULL;
    }

    int element = post[postIdx--];
    Node *root = new Node(element);

    // Find the position of curr in inorder
    int position = nodeToIndex[element];

    // Recursive call to left and right of position in inorder
    root->right = solve(in, post, postIdx, position + 1, inEnd, nodeToIndex);
    root->left = solve(in, post, postIdx, inStart, position - 1, nodeToIndex);

    return root;
}
// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{
    unordered_map<int, int> nodeToIndex;
    int postIdx = n - 1;
    createMappingOfInorderIndex(nodeToIndex, in, n);
    return solve(in, post, postIdx, 0, n - 1, nodeToIndex);
}