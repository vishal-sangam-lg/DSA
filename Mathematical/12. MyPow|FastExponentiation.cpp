// Leetcode 50 - https://leetcode.com/problems/powx-n
// TC - O(logN) : SC - O(1)
// Approach - Fast Exponentiation - Multiple on binary level.
// If ith bit is set in x. Then in x^n, it will be x^2^i. Multiply x^2^i to answer.
// Each iteration update x^2^I but Multiply to answer only for set bits in x

// Why this works?
// x *= x after every iteration is x^2^0 , x^2^1, x^2^2, x^2^3 ...
// Whenever there’s a set bit in n (checked by n & 1), we multiply pow by the current value of x
// effectively including x^2^i

// Example: x ^ 5 (5 is 101)
// x^5 is effectively x^2^0 * x^2^2 (x^2^1 is excluded since 2nd bit is 0)
// 2^5 is effectively 2^1 * 2^4

double myPow(double x, int n)
{
    long N = n;
    if (N == 0)
    {
        return 1;
    }
    // If n is negative, we make n positive and invert x
    // x ^ -n = (1/x^n) ===> 2 ^ -3 = (1/2^3)
    if (N < 0)
    {
        N = -N;
        x = 1 / x;
    }
    double pow = 1;
    while (N)
    {
        if (N & 1) // Bit it set, Multiply with x^2^i
        {
            pow *= x;
        }
        x *= x; // calculating x^2^i
        N = N >> 1;
    }
    return pow;
}