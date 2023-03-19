// https://practice.geeksforgeeks.org/problems/find-maximum-equal-sum-of-three-stacks/1
// Approach: accumulate 3 sums, 3 pointers, return when sums are equal or pop which is greater
// TC: O(n)
// SC: O(1)

int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2, vector<int> &S3)
{
    int sum1 = accumulate(S1.begin(), S1.end(), 0);
    int sum2 = accumulate(S2.begin(), S2.end(), 0);
    int sum3 = accumulate(S3.begin(), S3.end(), 0);
    int i = 0, j = 0, k = 0;

    while (i < N1 && j < N2 && k < N3)
    {
        if (sum1 == sum2 && sum2 == sum3)
        {
            return sum1;
        }

        if (sum1 >= sum2 && sum1 >= sum3)
        {
            sum1 -= S1[i];
            i++;
        }
        else if (sum2 >= sum1 && sum2 >= sum3)
        {
            sum2 -= S2[j];
            j++;
        }
        else
        {
            sum3 -= S3[k];
            k++;
        }
    }
    return 0;
}