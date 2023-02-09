// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

#include <iostream>
using namespace std;

// Approach I - traverse arr1, swap arr1[i] and arr2[0] if arr2[0] < arr1[i]
// Insert swapped arr2[0] in its right position to keep arr2 sorted
// TC: O(n^2) SC: O(1)

// void merge(long long arr1[], long long arr2[], int n, int m)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (arr1[i] > arr2[0])
//         {
//             // swapping arr1[i] and arr2[0]
//             swap(arr1[i], arr2[0]);
//             int first = arr2[0], j;
//             // Inserting arr2[0] to right position in arr2
//             // So that arr2 remains sorted
//             for (j = 1; j < m && arr2[j] < first; j++)
//             {
//                 arr2[j - 1] = arr2[j];
//             }
//             arr2[j - 1] = first;
//         }
//     }
// }

// Approach - II
// Swap till arr1[i] > arr2[j] where i is RTL and j is LTR
// move both pointers in opposite direction
// Sort both arrays again
// Intuition: if arr1[i] > arr2[j] => arr2[j] must belong to arr1 and vice versa
// TC: O(nlogn) SC: O(1)

// void merge(long long arr1[], long long arr2[], int n, int m)
// {
//     int i = n - 1, j = 0;
//     while (i >= 0 && j < m && arr1[i] > arr2[j])
//     {
//         swap(arr1[i], arr2[j]);
//         i--;
//         j++;
//     }
//     sort(arr1, arr1 + n);
//     sort(arr2, arr2 + m);
// }

// Two more better and optimal solutions exist
// using gap -> TC(nlogn) SC(1)
// using euclidean division lemma -> TC(n) SC(1)