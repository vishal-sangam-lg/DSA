// https://leetcode.com/problems/furthest-building-you-can-reach/
// Approach: Use minHeap to store smallest building heights
// Use ladders to other buildings, when pq.size() > ladders. use bricks

int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i < heights.size(); i++)
    {
        int currDiff = heights[i] - heights[i - 1];
        // current building is lower than or equal to previous one
        if (currDiff <= 0)
        {
            continue;
        }

        pq.push(currDiff);
        if (pq.size() > ladders)
        {
            bricks -= pq.top();
            pq.pop();
        }
        if (bricks < 0)
        {
            return i - 1;
        }
    }
    return heights.size() - 1;
}