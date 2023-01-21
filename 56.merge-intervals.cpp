/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        int n = intervals.size(), j = 0;
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < n; i++)
        {
            if (intervals[j][1] >= intervals[i][0])
                intervals[j][1] = max(intervals[j][1], intervals[i][1]);
            else
            {
                j++;
                intervals[j] = intervals[i];
            }
        }
        for (int i = 0; i <= j; i++)
            ans.push_back(intervals[i]);
        return ans;
    }
};
// @lc code=end
