// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// Approach: map<int,int> & queue<pair<Node*,int>>. Store Node and its corresponding value
// Root = 0. When you move left, decrement value by 1
// When you move right, increment value by 1
// Add to map as well.
// When you add a node for first time with particular value. Its part of top view
// TC: O(nlogn)
// SC: O(n)

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *currNode = it.first;
        int currNodeValue = it.second;

        if (mp.find(currNodeValue) == mp.end())
        {
            mp[currNodeValue] = currNode->data;
        }
        if (currNode->left)
            q.push({currNode->left, currNodeValue - 1});
        if (currNode->right)
            q.push({currNode->right, currNodeValue + 1});
    }

    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}