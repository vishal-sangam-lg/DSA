// https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1
// Approach: vector<pair<int,int>> {end, start}. Sort according to end
// If start > last end. ans++
// TC: O(nlogn)
// SC: O(n)

int activitySelection(vector<int> start, vector<int> end, int n)
{
    vector<pair<int, int>> activities;
    for (int i = 0; i < n; i++)
    {
        activities.push_back({end[i], start[i]});
    }
    int ans = 1;
    sort(activities.begin(), activities.end());

    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (activities[j].second > activities[i].first)
        {
            ans++;
            i = j;
        }
    }
    return ans;
}