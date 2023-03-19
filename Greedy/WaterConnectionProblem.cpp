// https://practice.geeksforgeeks.org/problems/water-connection-problem5822/1
// Approach: map pipes a->b, diameter a->d,
// isRoot[b[i]] = false coz If it has an incoming pipe, it can't be root
// add roots to vector if it is present in map of pipes and isRoot is true
// Traverse roots, for every root, traverse map of pipes, update minDiameter
// res.push_back({root, end, minDiameter})

// Dry run:
// 17 11
// 6 5 2
// 4 7 2
// 14 16 2
// 17 12 4
// 3 2 8
// 15 13 2
// 16 6 8
// 5 17 8
// 7 1 9
// 11 4 9
// 12 8 2

// pipes:
// 6 -> 5
// 4 -> 7
// 14 -> 16
// 17 -> 12
// 3 -> 2
// 15 -> 13
// 16 -> 6
// 5 -> 17
// 7 -> 1
// 11 -> 4
// 12 -> 8

// diameter:
// 6 -> 2
// 4 -> 2
// 14 -> 2
// 17 -> 4
// 3 -> 8
// 15 -> 2
// 16 -> 8
// 5 -> 8
// 7 -> 9
// 11 -> 9
// 12 -> 2

// isRoot
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// 0 f f T f f f f f f f  T  f  f  T  T  f  f

// roots: 3 11 14 15

vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
{
    unordered_map<int, int> pipes;
    unordered_map<int, int> diameter;
    vector<bool> isRoot(n + 1, true);

    // Mapping pipes a -> b and diameter a -> d
    // If a house has incomming pipe, it can't be root.
    for (int i = 0; i < p; i++)
    {
        pipes[a[i]] = b[i];
        diameter[a[i]] = d[i];
        isRoot[b[i]] = false;
    }

    // Adding root homes(starting points to vector)
    vector<int> roots;
    for (int i = 1; i <= n; i++)
    {
        if (isRoot[i] && pipes.find(i) != pipes.end())
        {
            roots.push_back(i);
        }
    }

    vector<vector<int>> res;
    for (int root : roots)
    {
        int minDiameter = diameter[root];
        int end = root;
        while (pipes.find(end) != pipes.end())
        {
            minDiameter = min(minDiameter, diameter[end]);
            end = pipes[end];
        }
        res.push_back({root, end, minDiameter});
    }
    return res;
}