// https://leetcode.com/problems/palindrome-number/
// Approach: Construct the reverse of given number. If its equal to given number. Its palindrome
// TC: O(n)
// SC: O(1)

#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    int given = x;
    long long int reverse = 0;
    while (given)
    {
        int remainder = given % 10;
        reverse = (reverse * 10) + remainder;
        given /= 10;
    }
    return reverse == x;
}

int main()
{
    cout << isPalindrome(121) << " " << isPalindrome(-121) << " " << isPalindrome(10) << endl;
}