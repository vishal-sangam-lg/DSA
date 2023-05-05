// https://leetcode.com/problems/clone-graph/
// https://practice.geeksforgeeks.org/problems/clone-graph/1

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// Approach I : dfs
// unordered_map<Node*, Node*> to store if copy is already made or not
// If node not present in map, make a new node, add to map, it neighbours -> dfs()

class Solution
{
public:
    unordered_map<Node *, Node *> mp;
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (mp.find(node) == mp.end()) // if not present in map -> copy not made
        {
            mp[node] = new Node(node->val, {}); // make a copy

            for (auto adj : node->neighbors) // travel all neighbours
            {
                mp[node]->neighbors.push_back(cloneGraph(adj)); // add copy
            }
        }

        return mp[node];
    }
};

// Approach II : bfs
// Same logic but bfs
unordered_map<Node *, Node *> mp;
Node *cloneGraph(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    Node *first = new Node(node->val, {});
    mp[node] = first;
    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        for (auto adj : curr->neighbors)
        {
            if (mp.find(adj) == mp.end()) // Not present in map
            {
                mp[adj] = new Node(adj->val, {});
                q.push(adj);
            }
            mp[curr]->neighbors.push_back(mp[adj]); // pushing neighbors
        }
    }

    return mp[node];
}