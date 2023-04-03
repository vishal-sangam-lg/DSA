// https://practice.geeksforgeeks.org/problems/heap-sort/1
// Approach: Build heap from (n/2-1) to 0 coz greater than (n/2) is leaf nodes
// Traverse RTL. swap(0, i). heapify(0th element)

void heapify(int arr[], int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // It might go further down, so call heapify again
        heapify(arr, n, largest);
    }
}

public:
// Function to build a Heap from array.
void buildHeap(int arr[], int n)
{
    // all nodes greater than (n/2) are leaf nodes
    // They always follow heap property, no need to process
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

public:
// Function to sort an array using Heap Sort.
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]); // Place largest element in correct position
        heapify(arr, i, 0);   // heapify first element that was swapped
    }
}
void heapify(int arr[], int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // It might go further down, so call heapify again
        heapify(arr, n, largest);
    }
}

public:
// Function to build a Heap from array.
void buildHeap(int arr[], int n)
{
    // all nodes greater than (n/2) are leaf nodes
    // They always follow heap property, no need to process
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

public:
// Function to sort an array using Heap Sort.
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]); // Place largest element in correct position
        heapify(arr, i, 0);   // heapify first element that was swapped
    }
}