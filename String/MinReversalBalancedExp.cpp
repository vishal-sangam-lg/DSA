// Minimum number of reversals required to convert the string into a balanced expression
// Approach:
// All possible invalid brackets that would be left after removing valid brackets
// case 1 - ......{{{{  ->  ans = 2 -> always count of open is even
// case 2 - }}}}......  ->  ans = 2 -> always count of close is even
// case 3 - ...}}{{...  ->  count of open and close can be both odd or both even
// case 3(odd) ->   }}}{{{    ->  ans = 4
// case 4(even) ->  }}}}{{{{  ->  ans = 4
// ... represent valid part of expression
// Conclusion -> ans = ceil(open/2.0) + ceil(close/2.0)
// TC: O(n)
// SC: O(1)

int countRev(string s)
{
    if (s.length() % 2 == 1)
        return -1;

    int open = 0, close = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
        {
            open++;
        }
        else
        {
            open--;
        }
        if (open < 0)
        {
            close++;
            open = 0;
        }
    }
    return ceil(close / 2.0) + ceil(open / 2.0);
}