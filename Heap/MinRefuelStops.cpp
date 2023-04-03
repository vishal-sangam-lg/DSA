// https://leetcode.com/problems/minimum-number-of-refueling-stops
// Approach: take currPos to be startFuel. add possible refuel till currPos
// Refuel using maxHeap. currPos += pq.top(). move forward

int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
    priority_queue<int> pq;
    int n = stations.size();
    int currPos = startFuel;
    int i = 0, refuel = 0;
    while (currPos < target)
    {
        while (i < n && currPos >= stations[i][0])
        {
            pq.push(stations[i][1]);
            i++;
        }
        if (pq.empty())
        {
            return -1;
        }
        currPos += pq.top();
        refuel++;
        pq.pop();
    }
    return refuel;
}