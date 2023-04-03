// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1
// Approach: Store smallerHalf in maxHeap and greaterHalf in minHeap
// BalanceHeaps() after every insertion. Return median according to size of heaps

priority_queue<double> smallerHalf;                                  // maxHeap
priority_queue<double, vector<double>, greater<double>> greaterHalf; // minHeap
// Function to insert heap.
void insertHeap(int &x)
{
    if (smallerHalf.size() == 0 || smallerHalf.top() > x)
    {
        smallerHalf.push(x);
    }
    else
    {
        greaterHalf.push(x);
    }
    balanceHeaps();
}

// Function to balance heaps.
void balanceHeaps()
{
    if (smallerHalf.size() > greaterHalf.size() + 1)
    {
        greaterHalf.push(smallerHalf.top());
        smallerHalf.pop();
    }
    else if (greaterHalf.size() > smallerHalf.size())
    {
        smallerHalf.push(greaterHalf.top());
        greaterHalf.pop();
    }
}

// Function to return Median.
double getMedian()
{
    double median;
    if (smallerHalf.size() == greaterHalf.size())
    {
        median = (smallerHalf.top() + greaterHalf.top()) / 2.0;
    }
    else
    {
        median = smallerHalf.top();
    }
    return median;
}