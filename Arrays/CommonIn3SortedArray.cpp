// https://practice.geeksforgeeks.org/problems/common-elements1132/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach I - Maps
// TC: O(n1+n2+n3)
// SC: O(n)

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> ans;
    unordered_map<int, int> map;
    for (int i = 0; i < n1; i++)
    {
        if (A[i] == A[i - 1])
            continue;
        map[A[i]]++;
    }
    for (int i = 0; i < n2; i++)
    {
        if (B[i] == B[i - 1])
            continue;
        map[B[i]]++;
    }
    for (int i = 0; i < n3; i++)
    {
        if (C[i] == C[i - 1])
            continue;
        map[C[i]]++;
    }
    for (auto it : map)
    {
        if (it.second >= 3)
        {
            ans.push_back(it.first);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// Approach II - Iteration
// TC: O(n1+n2+n3)
// SC: O(1)

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    vector<int> res;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            // Duplicate commonElements need not be considered
            if (res.size() > 0 && res.back() == A[i])
            {
                i++;
                j++;
                k++;
            }
            else
            {
                res.push_back(A[i]);
                i++;
                j++;
                k++;
            }
        }
        else if (A[i] < B[j] || A[i] < C[k])
            i++;
        else if (B[j] < A[i] || B[j] < C[k])
            j++;
        else if (C[k] < A[i] || C[k] < B[j])
            k++;
    }
    if (res.size() > 0)
    {
        return res;
    }
    else
    {
        return {-1};
    }
}
