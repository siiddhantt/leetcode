/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        int score = INT_MIN, max_end = INT_MIN;
        int r = values[n - 1] - (n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            max_end = max(max_end, r);
            score = max(score, values[i] + i + max_end);
            r = values[i] - i;
        }
        return score;
    }
};
// @lc code=end
