/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */

// @lc code=start
class Solution
{
public:
    int rec(int i, int age, vector<pair<int, int>> &vec, vector<vector<int>> &dp)
    {
        if (i >= vec.size())
            return 0;
        auto p = vec[i];
        if (dp[i][age] != -1)
            return dp[i][age];
        if (p.second >= age)
        {
            int l = rec(i + 1, age, vec, dp);
            int r = p.first + rec(i + 1, p.second, vec, dp);
            return dp[i][age] = max(l, r);
        }
        else
            return dp[i][age] = rec(i + 1, age, vec, dp);
    }
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        vector<pair<int, int>> vec;
        vector<vector<int>> dp(ages.size(), vector<int>(1001, -1));
        for (int i = 0; i < ages.size(); i++)
            vec.push_back({scores[i], ages[i]});
        sort(vec.begin(), vec.end());
        return rec(0, 0, vec, dp);
    }
};
// @lc code=end
