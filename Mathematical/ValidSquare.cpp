// https://leetcode.com/problems/valid-square/
// TC: O(1)
// SC: O(1)

#include <iostream>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

// Approach - I
int distance(vector<int> &x, vector<int> &y)
{
    return pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2);
}
bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
{
    set<int> s;
    // Calculate the distances between all pairs of points and add them to the set
    s.insert(distance(p1, p2));
    s.insert(distance(p1, p3));
    s.insert(distance(p1, p4));
    s.insert(distance(p2, p3));
    s.insert(distance(p2, p4));
    s.insert(distance(p3, p4));
    // A square must have 4 equal sides, so the set must contain 2 different values (the lengths of the sides and the diagonals)
    // The set should not contain 0, as that would mean that two points have the same coordinates
    return s.find(0) == s.end() && s.size() == 2;
}

// Approach - II
// Calculate the distance between all points and check if 4 sides are equal and diagonals are equal