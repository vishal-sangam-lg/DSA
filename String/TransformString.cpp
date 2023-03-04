// https://practice.geeksforgeeks.org/problems/transform-string5648/1
// https://practice.geeksforgeeks.org/problems/b6b3297ccfb1ad5f66a9c2b92979170417adf114/1
// Same code works for both
// Approach: Using 2maps, check if corresponding character are in same frequency in both string
// Traverse RTL, if strings don't match. Increment count
// TC: O(n)
// SC: O(n)

int transform(string A, string B)
{
    if (A.size() != B.size())
        return -1;

    // Checking if all corresponding character are in same frequency
    unordered_map<char, int> m1, m2;
    for (auto i : A)
        m1[i]++;
    for (auto i : B)
        m2[i]++;
    for (auto i : m1)
        if (i.second != m2[i.first])
            return -1;

    // Traverse from back, if characters don't match, increment count
    // Since, you have to insert it to front
    int count = 0;
    for (int i = A.size() - 1, j = A.size() - 1; i >= 0; i--)
    {
        if (A[i] == B[j])
            j--;
        else
            count++;
    }
    return count;
}