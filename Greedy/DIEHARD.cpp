// https://www.spoj.com/problems/DIEHARD/
// Approach: 1 -> air, 2 -> water, 3 -> fire
// {health, armour}
// 1(air)   -> +3, +2
// 2(water) -> -5, -10
// 3(fire)  -> -20, +5
// Recursion with dp

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int dp[1001][1001];

int diehard(int health, int armour, int prevStep)
{
    if (health <= 0 || armour <= 0)
    {
        return 0;
    }
    if (dp[health][armour] != -1)
    {
        return dp[health][armour];
    }

    int air = 0, water = 0, fire = 0;
    if (prevStep != 1)
    {
        air = 1 + diehard(health + 3, armour + 2, 1);
    }
    if (prevStep != 2)
    {
        water = 1 + diehard(health - 5, armour - 10, 2);
    }
    if (prevStep != 3)
    {
        fire = 1 + diehard(health - 20, armour + 5, 3);
    }

    return dp[health][armour] = max({air, water, fire});
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int health, armour;
        cin >> health >> armour;
        memset(dp, -1, sizeof(dp));
        cout << max({diehard(health + 3, armour + 2, 1), diehard(health - 5, armour - 10, 2), diehard(health - 20, armour + 5, 3)}) << endl;
    }
    return 0;
}