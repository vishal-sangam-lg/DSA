// https://leetcode.com/problems/reverse-words-in-a-string/
// Approach: traverse LTR till != ' '
// Reverse from there to next ' ' or end
// Repeat
// TC: O(n)
// SC: O(n) -> result

string reverseWords(string s)
{
    string result;
    int i = 0, n = s.length();

    while (i < n)
    {
        // to detect spaces and ignore them
        while (i < n && s[i] == ' ')
            i++;

        if (i >= n)
            break;

        int j = i;

        // to detect characters and break when we detect any space
        while (j < n && s[j] != ' ')
            j++;

        // to take out the word
        string sub = s.substr(i, j - i);

        if (result.length() == 0)
            result = sub;

        else
            result = sub + " " + result;

        i = j + 1;
    }

    return result;
}

// TC: O(n^2)
// SC: O(1)

void reverseword(string &s, int i, int j)
{
    while (i < j)
    {
        char t = s[i];
        s[i++] = s[j];
        s[j--] = t;
    }
}

void reverseWords(string &s)
{

    int i = 0, j = 0;
    int l = 0;
    int len = s.length();
    int wordcount = 0;

    while (true)
    {
        while (i < len && s[i] == ' ')
            i++; // skip spaces in front of the word
        if (i == len)
            break;
        if (wordcount)
            s[j++] = ' ';
        l = j;
        while (i < len && s[i] != ' ')
        {
            s[j] = s[i];
            j++;
            i++;
        }
        reverseword(s, l, j - 1); // reverse word in place
        wordcount++;
    }

    s.resize(j);              // resize result string
    reverseword(s, 0, j - 1); // reverse whole string
}

// GFG variant - https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

string reverseWords(string S)
{
    string res = "";
    string str = "";
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '.')
        {
            str = '.' + str;
            res = str + res;
            str = "";
        }
        else
            str += S[i];
    }
    res = str + res;
    return res;
}