// https://practice.geeksforgeeks.org/problems/sort-a-stack/1
// Approach: Recursively reach bottom of stack.
// Insert every element in correct position with insert()

void insert(stack<int> &s, int x)
{
    if (s.empty() || s.top() <= x)
    {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();
    insert(s, x);
    s.push(top);
}

void SortedStack ::sort()
{
    if (s.empty())
    {
        return;
    }

    int x = s.top();
    s.pop();
    sort();
    insert(s, x);
}