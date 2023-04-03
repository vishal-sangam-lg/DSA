// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1
// Approach: p pair<int, pair<int, int>> // <Element, <row_number,index> >
// priority_queue<p, vector<p>, greater<p>> pq;
// push first element of all rows to pq
// update mn, mx
// Then pop the top of pq. If its value is - mx < range
// Update mx, mn, range, low, high. Push its next element to pq

#define p pair<int, pair<int, int>> // <Element, <row_number,index> >
class Solution
{
public:
    pair<int, int> findSmallestRange(int arr[][N], int n, int k)
    {
        priority_queue<p, vector<p>, greater<p>> pq;

        int mn = INT_MAX, mx = INT_MIN, range = INT_MAX;
        int low = 0, high = 0;

        for (int i = 0; i < k; i++)
        {
            pq.push({arr[i][0], {i, 0}});
            mn = min(mn, arr[i][0]);
            mx = max(mx, arr[i][0]);
        }

        while (true)
        {
            p top = pq.top();
            pq.pop();

            int min1 = top.first;

            if (range > mx - min1)
            {
                mn = min1;
                low = mn;
                high = mx;
                range = mx - mn;
            }

            int i = top.second.first;  // row_number
            int j = top.second.second; // index

            if (j == n - 1)
                break;

            pq.push({arr[i][j + 1], {i, j + 1}});

            if (mx < arr[i][j + 1])
            {
                mx = arr[i][j + 1];
            }
        }

        return {low, high};
    }
};