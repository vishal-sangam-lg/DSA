// https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1
// Approach: Add to map. Get first most repeated and erase it from map
// Loop map to get second max
// TC: O(n)
// SC: O(n)

string secFrequent(string arr[], int n)
{
    int mx = 0;
    string firstMax = "";
    unordered_map<string, int> mp;

    // Finding first max
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > mx)
        {
            mx = mp[arr[i]];
            firstMax = arr[i];
        }
    }

    // Deleting first max
    mp.erase(firstMax);
    string secondMax = "";
    mx = 0;

    // Finding second max
    for (auto it : mp)
    {
        if (it.second > mx)
        {
            mx = it.second;
            secondMax = it.first;
        }
    }
    return secondMax;
}