// https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1
// Approach: Add string to set. Traverse string and erase a[i] from set.
// If *s.begin() < a[i], replace all occurences

string chooseandswap(string a)
{
    set<char> s(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
    {
        s.erase(a[i]);
        if (s.empty())
            break;
        if (*s.begin() < a[i])
        {
            char small = *s.begin();
            char replace = a[i];
            for (int j = 0; j < a.size(); j++)
            {
                if (a[j] == small)
                    a[j] = replace;
                else if (a[j] == replace)
                    a[j] = small;
            }
            break;
        }
    }
    return a;
}