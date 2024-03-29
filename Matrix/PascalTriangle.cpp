// https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/
// Try running in online c++ compiler -> vscode throws error
// Approach: r[i][j] = r[i - 1][j - 1] + r[i - 1][j];

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> r(numRows);

    for (int i = 0; i < numRows; i++)
    {
        r[i].resize(i + 1);
        r[i][0] = r[i][i] = 1;

        for (int j = 1; j < i; j++)
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    }

    return r;
}

int main()
{
    vector<vector<int>> ans = generate(5);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}