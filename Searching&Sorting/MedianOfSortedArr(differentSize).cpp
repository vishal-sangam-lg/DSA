// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Approach - I:
// Merge two arr to form one sorted arr.
// Return median of big sorted arr.
// TC: O(n1+n2)
// SC: O(n1+n2)

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0, j = 0, idx = 0;
    vector<int> sortedArr(nums1.size() + nums2.size());
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] <= nums2[j])
        {
            sortedArr[idx++] = nums1[i++];
        }
        else
        {
            sortedArr[idx++] = nums2[j++];
        }
    }
    while (i < nums1.size())
    {
        sortedArr[idx++] = nums1[i++];
    }
    while (j < nums2.size())
    {
        sortedArr[idx++] = nums2[j++];
    }
    int mid = sortedArr.size() / 2 - 1;
    if (sortedArr.size() % 2 == 0)
    {
        return double(double(sortedArr[mid] + sortedArr[mid + 1]) / 2);
    }
    else
    {
        return double(sortedArr[mid + 1]);
    }
}

// Approach - II: Binary Search
// TC: O(logn)
// SC: O(1)

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int n1 = nums1.size();
    int n2 = nums2.size();

    int low = 0, high = n1;
    while (low <= high)
    {
        int mid1 = low + (high - low) / 2;
        int mid2 = ((n1 + n2) / 2) - mid1;

        int left1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
        int left2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
        int right1 = mid1 == n1 ? INT_MAX : nums1[mid1];
        int right2 = mid2 == n2 ? INT_MAX : nums2[mid2];

        if (left1 > right2)
        {
            high = mid1 - 1;
        }
        else if (left2 > right1)
        {
            low = mid1 + 1;
        }
        else
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (double)(max(left1, left2) + min(right1, right2)) / 2;
            }
            else
            {
                return (double)min(right1, right2);
            }
        }
    }
    return -1;
}