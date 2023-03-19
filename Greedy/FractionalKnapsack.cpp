// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// Approach: sort it according to ratio value/weight (descending order). LOOT!
// TC: O(nlogn)
// SC: O(1)

static bool cmp(Item a, Item b)
{
    return a.value / (a.weight * 1.0) > b.value / (b.weight * 1.0);
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    double loot = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (W - arr[i].weight >= 0)
        {
            loot += arr[i].value;
            W -= arr[i].weight;
        }
        else
        {
            loot += W * (arr[i].value / (arr[i].weight * 1.0));
            break;
        }
    }
    return loot;
}