// https://www.spoj.com/problems/SUBSUMS/

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &arr, int a, int b, int i, int sum, int &count)
{
    if (i >= arr.size())
    {
        if (sum >= a && sum <= b)
        {
            count++;
        }
        return;
    }

    // Include
    solve(arr, a, b, i + 1, sum + arr[i], count);
    // Exclude
    solve(arr, a, b, i + 1, sum, count);
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0, sum = 0, count = 0;
    solve(arr, a, b, i, sum, count);
    cout << count << endl;
    return 0;
}