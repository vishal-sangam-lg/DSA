// Approach:
// Get difference, minimumJumpsRequired = difference/k
// If minimumJumpsRequired = 0, we jump by 1
// That happens when difference < k
// Else jump minimumJumpsRequired
// TC: O(n)
// SC: O(1)

int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == x)
        {
            return i;
        }
        else
        {
            int difference = abs(arr[i] - x);
            int minimumJumpsRequired = difference / k;
            // If minimumJumpsRequired = 0, we jump by 1
            // That happens when difference < k
            // Else jump minimumJumpsRequired
            i += max(1, minimumJumpsRequired);
        }
    }
    return -1;
}