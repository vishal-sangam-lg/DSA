// https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

// C++ program to count all duplicates
// from string using maps
#include <iostream>
#include <unordered_map>
using namespace std;
void printDups(string str)
{
    unordered_map<char, int> count;
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]]++;
    }

    for (auto it : count)
    {
        if (it.second > 1)
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}
/* Driver code*/
int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}