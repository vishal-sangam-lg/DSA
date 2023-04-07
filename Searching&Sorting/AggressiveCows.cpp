// https://practice.geeksforgeeks.org/problems/aggressive-cows/1
// Approach: 1 to max(stalls). Binary search for maximum distance the cows can be placed
// TC: O(nlogn)
// SC: O(1)

int getMax(vector<int> &arr)
{
    int ans = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }
    return ans;
}

bool isValid(int n, int cows, vector<int> &stalls, int distance)
{
    int curr = stalls[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (abs(stalls[i] - curr) >= distance)
        {
            count++;
            curr = stalls[i];
        }
    }
    return count >= cows;
}

int solve(int n, int cows, vector<int> &stalls)
{
    int start = 1;
    int end = getMax(stalls);
    sort(stalls.begin(), stalls.end());

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(n, cows, stalls, mid))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return end;
}

// https://www.spoj.com/problems/AGGRCOW/
#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int> &arr)
{
    int ans = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }
    return ans;
}

bool isValid(int n, int cows, vector<int> &stalls, int distance)
{
    int curr = stalls[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (abs(stalls[i] - curr) >= distance)
        {
            count++;
            curr = stalls[i];
        }
    }
    return count >= cows;
}

int solve(int n, int cows, vector<int> &stalls)
{
    int start = 1;
    int end = getMax(stalls);
    sort(stalls.begin(), stalls.end());

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(n, cows, stalls, mid))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return end;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        cout << solve(n, c, stalls) << endl;
    }
    return 0;
}