// https://practice.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1
// Approach: maxHeapify(i = (n-2)/2 to 0). Swap children if parent is less

void maxHeapify(vector<int> &arr, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void convertMinToMaxHeap(vector<int> &arr, int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}