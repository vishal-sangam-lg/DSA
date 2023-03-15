// https://practice.geeksforgeeks.org/problems/largest-bst/1

// Approach:
// Info class with lowerbound, upperbound, size, isBST
// Postorder traversal, instead of printing update all data members of Info and return
// Update global ans if required

// Intuition: We are trying to get max size of BST from bottom to top
// Because, if child subtree is not BST, top can't be BST

int ans = 0;
class Info
{
public:
    int lowerBound;
    int upperBound;
    int size;
    bool isBST;

    Info()
    {
        lowerBound = INT_MAX;
        upperBound = INT_MIN;
        size = 0;
        isBST = true;
    }

    Info(int a, int b, int c, bool d)
    {
        lowerBound = a;
        upperBound = b;
        size = c;
        isBST = d;
    }
};

class Solution
{
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Info solve(Node *root)
    {
        if (root == NULL)
        {
            return Info();
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        Info curr;
        curr.lowerBound = min(root->data, left.lowerBound);
        curr.upperBound = max(root->data, right.upperBound);
        curr.size = left.size + right.size + 1;

        if (left.isBST && right.isBST &&
            root->data > left.upperBound &&
            root->data < right.lowerBound)
        {
            curr.isBST = true;
            ans = max(ans, curr.size);
        }
        else
        {
            curr.isBST = false;
        }
        return curr;
    }

    int largestBst(Node *root)
    {
        ans = 0;
        Info temp = solve(root);
        return ans;
    }
};