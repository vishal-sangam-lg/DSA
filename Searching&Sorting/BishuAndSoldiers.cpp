// https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/
// Approach:
// Sort the array.
// Construct prefixSum array.
// Return strength of all the soldiers that Bishu can beat in each level
// TC: O(nlogn)
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> powers(n, 0);
    for (auto &i : powers)
        cin >> i;
    sort(powers.begin(), powers.end());

    vector<int> sum(n, 0);
    sum[0] = powers[0];
    for (int i = 1; i < n; ++i)
        sum[i] = sum[i - 1] + powers[i];

    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        int ans = upper_bound(powers.begin(), powers.end(), m) - powers.begin();
        cout << ans << " " << sum[ans - 1] << endl;
    }
    return 0;
}