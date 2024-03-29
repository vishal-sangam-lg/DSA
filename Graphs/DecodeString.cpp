// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1
// Approach: traverse string
// case1 - digit -> currNo
// case2 - char -> currString
// case3 -   [  -> push to stack
// case4 -   ]  -> pop prevNo prevStr, construct currStr

string decodedString(string s)
{
    int currNo = 0;
    string currString = "";
    int prevNo;
    string prevString;
    stack<string> stringstack;
    stack<int> numstack;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
            currNo = currNo * 10 + (s[i] - '0');
        if (isalpha(s[i]))
            currString += s[i];
        if (s[i] == '[')
        {
            stringstack.push(currString);
            numstack.push(currNo);
            currNo = 0;
            currString = "";
        }
        if (s[i] == ']')
        {
            prevNo = numstack.top();
            numstack.pop();
            prevString = stringstack.top();
            stringstack.pop();

            while (prevNo--)
            {
                prevString += currString;
            }
            currString = prevString;
        }
    }
    return currString;
}