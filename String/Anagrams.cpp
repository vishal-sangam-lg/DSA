// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1
// Sort all the words individually and add key as sorted word and value as actual word.
// Loop the map. Get ans.
// TC: O(|S| * nlogn)
// SC: O(|S|)

vector<vector<string>> Anagrams(vector<string> &string_list)
{
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;
    for (int i = 0; i < string_list.size(); i++)
    {
        string word = string_list[i];
        sort(word.begin(), word.end());
        mp[word].push_back(string_list[i]);
    }
    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}