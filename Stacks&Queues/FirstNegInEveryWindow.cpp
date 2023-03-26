// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// Approach: store -ve nos. in queue.
// if arr[i-k] < 0. pop from queue.
// TC: O(n)
// SC: O(k)

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k)
{
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            q.push(arr[i]);
        }
    }

    vector<long long> ans;
    if (q.empty())
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(q.front());
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] < 0)
        {
            q.push(arr[i]);
        }
        if (arr[i - k] < 0)
        {
            q.pop();
        }

        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(q.front());
        }
    }

    return ans;
}