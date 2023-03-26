// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
// Approach: Find nextSmallerElementOnLeft nextSmallerElementOnRight.
// ans = max(ans, arr[i] * (rightSmallerElements[i] - leftSmallerElements[i] - 1))

vector<int> nextSmallerElementOnLeft(long long arr[], int n)
{
    vector<int> v(n);
    stack<pair<long long, int>> st; // {smallest, index}

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] <= st.top().first)
        {
            st.pop();
        }

        if (st.empty())
        {
            v[i] = -1;
        }
        else
        {
            v[i] = st.top().second;
        }
        st.push({arr[i], i});
    }
    return v;
}

vector<int> nextSmallerElementOnRight(long long arr[], int n)
{
    vector<int> v(n);
    stack<pair<long long, int>> st; // {smallest, index}

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] <= st.top().first)
        {
            st.pop();
        }

        if (st.empty())
        {
            v[i] = n;
        }
        else
        {
            v[i] = st.top().second;
        }
        st.push({arr[i], i});
    }
    return v;
    vector<int> nextSmallerElementOnLeft(long long arr[], int n)
    {
        vector<int> v(n);
        stack<pair<long long, int>> st; // {smallest, index}

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] <= st.top().first)
            {
                st.pop();
            }

            if (st.empty())
            {
                v[i] = -1;
            }
            else
            {
                v[i] = st.top().second;
            }
            st.push({arr[i], i});
        }
        return v;
    }

    vector<int> nextSmallerElementOnRight(long long arr[], int n)
    {
        vector<int> v(n);
        stack<pair<long long, int>> st; // {smallest, index}

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[i] <= st.top().first)
            {
                st.pop();
            }

            if (st.empty())
            {
                v[i] = n;
            }
            else
            {
                v[i] = st.top().second;
            }
            st.push({arr[i], i});
        }
        return v;
    }

    long long getMaxArea(long long arr[], int n)
    {
        vector<int> leftSmallerElements = nextSmallerElementOnLeft(arr, n);
        vector<int> rightSmallerElements = nextSmallerElementOnRight(arr, n);
        long long ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, arr[i] * (rightSmallerElements[i] - leftSmallerElements[i] - 1));
        }
        return ans;
    }
}

long long getMaxArea(long long arr[], int n)
{
    vector<int> leftSmallerElements = nextSmallerElementOnLeft(arr, n);
    vector<int> rightSmallerElements = nextSmallerElementOnRight(arr, n);
    long long ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i] * (rightSmallerElements[i] - leftSmallerElements[i] - 1));
    }
    return ans;
}