// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
// Approach: Declare a denomination vector. Traverse it, reduce target with greedy approach
// TC: O(n)
// SC: O(1)

vector<int> minPartition(int N)
{
    vector<int> deno = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    vector<int> ans;
    for (int i = 0; i < deno.size(); i++)
    {
        while (N >= deno[i])
        {
            N -= deno[i];
            ans.push_back(deno[i]);
        }
    }
    return ans;
}