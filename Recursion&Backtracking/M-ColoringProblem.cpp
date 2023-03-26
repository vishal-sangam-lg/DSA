// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
// Approach: maintain color vector. Try to color a particular node with all possible color 1-m
// Backtrack if path fails

// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isValid(bool graph[101][101], int node, vector<int> &color, int n, int rang)
{
    for (int i = 0; i < n; i++)
    {
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
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, 0);
    return coloring(graph, m, n, color, 0);
}