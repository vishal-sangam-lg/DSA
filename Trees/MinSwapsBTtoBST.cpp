// https://practice.geeksforgeeks.org/problems/minimum-swap-required-to-convert-binary-tree-to-binary-search-tree/0
// Approach:
// Get inorder traversal.
// Map inorder value->index.
// Sort inorder.
// compare sorted inorder and map value and swap
// TC: O(nlogn)
// SC: O(n)

// Dry run(1 based indexing):
// example inorder: 2 5 1 4 3
// sorted inorder: 1 2 3 4 5
// map:
// 2 -> 1
// 5 -> 2
// 1 -> 3
// 4 -> 4
// 3 -> 5
// While traversing sorted inorder, swap if sorted index not equal to its original index in map
// i = 1 -> 1 and 3 will be swapped -> 3 2 1 4 5
// i = 1 -> 3 and 5 will be swapped -> 5 2 1 4 3
// i = 1 -> 5 and 2 will be swapped -> 2 5 1 4 3
// From then onwards, i and map values match. So loop will end

void inorderTraversal(vector<int> &A, int i, int n, vector<int> &inorder)
{
    if (i >= n)
    {
        return;
    }
    // left child = 2*i + 1
    inorderTraversal(A, 2 * i + 1, n, inorder);
    // Push inorder node to inorder vector
    inorder.push_back(A[i]);
    // right child = 2*i + 2
    inorderTraversal(A, 2 * i + 2, n, inorder);
}
int countSwaps(vector<int> &inorder, int n)
{
    // mapping elements with their indexes
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }

    sort(inorder.begin(), inorder.end());

    int count = 0;
    for (int i = 0; i < n;)
    {
        if (mp[inorder[i]] != i)
        {
            swap(inorder[i], inorder[mp[inorder[i]]]);
            count++;
        }
        else
        {
            i++;
        }
    }
    return count;
}
int minSwaps(vector<int> &A, int n)
{
    vector<int> inorder;
    inorderTraversal(A, 0, n, inorder);
    return countSwaps(inorder, n);
}
