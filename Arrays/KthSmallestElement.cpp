// https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array/
// Approach: Store k numbers in max heap, swap the top if it is greater
// Top of max heap is kth smallest number
// since max heap is descending and top is max
// TC: O(K log K +  (N – K) log K)
// SC: O(K)

#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i <= r; i++)
    {
        // If current element is < top that means
        // there are  other k-1 lesser elements
        // are present at bottom thus, pop that element
        // and add kth largest element into the heap till
        // curr at last all the greater element than kth
        // element will get pop off and at the top of heap
        // there will be kth smallest element
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main()
{
    int arr[] = {1, 4, 2, 3, 5};
    cout << kthSmallest(arr, 0, 4, 2) << endl;
}