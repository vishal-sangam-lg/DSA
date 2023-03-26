// https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1
// Approach: Try to place queen in every col of every row.
// Before placing, check if queen is already present in col top-left or top-right diagonal

bool isSafe(int row, int col, int n, vector<vector<int>> &board)
{
    // Checking if there already exist a queen in current column
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    // Checking if there already exist a queen in top-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    // Checking if there already exist a queen in top-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
void solve(int row, int n, vector<vector<int>> &board, vector<vector<int>> &ans)
{
    // Queens are placed in every row. Add to ans
    if (row == n)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    temp.push_back(j + 1);
                }
            }
        }
        ans.push_back(temp);
        return;
    }

    // Trying to place queen in every column of current row
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, n, board))
        {
            board[row][col] = 1;           // Place queen
            solve(row + 1, n, board, ans); // Place queen in next row
            board[row][col] = 0;           // Backtrack -> Remove queen
        }
    }
}
vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(0, n, board, ans);
    sort(ans.begin(), ans.end());
    return ans;
}