// https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1
// Approach: Return false if nodes are not equal. Recursive call for traverse in same direction || in opposite direction

bool isIsomorphic(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }

    return (isIsomorphic(root1->left, root2->left) &&
            isIsomorphic(root1->right, root2->right)) ||
           (isIsomorphic(root1->left, root2->right) &&
            isIsomorphic(root1->right, root2->left));
}