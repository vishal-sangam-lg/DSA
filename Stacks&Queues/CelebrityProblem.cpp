// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
// Approach I - Using stacks
// Step 1: Push all elements into stack
// Step 2: compare top 2 person, push 1 potential celebrity until stk.size() >= 2
// Step 3: Verify if the potential celebrity is actually a celebrity
// TC: O(n)
// SC: O(n)

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> stk;
    // Step 1: Push all elements into stack
    for (int i = 0; i < n; i++)
    {
        stk.push(i);
    }

    // Step 2:
    while (stk.size() >= 2)
    {
        int personA = stk.top();
        stk.pop();
        int personB = stk.top();
        stk.pop();

        // Person A knows Person B
        if (M[personA][personB] == 1)
        {
            stk.push(personB);
        }
        else
        {
            stk.push(personA);
        }
    }

    // Step 3: Verify if the potential celebrity is actually a celebrity
    int celebrity = stk.top();
    for (int i = 0; i < n; i++)
    {
        if (i != celebrity && (M[i][celebrity] == 0 || M[celebrity][i] == 1))
        {
            return -1;
        }
    }
    return celebrity;
}

// Approach II - Two pointer (Optimal solution)
// Initialise celebrity = 0, other = n-1
// If celebrity knows other, then he is not celebrity, celebrity++
// Else other has no chance of becoming celebrity since current celebrity doesn't know him. other--
// TC: O(n)
// SC: O(1)

int celebrity(vector<vector<int>> &M, int n)
{
    int celebrity = 0, other = n - 1;
    while (celebrity < other)
    {
        if (M[celebrity][other] == 1)
        {
            celebrity++;
        }
        else
        {
            other--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i != celebrity && (M[i][celebrity] == 0 || M[celebrity][i] == 1))
        {
            return -1;
        }
    }
    return celebrity;
}