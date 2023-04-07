// https://www.spoj.com/problems/ANARC05B/
// Approach: Traverse till a intersection, maintain sum1, sum2
// At intersection. ans = ans + max(sum1, sum2) + a[i]. Move forward
// TC: O(n)
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int b[], int n, int m)
{
    int seq1 = 0, seq2 = 0, i = 0, j = 0, ans = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            seq1 += a[i++];
        }
        else if (b[j] < a[i])
        {
            seq2 += b[j++];
        }
        else
        {
            ans = ans + max(seq1, seq2) + a[i];
            seq1 = seq2 = 0;
            i++;
            j++;
        }
    }
    while (i < n)
    {
        seq1 += a[i++];
    }
    while (j < m)
    {
        seq2 += b[j++];
    }
    ans = ans + max(seq1, seq2);
    return ans;
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        else
        {
            int a[n];
            for (int i = 0; i < n; i++)
                cin >> a[i];
            int m;
            cin >> m;
            int b[m];
            for (int i = 0; i < m; i++)
                cin >> b[i];

            cout << solve(a, b, n, m) << endl;
        }
    }
    return 0;
}