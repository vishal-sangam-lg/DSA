// https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
// Approach: Dutch National flag // low high i partitioning
// TC: O(n)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

void threeWayPartition(vector<int> &arr, int a, int b)
{
    // Dutch national flag algorithm
    // < a      -> 0 - low-1
    // [a, b]   -> low - high
    // > b      -> high+1 - arr end
    int low = 0, i = 0, high = arr.size() - 1;
    while (i <= high)
    {
        if (arr[i] < a)
        {
            swap(arr[low], arr[i]);
            low++;
            i++;
        }
        else if (arr[i] >= a && arr[i] <= b)
        {
            i++;
        }
        else
        {
            swap(arr[i], arr[high]);
            high--;
        }
    }
}