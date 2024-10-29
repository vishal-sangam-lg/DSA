// Leetcode 59 - https://leetcode.com/problems/spiral-matrix-ii/description/
// TC - O(n^n) : SC - O(n^n) for result

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> result(n, vector<int>(n, 0));
    int top = 0;
    int bottom = n - 1;
    int right = n - 1;
    int left = 0;
    int num = 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++) // processing top line
        {
            result[top][i] = num++;
        }
        top++;
        for (int i = top; i <= bottom; i++) // processing right line
        {
            result[i][right] = num++;
        }
        right--;
        for (int i = right; i >= left; i--) // processing botton line
        {
            result[bottom][i] = num++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--) // processing left line
        {
            result[i][left] = num++;
        }
        left++;
    }

    return result;
}