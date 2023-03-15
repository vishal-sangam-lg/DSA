// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1
// Approach: Store inorder traversal of both bst in vector.
// Two pointers - get sum, count++

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int countPairs(Node *root1, Node *root2, int x)
{
    // Store inorder of both bst in vector
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2);

    // now find sum using 2 pointer Approach - count++
    int i = 0;
    int j = v2.size() - 1;
    int count = 0;
    while (i < v1.size() && j >= 0)
    {
        int sum = v1[i] + v2[j];
        if (sum == x)
            count++, i++, j--;
        else if (sum < x)
            i++;
        else
            j--;
    }
    return count;
}