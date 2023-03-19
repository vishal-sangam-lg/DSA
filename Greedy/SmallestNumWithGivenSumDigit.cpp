// https://practice.geeksforgeeks.org/problems/smallest-number5829/1
// Approach: 10^(no. of digits - 1) will be initial number. Fill the number RTL with min(sumOfDigits, 9)

string smallestNumber(int sumOfDigits, int numberOfDigits)
{
    // Base case -> Number can't be formed
    if (numberOfDigits * 9 < sumOfDigits || (sumOfDigits == 0 && numberOfDigits > 1))
        return "-1";

    sumOfDigits--;
    int res = (int)pow(10, numberOfDigits - 1);
    int multiplier = 1;
    while (sumOfDigits > 0)
    {
        res += multiplier * min(sumOfDigits, 9);
        sumOfDigits -= min(sumOfDigits, 9);
        multiplier *= 10;
    }
    return to_string(res);
}