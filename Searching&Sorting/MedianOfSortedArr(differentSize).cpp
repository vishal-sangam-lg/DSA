// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Striver - https://www.youtube.com/watch?v=NTop3VTjmxk
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
// low high cut1 cut2 l1 l2 r1 r2. If cut is valid, return median else adjust low,high
// TC: O(logn)
// SC: O(1)

double MedianOfArrays(vector<int> &nums1, vector<int> &nums2)
{
    // Take first array as smaller array
    if (nums1.size() > nums2.size())
        return MedianOfArrays(nums2, nums1);

    int n1 = nums1.size();
    int n2 = nums2.size();

    int low = 0, high = n1;
    while (low <= high)
    {
        // Partition
        int cut1 = low + (high - low) / 2;
        int cut2 = ((n1 + n2) / 2) - cut1;

        // l1 | l2 becomes INT_MIN if no element is picked on left
        // r1 | r2 becomes INT_MAX if no element is picked on right
        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

        if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else if (left2 > right1)
        {
            low = cut1 + 1;
        }
        else // Valid partition
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