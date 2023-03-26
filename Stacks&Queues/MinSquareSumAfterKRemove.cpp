// https://practice.geeksforgeeks.org/problems/game-with-string4100/1
// Approach: Count freq. If freq > 0, add to maxHeap. while k-- reduce top of maxHeap by 1
// Calculate sumOfSquares with what is left inside maxHeap

int minValue(string s, int k)
{
    vector<int> freq(26, 0);
    priority_queue<int> maxHeap;

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            maxHeap.push(freq[i]);
        }
    }
    while (k--)
    {
        int top = maxHeap.top();
        maxHeap.pop();
        maxHeap.push(top - 1);
    }

    int sumOfSquares = 0;
    while (!maxHeap.empty())
    {
        int x = maxHeap.top();
        maxHeap.pop();
        sumOfSquares += (x * x);
    }
    return sumOfSquares;
}