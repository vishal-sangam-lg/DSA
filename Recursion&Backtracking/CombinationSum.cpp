// https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1
// Approach: Sort and delete duplicates from vector.
// solve for all combination with current num possible. Then backtrack and solve for next index

void solve(int index, int num, vector<int> &A, vector<int> &curr, vector<vector<int>> &ans)
{
    if (index == A.size())
    {
        if (num == 0)
        {
            ans.push_back(curr);
        }
        return;
    }

    if (A[index] <= num)
    {
        curr.push_back(A[index]);
        solve(index, num - A[index], A, curr, ans);
        curr.pop_back(); // backtrack
    }

    solve(index + 1, num, A, curr, ans);
}
vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    vector<vector<int>> ans;
    vector<int> curr;
    sort(A.begin(), A.end());
    // erase takes two params - (start position, end position)
    // unique takes two parms - (start position, end posiiton) and returns new end
    // rest of vector will be undefined after unique, so we erase them.
    A.erase(unique(A.begin(), A.end()), A.end());
    solve(0, B, A, curr, ans);
    return ans;
}