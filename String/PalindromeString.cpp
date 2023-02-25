// https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

// User function template for C++

int isPalindrome(string S)
{
    int i = 0;
    int j = S.length() - 1;
    while (i < j)
    {
        if (S[i] == S[j])
        {
            i++;
            j--;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
