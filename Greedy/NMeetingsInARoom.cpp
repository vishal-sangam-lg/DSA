// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// Approach: vector<pair<int,int>> sort with custom comparator
// If endtime is equal, sort according to start time. else sort according to end time
// TC: O(nlogn)
// SC: O(n)

static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++)
    {
        meetings.push_back({start[i], end[i]});
    }

    sort(meetings.begin(), meetings.end(), cmp);

    int ans = 1, lastEndtime = meetings[0].second;
    for (int i = 1; i < meetings.size(); i++)
    {
        if (lastEndtime < meetings[i].first)
        {
            lastEndtime = meetings[i].second;
            ans++;
        }
    }
    return ans;
}