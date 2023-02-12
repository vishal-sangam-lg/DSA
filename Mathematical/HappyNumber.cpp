// https://leetcode.com/problems/happy-number/
// Approach: Find squared sum and add to map. If it already exist in map.
// Cycle found -> return false

#include <iostream>
#include <unordered_map>
using namespace std;

bool isHappy(int n)
{
    unordered_map<int, int> mp;
    while (n != 1)
    {
        int sum = 0, currentDigit = n;
        while (currentDigit)
        {
            int remainder = currentDigit % 10;
            sum += pow(remainder, 2);
            currentDigit /= 10;
        }
        if (mp.find(sum) != mp.end())
        {
            return false;
        }
        else
        {
            mp[sum]++;
            n = sum;
        }
    }
    return true;
}

int main()
{
    cout << isHappy(19) << " " << isHappy(25) << endl;
}