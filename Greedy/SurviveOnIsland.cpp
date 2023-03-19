// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1
// Approach: Basic maths
// TC: O(1)
// SC: O(1)

int minimumDays(int S, int N, int M)
{
    int totalRequiredFood = M * S;
    int noOfDaysShopIsAvailable = S - (S / 7);
    int totalAvailableFood = N * noOfDaysShopIsAvailable;

    if (totalRequiredFood > totalAvailableFood)
    {
        return -1;
    }

    return ceil(totalRequiredFood / (float)N);
}