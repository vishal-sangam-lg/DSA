// https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1
// Appraoch: s = s1+s1
// If s contains s2. then s2 is a rotation of s1

bool areRotations(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    string s = s1 + s1;
    return s.find(s2) != string::npos;
}