// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
// Striver - https://www.youtube.com/watch?v=LjPx4wQaRIs
// Approach: vector<pair<int,int>> {deadline, profit}
// sort in descending order according to profit
// Try to do a job as late as possible. Fill the slots vector
// For sorted jobs vector i -> n add a job to its rightmost slot

static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}
vector<int> JobScheduling(Job arr[], int n)
{
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++)
    {
        jobs.push_back({arr[i].dead, arr[i].profit});
    }

    sort(jobs.begin(), jobs.end(), cmp);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }
    vector<int> slots(maxDeadline + 1, -1);

    int jobsDone = 0, maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].first; j > 0; j--)
        {
            if (slots[j] == -1)
            {
                slots[j] = i;
                jobsDone++;
                maxProfit += jobs[i].second;
                break;
            }
        }
    }

    return {jobsDone, maxProfit};
}