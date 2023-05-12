// https://practice.geeksforgeeks.org/problems/calculate-the-coefficient/0
// DP solution exists, but TC is higher
// Formula for permutation coefficient
// P(n, k) = n * (n - 1) * (n - 2)... *(n - k + 1)
int permutationCoeff(int n, int k)
{
    long long MOD = 1e9 + 7, coeff = 1;
    for (int i = n; i > n - k; i--)
        coeff = coeff * i % MOD;
    return coeff;
}