// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// Striver - https://www.youtube.com/watch?v=nv7F4PiLUzo
// Approach I - Using upper_bound and binary search
// count number of elements <= k in both arrays
// If that count is < k, it may or may not be an answer
// return low

int kthElement(int a[], int b[], int n, int m, int k)
{
    int l = min(a[0], b[0]);
    int h = max(a[n - 1], b[m - 1]);
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        // Count number of elements <= k in a and b
        int x = upper_bound(a, a + n, mid) - a;
        int y = upper_bound(b, b + m, mid) - b;
        // x+y < k -> Maybe or may not be the answer
        if (x + y < k)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return l;
}

// Approach II - Binary search
// Partition low high cut1 cut2 l1 l2 r1 r2 -> valid partition -> ans = max(l1, l2)
int kthElement(int a[], int b[], int n, int m, int k)
{
    if (n > m)
    {
        return kthElement(b, a, m, n, k);
    }

    int low = max(0, k - m); // Important! -> You have to take minimum k-m numbers from arr1
    int high = min(k, n);    // Important! -> You have to take maximum k to get kth element from arr1
    while (low <= high)
    {
        // Partition
        int cut1 = low + (high - low) / 2;
        int cut2 = k - cut1;
        int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : a[cut1];
        int r2 = cut2 == m ? INT_MAX : b[cut2];

        // Valid partition
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }

        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return -1;
}