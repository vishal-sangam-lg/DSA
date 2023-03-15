// https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1
// Approach: stable_sort(arr, arr+n, custom comparator using __builtin_popcount())
// References
// gcc builtin functions: https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/
// stable_sort: https://www.geeksforgeeks.org/stable_sort-c-stl/
// TC: O(nlogn)
// SC: O(1)

static bool custom_comparator(int a, int b)
{
    return __builtin_popcount(a) > __builtin_popcount(b);
}
void sortBySetBitCount(int arr[], int n)
{
    stable_sort(arr, arr + n, custom_comparator);
}