// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// Approach: Via every route k=0->n. Check if i->k->j is shorter than i->j for every cell in matrix[i][j]

void shortest_distance(vector<vector<int>> &mat)
{
    int size = mat.size();

    // For every vertex. V -> a, b, c, d
    // ex. src = a, target = d. check a->b->d,  a->c->d,  a->d
    // Check via b, c or if directly is it shorter
    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (mat[i][k] == -1 || mat[k][j] == -1)
                {
                    continue;
                }
                // Going i->j via k (Important!)
                int curr = mat[i][k] + mat[k][j];
                if (mat[i][j] == -1)
                {
                    mat[i][j] = curr;
                }
                else
                {
                    mat[i][j] = min(mat[i][j], curr);
                }
            }
        }
    }
}