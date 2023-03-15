// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
// Approach: Binary Search
// TC: O(logn)
// SC: O(1)

vector<int> find(int arr[], int n, int x)
{
    vector<int> v;
    // first occurence
    int s = 0;
    int e = n - 1;
    int first = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            first = mid;
            e = mid - 1;
        }
        else if (arr[mid] < x)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    // last occurence
    s = 0;
    e = n - 1;
    int last = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            last = mid;
            s = mid + 1;
        }
        else if (arr[mid] < x)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    v.push_back(first);
    v.push_back(last);
    return v;
}
