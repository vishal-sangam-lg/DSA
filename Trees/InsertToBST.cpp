// https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1
// Approach: if root==NULL return newNode. If its equal to k, return root.
// if root > key call(left), else call(right). return root
// TC: O(n)
// SC: O(height of tree)

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        Node *newNode = new Node(key);
        return newNode;
    }
    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}