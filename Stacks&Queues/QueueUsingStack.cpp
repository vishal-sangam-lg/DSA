// https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1

// Approach I - push O(1) & pop O(n)

void StackQueue ::push(int x)
{
    s1.push(x);
}

int StackQueue ::pop()
{
    if (s1.empty())
    {
        return -1;
    }

    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    int firstElement = s2.top(); // since s2 is reverse of s1
    s2.pop();

    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }

    return firstElement;
}

// Approach II - push O(n) & pop(1)

void StackQueue ::push(int x)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

int StackQueue ::pop()
{
    if (s1.empty())
        return -1;
    int res = s1.top();
    s1.pop();
    return res;
}