// https://www.spoj.com/problems/ARRANGE/
// Approach: Sort in descending order. add 1s to beginning.
// Special case n==2 and its 23. return 23. Else return desc order

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int countOnes = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                countOnes++;
        }

        sort(a, a + n, greater<int>());

        // Base case -> all 1s in the beginning
        for (int i = 0; i < countOnes; i++)
            cout << "1 ";

        // Special case -> 2 3 > 3 2
        if ((n - countOnes) == 2 && a[0] == 3 && a[1] == 2)
        {
            cout << "2 3" << endl;
        }
        // All other case -> return descending order
        else
        {
            for (int i = 0; i < (n - countOnes); i++)
                cout << a[i] << " ";
            cout << endl;
        }
    }

    return 0;
}