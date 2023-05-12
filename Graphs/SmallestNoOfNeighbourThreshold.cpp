// https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1
// Approach: floyd warshall algo to find minimum distance from all point to all point
// for city 0-n for adjCity 0-n -> if dist[city][adjCity] <= threshold cnt++;
// Return minCount

int findCity(int n, int m, vector<vector<int>> &edges,
             int distanceThreshold)
{
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (auto it : edges)
    {
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    // Floyd warshall algorithm to find shortest path
    // from all point to all point
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int cntCity = n; // count of neighbouring cities
    int cityNo = -1; // city with minimum neighbours with given threshold
    for (int city = 0; city < n; city++)
    {
        int cnt = 0;
        for (int adjCity = 0; adjCity < n; adjCity++)
        {
            if (dist[city][adjCity] <= distanceThreshold)
            {
                cnt++;
            }
        }
        if (cnt <= cntCity)
        {
            cntCity = cnt;
            cityNo = city;
        }
    }
    return cityNo;
}