// https://www.spoj.com/problems/CHOCOLA/
// Minimum cost to cut a board into squares - gfg variant
// https://practice.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1

// Approach: Sort X and Y in descending order. Cut the maximum costs first
// coz horizontal pieces and vertical pieces will be less initially. pieces++
// TC: O(nlogn)
// SC: O(1)

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N)
{
    sort(X.begin(), X.end(), greater<int>());
    sort(Y.begin(), Y.end(), greater<int>());

    int horizontalPieces = 1, verticalPieces = 1;
    int i = 0, j = 0, cost = 0;

    while (i < X.size() && j < Y.size())
    {
        if (X[i] >= Y[j])
        {
            cost += X[i] * verticalPieces;
            horizontalPieces++;
            i++;
        }
        else
        {
            cost += Y[j] * horizontalPieces;
            verticalPieces++;
            j++;
        }
    }

    while (i < X.size())
    {
        cost += X[i] * verticalPieces;
        horizontalPieces++;
        i++;
    }

    while (j < Y.size())
    {
        cost += Y[j] * horizontalPieces;
        verticalPieces++;
        j++;
    }

    return cost;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m;
        cin >> n;
        vector<int> X(m);
        for (int i = 0; i < m - 1; i++)
        {
            cin >> X[i];
        }
        vector<int> Y(n);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> Y[i];
        }
        cout << minimumCostOfBreaking(X, Y, m, n) << endl;
    }
    return 0;
}