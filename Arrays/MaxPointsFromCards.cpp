// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards
// TC: O(n)
// SC: O(1)
// Dry run:
// 1 2 3 4 5, k = 3
// window will be following
// 1 2 3
// 1 2     5
// 1     4 5
//     3 4 5

int maxScore(vector<int> &cardPoints, int k)
{
    // window of size k.
    int score = 0;
    // Get the score for complete window of size k
    for (int i = 0; i < k; i++)
    {
        score += cardPoints[i];
    }
    int currScore = score;
    // remove an element from right and add an element to left of window and update score
    for (int i = k - 1; i >= 0; i--)
    {
        currScore -= cardPoints[i];
        currScore += cardPoints[cardPoints.size() - k + i];
        score = max(score, currScore);
    }
    return score;
}