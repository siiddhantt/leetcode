/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>> maxh;
        vector<vector<int>> ans;
        for (auto it : points)
        {
            int d = pow(it[0], 2) + pow(it[1], 2);
            maxh.push(make_pair(d, it));
            if (maxh.size() > k)
                maxh.pop();
        }
        for (int i = 0; i < k; i++)
        {
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        return ans;
    }
};
// @lc code=end
