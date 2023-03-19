// https://www.spoj.com/problems/DEFKIN/
// Approach: Store heights and width in vector. Sort them.
// Find maximum difference between two widths, two heights
// ans = maxWidth * maxHeight

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maximumUndefendedArea(vector<int> &widths, vector<int> &heights)
{
    sort(widths.begin(), widths.end());
    sort(heights.begin(), heights.end());
    int maxWidth = 0, maxHeight = 0;
    for (int i = 0; i < widths.size() - 1; i++)
    {
        maxWidth = max(maxWidth, widths[i + 1] - widths[i] - 1);
        maxHeight = max(maxHeight, heights[i + 1] - heights[i] - 1);
    }
    return maxWidth * maxHeight;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int width, height, towers;
        cin >> width >> height >> towers;
        vector<int> widths;
        vector<int> heights;
        widths.push_back(0);
        heights.push_back(0);
        for (int i = 0; i < towers; i++)
        {
            int x, y;
            cin >> x >> y;
            widths.push_back(x);
            heights.push_back(y);
        }
        widths.push_back(width + 1);
        heights.push_back(height + 1);
        cout << maximumUndefendedArea(widths, heights) << endl;
    }
    return 0;
}