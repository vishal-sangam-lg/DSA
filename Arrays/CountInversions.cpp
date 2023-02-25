// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// Approach: Merge sort and increase the count if you find a smaller element in right subarray
// of merge function with size of leftsubarray till leftIdx
// TC: O(nlogn)
// SC: O(n)

void Merge(long long *arr, long long start, long long mid, long long end, long long &count)
{
    long long leftSubArray[mid - start + 1];
    long long rightSubArray[end - mid];
    for (long long i = 0; i < mid - start + 1; i++)
    {
        leftSubArray[i] = arr[start + i];
    }
    for (long long i = 0; i < end - mid; i++)
    {
        rightSubArray[i] = arr[mid + i + 1];
    }
    long long leftIdx = 0;
    long long rightIdx = 0;
    long long sortedIdx = start;
    while (leftIdx < mid - start + 1 && rightIdx < end - mid)
    {
        if (leftSubArray[leftIdx] <= rightSubArray[rightIdx])
        {
            arr[sortedIdx++] = leftSubArray[leftIdx++];
        }
        else
        {
            // Important
            count += (mid - start + 1) - leftIdx;
            arr[sortedIdx++] = rightSubArray[rightIdx++];
        }
    }
    while (leftIdx < mid - start + 1)
    {
        arr[sortedIdx++] = leftSubArray[leftIdx++];
    }
    while (rightIdx < end - mid)
    {
        arr[sortedIdx++] = rightSubArray[rightIdx++];
    }
}
void MergeSort(long long *arr, long long start, long long end, long long &count)
{
    if (start < end)
    {
        long long mid = start + (end - start) / 2;
        MergeSort(arr, start, mid, count);
        MergeSort(arr, mid + 1, end, count);
        Merge(arr, start, mid, end, count);
    }
    return;
}
long long int inversionCount(long long arr[], long long N)
{
    long long count = 0;
    MergeSort(arr, 0, N - 1, count);
    return count;
}