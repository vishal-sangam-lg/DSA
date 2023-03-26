// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1

// Approach I - Using 2 Queue -> push: O(1) pop: O(n)

void QueueStack ::push(int x)
{
    q1.push(x);
}

int QueueStack ::pop()
{
    if (q1.empty())
    {
        return -1;
    }

    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }

    int lastElement = q1.front();
    q1.pop();

    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }

    return lastElement;
}

// Approach II - Using 2 Queue -> push: O(n) pop: O(1)

void QueueStack ::push(int x)
{
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    q1.push(x);

    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
}

int QueueStack ::pop()
{
    if (q1.empty())
    {
        return -1;
    }

    int lastElement = q1.front();
    q1.pop();
    return lastElement;
}

// Approach III - Using 1 Queue -> push: O(1) pop: O(n)

void QueueStack ::push(int x)
{
    q1.push(x);
}

int QueueStack ::pop()
{
    if (q1.empty())
    {
        return -1;
    }

    int x = q1.back();
    int n = q1.size();
    for (int i = 0; i < n - 1; i++)
    {
        q1.push(q1.front());
        q1.pop();
    }
    q1.pop();
    return x;
}