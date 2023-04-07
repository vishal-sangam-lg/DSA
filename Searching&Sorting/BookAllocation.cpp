// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// Approach: Binary search in range [max_element(arr), accumulate(arr)]
// Choose mid and check if it is a valid allocation, update ans
// TC: O(log(sumOfArr - maxOfArr))
// SC: O(1)

int findPages(int A[], int N, int M)
{
    if (M > N)
        return -1;
    int s = *max_element(A, A + N);
    int e = accumulate(A, A + N, 0);
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        int sum = 0;
        int count = 1;
        int i = 0;
        for (int i = 0; i < N; i++)
        {
            sum += A[i];
            if (sum > mid)
            {
                count++;
                sum = A[i];
            }
        }
        if (count > M)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return s;
}