// https://practice.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1

string printSequence(string S)
{
    string sequences[] = {"2", "22", "222", "3", "33", "333", "4", "44", "444",
                          "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88",
                          "888", "9", "99", "999", "9999"};
    string seq;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == ' ')
        {
            seq += "0";
        }
        else
        {
            seq += sequences[S[i] - 'A'];
        }
    }
    return seq;
}