// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
// Approach: dfs
// O should become X only if it is not connected with boundary
// 1st itr -> mark all O connected to boundary as '#'
// 2nd itr -> mark all O as X and # as O
// TC: O(n*m)

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &board, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O')
        return;

    board[i][j] = '#';

    dfs(board, i - 1, j, n, m);
    dfs(board, i + 1, j, n, m);
    dfs(board, i, j - 1, n, m);
    dfs(board, i, j + 1, n, m);
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
{
    if (n == 0)
        return board;

    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O')
            dfs(board, i, 0, n, m);
        if (board[i][m - 1] == 'O')
            dfs(board, i, m - 1, n, m);
    }

    for (int i = 0; i < m; i++)
    {
        if (board[0][i] == 'O')
            dfs(board, 0, i, n, m);
        if (board[n - 1][i] == 'O')
            dfs(board, n - 1, i, n, m);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            if (board[i][j] == '#')
                board[i][j] = 'O';
        }
    }
    return board;
}