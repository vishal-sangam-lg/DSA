// https://practice.geeksforgeeks.org/problems/87f12e5c728d69a5322634776b54c75897d14daa/1
// https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/
// Approach: Hashing and nested loop
// TC: O(n^2) SC: O(n)
// If its DLL -> Two pointer. TC: O(n^2) SC: O(1)

int countTriplets(struct Node *head, int x)
{
    // // Hashing -> TC: O(n^2) SC: O(n)
    // unordered_set<int>s;
    // int count = 0;
    // struct Node *i, *j;
    // for(i = head; i != NULL; i = i -> next) {
    //     for(j = i -> next; j != NULL; j = j -> next) {
    //         if(s.find(x - i->data - j->data) != s.end()) count++;
    //     }
    //     s.insert(i -> data);
    // }
    // return count;

    // Using two pointer while traversing the DLL
    // TC: O(n^2) SC: O(1)
}