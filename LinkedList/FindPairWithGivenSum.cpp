// https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
// Approach:
// hashing -> TC: O(n) SC: O(n)
// Two pointers -> TC: O(n) SC: O(1)

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    // // Using hashing -> TC: O(n) SC: O(n)
    // vector<pair<int, int>> ans;
    // unordered_set<int> s;
    // Node *ptr = head;

    // while(ptr) {
    //     if(s.count(target - ptr->data) == 1)
    //         ans.push_back({min(ptr->data, target - ptr->data), max(ptr->data, target - ptr->data)});
    //     s.insert(ptr -> data);
    //     ptr = ptr -> next;
    // }
    // sort(ans.begin(), ans.end());
    // return ans;

    // Two pointers -> TC: O(n) SC: O(1)
    vector<pair<int, int>> ans;

    // Initilising left and right pointers to left and right of DLL
    Node *left = head;
    Node *right = head;
    while (right->next != NULL)
        right = right->next;

    // Searching for pairs in sorted DLL
    while (left->data < right->data)
    {
        int sum = left->data + right->data;
        if (sum == target)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < target)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }

    return ans;
}