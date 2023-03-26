// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
// Approach: Brute force -> Try to place all number 0-9 in every position of 9x9 matrix that is = 0
// Write isValid helper function to check before placing a number
// TC: O(9^(n^2))
// SC: O(n * n)

bool SolveSudoku(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int c = 1; c <= 9; c++)
                {
                    if (isValid(grid, i, j, c))
                    {
                        grid[i][j] = c;
                        if (SolveSudoku(grid) == true)
                            return true;
                        else
                            grid[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isValid(int grid[N][N], int row, int col, int c)
{
    for (int i = 0; i < 9; i++)
    {
        // Checking if number we are trying to insert in already in current row or column
        if (grid[i][col] == c || grid[row][i] == c)
            return false;
        // Checking if number we are trying to insert in already in current square
        if (grid[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
            return false;
    }
    return true;
}

// Function to print grids of the Sudoku.
void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
    }
}