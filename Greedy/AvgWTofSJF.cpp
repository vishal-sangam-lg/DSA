// https://practice.geeksforgeeks.org/problems/shortest-job-first/1
// Approach: sort burst time. Calculate total waiting time by adding all waiting time. return avg
// TC: O(nlogn)
// SC: O(1)

int solve(vector<int> &bt)
{
    sort(bt.begin(), bt.end());
    int n = bt.size(); // no. of tasks
    int ct = 0;        // completion time
    int totalWaitingTime = 0;

    for (int i = 0; i < n; i++)
    {
        ct += bt[i];
        totalWaitingTime += ct - bt[i];
    }

    return totalWaitingTime / n;
}