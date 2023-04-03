// https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1
// Approach: Traverse inorder and store sorted arr. Traverse postorder and copy back

void inorder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void postorder(Node *root, vector<int> &arr, int &i)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left, arr, i);
    postorder(root->right, arr, i);
    root->data = arr[i++];
}

void convertToMaxHeapUtil(Node *root)
{
    vector<int> arr;
    inorder(root, arr);
    int i = 0;
    postorder(root, arr, i);
}