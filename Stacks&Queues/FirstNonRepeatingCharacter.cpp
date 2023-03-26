// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
// Approach: Maintain char order in queue. Freq in aux arr. while freq != 1 pop from queue.
// If queue is empty. add # else queue.front

string FirstNonRepeating(string A)
{
    queue<int> q;
    int freq[26] = {0};
    for (int i = 0; i < A.size(); i++)
    {
        freq[A[i] - 'a']++;
        if (freq[A[i] - 'a'] == 1)
        {
            q.push(A[i]);
        }
        while (!q.empty() && freq[q.front() - 'a'] != 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            A[i] = '#';
        }
        else
        {
            A[i] = q.front();
        }
    }
    return A;
}