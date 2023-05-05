// https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1
// Approach:
// Always find the maxChar from the point of index
// Swap it with index, update ans, recursion call, backtrack

// Brute force - TLE
// void solve(string str, string &ans, int k, int index) {
//     ans = max(ans, str);
//     if(k == 0) {
//         return;
//     }

//     for(int i = index; i < str.length()-1; i++) {
//         for(int j = i+1; j < str.length(); j++) {
//             if(str[j] > str[i]) {
//                 swap(str[i], str[j]);
//                 solve(str, ans, k-1, index+1);
//                 swap(str[i], str[j]);
//             }
//         }
//     }
// }

// Optimal solution
// Always find the maxChar from the point of index
// Swap it with index, update ans, recursion call, backtrack
void solve(string str, string &ans, int k, int index)
{
    if (k == 0)
    {
        return;
    }
    int n = str.size();
    char maxChar = str[index];
    for (int i = index + 1; i < n; i++)
    {
        if (maxChar < str[i])
        {
            maxChar = str[i];
        }
    }

    if (maxChar != str[index])
    {
        k--;
    }
    for (int i = index; i < n; i++)
    {
        if (str[i] == maxChar)
        {
            swap(str[i], str[index]);
            if (str > ans)
            {
                ans = str;
            }
            solve(str, ans, k, index + 1);
            swap(str[i], str[index]);
        }
    }
}

// Function to find the largest number after k swaps.
string findMaximumNum(string str, int k)
{
    string ans = str;
    solve(str, ans, k, 0);
    return ans;
}