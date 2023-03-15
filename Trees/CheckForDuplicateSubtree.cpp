// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
// Approach: Get preorder traversal of left and right subtree
// Traverse them from RTL. If equal ans++ else break. Return ans
// Dry run:
//                1
//            2       3
//         4     5        2
//                      4   5
// Here 2, 4, 5 is duplicate subtree
// Left Subtree preorder  -> 2 4 5
// Right Subtree preorder -> 3 2 4 5

void preorder(Node *root, vector<int> &vec)
{
    if (root == NULL)
    {
        return;
    }
    vec.push_back(root->data);
    preorder(root->left, vec);
    preorder(root->right, vec);
}
/*This function returns true if the tree contains
a duplicate subtree of size 2 or more else returns false*/
int dupSub(Node *root)
{
    vector<int> left, right;
    preorder(root->left, left);
    preorder(root->right, right);

    int i = left.size() - 1;
    int j = right.size() - 1;
    int ans = 0;
    while (i >= 0 && j >= 0)
    {
        if (left[i] != right[j])
        {
            break;
        }
        i--;
        j--;
        ans++;
    }
    return ans > 1 ? 1 : 0;
}