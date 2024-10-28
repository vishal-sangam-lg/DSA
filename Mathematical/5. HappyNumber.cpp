// https://leetcode.com/problems/happy-number/
// Approach: Find squared sum and add to map. If it already exist in set.
// Cycle found -> return false

int getSumOfSquaresOfDigits(int n)
{
    int sumOfSquares = 0;
    while (n)
    {
        int digit = n % 10;
        sumOfSquares += (digit * digit);
        n /= 10;
    }
    return sumOfSquares;
}
bool isHappy(int n)
{
    unordered_set<int> set;
    set.insert(n);
    while (true)
    {
        if (n == 1)
        {
            return true;
        }
        n = getSumOfSquaresOfDigits(n);
        if (set.find(n) != set.end())
        {
            return false;
        }
        set.insert(n);
    }
}