// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
// Approach: Boyer Moore’s Voting Algorithm
// 1st itr -> Find the number that has highest frequency using count and maj_index
// 2nd itr -> Check if the frequency > size/2
// Intuition: If its a majoriry element, its count will never fall below zero
// when you ++ when you see it and -- when you don't see it
// TC: O(n)
// SC: O(1)

int majorityElement(int a[], int size)
{
    // Find the number that has highest frequency
    int count = 1, maj_index = 0;
    for (int i = 1; i < size; i++)
    {
        if (a[maj_index] == a[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }

    // Check if the frequency > size/2
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == a[maj_index])
            count++;
    }

    if (count > size / 2)
        return a[maj_index];

    return -1;
}

// Leetcode variant - https://leetcode.com/problems/majority-element/

int majorityElement(vector<int> &nums)
{
    // Find the number that has highest frequency
    int count = 1, maj_index = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[maj_index] == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }

    return nums[maj_index];
}