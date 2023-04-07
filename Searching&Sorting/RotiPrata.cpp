// https://practice.geeksforgeeks.org/problems/minimum-time-to-fulfil-all-orders/1
// Approach: Binary search in range [0, 1e8].
// Check you can fulfill the order in mid time
// Update ans accordingly
// TC: O(nlogn)
// SC: O(1)

bool isPossible(int parathasReq, vector<int> &rankings, int cooks, int mid)
{
    int parathas = 0;
    for (int i = 0; i < cooks; i++)
    {
        int totalTimeTaken = 0;
        int timeToCook = rankings[i];
        while (totalTimeTaken + timeToCook <= mid)
        {
            parathas++;
            totalTimeTaken += timeToCook;
            timeToCook += rankings[i];
            if (parathas >= parathasReq)
            {
                return true;
            }
        }
    }
    return 0;
}

int findMinTime(int N, vector<int> &A, int L)
{
    int start = 1, end = 1e8, ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(N, A, L, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

// https://www.spoj.com/problems/PRATA/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int parathasReq, vector<int> &rankings, int cooks, int mid)
{
    int parathas = 0;
    for (int i = 0; i < cooks; i++)
    {
        int totalTimeTaken = 0;
        int timeToCook = rankings[i];
        while (totalTimeTaken + timeToCook <= mid)
        {
            parathas++;
            totalTimeTaken += timeToCook;
            timeToCook += rankings[i];
            if (parathas >= parathasReq)
            {
                return true;
            }
        }
    }
    return false;
}

int findMinTime(int parathasReq, int cooks, vector<int> &rankings)
{
    int start = 1, end = 1e8, ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(parathasReq, rankings, cooks, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int parathasReq, cooks;
        cin >> parathasReq;
        cin >> cooks;
        vector<int> rankings(cooks);
        for (int i = 0; i < cooks; i++)
        {
            cin >> rankings[i];
        }
        cout << findMinTime(parathasReq, cooks, rankings) << endl;
    }
    return 0;
}