// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1
// Approach: sort + two-pointer
// Special case:
// size = 5, difference =  0
// arr = 1 2 2 6 5
// Solution -> start i = 0, j = 1

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    int i = 0, j = 1;
    while (i < size && j < size)
    {
        int diff = arr[j] - arr[i];
        if (diff == n && i != j)
        {
            return true;
        }
        else if (diff < n)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return false;
}