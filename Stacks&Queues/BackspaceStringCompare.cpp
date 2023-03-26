// https://leetcode.com/problems/backspace-string-compare/
// Approach: Construct string a and b from s, t. return a == b.
// if(s[i]=='# && a.size()>0) a.pop_back. Else a.push_back

string buildString(string s)
{
    string a = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            if (a.size() > 0)
            {
                a.pop_back();
            }
            else
            {
                continue;
            }
        }
        else
        {
            a.push_back(s[i]);
        }
    }
    return a;
}
bool backspaceCompare(string s, string t)
{
    string a = buildString(s);
    string b = buildString(t);

    return a == b;
}