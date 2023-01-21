/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, int> m;
    int rec(int i, vector<int> &days, vector<int> &costs, vector<int> &dp)
    {
        if (i >= days.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int c1, c2, c3, j;
        c1 = costs[0] + rec(i + 1, days, costs, dp);
        for (j = i + 1; j < days.size(); j++)
        {
            if (days[j] > days[i] + 6)
                break;
        }
        c2 = costs[1] + rec(j, days, costs, dp);
        for (j = i + 1; j < days.size(); j++)
        {
            if (days[j] > days[i] + 29)
                break;
        }
        c3 = costs[2] + rec(j, days, costs, dp);
        return dp[i] = min(c1, min(c2, c3));
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        for (int i = 0; i < days.size(); i++)
            m[days[i]] = i;
        vector<int> dp(days.size(), -1);
        return rec(0, days, costs, dp);
    }
};
// @lc code=end
