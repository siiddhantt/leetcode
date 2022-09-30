/*
 * @lc app=leetcode id=2007 lang=cpp
 *
 * [2007] Find Original Array From Doubled Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int n = changed.size();
        vector<int> res;
        if (n % 2 != 0)
        {
            return {};
        }
        map<int, int> m;
        for (auto it : changed)
        {
            m[it] = it * 2;
        }
        auto tmp = m;
        for (auto it : m)
        {
            if(it.first < 0) {
                continue;
            }
            if (m.find(it.second) != m.end())
            {
                res.push_back(it.first);
                m[it.first] = -1;
                m[it.second] = -1;
            }
        }
        if (res.size() == n/2)
            return res;
        else
            return {};
    }
};
// @lc code=end
