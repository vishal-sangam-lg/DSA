// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
// Approach: Store in minHeap. Get smallest two, add and push to minHeap

long long minCost(long long arr[], long long n)
{
    // You have to add 2 smallest sizes at every step
    priority_queue<long long, vector<long long>, greater<long long>> minHeap(arr, arr + n);
    long long cost = 0;

    if (minHeap.size() == 1)
    {
        return 0;
    }

    while (minHeap.size() > 1)
    {
        long long first = minHeap.top();
        minHeap.pop();

        long long second = minHeap.top();
        minHeap.pop();

        long long mergedLength = first + second;

        cost += mergedLength;
        minHeap.push(mergedLength);
    }
    return cost;
}