// https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/
// Leetcode 118 - https://leetcode.com/problems/pascals-triangle/description/
// Approach: r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
// Base case - i = 0, 1. All 1s

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result(numRows);

    for (int i = 0; i < numRows; ++i)
    {
        result[i].resize(i + 1, 1);
        // For i == 0, 1 => we just have 1s. (Base case)
        if (i == 0 || i == 1)
        {
            continue;
        }
        // Start from j = 1, since j = 0 will always be 1
        for (int j = 1; j < i; ++j)
        {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    return result;
}