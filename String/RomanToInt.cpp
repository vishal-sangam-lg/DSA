// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
// Approach: Store char values of roman in map.
// Construct int.
// If m[s[i]] < m[s[i+1]] then add m[s[i]] - m[s[i+1]]
// Else just add s[i]
// TC: O(n)
// SC: O(1)

int romanToDecimal(string str)
{
    map<char, int> rmap;
    rmap['I'] = 1;
    rmap['V'] = 5;
    rmap['X'] = 10;
    rmap['L'] = 50;
    rmap['C'] = 100;
    rmap['D'] = 500;
    rmap['M'] = 1000;
    int number = 0, i = 0;

    if (str.length() <= 1)
    {
        return rmap[str.at(0)];
    }
    else
    {
        while (i < str.size())
        {
            if (rmap[str[i]] < rmap[str[i + 1]])
            {
                number += rmap[str[i + 1]] - rmap[str[i]];
                i += 2;
            }
            else
            {
                number += rmap[str[i]];
                i++;
            }
        }
        return number;
    }
}