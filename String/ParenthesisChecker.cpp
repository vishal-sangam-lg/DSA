// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
// Approach: Use stack to store opening brackets. compare close and pop

bool ispar(string x)
{
    char st[x.length()];
    int top = -1;
    int flag = 1;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == '(' || x[i] == '[' || x[i] == '{')
        {
            st[++top] = x[i];
        }
        if (x[i] == ')' || x[i] == ']' || x[i] == '}')
        {
            char temp = st[top--];
            if (x[i] == ')' && temp != '(')
            {
                flag == 0;
            }
            else if (x[i] == ']' && temp != '[')
            {
                flag = 0;
            }
            else if (x[i] == '}' && temp != '{')
            {
                flag = 0;
            }
        }
    }
    if (top != -1)
    {
        return false;
    }
    if (flag == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}