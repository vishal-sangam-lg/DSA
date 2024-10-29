// https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1
// https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1
// Same solution for both questions
// Approach: Transform the matrix then swap rows
// TC: O(n^2)
// SC: O(1)

// The trick is
// Rotate 90 clockwise -> Transform and swap columns
// Rotate 90 anticlockwise -> Transform and swap rows

// Rotate 90 degrees anticlockwise
void rotateby90(vector<vector<int>> &m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i == j)
            {
                continue;
            }
            swap(m[i][j], m[j][i]);
        }
    }
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(m[i][j], m[n - i - 1][j]);
        }
    }
}

// https://leetcode.com/problems/rotate-image/
// Rotate 90 degrees clockwise
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transform the matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Swap columns to get rotated matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n / 2; ++j)
        {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}