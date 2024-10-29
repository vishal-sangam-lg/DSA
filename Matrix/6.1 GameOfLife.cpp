// https://leetcode.com/problems/game-of-life/

int getLiveNeighbors(vector<vector<int>> &curr, int i, int j, int row,
                     int col)
{
    int liveNeighbors = 0;
    if (i > 0)
    {
        // check the upper neighbour
        if (curr[i - 1][j] == 1 || curr[i - 1][j] == 3)
            liveNeighbors++;
    }
    if (i < row - 1)
    {
        // check the lower neighbour
        if (curr[i + 1][j] == 1 || curr[i + 1][j] == 3)
            liveNeighbors++;
    }
    if (j > 0)
    {
        // check the left neighbour
        if (curr[i][j - 1] == 1 || curr[i][j - 1] == 3)
            liveNeighbors++;
    }
    if (j < col - 1)
    {
        // check the right neighbour
        if (curr[i][j + 1] == 1 || curr[i][j + 1] == 3)
            liveNeighbors++;
    }

    if (i > 0 && j > 0)
    {
        // check top-left neighbor
        if (curr[i - 1][j - 1] == 1 || curr[i - 1][j - 1] == 3)
            liveNeighbors++;
    }
    if (i > 0 && j < col - 1)
    {
        // check top-right neighbor
        if (curr[i - 1][j + 1] == 1 || curr[i - 1][j + 1] == 3)
            liveNeighbors++;
    }
    if (i < row - 1 && j > 0)
    {
        // check botton-left neighbor
        if (curr[i + 1][j - 1] == 1 || curr[i + 1][j - 1] == 3)
            liveNeighbors++;
    }
    if (i < row - 1 && j < col - 1)
    {
        // check botton-right neighbor
        if (curr[i + 1][j + 1] == 1 || curr[i + 1][j + 1] == 3)
            liveNeighbors++;
    }
    return liveNeighbors;
}
void gameOfLife(vector<vector<int>> &board)
{
    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int liveNeighbors = getLiveNeighbors(board, i, j, n, m);
            if (board[i][j] == 0)
            {
                // currently dead
                // can become alive if has exactly three live neighbors
                if (liveNeighbors == 3)
                {
                    board[i][j] = 2; // newly alive
                }
            }
            else if (board[i][j] == 1)
            {
                // < 2 -> die
                // == 2 || == 3 -> live next generation
                // > 3 -> die
                if (liveNeighbors < 2 || liveNeighbors > 3)
                {
                    board[i][j] = 3; // newly dead
                }
            }
        }
    }
    // final modifications 2->1, 3->0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 2)
                board[i][j] = 1;
            else if (board[i][j] == 3)
                board[i][j] = 0;
        }
    }
}