// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
// Approach: Sort arrival and departure
// platform++ if arrival[i] <= departure[j] else j++
// TC: O(nlogn)
// SC: O(1)

// Dry run:
// arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
// dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
// sorted:
// arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
// dep[] = {0910, 1120, 1130, 1200, 1900, 2000}
// 0900     0940  0950  1100                   1500  1800
//     0910                   1120  1130 1200              1900 2000

int findPlatform(int arr[], int dep[], int n)
{
    int platform = 0;
    int i = 0, j = 0;
    sort(arr, arr + n);
    sort(dep, dep + n);
    while (i < n)
    {
        // If a train arrives before last train departures, platform++
        // j points at last departure
        if (arr[i] <= dep[j])
        {
            platform++;
        }
        else
        {
            j++;
        }
        i++;
    }
    return platform;
}