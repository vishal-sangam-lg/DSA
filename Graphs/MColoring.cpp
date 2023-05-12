// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

// Approach: dfs. for loop recursion.
// try to color every node with all 1-m colors available inside for loop
// backtrack if current flow of coloring doesn't work

bool isValid(bool graph[101][101], int node, vector<int> &color, int n, int rang)
{
    for (int i = 0; i < n; i++)
    {
        // If i and node are connected and color of i is rang that we are trying to color
        // return false
        if (graph[i][node] == 1 && color[i] == rang)
            return false;
    }
    return true;
}

bool coloring(bool graph[101][101], int m, int n, vector<int> &color, int node)
{
    if (node == n)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isValid(graph, node, color, n, i))
        {
            color[node] = i;
            if (coloring(graph, m, n, color, node + 1))
                return true;
            color[node] = 0; // backtrack
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, 0);
    return coloring(graph, m, n, color, 0);
}