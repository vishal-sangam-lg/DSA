// https://practice.geeksforgeeks.org/problems/check-if-all-levels-of-two-trees-are-anagrams-or-not/1
// Approach: BFS. add current level to queue. Then process the current with map<int,int>freq
// for queue1 freq[a]++ for queue2 freq[b]--.
// If they are anagrams at that level, all freq will be 0 after queue processing at that level
// TC: O(n)
// SC: O(n)

bool areAnagrams(Node *root1, Node *root2)
{
    queue<Node *> q1, q2;

    q1.push(root1);
    q2.push(root2);

    while (!q1.empty() && !q2.empty())
    {
        int s1 = q1.size(), s2 = q2.size();
        if (s1 != s2)
        {
            return false;
        }

        unordered_map<int, int> freq;

        for (int i = 0; i < s1; i++)
        {
            Node *a = q1.front();
            q1.pop();
            Node *b = q2.front();
            q2.pop();

            freq[a->data]++;
            freq[b->data]--;

            if (a->left)
                q1.push(a->left);
            if (a->right)
                q1.push(a->right);
            if (b->left)
                q2.push(b->left);
            if (b->right)
                q2.push(b->right);
        }

        for (auto it : freq)
            if (it.second != 0)
                return false;
    }
    if (!q1.empty() || !q2.empty())
        return false;

    return true;
}