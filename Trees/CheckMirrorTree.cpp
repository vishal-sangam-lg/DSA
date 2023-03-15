// https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1
// Approach: Store All edges from tree A in map<int, stack>
// Ex: 1->2 1->3 is stored as 1 -> 2 3 in stack
// Compare with edges of tree B. It should be equal in reverse order of stack

int checkMirrorTree(int n, int e, int A[], int B[])
{
    unordered_map<int, stack<int>> mp;
    // Storing all edges of A in map of stack so that
    // it can be compared with edges of B in reverse and pop
    for (int i = 0; i < 2 * e; i += 2)
    {
        mp[A[i]].push(A[i + 1]);
    }
    for (int i = 0; i < 2 * e; i += 2)
    {
        if (mp[B[i]].top() == B[i + 1])
        {
            mp[B[i]].pop();
        }
        else
        {
            return 0;
        }
    }
    return 1;
}