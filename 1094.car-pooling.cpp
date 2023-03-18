/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        map<int, vector<int>> m;
        int n = trips.size(), cap = 0;
        for (int i = 0; i < n; i++)
        {
            m[trips[i][1]].push_back(trips[i][0]);
            m[trips[i][2]].push_back(-1 * trips[i][0]);
        }
        for (auto it : m)
        {
            for (auto i : it.second)
                cap += i;
            if (cap > capacity)
                return false;
        }
        return true;
    }
};
// @lc code=end
