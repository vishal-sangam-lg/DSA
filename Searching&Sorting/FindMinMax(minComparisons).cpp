
// Naive Approach
int findSum(int A[], int N)
{
    int minNum = 0;
    int maxNum = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > maxNum)
        {
            maxNum = A[i];
        }
        if (A[i] < minNum)
        {
            minNum = A[i];
        }
    }
    return maxNum + minNum;
}

// Approach with minimum number of comparisons
// In every iteration of loop, we process two elements in array with 3 comparisons at most
// In naive approach, we do two comparisons for every element
// Hence, saving 1 comparison for every 2 element

int findSum(int A[], int N)
{
    int mini, maxi, i;
    // Initialize mini and maxi to first element if its odd sized array
    if (N & 1)
    {
        mini = A[0];
        maxi = A[0];
        i = 1;
    }
    else
    {
        // If its even, initialise with first two elements
        if (A[0] < A[1])
        {
            mini = A[0];
            maxi = A[1];
        }
        else
        {
            mini = A[1];
            maxi = A[0];
        }
        i = 2;
    }

    if (N <= 2)
        return mini + maxi;

    while (i < N - 1)
    {
        if (A[i] < A[i + 1])
        {
            if (A[i] < mini)
            {
                mini = A[i];
            }
            if (A[i + 1] > maxi)
            {
                maxi = A[i + 1];
            }
        }
        else
        {
            if (A[i] > maxi)
            {
                maxi = A[i];
            }
            if (A[i + 1] < mini)
            {
                mini = A[i + 1];
            }
        }
        i += 2;
    }
    return mini + maxi;
}